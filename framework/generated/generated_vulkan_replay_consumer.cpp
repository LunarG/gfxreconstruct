/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
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

#include "generated/generated_vulkan_replay_consumer.h"

#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReplayConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    if (!pInstance->IsNull()) { pInstance->SetHandleLength(1); }
    InstanceInfo handle_info;
    pInstance->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateInstance(returnValue, pCreateInfo, pAllocator, pInstance);
    CheckResult("vkCreateInstance", returnValue, replay_result);

    AddHandle<InstanceInfo>(format::kNullHandleId, pInstance->GetPointer(), pInstance->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddInstanceInfo);
}

void VulkanReplayConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetInstanceTable(in_instance)->DestroyInstance(in_instance, in_pAllocator);
    RemoveHandle(instance, &VulkanObjectInfoTable::RemoveInstanceInfo);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    pPhysicalDeviceCount->IsNull() ? nullptr : pPhysicalDeviceCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, InstanceInfo>("vkEnumeratePhysicalDevices", returnValue, instance, kInstanceArrayEnumeratePhysicalDevices, pPhysicalDeviceCount, pPhysicalDevices, &VulkanObjectInfoTable::GetInstanceInfo));
    if (!pPhysicalDevices->IsNull()) { pPhysicalDevices->SetHandleLength(*pPhysicalDeviceCount->GetOutputPointer()); }
    std::vector<PhysicalDeviceInfo> handle_info(*pPhysicalDeviceCount->GetOutputPointer());
    for (size_t i = 0; i < *pPhysicalDeviceCount->GetOutputPointer(); ++i) { pPhysicalDevices->SetConsumerData(i, &handle_info[i]); }

    VkResult replay_result = OverrideEnumeratePhysicalDevices(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDevices, returnValue, in_instance, pPhysicalDeviceCount, pPhysicalDevices);
    CheckResult("vkEnumeratePhysicalDevices", returnValue, replay_result);

    if (pPhysicalDevices->IsNull()) { SetOutputArrayCount<InstanceInfo>(instance, kInstanceArrayEnumeratePhysicalDevices, *pPhysicalDeviceCount->GetOutputPointer(), &VulkanObjectInfoTable::GetInstanceInfo); }
    AddHandles<PhysicalDeviceInfo>(instance, pPhysicalDevices->GetPointer(), pPhysicalDevices->GetLength(), pPhysicalDevices->GetHandlePointer(), *pPhysicalDeviceCount->GetOutputPointer(), std::move(handle_info), &VulkanObjectInfoTable::AddPhysicalDeviceInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkPhysicalDeviceFeatures* out_pFeatures = pFeatures->IsNull() ? nullptr : pFeatures->AllocateOutputData(1);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkFormatProperties* out_pFormatProperties = pFormatProperties->IsNull() ? nullptr : pFormatProperties->AllocateOutputData(1);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkImageFormatProperties* out_pImageFormatProperties = pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties(in_physicalDevice, format, type, tiling, usage, flags, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1);

    OverrideGetPhysicalDeviceProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties, in_physicalDevice, pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pQueueFamilyPropertyCount = pQueueFamilyPropertyCount->IsNull() ? nullptr : pQueueFamilyPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties, pQueueFamilyPropertyCount, pQueueFamilyProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkQueueFamilyProperties* out_pQueueFamilyProperties = pQueueFamilyProperties->IsNull() ? nullptr : pQueueFamilyProperties->AllocateOutputData(*out_pQueueFamilyPropertyCount);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    if (pQueueFamilyProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties, *out_pQueueFamilyPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pMemoryProperties->IsNull() ? nullptr : pMemoryProperties->AllocateOutputData(1);

    OverrideGetPhysicalDeviceMemoryProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties, in_physicalDevice, pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDevice->IsNull()) { pDevice->SetHandleLength(1); }
    DeviceInfo handle_info;
    pDevice->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDevice(returnValue, in_physicalDevice, pCreateInfo, pAllocator, pDevice);
    CheckResult("vkCreateDevice", returnValue, replay_result);

    AddHandle<DeviceInfo>(physicalDevice, pDevice->GetPointer(), pDevice->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDeviceInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    OverrideDestroyDevice(GetDeviceTable(in_device->handle)->DestroyDevice, in_device, pAllocator);
    RemoveHandle(device, &VulkanObjectInfoTable::RemoveDeviceInfo);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    if (!pQueue->IsNull()) { pQueue->SetHandleLength(1); }
    VkQueue* out_pQueue = pQueue->GetHandlePointer();

    GetDeviceTable(in_device)->GetDeviceQueue(in_device, queueFamilyIndex, queueIndex, out_pQueue);

    AddHandle<QueueInfo>(device, pQueue->GetPointer(), out_pQueue, &VulkanObjectInfoTable::AddQueueInfo);
}

void VulkanReplayConsumer::Process_vkQueueSubmit(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

    MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

    VkResult replay_result = OverrideQueueSubmit(GetDeviceTable(in_queue->handle)->QueueSubmit, returnValue, in_queue, submitCount, pSubmits, in_fence);
    CheckResult("vkQueueSubmit", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectInfoTable::GetQueueInfo);

    VkResult replay_result = GetDeviceTable(in_queue)->QueueWaitIdle(in_queue);
    CheckResult("vkQueueWaitIdle", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);

    VkResult replay_result = GetDeviceTable(in_device)->DeviceWaitIdle(in_device);
    CheckResult("vkDeviceWaitIdle", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pAllocateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pMemory->IsNull()) { pMemory->SetHandleLength(1); }
    DeviceMemoryInfo handle_info;
    pMemory->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideAllocateMemory(GetDeviceTable(in_device->handle)->AllocateMemory, returnValue, in_device, pAllocateInfo, pAllocator, pMemory);
    CheckResult("vkAllocateMemory", returnValue, replay_result);

    AddHandle<DeviceMemoryInfo>(device, pMemory->GetPointer(), pMemory->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDeviceMemoryInfo);
}

void VulkanReplayConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);

    OverrideFreeMemory(GetDeviceTable(in_device->handle)->FreeMemory, in_device, in_memory, pAllocator);
    RemoveHandle(memory, &VulkanObjectInfoTable::RemoveDeviceMemoryInfo);
}

void VulkanReplayConsumer::Process_vkMapMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);
    void** out_ppData = ppData->IsNull() ? nullptr : ppData->AllocateOutputData(1);

    VkResult replay_result = OverrideMapMemory(GetDeviceTable(in_device->handle)->MapMemory, returnValue, in_device, in_memory, offset, size, flags, out_ppData);
    CheckResult("vkMapMemory", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*ppData->GetPointer()), *ppData->GetOutputPointer(), format::ApiCallId::ApiCall_vkMapMemory, "vkMapMemory");
}

void VulkanReplayConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);

    OverrideUnmapMemory(GetDeviceTable(in_device->handle)->UnmapMemory, in_device, in_memory);
}

void VulkanReplayConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pMemoryRanges->GetMetaStructPointer(), pMemoryRanges->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideFlushMappedMemoryRanges(GetDeviceTable(in_device->handle)->FlushMappedMemoryRanges, returnValue, in_device, memoryRangeCount, pMemoryRanges);
    CheckResult("vkFlushMappedMemoryRanges", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pMemoryRanges->GetMetaStructPointer(), pMemoryRanges->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideInvalidateMappedMemoryRanges(GetDeviceTable(in_device->handle)->InvalidateMappedMemoryRanges, returnValue, in_device, memoryRangeCount, pMemoryRanges);
    CheckResult("vkInvalidateMappedMemoryRanges", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeviceMemory in_memory = MapHandle<DeviceMemoryInfo>(memory, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    VkDeviceSize* out_pCommittedMemoryInBytes = pCommittedMemoryInBytes->IsNull() ? nullptr : pCommittedMemoryInBytes->AllocateOutputData(1, static_cast<VkDeviceSize>(0));

    GetDeviceTable(in_device)->GetDeviceMemoryCommitment(in_device, in_memory, out_pCommittedMemoryInBytes);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);

    VkResult replay_result = OverrideBindBufferMemory(GetDeviceTable(in_device->handle)->BindBufferMemory, returnValue, in_device, in_buffer, in_memory, memoryOffset);
    CheckResult("vkBindBufferMemory", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);
    auto in_memory = GetObjectInfoTable().GetDeviceMemoryInfo(memory);

    VkResult replay_result = OverrideBindImageMemory(GetDeviceTable(in_device->handle)->BindImageMemory, returnValue, in_device, in_image, in_memory, memoryOffset);
    CheckResult("vkBindImageMemory", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkMemoryRequirements* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetBufferMemoryRequirements(in_device, in_buffer, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectInfoTable::GetImageInfo);
    VkMemoryRequirements* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetImageMemoryRequirements(in_device, in_image, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectInfoTable::GetImageInfo);
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, ImageInfo>("vkGetImageSparseMemoryRequirements", VK_SUCCESS, image, kImageArrayGetImageSparseMemoryRequirements, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &VulkanObjectInfoTable::GetImageInfo));
    VkSparseImageMemoryRequirements* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount);

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements(in_device, in_image, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<ImageInfo>(image, kImageArrayGetImageSparseMemoryRequirements, *out_pSparseMemoryRequirementCount, &VulkanObjectInfoTable::GetImageInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkSparseImageFormatProperties* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(in_physicalDevice, format, type, samples, usage, tiling, out_pPropertyCount, out_pProperties);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties, *out_pPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

    MapStructArrayHandles(pBindInfo->GetMetaStructPointer(), pBindInfo->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

    VkResult replay_result = OverrideQueueBindSparse(GetDeviceTable(in_queue->handle)->QueueBindSparse, returnValue, in_queue, bindInfoCount, pBindInfo, in_fence);
    CheckResult("vkQueueBindSparse", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkFenceCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pFence->IsNull()) { pFence->SetHandleLength(1); }
    VkFence* out_pFence = pFence->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateFence(in_device, in_pCreateInfo, in_pAllocator, out_pFence);
    CheckResult("vkCreateFence", returnValue, replay_result);

    AddHandle<FenceInfo>(device, pFence->GetPointer(), out_pFence, &VulkanObjectInfoTable::AddFenceInfo);
}

void VulkanReplayConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkFence in_fence = MapHandle<FenceInfo>(fence, &VulkanObjectInfoTable::GetFenceInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyFence(in_device, in_fence, in_pAllocator);
    RemoveHandle(fence, &VulkanObjectInfoTable::RemoveFenceInfo);
}

void VulkanReplayConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkFence* in_pFences = MapHandles<FenceInfo>(pFences, fenceCount, &VulkanObjectInfoTable::GetFenceInfo);

    VkResult replay_result = GetDeviceTable(in_device)->ResetFences(in_device, fenceCount, in_pFences);
    CheckResult("vkResetFences", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

    VkResult replay_result = OverrideGetFenceStatus(GetDeviceTable(in_device->handle)->GetFenceStatus, returnValue, in_device, in_fence);
    CheckResult("vkGetFenceStatus", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkWaitForFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    MapHandles<FenceInfo>(pFences, fenceCount, &VulkanObjectInfoTable::GetFenceInfo);

    VkResult replay_result = OverrideWaitForFences(GetDeviceTable(in_device->handle)->WaitForFences, returnValue, in_device, fenceCount, pFences, waitAll, timeout);
    CheckResult("vkWaitForFences", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSemaphoreCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSemaphore->IsNull()) { pSemaphore->SetHandleLength(1); }
    VkSemaphore* out_pSemaphore = pSemaphore->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSemaphore(in_device, in_pCreateInfo, in_pAllocator, out_pSemaphore);
    CheckResult("vkCreateSemaphore", returnValue, replay_result);

    AddHandle<SemaphoreInfo>(device, pSemaphore->GetPointer(), out_pSemaphore, &VulkanObjectInfoTable::AddSemaphoreInfo);
}

void VulkanReplayConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSemaphore in_semaphore = MapHandle<SemaphoreInfo>(semaphore, &VulkanObjectInfoTable::GetSemaphoreInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySemaphore(in_device, in_semaphore, in_pAllocator);
    RemoveHandle(semaphore, &VulkanObjectInfoTable::RemoveSemaphoreInfo);
}

void VulkanReplayConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkEventCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pEvent->IsNull()) { pEvent->SetHandleLength(1); }
    VkEvent* out_pEvent = pEvent->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateEvent(in_device, in_pCreateInfo, in_pAllocator, out_pEvent);
    CheckResult("vkCreateEvent", returnValue, replay_result);

    AddHandle<EventInfo>(device, pEvent->GetPointer(), out_pEvent, &VulkanObjectInfoTable::AddEventInfo);
}

void VulkanReplayConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectInfoTable::GetEventInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyEvent(in_device, in_event, in_pAllocator);
    RemoveHandle(event, &VulkanObjectInfoTable::RemoveEventInfo);
}

void VulkanReplayConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_event = GetObjectInfoTable().GetEventInfo(event);

    VkResult replay_result = OverrideGetEventStatus(GetDeviceTable(in_device->handle)->GetEventStatus, returnValue, in_device, in_event);
    CheckResult("vkGetEventStatus", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectInfoTable::GetEventInfo);

    VkResult replay_result = GetDeviceTable(in_device)->SetEvent(in_device, in_event);
    CheckResult("vkSetEvent", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectInfoTable::GetEventInfo);

    VkResult replay_result = GetDeviceTable(in_device)->ResetEvent(in_device, in_event);
    CheckResult("vkResetEvent", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkQueryPoolCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pQueryPool->IsNull()) { pQueryPool->SetHandleLength(1); }
    VkQueryPool* out_pQueryPool = pQueryPool->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateQueryPool(in_device, in_pCreateInfo, in_pAllocator, out_pQueryPool);
    CheckResult("vkCreateQueryPool", returnValue, replay_result);

    AddHandle<QueryPoolInfo>(device, pQueryPool->GetPointer(), out_pQueryPool, &VulkanObjectInfoTable::AddQueryPoolInfo);
}

void VulkanReplayConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyQueryPool(in_device, in_queryPool, in_pAllocator);
    RemoveHandle(queryPool, &VulkanObjectInfoTable::RemoveQueryPoolInfo);
}

void VulkanReplayConsumer::Process_vkGetQueryPoolResults(
    const ApiCallInfo&                          call_info,
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
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_queryPool = GetObjectInfoTable().GetQueryPoolInfo(queryPool);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

    VkResult replay_result = OverrideGetQueryPoolResults(GetDeviceTable(in_device->handle)->GetQueryPoolResults, returnValue, in_device, in_queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    CheckResult("vkGetQueryPoolResults", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pBuffer->IsNull()) { pBuffer->SetHandleLength(1); }
    BufferInfo handle_info;
    pBuffer->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateBuffer(GetDeviceTable(in_device->handle)->CreateBuffer, returnValue, in_device, pCreateInfo, pAllocator, pBuffer);
    CheckResult("vkCreateBuffer", returnValue, replay_result);

    AddHandle<BufferInfo>(device, pBuffer->GetPointer(), pBuffer->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddBufferInfo);
}

void VulkanReplayConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_buffer = GetObjectInfoTable().GetBufferInfo(buffer);

    OverrideDestroyBuffer(GetDeviceTable(in_device->handle)->DestroyBuffer, in_device, in_buffer, pAllocator);
    RemoveHandle(buffer, &VulkanObjectInfoTable::RemoveBufferInfo);
}

void VulkanReplayConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkBufferViewCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pView->IsNull()) { pView->SetHandleLength(1); }
    VkBufferView* out_pView = pView->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateBufferView(in_device, in_pCreateInfo, in_pAllocator, out_pView);
    CheckResult("vkCreateBufferView", returnValue, replay_result);

    AddHandle<BufferViewInfo>(device, pView->GetPointer(), out_pView, &VulkanObjectInfoTable::AddBufferViewInfo);
}

void VulkanReplayConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkBufferView in_bufferView = MapHandle<BufferViewInfo>(bufferView, &VulkanObjectInfoTable::GetBufferViewInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyBufferView(in_device, in_bufferView, in_pAllocator);
    RemoveHandle(bufferView, &VulkanObjectInfoTable::RemoveBufferViewInfo);
}

void VulkanReplayConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pImage->IsNull()) { pImage->SetHandleLength(1); }
    ImageInfo handle_info;
    pImage->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateImage(GetDeviceTable(in_device->handle)->CreateImage, returnValue, in_device, pCreateInfo, pAllocator, pImage);
    CheckResult("vkCreateImage", returnValue, replay_result);

    AddHandle<ImageInfo>(device, pImage->GetPointer(), pImage->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddImageInfo);
}

void VulkanReplayConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);

    OverrideDestroyImage(GetDeviceTable(in_device->handle)->DestroyImage, in_device, in_image, pAllocator);
    RemoveHandle(image, &VulkanObjectInfoTable::RemoveImageInfo);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetImageInfo(image);
    pLayout->IsNull() ? nullptr : pLayout->AllocateOutputData(1);

    OverrideGetImageSubresourceLayout(GetDeviceTable(in_device->handle)->GetImageSubresourceLayout, in_device, in_image, pSubresource, pLayout);
}

void VulkanReplayConsumer::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkImageViewCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pView->IsNull()) { pView->SetHandleLength(1); }
    VkImageView* out_pView = pView->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateImageView(in_device, in_pCreateInfo, in_pAllocator, out_pView);
    CheckResult("vkCreateImageView", returnValue, replay_result);

    AddHandle<ImageViewInfo>(device, pView->GetPointer(), out_pView, &VulkanObjectInfoTable::AddImageViewInfo);
}

void VulkanReplayConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkImageView in_imageView = MapHandle<ImageViewInfo>(imageView, &VulkanObjectInfoTable::GetImageViewInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyImageView(in_device, in_imageView, in_pAllocator);
    RemoveHandle(imageView, &VulkanObjectInfoTable::RemoveImageViewInfo);
}

void VulkanReplayConsumer::Process_vkCreateShaderModule(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderModule>*       pShaderModule)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pShaderModule->IsNull()) { pShaderModule->SetHandleLength(1); }
    ShaderModuleInfo handle_info;
    pShaderModule->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateShaderModule(GetDeviceTable(in_device->handle)->CreateShaderModule, returnValue, in_device, pCreateInfo, pAllocator, pShaderModule);
    CheckResult("vkCreateShaderModule", returnValue, replay_result);

    AddHandle<ShaderModuleInfo>(device, pShaderModule->GetPointer(), pShaderModule->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddShaderModuleInfo);
}

void VulkanReplayConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkShaderModule in_shaderModule = MapHandle<ShaderModuleInfo>(shaderModule, &VulkanObjectInfoTable::GetShaderModuleInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyShaderModule(in_device, in_shaderModule, in_pAllocator);
    RemoveHandle(shaderModule, &VulkanObjectInfoTable::RemoveShaderModuleInfo);
}

void VulkanReplayConsumer::Process_vkCreatePipelineCache(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineCache>*      pPipelineCache)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pPipelineCache->IsNull()) { pPipelineCache->SetHandleLength(1); }
    PipelineCacheInfo handle_info;
    pPipelineCache->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreatePipelineCache(GetDeviceTable(in_device->handle)->CreatePipelineCache, returnValue, in_device, pCreateInfo, pAllocator, pPipelineCache);
    CheckResult("vkCreatePipelineCache", returnValue, replay_result);

    AddHandle<PipelineCacheInfo>(device, pPipelineCache->GetPointer(), pPipelineCache->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddPipelineCacheInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipelineCache in_pipelineCache = MapHandle<PipelineCacheInfo>(pipelineCache, &VulkanObjectInfoTable::GetPipelineCacheInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPipelineCache(in_device, in_pipelineCache, in_pAllocator);
    RemoveHandle(pipelineCache, &VulkanObjectInfoTable::RemovePipelineCacheInfo);
}

void VulkanReplayConsumer::Process_vkGetPipelineCacheData(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipelineCache = GetObjectInfoTable().GetPipelineCacheInfo(pipelineCache);
    pDataSize->IsNull() ? nullptr : pDataSize->AllocateOutputData(1, GetOutputArrayCount<size_t, PipelineCacheInfo>("vkGetPipelineCacheData", returnValue, pipelineCache, kPipelineCacheArrayGetPipelineCacheData, pDataSize, pData, &VulkanObjectInfoTable::GetPipelineCacheInfo));
    if (!pData->IsNull()) { pData->AllocateOutputData(*pDataSize->GetOutputPointer()); }

    VkResult replay_result = OverrideGetPipelineCacheData(GetDeviceTable(in_device->handle)->GetPipelineCacheData, returnValue, in_device, in_pipelineCache, pDataSize, pData);
    CheckResult("vkGetPipelineCacheData", returnValue, replay_result);

    if (pData->IsNull()) { SetOutputArrayCount<PipelineCacheInfo>(pipelineCache, kPipelineCacheArrayGetPipelineCacheData, *pDataSize->GetOutputPointer(), &VulkanObjectInfoTable::GetPipelineCacheInfo); }
}

void VulkanReplayConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipelineCache in_dstCache = MapHandle<PipelineCacheInfo>(dstCache, &VulkanObjectInfoTable::GetPipelineCacheInfo);
    const VkPipelineCache* in_pSrcCaches = MapHandles<PipelineCacheInfo>(pSrcCaches, srcCacheCount, &VulkanObjectInfoTable::GetPipelineCacheInfo);

    VkResult replay_result = GetDeviceTable(in_device)->MergePipelineCaches(in_device, in_dstCache, srcCacheCount, in_pSrcCaches);
    CheckResult("vkMergePipelineCaches", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipelineCache in_pipelineCache = MapHandle<PipelineCacheInfo>(pipelineCache, &VulkanObjectInfoTable::GetPipelineCacheInfo);
    const VkGraphicsPipelineCreateInfo* in_pCreateInfos = pCreateInfos->GetPointer();
    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    VkPipeline* out_pPipelines = pPipelines->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateGraphicsPipelines(in_device, in_pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);
    CheckResult("vkCreateGraphicsPipelines", returnValue, replay_result);

    AddHandles<PipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), out_pPipelines, createInfoCount, &VulkanObjectInfoTable::AddPipelineInfo);
}

void VulkanReplayConsumer::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipelineCache in_pipelineCache = MapHandle<PipelineCacheInfo>(pipelineCache, &VulkanObjectInfoTable::GetPipelineCacheInfo);
    const VkComputePipelineCreateInfo* in_pCreateInfos = pCreateInfos->GetPointer();
    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    VkPipeline* out_pPipelines = pPipelines->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateComputePipelines(in_device, in_pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);
    CheckResult("vkCreateComputePipelines", returnValue, replay_result);

    AddHandles<PipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), out_pPipelines, createInfoCount, &VulkanObjectInfoTable::AddPipelineInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectInfoTable::GetPipelineInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPipeline(in_device, in_pipeline, in_pAllocator);
    RemoveHandle(pipeline, &VulkanObjectInfoTable::RemovePipelineInfo);
}

void VulkanReplayConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkPipelineLayoutCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pPipelineLayout->IsNull()) { pPipelineLayout->SetHandleLength(1); }
    VkPipelineLayout* out_pPipelineLayout = pPipelineLayout->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreatePipelineLayout(in_device, in_pCreateInfo, in_pAllocator, out_pPipelineLayout);
    CheckResult("vkCreatePipelineLayout", returnValue, replay_result);

    AddHandle<PipelineLayoutInfo>(device, pPipelineLayout->GetPointer(), out_pPipelineLayout, &VulkanObjectInfoTable::AddPipelineLayoutInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipelineLayout in_pipelineLayout = MapHandle<PipelineLayoutInfo>(pipelineLayout, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPipelineLayout(in_device, in_pipelineLayout, in_pAllocator);
    RemoveHandle(pipelineLayout, &VulkanObjectInfoTable::RemovePipelineLayoutInfo);
}

void VulkanReplayConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSamplerCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSampler->IsNull()) { pSampler->SetHandleLength(1); }
    VkSampler* out_pSampler = pSampler->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSampler(in_device, in_pCreateInfo, in_pAllocator, out_pSampler);
    CheckResult("vkCreateSampler", returnValue, replay_result);

    AddHandle<SamplerInfo>(device, pSampler->GetPointer(), out_pSampler, &VulkanObjectInfoTable::AddSamplerInfo);
}

void VulkanReplayConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSampler in_sampler = MapHandle<SamplerInfo>(sampler, &VulkanObjectInfoTable::GetSamplerInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySampler(in_device, in_sampler, in_pAllocator);
    RemoveHandle(sampler, &VulkanObjectInfoTable::RemoveSamplerInfo);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSetLayout->IsNull()) { pSetLayout->SetHandleLength(1); }
    VkDescriptorSetLayout* out_pSetLayout = pSetLayout->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateDescriptorSetLayout(in_device, in_pCreateInfo, in_pAllocator, out_pSetLayout);
    CheckResult("vkCreateDescriptorSetLayout", returnValue, replay_result);

    AddHandle<DescriptorSetLayoutInfo>(device, pSetLayout->GetPointer(), out_pSetLayout, &VulkanObjectInfoTable::AddDescriptorSetLayoutInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDescriptorSetLayout in_descriptorSetLayout = MapHandle<DescriptorSetLayoutInfo>(descriptorSetLayout, &VulkanObjectInfoTable::GetDescriptorSetLayoutInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyDescriptorSetLayout(in_device, in_descriptorSetLayout, in_pAllocator);
    RemoveHandle(descriptorSetLayout, &VulkanObjectInfoTable::RemoveDescriptorSetLayoutInfo);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pDescriptorPool->IsNull()) { pDescriptorPool->SetHandleLength(1); }
    DescriptorPoolInfo handle_info;
    pDescriptorPool->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDescriptorPool(GetDeviceTable(in_device->handle)->CreateDescriptorPool, returnValue, in_device, pCreateInfo, pAllocator, pDescriptorPool);
    CheckResult("vkCreateDescriptorPool", returnValue, replay_result);

    AddHandle<DescriptorPoolInfo>(device, pDescriptorPool->GetPointer(), pDescriptorPool->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDescriptorPoolInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorPool = GetObjectInfoTable().GetDescriptorPoolInfo(descriptorPool);

    OverrideDestroyDescriptorPool(GetDeviceTable(in_device->handle)->DestroyDescriptorPool, in_device, in_descriptorPool, pAllocator);
    RemovePoolHandle<DescriptorPoolInfo>(descriptorPool, &VulkanObjectInfoTable::GetDescriptorPoolInfo, &VulkanObjectInfoTable::RemoveDescriptorPoolInfo, &VulkanObjectInfoTable::RemoveDescriptorSetInfo);
}

void VulkanReplayConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorPool = GetObjectInfoTable().GetDescriptorPoolInfo(descriptorPool);

    VkResult replay_result = OverrideResetDescriptorPool(GetDeviceTable(in_device->handle)->ResetDescriptorPool, returnValue, in_device, in_descriptorPool, flags);
    CheckResult("vkResetDescriptorPool", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pAllocateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDescriptorSets->IsNull()) { pDescriptorSets->SetHandleLength(pAllocateInfo->GetPointer()->descriptorSetCount); }
    std::vector<DescriptorSetInfo> handle_info(pAllocateInfo->GetPointer()->descriptorSetCount);
    for (size_t i = 0; i < pAllocateInfo->GetPointer()->descriptorSetCount; ++i) { pDescriptorSets->SetConsumerData(i, &handle_info[i]); }

    VkResult replay_result = OverrideAllocateDescriptorSets(GetDeviceTable(in_device->handle)->AllocateDescriptorSets, returnValue, in_device, pAllocateInfo, pDescriptorSets);
    CheckResult("vkAllocateDescriptorSets", returnValue, replay_result);

    AddPoolHandles<DescriptorPoolInfo, DescriptorSetInfo>(device, handle_mapping::GetPoolId(pAllocateInfo->GetMetaStructPointer()), pDescriptorSets->GetPointer(), pDescriptorSets->GetLength(), pDescriptorSets->GetHandlePointer(), pAllocateInfo->GetPointer()->descriptorSetCount, std::move(handle_info), &VulkanObjectInfoTable::GetDescriptorPoolInfo, &VulkanObjectInfoTable::AddDescriptorSetInfo);
}

void VulkanReplayConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDescriptorPool in_descriptorPool = MapHandle<DescriptorPoolInfo>(descriptorPool, &VulkanObjectInfoTable::GetDescriptorPoolInfo);
    const VkDescriptorSet* in_pDescriptorSets = MapHandles<DescriptorSetInfo>(pDescriptorSets, descriptorSetCount, &VulkanObjectInfoTable::GetDescriptorSetInfo);

    VkResult replay_result = GetDeviceTable(in_device)->FreeDescriptorSets(in_device, in_descriptorPool, descriptorSetCount, in_pDescriptorSets);
    CheckResult("vkFreeDescriptorSets", returnValue, replay_result);
    RemovePoolHandles<DescriptorPoolInfo, DescriptorSetInfo>(descriptorPool, pDescriptorSets, descriptorSetCount, &VulkanObjectInfoTable::GetDescriptorPoolInfo, &VulkanObjectInfoTable::RemoveDescriptorSetInfo);
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkWriteDescriptorSet* in_pDescriptorWrites = pDescriptorWrites->GetPointer();
    MapStructArrayHandles(pDescriptorWrites->GetMetaStructPointer(), pDescriptorWrites->GetLength(), GetObjectInfoTable());
    const VkCopyDescriptorSet* in_pDescriptorCopies = pDescriptorCopies->GetPointer();
    MapStructArrayHandles(pDescriptorCopies->GetMetaStructPointer(), pDescriptorCopies->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_device)->UpdateDescriptorSets(in_device, descriptorWriteCount, in_pDescriptorWrites, descriptorCopyCount, in_pDescriptorCopies);
}

void VulkanReplayConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkFramebufferCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pFramebuffer->IsNull()) { pFramebuffer->SetHandleLength(1); }
    VkFramebuffer* out_pFramebuffer = pFramebuffer->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateFramebuffer(in_device, in_pCreateInfo, in_pAllocator, out_pFramebuffer);
    CheckResult("vkCreateFramebuffer", returnValue, replay_result);

    AddHandle<FramebufferInfo>(device, pFramebuffer->GetPointer(), out_pFramebuffer, &VulkanObjectInfoTable::AddFramebufferInfo);
}

void VulkanReplayConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkFramebuffer in_framebuffer = MapHandle<FramebufferInfo>(framebuffer, &VulkanObjectInfoTable::GetFramebufferInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyFramebuffer(in_device, in_framebuffer, in_pAllocator);
    RemoveHandle(framebuffer, &VulkanObjectInfoTable::RemoveFramebufferInfo);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pRenderPass->IsNull()) { pRenderPass->SetHandleLength(1); }
    RenderPassInfo handle_info;
    pRenderPass->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateRenderPass(GetDeviceTable(in_device->handle)->CreateRenderPass, returnValue, in_device, pCreateInfo, pAllocator, pRenderPass);
    CheckResult("vkCreateRenderPass", returnValue, replay_result);

    AddHandle<RenderPassInfo>(device, pRenderPass->GetPointer(), pRenderPass->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkRenderPass in_renderPass = MapHandle<RenderPassInfo>(renderPass, &VulkanObjectInfoTable::GetRenderPassInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyRenderPass(in_device, in_renderPass, in_pAllocator);
    RemoveHandle(renderPass, &VulkanObjectInfoTable::RemoveRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkRenderPass in_renderPass = MapHandle<RenderPassInfo>(renderPass, &VulkanObjectInfoTable::GetRenderPassInfo);
    VkExtent2D* out_pGranularity = pGranularity->IsNull() ? nullptr : pGranularity->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetRenderAreaGranularity(in_device, in_renderPass, out_pGranularity);
}

void VulkanReplayConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkCommandPoolCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pCommandPool->IsNull()) { pCommandPool->SetHandleLength(1); }
    VkCommandPool* out_pCommandPool = pCommandPool->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateCommandPool(in_device, in_pCreateInfo, in_pAllocator, out_pCommandPool);
    CheckResult("vkCreateCommandPool", returnValue, replay_result);

    AddHandle<CommandPoolInfo>(device, pCommandPool->GetPointer(), out_pCommandPool, &VulkanObjectInfoTable::AddCommandPoolInfo);
}

void VulkanReplayConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkCommandPool in_commandPool = MapHandle<CommandPoolInfo>(commandPool, &VulkanObjectInfoTable::GetCommandPoolInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyCommandPool(in_device, in_commandPool, in_pAllocator);
    RemovePoolHandle<CommandPoolInfo>(commandPool, &VulkanObjectInfoTable::GetCommandPoolInfo, &VulkanObjectInfoTable::RemoveCommandPoolInfo, &VulkanObjectInfoTable::RemoveCommandBufferInfo);
}

void VulkanReplayConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkCommandPool in_commandPool = MapHandle<CommandPoolInfo>(commandPool, &VulkanObjectInfoTable::GetCommandPoolInfo);

    VkResult replay_result = GetDeviceTable(in_device)->ResetCommandPool(in_device, in_commandPool, flags);
    CheckResult("vkResetCommandPool", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pAllocateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pCommandBuffers->IsNull()) { pCommandBuffers->SetHandleLength(pAllocateInfo->GetPointer()->commandBufferCount); }
    std::vector<CommandBufferInfo> handle_info(pAllocateInfo->GetPointer()->commandBufferCount);
    for (size_t i = 0; i < pAllocateInfo->GetPointer()->commandBufferCount; ++i) { pCommandBuffers->SetConsumerData(i, &handle_info[i]); }

    VkResult replay_result = OverrideAllocateCommandBuffers(GetDeviceTable(in_device->handle)->AllocateCommandBuffers, returnValue, in_device, pAllocateInfo, pCommandBuffers);
    CheckResult("vkAllocateCommandBuffers", returnValue, replay_result);

    AddPoolHandles<CommandPoolInfo, CommandBufferInfo>(device, handle_mapping::GetPoolId(pAllocateInfo->GetMetaStructPointer()), pCommandBuffers->GetPointer(), pCommandBuffers->GetLength(), pCommandBuffers->GetHandlePointer(), pAllocateInfo->GetPointer()->commandBufferCount, std::move(handle_info), &VulkanObjectInfoTable::GetCommandPoolInfo, &VulkanObjectInfoTable::AddCommandBufferInfo);
}

void VulkanReplayConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkCommandPool in_commandPool = MapHandle<CommandPoolInfo>(commandPool, &VulkanObjectInfoTable::GetCommandPoolInfo);
    const VkCommandBuffer* in_pCommandBuffers = MapHandles<CommandBufferInfo>(pCommandBuffers, commandBufferCount, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_device)->FreeCommandBuffers(in_device, in_commandPool, commandBufferCount, in_pCommandBuffers);
    RemovePoolHandles<CommandPoolInfo, CommandBufferInfo>(commandPool, pCommandBuffers, commandBufferCount, &VulkanObjectInfoTable::GetCommandPoolInfo, &VulkanObjectInfoTable::RemoveCommandBufferInfo);
}

void VulkanReplayConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCommandBufferBeginInfo* in_pBeginInfo = pBeginInfo->GetPointer();
    MapStructHandles(pBeginInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->BeginCommandBuffer(in_commandBuffer, in_pBeginInfo);
    CheckResult("vkBeginCommandBuffer", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->EndCommandBuffer(in_commandBuffer);
    CheckResult("vkEndCommandBuffer", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->ResetCommandBuffer(in_commandBuffer, flags);
    CheckResult("vkResetCommandBuffer", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectInfoTable::GetPipelineInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindPipeline(in_commandBuffer, pipelineBindPoint, in_pipeline);
}

void VulkanReplayConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkViewport* in_pViewports = pViewports->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewport(in_commandBuffer, firstViewport, viewportCount, in_pViewports);
}

void VulkanReplayConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkRect2D* in_pScissors = pScissors->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetScissor(in_commandBuffer, firstScissor, scissorCount, in_pScissors);
}

void VulkanReplayConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineWidth(in_commandBuffer, lineWidth);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBias(in_commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

void VulkanReplayConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const float* in_blendConstants = blendConstants->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetBlendConstants(in_commandBuffer, in_blendConstants);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBounds(in_commandBuffer, minDepthBounds, maxDepthBounds);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilCompareMask(in_commandBuffer, faceMask, compareMask);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilWriteMask(in_commandBuffer, faceMask, writeMask);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilReference(in_commandBuffer, faceMask, reference);
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    PointerDecoder<uint32_t>*                   pDynamicOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkPipelineLayout in_layout = MapHandle<PipelineLayoutInfo>(layout, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    const VkDescriptorSet* in_pDescriptorSets = MapHandles<DescriptorSetInfo>(pDescriptorSets, descriptorSetCount, &VulkanObjectInfoTable::GetDescriptorSetInfo);
    const uint32_t* in_pDynamicOffsets = pDynamicOffsets->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindDescriptorSets(in_commandBuffer, pipelineBindPoint, in_layout, firstSet, descriptorSetCount, in_pDescriptorSets, dynamicOffsetCount, in_pDynamicOffsets);
}

void VulkanReplayConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindIndexBuffer(in_commandBuffer, in_buffer, offset, indexType);
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<BufferInfo>(pBuffers, bindingCount, &VulkanObjectInfoTable::GetBufferInfo);
    const VkDeviceSize* in_pOffsets = pOffsets->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets);
}

void VulkanReplayConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDraw(in_commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexed(in_commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirect(in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirect(in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDispatch(in_commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDispatchIndirect(in_commandBuffer, in_buffer, offset);
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_srcBuffer = MapHandle<BufferInfo>(srcBuffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectInfoTable::GetBufferInfo);
    const VkBufferCopy* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyBuffer(in_commandBuffer, in_srcBuffer, in_dstBuffer, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkImage in_srcImage = MapHandle<ImageInfo>(srcImage, &VulkanObjectInfoTable::GetImageInfo);
    VkImage in_dstImage = MapHandle<ImageInfo>(dstImage, &VulkanObjectInfoTable::GetImageInfo);
    const VkImageCopy* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
    VkFilter                                    filter)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkImage in_srcImage = MapHandle<ImageInfo>(srcImage, &VulkanObjectInfoTable::GetImageInfo);
    VkImage in_dstImage = MapHandle<ImageInfo>(dstImage, &VulkanObjectInfoTable::GetImageInfo);
    const VkImageBlit* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBlitImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions, filter);
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_srcBuffer = MapHandle<BufferInfo>(srcBuffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkImage in_dstImage = MapHandle<ImageInfo>(dstImage, &VulkanObjectInfoTable::GetImageInfo);
    const VkBufferImageCopy* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage(in_commandBuffer, in_srcBuffer, in_dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkImage in_srcImage = MapHandle<ImageInfo>(srcImage, &VulkanObjectInfoTable::GetImageInfo);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectInfoTable::GetBufferInfo);
    const VkBufferImageCopy* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer(in_commandBuffer, in_srcImage, srcImageLayout, in_dstBuffer, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectInfoTable::GetBufferInfo);
    const void* in_pData = pData->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdUpdateBuffer(in_commandBuffer, in_dstBuffer, dstOffset, dataSize, in_pData);
}

void VulkanReplayConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdFillBuffer(in_commandBuffer, in_dstBuffer, dstOffset, size, data);
}

void VulkanReplayConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectInfoTable::GetImageInfo);
    const VkClearColorValue* in_pColor = pColor->GetPointer();
    const VkImageSubresourceRange* in_pRanges = pRanges->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearColorImage(in_commandBuffer, in_image, imageLayout, in_pColor, rangeCount, in_pRanges);
}

void VulkanReplayConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectInfoTable::GetImageInfo);
    const VkClearDepthStencilValue* in_pDepthStencil = pDepthStencil->GetPointer();
    const VkImageSubresourceRange* in_pRanges = pRanges->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearDepthStencilImage(in_commandBuffer, in_image, imageLayout, in_pDepthStencil, rangeCount, in_pRanges);
}

void VulkanReplayConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkClearAttachment* in_pAttachments = pAttachments->GetPointer();
    const VkClearRect* in_pRects = pRects->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearAttachments(in_commandBuffer, attachmentCount, in_pAttachments, rectCount, in_pRects);
}

void VulkanReplayConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkImage in_srcImage = MapHandle<ImageInfo>(srcImage, &VulkanObjectInfoTable::GetImageInfo);
    VkImage in_dstImage = MapHandle<ImageInfo>(dstImage, &VulkanObjectInfoTable::GetImageInfo);
    const VkImageResolve* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdResolveImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions);
}

void VulkanReplayConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectInfoTable::GetEventInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetEvent(in_commandBuffer, in_event, stageMask);
}

void VulkanReplayConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectInfoTable::GetEventInfo);

    GetDeviceTable(in_commandBuffer)->CmdResetEvent(in_commandBuffer, in_event, stageMask);
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents(
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
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkEvent* in_pEvents = MapHandles<EventInfo>(pEvents, eventCount, &VulkanObjectInfoTable::GetEventInfo);
    const VkMemoryBarrier* in_pMemoryBarriers = pMemoryBarriers->GetPointer();
    const VkBufferMemoryBarrier* in_pBufferMemoryBarriers = pBufferMemoryBarriers->GetPointer();
    MapStructArrayHandles(pBufferMemoryBarriers->GetMetaStructPointer(), pBufferMemoryBarriers->GetLength(), GetObjectInfoTable());
    const VkImageMemoryBarrier* in_pImageMemoryBarriers = pImageMemoryBarriers->GetPointer();
    MapStructArrayHandles(pImageMemoryBarriers->GetMetaStructPointer(), pImageMemoryBarriers->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdWaitEvents(in_commandBuffer, eventCount, in_pEvents, srcStageMask, dstStageMask, memoryBarrierCount, in_pMemoryBarriers, bufferMemoryBarrierCount, in_pBufferMemoryBarriers, imageMemoryBarrierCount, in_pImageMemoryBarriers);
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier(
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
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers)
{
    auto in_commandBuffer = GetObjectInfoTable().GetCommandBufferInfo(commandBuffer);

    MapStructArrayHandles(pBufferMemoryBarriers->GetMetaStructPointer(), pBufferMemoryBarriers->GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(pImageMemoryBarriers->GetMetaStructPointer(), pImageMemoryBarriers->GetLength(), GetObjectInfoTable());

    OverrideCmdPipelineBarrier(GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier, in_commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void VulkanReplayConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdBeginQuery(in_commandBuffer, in_queryPool, query, flags);
}

void VulkanReplayConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndQuery(in_commandBuffer, in_queryPool, query);
}

void VulkanReplayConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdResetQueryPool(in_commandBuffer, in_queryPool, firstQuery, queryCount);
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteTimestamp(in_commandBuffer, pipelineStage, in_queryPool, query);
}

void VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdCopyQueryPoolResults(in_commandBuffer, in_queryPool, firstQuery, queryCount, in_dstBuffer, dstOffset, stride, flags);
}

void VulkanReplayConsumer::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    PointerDecoder<uint8_t>*                    pValues)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkPipelineLayout in_layout = MapHandle<PipelineLayoutInfo>(layout, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    const void* in_pValues = pValues->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdPushConstants(in_commandBuffer, in_layout, stageFlags, offset, size, in_pValues);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkRenderPassBeginInfo* in_pRenderPassBegin = pRenderPassBegin->GetPointer();
    MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginRenderPass(in_commandBuffer, in_pRenderPassBegin, contents);
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass(in_commandBuffer, contents);
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndRenderPass(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCommandBuffer* in_pCommandBuffers = MapHandles<CommandBufferInfo>(pCommandBuffers, commandBufferCount, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdExecuteCommands(in_commandBuffer, commandBufferCount, in_pCommandBuffers);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindBufferMemory2(GetDeviceTable(in_device->handle)->BindBufferMemory2, returnValue, in_device, bindInfoCount, pBindInfos);
    CheckResult("vkBindBufferMemory2", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindImageMemory2(GetDeviceTable(in_device->handle)->BindImageMemory2, returnValue, in_device, bindInfoCount, pBindInfos);
    CheckResult("vkBindImageMemory2", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = pPeerMemoryFeatures->IsNull() ? nullptr : pPeerMemoryFeatures->AllocateOutputData(1, static_cast<VkPeerMemoryFeatureFlags>(0));

    GetDeviceTable(in_device)->GetDeviceGroupPeerMemoryFeatures(in_device, heapIndex, localDeviceIndex, remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDeviceMask(in_commandBuffer, deviceMask);
}

void VulkanReplayConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDispatchBase(in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    pPhysicalDeviceGroupCount->IsNull() ? nullptr : pPhysicalDeviceGroupCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, InstanceInfo>("vkEnumeratePhysicalDeviceGroups", returnValue, instance, kInstanceArrayEnumeratePhysicalDeviceGroups, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties, &VulkanObjectInfoTable::GetInstanceInfo));
    SetStructArrayHandleLengths<Decoded_VkPhysicalDeviceGroupProperties>(pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength());
    if (!pPhysicalDeviceGroupProperties->IsNull()) { pPhysicalDeviceGroupProperties->AllocateOutputData(*pPhysicalDeviceGroupCount->GetOutputPointer(), VkPhysicalDeviceGroupProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, nullptr }); }

    VkResult replay_result = OverrideEnumeratePhysicalDeviceGroups(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDeviceGroups, returnValue, in_instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    CheckResult("vkEnumeratePhysicalDeviceGroups", returnValue, replay_result);

    if (pPhysicalDeviceGroupProperties->IsNull()) { SetOutputArrayCount<InstanceInfo>(instance, kInstanceArrayEnumeratePhysicalDeviceGroups, *pPhysicalDeviceGroupCount->GetOutputPointer(), &VulkanObjectInfoTable::GetInstanceInfo); }
    AddStructArrayHandles<Decoded_VkPhysicalDeviceGroupProperties>(instance, pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength(), pPhysicalDeviceGroupProperties->GetOutputPointer(), *pPhysicalDeviceGroupCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkImageMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageMemoryRequirements2(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkBufferMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetBufferMemoryRequirements2(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkImageSparseMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetImageSparseMemoryRequirements2", VK_SUCCESS, device, kDeviceArrayGetImageSparseMemoryRequirements2, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &VulkanObjectInfoTable::GetDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements2(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetImageSparseMemoryRequirements2, *out_pSparseMemoryRequirementCount, &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkPhysicalDeviceFeatures2* out_pFeatures = pFeatures->IsNull() ? nullptr : pFeatures->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures2(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, nullptr });

    OverrideGetPhysicalDeviceProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties2, in_physicalDevice, pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkFormatProperties2* out_pFormatProperties = pFormatProperties->IsNull() ? nullptr : pFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties2(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = pImageFormatInfo->GetPointer();
    VkImageFormatProperties2* out_pImageFormatProperties = pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties2(in_physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties2", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pQueueFamilyPropertyCount = pQueueFamilyPropertyCount->IsNull() ? nullptr : pQueueFamilyPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties2", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2, pQueueFamilyPropertyCount, pQueueFamilyProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkQueueFamilyProperties2* out_pQueueFamilyProperties = pQueueFamilyProperties->IsNull() ? nullptr : pQueueFamilyProperties->AllocateOutputData(*out_pQueueFamilyPropertyCount, VkQueueFamilyProperties2{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    if (pQueueFamilyProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2, *out_pQueueFamilyPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pMemoryProperties->IsNull() ? nullptr : pMemoryProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, nullptr });

    OverrideGetPhysicalDeviceMemoryProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties2, in_physicalDevice, pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = pFormatInfo->GetPointer();
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties2", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkSparseImageFormatProperties2* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkSparseImageFormatProperties2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(in_physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2, *out_pPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkCommandPool in_commandPool = MapHandle<CommandPoolInfo>(commandPool, &VulkanObjectInfoTable::GetCommandPoolInfo);

    GetDeviceTable(in_device)->TrimCommandPool(in_device, in_commandPool, flags);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDeviceQueueInfo2* in_pQueueInfo = pQueueInfo->GetPointer();
    if (!pQueue->IsNull()) { pQueue->SetHandleLength(1); }
    VkQueue* out_pQueue = pQueue->GetHandlePointer();

    GetDeviceTable(in_device)->GetDeviceQueue2(in_device, in_pQueueInfo, out_pQueue);

    AddHandle<QueueInfo>(device, pQueue->GetPointer(), out_pQueue, &VulkanObjectInfoTable::AddQueueInfo);
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSamplerYcbcrConversionCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pYcbcrConversion->IsNull()) { pYcbcrConversion->SetHandleLength(1); }
    VkSamplerYcbcrConversion* out_pYcbcrConversion = pYcbcrConversion->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSamplerYcbcrConversion(in_device, in_pCreateInfo, in_pAllocator, out_pYcbcrConversion);
    CheckResult("vkCreateSamplerYcbcrConversion", returnValue, replay_result);

    AddHandle<SamplerYcbcrConversionInfo>(device, pYcbcrConversion->GetPointer(), out_pYcbcrConversion, &VulkanObjectInfoTable::AddSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSamplerYcbcrConversion in_ycbcrConversion = MapHandle<SamplerYcbcrConversionInfo>(ycbcrConversion, &VulkanObjectInfoTable::GetSamplerYcbcrConversionInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySamplerYcbcrConversion(in_device, in_ycbcrConversion, in_pAllocator);
    RemoveHandle(ycbcrConversion, &VulkanObjectInfoTable::RemoveSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDescriptorUpdateTemplate->IsNull()) { pDescriptorUpdateTemplate->SetHandleLength(1); }
    DescriptorUpdateTemplateInfo handle_info;
    pDescriptorUpdateTemplate->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->CreateDescriptorUpdateTemplate, returnValue, in_device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    CheckResult("vkCreateDescriptorUpdateTemplate", returnValue, replay_result);

    AddHandle<DescriptorUpdateTemplateInfo>(device, pDescriptorUpdateTemplate->GetPointer(), pDescriptorUpdateTemplate->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorUpdateTemplate = GetObjectInfoTable().GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    OverrideDestroyDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->DestroyDescriptorUpdateTemplate, in_device, in_descriptorUpdateTemplate, pAllocator);
    RemoveHandle(descriptorUpdateTemplate, &VulkanObjectInfoTable::RemoveDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = pExternalBufferInfo->GetPointer();
    VkExternalBufferProperties* out_pExternalBufferProperties = pExternalBufferProperties->IsNull() ? nullptr : pExternalBufferProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalBufferProperties(in_physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = pExternalFenceInfo->GetPointer();
    VkExternalFenceProperties* out_pExternalFenceProperties = pExternalFenceProperties->IsNull() ? nullptr : pExternalFenceProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalFenceProperties(in_physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = pExternalSemaphoreInfo->GetPointer();
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = pExternalSemaphoreProperties->IsNull() ? nullptr : pExternalSemaphoreProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(in_physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkDescriptorSetLayoutSupport* out_pSupport = pSupport->IsNull() ? nullptr : pSupport->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, nullptr });

    GetDeviceTable(in_device)->GetDescriptorSetLayoutSupport(in_device, in_pCreateInfo, out_pSupport);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCount(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCount(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pRenderPass->IsNull()) { pRenderPass->SetHandleLength(1); }
    RenderPassInfo handle_info;
    pRenderPass->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateRenderPass2(GetDeviceTable(in_device->handle)->CreateRenderPass2, returnValue, in_device, pCreateInfo, pAllocator, pRenderPass);
    CheckResult("vkCreateRenderPass2", returnValue, replay_result);

    AddHandle<RenderPassInfo>(device, pRenderPass->GetPointer(), pRenderPass->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkRenderPassBeginInfo* in_pRenderPassBegin = pRenderPassBegin->GetPointer();
    MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());
    const VkSubpassBeginInfo* in_pSubpassBeginInfo = pSubpassBeginInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBeginRenderPass2(in_commandBuffer, in_pRenderPassBegin, in_pSubpassBeginInfo);
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkSubpassBeginInfo* in_pSubpassBeginInfo = pSubpassBeginInfo->GetPointer();
    const VkSubpassEndInfo* in_pSubpassEndInfo = pSubpassEndInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass2(in_commandBuffer, in_pSubpassBeginInfo, in_pSubpassEndInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkSubpassEndInfo* in_pSubpassEndInfo = pSubpassEndInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndRenderPass2(in_commandBuffer, in_pSubpassEndInfo);
}

void VulkanReplayConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_device)->ResetQueryPool(in_device, in_queryPool, firstQuery, queryCount);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreCounterValue(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSemaphore in_semaphore = MapHandle<SemaphoreInfo>(semaphore, &VulkanObjectInfoTable::GetSemaphoreInfo);
    uint64_t* out_pValue = pValue->IsNull() ? nullptr : pValue->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreCounterValue(in_device, in_semaphore, out_pValue);
    CheckResult("vkGetSemaphoreCounterValue", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSemaphoreWaitInfo* in_pWaitInfo = pWaitInfo->GetPointer();
    MapStructHandles(pWaitInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->WaitSemaphores(in_device, in_pWaitInfo, timeout);
    CheckResult("vkWaitSemaphores", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSemaphoreSignalInfo* in_pSignalInfo = pSignalInfo->GetPointer();
    MapStructHandles(pSignalInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->SignalSemaphore(in_device, in_pSignalInfo);
    CheckResult("vkSignalSemaphore", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetBufferDeviceAddress(GetDeviceTable(in_device->handle)->GetBufferDeviceAddress, in_device, pInfo);
}

void VulkanReplayConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkBufferDeviceAddressInfo* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetBufferOpaqueCaptureAddress(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDeviceMemoryOpaqueCaptureAddressInfo* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetDeviceMemoryOpaqueCaptureAddress(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pToolCount = pToolCount->IsNull() ? nullptr : pToolCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceToolProperties", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolProperties, pToolCount, pToolProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkPhysicalDeviceToolProperties* out_pToolProperties = pToolProperties->IsNull() ? nullptr : pToolProperties->AllocateOutputData(*out_pToolCount, VkPhysicalDeviceToolProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceToolProperties(in_physicalDevice, out_pToolCount, out_pToolProperties);
    CheckResult("vkGetPhysicalDeviceToolProperties", returnValue, replay_result);

    if (pToolProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolProperties, *out_pToolCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkPrivateDataSlotCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pPrivateDataSlot->IsNull()) { pPrivateDataSlot->SetHandleLength(1); }
    VkPrivateDataSlot* out_pPrivateDataSlot = pPrivateDataSlot->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreatePrivateDataSlot(in_device, in_pCreateInfo, in_pAllocator, out_pPrivateDataSlot);
    CheckResult("vkCreatePrivateDataSlot", returnValue, replay_result);

    AddHandle<PrivateDataSlotInfo>(device, pPrivateDataSlot->GetPointer(), out_pPrivateDataSlot, &VulkanObjectInfoTable::AddPrivateDataSlotInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<PrivateDataSlotInfo>(privateDataSlot, &VulkanObjectInfoTable::GetPrivateDataSlotInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPrivateDataSlot(in_device, in_privateDataSlot, in_pAllocator);
    RemoveHandle(privateDataSlot, &VulkanObjectInfoTable::RemovePrivateDataSlotInfo);
}

void VulkanReplayConsumer::Process_vkSetPrivateData(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<PrivateDataSlotInfo>(privateDataSlot, &VulkanObjectInfoTable::GetPrivateDataSlotInfo);

    VkResult replay_result = GetDeviceTable(in_device)->SetPrivateData(in_device, objectType, in_objectHandle, in_privateDataSlot, data);
    CheckResult("vkSetPrivateData", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<PrivateDataSlotInfo>(privateDataSlot, &VulkanObjectInfoTable::GetPrivateDataSlotInfo);
    uint64_t* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(1, static_cast<uint64_t>(0));

    GetDeviceTable(in_device)->GetPrivateData(in_device, objectType, in_objectHandle, in_privateDataSlot, out_pData);
}

void VulkanReplayConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectInfoTable::GetEventInfo);
    const VkDependencyInfo* in_pDependencyInfo = pDependencyInfo->GetPointer();
    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetEvent2(in_commandBuffer, in_event, in_pDependencyInfo);
}

void VulkanReplayConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectInfoTable::GetEventInfo);

    GetDeviceTable(in_commandBuffer)->CmdResetEvent2(in_commandBuffer, in_event, stageMask);
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkEvent* in_pEvents = MapHandles<EventInfo>(pEvents, eventCount, &VulkanObjectInfoTable::GetEventInfo);
    const VkDependencyInfo* in_pDependencyInfos = pDependencyInfos->GetPointer();
    MapStructArrayHandles(pDependencyInfos->GetMetaStructPointer(), pDependencyInfos->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdWaitEvents2(in_commandBuffer, eventCount, in_pEvents, in_pDependencyInfos);
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkDependencyInfo* in_pDependencyInfo = pDependencyInfo->GetPointer();
    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPipelineBarrier2(in_commandBuffer, in_pDependencyInfo);
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteTimestamp2(in_commandBuffer, stage, in_queryPool, query);
}

void VulkanReplayConsumer::Process_vkQueueSubmit2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

    MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

    VkResult replay_result = OverrideQueueSubmit2(GetDeviceTable(in_queue->handle)->QueueSubmit2, returnValue, in_queue, submitCount, pSubmits, in_fence);
    CheckResult("vkQueueSubmit2", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyBufferInfo2* in_pCopyBufferInfo = pCopyBufferInfo->GetPointer();
    MapStructHandles(pCopyBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyBuffer2(in_commandBuffer, in_pCopyBufferInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyImageInfo2* in_pCopyImageInfo = pCopyImageInfo->GetPointer();
    MapStructHandles(pCopyImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyImage2(in_commandBuffer, in_pCopyImageInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyBufferToImageInfo2* in_pCopyBufferToImageInfo = pCopyBufferToImageInfo->GetPointer();
    MapStructHandles(pCopyBufferToImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage2(in_commandBuffer, in_pCopyBufferToImageInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyImageToBufferInfo2* in_pCopyImageToBufferInfo = pCopyImageToBufferInfo->GetPointer();
    MapStructHandles(pCopyImageToBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer2(in_commandBuffer, in_pCopyImageToBufferInfo);
}

void VulkanReplayConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkBlitImageInfo2* in_pBlitImageInfo = pBlitImageInfo->GetPointer();
    MapStructHandles(pBlitImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBlitImage2(in_commandBuffer, in_pBlitImageInfo);
}

void VulkanReplayConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkResolveImageInfo2* in_pResolveImageInfo = pResolveImageInfo->GetPointer();
    MapStructHandles(pResolveImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdResolveImage2(in_commandBuffer, in_pResolveImageInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkRenderingInfo* in_pRenderingInfo = pRenderingInfo->GetPointer();
    MapStructHandles(pRenderingInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginRendering(in_commandBuffer, in_pRenderingInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndRendering(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCullMode(in_commandBuffer, cullMode);
}

void VulkanReplayConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetFrontFace(in_commandBuffer, frontFace);
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveTopology(in_commandBuffer, primitiveTopology);
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkViewport* in_pViewports = pViewports->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWithCount(in_commandBuffer, viewportCount, in_pViewports);
}

void VulkanReplayConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkRect2D* in_pScissors = pScissors->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetScissorWithCount(in_commandBuffer, scissorCount, in_pScissors);
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<BufferInfo>(pBuffers, bindingCount, &VulkanObjectInfoTable::GetBufferInfo);
    const VkDeviceSize* in_pOffsets = pOffsets->GetPointer();
    const VkDeviceSize* in_pSizes = pSizes->GetPointer();
    const VkDeviceSize* in_pStrides = pStrides->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers2(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets, in_pSizes, in_pStrides);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthTestEnable(in_commandBuffer, depthTestEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthWriteEnable(in_commandBuffer, depthWriteEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthCompareOp(in_commandBuffer, depthCompareOp);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBoundsTestEnable(in_commandBuffer, depthBoundsTestEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilTestEnable(in_commandBuffer, stencilTestEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilOp(in_commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizerDiscardEnable(in_commandBuffer, rasterizerDiscardEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBiasEnable(in_commandBuffer, depthBiasEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveRestartEnable(in_commandBuffer, primitiveRestartEnable);
}

void VulkanReplayConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDeviceBufferMemoryRequirements* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetDeviceBufferMemoryRequirements(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetDeviceImageMemoryRequirements(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetDeviceImageSparseMemoryRequirements", VK_SUCCESS, device, kDeviceArrayGetDeviceImageSparseMemoryRequirements, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &VulkanObjectInfoTable::GetDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetDeviceImageSparseMemoryRequirements(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetDeviceImageSparseMemoryRequirements, *out_pSparseMemoryRequirementCount, &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    auto in_surface = GetObjectInfoTable().GetSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }

    OverrideDestroySurfaceKHR(GetInstanceTable(in_instance->handle)->DestroySurfaceKHR, in_instance, in_surface, pAllocator);
    RemoveHandle(surface, &VulkanObjectInfoTable::RemoveSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectInfoTable::GetSurfaceKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    VkBool32* out_pSupported = pSupported->IsNull() ? nullptr : pSupported->AllocateOutputData(1, static_cast<VkBool32>(0));

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(in_physicalDevice, queueFamilyIndex, in_surface, out_pSupported);
    CheckResult("vkGetPhysicalDeviceSurfaceSupportKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    auto in_surface = GetObjectInfoTable().GetSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    pSurfaceCapabilities->IsNull() ? nullptr : pSurfaceCapabilities->AllocateOutputData(1);

    VkResult replay_result = OverrideGetPhysicalDeviceSurfaceCapabilitiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceCapabilitiesKHR, returnValue, in_physicalDevice, in_surface, pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilitiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectInfoTable::GetSurfaceKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    uint32_t* out_pSurfaceFormatCount = pSurfaceFormatCount->IsNull() ? nullptr : pSurfaceFormatCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, SurfaceKHRInfo>("vkGetPhysicalDeviceSurfaceFormatsKHR", returnValue, surface, kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR, pSurfaceFormatCount, pSurfaceFormats, &VulkanObjectInfoTable::GetSurfaceKHRInfo));
    VkSurfaceFormatKHR* out_pSurfaceFormats = pSurfaceFormats->IsNull() ? nullptr : pSurfaceFormats->AllocateOutputData(*out_pSurfaceFormatCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(in_physicalDevice, in_surface, out_pSurfaceFormatCount, out_pSurfaceFormats);
    CheckResult("vkGetPhysicalDeviceSurfaceFormatsKHR", returnValue, replay_result);

    if (pSurfaceFormats->IsNull()) { SetOutputArrayCount<SurfaceKHRInfo>(surface, kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR, *out_pSurfaceFormatCount, &VulkanObjectInfoTable::GetSurfaceKHRInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectInfoTable::GetSurfaceKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    uint32_t* out_pPresentModeCount = pPresentModeCount->IsNull() ? nullptr : pPresentModeCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, SurfaceKHRInfo>("vkGetPhysicalDeviceSurfacePresentModesKHR", returnValue, surface, kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR, pPresentModeCount, pPresentModes, &VulkanObjectInfoTable::GetSurfaceKHRInfo));
    VkPresentModeKHR* out_pPresentModes = pPresentModes->IsNull() ? nullptr : pPresentModes->AllocateOutputData(*out_pPresentModeCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(in_physicalDevice, in_surface, out_pPresentModeCount, out_pPresentModes);
    CheckResult("vkGetPhysicalDeviceSurfacePresentModesKHR", returnValue, replay_result);

    if (pPresentModes->IsNull()) { SetOutputArrayCount<SurfaceKHRInfo>(surface, kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR, *out_pPresentModeCount, &VulkanObjectInfoTable::GetSurfaceKHRInfo); }
}

void VulkanReplayConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pSwapchain->IsNull()) { pSwapchain->SetHandleLength(1); }
    SwapchainKHRInfo handle_info;
    pSwapchain->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateSwapchainKHR(GetDeviceTable(in_device->handle)->CreateSwapchainKHR, returnValue, in_device, pCreateInfo, pAllocator, pSwapchain);
    CheckResult("vkCreateSwapchainKHR", returnValue, replay_result);

    AddHandle<SwapchainKHRInfo>(device, pSwapchain->GetPointer(), pSwapchain->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSwapchainKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);

    OverrideDestroySwapchainKHR(GetDeviceTable(in_device->handle)->DestroySwapchainKHR, in_device, in_swapchain, pAllocator);
    RemoveHandle(swapchain, &VulkanObjectInfoTable::RemoveSwapchainKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);
    pSwapchainImageCount->IsNull() ? nullptr : pSwapchainImageCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, SwapchainKHRInfo>("vkGetSwapchainImagesKHR", returnValue, swapchain, kSwapchainKHRArrayGetSwapchainImagesKHR, pSwapchainImageCount, pSwapchainImages, &VulkanObjectInfoTable::GetSwapchainKHRInfo));
    if (!pSwapchainImages->IsNull()) { pSwapchainImages->SetHandleLength(*pSwapchainImageCount->GetOutputPointer()); }
    std::vector<ImageInfo> handle_info(*pSwapchainImageCount->GetOutputPointer());
    for (size_t i = 0; i < *pSwapchainImageCount->GetOutputPointer(); ++i) { pSwapchainImages->SetConsumerData(i, &handle_info[i]); }

    VkResult replay_result = OverrideGetSwapchainImagesKHR(GetDeviceTable(in_device->handle)->GetSwapchainImagesKHR, returnValue, in_device, in_swapchain, pSwapchainImageCount, pSwapchainImages);
    CheckResult("vkGetSwapchainImagesKHR", returnValue, replay_result);

    if (pSwapchainImages->IsNull()) { SetOutputArrayCount<SwapchainKHRInfo>(swapchain, kSwapchainKHRArrayGetSwapchainImagesKHR, *pSwapchainImageCount->GetOutputPointer(), &VulkanObjectInfoTable::GetSwapchainKHRInfo); }
    AddHandles<ImageInfo>(device, pSwapchainImages->GetPointer(), pSwapchainImages->GetLength(), pSwapchainImages->GetHandlePointer(), *pSwapchainImageCount->GetOutputPointer(), std::move(handle_info), &VulkanObjectInfoTable::AddImageInfo);
}

void VulkanReplayConsumer::Process_vkAcquireNextImageKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    timeout,
    format::HandleId                            semaphore,
    format::HandleId                            fence,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetSwapchainKHRInfo(swapchain);
    auto in_semaphore = GetObjectInfoTable().GetSemaphoreInfo(semaphore);
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);
    pImageIndex->IsNull() ? nullptr : pImageIndex->AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = OverrideAcquireNextImageKHR(GetDeviceTable(in_device->handle)->AcquireNextImageKHR, returnValue, in_device, in_swapchain, timeout, in_semaphore, in_fence, pImageIndex);
    CheckResult("vkAcquireNextImageKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

    MapStructHandles(pPresentInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideQueuePresentKHR(GetDeviceTable(in_queue->handle)->QueuePresentKHR, returnValue, in_queue, pPresentInfo);
    CheckResult("vkQueuePresentKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeviceGroupPresentCapabilitiesKHR* out_pDeviceGroupPresentCapabilities = pDeviceGroupPresentCapabilities->IsNull() ? nullptr : pDeviceGroupPresentCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupPresentCapabilitiesKHR(in_device, out_pDeviceGroupPresentCapabilities);
    CheckResult("vkGetDeviceGroupPresentCapabilitiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectInfoTable::GetSurfaceKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    VkDeviceGroupPresentModeFlagsKHR* out_pModes = pModes->IsNull() ? nullptr : pModes->AllocateOutputData(1, static_cast<VkDeviceGroupPresentModeFlagsKHR>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupSurfacePresentModesKHR(in_device, in_surface, out_pModes);
    CheckResult("vkGetDeviceGroupSurfacePresentModesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectInfoTable::GetSurfaceKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    uint32_t* out_pRectCount = pRectCount->IsNull() ? nullptr : pRectCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, SurfaceKHRInfo>("vkGetPhysicalDevicePresentRectanglesKHR", returnValue, surface, kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR, pRectCount, pRects, &VulkanObjectInfoTable::GetSurfaceKHRInfo));
    VkRect2D* out_pRects = pRects->IsNull() ? nullptr : pRects->AllocateOutputData(*out_pRectCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(in_physicalDevice, in_surface, out_pRectCount, out_pRects);
    CheckResult("vkGetPhysicalDevicePresentRectanglesKHR", returnValue, replay_result);

    if (pRects->IsNull()) { SetOutputArrayCount<SurfaceKHRInfo>(surface, kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR, *out_pRectCount, &VulkanObjectInfoTable::GetSurfaceKHRInfo); }
}

void VulkanReplayConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pAcquireInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pImageIndex->IsNull() ? nullptr : pImageIndex->AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = OverrideAcquireNextImage2KHR(GetDeviceTable(in_device->handle)->AcquireNextImage2KHR, returnValue, in_device, pAcquireInfo, pImageIndex);
    CheckResult("vkAcquireNextImage2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPropertiesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkDisplayPropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPropertiesKHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR, *out_pPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayPropertiesKHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkDisplayPlanePropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR, *out_pPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayPlanePropertiesKHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    planeIndex,
    PointerDecoder<uint32_t>*                   pDisplayCount,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplays)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pDisplayCount = pDisplayCount->IsNull() ? nullptr : pDisplayCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetDisplayPlaneSupportedDisplaysKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR, pDisplayCount, pDisplays, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    if (!pDisplays->IsNull()) { pDisplays->SetHandleLength(*out_pDisplayCount); }
    VkDisplayKHR* out_pDisplays = pDisplays->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(in_physicalDevice, planeIndex, out_pDisplayCount, out_pDisplays);
    CheckResult("vkGetDisplayPlaneSupportedDisplaysKHR", returnValue, replay_result);

    if (pDisplays->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR, *out_pDisplayCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    AddHandles<DisplayKHRInfo>(physicalDevice, pDisplays->GetPointer(), pDisplays->GetLength(), out_pDisplays, *out_pDisplayCount, &VulkanObjectInfoTable::AddDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectInfoTable::GetDisplayKHRInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DisplayKHRInfo>("vkGetDisplayModePropertiesKHR", returnValue, display, kDisplayKHRArrayGetDisplayModePropertiesKHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetDisplayKHRInfo));
    VkDisplayModePropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayModePropertiesKHR(in_physicalDevice, in_display, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetDisplayModePropertiesKHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<DisplayKHRInfo>(display, kDisplayKHRArrayGetDisplayModePropertiesKHR, *out_pPropertyCount, &VulkanObjectInfoTable::GetDisplayKHRInfo); }
    AddStructArrayHandles<Decoded_VkDisplayModePropertiesKHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDisplayModeKHR>*     pMode)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectInfoTable::GetDisplayKHRInfo);
    const VkDisplayModeCreateInfoKHR* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pMode->IsNull()) { pMode->SetHandleLength(1); }
    VkDisplayModeKHR* out_pMode = pMode->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->CreateDisplayModeKHR(in_physicalDevice, in_display, in_pCreateInfo, in_pAllocator, out_pMode);
    CheckResult("vkCreateDisplayModeKHR", returnValue, replay_result);

    AddHandle<DisplayModeKHRInfo>(physicalDevice, pMode->GetPointer(), out_pMode, &VulkanObjectInfoTable::AddDisplayModeKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkDisplayModeKHR in_mode = MapHandle<DisplayModeKHRInfo>(mode, &VulkanObjectInfoTable::GetDisplayModeKHRInfo);
    VkDisplayPlaneCapabilitiesKHR* out_pCapabilities = pCapabilities->IsNull() ? nullptr : pCapabilities->AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneCapabilitiesKHR(in_physicalDevice, in_mode, planeIndex, out_pCapabilities);
    CheckResult("vkGetDisplayPlaneCapabilitiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkDisplaySurfaceCreateInfoKHR* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateDisplayPlaneSurfaceKHR(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateDisplayPlaneSurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSwapchainCreateInfoKHR* in_pCreateInfos = pCreateInfos->GetPointer();
    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSwapchains->IsNull()) { pSwapchains->SetHandleLength(swapchainCount); }
    VkSwapchainKHR* out_pSwapchains = pSwapchains->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSharedSwapchainsKHR(in_device, swapchainCount, in_pCreateInfos, in_pAllocator, out_pSwapchains);
    CheckResult("vkCreateSharedSwapchainsKHR", returnValue, replay_result);

    AddHandles<SwapchainKHRInfo>(device, pSwapchains->GetPointer(), pSwapchains->GetLength(), out_pSwapchains, swapchainCount, &VulkanObjectInfoTable::AddSwapchainKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateXlibSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateXlibSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateXlibSurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR, "vkGetPhysicalDeviceXlibPresentationSupportKHR"));

    OverrideGetPhysicalDeviceXlibPresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceXlibPresentationSupportKHR, in_physicalDevice, queueFamilyIndex, in_dpy, visualID);
}

void VulkanReplayConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateXcbSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateXcbSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateXcbSurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    xcb_connection_t* in_connection = static_cast<xcb_connection_t*>(PreProcessExternalObject(connection, format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR, "vkGetPhysicalDeviceXcbPresentationSupportKHR"));

    OverrideGetPhysicalDeviceXcbPresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceXcbPresentationSupportKHR, in_physicalDevice, queueFamilyIndex, in_connection, visual_id);
}

void VulkanReplayConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateWaylandSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateWaylandSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateWaylandSurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    struct wl_display* in_display = static_cast<struct wl_display*>(PreProcessExternalObject(display, format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR, "vkGetPhysicalDeviceWaylandPresentationSupportKHR"));

    OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceWaylandPresentationSupportKHR, in_physicalDevice, queueFamilyIndex, in_display);
}

void VulkanReplayConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateAndroidSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateAndroidSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateAndroidSurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    SurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateWin32SurfaceKHR(GetInstanceTable(in_instance->handle)->CreateWin32SurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateWin32SurfaceKHR", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);

    OverrideGetPhysicalDeviceWin32PresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceWin32PresentationSupportKHR, in_physicalDevice, queueFamilyIndex);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile,
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkVideoProfileInfoKHR* in_pVideoProfile = pVideoProfile->GetPointer();
    VkVideoCapabilitiesKHR* out_pCapabilities = pCapabilities->IsNull() ? nullptr : pCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceVideoCapabilitiesKHR(in_physicalDevice, in_pVideoProfile, out_pCapabilities);
    CheckResult("vkGetPhysicalDeviceVideoCapabilitiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo,
    PointerDecoder<uint32_t>*                   pVideoFormatPropertyCount,
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceVideoFormatInfoKHR* in_pVideoFormatInfo = pVideoFormatInfo->GetPointer();
    uint32_t* out_pVideoFormatPropertyCount = pVideoFormatPropertyCount->IsNull() ? nullptr : pVideoFormatPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceVideoFormatPropertiesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceVideoFormatPropertiesKHR, pVideoFormatPropertyCount, pVideoFormatProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkVideoFormatPropertiesKHR* out_pVideoFormatProperties = pVideoFormatProperties->IsNull() ? nullptr : pVideoFormatProperties->AllocateOutputData(*out_pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR{ VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceVideoFormatPropertiesKHR(in_physicalDevice, in_pVideoFormatInfo, out_pVideoFormatPropertyCount, out_pVideoFormatProperties);
    CheckResult("vkGetPhysicalDeviceVideoFormatPropertiesKHR", returnValue, replay_result);

    if (pVideoFormatProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceVideoFormatPropertiesKHR, *out_pVideoFormatPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionKHR>*    pVideoSession)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkVideoSessionCreateInfoKHR* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pVideoSession->IsNull()) { pVideoSession->SetHandleLength(1); }
    VkVideoSessionKHR* out_pVideoSession = pVideoSession->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateVideoSessionKHR(in_device, in_pCreateInfo, in_pAllocator, out_pVideoSession);
    CheckResult("vkCreateVideoSessionKHR", returnValue, replay_result);

    AddHandle<VideoSessionKHRInfo>(device, pVideoSession->GetPointer(), out_pVideoSession, &VulkanObjectInfoTable::AddVideoSessionKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkVideoSessionKHR in_videoSession = MapHandle<VideoSessionKHRInfo>(videoSession, &VulkanObjectInfoTable::GetVideoSessionKHRInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyVideoSessionKHR(in_device, in_videoSession, in_pAllocator);
    RemoveHandle(videoSession, &VulkanObjectInfoTable::RemoveVideoSessionKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetVideoSessionMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    PointerDecoder<uint32_t>*                   pMemoryRequirementsCount,
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkVideoSessionKHR in_videoSession = MapHandle<VideoSessionKHRInfo>(videoSession, &VulkanObjectInfoTable::GetVideoSessionKHRInfo);
    uint32_t* out_pMemoryRequirementsCount = pMemoryRequirementsCount->IsNull() ? nullptr : pMemoryRequirementsCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VideoSessionKHRInfo>("vkGetVideoSessionMemoryRequirementsKHR", returnValue, videoSession, kVideoSessionKHRArrayGetVideoSessionMemoryRequirementsKHR, pMemoryRequirementsCount, pMemoryRequirements, &VulkanObjectInfoTable::GetVideoSessionKHRInfo));
    VkVideoSessionMemoryRequirementsKHR* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(*out_pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR{ VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetVideoSessionMemoryRequirementsKHR(in_device, in_videoSession, out_pMemoryRequirementsCount, out_pMemoryRequirements);
    CheckResult("vkGetVideoSessionMemoryRequirementsKHR", returnValue, replay_result);

    if (pMemoryRequirements->IsNull()) { SetOutputArrayCount<VideoSessionKHRInfo>(videoSession, kVideoSessionKHRArrayGetVideoSessionMemoryRequirementsKHR, *out_pMemoryRequirementsCount, &VulkanObjectInfoTable::GetVideoSessionKHRInfo); }
}

void VulkanReplayConsumer::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkVideoSessionKHR in_videoSession = MapHandle<VideoSessionKHRInfo>(videoSession, &VulkanObjectInfoTable::GetVideoSessionKHRInfo);
    const VkBindVideoSessionMemoryInfoKHR* in_pBindSessionMemoryInfos = pBindSessionMemoryInfos->GetPointer();
    MapStructArrayHandles(pBindSessionMemoryInfos->GetMetaStructPointer(), pBindSessionMemoryInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->BindVideoSessionMemoryKHR(in_device, in_videoSession, bindSessionMemoryInfoCount, in_pBindSessionMemoryInfos);
    CheckResult("vkBindVideoSessionMemoryKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkVideoSessionParametersCreateInfoKHR* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pVideoSessionParameters->IsNull()) { pVideoSessionParameters->SetHandleLength(1); }
    VkVideoSessionParametersKHR* out_pVideoSessionParameters = pVideoSessionParameters->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateVideoSessionParametersKHR(in_device, in_pCreateInfo, in_pAllocator, out_pVideoSessionParameters);
    CheckResult("vkCreateVideoSessionParametersKHR", returnValue, replay_result);

    AddHandle<VideoSessionParametersKHRInfo>(device, pVideoSessionParameters->GetPointer(), out_pVideoSessionParameters, &VulkanObjectInfoTable::AddVideoSessionParametersKHRInfo);
}

void VulkanReplayConsumer::Process_vkUpdateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkVideoSessionParametersKHR in_videoSessionParameters = MapHandle<VideoSessionParametersKHRInfo>(videoSessionParameters, &VulkanObjectInfoTable::GetVideoSessionParametersKHRInfo);
    const VkVideoSessionParametersUpdateInfoKHR* in_pUpdateInfo = pUpdateInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->UpdateVideoSessionParametersKHR(in_device, in_videoSessionParameters, in_pUpdateInfo);
    CheckResult("vkUpdateVideoSessionParametersKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkVideoSessionParametersKHR in_videoSessionParameters = MapHandle<VideoSessionParametersKHRInfo>(videoSessionParameters, &VulkanObjectInfoTable::GetVideoSessionParametersKHRInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyVideoSessionParametersKHR(in_device, in_videoSessionParameters, in_pAllocator);
    RemoveHandle(videoSessionParameters, &VulkanObjectInfoTable::RemoveVideoSessionParametersKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkVideoBeginCodingInfoKHR* in_pBeginInfo = pBeginInfo->GetPointer();
    MapStructHandles(pBeginInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginVideoCodingKHR(in_commandBuffer, in_pBeginInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkVideoEndCodingInfoKHR* in_pEndCodingInfo = pEndCodingInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndVideoCodingKHR(in_commandBuffer, in_pEndCodingInfo);
}

void VulkanReplayConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkVideoCodingControlInfoKHR* in_pCodingControlInfo = pCodingControlInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdControlVideoCodingKHR(in_commandBuffer, in_pCodingControlInfo);
}

void VulkanReplayConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkVideoDecodeInfoKHR* in_pDecodeInfo = pDecodeInfo->GetPointer();
    MapStructHandles(pDecodeInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDecodeVideoKHR(in_commandBuffer, in_pDecodeInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkRenderingInfo* in_pRenderingInfo = pRenderingInfo->GetPointer();
    MapStructHandles(pRenderingInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginRenderingKHR(in_commandBuffer, in_pRenderingInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndRenderingKHR(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkPhysicalDeviceFeatures2* out_pFeatures = pFeatures->IsNull() ? nullptr : pFeatures->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures2KHR(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, nullptr });

    OverrideGetPhysicalDeviceProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties2KHR, in_physicalDevice, pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkFormatProperties2* out_pFormatProperties = pFormatProperties->IsNull() ? nullptr : pFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = pImageFormatInfo->GetPointer();
    VkImageFormatProperties2* out_pImageFormatProperties = pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(in_physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pQueueFamilyPropertyCount = pQueueFamilyPropertyCount->IsNull() ? nullptr : pQueueFamilyPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties2KHR", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR, pQueueFamilyPropertyCount, pQueueFamilyProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkQueueFamilyProperties2* out_pQueueFamilyProperties = pQueueFamilyProperties->IsNull() ? nullptr : pQueueFamilyProperties->AllocateOutputData(*out_pQueueFamilyPropertyCount, VkQueueFamilyProperties2{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    if (pQueueFamilyProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR, *out_pQueueFamilyPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    pMemoryProperties->IsNull() ? nullptr : pMemoryProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, nullptr });

    OverrideGetPhysicalDeviceMemoryProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties2KHR, in_physicalDevice, pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = pFormatInfo->GetPointer();
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties2KHR", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkSparseImageFormatProperties2* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkSparseImageFormatProperties2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(in_physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR, *out_pPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = pPeerMemoryFeatures->IsNull() ? nullptr : pPeerMemoryFeatures->AllocateOutputData(1, static_cast<VkPeerMemoryFeatureFlags>(0));

    GetDeviceTable(in_device)->GetDeviceGroupPeerMemoryFeaturesKHR(in_device, heapIndex, localDeviceIndex, remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDeviceMaskKHR(in_commandBuffer, deviceMask);
}

void VulkanReplayConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDispatchBaseKHR(in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkCommandPool in_commandPool = MapHandle<CommandPoolInfo>(commandPool, &VulkanObjectInfoTable::GetCommandPoolInfo);

    GetDeviceTable(in_device)->TrimCommandPoolKHR(in_device, in_commandPool, flags);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    pPhysicalDeviceGroupCount->IsNull() ? nullptr : pPhysicalDeviceGroupCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, InstanceInfo>("vkEnumeratePhysicalDeviceGroupsKHR", returnValue, instance, kInstanceArrayEnumeratePhysicalDeviceGroupsKHR, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties, &VulkanObjectInfoTable::GetInstanceInfo));
    SetStructArrayHandleLengths<Decoded_VkPhysicalDeviceGroupProperties>(pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength());
    if (!pPhysicalDeviceGroupProperties->IsNull()) { pPhysicalDeviceGroupProperties->AllocateOutputData(*pPhysicalDeviceGroupCount->GetOutputPointer(), VkPhysicalDeviceGroupProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, nullptr }); }

    VkResult replay_result = OverrideEnumeratePhysicalDeviceGroups(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDeviceGroupsKHR, returnValue, in_instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    CheckResult("vkEnumeratePhysicalDeviceGroupsKHR", returnValue, replay_result);

    if (pPhysicalDeviceGroupProperties->IsNull()) { SetOutputArrayCount<InstanceInfo>(instance, kInstanceArrayEnumeratePhysicalDeviceGroupsKHR, *pPhysicalDeviceGroupCount->GetOutputPointer(), &VulkanObjectInfoTable::GetInstanceInfo); }
    AddStructArrayHandles<Decoded_VkPhysicalDeviceGroupProperties>(instance, pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength(), pPhysicalDeviceGroupProperties->GetOutputPointer(), *pPhysicalDeviceGroupCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = pExternalBufferInfo->GetPointer();
    VkExternalBufferProperties* out_pExternalBufferProperties = pExternalBufferProperties->IsNull() ? nullptr : pExternalBufferProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(in_physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkMemoryGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = pGetWin32HandleInfo->GetPointer();
    MapStructHandles(pGetWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetMemoryWin32HandleKHR", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR, "vkGetMemoryWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    handle,
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    HANDLE in_handle = static_cast<HANDLE>(PreProcessExternalObject(handle, format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR, "vkGetMemoryWin32HandlePropertiesKHR"));
    VkMemoryWin32HandlePropertiesKHR* out_pMemoryWin32HandleProperties = pMemoryWin32HandleProperties->IsNull() ? nullptr : pMemoryWin32HandleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandlePropertiesKHR(in_device, handleType, in_handle, out_pMemoryWin32HandleProperties);
    CheckResult("vkGetMemoryWin32HandlePropertiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkMemoryGetFdInfoKHR* in_pGetFdInfo = pGetFdInfo->GetPointer();
    MapStructHandles(pGetFdInfo->GetMetaStructPointer(), GetObjectInfoTable());
    int* out_pFd = pFd->IsNull() ? nullptr : pFd->AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryFdKHR(in_device, in_pGetFdInfo, out_pFd);
    CheckResult("vkGetMemoryFdKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkMemoryFdPropertiesKHR* out_pMemoryFdProperties = pMemoryFdProperties->IsNull() ? nullptr : pMemoryFdProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryFdPropertiesKHR(in_device, handleType, fd, out_pMemoryFdProperties);
    CheckResult("vkGetMemoryFdPropertiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = pExternalSemaphoreInfo->GetPointer();
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = pExternalSemaphoreProperties->IsNull() ? nullptr : pExternalSemaphoreProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(in_physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

void VulkanReplayConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pImportSemaphoreWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideImportSemaphoreWin32HandleKHR(GetDeviceTable(in_device->handle)->ImportSemaphoreWin32HandleKHR, returnValue, in_device, pImportSemaphoreWin32HandleInfo);
    CheckResult("vkImportSemaphoreWin32HandleKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSemaphoreGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = pGetWin32HandleInfo->GetPointer();
    MapStructHandles(pGetWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetSemaphoreWin32HandleKHR", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR, "vkGetSemaphoreWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pImportSemaphoreFdInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideImportSemaphoreFdKHR(GetDeviceTable(in_device->handle)->ImportSemaphoreFdKHR, returnValue, in_device, pImportSemaphoreFdInfo);
    CheckResult("vkImportSemaphoreFdKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pGetFdInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pFd->IsNull() ? nullptr : pFd->AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = OverrideGetSemaphoreFdKHR(GetDeviceTable(in_device->handle)->GetSemaphoreFdKHR, returnValue, in_device, pGetFdInfo, pFd);
    CheckResult("vkGetSemaphoreFdKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkPipelineLayout in_layout = MapHandle<PipelineLayoutInfo>(layout, &VulkanObjectInfoTable::GetPipelineLayoutInfo);
    const VkWriteDescriptorSet* in_pDescriptorWrites = pDescriptorWrites->GetPointer();
    MapStructArrayHandles(pDescriptorWrites->GetMetaStructPointer(), pDescriptorWrites->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSetKHR(in_commandBuffer, pipelineBindPoint, in_layout, set, descriptorWriteCount, in_pDescriptorWrites);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDescriptorUpdateTemplate->IsNull()) { pDescriptorUpdateTemplate->SetHandleLength(1); }
    DescriptorUpdateTemplateInfo handle_info;
    pDescriptorUpdateTemplate->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->CreateDescriptorUpdateTemplateKHR, returnValue, in_device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    CheckResult("vkCreateDescriptorUpdateTemplateKHR", returnValue, replay_result);

    AddHandle<DescriptorUpdateTemplateInfo>(device, pDescriptorUpdateTemplate->GetPointer(), pDescriptorUpdateTemplate->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_descriptorUpdateTemplate = GetObjectInfoTable().GetDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    OverrideDestroyDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->DestroyDescriptorUpdateTemplateKHR, in_device, in_descriptorUpdateTemplate, pAllocator);
    RemoveHandle(descriptorUpdateTemplate, &VulkanObjectInfoTable::RemoveDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    if (!pRenderPass->IsNull()) { pRenderPass->SetHandleLength(1); }
    RenderPassInfo handle_info;
    pRenderPass->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateRenderPass2(GetDeviceTable(in_device->handle)->CreateRenderPass2KHR, returnValue, in_device, pCreateInfo, pAllocator, pRenderPass);
    CheckResult("vkCreateRenderPass2KHR", returnValue, replay_result);

    AddHandle<RenderPassInfo>(device, pRenderPass->GetPointer(), pRenderPass->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkRenderPassBeginInfo* in_pRenderPassBegin = pRenderPassBegin->GetPointer();
    MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());
    const VkSubpassBeginInfo* in_pSubpassBeginInfo = pSubpassBeginInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBeginRenderPass2KHR(in_commandBuffer, in_pRenderPassBegin, in_pSubpassBeginInfo);
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkSubpassBeginInfo* in_pSubpassBeginInfo = pSubpassBeginInfo->GetPointer();
    const VkSubpassEndInfo* in_pSubpassEndInfo = pSubpassEndInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass2KHR(in_commandBuffer, in_pSubpassBeginInfo, in_pSubpassEndInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkSubpassEndInfo* in_pSubpassEndInfo = pSubpassEndInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndRenderPass2KHR(in_commandBuffer, in_pSubpassEndInfo);
}

void VulkanReplayConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainStatusKHR(in_device, in_swapchain);
    CheckResult("vkGetSwapchainStatusKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = pExternalFenceInfo->GetPointer();
    VkExternalFenceProperties* out_pExternalFenceProperties = pExternalFenceProperties->IsNull() ? nullptr : pExternalFenceProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(in_physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

void VulkanReplayConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkImportFenceWin32HandleInfoKHR* in_pImportFenceWin32HandleInfo = pImportFenceWin32HandleInfo->GetPointer();
    MapStructHandles(pImportFenceWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ImportFenceWin32HandleKHR(in_device, in_pImportFenceWin32HandleInfo);
    CheckResult("vkImportFenceWin32HandleKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkFenceGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = pGetWin32HandleInfo->GetPointer();
    MapStructHandles(pGetWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetFenceWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetFenceWin32HandleKHR", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR, "vkGetFenceWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkImportFenceFdInfoKHR* in_pImportFenceFdInfo = pImportFenceFdInfo->GetPointer();
    MapStructHandles(pImportFenceFdInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ImportFenceFdKHR(in_device, in_pImportFenceFdInfo);
    CheckResult("vkImportFenceFdKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkFenceGetFdInfoKHR* in_pGetFdInfo = pGetFdInfo->GetPointer();
    MapStructHandles(pGetFdInfo->GetMetaStructPointer(), GetObjectInfoTable());
    int* out_pFd = pFd->IsNull() ? nullptr : pFd->AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetFenceFdKHR(in_device, in_pGetFdInfo, out_pFd);
    CheckResult("vkGetFenceFdKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    PointerDecoder<uint32_t>*                   pCounterCount,
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters,
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pCounterCount = pCounterCount->IsNull() ? nullptr : pCounterCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", returnValue, physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, pCounterCount, pCounterDescriptions, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkPerformanceCounterKHR* out_pCounters = pCounters->IsNull() ? nullptr : pCounters->AllocateOutputData(*out_pCounterCount, VkPerformanceCounterKHR{ VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR, nullptr });
    VkPerformanceCounterDescriptionKHR* out_pCounterDescriptions = pCounterDescriptions->IsNull() ? nullptr : pCounterDescriptions->AllocateOutputData(*out_pCounterCount, VkPerformanceCounterDescriptionKHR{ VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(in_physicalDevice, queueFamilyIndex, out_pCounterCount, out_pCounters, out_pCounterDescriptions);
    CheckResult("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", returnValue, replay_result);

    if (pCounters->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, *out_pCounterCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    if (pCounterDescriptions->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, *out_pCounterCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkQueryPoolPerformanceCreateInfoKHR* in_pPerformanceQueryCreateInfo = pPerformanceQueryCreateInfo->GetPointer();
    uint32_t* out_pNumPasses = pNumPasses->IsNull() ? nullptr : pNumPasses->AllocateOutputData(1, static_cast<uint32_t>(0));

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(in_physicalDevice, in_pPerformanceQueryCreateInfo, out_pNumPasses);
}

void VulkanReplayConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkAcquireProfilingLockInfoKHR* in_pInfo = pInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->AcquireProfilingLockKHR(in_device, in_pInfo);
    CheckResult("vkAcquireProfilingLockKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);

    GetDeviceTable(in_device)->ReleaseProfilingLockKHR(in_device);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);

    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    pSurfaceCapabilities->IsNull() ? nullptr : pSurfaceCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR, nullptr });

    VkResult replay_result = OverrideGetPhysicalDeviceSurfaceCapabilities2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceCapabilities2KHR, returnValue, in_physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilities2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = pSurfaceInfo->GetPointer();
    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    uint32_t* out_pSurfaceFormatCount = pSurfaceFormatCount->IsNull() ? nullptr : pSurfaceFormatCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSurfaceFormats2KHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR, pSurfaceFormatCount, pSurfaceFormats, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkSurfaceFormat2KHR* out_pSurfaceFormats = pSurfaceFormats->IsNull() ? nullptr : pSurfaceFormats->AllocateOutputData(*out_pSurfaceFormatCount, VkSurfaceFormat2KHR{ VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(in_physicalDevice, in_pSurfaceInfo, out_pSurfaceFormatCount, out_pSurfaceFormats);
    CheckResult("vkGetPhysicalDeviceSurfaceFormats2KHR", returnValue, replay_result);

    if (pSurfaceFormats->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR, *out_pSurfaceFormatCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayProperties2KHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkDisplayProperties2KHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkDisplayProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayProperties2KHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR, *out_pPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayProperties2KHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkDisplayPlaneProperties2KHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkDisplayPlaneProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR, *out_pPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayPlaneProperties2KHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetDisplayModeProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectInfoTable::GetDisplayKHRInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DisplayKHRInfo>("vkGetDisplayModeProperties2KHR", returnValue, display, kDisplayKHRArrayGetDisplayModeProperties2KHR, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetDisplayKHRInfo));
    VkDisplayModeProperties2KHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkDisplayModeProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayModeProperties2KHR(in_physicalDevice, in_display, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetDisplayModeProperties2KHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<DisplayKHRInfo>(display, kDisplayKHRArrayGetDisplayModeProperties2KHR, *out_pPropertyCount, &VulkanObjectInfoTable::GetDisplayKHRInfo); }
    AddStructArrayHandles<Decoded_VkDisplayModeProperties2KHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkDisplayPlaneInfo2KHR* in_pDisplayPlaneInfo = pDisplayPlaneInfo->GetPointer();
    MapStructHandles(pDisplayPlaneInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkDisplayPlaneCapabilities2KHR* out_pCapabilities = pCapabilities->IsNull() ? nullptr : pCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneCapabilities2KHR(in_physicalDevice, in_pDisplayPlaneInfo, out_pCapabilities);
    CheckResult("vkGetDisplayPlaneCapabilities2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkImageMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageMemoryRequirements2KHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkBufferMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetBufferMemoryRequirements2KHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkImageSparseMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetImageSparseMemoryRequirements2KHR", VK_SUCCESS, device, kDeviceArrayGetImageSparseMemoryRequirements2KHR, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &VulkanObjectInfoTable::GetDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements2KHR(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetImageSparseMemoryRequirements2KHR, *out_pSparseMemoryRequirementCount, &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSamplerYcbcrConversionCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pYcbcrConversion->IsNull()) { pYcbcrConversion->SetHandleLength(1); }
    VkSamplerYcbcrConversion* out_pYcbcrConversion = pYcbcrConversion->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSamplerYcbcrConversionKHR(in_device, in_pCreateInfo, in_pAllocator, out_pYcbcrConversion);
    CheckResult("vkCreateSamplerYcbcrConversionKHR", returnValue, replay_result);

    AddHandle<SamplerYcbcrConversionInfo>(device, pYcbcrConversion->GetPointer(), out_pYcbcrConversion, &VulkanObjectInfoTable::AddSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSamplerYcbcrConversion in_ycbcrConversion = MapHandle<SamplerYcbcrConversionInfo>(ycbcrConversion, &VulkanObjectInfoTable::GetSamplerYcbcrConversionInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySamplerYcbcrConversionKHR(in_device, in_ycbcrConversion, in_pAllocator);
    RemoveHandle(ycbcrConversion, &VulkanObjectInfoTable::RemoveSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindBufferMemory2(GetDeviceTable(in_device->handle)->BindBufferMemory2KHR, returnValue, in_device, bindInfoCount, pBindInfos);
    CheckResult("vkBindBufferMemory2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindImageMemory2(GetDeviceTable(in_device->handle)->BindImageMemory2KHR, returnValue, in_device, bindInfoCount, pBindInfos);
    CheckResult("vkBindImageMemory2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkDescriptorSetLayoutSupport* out_pSupport = pSupport->IsNull() ? nullptr : pSupport->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, nullptr });

    GetDeviceTable(in_device)->GetDescriptorSetLayoutSupportKHR(in_device, in_pCreateInfo, out_pSupport);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCountKHR(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCountKHR(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreCounterValueKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSemaphore in_semaphore = MapHandle<SemaphoreInfo>(semaphore, &VulkanObjectInfoTable::GetSemaphoreInfo);
    uint64_t* out_pValue = pValue->IsNull() ? nullptr : pValue->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreCounterValueKHR(in_device, in_semaphore, out_pValue);
    CheckResult("vkGetSemaphoreCounterValueKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSemaphoreWaitInfo* in_pWaitInfo = pWaitInfo->GetPointer();
    MapStructHandles(pWaitInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->WaitSemaphoresKHR(in_device, in_pWaitInfo, timeout);
    CheckResult("vkWaitSemaphoresKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSemaphoreSignalInfo* in_pSignalInfo = pSignalInfo->GetPointer();
    MapStructHandles(pSignalInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->SignalSemaphoreKHR(in_device, in_pSignalInfo);
    CheckResult("vkSignalSemaphoreKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pFragmentShadingRateCount = pFragmentShadingRateCount->IsNull() ? nullptr : pFragmentShadingRateCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceFragmentShadingRatesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR, pFragmentShadingRateCount, pFragmentShadingRates, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkPhysicalDeviceFragmentShadingRateKHR* out_pFragmentShadingRates = pFragmentShadingRates->IsNull() ? nullptr : pFragmentShadingRates->AllocateOutputData(*out_pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFragmentShadingRatesKHR(in_physicalDevice, out_pFragmentShadingRateCount, out_pFragmentShadingRates);
    CheckResult("vkGetPhysicalDeviceFragmentShadingRatesKHR", returnValue, replay_result);

    if (pFragmentShadingRates->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR, *out_pFragmentShadingRateCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkExtent2D* in_pFragmentSize = pFragmentSize->GetPointer();
    const VkFragmentShadingRateCombinerOpKHR* in_combinerOps = combinerOps->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetFragmentShadingRateKHR(in_commandBuffer, in_pFragmentSize, in_combinerOps);
}

void VulkanReplayConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->WaitForPresentKHR(in_device, in_swapchain, presentId, timeout);
    CheckResult("vkWaitForPresentKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetBufferDeviceAddress(GetDeviceTable(in_device->handle)->GetBufferDeviceAddressKHR, in_device, pInfo);
}

void VulkanReplayConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkBufferDeviceAddressInfo* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetBufferOpaqueCaptureAddressKHR(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDeviceMemoryOpaqueCaptureAddressInfo* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetDeviceMemoryOpaqueCaptureAddressKHR(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pDeferredOperation->IsNull()) { pDeferredOperation->SetHandleLength(1); }
    VkDeferredOperationKHR* out_pDeferredOperation = pDeferredOperation->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateDeferredOperationKHR(in_device, in_pAllocator, out_pDeferredOperation);
    CheckResult("vkCreateDeferredOperationKHR", returnValue, replay_result);

    AddHandle<DeferredOperationKHRInfo>(device, pDeferredOperation->GetPointer(), out_pDeferredOperation, &VulkanObjectInfoTable::AddDeferredOperationKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeferredOperationKHR in_operation = MapHandle<DeferredOperationKHRInfo>(operation, &VulkanObjectInfoTable::GetDeferredOperationKHRInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyDeferredOperationKHR(in_device, in_operation, in_pAllocator);
    RemoveHandle(operation, &VulkanObjectInfoTable::RemoveDeferredOperationKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeferredOperationKHR in_operation = MapHandle<DeferredOperationKHRInfo>(operation, &VulkanObjectInfoTable::GetDeferredOperationKHRInfo);

    GetDeviceTable(in_device)->GetDeferredOperationMaxConcurrencyKHR(in_device, in_operation);
}

void VulkanReplayConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeferredOperationKHR in_operation = MapHandle<DeferredOperationKHRInfo>(operation, &VulkanObjectInfoTable::GetDeferredOperationKHRInfo);

    VkResult replay_result = GetDeviceTable(in_device)->GetDeferredOperationResultKHR(in_device, in_operation);
    CheckResult("vkGetDeferredOperationResultKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_operation = GetObjectInfoTable().GetDeferredOperationKHRInfo(operation);

    VkResult replay_result = OverrideDeferredOperationJoinKHR(GetDeviceTable(in_device->handle)->DeferredOperationJoinKHR, returnValue, in_device, in_operation);
    CheckResult("vkDeferredOperationJoinKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkPipelineInfoKHR* in_pPipelineInfo = pPipelineInfo->GetPointer();
    MapStructHandles(pPipelineInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pExecutableCount = pExecutableCount->IsNull() ? nullptr : pExecutableCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetPipelineExecutablePropertiesKHR", returnValue, device, kDeviceArrayGetPipelineExecutablePropertiesKHR, pExecutableCount, pProperties, &VulkanObjectInfoTable::GetDeviceInfo));
    VkPipelineExecutablePropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pExecutableCount, VkPipelineExecutablePropertiesKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutablePropertiesKHR(in_device, in_pPipelineInfo, out_pExecutableCount, out_pProperties);
    CheckResult("vkGetPipelineExecutablePropertiesKHR", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetPipelineExecutablePropertiesKHR, *out_pExecutableCount, &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkPipelineExecutableInfoKHR* in_pExecutableInfo = pExecutableInfo->GetPointer();
    MapStructHandles(pExecutableInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pStatisticCount = pStatisticCount->IsNull() ? nullptr : pStatisticCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetPipelineExecutableStatisticsKHR", returnValue, device, kDeviceArrayGetPipelineExecutableStatisticsKHR, pStatisticCount, pStatistics, &VulkanObjectInfoTable::GetDeviceInfo));
    VkPipelineExecutableStatisticKHR* out_pStatistics = pStatistics->IsNull() ? nullptr : pStatistics->AllocateOutputData(*out_pStatisticCount, VkPipelineExecutableStatisticKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutableStatisticsKHR(in_device, in_pExecutableInfo, out_pStatisticCount, out_pStatistics);
    CheckResult("vkGetPipelineExecutableStatisticsKHR", returnValue, replay_result);

    if (pStatistics->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetPipelineExecutableStatisticsKHR, *out_pStatisticCount, &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkPipelineExecutableInfoKHR* in_pExecutableInfo = pExecutableInfo->GetPointer();
    MapStructHandles(pExecutableInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pInternalRepresentationCount = pInternalRepresentationCount->IsNull() ? nullptr : pInternalRepresentationCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetPipelineExecutableInternalRepresentationsKHR", returnValue, device, kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR, pInternalRepresentationCount, pInternalRepresentations, &VulkanObjectInfoTable::GetDeviceInfo));
    VkPipelineExecutableInternalRepresentationKHR* out_pInternalRepresentations = pInternalRepresentations->IsNull() ? nullptr : pInternalRepresentations->AllocateOutputData(*out_pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutableInternalRepresentationsKHR(in_device, in_pExecutableInfo, out_pInternalRepresentationCount, out_pInternalRepresentations);
    CheckResult("vkGetPipelineExecutableInternalRepresentationsKHR", returnValue, replay_result);

    if (pInternalRepresentations->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR, *out_pInternalRepresentationCount, &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkVideoEncodeInfoKHR* in_pEncodeInfo = pEncodeInfo->GetPointer();
    MapStructHandles(pEncodeInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdEncodeVideoKHR(in_commandBuffer, in_pEncodeInfo);
}

void VulkanReplayConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectInfoTable::GetEventInfo);
    const VkDependencyInfo* in_pDependencyInfo = pDependencyInfo->GetPointer();
    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetEvent2KHR(in_commandBuffer, in_event, in_pDependencyInfo);
}

void VulkanReplayConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkEvent in_event = MapHandle<EventInfo>(event, &VulkanObjectInfoTable::GetEventInfo);

    GetDeviceTable(in_commandBuffer)->CmdResetEvent2KHR(in_commandBuffer, in_event, stageMask);
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkEvent* in_pEvents = MapHandles<EventInfo>(pEvents, eventCount, &VulkanObjectInfoTable::GetEventInfo);
    const VkDependencyInfo* in_pDependencyInfos = pDependencyInfos->GetPointer();
    MapStructArrayHandles(pDependencyInfos->GetMetaStructPointer(), pDependencyInfos->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdWaitEvents2KHR(in_commandBuffer, eventCount, in_pEvents, in_pDependencyInfos);
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkDependencyInfo* in_pDependencyInfo = pDependencyInfo->GetPointer();
    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPipelineBarrier2KHR(in_commandBuffer, in_pDependencyInfo);
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteTimestamp2KHR(in_commandBuffer, stage, in_queryPool, query);
}

void VulkanReplayConsumer::Process_vkQueueSubmit2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetQueueInfo(queue);

    MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetFenceInfo(fence);

    VkResult replay_result = OverrideQueueSubmit2(GetDeviceTable(in_queue->handle)->QueueSubmit2KHR, returnValue, in_queue, submitCount, pSubmits, in_fence);
    CheckResult("vkQueueSubmit2KHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteBufferMarker2AMD(in_commandBuffer, stage, in_dstBuffer, dstOffset, marker);
}

void VulkanReplayConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectInfoTable::GetQueueInfo);
    uint32_t* out_pCheckpointDataCount = pCheckpointDataCount->IsNull() ? nullptr : pCheckpointDataCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, QueueInfo>("vkGetQueueCheckpointData2NV", VK_SUCCESS, queue, kQueueArrayGetQueueCheckpointData2NV, pCheckpointDataCount, pCheckpointData, &VulkanObjectInfoTable::GetQueueInfo));
    VkCheckpointData2NV* out_pCheckpointData = pCheckpointData->IsNull() ? nullptr : pCheckpointData->AllocateOutputData(*out_pCheckpointDataCount, VkCheckpointData2NV{ VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV, nullptr });

    GetDeviceTable(in_queue)->GetQueueCheckpointData2NV(in_queue, out_pCheckpointDataCount, out_pCheckpointData);

    if (pCheckpointData->IsNull()) { SetOutputArrayCount<QueueInfo>(queue, kQueueArrayGetQueueCheckpointData2NV, *out_pCheckpointDataCount, &VulkanObjectInfoTable::GetQueueInfo); }
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyBufferInfo2* in_pCopyBufferInfo = pCopyBufferInfo->GetPointer();
    MapStructHandles(pCopyBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyBuffer2KHR(in_commandBuffer, in_pCopyBufferInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyImageInfo2* in_pCopyImageInfo = pCopyImageInfo->GetPointer();
    MapStructHandles(pCopyImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyImage2KHR(in_commandBuffer, in_pCopyImageInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyBufferToImageInfo2* in_pCopyBufferToImageInfo = pCopyBufferToImageInfo->GetPointer();
    MapStructHandles(pCopyBufferToImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage2KHR(in_commandBuffer, in_pCopyBufferToImageInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyImageToBufferInfo2* in_pCopyImageToBufferInfo = pCopyImageToBufferInfo->GetPointer();
    MapStructHandles(pCopyImageToBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer2KHR(in_commandBuffer, in_pCopyImageToBufferInfo);
}

void VulkanReplayConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkBlitImageInfo2* in_pBlitImageInfo = pBlitImageInfo->GetPointer();
    MapStructHandles(pBlitImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBlitImage2KHR(in_commandBuffer, in_pBlitImageInfo);
}

void VulkanReplayConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkResolveImageInfo2* in_pResolveImageInfo = pResolveImageInfo->GetPointer();
    MapStructHandles(pResolveImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdResolveImage2KHR(in_commandBuffer, in_pResolveImageInfo);
}

void VulkanReplayConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdTraceRaysIndirect2KHR(in_commandBuffer, indirectDeviceAddress);
}

void VulkanReplayConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDeviceBufferMemoryRequirements* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetDeviceBufferMemoryRequirementsKHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetDeviceImageMemoryRequirementsKHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, DeviceInfo>("vkGetDeviceImageSparseMemoryRequirementsKHR", VK_SUCCESS, device, kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &VulkanObjectInfoTable::GetDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetDeviceImageSparseMemoryRequirementsKHR(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<DeviceInfo>(device, kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR, *out_pSparseMemoryRequirementCount, &VulkanObjectInfoTable::GetDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pCallback->IsNull()) { pCallback->SetHandleLength(1); }
    DebugReportCallbackEXTInfo handle_info;
    pCallback->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDebugReportCallbackEXT(GetInstanceTable(in_instance->handle)->CreateDebugReportCallbackEXT, returnValue, in_instance, pCreateInfo, pAllocator, pCallback);
    CheckResult("vkCreateDebugReportCallbackEXT", returnValue, replay_result);

    AddHandle<DebugReportCallbackEXTInfo>(instance, pCallback->GetPointer(), pCallback->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDebugReportCallbackEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    VkDebugReportCallbackEXT in_callback = MapHandle<DebugReportCallbackEXTInfo>(callback, &VulkanObjectInfoTable::GetDebugReportCallbackEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetInstanceTable(in_instance)->DestroyDebugReportCallbackEXT(in_instance, in_callback, in_pAllocator);
    RemoveHandle(callback, &VulkanObjectInfoTable::RemoveDebugReportCallbackEXTInfo);
}

void VulkanReplayConsumer::Process_vkDebugReportMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    StringDecoder*                              pLayerPrefix,
    StringDecoder*                              pMessage)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    uint64_t in_object = MapHandle(object, objectType);
    const char* in_pLayerPrefix = pLayerPrefix->GetPointer();
    const char* in_pMessage = pMessage->GetPointer();

    GetInstanceTable(in_instance)->DebugReportMessageEXT(in_instance, flags, objectType, in_object, location, messageCode, in_pLayerPrefix, in_pMessage);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDebugMarkerObjectTagInfoEXT* in_pTagInfo = pTagInfo->GetPointer();
    MapStructHandles(pTagInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->DebugMarkerSetObjectTagEXT(in_device, in_pTagInfo);
    CheckResult("vkDebugMarkerSetObjectTagEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDebugMarkerObjectNameInfoEXT* in_pNameInfo = pNameInfo->GetPointer();
    MapStructHandles(pNameInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->DebugMarkerSetObjectNameEXT(in_device, in_pNameInfo);
    CheckResult("vkDebugMarkerSetObjectNameEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkDebugMarkerMarkerInfoEXT* in_pMarkerInfo = pMarkerInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDebugMarkerBeginEXT(in_commandBuffer, in_pMarkerInfo);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDebugMarkerEndEXT(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkDebugMarkerMarkerInfoEXT* in_pMarkerInfo = pMarkerInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDebugMarkerInsertEXT(in_commandBuffer, in_pMarkerInfo);
}

void VulkanReplayConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<BufferInfo>(pBuffers, bindingCount, &VulkanObjectInfoTable::GetBufferInfo);
    const VkDeviceSize* in_pOffsets = pOffsets->GetPointer();
    const VkDeviceSize* in_pSizes = pSizes->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindTransformFeedbackBuffersEXT(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets, in_pSizes);
}

void VulkanReplayConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkBuffer* in_pCounterBuffers = MapHandles<BufferInfo>(pCounterBuffers, counterBufferCount, &VulkanObjectInfoTable::GetBufferInfo);
    const VkDeviceSize* in_pCounterBufferOffsets = pCounterBufferOffsets->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBeginTransformFeedbackEXT(in_commandBuffer, firstCounterBuffer, counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);
}

void VulkanReplayConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkBuffer* in_pCounterBuffers = MapHandles<BufferInfo>(pCounterBuffers, counterBufferCount, &VulkanObjectInfoTable::GetBufferInfo);
    const VkDeviceSize* in_pCounterBufferOffsets = pCounterBufferOffsets->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndTransformFeedbackEXT(in_commandBuffer, firstCounterBuffer, counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);
}

void VulkanReplayConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdBeginQueryIndexedEXT(in_commandBuffer, in_queryPool, query, flags, index);
}

void VulkanReplayConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndQueryIndexedEXT(in_commandBuffer, in_queryPool, query, index);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_counterBuffer = MapHandle<BufferInfo>(counterBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectByteCountEXT(in_commandBuffer, instanceCount, firstInstance, in_counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

void VulkanReplayConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkImageViewHandleInfoNVX* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetImageViewHandleNVX(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkImageView in_imageView = MapHandle<ImageViewInfo>(imageView, &VulkanObjectInfoTable::GetImageViewInfo);
    VkImageViewAddressPropertiesNVX* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetImageViewAddressNVX(in_device, in_imageView, out_pProperties);
    CheckResult("vkGetImageViewAddressNVX", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCountAMD(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCountAMD(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkGetShaderInfoAMD(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    PointerDecoder<size_t>*                     pInfoSize,
    PointerDecoder<uint8_t>*                    pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectInfoTable::GetPipelineInfo);
    size_t* out_pInfoSize = pInfoSize->IsNull() ? nullptr : pInfoSize->AllocateOutputData(1, GetOutputArrayCount<size_t, PipelineInfo>("vkGetShaderInfoAMD", returnValue, pipeline, kPipelineArrayGetShaderInfoAMD, pInfoSize, pInfo, &VulkanObjectInfoTable::GetPipelineInfo));
    void* out_pInfo = pInfo->IsNull() ? nullptr : pInfo->AllocateOutputData(*out_pInfoSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetShaderInfoAMD(in_device, in_pipeline, shaderStage, infoType, out_pInfoSize, out_pInfo);
    CheckResult("vkGetShaderInfoAMD", returnValue, replay_result);

    if (pInfo->IsNull()) { SetOutputArrayCount<PipelineInfo>(pipeline, kPipelineArrayGetShaderInfoAMD, *out_pInfoSize, &VulkanObjectInfoTable::GetPipelineInfo); }
}

void VulkanReplayConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkStreamDescriptorSurfaceCreateInfoGGP* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateStreamDescriptorSurfaceGGP(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateStreamDescriptorSurfaceGGP", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    const ApiCallInfo&                          call_info,
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
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkExternalImageFormatPropertiesNV* out_pExternalImageFormatProperties = pExternalImageFormatProperties->IsNull() ? nullptr : pExternalImageFormatProperties->AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(in_physicalDevice, format, type, tiling, usage, flags, externalHandleType, out_pExternalImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceExternalImageFormatPropertiesNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeviceMemory in_memory = MapHandle<DeviceMemoryInfo>(memory, &VulkanObjectInfoTable::GetDeviceMemoryInfo);
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandleNV(in_device, in_memory, handleType, out_pHandle);
    CheckResult("vkGetMemoryWin32HandleNV", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV, "vkGetMemoryWin32HandleNV");
}

void VulkanReplayConsumer::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkViSurfaceCreateInfoNN* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateViSurfaceNN(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateViSurfaceNN", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkConditionalRenderingBeginInfoEXT* in_pConditionalRenderingBegin = pConditionalRenderingBegin->GetPointer();
    MapStructHandles(pConditionalRenderingBegin->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginConditionalRenderingEXT(in_commandBuffer, in_pConditionalRenderingBegin);
}

void VulkanReplayConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndConditionalRenderingEXT(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkViewportWScalingNV* in_pViewportWScalings = pViewportWScalings->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWScalingNV(in_commandBuffer, firstViewport, viewportCount, in_pViewportWScalings);
}

void VulkanReplayConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectInfoTable::GetDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->ReleaseDisplayEXT(in_physicalDevice, in_display);
    CheckResult("vkReleaseDisplayEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT, "vkAcquireXlibDisplayEXT"));
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectInfoTable::GetDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->AcquireXlibDisplayEXT(in_physicalDevice, in_dpy, in_display);
    CheckResult("vkAcquireXlibDisplayEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    auto in_physicalDevice = GetObjectInfoTable().GetPhysicalDeviceInfo(physicalDevice);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT, "vkGetRandROutputDisplayEXT"));
    if (!pDisplay->IsNull()) { pDisplay->SetHandleLength(1); }
    DisplayKHRInfo handle_info;
    pDisplay->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideGetRandROutputDisplayEXT(GetInstanceTable(in_physicalDevice->handle)->GetRandROutputDisplayEXT, returnValue, in_physicalDevice, in_dpy, rrOutput, pDisplay);
    CheckResult("vkGetRandROutputDisplayEXT", returnValue, replay_result);

    AddHandle<DisplayKHRInfo>(physicalDevice, pDisplay->GetPointer(), pDisplay->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<SurfaceKHRInfo>(surface, &VulkanObjectInfoTable::GetSurfaceKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    VkSurfaceCapabilities2EXT* out_pSurfaceCapabilities = pSurfaceCapabilities->IsNull() ? nullptr : pSurfaceCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(in_physicalDevice, in_surface, out_pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilities2EXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectInfoTable::GetDisplayKHRInfo);
    const VkDisplayPowerInfoEXT* in_pDisplayPowerInfo = pDisplayPowerInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->DisplayPowerControlEXT(in_device, in_display, in_pDisplayPowerInfo);
    CheckResult("vkDisplayPowerControlEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDeviceEventInfoEXT* in_pDeviceEventInfo = pDeviceEventInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pFence->IsNull()) { pFence->SetHandleLength(1); }
    VkFence* out_pFence = pFence->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->RegisterDeviceEventEXT(in_device, in_pDeviceEventInfo, in_pAllocator, out_pFence);
    CheckResult("vkRegisterDeviceEventEXT", returnValue, replay_result);

    AddHandle<FenceInfo>(device, pFence->GetPointer(), out_pFence, &VulkanObjectInfoTable::AddFenceInfo);
}

void VulkanReplayConsumer::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectInfoTable::GetDisplayKHRInfo);
    const VkDisplayEventInfoEXT* in_pDisplayEventInfo = pDisplayEventInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pFence->IsNull()) { pFence->SetHandleLength(1); }
    VkFence* out_pFence = pFence->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->RegisterDisplayEventEXT(in_device, in_display, in_pDisplayEventInfo, in_pAllocator, out_pFence);
    CheckResult("vkRegisterDisplayEventEXT", returnValue, replay_result);

    AddHandle<FenceInfo>(device, pFence->GetPointer(), out_pFence, &VulkanObjectInfoTable::AddFenceInfo);
}

void VulkanReplayConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }
    uint64_t* out_pCounterValue = pCounterValue->IsNull() ? nullptr : pCounterValue->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainCounterEXT(in_device, in_swapchain, counter, out_pCounterValue);
    CheckResult("vkGetSwapchainCounterEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }
    VkRefreshCycleDurationGOOGLE* out_pDisplayTimingProperties = pDisplayTimingProperties->IsNull() ? nullptr : pDisplayTimingProperties->AllocateOutputData(1);

    VkResult replay_result = GetDeviceTable(in_device)->GetRefreshCycleDurationGOOGLE(in_device, in_swapchain, out_pDisplayTimingProperties);
    CheckResult("vkGetRefreshCycleDurationGOOGLE", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }
    uint32_t* out_pPresentationTimingCount = pPresentationTimingCount->IsNull() ? nullptr : pPresentationTimingCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, SwapchainKHRInfo>("vkGetPastPresentationTimingGOOGLE", returnValue, swapchain, kSwapchainKHRArrayGetPastPresentationTimingGOOGLE, pPresentationTimingCount, pPresentationTimings, &VulkanObjectInfoTable::GetSwapchainKHRInfo));
    VkPastPresentationTimingGOOGLE* out_pPresentationTimings = pPresentationTimings->IsNull() ? nullptr : pPresentationTimings->AllocateOutputData(*out_pPresentationTimingCount);

    VkResult replay_result = GetDeviceTable(in_device)->GetPastPresentationTimingGOOGLE(in_device, in_swapchain, out_pPresentationTimingCount, out_pPresentationTimings);
    CheckResult("vkGetPastPresentationTimingGOOGLE", returnValue, replay_result);

    if (pPresentationTimings->IsNull()) { SetOutputArrayCount<SwapchainKHRInfo>(swapchain, kSwapchainKHRArrayGetPastPresentationTimingGOOGLE, *out_pPresentationTimingCount, &VulkanObjectInfoTable::GetSwapchainKHRInfo); }
}

void VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkRect2D* in_pDiscardRectangles = pDiscardRectangles->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleEXT(in_commandBuffer, firstDiscardRectangle, discardRectangleCount, in_pDiscardRectangles);
}

void VulkanReplayConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSwapchainKHR* in_pSwapchains = MapHandles<SwapchainKHRInfo>(pSwapchains, swapchainCount, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    const VkHdrMetadataEXT* in_pMetadata = pMetadata->GetPointer();

    GetDeviceTable(in_device)->SetHdrMetadataEXT(in_device, swapchainCount, in_pSwapchains, in_pMetadata);
}

void VulkanReplayConsumer::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkIOSSurfaceCreateInfoMVK* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateIOSSurfaceMVK(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateIOSSurfaceMVK", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkMacOSSurfaceCreateInfoMVK* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateMacOSSurfaceMVK(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateMacOSSurfaceMVK", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDebugUtilsObjectNameInfoEXT* in_pNameInfo = pNameInfo->GetPointer();
    MapStructHandles(pNameInfo->GetMetaStructPointer(), GetObjectInfoTable());
    DeviceInfo* device_info = GetObjectInfoTable().GetDeviceInfo(device);
    VkPhysicalDevice             physical_device = device_info->parent;

    VkResult replay_result = GetInstanceTable(physical_device)->SetDebugUtilsObjectNameEXT(in_device, in_pNameInfo);
    CheckResult("vkSetDebugUtilsObjectNameEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDebugUtilsObjectTagInfoEXT* in_pTagInfo = pTagInfo->GetPointer();
    MapStructHandles(pTagInfo->GetMetaStructPointer(), GetObjectInfoTable());
    DeviceInfo* device_info = GetObjectInfoTable().GetDeviceInfo(device);
    VkPhysicalDevice             physical_device = device_info->parent;

    VkResult replay_result = GetInstanceTable(physical_device)->SetDebugUtilsObjectTagEXT(in_device, in_pTagInfo);
    CheckResult("vkSetDebugUtilsObjectTagEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectInfoTable::GetQueueInfo);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo->GetPointer();

    GetDeviceTable(in_queue)->QueueBeginDebugUtilsLabelEXT(in_queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectInfoTable::GetQueueInfo);

    GetDeviceTable(in_queue)->QueueEndDebugUtilsLabelEXT(in_queue);
}

void VulkanReplayConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectInfoTable::GetQueueInfo);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo->GetPointer();

    GetDeviceTable(in_queue)->QueueInsertDebugUtilsLabelEXT(in_queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBeginDebugUtilsLabelEXT(in_commandBuffer, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndDebugUtilsLabelEXT(in_commandBuffer);
}

void VulkanReplayConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdInsertDebugUtilsLabelEXT(in_commandBuffer, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    auto in_instance = GetObjectInfoTable().GetInstanceInfo(instance);
    if (!pMessenger->IsNull()) { pMessenger->SetHandleLength(1); }
    DebugUtilsMessengerEXTInfo handle_info;
    pMessenger->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDebugUtilsMessengerEXT(GetInstanceTable(in_instance->handle)->CreateDebugUtilsMessengerEXT, returnValue, in_instance, pCreateInfo, pAllocator, pMessenger);
    CheckResult("vkCreateDebugUtilsMessengerEXT", returnValue, replay_result);

    AddHandle<DebugUtilsMessengerEXTInfo>(instance, pMessenger->GetPointer(), pMessenger->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddDebugUtilsMessengerEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    VkDebugUtilsMessengerEXT in_messenger = MapHandle<DebugUtilsMessengerEXTInfo>(messenger, &VulkanObjectInfoTable::GetDebugUtilsMessengerEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetInstanceTable(in_instance)->DestroyDebugUtilsMessengerEXT(in_instance, in_messenger, in_pAllocator);
    RemoveHandle(messenger, &VulkanObjectInfoTable::RemoveDebugUtilsMessengerEXTInfo);
}

void VulkanReplayConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkDebugUtilsMessengerCallbackDataEXT* in_pCallbackData = pCallbackData->GetPointer();

    GetInstanceTable(in_instance)->SubmitDebugUtilsMessageEXT(in_instance, messageSeverity, messageTypes, in_pCallbackData);
}

void VulkanReplayConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    const struct AHardwareBuffer* in_buffer = static_cast<const struct AHardwareBuffer*>(PreProcessExternalObject(buffer, format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID, "vkGetAndroidHardwareBufferPropertiesANDROID"));
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID, nullptr });

    VkResult replay_result = OverrideGetAndroidHardwareBufferPropertiesANDROID(GetDeviceTable(in_device->handle)->GetAndroidHardwareBufferPropertiesANDROID, returnValue, in_device, in_buffer, pProperties);
    CheckResult("vkGetAndroidHardwareBufferPropertiesANDROID", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    struct AHardwareBuffer** out_pBuffer = pBuffer->IsNull() ? nullptr : reinterpret_cast<struct AHardwareBuffer**>(pBuffer->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryAndroidHardwareBufferANDROID(in_device, in_pInfo, out_pBuffer);
    CheckResult("vkGetMemoryAndroidHardwareBufferANDROID", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pBuffer->GetPointer()), static_cast<void*>(*out_pBuffer), format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID, "vkGetMemoryAndroidHardwareBufferANDROID");
}

void VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkSampleLocationsInfoEXT* in_pSampleLocationsInfo = pSampleLocationsInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetSampleLocationsEXT(in_commandBuffer, in_pSampleLocationsInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkMultisamplePropertiesEXT* out_pMultisampleProperties = pMultisampleProperties->IsNull() ? nullptr : pMultisampleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(in_physicalDevice, samples, out_pMultisampleProperties);
}

void VulkanReplayConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectInfoTable::GetImageInfo);
    VkImageDrmFormatModifierPropertiesEXT* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetImageDrmFormatModifierPropertiesEXT(in_device, in_image, out_pProperties);
    CheckResult("vkGetImageDrmFormatModifierPropertiesEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkValidationCacheCreateInfoEXT* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pValidationCache->IsNull()) { pValidationCache->SetHandleLength(1); }
    VkValidationCacheEXT* out_pValidationCache = pValidationCache->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateValidationCacheEXT(in_device, in_pCreateInfo, in_pAllocator, out_pValidationCache);
    CheckResult("vkCreateValidationCacheEXT", returnValue, replay_result);

    AddHandle<ValidationCacheEXTInfo>(device, pValidationCache->GetPointer(), out_pValidationCache, &VulkanObjectInfoTable::AddValidationCacheEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkValidationCacheEXT in_validationCache = MapHandle<ValidationCacheEXTInfo>(validationCache, &VulkanObjectInfoTable::GetValidationCacheEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyValidationCacheEXT(in_device, in_validationCache, in_pAllocator);
    RemoveHandle(validationCache, &VulkanObjectInfoTable::RemoveValidationCacheEXTInfo);
}

void VulkanReplayConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkValidationCacheEXT in_dstCache = MapHandle<ValidationCacheEXTInfo>(dstCache, &VulkanObjectInfoTable::GetValidationCacheEXTInfo);
    const VkValidationCacheEXT* in_pSrcCaches = MapHandles<ValidationCacheEXTInfo>(pSrcCaches, srcCacheCount, &VulkanObjectInfoTable::GetValidationCacheEXTInfo);

    VkResult replay_result = GetDeviceTable(in_device)->MergeValidationCachesEXT(in_device, in_dstCache, srcCacheCount, in_pSrcCaches);
    CheckResult("vkMergeValidationCachesEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkValidationCacheEXT in_validationCache = MapHandle<ValidationCacheEXTInfo>(validationCache, &VulkanObjectInfoTable::GetValidationCacheEXTInfo);
    size_t* out_pDataSize = pDataSize->IsNull() ? nullptr : pDataSize->AllocateOutputData(1, GetOutputArrayCount<size_t, ValidationCacheEXTInfo>("vkGetValidationCacheDataEXT", returnValue, validationCache, kValidationCacheEXTArrayGetValidationCacheDataEXT, pDataSize, pData, &VulkanObjectInfoTable::GetValidationCacheEXTInfo));
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(*out_pDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetValidationCacheDataEXT(in_device, in_validationCache, out_pDataSize, out_pData);
    CheckResult("vkGetValidationCacheDataEXT", returnValue, replay_result);

    if (pData->IsNull()) { SetOutputArrayCount<ValidationCacheEXTInfo>(validationCache, kValidationCacheEXTArrayGetValidationCacheDataEXT, *out_pDataSize, &VulkanObjectInfoTable::GetValidationCacheEXTInfo); }
}

void VulkanReplayConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkImageView in_imageView = MapHandle<ImageViewInfo>(imageView, &VulkanObjectInfoTable::GetImageViewInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindShadingRateImageNV(in_commandBuffer, in_imageView, imageLayout);
}

void VulkanReplayConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkShadingRatePaletteNV* in_pShadingRatePalettes = pShadingRatePalettes->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportShadingRatePaletteNV(in_commandBuffer, firstViewport, viewportCount, in_pShadingRatePalettes);
}

void VulkanReplayConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCoarseSampleOrderCustomNV* in_pCustomSampleOrders = pCustomSampleOrders->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetCoarseSampleOrderNV(in_commandBuffer, sampleOrderType, customSampleOrderCount, in_pCustomSampleOrders);
}

void VulkanReplayConsumer::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkAccelerationStructureCreateInfoNV* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pAccelerationStructure->IsNull()) { pAccelerationStructure->SetHandleLength(1); }
    VkAccelerationStructureNV* out_pAccelerationStructure = pAccelerationStructure->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateAccelerationStructureNV(in_device, in_pCreateInfo, in_pAllocator, out_pAccelerationStructure);
    CheckResult("vkCreateAccelerationStructureNV", returnValue, replay_result);

    AddHandle<AccelerationStructureNVInfo>(device, pAccelerationStructure->GetPointer(), out_pAccelerationStructure, &VulkanObjectInfoTable::AddAccelerationStructureNVInfo);
}

void VulkanReplayConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkAccelerationStructureNV in_accelerationStructure = MapHandle<AccelerationStructureNVInfo>(accelerationStructure, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyAccelerationStructureNV(in_device, in_accelerationStructure, in_pAllocator);
    RemoveHandle(accelerationStructure, &VulkanObjectInfoTable::RemoveAccelerationStructureNVInfo);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkAccelerationStructureMemoryRequirementsInfoNV* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2KHR* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetAccelerationStructureMemoryRequirementsNV(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkBindAccelerationStructureMemoryInfoNV* in_pBindInfos = pBindInfos->GetPointer();
    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->BindAccelerationStructureMemoryNV(in_device, bindInfoCount, in_pBindInfos);
    CheckResult("vkBindAccelerationStructureMemoryNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
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
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkAccelerationStructureInfoNV* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkBuffer in_instanceData = MapHandle<BufferInfo>(instanceData, &VulkanObjectInfoTable::GetBufferInfo);
    VkAccelerationStructureNV in_dst = MapHandle<AccelerationStructureNVInfo>(dst, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);
    VkAccelerationStructureNV in_src = MapHandle<AccelerationStructureNVInfo>(src, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);
    VkBuffer in_scratch = MapHandle<BufferInfo>(scratch, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdBuildAccelerationStructureNV(in_commandBuffer, in_pInfo, in_instanceData, instanceOffset, update, in_dst, in_src, in_scratch, scratchOffset);
}

void VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkAccelerationStructureNV in_dst = MapHandle<AccelerationStructureNVInfo>(dst, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);
    VkAccelerationStructureNV in_src = MapHandle<AccelerationStructureNVInfo>(src, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);

    GetDeviceTable(in_commandBuffer)->CmdCopyAccelerationStructureNV(in_commandBuffer, in_dst, in_src, mode);
}

void VulkanReplayConsumer::Process_vkCmdTraceRaysNV(
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
    uint32_t                                    depth)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_raygenShaderBindingTableBuffer = MapHandle<BufferInfo>(raygenShaderBindingTableBuffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_missShaderBindingTableBuffer = MapHandle<BufferInfo>(missShaderBindingTableBuffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_hitShaderBindingTableBuffer = MapHandle<BufferInfo>(hitShaderBindingTableBuffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_callableShaderBindingTableBuffer = MapHandle<BufferInfo>(callableShaderBindingTableBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdTraceRaysNV(in_commandBuffer, in_raygenShaderBindingTableBuffer, raygenShaderBindingOffset, in_missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, in_hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, in_callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

void VulkanReplayConsumer::Process_vkCreateRayTracingPipelinesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipelineCache in_pipelineCache = MapHandle<PipelineCacheInfo>(pipelineCache, &VulkanObjectInfoTable::GetPipelineCacheInfo);
    const VkRayTracingPipelineCreateInfoNV* in_pCreateInfos = pCreateInfos->GetPointer();
    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    VkPipeline* out_pPipelines = pPipelines->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateRayTracingPipelinesNV(in_device, in_pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);
    CheckResult("vkCreateRayTracingPipelinesNV", returnValue, replay_result);

    AddHandles<PipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), out_pPipelines, createInfoCount, &VulkanObjectInfoTable::AddPipelineInfo);
}

void VulkanReplayConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_pipeline = GetObjectInfoTable().GetPipelineInfo(pipeline);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

    VkResult replay_result = OverrideGetRayTracingShaderGroupHandlesKHR(GetDeviceTable(in_device->handle)->GetRayTracingShaderGroupHandlesKHR, returnValue, in_device, in_pipeline, firstGroup, groupCount, dataSize, pData);
    CheckResult("vkGetRayTracingShaderGroupHandlesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectInfoTable::GetPipelineInfo);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetRayTracingShaderGroupHandlesNV(in_device, in_pipeline, firstGroup, groupCount, dataSize, out_pData);
    CheckResult("vkGetRayTracingShaderGroupHandlesNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkAccelerationStructureNV in_accelerationStructure = MapHandle<AccelerationStructureNVInfo>(accelerationStructure, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetAccelerationStructureHandleNV(in_device, in_accelerationStructure, dataSize, out_pData);
    CheckResult("vkGetAccelerationStructureHandleNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkAccelerationStructureNV* in_pAccelerationStructures = MapHandles<AccelerationStructureNVInfo>(pAccelerationStructures, accelerationStructureCount, &VulkanObjectInfoTable::GetAccelerationStructureNVInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(in_commandBuffer, accelerationStructureCount, in_pAccelerationStructures, queryType, in_queryPool, firstQuery);
}

void VulkanReplayConsumer::Process_vkCompileDeferredNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectInfoTable::GetPipelineInfo);

    VkResult replay_result = GetDeviceTable(in_device)->CompileDeferredNV(in_device, in_pipeline, shader);
    CheckResult("vkCompileDeferredNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const void* in_pHostPointer = PreProcessExternalObject(pHostPointer, format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT, "vkGetMemoryHostPointerPropertiesEXT");
    VkMemoryHostPointerPropertiesEXT* out_pMemoryHostPointerProperties = pMemoryHostPointerProperties->IsNull() ? nullptr : pMemoryHostPointerProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryHostPointerPropertiesEXT(in_device, handleType, in_pHostPointer, out_pMemoryHostPointerProperties);
    CheckResult("vkGetMemoryHostPointerPropertiesEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<BufferInfo>(dstBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteBufferMarkerAMD(in_commandBuffer, pipelineStage, in_dstBuffer, dstOffset, marker);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pTimeDomainCount = pTimeDomainCount->IsNull() ? nullptr : pTimeDomainCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT, pTimeDomainCount, pTimeDomains, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkTimeDomainEXT* out_pTimeDomains = pTimeDomains->IsNull() ? nullptr : pTimeDomains->AllocateOutputData(*out_pTimeDomainCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(in_physicalDevice, out_pTimeDomainCount, out_pTimeDomains);
    CheckResult("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", returnValue, replay_result);

    if (pTimeDomains->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT, *out_pTimeDomainCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkCalibratedTimestampInfoEXT* in_pTimestampInfos = pTimestampInfos->GetPointer();
    uint64_t* out_pTimestamps = pTimestamps->IsNull() ? nullptr : pTimestamps->AllocateOutputData(timestampCount);
    uint64_t* out_pMaxDeviation = pMaxDeviation->IsNull() ? nullptr : pMaxDeviation->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetCalibratedTimestampsEXT(in_device, timestampCount, in_pTimestampInfos, out_pTimestamps, out_pMaxDeviation);
    CheckResult("vkGetCalibratedTimestampsEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksNV(in_commandBuffer, taskCount, firstTask);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectNV(in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectCountNV(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkRect2D* in_pExclusiveScissors = pExclusiveScissors->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetExclusiveScissorNV(in_commandBuffer, firstExclusiveScissor, exclusiveScissorCount, in_pExclusiveScissors);
}

void VulkanReplayConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const void* in_pCheckpointMarker = PreProcessExternalObject(pCheckpointMarker, format::ApiCallId::ApiCall_vkCmdSetCheckpointNV, "vkCmdSetCheckpointNV");

    GetDeviceTable(in_commandBuffer)->CmdSetCheckpointNV(in_commandBuffer, in_pCheckpointMarker);
}

void VulkanReplayConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectInfoTable::GetQueueInfo);
    uint32_t* out_pCheckpointDataCount = pCheckpointDataCount->IsNull() ? nullptr : pCheckpointDataCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, QueueInfo>("vkGetQueueCheckpointDataNV", VK_SUCCESS, queue, kQueueArrayGetQueueCheckpointDataNV, pCheckpointDataCount, pCheckpointData, &VulkanObjectInfoTable::GetQueueInfo));
    VkCheckpointDataNV* out_pCheckpointData = pCheckpointData->IsNull() ? nullptr : pCheckpointData->AllocateOutputData(*out_pCheckpointDataCount, VkCheckpointDataNV{ VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV, nullptr });

    GetDeviceTable(in_queue)->GetQueueCheckpointDataNV(in_queue, out_pCheckpointDataCount, out_pCheckpointData);

    if (pCheckpointData->IsNull()) { SetOutputArrayCount<QueueInfo>(queue, kQueueArrayGetQueueCheckpointDataNV, *out_pCheckpointDataCount, &VulkanObjectInfoTable::GetQueueInfo); }
}

void VulkanReplayConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkInitializePerformanceApiInfoINTEL* in_pInitializeInfo = pInitializeInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->InitializePerformanceApiINTEL(in_device, in_pInitializeInfo);
    CheckResult("vkInitializePerformanceApiINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);

    GetDeviceTable(in_device)->UninitializePerformanceApiINTEL(in_device);
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkPerformanceMarkerInfoINTEL* in_pMarkerInfo = pMarkerInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceMarkerINTEL(in_commandBuffer, in_pMarkerInfo);
    CheckResult("vkCmdSetPerformanceMarkerINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkPerformanceStreamMarkerInfoINTEL* in_pMarkerInfo = pMarkerInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceStreamMarkerINTEL(in_commandBuffer, in_pMarkerInfo);
    CheckResult("vkCmdSetPerformanceStreamMarkerINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkPerformanceOverrideInfoINTEL* in_pOverrideInfo = pOverrideInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceOverrideINTEL(in_commandBuffer, in_pOverrideInfo);
    CheckResult("vkCmdSetPerformanceOverrideINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkPerformanceConfigurationAcquireInfoINTEL* in_pAcquireInfo = pAcquireInfo->GetPointer();
    if (!pConfiguration->IsNull()) { pConfiguration->SetHandleLength(1); }
    VkPerformanceConfigurationINTEL* out_pConfiguration = pConfiguration->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->AcquirePerformanceConfigurationINTEL(in_device, in_pAcquireInfo, out_pConfiguration);
    CheckResult("vkAcquirePerformanceConfigurationINTEL", returnValue, replay_result);

    AddHandle<PerformanceConfigurationINTELInfo>(device, pConfiguration->GetPointer(), out_pConfiguration, &VulkanObjectInfoTable::AddPerformanceConfigurationINTELInfo);
}

void VulkanReplayConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPerformanceConfigurationINTEL in_configuration = MapHandle<PerformanceConfigurationINTELInfo>(configuration, &VulkanObjectInfoTable::GetPerformanceConfigurationINTELInfo);

    VkResult replay_result = GetDeviceTable(in_device)->ReleasePerformanceConfigurationINTEL(in_device, in_configuration);
    CheckResult("vkReleasePerformanceConfigurationINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    VkQueue in_queue = MapHandle<QueueInfo>(queue, &VulkanObjectInfoTable::GetQueueInfo);
    VkPerformanceConfigurationINTEL in_configuration = MapHandle<PerformanceConfigurationINTELInfo>(configuration, &VulkanObjectInfoTable::GetPerformanceConfigurationINTELInfo);

    VkResult replay_result = GetDeviceTable(in_queue)->QueueSetPerformanceConfigurationINTEL(in_queue, in_configuration);
    CheckResult("vkQueueSetPerformanceConfigurationINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPerformanceValueINTEL* out_pValue = pValue->IsNull() ? nullptr : pValue->AllocateOutputData(1);

    VkResult replay_result = GetDeviceTable(in_device)->GetPerformanceParameterINTEL(in_device, parameter, out_pValue);
    CheckResult("vkGetPerformanceParameterINTEL", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSwapchainKHR in_swapChain = MapHandle<SwapchainKHRInfo>(swapChain, &VulkanObjectInfoTable::GetSwapchainKHRInfo);

    GetDeviceTable(in_device)->SetLocalDimmingAMD(in_device, in_swapChain, localDimmingEnable);
}

void VulkanReplayConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkImagePipeSurfaceCreateInfoFUCHSIA* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateImagePipeSurfaceFUCHSIA(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateImagePipeSurfaceFUCHSIA", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkMetalSurfaceCreateInfoEXT* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateMetalSurfaceEXT(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateMetalSurfaceEXT", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkBufferDeviceAddressInfo* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetBufferDeviceAddressEXT(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pToolCount = pToolCount->IsNull() ? nullptr : pToolCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceToolPropertiesEXT", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT, pToolCount, pToolProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkPhysicalDeviceToolProperties* out_pToolProperties = pToolProperties->IsNull() ? nullptr : pToolProperties->AllocateOutputData(*out_pToolCount, VkPhysicalDeviceToolProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceToolPropertiesEXT(in_physicalDevice, out_pToolCount, out_pToolProperties);
    CheckResult("vkGetPhysicalDeviceToolPropertiesEXT", returnValue, replay_result);

    if (pToolProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT, *out_pToolCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV, pPropertyCount, pProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkCooperativeMatrixPropertiesNV* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkCooperativeMatrixPropertiesNV{ VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesNV(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV, *out_pPropertyCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    uint32_t* out_pCombinationCount = pCombinationCount->IsNull() ? nullptr : pCombinationCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV, pCombinationCount, pCombinations, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkFramebufferMixedSamplesCombinationNV* out_pCombinations = pCombinations->IsNull() ? nullptr : pCombinations->AllocateOutputData(*out_pCombinationCount, VkFramebufferMixedSamplesCombinationNV{ VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(in_physicalDevice, out_pCombinationCount, out_pCombinations);
    CheckResult("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", returnValue, replay_result);

    if (pCombinations->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV, *out_pCombinationCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = pSurfaceInfo->GetPointer();
    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    uint32_t* out_pPresentModeCount = pPresentModeCount->IsNull() ? nullptr : pPresentModeCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceSurfacePresentModes2EXT", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT, pPresentModeCount, pPresentModes, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkPresentModeKHR* out_pPresentModes = pPresentModes->IsNull() ? nullptr : pPresentModes->AllocateOutputData(*out_pPresentModeCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfacePresentModes2EXT(in_physicalDevice, in_pSurfaceInfo, out_pPresentModeCount, out_pPresentModes);
    CheckResult("vkGetPhysicalDeviceSurfacePresentModes2EXT", returnValue, replay_result);

    if (pPresentModes->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT, *out_pPresentModeCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->AcquireFullScreenExclusiveModeEXT(in_device, in_swapchain);
    CheckResult("vkAcquireFullScreenExclusiveModeEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<SwapchainKHRInfo>(swapchain, &VulkanObjectInfoTable::GetSwapchainKHRInfo);
    if (GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(GetObjectInfoTable().GetSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->ReleaseFullScreenExclusiveModeEXT(in_device, in_swapchain);
    CheckResult("vkReleaseFullScreenExclusiveModeEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = pSurfaceInfo->GetPointer();
    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    VkDeviceGroupPresentModeFlagsKHR* out_pModes = pModes->IsNull() ? nullptr : pModes->AllocateOutputData(1, static_cast<VkDeviceGroupPresentModeFlagsKHR>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupSurfacePresentModes2EXT(in_device, in_pSurfaceInfo, out_pModes);
    CheckResult("vkGetDeviceGroupSurfacePresentModes2EXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkHeadlessSurfaceCreateInfoEXT* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateHeadlessSurfaceEXT(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateHeadlessSurfaceEXT", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineStippleEXT(in_commandBuffer, lineStippleFactor, lineStipplePattern);
}

void VulkanReplayConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_device)->ResetQueryPoolEXT(in_device, in_queryPool, firstQuery, queryCount);
}

void VulkanReplayConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCullModeEXT(in_commandBuffer, cullMode);
}

void VulkanReplayConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetFrontFaceEXT(in_commandBuffer, frontFace);
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveTopologyEXT(in_commandBuffer, primitiveTopology);
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkViewport* in_pViewports = pViewports->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWithCountEXT(in_commandBuffer, viewportCount, in_pViewports);
}

void VulkanReplayConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkRect2D* in_pScissors = pScissors->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetScissorWithCountEXT(in_commandBuffer, scissorCount, in_pScissors);
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<BufferInfo>(pBuffers, bindingCount, &VulkanObjectInfoTable::GetBufferInfo);
    const VkDeviceSize* in_pOffsets = pOffsets->GetPointer();
    const VkDeviceSize* in_pSizes = pSizes->GetPointer();
    const VkDeviceSize* in_pStrides = pStrides->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers2EXT(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets, in_pSizes, in_pStrides);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthTestEnableEXT(in_commandBuffer, depthTestEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthWriteEnableEXT(in_commandBuffer, depthWriteEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthCompareOpEXT(in_commandBuffer, depthCompareOp);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBoundsTestEnableEXT(in_commandBuffer, depthBoundsTestEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilTestEnableEXT(in_commandBuffer, stencilTestEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilOpEXT(in_commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void VulkanReplayConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkReleaseSwapchainImagesInfoEXT* in_pReleaseInfo = pReleaseInfo->GetPointer();
    MapStructHandles(pReleaseInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ReleaseSwapchainImagesEXT(in_device, in_pReleaseInfo);
    CheckResult("vkReleaseSwapchainImagesEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkGeneratedCommandsMemoryRequirementsInfoNV* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetGeneratedCommandsMemoryRequirementsNV(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkGeneratedCommandsInfoNV* in_pGeneratedCommandsInfo = pGeneratedCommandsInfo->GetPointer();
    MapStructHandles(pGeneratedCommandsInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPreprocessGeneratedCommandsNV(in_commandBuffer, in_pGeneratedCommandsInfo);
}

void VulkanReplayConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkGeneratedCommandsInfoNV* in_pGeneratedCommandsInfo = pGeneratedCommandsInfo->GetPointer();
    MapStructHandles(pGeneratedCommandsInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdExecuteGeneratedCommandsNV(in_commandBuffer, isPreprocessed, in_pGeneratedCommandsInfo);
}

void VulkanReplayConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectInfoTable::GetPipelineInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindPipelineShaderGroupNV(in_commandBuffer, pipelineBindPoint, in_pipeline, groupIndex);
}

void VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkIndirectCommandsLayoutCreateInfoNV* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pIndirectCommandsLayout->IsNull()) { pIndirectCommandsLayout->SetHandleLength(1); }
    VkIndirectCommandsLayoutNV* out_pIndirectCommandsLayout = pIndirectCommandsLayout->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateIndirectCommandsLayoutNV(in_device, in_pCreateInfo, in_pAllocator, out_pIndirectCommandsLayout);
    CheckResult("vkCreateIndirectCommandsLayoutNV", returnValue, replay_result);

    AddHandle<IndirectCommandsLayoutNVInfo>(device, pIndirectCommandsLayout->GetPointer(), out_pIndirectCommandsLayout, &VulkanObjectInfoTable::AddIndirectCommandsLayoutNVInfo);
}

void VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkIndirectCommandsLayoutNV in_indirectCommandsLayout = MapHandle<IndirectCommandsLayoutNVInfo>(indirectCommandsLayout, &VulkanObjectInfoTable::GetIndirectCommandsLayoutNVInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyIndirectCommandsLayoutNV(in_device, in_indirectCommandsLayout, in_pAllocator);
    RemoveHandle(indirectCommandsLayout, &VulkanObjectInfoTable::RemoveIndirectCommandsLayoutNVInfo);
}

void VulkanReplayConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    format::HandleId                            display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectInfoTable::GetDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->AcquireDrmDisplayEXT(in_physicalDevice, drmFd, in_display);
    CheckResult("vkAcquireDrmDisplayEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    HandlePointerDecoder<VkDisplayKHR>*         display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    if (!display->IsNull()) { display->SetHandleLength(1); }
    VkDisplayKHR* out_display = display->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDrmDisplayEXT(in_physicalDevice, drmFd, connectorId, out_display);
    CheckResult("vkGetDrmDisplayEXT", returnValue, replay_result);

    AddHandle<DisplayKHRInfo>(physicalDevice, display->GetPointer(), out_display, &VulkanObjectInfoTable::AddDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkPrivateDataSlotCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pPrivateDataSlot->IsNull()) { pPrivateDataSlot->SetHandleLength(1); }
    VkPrivateDataSlot* out_pPrivateDataSlot = pPrivateDataSlot->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreatePrivateDataSlotEXT(in_device, in_pCreateInfo, in_pAllocator, out_pPrivateDataSlot);
    CheckResult("vkCreatePrivateDataSlotEXT", returnValue, replay_result);

    AddHandle<PrivateDataSlotInfo>(device, pPrivateDataSlot->GetPointer(), out_pPrivateDataSlot, &VulkanObjectInfoTable::AddPrivateDataSlotInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<PrivateDataSlotInfo>(privateDataSlot, &VulkanObjectInfoTable::GetPrivateDataSlotInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPrivateDataSlotEXT(in_device, in_privateDataSlot, in_pAllocator);
    RemoveHandle(privateDataSlot, &VulkanObjectInfoTable::RemovePrivateDataSlotInfo);
}

void VulkanReplayConsumer::Process_vkSetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<PrivateDataSlotInfo>(privateDataSlot, &VulkanObjectInfoTable::GetPrivateDataSlotInfo);

    VkResult replay_result = GetDeviceTable(in_device)->SetPrivateDataEXT(in_device, objectType, in_objectHandle, in_privateDataSlot, data);
    CheckResult("vkSetPrivateDataEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<PrivateDataSlotInfo>(privateDataSlot, &VulkanObjectInfoTable::GetPrivateDataSlotInfo);
    uint64_t* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(1, static_cast<uint64_t>(0));

    GetDeviceTable(in_device)->GetPrivateDataEXT(in_device, objectType, in_objectHandle, in_privateDataSlot, out_pData);
}

void VulkanReplayConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkFragmentShadingRateCombinerOpKHR* in_combinerOps = combinerOps->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetFragmentShadingRateEnumNV(in_commandBuffer, shadingRate, in_combinerOps);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2EXT>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2EXT>* pLayout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkImage in_image = MapHandle<ImageInfo>(image, &VulkanObjectInfoTable::GetImageInfo);
    const VkImageSubresource2EXT* in_pSubresource = pSubresource->GetPointer();
    VkSubresourceLayout2EXT* out_pLayout = pLayout->IsNull() ? nullptr : pLayout->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_EXT, nullptr });

    GetDeviceTable(in_device)->GetImageSubresourceLayout2EXT(in_device, in_image, in_pSubresource, out_pLayout);
}

void VulkanReplayConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts,
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeviceFaultCountsEXT* out_pFaultCounts = pFaultCounts->IsNull() ? nullptr : pFaultCounts->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT, nullptr });
    VkDeviceFaultInfoEXT* out_pFaultInfo = pFaultInfo->IsNull() ? nullptr : pFaultInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceFaultInfoEXT(in_device, out_pFaultCounts, out_pFaultInfo);
    CheckResult("vkGetDeviceFaultInfoEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<DisplayKHRInfo>(display, &VulkanObjectInfoTable::GetDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->AcquireWinrtDisplayNV(in_physicalDevice, in_display);
    CheckResult("vkAcquireWinrtDisplayNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    if (!pDisplay->IsNull()) { pDisplay->SetHandleLength(1); }
    VkDisplayKHR* out_pDisplay = pDisplay->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetWinrtDisplayNV(in_physicalDevice, deviceRelativeId, out_pDisplay);
    CheckResult("vkGetWinrtDisplayNV", returnValue, replay_result);

    AddHandle<DisplayKHRInfo>(physicalDevice, pDisplay->GetPointer(), out_pDisplay, &VulkanObjectInfoTable::AddDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkDirectFBSurfaceCreateInfoEXT* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateDirectFBSurfaceEXT(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateDirectFBSurfaceEXT", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    IDirectFB* in_dfb = static_cast<IDirectFB*>(PreProcessExternalObject(dfb, format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT"));

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDirectFBPresentationSupportEXT(in_physicalDevice, queueFamilyIndex, in_dfb);
}

void VulkanReplayConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkVertexInputBindingDescription2EXT* in_pVertexBindingDescriptions = pVertexBindingDescriptions->GetPointer();
    const VkVertexInputAttributeDescription2EXT* in_pVertexAttributeDescriptions = pVertexAttributeDescriptions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetVertexInputEXT(in_commandBuffer, vertexBindingDescriptionCount, in_pVertexBindingDescriptions, vertexAttributeDescriptionCount, in_pVertexAttributeDescriptions);
}

void VulkanReplayConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkMemoryGetZirconHandleInfoFUCHSIA* in_pGetZirconHandleInfo = pGetZirconHandleInfo->GetPointer();
    MapStructHandles(pGetZirconHandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    zx_handle_t* out_pZirconHandle = pZirconHandle->IsNull() ? nullptr : pZirconHandle->AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryZirconHandleFUCHSIA(in_device, in_pGetZirconHandleInfo, out_pZirconHandle);
    CheckResult("vkGetMemoryZirconHandleFUCHSIA", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint32_t                                    zirconHandle,
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkMemoryZirconHandlePropertiesFUCHSIA* out_pMemoryZirconHandleProperties = pMemoryZirconHandleProperties->IsNull() ? nullptr : pMemoryZirconHandleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryZirconHandlePropertiesFUCHSIA(in_device, handleType, zirconHandle, out_pMemoryZirconHandleProperties);
    CheckResult("vkGetMemoryZirconHandlePropertiesFUCHSIA", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkImportSemaphoreZirconHandleInfoFUCHSIA* in_pImportSemaphoreZirconHandleInfo = pImportSemaphoreZirconHandleInfo->GetPointer();
    MapStructHandles(pImportSemaphoreZirconHandleInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ImportSemaphoreZirconHandleFUCHSIA(in_device, in_pImportSemaphoreZirconHandleInfo);
    CheckResult("vkImportSemaphoreZirconHandleFUCHSIA", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkSemaphoreGetZirconHandleInfoFUCHSIA* in_pGetZirconHandleInfo = pGetZirconHandleInfo->GetPointer();
    MapStructHandles(pGetZirconHandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    zx_handle_t* out_pZirconHandle = pZirconHandle->IsNull() ? nullptr : pZirconHandle->AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreZirconHandleFUCHSIA(in_device, in_pGetZirconHandleInfo, out_pZirconHandle);
    CheckResult("vkGetSemaphoreZirconHandleFUCHSIA", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkImageView in_imageView = MapHandle<ImageViewInfo>(imageView, &VulkanObjectInfoTable::GetImageViewInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindInvocationMaskHUAWEI(in_commandBuffer, in_imageView, imageLayout);
}

void VulkanReplayConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo,
    PointerDecoder<uint64_t, void*>*            pAddress)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkMemoryGetRemoteAddressInfoNV* in_pMemoryGetRemoteAddressInfo = pMemoryGetRemoteAddressInfo->GetPointer();
    MapStructHandles(pMemoryGetRemoteAddressInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkRemoteAddressNV* out_pAddress = pAddress->IsNull() ? nullptr : reinterpret_cast<VkRemoteAddressNV*>(pAddress->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryRemoteAddressNV(in_device, in_pMemoryGetRemoteAddressInfo, out_pAddress);
    CheckResult("vkGetMemoryRemoteAddressNV", returnValue, replay_result);

    PostProcessExternalObject(replay_result, (*pAddress->GetPointer()), static_cast<void*>(*out_pAddress), format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV, "vkGetMemoryRemoteAddressNV");
}

void VulkanReplayConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPatchControlPointsEXT(in_commandBuffer, patchControlPoints);
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizerDiscardEnableEXT(in_commandBuffer, rasterizerDiscardEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBiasEnableEXT(in_commandBuffer, depthBiasEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLogicOpEXT(in_commandBuffer, logicOp);
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveRestartEnableEXT(in_commandBuffer, primitiveRestartEnable);
}

void VulkanReplayConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<InstanceInfo>(instance, &VulkanObjectInfoTable::GetInstanceInfo);
    const VkScreenSurfaceCreateInfoQNX* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateScreenSurfaceQNX(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateScreenSurfaceQNX", returnValue, replay_result);

    AddHandle<SurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &VulkanObjectInfoTable::AddSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    window)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    struct _screen_window* in_window = static_cast<struct _screen_window*>(PreProcessExternalObject(window, format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX, "vkGetPhysicalDeviceScreenPresentationSupportQNX"));

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceScreenPresentationSupportQNX(in_physicalDevice, queueFamilyIndex, in_window);
}

void VulkanReplayConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkBool32* in_pColorWriteEnables = pColorWriteEnables->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorWriteEnableEXT(in_commandBuffer, attachmentCount, in_pColorWriteEnables);
}

void VulkanReplayConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkMultiDrawInfoEXT* in_pVertexInfo = pVertexInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDrawMultiEXT(in_commandBuffer, drawCount, in_pVertexInfo, instanceCount, firstInstance, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    PointerDecoder<int32_t>*                    pVertexOffset)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkMultiDrawIndexedInfoEXT* in_pIndexInfo = pIndexInfo->GetPointer();
    const int32_t* in_pVertexOffset = pVertexOffset->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDrawMultiIndexedEXT(in_commandBuffer, drawCount, in_pIndexInfo, instanceCount, firstInstance, stride, in_pVertexOffset);
}

void VulkanReplayConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromap)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkMicromapCreateInfoEXT* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pMicromap->IsNull()) { pMicromap->SetHandleLength(1); }
    VkMicromapEXT* out_pMicromap = pMicromap->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateMicromapEXT(in_device, in_pCreateInfo, in_pAllocator, out_pMicromap);
    CheckResult("vkCreateMicromapEXT", returnValue, replay_result);

    AddHandle<MicromapEXTInfo>(device, pMicromap->GetPointer(), out_pMicromap, &VulkanObjectInfoTable::AddMicromapEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkMicromapEXT in_micromap = MapHandle<MicromapEXTInfo>(micromap, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyMicromapEXT(in_device, in_micromap, in_pAllocator);
    RemoveHandle(micromap, &VulkanObjectInfoTable::RemoveMicromapEXTInfo);
}

void VulkanReplayConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkMicromapBuildInfoEXT* in_pInfos = pInfos->GetPointer();
    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBuildMicromapsEXT(in_commandBuffer, infoCount, in_pInfos);
}

void VulkanReplayConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<DeferredOperationKHRInfo>(deferredOperation, &VulkanObjectInfoTable::GetDeferredOperationKHRInfo);
    const VkMicromapBuildInfoEXT* in_pInfos = pInfos->GetPointer();
    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->BuildMicromapsEXT(in_device, in_deferredOperation, infoCount, in_pInfos);
    CheckResult("vkBuildMicromapsEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<DeferredOperationKHRInfo>(deferredOperation, &VulkanObjectInfoTable::GetDeferredOperationKHRInfo);
    const VkCopyMicromapInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMicromapEXT(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMicromapEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<DeferredOperationKHRInfo>(deferredOperation, &VulkanObjectInfoTable::GetDeferredOperationKHRInfo);
    const VkCopyMicromapToMemoryInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMicromapToMemoryEXT(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMicromapToMemoryEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<DeferredOperationKHRInfo>(deferredOperation, &VulkanObjectInfoTable::GetDeferredOperationKHRInfo);
    const VkCopyMemoryToMicromapInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMemoryToMicromapEXT(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMemoryToMicromapEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkMicromapEXT* in_pMicromaps = MapHandles<MicromapEXTInfo>(pMicromaps, micromapCount, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->WriteMicromapsPropertiesEXT(in_device, micromapCount, in_pMicromaps, queryType, dataSize, out_pData, stride);
    CheckResult("vkWriteMicromapsPropertiesEXT", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyMicromapInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMicromapEXT(in_commandBuffer, in_pInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyMicromapToMemoryInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMicromapToMemoryEXT(in_commandBuffer, in_pInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyMemoryToMicromapInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMemoryToMicromapEXT(in_commandBuffer, in_pInfo);
}

void VulkanReplayConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkMicromapEXT* in_pMicromaps = MapHandles<MicromapEXTInfo>(pMicromaps, micromapCount, &VulkanObjectInfoTable::GetMicromapEXTInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteMicromapsPropertiesEXT(in_commandBuffer, micromapCount, in_pMicromaps, queryType, in_queryPool, firstQuery);
}

void VulkanReplayConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkMicromapVersionInfoEXT* in_pVersionInfo = pVersionInfo->GetPointer();
    VkAccelerationStructureCompatibilityKHR* out_pCompatibility = pCompatibility->IsNull() ? nullptr : pCompatibility->AllocateOutputData(1, static_cast<VkAccelerationStructureCompatibilityKHR>(0));

    GetDeviceTable(in_device)->GetDeviceMicromapCompatibilityEXT(in_device, in_pVersionInfo, out_pCompatibility);
}

void VulkanReplayConsumer::Process_vkGetMicromapBuildSizesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo,
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkMicromapBuildInfoEXT* in_pBuildInfo = pBuildInfo->GetPointer();
    MapStructHandles(pBuildInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMicromapBuildSizesInfoEXT* out_pSizeInfo = pSizeInfo->IsNull() ? nullptr : pSizeInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT, nullptr });

    GetDeviceTable(in_device)->GetMicromapBuildSizesEXT(in_device, buildType, in_pBuildInfo, out_pSizeInfo);
}

void VulkanReplayConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawClusterHUAWEI(in_commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawClusterIndirectHUAWEI(in_commandBuffer, in_buffer, offset);
}

void VulkanReplayConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeviceMemory in_memory = MapHandle<DeviceMemoryInfo>(memory, &VulkanObjectInfoTable::GetDeviceMemoryInfo);

    GetDeviceTable(in_device)->SetDeviceMemoryPriorityEXT(in_device, in_memory, priority);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkDescriptorSetBindingReferenceVALVE* in_pBindingReference = pBindingReference->GetPointer();
    MapStructHandles(pBindingReference->GetMetaStructPointer(), GetObjectInfoTable());
    VkDescriptorSetLayoutHostMappingInfoVALVE* out_pHostMapping = pHostMapping->IsNull() ? nullptr : pHostMapping->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE, nullptr });

    GetDeviceTable(in_device)->GetDescriptorSetLayoutHostMappingInfoVALVE(in_device, in_pBindingReference, out_pHostMapping);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDescriptorSet in_descriptorSet = MapHandle<DescriptorSetInfo>(descriptorSet, &VulkanObjectInfoTable::GetDescriptorSetInfo);
    void** out_ppData = ppData->IsNull() ? nullptr : ppData->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetDescriptorSetHostMappingVALVE(in_device, in_descriptorSet, out_ppData);

    PostProcessExternalObject(VK_SUCCESS, (*ppData->GetPointer()), *ppData->GetOutputPointer(), format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE, "vkGetDescriptorSetHostMappingVALVE");
}

void VulkanReplayConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetTessellationDomainOriginEXT(in_commandBuffer, domainOrigin);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClampEnableEXT(in_commandBuffer, depthClampEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPolygonModeEXT(in_commandBuffer, polygonMode);
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizationSamplesEXT(in_commandBuffer, rasterizationSamples);
}

void VulkanReplayConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkSampleMask* in_pSampleMask = pSampleMask->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetSampleMaskEXT(in_commandBuffer, samples, in_pSampleMask);
}

void VulkanReplayConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetAlphaToCoverageEnableEXT(in_commandBuffer, alphaToCoverageEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetAlphaToOneEnableEXT(in_commandBuffer, alphaToOneEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLogicOpEnableEXT(in_commandBuffer, logicOpEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorBlendEnables)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkBool32* in_pColorBlendEnables = pColorBlendEnables->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorBlendEnableEXT(in_commandBuffer, firstAttachment, attachmentCount, in_pColorBlendEnables);
}

void VulkanReplayConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkColorBlendEquationEXT* in_pColorBlendEquations = pColorBlendEquations->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorBlendEquationEXT(in_commandBuffer, firstAttachment, attachmentCount, in_pColorBlendEquations);
}

void VulkanReplayConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkColorComponentFlags* in_pColorWriteMasks = pColorWriteMasks->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorWriteMaskEXT(in_commandBuffer, firstAttachment, attachmentCount, in_pColorWriteMasks);
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizationStreamEXT(in_commandBuffer, rasterizationStream);
}

void VulkanReplayConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetConservativeRasterizationModeEXT(in_commandBuffer, conservativeRasterizationMode);
}

void VulkanReplayConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetExtraPrimitiveOverestimationSizeEXT(in_commandBuffer, extraPrimitiveOverestimationSize);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClipEnableEXT(in_commandBuffer, depthClipEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetSampleLocationsEnableEXT(in_commandBuffer, sampleLocationsEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkColorBlendAdvancedEXT* in_pColorBlendAdvanced = pColorBlendAdvanced->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorBlendAdvancedEXT(in_commandBuffer, firstAttachment, attachmentCount, in_pColorBlendAdvanced);
}

void VulkanReplayConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetProvokingVertexModeEXT(in_commandBuffer, provokingVertexMode);
}

void VulkanReplayConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineRasterizationModeEXT(in_commandBuffer, lineRasterizationMode);
}

void VulkanReplayConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineStippleEnableEXT(in_commandBuffer, stippledLineEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClipNegativeOneToOneEXT(in_commandBuffer, negativeOneToOne);
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWScalingEnableNV(in_commandBuffer, viewportWScalingEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkViewportSwizzleNV* in_pViewportSwizzles = pViewportSwizzles->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportSwizzleNV(in_commandBuffer, firstViewport, viewportCount, in_pViewportSwizzles);
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageToColorEnableNV(in_commandBuffer, coverageToColorEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageToColorLocationNV(in_commandBuffer, coverageToColorLocation);
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationModeNV(in_commandBuffer, coverageModulationMode);
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationTableEnableNV(in_commandBuffer, coverageModulationTableEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const float* in_pCoverageModulationTable = pCoverageModulationTable->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationTableNV(in_commandBuffer, coverageModulationTableCount, in_pCoverageModulationTable);
}

void VulkanReplayConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetShadingRateImageEnableNV(in_commandBuffer, shadingRateImageEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRepresentativeFragmentTestEnableNV(in_commandBuffer, representativeFragmentTestEnable);
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageReductionModeNV(in_commandBuffer, coverageReductionMode);
}

void VulkanReplayConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkShaderModule in_shaderModule = MapHandle<ShaderModuleInfo>(shaderModule, &VulkanObjectInfoTable::GetShaderModuleInfo);
    VkShaderModuleIdentifierEXT* out_pIdentifier = pIdentifier->IsNull() ? nullptr : pIdentifier->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT, nullptr });

    GetDeviceTable(in_device)->GetShaderModuleIdentifierEXT(in_device, in_shaderModule, out_pIdentifier);
}

void VulkanReplayConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkShaderModuleCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkShaderModuleIdentifierEXT* out_pIdentifier = pIdentifier->IsNull() ? nullptr : pIdentifier->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT, nullptr });

    GetDeviceTable(in_device)->GetShaderModuleCreateInfoIdentifierEXT(in_device, in_pCreateInfo, out_pIdentifier);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo,
    PointerDecoder<uint32_t>*                   pFormatCount,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<PhysicalDeviceInfo>(physicalDevice, &VulkanObjectInfoTable::GetPhysicalDeviceInfo);
    const VkOpticalFlowImageFormatInfoNV* in_pOpticalFlowImageFormatInfo = pOpticalFlowImageFormatInfo->GetPointer();
    uint32_t* out_pFormatCount = pFormatCount->IsNull() ? nullptr : pFormatCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, PhysicalDeviceInfo>("vkGetPhysicalDeviceOpticalFlowImageFormatsNV", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceOpticalFlowImageFormatsNV, pFormatCount, pImageFormatProperties, &VulkanObjectInfoTable::GetPhysicalDeviceInfo));
    VkOpticalFlowImageFormatPropertiesNV* out_pImageFormatProperties = pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(*out_pFormatCount, VkOpticalFlowImageFormatPropertiesNV{ VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceOpticalFlowImageFormatsNV(in_physicalDevice, in_pOpticalFlowImageFormatInfo, out_pFormatCount, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceOpticalFlowImageFormatsNV", returnValue, replay_result);

    if (pImageFormatProperties->IsNull()) { SetOutputArrayCount<PhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceOpticalFlowImageFormatsNV, *out_pFormatCount, &VulkanObjectInfoTable::GetPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkOpticalFlowSessionCreateInfoNV* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSession->IsNull()) { pSession->SetHandleLength(1); }
    VkOpticalFlowSessionNV* out_pSession = pSession->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateOpticalFlowSessionNV(in_device, in_pCreateInfo, in_pAllocator, out_pSession);
    CheckResult("vkCreateOpticalFlowSessionNV", returnValue, replay_result);

    AddHandle<OpticalFlowSessionNVInfo>(device, pSession->GetPointer(), out_pSession, &VulkanObjectInfoTable::AddOpticalFlowSessionNVInfo);
}

void VulkanReplayConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkOpticalFlowSessionNV in_session = MapHandle<OpticalFlowSessionNVInfo>(session, &VulkanObjectInfoTable::GetOpticalFlowSessionNVInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyOpticalFlowSessionNV(in_device, in_session, in_pAllocator);
    RemoveHandle(session, &VulkanObjectInfoTable::RemoveOpticalFlowSessionNVInfo);
}

void VulkanReplayConsumer::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            session,
    VkOpticalFlowSessionBindingPointNV          bindingPoint,
    format::HandleId                            view,
    VkImageLayout                               layout)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkOpticalFlowSessionNV in_session = MapHandle<OpticalFlowSessionNVInfo>(session, &VulkanObjectInfoTable::GetOpticalFlowSessionNVInfo);
    VkImageView in_view = MapHandle<ImageViewInfo>(view, &VulkanObjectInfoTable::GetImageViewInfo);

    VkResult replay_result = GetDeviceTable(in_device)->BindOpticalFlowSessionImageNV(in_device, in_session, bindingPoint, in_view, layout);
    CheckResult("vkBindOpticalFlowSessionImageNV", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkOpticalFlowSessionNV in_session = MapHandle<OpticalFlowSessionNVInfo>(session, &VulkanObjectInfoTable::GetOpticalFlowSessionNVInfo);
    const VkOpticalFlowExecuteInfoNV* in_pExecuteInfo = pExecuteInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdOpticalFlowExecuteNV(in_commandBuffer, in_session, in_pExecuteInfo);
}

void VulkanReplayConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    PointerDecoder<uint32_t>*                   pPropertiesCount,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkFramebuffer in_framebuffer = MapHandle<FramebufferInfo>(framebuffer, &VulkanObjectInfoTable::GetFramebufferInfo);
    uint32_t* out_pPropertiesCount = pPropertiesCount->IsNull() ? nullptr : pPropertiesCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, FramebufferInfo>("vkGetFramebufferTilePropertiesQCOM", returnValue, framebuffer, kFramebufferArrayGetFramebufferTilePropertiesQCOM, pPropertiesCount, pProperties, &VulkanObjectInfoTable::GetFramebufferInfo));
    VkTilePropertiesQCOM* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertiesCount, VkTilePropertiesQCOM{ VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetFramebufferTilePropertiesQCOM(in_device, in_framebuffer, out_pPropertiesCount, out_pProperties);
    CheckResult("vkGetFramebufferTilePropertiesQCOM", returnValue, replay_result);

    if (pProperties->IsNull()) { SetOutputArrayCount<FramebufferInfo>(framebuffer, kFramebufferArrayGetFramebufferTilePropertiesQCOM, *out_pPropertiesCount, &VulkanObjectInfoTable::GetFramebufferInfo); }
}

void VulkanReplayConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkRenderingInfo* in_pRenderingInfo = pRenderingInfo->GetPointer();
    MapStructHandles(pRenderingInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkTilePropertiesQCOM* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetDynamicRenderingTilePropertiesQCOM(in_device, in_pRenderingInfo, out_pProperties);
    CheckResult("vkGetDynamicRenderingTilePropertiesQCOM", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pAccelerationStructure->IsNull()) { pAccelerationStructure->SetHandleLength(1); }
    AccelerationStructureKHRInfo handle_info;
    pAccelerationStructure->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateAccelerationStructureKHR(GetDeviceTable(in_device->handle)->CreateAccelerationStructureKHR, returnValue, in_device, pCreateInfo, pAllocator, pAccelerationStructure);
    CheckResult("vkCreateAccelerationStructureKHR", returnValue, replay_result);

    AddHandle<AccelerationStructureKHRInfo>(device, pAccelerationStructure->GetPointer(), pAccelerationStructure->GetHandlePointer(), std::move(handle_info), &VulkanObjectInfoTable::AddAccelerationStructureKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkAccelerationStructureKHR in_accelerationStructure = MapHandle<AccelerationStructureKHRInfo>(accelerationStructure, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyAccelerationStructureKHR(in_device, in_accelerationStructure, in_pAllocator);
    RemoveHandle(accelerationStructure, &VulkanObjectInfoTable::RemoveAccelerationStructureKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkAccelerationStructureBuildGeometryInfoKHR* in_pInfos = pInfos->GetPointer();
    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());
    const VkAccelerationStructureBuildRangeInfoKHR* const* in_ppBuildRangeInfos = ppBuildRangeInfos->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBuildAccelerationStructuresKHR(in_commandBuffer, infoCount, in_pInfos, in_ppBuildRangeInfos);
}

void VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    PointerDecoder<VkDeviceAddress>*            pIndirectDeviceAddresses,
    PointerDecoder<uint32_t>*                   pIndirectStrides,
    PointerDecoder<uint32_t*>*                  ppMaxPrimitiveCounts)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkAccelerationStructureBuildGeometryInfoKHR* in_pInfos = pInfos->GetPointer();
    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());
    const VkDeviceAddress* in_pIndirectDeviceAddresses = pIndirectDeviceAddresses->GetPointer();
    const uint32_t* in_pIndirectStrides = pIndirectStrides->GetPointer();
    const uint32_t* const* in_ppMaxPrimitiveCounts = ppMaxPrimitiveCounts->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBuildAccelerationStructuresIndirectKHR(in_commandBuffer, infoCount, in_pInfos, in_pIndirectDeviceAddresses, in_pIndirectStrides, in_ppMaxPrimitiveCounts);
}

void VulkanReplayConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<DeferredOperationKHRInfo>(deferredOperation, &VulkanObjectInfoTable::GetDeferredOperationKHRInfo);
    const VkCopyAccelerationStructureToMemoryInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyAccelerationStructureToMemoryKHR(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyAccelerationStructureToMemoryKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<DeferredOperationKHRInfo>(deferredOperation, &VulkanObjectInfoTable::GetDeferredOperationKHRInfo);
    const VkCopyMemoryToAccelerationStructureInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMemoryToAccelerationStructureKHR(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMemoryToAccelerationStructureKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkAccelerationStructureKHR* in_pAccelerationStructures = MapHandles<AccelerationStructureKHRInfo>(pAccelerationStructures, accelerationStructureCount, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->WriteAccelerationStructuresPropertiesKHR(in_device, accelerationStructureCount, in_pAccelerationStructures, queryType, dataSize, out_pData, stride);
    CheckResult("vkWriteAccelerationStructuresPropertiesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyAccelerationStructureInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyAccelerationStructureKHR(in_commandBuffer, in_pInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyAccelerationStructureToMemoryInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyAccelerationStructureToMemoryKHR(in_commandBuffer, in_pInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkCopyMemoryToAccelerationStructureInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMemoryToAccelerationStructureKHR(in_commandBuffer, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetAccelerationStructureDeviceAddressKHR(GetDeviceTable(in_device->handle)->GetAccelerationStructureDeviceAddressKHR, in_device, pInfo);
}

void VulkanReplayConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkAccelerationStructureKHR* in_pAccelerationStructures = MapHandles<AccelerationStructureKHRInfo>(pAccelerationStructures, accelerationStructureCount, &VulkanObjectInfoTable::GetAccelerationStructureKHRInfo);
    VkQueryPool in_queryPool = MapHandle<QueryPoolInfo>(queryPool, &VulkanObjectInfoTable::GetQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteAccelerationStructuresPropertiesKHR(in_commandBuffer, accelerationStructureCount, in_pAccelerationStructures, queryType, in_queryPool, firstQuery);
}

void VulkanReplayConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkAccelerationStructureVersionInfoKHR* in_pVersionInfo = pVersionInfo->GetPointer();
    VkAccelerationStructureCompatibilityKHR* out_pCompatibility = pCompatibility->IsNull() ? nullptr : pCompatibility->AllocateOutputData(1, static_cast<VkAccelerationStructureCompatibilityKHR>(0));

    GetDeviceTable(in_device)->GetDeviceAccelerationStructureCompatibilityKHR(in_device, in_pVersionInfo, out_pCompatibility);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
    PointerDecoder<uint32_t>*                   pMaxPrimitiveCounts,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    const VkAccelerationStructureBuildGeometryInfoKHR* in_pBuildInfo = pBuildInfo->GetPointer();
    MapStructHandles(pBuildInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const uint32_t* in_pMaxPrimitiveCounts = pMaxPrimitiveCounts->GetPointer();
    VkAccelerationStructureBuildSizesInfoKHR* out_pSizeInfo = pSizeInfo->IsNull() ? nullptr : pSizeInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR, nullptr });

    GetDeviceTable(in_device)->GetAccelerationStructureBuildSizesKHR(in_device, buildType, in_pBuildInfo, in_pMaxPrimitiveCounts, out_pSizeInfo);
}

void VulkanReplayConsumer::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdTraceRaysKHR(in_commandBuffer, in_pRaygenShaderBindingTable, in_pMissShaderBindingTable, in_pHitShaderBindingTable, in_pCallableShaderBindingTable, width, height, depth);
}

void VulkanReplayConsumer::Process_vkCreateRayTracingPipelinesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    auto in_device = GetObjectInfoTable().GetDeviceInfo(device);
    auto in_deferredOperation = GetObjectInfoTable().GetDeferredOperationKHRInfo(deferredOperation);
    auto in_pipelineCache = GetObjectInfoTable().GetPipelineCacheInfo(pipelineCache);

    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    std::vector<PipelineInfo> handle_info(createInfoCount);
    for (size_t i = 0; i < createInfoCount; ++i) { pPipelines->SetConsumerData(i, &handle_info[i]); }

    VkResult replay_result = OverrideCreateRayTracingPipelinesKHR(GetDeviceTable(in_device->handle)->CreateRayTracingPipelinesKHR, returnValue, in_device, in_deferredOperation, in_pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    CheckResult("vkCreateRayTracingPipelinesKHR", returnValue, replay_result);

    AddHandles<PipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), pPipelines->GetHandlePointer(), createInfoCount, std::move(handle_info), &VulkanObjectInfoTable::AddPipelineInfo);
}

void VulkanReplayConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectInfoTable::GetPipelineInfo);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR(in_device, in_pipeline, firstGroup, groupCount, dataSize, out_pData);
    CheckResult("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", returnValue, replay_result);
}

void VulkanReplayConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdTraceRaysIndirectKHR(in_commandBuffer, in_pRaygenShaderBindingTable, in_pMissShaderBindingTable, in_pHitShaderBindingTable, in_pCallableShaderBindingTable, indirectDeviceAddress);
}

void VulkanReplayConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceSize                                returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader)
{
    VkDevice in_device = MapHandle<DeviceInfo>(device, &VulkanObjectInfoTable::GetDeviceInfo);
    VkPipeline in_pipeline = MapHandle<PipelineInfo>(pipeline, &VulkanObjectInfoTable::GetPipelineInfo);

    GetDeviceTable(in_device)->GetRayTracingShaderGroupStackSizeKHR(in_device, in_pipeline, group, groupShader);
}

void VulkanReplayConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRayTracingPipelineStackSizeKHR(in_commandBuffer, pipelineStackSize);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksEXT(in_commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectEXT(in_commandBuffer, in_buffer, offset, drawCount, stride);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<CommandBufferInfo>(commandBuffer, &VulkanObjectInfoTable::GetCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<BufferInfo>(buffer, &VulkanObjectInfoTable::GetBufferInfo);
    VkBuffer in_countBuffer = MapHandle<BufferInfo>(countBuffer, &VulkanObjectInfoTable::GetBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectCountEXT(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
