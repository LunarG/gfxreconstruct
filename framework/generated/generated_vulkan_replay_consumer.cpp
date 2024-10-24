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

#include "generated/generated_vulkan_replay_consumer.h"

#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "decode/vulkan_handle_mapping_util.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
void InitializeOutputStructPNext(StructPointerDecoder<T> *decoder);

void VulkanReplayConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    if (!pInstance->IsNull()) { pInstance->SetHandleLength(1); }
    VulkanInstanceInfo handle_info;
    pInstance->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateInstance(returnValue, pCreateInfo, pAllocator, pInstance);
    CheckResult("vkCreateInstance", returnValue, replay_result, call_info);

    AddHandle<VulkanInstanceInfo>(format::kNullHandleId, pInstance->GetPointer(), pInstance->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkInstanceInfo);
}

void VulkanReplayConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetInstanceTable(in_instance)->DestroyInstance(in_instance, in_pAllocator);
    RemoveHandle(instance, &CommonObjectInfoTable::RemoveVkInstanceInfo);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    pPhysicalDeviceCount->IsNull() ? nullptr : pPhysicalDeviceCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanInstanceInfo>("vkEnumeratePhysicalDevices", returnValue, instance, kInstanceArrayEnumeratePhysicalDevices, pPhysicalDeviceCount, pPhysicalDevices, &CommonObjectInfoTable::GetVkInstanceInfo));
    if (!pPhysicalDevices->IsNull()) { pPhysicalDevices->SetHandleLength(*pPhysicalDeviceCount->GetOutputPointer()); }
    std::vector<VulkanPhysicalDeviceInfo> handle_info(*pPhysicalDeviceCount->GetOutputPointer());
    for (size_t i = 0; i < *pPhysicalDeviceCount->GetOutputPointer(); ++i) { pPhysicalDevices->SetConsumerData(i, &handle_info[i]); }

    VkResult replay_result = OverrideEnumeratePhysicalDevices(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDevices, returnValue, in_instance, pPhysicalDeviceCount, pPhysicalDevices);
    CheckResult("vkEnumeratePhysicalDevices", returnValue, replay_result, call_info);

    if (pPhysicalDevices->IsNull()) { SetOutputArrayCount<VulkanInstanceInfo>(instance, kInstanceArrayEnumeratePhysicalDevices, *pPhysicalDeviceCount->GetOutputPointer(), &CommonObjectInfoTable::GetVkInstanceInfo); }
    AddHandles<VulkanPhysicalDeviceInfo>(instance, pPhysicalDevices->GetPointer(), pPhysicalDevices->GetLength(), pPhysicalDevices->GetHandlePointer(), *pPhysicalDeviceCount->GetOutputPointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkPhysicalDeviceInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkPhysicalDeviceFeatures* out_pFeatures = pFeatures->IsNull() ? nullptr : pFeatures->AllocateOutputData(1);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
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
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkImageFormatProperties* out_pImageFormatProperties = pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties(in_physicalDevice, format, type, tiling, usage, flags, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1);

    OverrideGetPhysicalDeviceProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties, in_physicalDevice, pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pQueueFamilyPropertyCount = pQueueFamilyPropertyCount->IsNull() ? nullptr : pQueueFamilyPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties, pQueueFamilyPropertyCount, pQueueFamilyProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkQueueFamilyProperties* out_pQueueFamilyProperties = pQueueFamilyProperties->IsNull() ? nullptr : pQueueFamilyProperties->AllocateOutputData(*out_pQueueFamilyPropertyCount);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    if (pQueueFamilyProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties, *out_pQueueFamilyPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
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
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDevice->IsNull()) { pDevice->SetHandleLength(1); }
    VulkanDeviceInfo handle_info;
    pDevice->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDevice(returnValue, in_physicalDevice, pCreateInfo, pAllocator, pDevice);
    CheckResult("vkCreateDevice", returnValue, replay_result, call_info);

    AddHandle<VulkanDeviceInfo>(physicalDevice, pDevice->GetPointer(), pDevice->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDeviceInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    OverrideDestroyDevice(GetDeviceTable(in_device->handle)->DestroyDevice, in_device, pAllocator);
    RemoveHandle(device, &CommonObjectInfoTable::RemoveVkDeviceInfo);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    if (!pQueue->IsNull()) { pQueue->SetHandleLength(1); }
    VulkanQueueInfo handle_info;
    pQueue->SetConsumerData(0, &handle_info);

    OverrideGetDeviceQueue(GetDeviceTable(in_device->handle)->GetDeviceQueue, in_device, queueFamilyIndex, queueIndex, pQueue);

    AddHandle<VulkanQueueInfo>(device, pQueue->GetPointer(), pQueue->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkQueueInfo);
}

void VulkanReplayConsumer::Process_vkQueueSubmit(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetVkQueueInfo(queue);

    MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(fence);

    VkResult replay_result = OverrideQueueSubmit(GetDeviceTable(in_queue->handle)->QueueSubmit, call_info.index, returnValue, in_queue, submitCount, pSubmits, in_fence);
    CheckResult("vkQueueSubmit", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(queue, &CommonObjectInfoTable::GetVkQueueInfo);

    VkResult replay_result = GetDeviceTable(in_queue)->QueueWaitIdle(in_queue);
    CheckResult("vkQueueWaitIdle", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);

    VkResult replay_result = GetDeviceTable(in_device)->DeviceWaitIdle(in_device);
    CheckResult("vkDeviceWaitIdle", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pAllocateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pMemory->IsNull()) { pMemory->SetHandleLength(1); }
    VulkanDeviceMemoryInfo handle_info;
    pMemory->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideAllocateMemory(GetDeviceTable(in_device->handle)->AllocateMemory, returnValue, in_device, pAllocateInfo, pAllocator, pMemory);
    CheckResult("vkAllocateMemory", returnValue, replay_result, call_info);

    AddHandle<VulkanDeviceMemoryInfo>(device, pMemory->GetPointer(), pMemory->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDeviceMemoryInfo);
}

void VulkanReplayConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(memory);

    OverrideFreeMemory(GetDeviceTable(in_device->handle)->FreeMemory, in_device, in_memory, pAllocator);
    RemoveHandle(memory, &CommonObjectInfoTable::RemoveVkDeviceMemoryInfo);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(memory);
    void** out_ppData = ppData->IsNull() ? nullptr : ppData->AllocateOutputData(1);

    VkResult replay_result = OverrideMapMemory(GetDeviceTable(in_device->handle)->MapMemory, returnValue, in_device, in_memory, offset, size, flags, out_ppData);
    CheckResult("vkMapMemory", returnValue, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*ppData->GetPointer()), *ppData->GetOutputPointer(), format::ApiCallId::ApiCall_vkMapMemory, "vkMapMemory");
}

void VulkanReplayConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(memory);

    OverrideUnmapMemory(GetDeviceTable(in_device->handle)->UnmapMemory, in_device, in_memory);
}

void VulkanReplayConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructArrayHandles(pMemoryRanges->GetMetaStructPointer(), pMemoryRanges->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideFlushMappedMemoryRanges(GetDeviceTable(in_device->handle)->FlushMappedMemoryRanges, returnValue, in_device, memoryRangeCount, pMemoryRanges);
    CheckResult("vkFlushMappedMemoryRanges", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructArrayHandles(pMemoryRanges->GetMetaStructPointer(), pMemoryRanges->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideInvalidateMappedMemoryRanges(GetDeviceTable(in_device->handle)->InvalidateMappedMemoryRanges, returnValue, in_device, memoryRangeCount, pMemoryRanges);
    CheckResult("vkInvalidateMappedMemoryRanges", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeviceMemory in_memory = MapHandle<VulkanDeviceMemoryInfo>(memory, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_buffer = GetObjectInfoTable().GetVkBufferInfo(buffer);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(memory);

    VkResult replay_result = OverrideBindBufferMemory(GetDeviceTable(in_device->handle)->BindBufferMemory, returnValue, in_device, in_buffer, in_memory, memoryOffset);
    CheckResult("vkBindBufferMemory", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetVkImageInfo(image);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(memory);

    VkResult replay_result = OverrideBindImageMemory(GetDeviceTable(in_device->handle)->BindImageMemory, returnValue, in_device, in_image, in_memory, memoryOffset);
    CheckResult("vkBindImageMemory", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkMemoryRequirements* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetBufferMemoryRequirements(in_device, in_buffer, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(image, &CommonObjectInfoTable::GetVkImageInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(image, &CommonObjectInfoTable::GetVkImageInfo);
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanImageInfo>("vkGetImageSparseMemoryRequirements", VK_SUCCESS, image, kImageArrayGetImageSparseMemoryRequirements, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &CommonObjectInfoTable::GetVkImageInfo));
    VkSparseImageMemoryRequirements* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount);

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements(in_device, in_image, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<VulkanImageInfo>(image, kImageArrayGetImageSparseMemoryRequirements, *out_pSparseMemoryRequirementCount, &CommonObjectInfoTable::GetVkImageInfo); }
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
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkSparseImageFormatProperties* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(in_physicalDevice, format, type, samples, usage, tiling, out_pPropertyCount, out_pProperties);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetVkQueueInfo(queue);

    MapStructArrayHandles(pBindInfo->GetMetaStructPointer(), pBindInfo->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(fence);

    VkResult replay_result = OverrideQueueBindSparse(GetDeviceTable(in_queue->handle)->QueueBindSparse, returnValue, in_queue, bindInfoCount, pBindInfo, in_fence);
    CheckResult("vkQueueBindSparse", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkFenceCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pFence->IsNull()) { pFence->SetHandleLength(1); }
    VkFence* out_pFence = pFence->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateFence(in_device, in_pCreateInfo, in_pAllocator, out_pFence);
    CheckResult("vkCreateFence", returnValue, replay_result, call_info);

    AddHandle<VulkanFenceInfo>(device, pFence->GetPointer(), out_pFence, &CommonObjectInfoTable::AddVkFenceInfo);
}

void VulkanReplayConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkFence in_fence = MapHandle<VulkanFenceInfo>(fence, &CommonObjectInfoTable::GetVkFenceInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyFence(in_device, in_fence, in_pAllocator);
    RemoveHandle(fence, &CommonObjectInfoTable::RemoveVkFenceInfo);
}

void VulkanReplayConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkFence* in_pFences = MapHandles<VulkanFenceInfo>(pFences, fenceCount, &CommonObjectInfoTable::GetVkFenceInfo);

    VkResult replay_result = GetDeviceTable(in_device)->ResetFences(in_device, fenceCount, in_pFences);
    CheckResult("vkResetFences", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(fence);

    VkResult replay_result = OverrideGetFenceStatus(GetDeviceTable(in_device->handle)->GetFenceStatus, returnValue, in_device, in_fence);
    CheckResult("vkGetFenceStatus", returnValue, replay_result, call_info);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    MapHandles<VulkanFenceInfo>(pFences, fenceCount, &CommonObjectInfoTable::GetVkFenceInfo);

    VkResult replay_result = OverrideWaitForFences(GetDeviceTable(in_device->handle)->WaitForFences, returnValue, in_device, fenceCount, pFences, waitAll, timeout);
    CheckResult("vkWaitForFences", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSemaphore->IsNull()) { pSemaphore->SetHandleLength(1); }
    VkSemaphore* out_pSemaphore = pSemaphore->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSemaphore(in_device, in_pCreateInfo, in_pAllocator, out_pSemaphore);
    CheckResult("vkCreateSemaphore", returnValue, replay_result, call_info);

    AddHandle<VulkanSemaphoreInfo>(device, pSemaphore->GetPointer(), out_pSemaphore, &CommonObjectInfoTable::AddVkSemaphoreInfo);
}

void VulkanReplayConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSemaphore in_semaphore = MapHandle<VulkanSemaphoreInfo>(semaphore, &CommonObjectInfoTable::GetVkSemaphoreInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySemaphore(in_device, in_semaphore, in_pAllocator);
    RemoveHandle(semaphore, &CommonObjectInfoTable::RemoveVkSemaphoreInfo);
}

void VulkanReplayConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkEventCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pEvent->IsNull()) { pEvent->SetHandleLength(1); }
    VkEvent* out_pEvent = pEvent->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateEvent(in_device, in_pCreateInfo, in_pAllocator, out_pEvent);
    CheckResult("vkCreateEvent", returnValue, replay_result, call_info);

    AddHandle<VulkanEventInfo>(device, pEvent->GetPointer(), out_pEvent, &CommonObjectInfoTable::AddVkEventInfo);
}

void VulkanReplayConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkEvent in_event = MapHandle<VulkanEventInfo>(event, &CommonObjectInfoTable::GetVkEventInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyEvent(in_device, in_event, in_pAllocator);
    RemoveHandle(event, &CommonObjectInfoTable::RemoveVkEventInfo);
}

void VulkanReplayConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_event = GetObjectInfoTable().GetVkEventInfo(event);

    VkResult replay_result = OverrideGetEventStatus(GetDeviceTable(in_device->handle)->GetEventStatus, returnValue, in_device, in_event);
    CheckResult("vkGetEventStatus", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkEvent in_event = MapHandle<VulkanEventInfo>(event, &CommonObjectInfoTable::GetVkEventInfo);

    VkResult replay_result = GetDeviceTable(in_device)->SetEvent(in_device, in_event);
    CheckResult("vkSetEvent", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkEvent in_event = MapHandle<VulkanEventInfo>(event, &CommonObjectInfoTable::GetVkEventInfo);

    VkResult replay_result = GetDeviceTable(in_device)->ResetEvent(in_device, in_event);
    CheckResult("vkResetEvent", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkQueryPoolCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pQueryPool->IsNull()) { pQueryPool->SetHandleLength(1); }
    VkQueryPool* out_pQueryPool = pQueryPool->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateQueryPool(in_device, in_pCreateInfo, in_pAllocator, out_pQueryPool);
    CheckResult("vkCreateQueryPool", returnValue, replay_result, call_info);

    AddHandle<VulkanQueryPoolInfo>(device, pQueryPool->GetPointer(), out_pQueryPool, &CommonObjectInfoTable::AddVkQueryPoolInfo);
}

void VulkanReplayConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyQueryPool(in_device, in_queryPool, in_pAllocator);
    RemoveHandle(queryPool, &CommonObjectInfoTable::RemoveVkQueryPoolInfo);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(queryPool);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

    VkResult replay_result = OverrideGetQueryPoolResults(GetDeviceTable(in_device->handle)->GetQueryPoolResults, returnValue, in_device, in_queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    CheckResult("vkGetQueryPoolResults", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    if (!pBuffer->IsNull()) { pBuffer->SetHandleLength(1); }
    VulkanBufferInfo handle_info;
    pBuffer->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateBuffer(GetDeviceTable(in_device->handle)->CreateBuffer, returnValue, in_device, pCreateInfo, pAllocator, pBuffer);
    CheckResult("vkCreateBuffer", returnValue, replay_result, call_info);

    AddHandle<VulkanBufferInfo>(device, pBuffer->GetPointer(), pBuffer->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkBufferInfo);
}

void VulkanReplayConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_buffer = GetObjectInfoTable().GetVkBufferInfo(buffer);

    OverrideDestroyBuffer(GetDeviceTable(in_device->handle)->DestroyBuffer, in_device, in_buffer, pAllocator);
    RemoveHandle(buffer, &CommonObjectInfoTable::RemoveVkBufferInfo);
}

void VulkanReplayConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkBufferViewCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pView->IsNull()) { pView->SetHandleLength(1); }
    VkBufferView* out_pView = pView->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateBufferView(in_device, in_pCreateInfo, in_pAllocator, out_pView);
    CheckResult("vkCreateBufferView", returnValue, replay_result, call_info);

    AddHandle<VulkanBufferViewInfo>(device, pView->GetPointer(), out_pView, &CommonObjectInfoTable::AddVkBufferViewInfo);
}

void VulkanReplayConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkBufferView in_bufferView = MapHandle<VulkanBufferViewInfo>(bufferView, &CommonObjectInfoTable::GetVkBufferViewInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyBufferView(in_device, in_bufferView, in_pAllocator);
    RemoveHandle(bufferView, &CommonObjectInfoTable::RemoveVkBufferViewInfo);
}

void VulkanReplayConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pImage->IsNull()) { pImage->SetHandleLength(1); }
    VulkanImageInfo handle_info;
    pImage->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateImage(GetDeviceTable(in_device->handle)->CreateImage, returnValue, in_device, pCreateInfo, pAllocator, pImage);
    CheckResult("vkCreateImage", returnValue, replay_result, call_info);

    AddHandle<VulkanImageInfo>(device, pImage->GetPointer(), pImage->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkImageInfo);
}

void VulkanReplayConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetVkImageInfo(image);

    OverrideDestroyImage(GetDeviceTable(in_device->handle)->DestroyImage, in_device, in_image, pAllocator);
    RemoveHandle(image, &CommonObjectInfoTable::RemoveVkImageInfo);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_image = GetObjectInfoTable().GetVkImageInfo(image);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pView->IsNull()) { pView->SetHandleLength(1); }
    VulkanImageViewInfo handle_info;
    pView->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateImageView(GetDeviceTable(in_device->handle)->CreateImageView, returnValue, in_device, pCreateInfo, pAllocator, pView);
    CheckResult("vkCreateImageView", returnValue, replay_result, call_info);

    AddHandle<VulkanImageViewInfo>(device, pView->GetPointer(), pView->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkImageViewInfo);
}

void VulkanReplayConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImageView in_imageView = MapHandle<VulkanImageViewInfo>(imageView, &CommonObjectInfoTable::GetVkImageViewInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyImageView(in_device, in_imageView, in_pAllocator);
    RemoveHandle(imageView, &CommonObjectInfoTable::RemoveVkImageViewInfo);
}

void VulkanReplayConsumer::Process_vkCreateShaderModule(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderModule>*       pShaderModule)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pShaderModule->IsNull()) { pShaderModule->SetHandleLength(1); }
    VulkanShaderModuleInfo handle_info;
    pShaderModule->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateShaderModule(GetDeviceTable(in_device->handle)->CreateShaderModule, returnValue, in_device, pCreateInfo, pAllocator, pShaderModule);
    CheckResult("vkCreateShaderModule", returnValue, replay_result, call_info);

    AddHandle<VulkanShaderModuleInfo>(device, pShaderModule->GetPointer(), pShaderModule->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkShaderModuleInfo);
}

void VulkanReplayConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_shaderModule = GetObjectInfoTable().GetVkShaderModuleInfo(shaderModule);

    OverrideDestroyShaderModule(GetDeviceTable(in_device->handle)->DestroyShaderModule, in_device, in_shaderModule, pAllocator);
    RemoveHandle(shaderModule, &CommonObjectInfoTable::RemoveVkShaderModuleInfo);
}

void VulkanReplayConsumer::Process_vkCreatePipelineCache(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineCache>*      pPipelineCache)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    if (!pPipelineCache->IsNull()) { pPipelineCache->SetHandleLength(1); }
    VulkanPipelineCacheInfo handle_info;
    pPipelineCache->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreatePipelineCache(GetDeviceTable(in_device->handle)->CreatePipelineCache, returnValue, in_device, pCreateInfo, pAllocator, pPipelineCache);
    CheckResult("vkCreatePipelineCache", returnValue, replay_result, call_info);

    AddHandle<VulkanPipelineCacheInfo>(device, pPipelineCache->GetPointer(), pPipelineCache->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineCacheInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipelineCache in_pipelineCache = MapHandle<VulkanPipelineCacheInfo>(pipelineCache, &CommonObjectInfoTable::GetVkPipelineCacheInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPipelineCache(in_device, in_pipelineCache, in_pAllocator);
    RemoveHandle(pipelineCache, &CommonObjectInfoTable::RemoveVkPipelineCacheInfo);
}

void VulkanReplayConsumer::Process_vkGetPipelineCacheData(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_pipelineCache = GetObjectInfoTable().GetVkPipelineCacheInfo(pipelineCache);
    pDataSize->IsNull() ? nullptr : pDataSize->AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanPipelineCacheInfo>("vkGetPipelineCacheData", returnValue, pipelineCache, kPipelineCacheArrayGetPipelineCacheData, pDataSize, pData, &CommonObjectInfoTable::GetVkPipelineCacheInfo));
    if (!pData->IsNull()) { pData->AllocateOutputData(*pDataSize->GetOutputPointer()); }

    VkResult replay_result = OverrideGetPipelineCacheData(GetDeviceTable(in_device->handle)->GetPipelineCacheData, returnValue, in_device, in_pipelineCache, pDataSize, pData);
    CheckResult("vkGetPipelineCacheData", returnValue, replay_result, call_info);

    if (pData->IsNull()) { SetOutputArrayCount<VulkanPipelineCacheInfo>(pipelineCache, kPipelineCacheArrayGetPipelineCacheData, *pDataSize->GetOutputPointer(), &CommonObjectInfoTable::GetVkPipelineCacheInfo); }
}

void VulkanReplayConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipelineCache in_dstCache = MapHandle<VulkanPipelineCacheInfo>(dstCache, &CommonObjectInfoTable::GetVkPipelineCacheInfo);
    const VkPipelineCache* in_pSrcCaches = MapHandles<VulkanPipelineCacheInfo>(pSrcCaches, srcCacheCount, &CommonObjectInfoTable::GetVkPipelineCacheInfo);

    VkResult replay_result = GetDeviceTable(in_device)->MergePipelineCaches(in_device, in_dstCache, srcCacheCount, in_pSrcCaches);
    CheckResult("vkMergePipelineCaches", returnValue, replay_result, call_info);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_pipelineCache = GetObjectInfoTable().GetVkPipelineCacheInfo(pipelineCache);

    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    if (omitted_pipeline_cache_data_) {AllowCompileDuringPipelineCreation(createInfoCount, pCreateInfos->GetPointer());}
    std::vector<VulkanPipelineInfo> handle_info(createInfoCount);
    for (size_t i = 0; i < createInfoCount; ++i) { pPipelines->SetConsumerData(i, &handle_info[i]); }

    if (UseAsyncOperations())
    {
        auto task = AsyncCreateGraphicsPipelines(call_info, returnValue, in_device, in_pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        if(task)
        {
           AddHandlesAsync<VulkanPipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), std::move(handle_info), &VulkanObjectInfoTable::AddVkPipelineInfo, std::move(task));
           return;
        }
    }
    VkResult replay_result = OverrideCreateGraphicsPipelines(GetDeviceTable(in_device->handle)->CreateGraphicsPipelines, returnValue, in_device, in_pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    CheckResult("vkCreateGraphicsPipelines", returnValue, replay_result, call_info);

    AddHandles<VulkanPipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), pPipelines->GetHandlePointer(), createInfoCount, std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineInfo);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_pipelineCache = GetObjectInfoTable().GetVkPipelineCacheInfo(pipelineCache);

    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    if (omitted_pipeline_cache_data_) {AllowCompileDuringPipelineCreation(createInfoCount, pCreateInfos->GetPointer());}
    std::vector<VulkanPipelineInfo> handle_info(createInfoCount);
    for (size_t i = 0; i < createInfoCount; ++i) { pPipelines->SetConsumerData(i, &handle_info[i]); }

    if (UseAsyncOperations())
    {
        auto task = AsyncCreateComputePipelines(call_info, returnValue, in_device, in_pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        if(task)
        {
           AddHandlesAsync<VulkanPipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), std::move(handle_info), &VulkanObjectInfoTable::AddVkPipelineInfo, std::move(task));
           return;
        }
    }
    VkResult replay_result = OverrideCreateComputePipelines(GetDeviceTable(in_device->handle)->CreateComputePipelines, returnValue, in_device, in_pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    CheckResult("vkCreateComputePipelines", returnValue, replay_result, call_info);

    AddHandles<VulkanPipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), pPipelines->GetHandlePointer(), createInfoCount, std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_pipeline = GetObjectInfoTable().GetVkPipelineInfo(pipeline);

    OverrideDestroyPipeline(GetDeviceTable(in_device->handle)->DestroyPipeline, in_device, in_pipeline, pAllocator);
    RemoveHandle(pipeline, &CommonObjectInfoTable::RemoveVkPipelineInfo);
}

void VulkanReplayConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineLayoutCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pPipelineLayout->IsNull()) { pPipelineLayout->SetHandleLength(1); }
    VkPipelineLayout* out_pPipelineLayout = pPipelineLayout->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreatePipelineLayout(in_device, in_pCreateInfo, in_pAllocator, out_pPipelineLayout);
    CheckResult("vkCreatePipelineLayout", returnValue, replay_result, call_info);

    AddHandle<VulkanPipelineLayoutInfo>(device, pPipelineLayout->GetPointer(), out_pPipelineLayout, &CommonObjectInfoTable::AddVkPipelineLayoutInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipelineLayout in_pipelineLayout = MapHandle<VulkanPipelineLayoutInfo>(pipelineLayout, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPipelineLayout(in_device, in_pipelineLayout, in_pAllocator);
    RemoveHandle(pipelineLayout, &CommonObjectInfoTable::RemoveVkPipelineLayoutInfo);
}

void VulkanReplayConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSamplerCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSampler->IsNull()) { pSampler->SetHandleLength(1); }
    VkSampler* out_pSampler = pSampler->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSampler(in_device, in_pCreateInfo, in_pAllocator, out_pSampler);
    CheckResult("vkCreateSampler", returnValue, replay_result, call_info);

    AddHandle<VulkanSamplerInfo>(device, pSampler->GetPointer(), out_pSampler, &CommonObjectInfoTable::AddVkSamplerInfo);
}

void VulkanReplayConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSampler in_sampler = MapHandle<VulkanSamplerInfo>(sampler, &CommonObjectInfoTable::GetVkSamplerInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySampler(in_device, in_sampler, in_pAllocator);
    RemoveHandle(sampler, &CommonObjectInfoTable::RemoveVkSamplerInfo);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pSetLayout->IsNull()) { pSetLayout->SetHandleLength(1); }
    VulkanDescriptorSetLayoutInfo handle_info;
    pSetLayout->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDescriptorSetLayout(GetDeviceTable(in_device->handle)->CreateDescriptorSetLayout, returnValue, in_device, pCreateInfo, pAllocator, pSetLayout);
    CheckResult("vkCreateDescriptorSetLayout", returnValue, replay_result, call_info);

    AddHandle<VulkanDescriptorSetLayoutInfo>(device, pSetLayout->GetPointer(), pSetLayout->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDescriptorSetLayoutInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDescriptorSetLayout in_descriptorSetLayout = MapHandle<VulkanDescriptorSetLayoutInfo>(descriptorSetLayout, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyDescriptorSetLayout(in_device, in_descriptorSetLayout, in_pAllocator);
    RemoveHandle(descriptorSetLayout, &CommonObjectInfoTable::RemoveVkDescriptorSetLayoutInfo);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    if (!pDescriptorPool->IsNull()) { pDescriptorPool->SetHandleLength(1); }
    VulkanDescriptorPoolInfo handle_info;
    pDescriptorPool->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDescriptorPool(GetDeviceTable(in_device->handle)->CreateDescriptorPool, returnValue, in_device, pCreateInfo, pAllocator, pDescriptorPool);
    CheckResult("vkCreateDescriptorPool", returnValue, replay_result, call_info);

    AddHandle<VulkanDescriptorPoolInfo>(device, pDescriptorPool->GetPointer(), pDescriptorPool->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDescriptorPoolInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_descriptorPool = GetObjectInfoTable().GetVkDescriptorPoolInfo(descriptorPool);

    OverrideDestroyDescriptorPool(GetDeviceTable(in_device->handle)->DestroyDescriptorPool, in_device, in_descriptorPool, pAllocator);
    RemovePoolHandle<VulkanDescriptorPoolInfo>(descriptorPool, &CommonObjectInfoTable::GetVkDescriptorPoolInfo, &CommonObjectInfoTable::RemoveVkDescriptorPoolInfo, &CommonObjectInfoTable::RemoveVkDescriptorSetInfo);
}

void VulkanReplayConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_descriptorPool = GetObjectInfoTable().GetVkDescriptorPoolInfo(descriptorPool);

    VkResult replay_result = OverrideResetDescriptorPool(GetDeviceTable(in_device->handle)->ResetDescriptorPool, returnValue, in_device, in_descriptorPool, flags);
    CheckResult("vkResetDescriptorPool", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pAllocateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDescriptorSets->IsNull()) { pDescriptorSets->SetHandleLength(pAllocateInfo->GetPointer()->descriptorSetCount); }
    std::vector<VulkanDescriptorSetInfo> handle_info(pAllocateInfo->GetPointer()->descriptorSetCount);
    for (size_t i = 0; i < pAllocateInfo->GetPointer()->descriptorSetCount; ++i) { pDescriptorSets->SetConsumerData(i, &handle_info[i]); }

    VkResult replay_result = OverrideAllocateDescriptorSets(GetDeviceTable(in_device->handle)->AllocateDescriptorSets, returnValue, in_device, pAllocateInfo, pDescriptorSets);
    CheckResult("vkAllocateDescriptorSets", returnValue, replay_result, call_info);

    AddPoolHandles<VulkanDescriptorPoolInfo, VulkanDescriptorSetInfo>(device, handle_mapping::GetPoolId(pAllocateInfo->GetMetaStructPointer()), pDescriptorSets->GetPointer(), pDescriptorSets->GetLength(), pDescriptorSets->GetHandlePointer(), pAllocateInfo->GetPointer()->descriptorSetCount, std::move(handle_info), &CommonObjectInfoTable::GetVkDescriptorPoolInfo, &CommonObjectInfoTable::AddVkDescriptorSetInfo);
}

void VulkanReplayConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDescriptorPool in_descriptorPool = MapHandle<VulkanDescriptorPoolInfo>(descriptorPool, &CommonObjectInfoTable::GetVkDescriptorPoolInfo);
    const VkDescriptorSet* in_pDescriptorSets = MapHandles<VulkanDescriptorSetInfo>(pDescriptorSets, descriptorSetCount, &CommonObjectInfoTable::GetVkDescriptorSetInfo);

    VkResult replay_result = GetDeviceTable(in_device)->FreeDescriptorSets(in_device, in_descriptorPool, descriptorSetCount, in_pDescriptorSets);
    CheckResult("vkFreeDescriptorSets", returnValue, replay_result, call_info);
    RemovePoolHandles<VulkanDescriptorPoolInfo, VulkanDescriptorSetInfo>(descriptorPool, pDescriptorSets, descriptorSetCount, &CommonObjectInfoTable::GetVkDescriptorPoolInfo, &CommonObjectInfoTable::RemoveVkDescriptorSetInfo);
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructArrayHandles(pDescriptorWrites->GetMetaStructPointer(), pDescriptorWrites->GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(pDescriptorCopies->GetMetaStructPointer(), pDescriptorCopies->GetLength(), GetObjectInfoTable());

    OverrideUpdateDescriptorSets(GetDeviceTable(in_device->handle)->UpdateDescriptorSets, in_device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

void VulkanReplayConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pFramebuffer->IsNull()) { pFramebuffer->SetHandleLength(1); }
    VulkanFramebufferInfo handle_info;
    pFramebuffer->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateFramebuffer(GetDeviceTable(in_device->handle)->CreateFramebuffer, returnValue, in_device, pCreateInfo, pAllocator, pFramebuffer);
    CheckResult("vkCreateFramebuffer", returnValue, replay_result, call_info);

    AddHandle<VulkanFramebufferInfo>(device, pFramebuffer->GetPointer(), pFramebuffer->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkFramebufferInfo);
}

void VulkanReplayConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkFramebuffer in_framebuffer = MapHandle<VulkanFramebufferInfo>(framebuffer, &CommonObjectInfoTable::GetVkFramebufferInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyFramebuffer(in_device, in_framebuffer, in_pAllocator);
    RemoveHandle(framebuffer, &CommonObjectInfoTable::RemoveVkFramebufferInfo);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    if (!pRenderPass->IsNull()) { pRenderPass->SetHandleLength(1); }
    VulkanRenderPassInfo handle_info;
    pRenderPass->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateRenderPass(GetDeviceTable(in_device->handle)->CreateRenderPass, returnValue, in_device, pCreateInfo, pAllocator, pRenderPass);
    CheckResult("vkCreateRenderPass", returnValue, replay_result, call_info);

    AddHandle<VulkanRenderPassInfo>(device, pRenderPass->GetPointer(), pRenderPass->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_renderPass = GetObjectInfoTable().GetVkRenderPassInfo(renderPass);

    OverrideDestroyRenderPass(GetDeviceTable(in_device->handle)->DestroyRenderPass, in_device, in_renderPass, pAllocator);
    RemoveHandle(renderPass, &CommonObjectInfoTable::RemoveVkRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkRenderPass in_renderPass = MapHandle<VulkanRenderPassInfo>(renderPass, &CommonObjectInfoTable::GetVkRenderPassInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCommandPoolCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pCommandPool->IsNull()) { pCommandPool->SetHandleLength(1); }
    VkCommandPool* out_pCommandPool = pCommandPool->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateCommandPool(in_device, in_pCreateInfo, in_pAllocator, out_pCommandPool);
    CheckResult("vkCreateCommandPool", returnValue, replay_result, call_info);

    AddHandle<VulkanCommandPoolInfo>(device, pCommandPool->GetPointer(), out_pCommandPool, &CommonObjectInfoTable::AddVkCommandPoolInfo);
}

void VulkanReplayConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_commandPool = GetObjectInfoTable().GetVkCommandPoolInfo(commandPool);

    OverrideDestroyCommandPool(GetDeviceTable(in_device->handle)->DestroyCommandPool, in_device, in_commandPool, pAllocator);
    RemovePoolHandle<VulkanCommandPoolInfo>(commandPool, &CommonObjectInfoTable::GetVkCommandPoolInfo, &CommonObjectInfoTable::RemoveVkCommandPoolInfo, &CommonObjectInfoTable::RemoveVkCommandBufferInfo);
}

void VulkanReplayConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_commandPool = GetObjectInfoTable().GetVkCommandPoolInfo(commandPool);

    VkResult replay_result = OverrideResetCommandPool(GetDeviceTable(in_device->handle)->ResetCommandPool, returnValue, in_device, in_commandPool, flags);
    CheckResult("vkResetCommandPool", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pAllocateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pCommandBuffers->IsNull()) { pCommandBuffers->SetHandleLength(pAllocateInfo->GetPointer()->commandBufferCount); }
    std::vector<VulkanCommandBufferInfo> handle_info(pAllocateInfo->GetPointer()->commandBufferCount);
    for (size_t i = 0; i < pAllocateInfo->GetPointer()->commandBufferCount; ++i) { pCommandBuffers->SetConsumerData(i, &handle_info[i]); }

    VkResult replay_result = OverrideAllocateCommandBuffers(GetDeviceTable(in_device->handle)->AllocateCommandBuffers, returnValue, in_device, pAllocateInfo, pCommandBuffers);
    CheckResult("vkAllocateCommandBuffers", returnValue, replay_result, call_info);

    AddPoolHandles<VulkanCommandPoolInfo, VulkanCommandBufferInfo>(device, handle_mapping::GetPoolId(pAllocateInfo->GetMetaStructPointer()), pCommandBuffers->GetPointer(), pCommandBuffers->GetLength(), pCommandBuffers->GetHandlePointer(), pAllocateInfo->GetPointer()->commandBufferCount, std::move(handle_info), &CommonObjectInfoTable::GetVkCommandPoolInfo, &CommonObjectInfoTable::AddVkCommandBufferInfo);
}

void VulkanReplayConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_commandPool = GetObjectInfoTable().GetVkCommandPoolInfo(commandPool);
    MapHandles<VulkanCommandBufferInfo>(pCommandBuffers, commandBufferCount, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    OverrideFreeCommandBuffers(GetDeviceTable(in_device->handle)->FreeCommandBuffers, in_device, in_commandPool, commandBufferCount, pCommandBuffers);
    RemovePoolHandles<VulkanCommandPoolInfo, VulkanCommandBufferInfo>(commandPool, pCommandBuffers, commandBufferCount, &CommonObjectInfoTable::GetVkCommandPoolInfo, &CommonObjectInfoTable::RemoveVkCommandBufferInfo);
}

void VulkanReplayConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    MapStructHandles(pBeginInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideBeginCommandBuffer(GetDeviceTable(in_commandBuffer->handle)->BeginCommandBuffer, call_info.index, returnValue, in_commandBuffer, pBeginInfo);
    CheckResult("vkBeginCommandBuffer", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->EndCommandBuffer(in_commandBuffer);
    CheckResult("vkEndCommandBuffer", returnValue, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkEndCommandBuffer(call_info, GetDeviceTable(in_commandBuffer)->EndCommandBuffer, returnValue, in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    VkResult replay_result = OverrideResetCommandBuffer(GetDeviceTable(in_commandBuffer->handle)->ResetCommandBuffer, returnValue, in_commandBuffer, flags);
    CheckResult("vkResetCommandBuffer", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindPipeline(in_commandBuffer, pipelineBindPoint, in_pipeline);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindPipeline(call_info, GetDeviceTable(in_commandBuffer)->CmdBindPipeline, in_commandBuffer, pipelineBindPoint, GetObjectInfoTable().GetVkPipelineInfo(pipeline));
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkViewport* in_pViewports = pViewports->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewport(in_commandBuffer, firstViewport, viewportCount, in_pViewports);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetViewport(call_info, GetDeviceTable(in_commandBuffer)->CmdSetViewport, in_commandBuffer, firstViewport, viewportCount, in_pViewports);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRect2D* in_pScissors = pScissors->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetScissor(in_commandBuffer, firstScissor, scissorCount, in_pScissors);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetScissor(call_info, GetDeviceTable(in_commandBuffer)->CmdSetScissor, in_commandBuffer, firstScissor, scissorCount, in_pScissors);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineWidth(in_commandBuffer, lineWidth);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetLineWidth(call_info, GetDeviceTable(in_commandBuffer)->CmdSetLineWidth, in_commandBuffer, lineWidth);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBias(in_commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthBias(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthBias, in_commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const float* in_blendConstants = blendConstants->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetBlendConstants(in_commandBuffer, in_blendConstants);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetBlendConstants(call_info, GetDeviceTable(in_commandBuffer)->CmdSetBlendConstants, in_commandBuffer, in_blendConstants);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBounds(in_commandBuffer, minDepthBounds, maxDepthBounds);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthBounds(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthBounds, in_commandBuffer, minDepthBounds, maxDepthBounds);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilCompareMask(in_commandBuffer, faceMask, compareMask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetStencilCompareMask(call_info, GetDeviceTable(in_commandBuffer)->CmdSetStencilCompareMask, in_commandBuffer, faceMask, compareMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilWriteMask(in_commandBuffer, faceMask, writeMask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetStencilWriteMask(call_info, GetDeviceTable(in_commandBuffer)->CmdSetStencilWriteMask, in_commandBuffer, faceMask, writeMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilReference(in_commandBuffer, faceMask, reference);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetStencilReference(call_info, GetDeviceTable(in_commandBuffer)->CmdSetStencilReference, in_commandBuffer, faceMask, reference);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipelineLayout in_layout = MapHandle<VulkanPipelineLayoutInfo>(layout, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);
    const VkDescriptorSet* in_pDescriptorSets = MapHandles<VulkanDescriptorSetInfo>(pDescriptorSets, descriptorSetCount, &CommonObjectInfoTable::GetVkDescriptorSetInfo);
    const uint32_t* in_pDynamicOffsets = pDynamicOffsets->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindDescriptorSets(in_commandBuffer, pipelineBindPoint, in_layout, firstSet, descriptorSetCount, in_pDescriptorSets, dynamicOffsetCount, in_pDynamicOffsets);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindDescriptorSets(call_info, GetDeviceTable(in_commandBuffer)->CmdBindDescriptorSets, in_commandBuffer, pipelineBindPoint, GetObjectInfoTable().GetVkPipelineLayoutInfo(layout), firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, in_pDynamicOffsets);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindIndexBuffer(in_commandBuffer, in_buffer, offset, indexType);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindIndexBuffer(call_info, GetDeviceTable(in_commandBuffer)->CmdBindIndexBuffer, in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(buffer), offset, indexType);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<VulkanBufferInfo>(pBuffers, bindingCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pOffsets = pOffsets->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindVertexBuffers(call_info, GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers, in_commandBuffer, firstBinding, bindingCount, pBuffers, in_pOffsets);
    }
}

void VulkanReplayConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDraw(in_commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDraw(call_info, GetDeviceTable(in_commandBuffer)->CmdDraw, in_commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexed(in_commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawIndexed(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawIndexed, in_commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirect(in_commandBuffer, in_buffer, offset, drawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawIndirect(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawIndirect, in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(buffer), offset, drawCount, stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirect(in_commandBuffer, in_buffer, offset, drawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawIndexedIndirect(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirect, in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(buffer), offset, drawCount, stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDispatch(in_commandBuffer, groupCountX, groupCountY, groupCountZ);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDispatch(call_info, GetDeviceTable(in_commandBuffer)->CmdDispatch, in_commandBuffer, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanReplayConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDispatchIndirect(in_commandBuffer, in_buffer, offset);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDispatchIndirect(call_info, GetDeviceTable(in_commandBuffer)->CmdDispatchIndirect, in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(buffer), offset);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_srcBuffer = MapHandle<VulkanBufferInfo>(srcBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkBufferCopy* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyBuffer(in_commandBuffer, in_srcBuffer, in_dstBuffer, regionCount, in_pRegions);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyBuffer(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyBuffer, in_commandBuffer, in_srcBuffer, in_dstBuffer, regionCount, in_pRegions);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_srcImage = MapHandle<VulkanImageInfo>(srcImage, &CommonObjectInfoTable::GetVkImageInfo);
    VkImage in_dstImage = MapHandle<VulkanImageInfo>(dstImage, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageCopy* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyImage(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyImage, in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_srcImage = MapHandle<VulkanImageInfo>(srcImage, &CommonObjectInfoTable::GetVkImageInfo);
    VkImage in_dstImage = MapHandle<VulkanImageInfo>(dstImage, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageBlit* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBlitImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions, filter);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBlitImage(call_info, GetDeviceTable(in_commandBuffer)->CmdBlitImage, in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions, filter);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_srcBuffer = MapHandle<VulkanBufferInfo>(srcBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkImage in_dstImage = MapHandle<VulkanImageInfo>(dstImage, &CommonObjectInfoTable::GetVkImageInfo);
    const VkBufferImageCopy* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage(in_commandBuffer, in_srcBuffer, in_dstImage, dstImageLayout, regionCount, in_pRegions);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyBufferToImage(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage, in_commandBuffer, in_srcBuffer, in_dstImage, dstImageLayout, regionCount, in_pRegions);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_srcImage = MapHandle<VulkanImageInfo>(srcImage, &CommonObjectInfoTable::GetVkImageInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkBufferImageCopy* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer(in_commandBuffer, in_srcImage, srcImageLayout, in_dstBuffer, regionCount, in_pRegions);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyImageToBuffer(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer, in_commandBuffer, in_srcImage, srcImageLayout, in_dstBuffer, regionCount, in_pRegions);
    }
}

void VulkanReplayConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    const void* in_pData = pData->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdUpdateBuffer(in_commandBuffer, in_dstBuffer, dstOffset, dataSize, in_pData);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdUpdateBuffer(call_info, GetDeviceTable(in_commandBuffer)->CmdUpdateBuffer, in_commandBuffer, in_dstBuffer, dstOffset, dataSize, in_pData);
    }
}

void VulkanReplayConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdFillBuffer(in_commandBuffer, in_dstBuffer, dstOffset, size, data);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdFillBuffer(call_info, GetDeviceTable(in_commandBuffer)->CmdFillBuffer, in_commandBuffer, in_dstBuffer, dstOffset, size, data);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(image, &CommonObjectInfoTable::GetVkImageInfo);
    const VkClearColorValue* in_pColor = pColor->GetPointer();
    const VkImageSubresourceRange* in_pRanges = pRanges->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearColorImage(in_commandBuffer, in_image, imageLayout, in_pColor, rangeCount, in_pRanges);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdClearColorImage(call_info, GetDeviceTable(in_commandBuffer)->CmdClearColorImage, in_commandBuffer, in_image, imageLayout, in_pColor, rangeCount, in_pRanges);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(image, &CommonObjectInfoTable::GetVkImageInfo);
    const VkClearDepthStencilValue* in_pDepthStencil = pDepthStencil->GetPointer();
    const VkImageSubresourceRange* in_pRanges = pRanges->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearDepthStencilImage(in_commandBuffer, in_image, imageLayout, in_pDepthStencil, rangeCount, in_pRanges);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdClearDepthStencilImage(call_info, GetDeviceTable(in_commandBuffer)->CmdClearDepthStencilImage, in_commandBuffer, in_image, imageLayout, in_pDepthStencil, rangeCount, in_pRanges);
    }
}

void VulkanReplayConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkClearAttachment* in_pAttachments = pAttachments->GetPointer();
    const VkClearRect* in_pRects = pRects->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearAttachments(in_commandBuffer, attachmentCount, in_pAttachments, rectCount, in_pRects);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdClearAttachments(call_info, GetDeviceTable(in_commandBuffer)->CmdClearAttachments, in_commandBuffer, attachmentCount, in_pAttachments, rectCount, in_pRects);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_srcImage = MapHandle<VulkanImageInfo>(srcImage, &CommonObjectInfoTable::GetVkImageInfo);
    VkImage in_dstImage = MapHandle<VulkanImageInfo>(dstImage, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageResolve* in_pRegions = pRegions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdResolveImage(in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdResolveImage(call_info, GetDeviceTable(in_commandBuffer)->CmdResolveImage, in_commandBuffer, in_srcImage, srcImageLayout, in_dstImage, dstImageLayout, regionCount, in_pRegions);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkEvent in_event = MapHandle<VulkanEventInfo>(event, &CommonObjectInfoTable::GetVkEventInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetEvent(in_commandBuffer, in_event, stageMask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetEvent(call_info, GetDeviceTable(in_commandBuffer)->CmdSetEvent, in_commandBuffer, in_event, stageMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkEvent in_event = MapHandle<VulkanEventInfo>(event, &CommonObjectInfoTable::GetVkEventInfo);

    GetDeviceTable(in_commandBuffer)->CmdResetEvent(in_commandBuffer, in_event, stageMask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdResetEvent(call_info, GetDeviceTable(in_commandBuffer)->CmdResetEvent, in_commandBuffer, in_event, stageMask);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkEvent* in_pEvents = MapHandles<VulkanEventInfo>(pEvents, eventCount, &CommonObjectInfoTable::GetVkEventInfo);
    const VkMemoryBarrier* in_pMemoryBarriers = pMemoryBarriers->GetPointer();
    const VkBufferMemoryBarrier* in_pBufferMemoryBarriers = pBufferMemoryBarriers->GetPointer();
    MapStructArrayHandles(pBufferMemoryBarriers->GetMetaStructPointer(), pBufferMemoryBarriers->GetLength(), GetObjectInfoTable());
    const VkImageMemoryBarrier* in_pImageMemoryBarriers = pImageMemoryBarriers->GetPointer();
    MapStructArrayHandles(pImageMemoryBarriers->GetMetaStructPointer(), pImageMemoryBarriers->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdWaitEvents(in_commandBuffer, eventCount, in_pEvents, srcStageMask, dstStageMask, memoryBarrierCount, in_pMemoryBarriers, bufferMemoryBarrierCount, in_pBufferMemoryBarriers, imageMemoryBarrierCount, in_pImageMemoryBarriers);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWaitEvents(call_info, GetDeviceTable(in_commandBuffer)->CmdWaitEvents, in_commandBuffer, eventCount, in_pEvents, srcStageMask, dstStageMask, memoryBarrierCount, in_pMemoryBarriers, bufferMemoryBarrierCount, in_pBufferMemoryBarriers, imageMemoryBarrierCount, in_pImageMemoryBarriers);
    }
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
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    MapStructArrayHandles(pBufferMemoryBarriers->GetMetaStructPointer(), pBufferMemoryBarriers->GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(pImageMemoryBarriers->GetMetaStructPointer(), pImageMemoryBarriers->GetLength(), GetObjectInfoTable());

    OverrideCmdPipelineBarrier(GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier, in_commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPipelineBarrier(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier, in_commandBuffer->handle, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers->GetPointer(), bufferMemoryBarrierCount, pBufferMemoryBarriers->GetPointer(), imageMemoryBarrierCount, pImageMemoryBarriers->GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdBeginQuery(in_commandBuffer, in_queryPool, query, flags);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginQuery(call_info, GetDeviceTable(in_commandBuffer)->CmdBeginQuery, in_commandBuffer, in_queryPool, query, flags);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndQuery(in_commandBuffer, in_queryPool, query);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndQuery(call_info, GetDeviceTable(in_commandBuffer)->CmdEndQuery, in_commandBuffer, in_queryPool, query);
    }
}

void VulkanReplayConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdResetQueryPool(in_commandBuffer, in_queryPool, firstQuery, queryCount);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdResetQueryPool(call_info, GetDeviceTable(in_commandBuffer)->CmdResetQueryPool, in_commandBuffer, in_queryPool, firstQuery, queryCount);
    }
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteTimestamp(in_commandBuffer, pipelineStage, in_queryPool, query);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWriteTimestamp(call_info, GetDeviceTable(in_commandBuffer)->CmdWriteTimestamp, in_commandBuffer, pipelineStage, in_queryPool, query);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdCopyQueryPoolResults(in_commandBuffer, in_queryPool, firstQuery, queryCount, in_dstBuffer, dstOffset, stride, flags);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyQueryPoolResults(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyQueryPoolResults, in_commandBuffer, in_queryPool, firstQuery, queryCount, in_dstBuffer, dstOffset, stride, flags);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipelineLayout in_layout = MapHandle<VulkanPipelineLayoutInfo>(layout, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);
    const void* in_pValues = pValues->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdPushConstants(in_commandBuffer, in_layout, stageFlags, offset, size, in_pValues);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPushConstants(call_info, GetDeviceTable(in_commandBuffer)->CmdPushConstants, in_commandBuffer, in_layout, stageFlags, offset, size, in_pValues);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdBeginRenderPass(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass, in_commandBuffer, pRenderPassBegin, contents);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginRenderPass(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass, in_commandBuffer->handle, pRenderPassBegin, contents);
    }
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass(in_commandBuffer, contents);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdNextSubpass(call_info, GetDeviceTable(in_commandBuffer)->CmdNextSubpass, in_commandBuffer, contents);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndRenderPass(in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndRenderPass(call_info, GetDeviceTable(in_commandBuffer)->CmdEndRenderPass, in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCommandBuffer* in_pCommandBuffers = MapHandles<VulkanCommandBufferInfo>(pCommandBuffers, commandBufferCount, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdExecuteCommands(in_commandBuffer, commandBufferCount, in_pCommandBuffers);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdExecuteCommands(call_info, GetDeviceTable(in_commandBuffer)->CmdExecuteCommands, in_commandBuffer, commandBufferCount, in_pCommandBuffers);
    }
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindBufferMemory2(GetDeviceTable(in_device->handle)->BindBufferMemory2, returnValue, in_device, bindInfoCount, pBindInfos);
    CheckResult("vkBindBufferMemory2", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindImageMemory2(GetDeviceTable(in_device->handle)->BindImageMemory2, returnValue, in_device, bindInfoCount, pBindInfos);
    CheckResult("vkBindImageMemory2", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = pPeerMemoryFeatures->IsNull() ? nullptr : pPeerMemoryFeatures->AllocateOutputData(1, static_cast<VkPeerMemoryFeatureFlags>(0));

    GetDeviceTable(in_device)->GetDeviceGroupPeerMemoryFeatures(in_device, heapIndex, localDeviceIndex, remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDeviceMask(in_commandBuffer, deviceMask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDeviceMask(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDeviceMask, in_commandBuffer, deviceMask);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDispatchBase(in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDispatchBase(call_info, GetDeviceTable(in_commandBuffer)->CmdDispatchBase, in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    pPhysicalDeviceGroupCount->IsNull() ? nullptr : pPhysicalDeviceGroupCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanInstanceInfo>("vkEnumeratePhysicalDeviceGroups", returnValue, instance, kInstanceArrayEnumeratePhysicalDeviceGroups, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties, &CommonObjectInfoTable::GetVkInstanceInfo));
    SetStructArrayHandleLengths<Decoded_VkPhysicalDeviceGroupProperties>(pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength());
    if (!pPhysicalDeviceGroupProperties->IsNull()) { pPhysicalDeviceGroupProperties->AllocateOutputData(*pPhysicalDeviceGroupCount->GetOutputPointer(), VkPhysicalDeviceGroupProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, nullptr }); }

    VkResult replay_result = OverrideEnumeratePhysicalDeviceGroups(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDeviceGroups, returnValue, in_instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    CheckResult("vkEnumeratePhysicalDeviceGroups", returnValue, replay_result, call_info);

    if (pPhysicalDeviceGroupProperties->IsNull()) { SetOutputArrayCount<VulkanInstanceInfo>(instance, kInstanceArrayEnumeratePhysicalDeviceGroups, *pPhysicalDeviceGroupCount->GetOutputPointer(), &CommonObjectInfoTable::GetVkInstanceInfo); }
    AddStructArrayHandles<Decoded_VkPhysicalDeviceGroupProperties>(instance, pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength(), pPhysicalDeviceGroupProperties->GetOutputPointer(), *pPhysicalDeviceGroupCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImageMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetImageMemoryRequirements2(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkBufferMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetBufferMemoryRequirements2(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImageSparseMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetImageSparseMemoryRequirements2", VK_SUCCESS, device, kDeviceArrayGetImageSparseMemoryRequirements2, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements2(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(device, kDeviceArrayGetImageSparseMemoryRequirements2, *out_pSparseMemoryRequirementCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkPhysicalDeviceFeatures2* out_pFeatures = pFeatures->IsNull() ? nullptr : pFeatures->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr });
    InitializeOutputStructPNext(pFeatures);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures2(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(pProperties);

    OverrideGetPhysicalDeviceProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties2, in_physicalDevice, pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkFormatProperties2* out_pFormatProperties = pFormatProperties->IsNull() ? nullptr : pFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(pFormatProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties2(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = pImageFormatInfo->GetPointer();
    VkImageFormatProperties2* out_pImageFormatProperties = pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(pImageFormatProperties);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties2(in_physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties2", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pQueueFamilyPropertyCount = pQueueFamilyPropertyCount->IsNull() ? nullptr : pQueueFamilyPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties2", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2, pQueueFamilyPropertyCount, pQueueFamilyProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkQueueFamilyProperties2* out_pQueueFamilyProperties = pQueueFamilyProperties->IsNull() ? nullptr : pQueueFamilyProperties->AllocateOutputData(*out_pQueueFamilyPropertyCount, VkQueueFamilyProperties2{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    if (pQueueFamilyProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2, *out_pQueueFamilyPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
    pMemoryProperties->IsNull() ? nullptr : pMemoryProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(pMemoryProperties);

    OverrideGetPhysicalDeviceMemoryProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties2, in_physicalDevice, pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = pFormatInfo->GetPointer();
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties2", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkSparseImageFormatProperties2* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkSparseImageFormatProperties2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(in_physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkCommandPool in_commandPool = MapHandle<VulkanCommandPoolInfo>(commandPool, &CommonObjectInfoTable::GetVkCommandPoolInfo);

    GetDeviceTable(in_device)->TrimCommandPool(in_device, in_commandPool, flags);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    if (!pQueue->IsNull()) { pQueue->SetHandleLength(1); }
    VulkanQueueInfo handle_info;
    pQueue->SetConsumerData(0, &handle_info);

    OverrideGetDeviceQueue2(GetDeviceTable(in_device->handle)->GetDeviceQueue2, in_device, pQueueInfo, pQueue);

    AddHandle<VulkanQueueInfo>(device, pQueue->GetPointer(), pQueue->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkQueueInfo);
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSamplerYcbcrConversionCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pYcbcrConversion->IsNull()) { pYcbcrConversion->SetHandleLength(1); }
    VkSamplerYcbcrConversion* out_pYcbcrConversion = pYcbcrConversion->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSamplerYcbcrConversion(in_device, in_pCreateInfo, in_pAllocator, out_pYcbcrConversion);
    CheckResult("vkCreateSamplerYcbcrConversion", returnValue, replay_result, call_info);

    AddHandle<VulkanSamplerYcbcrConversionInfo>(device, pYcbcrConversion->GetPointer(), out_pYcbcrConversion, &CommonObjectInfoTable::AddVkSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSamplerYcbcrConversion in_ycbcrConversion = MapHandle<VulkanSamplerYcbcrConversionInfo>(ycbcrConversion, &CommonObjectInfoTable::GetVkSamplerYcbcrConversionInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySamplerYcbcrConversion(in_device, in_ycbcrConversion, in_pAllocator);
    RemoveHandle(ycbcrConversion, &CommonObjectInfoTable::RemoveVkSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDescriptorUpdateTemplate->IsNull()) { pDescriptorUpdateTemplate->SetHandleLength(1); }
    VulkanDescriptorUpdateTemplateInfo handle_info;
    pDescriptorUpdateTemplate->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->CreateDescriptorUpdateTemplate, returnValue, in_device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    CheckResult("vkCreateDescriptorUpdateTemplate", returnValue, replay_result, call_info);

    AddHandle<VulkanDescriptorUpdateTemplateInfo>(device, pDescriptorUpdateTemplate->GetPointer(), pDescriptorUpdateTemplate->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_descriptorUpdateTemplate = GetObjectInfoTable().GetVkDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    OverrideDestroyDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->DestroyDescriptorUpdateTemplate, in_device, in_descriptorUpdateTemplate, pAllocator);
    RemoveHandle(descriptorUpdateTemplate, &CommonObjectInfoTable::RemoveVkDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = pExternalBufferInfo->GetPointer();
    VkExternalBufferProperties* out_pExternalBufferProperties = pExternalBufferProperties->IsNull() ? nullptr : pExternalBufferProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, nullptr });
    InitializeOutputStructPNext(pExternalBufferProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalBufferProperties(in_physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = pExternalFenceInfo->GetPointer();
    VkExternalFenceProperties* out_pExternalFenceProperties = pExternalFenceProperties->IsNull() ? nullptr : pExternalFenceProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, nullptr });
    InitializeOutputStructPNext(pExternalFenceProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalFenceProperties(in_physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = pExternalSemaphoreInfo->GetPointer();
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = pExternalSemaphoreProperties->IsNull() ? nullptr : pExternalSemaphoreProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, nullptr });
    InitializeOutputStructPNext(pExternalSemaphoreProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(in_physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkDescriptorSetLayoutSupport* out_pSupport = pSupport->IsNull() ? nullptr : pSupport->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, nullptr });
    InitializeOutputStructPNext(pSupport);

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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCount(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawIndirectCount(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCount, in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(buffer), offset, GetObjectInfoTable().GetVkBufferInfo(countBuffer), countBufferOffset, maxDrawCount, stride);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCount(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawIndexedIndirectCount(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCount, in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(buffer), offset, GetObjectInfoTable().GetVkBufferInfo(countBuffer), countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayConsumer::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    if (!pRenderPass->IsNull()) { pRenderPass->SetHandleLength(1); }
    VulkanRenderPassInfo handle_info;
    pRenderPass->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateRenderPass2(GetDeviceTable(in_device->handle)->CreateRenderPass2, returnValue, in_device, pCreateInfo, pAllocator, pRenderPass);
    CheckResult("vkCreateRenderPass2", returnValue, replay_result, call_info);

    AddHandle<VulkanRenderPassInfo>(device, pRenderPass->GetPointer(), pRenderPass->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdBeginRenderPass2(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass2, in_commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginRenderPass2(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass2, in_commandBuffer->handle, pRenderPassBegin, pSubpassBeginInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSubpassBeginInfo* in_pSubpassBeginInfo = pSubpassBeginInfo->GetPointer();
    const VkSubpassEndInfo* in_pSubpassEndInfo = pSubpassEndInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass2(in_commandBuffer, in_pSubpassBeginInfo, in_pSubpassEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdNextSubpass2(call_info, GetDeviceTable(in_commandBuffer)->CmdNextSubpass2, in_commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSubpassEndInfo* in_pSubpassEndInfo = pSubpassEndInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndRenderPass2(in_commandBuffer, in_pSubpassEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndRenderPass2(call_info, GetDeviceTable(in_commandBuffer)->CmdEndRenderPass2, in_commandBuffer, pSubpassEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_device)->ResetQueryPool(in_device, in_queryPool, firstQuery, queryCount);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreCounterValue(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSemaphore in_semaphore = MapHandle<VulkanSemaphoreInfo>(semaphore, &CommonObjectInfoTable::GetVkSemaphoreInfo);
    uint64_t* out_pValue = pValue->IsNull() ? nullptr : pValue->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreCounterValue(in_device, in_semaphore, out_pValue);
    CheckResult("vkGetSemaphoreCounterValue", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pWaitInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideWaitSemaphores(GetDeviceTable(in_device->handle)->WaitSemaphores, returnValue, in_device, pWaitInfo, timeout);
    CheckResult("vkWaitSemaphores", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreSignalInfo* in_pSignalInfo = pSignalInfo->GetPointer();
    MapStructHandles(pSignalInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->SignalSemaphore(in_device, in_pSignalInfo);
    CheckResult("vkSignalSemaphore", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetBufferDeviceAddress(GetDeviceTable(in_device->handle)->GetBufferDeviceAddress, returnValue, in_device, pInfo);
}

void VulkanReplayConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
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
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
    pToolCount->IsNull() ? nullptr : pToolCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceToolProperties", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolProperties, pToolCount, pToolProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    if (!pToolProperties->IsNull()) { pToolProperties->AllocateOutputData(*pToolCount->GetOutputPointer(), VkPhysicalDeviceToolProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES, nullptr }); }

    VkResult replay_result = OverrideGetPhysicalDeviceToolProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceToolProperties, returnValue, in_physicalDevice, pToolCount, pToolProperties);
    CheckResult("vkGetPhysicalDeviceToolProperties", returnValue, replay_result, call_info);

    if (pToolProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolProperties, *pToolCount->GetOutputPointer(), &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPrivateDataSlotCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pPrivateDataSlot->IsNull()) { pPrivateDataSlot->SetHandleLength(1); }
    VkPrivateDataSlot* out_pPrivateDataSlot = pPrivateDataSlot->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreatePrivateDataSlot(in_device, in_pCreateInfo, in_pAllocator, out_pPrivateDataSlot);
    CheckResult("vkCreatePrivateDataSlot", returnValue, replay_result, call_info);

    AddHandle<VulkanPrivateDataSlotInfo>(device, pPrivateDataSlot->GetPointer(), out_pPrivateDataSlot, &CommonObjectInfoTable::AddVkPrivateDataSlotInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPrivateDataSlot(in_device, in_privateDataSlot, in_pAllocator);
    RemoveHandle(privateDataSlot, &CommonObjectInfoTable::RemoveVkPrivateDataSlotInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);

    VkResult replay_result = GetDeviceTable(in_device)->SetPrivateData(in_device, objectType, in_objectHandle, in_privateDataSlot, data);
    CheckResult("vkSetPrivateData", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);
    uint64_t* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(1, static_cast<uint64_t>(0));

    GetDeviceTable(in_device)->GetPrivateData(in_device, objectType, in_objectHandle, in_privateDataSlot, out_pData);
}

void VulkanReplayConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkEvent in_event = MapHandle<VulkanEventInfo>(event, &CommonObjectInfoTable::GetVkEventInfo);
    const VkDependencyInfo* in_pDependencyInfo = pDependencyInfo->GetPointer();
    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetEvent2(in_commandBuffer, in_event, in_pDependencyInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetEvent2(call_info, GetDeviceTable(in_commandBuffer)->CmdSetEvent2, in_commandBuffer, in_event, in_pDependencyInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkEvent in_event = MapHandle<VulkanEventInfo>(event, &CommonObjectInfoTable::GetVkEventInfo);

    GetDeviceTable(in_commandBuffer)->CmdResetEvent2(in_commandBuffer, in_event, stageMask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdResetEvent2(call_info, GetDeviceTable(in_commandBuffer)->CmdResetEvent2, in_commandBuffer, in_event, stageMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkEvent* in_pEvents = MapHandles<VulkanEventInfo>(pEvents, eventCount, &CommonObjectInfoTable::GetVkEventInfo);
    const VkDependencyInfo* in_pDependencyInfos = pDependencyInfos->GetPointer();
    MapStructArrayHandles(pDependencyInfos->GetMetaStructPointer(), pDependencyInfos->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdWaitEvents2(in_commandBuffer, eventCount, in_pEvents, in_pDependencyInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWaitEvents2(call_info, GetDeviceTable(in_commandBuffer)->CmdWaitEvents2, in_commandBuffer, eventCount, in_pEvents, in_pDependencyInfos);
    }
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdPipelineBarrier2(GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier2, in_commandBuffer, pDependencyInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPipelineBarrier2(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier2, in_commandBuffer->handle, pDependencyInfo->GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteTimestamp2(in_commandBuffer, stage, in_queryPool, query);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWriteTimestamp2(call_info, GetDeviceTable(in_commandBuffer)->CmdWriteTimestamp2, in_commandBuffer, stage, in_queryPool, query);
    }
}

void VulkanReplayConsumer::Process_vkQueueSubmit2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetVkQueueInfo(queue);

    MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(fence);

    VkResult replay_result = OverrideQueueSubmit2(GetDeviceTable(in_queue->handle)->QueueSubmit2, returnValue, in_queue, submitCount, pSubmits, in_fence);
    CheckResult("vkQueueSubmit2", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyBufferInfo2* in_pCopyBufferInfo = pCopyBufferInfo->GetPointer();
    MapStructHandles(pCopyBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyBuffer2(in_commandBuffer, in_pCopyBufferInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyBuffer2(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyBuffer2, in_commandBuffer, in_pCopyBufferInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyImageInfo2* in_pCopyImageInfo = pCopyImageInfo->GetPointer();
    MapStructHandles(pCopyImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyImage2(in_commandBuffer, in_pCopyImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyImage2(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyImage2, in_commandBuffer, in_pCopyImageInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyBufferToImageInfo2* in_pCopyBufferToImageInfo = pCopyBufferToImageInfo->GetPointer();
    MapStructHandles(pCopyBufferToImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage2(in_commandBuffer, in_pCopyBufferToImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyBufferToImage2(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage2, in_commandBuffer, in_pCopyBufferToImageInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyImageToBufferInfo2* in_pCopyImageToBufferInfo = pCopyImageToBufferInfo->GetPointer();
    MapStructHandles(pCopyImageToBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer2(in_commandBuffer, in_pCopyImageToBufferInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyImageToBuffer2(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer2, in_commandBuffer, in_pCopyImageToBufferInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBlitImageInfo2* in_pBlitImageInfo = pBlitImageInfo->GetPointer();
    MapStructHandles(pBlitImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBlitImage2(in_commandBuffer, in_pBlitImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBlitImage2(call_info, GetDeviceTable(in_commandBuffer)->CmdBlitImage2, in_commandBuffer, in_pBlitImageInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkResolveImageInfo2* in_pResolveImageInfo = pResolveImageInfo->GetPointer();
    MapStructHandles(pResolveImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdResolveImage2(in_commandBuffer, in_pResolveImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdResolveImage2(call_info, GetDeviceTable(in_commandBuffer)->CmdResolveImage2, in_commandBuffer, in_pResolveImageInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRenderingInfo* in_pRenderingInfo = pRenderingInfo->GetPointer();
    MapStructHandles(pRenderingInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginRendering(in_commandBuffer, in_pRenderingInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginRendering(call_info, GetDeviceTable(in_commandBuffer)->CmdBeginRendering, in_commandBuffer, pRenderingInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndRendering(in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndRendering(call_info, GetDeviceTable(in_commandBuffer)->CmdEndRendering, in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCullMode(in_commandBuffer, cullMode);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetCullMode(call_info, GetDeviceTable(in_commandBuffer)->CmdSetCullMode, in_commandBuffer, cullMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetFrontFace(in_commandBuffer, frontFace);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetFrontFace(call_info, GetDeviceTable(in_commandBuffer)->CmdSetFrontFace, in_commandBuffer, frontFace);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveTopology(in_commandBuffer, primitiveTopology);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetPrimitiveTopology(call_info, GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveTopology, in_commandBuffer, primitiveTopology);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkViewport* in_pViewports = pViewports->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWithCount(in_commandBuffer, viewportCount, in_pViewports);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetViewportWithCount(call_info, GetDeviceTable(in_commandBuffer)->CmdSetViewportWithCount, in_commandBuffer, viewportCount, in_pViewports);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRect2D* in_pScissors = pScissors->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetScissorWithCount(in_commandBuffer, scissorCount, in_pScissors);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetScissorWithCount(call_info, GetDeviceTable(in_commandBuffer)->CmdSetScissorWithCount, in_commandBuffer, scissorCount, in_pScissors);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<VulkanBufferInfo>(pBuffers, bindingCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pOffsets = pOffsets->GetPointer();
    const VkDeviceSize* in_pSizes = pSizes->GetPointer();
    const VkDeviceSize* in_pStrides = pStrides->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers2(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets, in_pSizes, in_pStrides);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindVertexBuffers2(call_info, GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers2, in_commandBuffer, firstBinding, bindingCount, pBuffers, in_pOffsets, in_pSizes, in_pStrides);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthTestEnable(in_commandBuffer, depthTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthTestEnable(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthTestEnable, in_commandBuffer, depthTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthWriteEnable(in_commandBuffer, depthWriteEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthWriteEnable(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthWriteEnable, in_commandBuffer, depthWriteEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthCompareOp(in_commandBuffer, depthCompareOp);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthCompareOp(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthCompareOp, in_commandBuffer, depthCompareOp);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBoundsTestEnable(in_commandBuffer, depthBoundsTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthBoundsTestEnable(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthBoundsTestEnable, in_commandBuffer, depthBoundsTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilTestEnable(in_commandBuffer, stencilTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetStencilTestEnable(call_info, GetDeviceTable(in_commandBuffer)->CmdSetStencilTestEnable, in_commandBuffer, stencilTestEnable);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilOp(in_commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetStencilOp(call_info, GetDeviceTable(in_commandBuffer)->CmdSetStencilOp, in_commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizerDiscardEnable(in_commandBuffer, rasterizerDiscardEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetRasterizerDiscardEnable(call_info, GetDeviceTable(in_commandBuffer)->CmdSetRasterizerDiscardEnable, in_commandBuffer, rasterizerDiscardEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBiasEnable(in_commandBuffer, depthBiasEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthBiasEnable(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthBiasEnable, in_commandBuffer, depthBiasEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveRestartEnable(in_commandBuffer, primitiveRestartEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetPrimitiveRestartEnable(call_info, GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveRestartEnable, in_commandBuffer, primitiveRestartEnable);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceBufferMemoryRequirements* in_pInfo = pInfo->GetPointer();
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetDeviceBufferMemoryRequirements(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetDeviceImageMemoryRequirements(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetDeviceImageSparseMemoryRequirements", VK_SUCCESS, device, kDeviceArrayGetDeviceImageSparseMemoryRequirements, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetDeviceImageSparseMemoryRequirements(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(device, kDeviceArrayGetDeviceImageSparseMemoryRequirements, *out_pSparseMemoryRequirementCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    auto in_surface = GetObjectInfoTable().GetVkSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }

    OverrideDestroySurfaceKHR(GetInstanceTable(in_instance->handle)->DestroySurfaceKHR, in_instance, in_surface, pAllocator);
    RemoveHandle(surface, &CommonObjectInfoTable::RemoveVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceSupportKHR for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    VkBool32* out_pSupported = pSupported->IsNull() ? nullptr : pSupported->AllocateOutputData(1, static_cast<VkBool32>(0));

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(in_physicalDevice, queueFamilyIndex, in_surface, out_pSupported);
    CheckResult("vkGetPhysicalDeviceSurfaceSupportKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceCapabilitiesKHR for offscreen.");
        return;
    }
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
    auto in_surface = GetObjectInfoTable().GetVkSurfaceKHRInfo(surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    pSurfaceCapabilities->IsNull() ? nullptr : pSurfaceCapabilities->AllocateOutputData(1);

    VkResult replay_result = OverrideGetPhysicalDeviceSurfaceCapabilitiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceCapabilitiesKHR, returnValue, in_physicalDevice, in_surface, pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilitiesKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceFormatsKHR for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    uint32_t* out_pSurfaceFormatCount = pSurfaceFormatCount->IsNull() ? nullptr : pSurfaceFormatCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanSurfaceKHRInfo>("vkGetPhysicalDeviceSurfaceFormatsKHR", returnValue, surface, kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR, pSurfaceFormatCount, pSurfaceFormats, &CommonObjectInfoTable::GetVkSurfaceKHRInfo));
    VkSurfaceFormatKHR* out_pSurfaceFormats = pSurfaceFormats->IsNull() ? nullptr : pSurfaceFormats->AllocateOutputData(*out_pSurfaceFormatCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(in_physicalDevice, in_surface, out_pSurfaceFormatCount, out_pSurfaceFormats);
    CheckResult("vkGetPhysicalDeviceSurfaceFormatsKHR", returnValue, replay_result, call_info);

    if (pSurfaceFormats->IsNull()) { SetOutputArrayCount<VulkanSurfaceKHRInfo>(surface, kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR, *out_pSurfaceFormatCount, &CommonObjectInfoTable::GetVkSurfaceKHRInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfacePresentModesKHR for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    uint32_t* out_pPresentModeCount = pPresentModeCount->IsNull() ? nullptr : pPresentModeCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanSurfaceKHRInfo>("vkGetPhysicalDeviceSurfacePresentModesKHR", returnValue, surface, kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR, pPresentModeCount, pPresentModes, &CommonObjectInfoTable::GetVkSurfaceKHRInfo));
    VkPresentModeKHR* out_pPresentModes = pPresentModes->IsNull() ? nullptr : pPresentModes->AllocateOutputData(*out_pPresentModeCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(in_physicalDevice, in_surface, out_pPresentModeCount, out_pPresentModes);
    CheckResult("vkGetPhysicalDeviceSurfacePresentModesKHR", returnValue, replay_result, call_info);

    if (pPresentModes->IsNull()) { SetOutputArrayCount<VulkanSurfaceKHRInfo>(surface, kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR, *out_pPresentModeCount, &CommonObjectInfoTable::GetVkSurfaceKHRInfo); }
}

void VulkanReplayConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pSwapchain->IsNull()) { pSwapchain->SetHandleLength(1); }
    VulkanSwapchainKHRInfo handle_info;
    pSwapchain->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateSwapchainKHR(GetDeviceTable(in_device->handle)->CreateSwapchainKHR, returnValue, in_device, pCreateInfo, pAllocator, pSwapchain);
    CheckResult("vkCreateSwapchainKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanSwapchainKHRInfo>(device, pSwapchain->GetPointer(), pSwapchain->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSwapchainKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain);

    OverrideDestroySwapchainKHR(GetDeviceTable(in_device->handle)->DestroySwapchainKHR, in_device, in_swapchain, pAllocator);
    RemoveHandle(swapchain, &CommonObjectInfoTable::RemoveVkSwapchainKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain);
    pSwapchainImageCount->IsNull() ? nullptr : pSwapchainImageCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanSwapchainKHRInfo>("vkGetSwapchainImagesKHR", returnValue, swapchain, kSwapchainKHRArrayGetSwapchainImagesKHR, pSwapchainImageCount, pSwapchainImages, &CommonObjectInfoTable::GetVkSwapchainKHRInfo));
    if (!pSwapchainImages->IsNull()) { pSwapchainImages->SetHandleLength(*pSwapchainImageCount->GetOutputPointer()); }
    std::vector<VulkanImageInfo> handle_info(*pSwapchainImageCount->GetOutputPointer());
    for (size_t i = 0; i < *pSwapchainImageCount->GetOutputPointer(); ++i) { pSwapchainImages->SetConsumerData(i, &handle_info[i]); }

    VkResult replay_result = OverrideGetSwapchainImagesKHR(GetDeviceTable(in_device->handle)->GetSwapchainImagesKHR, returnValue, in_device, in_swapchain, pSwapchainImageCount, pSwapchainImages);
    CheckResult("vkGetSwapchainImagesKHR", returnValue, replay_result, call_info);

    if (pSwapchainImages->IsNull()) { SetOutputArrayCount<VulkanSwapchainKHRInfo>(swapchain, kSwapchainKHRArrayGetSwapchainImagesKHR, *pSwapchainImageCount->GetOutputPointer(), &CommonObjectInfoTable::GetVkSwapchainKHRInfo); }
    AddHandles<VulkanImageInfo>(device, pSwapchainImages->GetPointer(), pSwapchainImages->GetLength(), pSwapchainImages->GetHandlePointer(), *pSwapchainImageCount->GetOutputPointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkImageInfo);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain);
    auto in_semaphore = GetObjectInfoTable().GetVkSemaphoreInfo(semaphore);
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(fence);
    pImageIndex->IsNull() ? nullptr : pImageIndex->AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = OverrideAcquireNextImageKHR(GetDeviceTable(in_device->handle)->AcquireNextImageKHR, returnValue, in_device, in_swapchain, timeout, in_semaphore, in_fence, pImageIndex);
    CheckResult("vkAcquireNextImageKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    auto in_queue = GetObjectInfoTable().GetVkQueueInfo(queue);

    MapStructHandles(pPresentInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideQueuePresentKHR(GetDeviceTable(in_queue->handle)->QueuePresentKHR, returnValue, in_queue, pPresentInfo);
    CheckResult("vkQueuePresentKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetDeviceGroupPresentCapabilitiesKHR for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeviceGroupPresentCapabilitiesKHR* out_pDeviceGroupPresentCapabilities = pDeviceGroupPresentCapabilities->IsNull() ? nullptr : pDeviceGroupPresentCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR, nullptr });
    InitializeOutputStructPNext(pDeviceGroupPresentCapabilities);

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupPresentCapabilitiesKHR(in_device, out_pDeviceGroupPresentCapabilities);
    CheckResult("vkGetDeviceGroupPresentCapabilitiesKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetDeviceGroupSurfacePresentModesKHR for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    VkDeviceGroupPresentModeFlagsKHR* out_pModes = pModes->IsNull() ? nullptr : pModes->AllocateOutputData(1, static_cast<VkDeviceGroupPresentModeFlagsKHR>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupSurfacePresentModesKHR(in_device, in_surface, out_pModes);
    CheckResult("vkGetDeviceGroupSurfacePresentModesKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDevicePresentRectanglesKHR for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    uint32_t* out_pRectCount = pRectCount->IsNull() ? nullptr : pRectCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanSurfaceKHRInfo>("vkGetPhysicalDevicePresentRectanglesKHR", returnValue, surface, kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR, pRectCount, pRects, &CommonObjectInfoTable::GetVkSurfaceKHRInfo));
    VkRect2D* out_pRects = pRects->IsNull() ? nullptr : pRects->AllocateOutputData(*out_pRectCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(in_physicalDevice, in_surface, out_pRectCount, out_pRects);
    CheckResult("vkGetPhysicalDevicePresentRectanglesKHR", returnValue, replay_result, call_info);

    if (pRects->IsNull()) { SetOutputArrayCount<VulkanSurfaceKHRInfo>(surface, kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR, *out_pRectCount, &CommonObjectInfoTable::GetVkSurfaceKHRInfo); }
}

void VulkanReplayConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pAcquireInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pImageIndex->IsNull() ? nullptr : pImageIndex->AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = OverrideAcquireNextImage2KHR(GetDeviceTable(in_device->handle)->AcquireNextImage2KHR, returnValue, in_device, pAcquireInfo, pImageIndex);
    CheckResult("vkAcquireNextImage2KHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPropertiesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkDisplayPropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPropertiesKHR", returnValue, replay_result, call_info);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayPropertiesKHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkDisplayPlanePropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", returnValue, replay_result, call_info);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
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
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pDisplayCount = pDisplayCount->IsNull() ? nullptr : pDisplayCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetDisplayPlaneSupportedDisplaysKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR, pDisplayCount, pDisplays, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    if (!pDisplays->IsNull()) { pDisplays->SetHandleLength(*out_pDisplayCount); }
    VkDisplayKHR* out_pDisplays = pDisplays->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(in_physicalDevice, planeIndex, out_pDisplayCount, out_pDisplays);
    CheckResult("vkGetDisplayPlaneSupportedDisplaysKHR", returnValue, replay_result, call_info);

    if (pDisplays->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR, *out_pDisplayCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    AddHandles<VulkanDisplayKHRInfo>(physicalDevice, pDisplays->GetPointer(), pDisplays->GetLength(), out_pDisplays, *out_pDisplayCount, &CommonObjectInfoTable::AddVkDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDisplayKHRInfo>("vkGetDisplayModePropertiesKHR", returnValue, display, kDisplayKHRArrayGetDisplayModePropertiesKHR, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkDisplayKHRInfo));
    VkDisplayModePropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayModePropertiesKHR(in_physicalDevice, in_display, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetDisplayModePropertiesKHR", returnValue, replay_result, call_info);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanDisplayKHRInfo>(display, kDisplayKHRArrayGetDisplayModePropertiesKHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkDisplayKHRInfo); }
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
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    const VkDisplayModeCreateInfoKHR* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pMode->IsNull()) { pMode->SetHandleLength(1); }
    VkDisplayModeKHR* out_pMode = pMode->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->CreateDisplayModeKHR(in_physicalDevice, in_display, in_pCreateInfo, in_pAllocator, out_pMode);
    CheckResult("vkCreateDisplayModeKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanDisplayModeKHRInfo>(physicalDevice, pMode->GetPointer(), out_pMode, &CommonObjectInfoTable::AddVkDisplayModeKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayModeKHR in_mode = MapHandle<VulkanDisplayModeKHRInfo>(mode, &CommonObjectInfoTable::GetVkDisplayModeKHRInfo);
    VkDisplayPlaneCapabilitiesKHR* out_pCapabilities = pCapabilities->IsNull() ? nullptr : pCapabilities->AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneCapabilitiesKHR(in_physicalDevice, in_mode, planeIndex, out_pCapabilities);
    CheckResult("vkGetDisplayPlaneCapabilitiesKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDisplayPlaneSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateDisplayPlaneSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateDisplayPlaneSurfaceKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    if (!pSwapchains->IsNull()) { pSwapchains->SetHandleLength(swapchainCount); }
    std::vector<VulkanSwapchainKHRInfo> handle_info(swapchainCount);
    for (size_t i = 0; i < swapchainCount; ++i) { pSwapchains->SetConsumerData(i, &handle_info[i]); }

    VkResult replay_result = OverrideCreateSharedSwapchainsKHR(GetDeviceTable(in_device->handle)->CreateSharedSwapchainsKHR, returnValue, in_device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    CheckResult("vkCreateSharedSwapchainsKHR", returnValue, replay_result, call_info);

    AddHandles<VulkanSwapchainKHRInfo>(device, pSwapchains->GetPointer(), pSwapchains->GetLength(), pSwapchains->GetHandlePointer(), swapchainCount, std::move(handle_info), &CommonObjectInfoTable::AddVkSwapchainKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateXlibSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateXlibSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateXlibSurfaceKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
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
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateXcbSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateXcbSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateXcbSurfaceKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
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
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateWaylandSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateWaylandSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateWaylandSurfaceKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
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
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateAndroidSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateAndroidSurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateAndroidSurfaceKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateWin32SurfaceKHR(GetInstanceTable(in_instance->handle)->CreateWin32SurfaceKHR, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateWin32SurfaceKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);

    OverrideGetPhysicalDeviceWin32PresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceWin32PresentationSupportKHR, in_physicalDevice, queueFamilyIndex);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile,
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkVideoProfileInfoKHR* in_pVideoProfile = pVideoProfile->GetPointer();
    VkVideoCapabilitiesKHR* out_pCapabilities = pCapabilities->IsNull() ? nullptr : pCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR, nullptr });
    InitializeOutputStructPNext(pCapabilities);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceVideoCapabilitiesKHR(in_physicalDevice, in_pVideoProfile, out_pCapabilities);
    CheckResult("vkGetPhysicalDeviceVideoCapabilitiesKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo,
    PointerDecoder<uint32_t>*                   pVideoFormatPropertyCount,
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceVideoFormatInfoKHR* in_pVideoFormatInfo = pVideoFormatInfo->GetPointer();
    uint32_t* out_pVideoFormatPropertyCount = pVideoFormatPropertyCount->IsNull() ? nullptr : pVideoFormatPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceVideoFormatPropertiesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceVideoFormatPropertiesKHR, pVideoFormatPropertyCount, pVideoFormatProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkVideoFormatPropertiesKHR* out_pVideoFormatProperties = pVideoFormatProperties->IsNull() ? nullptr : pVideoFormatProperties->AllocateOutputData(*out_pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR{ VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceVideoFormatPropertiesKHR(in_physicalDevice, in_pVideoFormatInfo, out_pVideoFormatPropertyCount, out_pVideoFormatProperties);
    CheckResult("vkGetPhysicalDeviceVideoFormatPropertiesKHR", returnValue, replay_result, call_info);

    if (pVideoFormatProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceVideoFormatPropertiesKHR, *out_pVideoFormatPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionKHR>*    pVideoSession)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    if (!pVideoSession->IsNull()) { pVideoSession->SetHandleLength(1); }
    VulkanVideoSessionKHRInfo handle_info;
    pVideoSession->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateVideoSessionKHR(GetDeviceTable(in_device->handle)->CreateVideoSessionKHR, returnValue, in_device, pCreateInfo, pAllocator, pVideoSession);
    CheckResult("vkCreateVideoSessionKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanVideoSessionKHRInfo>(device, pVideoSession->GetPointer(), pVideoSession->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkVideoSessionKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_videoSession = GetObjectInfoTable().GetVkVideoSessionKHRInfo(videoSession);

    OverrideDestroyVideoSessionKHR(GetDeviceTable(in_device->handle)->DestroyVideoSessionKHR, in_device, in_videoSession, pAllocator);
    RemoveHandle(videoSession, &CommonObjectInfoTable::RemoveVkVideoSessionKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetVideoSessionMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    PointerDecoder<uint32_t>*                   pMemoryRequirementsCount,
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkVideoSessionKHR in_videoSession = MapHandle<VulkanVideoSessionKHRInfo>(videoSession, &CommonObjectInfoTable::GetVkVideoSessionKHRInfo);
    uint32_t* out_pMemoryRequirementsCount = pMemoryRequirementsCount->IsNull() ? nullptr : pMemoryRequirementsCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanVideoSessionKHRInfo>("vkGetVideoSessionMemoryRequirementsKHR", returnValue, videoSession, kVideoSessionKHRArrayGetVideoSessionMemoryRequirementsKHR, pMemoryRequirementsCount, pMemoryRequirements, &CommonObjectInfoTable::GetVkVideoSessionKHRInfo));
    VkVideoSessionMemoryRequirementsKHR* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(*out_pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR{ VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetVideoSessionMemoryRequirementsKHR(in_device, in_videoSession, out_pMemoryRequirementsCount, out_pMemoryRequirements);
    CheckResult("vkGetVideoSessionMemoryRequirementsKHR", returnValue, replay_result, call_info);

    if (pMemoryRequirements->IsNull()) { SetOutputArrayCount<VulkanVideoSessionKHRInfo>(videoSession, kVideoSessionKHRArrayGetVideoSessionMemoryRequirementsKHR, *out_pMemoryRequirementsCount, &CommonObjectInfoTable::GetVkVideoSessionKHRInfo); }
}

void VulkanReplayConsumer::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_videoSession = GetObjectInfoTable().GetVkVideoSessionKHRInfo(videoSession);

    MapStructArrayHandles(pBindSessionMemoryInfos->GetMetaStructPointer(), pBindSessionMemoryInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindVideoSessionMemoryKHR(GetDeviceTable(in_device->handle)->BindVideoSessionMemoryKHR, returnValue, in_device, in_videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
    CheckResult("vkBindVideoSessionMemoryKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkVideoSessionParametersCreateInfoKHR* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pVideoSessionParameters->IsNull()) { pVideoSessionParameters->SetHandleLength(1); }
    VkVideoSessionParametersKHR* out_pVideoSessionParameters = pVideoSessionParameters->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateVideoSessionParametersKHR(in_device, in_pCreateInfo, in_pAllocator, out_pVideoSessionParameters);
    CheckResult("vkCreateVideoSessionParametersKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanVideoSessionParametersKHRInfo>(device, pVideoSessionParameters->GetPointer(), out_pVideoSessionParameters, &CommonObjectInfoTable::AddVkVideoSessionParametersKHRInfo);
}

void VulkanReplayConsumer::Process_vkUpdateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkVideoSessionParametersKHR in_videoSessionParameters = MapHandle<VulkanVideoSessionParametersKHRInfo>(videoSessionParameters, &CommonObjectInfoTable::GetVkVideoSessionParametersKHRInfo);
    const VkVideoSessionParametersUpdateInfoKHR* in_pUpdateInfo = pUpdateInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->UpdateVideoSessionParametersKHR(in_device, in_videoSessionParameters, in_pUpdateInfo);
    CheckResult("vkUpdateVideoSessionParametersKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkVideoSessionParametersKHR in_videoSessionParameters = MapHandle<VulkanVideoSessionParametersKHRInfo>(videoSessionParameters, &CommonObjectInfoTable::GetVkVideoSessionParametersKHRInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyVideoSessionParametersKHR(in_device, in_videoSessionParameters, in_pAllocator);
    RemoveHandle(videoSessionParameters, &CommonObjectInfoTable::RemoveVkVideoSessionParametersKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVideoBeginCodingInfoKHR* in_pBeginInfo = pBeginInfo->GetPointer();
    MapStructHandles(pBeginInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginVideoCodingKHR(in_commandBuffer, in_pBeginInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginVideoCodingKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdBeginVideoCodingKHR, in_commandBuffer, in_pBeginInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVideoEndCodingInfoKHR* in_pEndCodingInfo = pEndCodingInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndVideoCodingKHR(in_commandBuffer, in_pEndCodingInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndVideoCodingKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdEndVideoCodingKHR, in_commandBuffer, in_pEndCodingInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVideoCodingControlInfoKHR* in_pCodingControlInfo = pCodingControlInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdControlVideoCodingKHR(in_commandBuffer, in_pCodingControlInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdControlVideoCodingKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdControlVideoCodingKHR, in_commandBuffer, in_pCodingControlInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVideoDecodeInfoKHR* in_pDecodeInfo = pDecodeInfo->GetPointer();
    MapStructHandles(pDecodeInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDecodeVideoKHR(in_commandBuffer, in_pDecodeInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDecodeVideoKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdDecodeVideoKHR, in_commandBuffer, in_pDecodeInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRenderingInfo* in_pRenderingInfo = pRenderingInfo->GetPointer();
    MapStructHandles(pRenderingInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginRenderingKHR(in_commandBuffer, in_pRenderingInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginRenderingKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdBeginRenderingKHR, in_commandBuffer, pRenderingInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndRenderingKHR(in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndRenderingKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdEndRenderingKHR, in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkPhysicalDeviceFeatures2* out_pFeatures = pFeatures->IsNull() ? nullptr : pFeatures->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr });
    InitializeOutputStructPNext(pFeatures);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures2KHR(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(pProperties);

    OverrideGetPhysicalDeviceProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties2KHR, in_physicalDevice, pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkFormatProperties2* out_pFormatProperties = pFormatProperties->IsNull() ? nullptr : pFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(pFormatProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(in_physicalDevice, format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = pImageFormatInfo->GetPointer();
    VkImageFormatProperties2* out_pImageFormatProperties = pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(pImageFormatProperties);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(in_physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties2KHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pQueueFamilyPropertyCount = pQueueFamilyPropertyCount->IsNull() ? nullptr : pQueueFamilyPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties2KHR", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR, pQueueFamilyPropertyCount, pQueueFamilyProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkQueueFamilyProperties2* out_pQueueFamilyProperties = pQueueFamilyProperties->IsNull() ? nullptr : pQueueFamilyProperties->AllocateOutputData(*out_pQueueFamilyPropertyCount, VkQueueFamilyProperties2{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(in_physicalDevice, out_pQueueFamilyPropertyCount, out_pQueueFamilyProperties);

    if (pQueueFamilyProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR, *out_pQueueFamilyPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
    pMemoryProperties->IsNull() ? nullptr : pMemoryProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(pMemoryProperties);

    OverrideGetPhysicalDeviceMemoryProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties2KHR, in_physicalDevice, pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = pFormatInfo->GetPointer();
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties2KHR", VK_SUCCESS, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkSparseImageFormatProperties2* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkSparseImageFormatProperties2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(in_physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = pPeerMemoryFeatures->IsNull() ? nullptr : pPeerMemoryFeatures->AllocateOutputData(1, static_cast<VkPeerMemoryFeatureFlags>(0));

    GetDeviceTable(in_device)->GetDeviceGroupPeerMemoryFeaturesKHR(in_device, heapIndex, localDeviceIndex, remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDeviceMaskKHR(in_commandBuffer, deviceMask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDeviceMaskKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDeviceMaskKHR, in_commandBuffer, deviceMask);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDispatchBaseKHR(in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDispatchBaseKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdDispatchBaseKHR, in_commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanReplayConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkCommandPool in_commandPool = MapHandle<VulkanCommandPoolInfo>(commandPool, &CommonObjectInfoTable::GetVkCommandPoolInfo);

    GetDeviceTable(in_device)->TrimCommandPoolKHR(in_device, in_commandPool, flags);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    pPhysicalDeviceGroupCount->IsNull() ? nullptr : pPhysicalDeviceGroupCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanInstanceInfo>("vkEnumeratePhysicalDeviceGroupsKHR", returnValue, instance, kInstanceArrayEnumeratePhysicalDeviceGroupsKHR, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties, &CommonObjectInfoTable::GetVkInstanceInfo));
    SetStructArrayHandleLengths<Decoded_VkPhysicalDeviceGroupProperties>(pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength());
    if (!pPhysicalDeviceGroupProperties->IsNull()) { pPhysicalDeviceGroupProperties->AllocateOutputData(*pPhysicalDeviceGroupCount->GetOutputPointer(), VkPhysicalDeviceGroupProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, nullptr }); }

    VkResult replay_result = OverrideEnumeratePhysicalDeviceGroups(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDeviceGroupsKHR, returnValue, in_instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    CheckResult("vkEnumeratePhysicalDeviceGroupsKHR", returnValue, replay_result, call_info);

    if (pPhysicalDeviceGroupProperties->IsNull()) { SetOutputArrayCount<VulkanInstanceInfo>(instance, kInstanceArrayEnumeratePhysicalDeviceGroupsKHR, *pPhysicalDeviceGroupCount->GetOutputPointer(), &CommonObjectInfoTable::GetVkInstanceInfo); }
    AddStructArrayHandles<Decoded_VkPhysicalDeviceGroupProperties>(instance, pPhysicalDeviceGroupProperties->GetMetaStructPointer(), pPhysicalDeviceGroupProperties->GetLength(), pPhysicalDeviceGroupProperties->GetOutputPointer(), *pPhysicalDeviceGroupCount->GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = pExternalBufferInfo->GetPointer();
    VkExternalBufferProperties* out_pExternalBufferProperties = pExternalBufferProperties->IsNull() ? nullptr : pExternalBufferProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, nullptr });
    InitializeOutputStructPNext(pExternalBufferProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(in_physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = pGetWin32HandleInfo->GetPointer();
    MapStructHandles(pGetWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetMemoryWin32HandleKHR", returnValue, replay_result, call_info);

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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    HANDLE in_handle = static_cast<HANDLE>(PreProcessExternalObject(handle, format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR, "vkGetMemoryWin32HandlePropertiesKHR"));
    VkMemoryWin32HandlePropertiesKHR* out_pMemoryWin32HandleProperties = pMemoryWin32HandleProperties->IsNull() ? nullptr : pMemoryWin32HandleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR, nullptr });
    InitializeOutputStructPNext(pMemoryWin32HandleProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandlePropertiesKHR(in_device, handleType, in_handle, out_pMemoryWin32HandleProperties);
    CheckResult("vkGetMemoryWin32HandlePropertiesKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryGetFdInfoKHR* in_pGetFdInfo = pGetFdInfo->GetPointer();
    MapStructHandles(pGetFdInfo->GetMetaStructPointer(), GetObjectInfoTable());
    int* out_pFd = pFd->IsNull() ? nullptr : pFd->AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryFdKHR(in_device, in_pGetFdInfo, out_pFd);
    CheckResult("vkGetMemoryFdKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkMemoryFdPropertiesKHR* out_pMemoryFdProperties = pMemoryFdProperties->IsNull() ? nullptr : pMemoryFdProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR, nullptr });
    InitializeOutputStructPNext(pMemoryFdProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryFdPropertiesKHR(in_device, handleType, fd, out_pMemoryFdProperties);
    CheckResult("vkGetMemoryFdPropertiesKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = pExternalSemaphoreInfo->GetPointer();
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = pExternalSemaphoreProperties->IsNull() ? nullptr : pExternalSemaphoreProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, nullptr });
    InitializeOutputStructPNext(pExternalSemaphoreProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(in_physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

void VulkanReplayConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pImportSemaphoreWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideImportSemaphoreWin32HandleKHR(GetDeviceTable(in_device->handle)->ImportSemaphoreWin32HandleKHR, returnValue, in_device, pImportSemaphoreWin32HandleInfo);
    CheckResult("vkImportSemaphoreWin32HandleKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = pGetWin32HandleInfo->GetPointer();
    MapStructHandles(pGetWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetSemaphoreWin32HandleKHR", returnValue, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR, "vkGetSemaphoreWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pImportSemaphoreFdInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideImportSemaphoreFdKHR(GetDeviceTable(in_device->handle)->ImportSemaphoreFdKHR, returnValue, in_device, pImportSemaphoreFdInfo);
    CheckResult("vkImportSemaphoreFdKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pGetFdInfo->GetMetaStructPointer(), GetObjectInfoTable());
    pFd->IsNull() ? nullptr : pFd->AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = OverrideGetSemaphoreFdKHR(GetDeviceTable(in_device->handle)->GetSemaphoreFdKHR, returnValue, in_device, pGetFdInfo, pFd);
    CheckResult("vkGetSemaphoreFdKHR", returnValue, replay_result, call_info);
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipelineLayout in_layout = MapHandle<VulkanPipelineLayoutInfo>(layout, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);
    const VkWriteDescriptorSet* in_pDescriptorWrites = pDescriptorWrites->GetPointer();
    MapStructArrayHandles(pDescriptorWrites->GetMetaStructPointer(), pDescriptorWrites->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSetKHR(in_commandBuffer, pipelineBindPoint, in_layout, set, descriptorWriteCount, in_pDescriptorWrites);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPushDescriptorSetKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSetKHR, in_commandBuffer, pipelineBindPoint, in_layout, set, descriptorWriteCount, in_pDescriptorWrites);
    }
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pDescriptorUpdateTemplate->IsNull()) { pDescriptorUpdateTemplate->SetHandleLength(1); }
    VulkanDescriptorUpdateTemplateInfo handle_info;
    pDescriptorUpdateTemplate->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->CreateDescriptorUpdateTemplateKHR, returnValue, in_device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    CheckResult("vkCreateDescriptorUpdateTemplateKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanDescriptorUpdateTemplateInfo>(device, pDescriptorUpdateTemplate->GetPointer(), pDescriptorUpdateTemplate->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_descriptorUpdateTemplate = GetObjectInfoTable().GetVkDescriptorUpdateTemplateInfo(descriptorUpdateTemplate);

    OverrideDestroyDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->DestroyDescriptorUpdateTemplateKHR, in_device, in_descriptorUpdateTemplate, pAllocator);
    RemoveHandle(descriptorUpdateTemplate, &CommonObjectInfoTable::RemoveVkDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    if (!pRenderPass->IsNull()) { pRenderPass->SetHandleLength(1); }
    VulkanRenderPassInfo handle_info;
    pRenderPass->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateRenderPass2(GetDeviceTable(in_device->handle)->CreateRenderPass2KHR, returnValue, in_device, pCreateInfo, pAllocator, pRenderPass);
    CheckResult("vkCreateRenderPass2KHR", returnValue, replay_result, call_info);

    AddHandle<VulkanRenderPassInfo>(device, pRenderPass->GetPointer(), pRenderPass->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    MapStructHandles(pRenderPassBegin->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdBeginRenderPass2(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass2KHR, in_commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginRenderPass2KHR(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass2KHR, in_commandBuffer->handle, pRenderPassBegin, pSubpassBeginInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSubpassBeginInfo* in_pSubpassBeginInfo = pSubpassBeginInfo->GetPointer();
    const VkSubpassEndInfo* in_pSubpassEndInfo = pSubpassEndInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass2KHR(in_commandBuffer, in_pSubpassBeginInfo, in_pSubpassEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdNextSubpass2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdNextSubpass2KHR, in_commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSubpassEndInfo* in_pSubpassEndInfo = pSubpassEndInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndRenderPass2KHR(in_commandBuffer, in_pSubpassEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndRenderPass2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdEndRenderPass2KHR, in_commandBuffer, pSubpassEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetSwapchainStatusKHR for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainStatusKHR(in_device, in_swapchain);
    CheckResult("vkGetSwapchainStatusKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = pExternalFenceInfo->GetPointer();
    VkExternalFenceProperties* out_pExternalFenceProperties = pExternalFenceProperties->IsNull() ? nullptr : pExternalFenceProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, nullptr });
    InitializeOutputStructPNext(pExternalFenceProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(in_physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

void VulkanReplayConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImportFenceWin32HandleInfoKHR* in_pImportFenceWin32HandleInfo = pImportFenceWin32HandleInfo->GetPointer();
    MapStructHandles(pImportFenceWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ImportFenceWin32HandleKHR(in_device, in_pImportFenceWin32HandleInfo);
    CheckResult("vkImportFenceWin32HandleKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkFenceGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = pGetWin32HandleInfo->GetPointer();
    MapStructHandles(pGetWin32HandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetFenceWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetFenceWin32HandleKHR", returnValue, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*pHandle->GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR, "vkGetFenceWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImportFenceFdInfoKHR* in_pImportFenceFdInfo = pImportFenceFdInfo->GetPointer();
    MapStructHandles(pImportFenceFdInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ImportFenceFdKHR(in_device, in_pImportFenceFdInfo);
    CheckResult("vkImportFenceFdKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkFenceGetFdInfoKHR* in_pGetFdInfo = pGetFdInfo->GetPointer();
    MapStructHandles(pGetFdInfo->GetMetaStructPointer(), GetObjectInfoTable());
    int* out_pFd = pFd->IsNull() ? nullptr : pFd->AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetFenceFdKHR(in_device, in_pGetFdInfo, out_pFd);
    CheckResult("vkGetFenceFdKHR", returnValue, replay_result, call_info);
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
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pCounterCount = pCounterCount->IsNull() ? nullptr : pCounterCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", returnValue, physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, pCounterCount, pCounterDescriptions, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkPerformanceCounterKHR* out_pCounters = pCounters->IsNull() ? nullptr : pCounters->AllocateOutputData(*out_pCounterCount, VkPerformanceCounterKHR{ VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR, nullptr });
    VkPerformanceCounterDescriptionKHR* out_pCounterDescriptions = pCounterDescriptions->IsNull() ? nullptr : pCounterDescriptions->AllocateOutputData(*out_pCounterCount, VkPerformanceCounterDescriptionKHR{ VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(in_physicalDevice, queueFamilyIndex, out_pCounterCount, out_pCounters, out_pCounterDescriptions);
    CheckResult("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", returnValue, replay_result, call_info);

    if (pCounters->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, *out_pCounterCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    if (pCounterDescriptions->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, *out_pCounterCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    VkResult replay_result = OverrideAcquireProfilingLockKHR(GetDeviceTable(in_device->handle)->AcquireProfilingLockKHR, returnValue, in_device, pInfo);
    CheckResult("vkAcquireProfilingLockKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);

    GetDeviceTable(in_device)->ReleaseProfilingLockKHR(in_device);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceCapabilities2KHR for offscreen.");
        return;
    }
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);

    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    pSurfaceCapabilities->IsNull() ? nullptr : pSurfaceCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR, nullptr });
    InitializeOutputStructPNext(pSurfaceCapabilities);

    VkResult replay_result = OverrideGetPhysicalDeviceSurfaceCapabilities2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceCapabilities2KHR, returnValue, in_physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilities2KHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceFormats2KHR for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = pSurfaceInfo->GetPointer();
    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    uint32_t* out_pSurfaceFormatCount = pSurfaceFormatCount->IsNull() ? nullptr : pSurfaceFormatCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSurfaceFormats2KHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR, pSurfaceFormatCount, pSurfaceFormats, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkSurfaceFormat2KHR* out_pSurfaceFormats = pSurfaceFormats->IsNull() ? nullptr : pSurfaceFormats->AllocateOutputData(*out_pSurfaceFormatCount, VkSurfaceFormat2KHR{ VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(in_physicalDevice, in_pSurfaceInfo, out_pSurfaceFormatCount, out_pSurfaceFormats);
    CheckResult("vkGetPhysicalDeviceSurfaceFormats2KHR", returnValue, replay_result, call_info);

    if (pSurfaceFormats->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR, *out_pSurfaceFormatCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayProperties2KHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkDisplayProperties2KHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkDisplayProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayProperties2KHR", returnValue, replay_result, call_info);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayProperties2KHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkDisplayPlaneProperties2KHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkDisplayPlaneProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", returnValue, replay_result, call_info);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
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
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDisplayKHRInfo>("vkGetDisplayModeProperties2KHR", returnValue, display, kDisplayKHRArrayGetDisplayModeProperties2KHR, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkDisplayKHRInfo));
    VkDisplayModeProperties2KHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkDisplayModeProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayModeProperties2KHR(in_physicalDevice, in_display, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetDisplayModeProperties2KHR", returnValue, replay_result, call_info);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanDisplayKHRInfo>(display, kDisplayKHRArrayGetDisplayModeProperties2KHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkDisplayKHRInfo); }
    AddStructArrayHandles<Decoded_VkDisplayModeProperties2KHR>(physicalDevice, pProperties->GetMetaStructPointer(), pProperties->GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkDisplayPlaneInfo2KHR* in_pDisplayPlaneInfo = pDisplayPlaneInfo->GetPointer();
    MapStructHandles(pDisplayPlaneInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkDisplayPlaneCapabilities2KHR* out_pCapabilities = pCapabilities->IsNull() ? nullptr : pCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR, nullptr });
    InitializeOutputStructPNext(pCapabilities);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneCapabilities2KHR(in_physicalDevice, in_pDisplayPlaneInfo, out_pCapabilities);
    CheckResult("vkGetDisplayPlaneCapabilities2KHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImageMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetImageMemoryRequirements2KHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkBufferMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetBufferMemoryRequirements2KHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImageSparseMemoryRequirementsInfo2* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetImageSparseMemoryRequirements2KHR", VK_SUCCESS, device, kDeviceArrayGetImageSparseMemoryRequirements2KHR, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements2KHR(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(device, kDeviceArrayGetImageSparseMemoryRequirements2KHR, *out_pSparseMemoryRequirementCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSamplerYcbcrConversionCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pYcbcrConversion->IsNull()) { pYcbcrConversion->SetHandleLength(1); }
    VkSamplerYcbcrConversion* out_pYcbcrConversion = pYcbcrConversion->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateSamplerYcbcrConversionKHR(in_device, in_pCreateInfo, in_pAllocator, out_pYcbcrConversion);
    CheckResult("vkCreateSamplerYcbcrConversionKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanSamplerYcbcrConversionInfo>(device, pYcbcrConversion->GetPointer(), out_pYcbcrConversion, &CommonObjectInfoTable::AddVkSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSamplerYcbcrConversion in_ycbcrConversion = MapHandle<VulkanSamplerYcbcrConversionInfo>(ycbcrConversion, &CommonObjectInfoTable::GetVkSamplerYcbcrConversionInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroySamplerYcbcrConversionKHR(in_device, in_ycbcrConversion, in_pAllocator);
    RemoveHandle(ycbcrConversion, &CommonObjectInfoTable::RemoveVkSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindBufferMemory2(GetDeviceTable(in_device->handle)->BindBufferMemory2KHR, returnValue, in_device, bindInfoCount, pBindInfos);
    CheckResult("vkBindBufferMemory2KHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindImageMemory2(GetDeviceTable(in_device->handle)->BindImageMemory2KHR, returnValue, in_device, bindInfoCount, pBindInfos);
    CheckResult("vkBindImageMemory2KHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkDescriptorSetLayoutSupport* out_pSupport = pSupport->IsNull() ? nullptr : pSupport->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, nullptr });
    InitializeOutputStructPNext(pSupport);

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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCountKHR(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawIndirectCountKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCountKHR, in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(buffer), offset, GetObjectInfoTable().GetVkBufferInfo(countBuffer), countBufferOffset, maxDrawCount, stride);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCountKHR(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawIndexedIndirectCountKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCountKHR, in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(buffer), offset, GetObjectInfoTable().GetVkBufferInfo(countBuffer), countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayConsumer::Process_vkGetSemaphoreCounterValueKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSemaphore in_semaphore = MapHandle<VulkanSemaphoreInfo>(semaphore, &CommonObjectInfoTable::GetVkSemaphoreInfo);
    uint64_t* out_pValue = pValue->IsNull() ? nullptr : pValue->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreCounterValueKHR(in_device, in_semaphore, out_pValue);
    CheckResult("vkGetSemaphoreCounterValueKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreWaitInfo* in_pWaitInfo = pWaitInfo->GetPointer();
    MapStructHandles(pWaitInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->WaitSemaphoresKHR(in_device, in_pWaitInfo, timeout);
    CheckResult("vkWaitSemaphoresKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreSignalInfo* in_pSignalInfo = pSignalInfo->GetPointer();
    MapStructHandles(pSignalInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->SignalSemaphoreKHR(in_device, in_pSignalInfo);
    CheckResult("vkSignalSemaphoreKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pFragmentShadingRateCount = pFragmentShadingRateCount->IsNull() ? nullptr : pFragmentShadingRateCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceFragmentShadingRatesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR, pFragmentShadingRateCount, pFragmentShadingRates, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkPhysicalDeviceFragmentShadingRateKHR* out_pFragmentShadingRates = pFragmentShadingRates->IsNull() ? nullptr : pFragmentShadingRates->AllocateOutputData(*out_pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFragmentShadingRatesKHR(in_physicalDevice, out_pFragmentShadingRateCount, out_pFragmentShadingRates);
    CheckResult("vkGetPhysicalDeviceFragmentShadingRatesKHR", returnValue, replay_result, call_info);

    if (pFragmentShadingRates->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR, *out_pFragmentShadingRateCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkExtent2D* in_pFragmentSize = pFragmentSize->GetPointer();
    const VkFragmentShadingRateCombinerOpKHR* in_combinerOps = combinerOps->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetFragmentShadingRateKHR(in_commandBuffer, in_pFragmentSize, in_combinerOps);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetFragmentShadingRateKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdSetFragmentShadingRateKHR, in_commandBuffer, in_pFragmentSize, in_combinerOps);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfoKHR>* pLocationInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRenderingAttachmentLocationInfoKHR* in_pLocationInfo = pLocationInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetRenderingAttachmentLocationsKHR(in_commandBuffer, in_pLocationInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetRenderingAttachmentLocationsKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdSetRenderingAttachmentLocationsKHR, in_commandBuffer, in_pLocationInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfoKHR>* pInputAttachmentIndexInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRenderingInputAttachmentIndexInfoKHR* in_pInputAttachmentIndexInfo = pInputAttachmentIndexInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetRenderingInputAttachmentIndicesKHR(in_commandBuffer, in_pInputAttachmentIndexInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetRenderingInputAttachmentIndicesKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdSetRenderingInputAttachmentIndicesKHR, in_commandBuffer, in_pInputAttachmentIndexInfo);
    }
}

void VulkanReplayConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkWaitForPresentKHR for offscreen.");
        return;
    }
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_swapchain = GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain);

    VkResult replay_result = OverrideWaitForPresentKHR(GetDeviceTable(in_device->handle)->WaitForPresentKHR, returnValue, in_device, in_swapchain, presentId, timeout);
    CheckResult("vkWaitForPresentKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetBufferDeviceAddress(GetDeviceTable(in_device->handle)->GetBufferDeviceAddressKHR, returnValue, in_device, pInfo);
}

void VulkanReplayConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pDeferredOperation->IsNull()) { pDeferredOperation->SetHandleLength(1); }
    VkDeferredOperationKHR* out_pDeferredOperation = pDeferredOperation->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateDeferredOperationKHR(in_device, in_pAllocator, out_pDeferredOperation);
    CheckResult("vkCreateDeferredOperationKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanDeferredOperationKHRInfo>(device, pDeferredOperation->GetPointer(), out_pDeferredOperation, &CommonObjectInfoTable::AddVkDeferredOperationKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_operation = MapHandle<VulkanDeferredOperationKHRInfo>(operation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyDeferredOperationKHR(in_device, in_operation, in_pAllocator);
    RemoveHandle(operation, &CommonObjectInfoTable::RemoveVkDeferredOperationKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_operation = MapHandle<VulkanDeferredOperationKHRInfo>(operation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);

    GetDeviceTable(in_device)->GetDeferredOperationMaxConcurrencyKHR(in_device, in_operation);
}

void VulkanReplayConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_operation = MapHandle<VulkanDeferredOperationKHRInfo>(operation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);

    VkResult replay_result = GetDeviceTable(in_device)->GetDeferredOperationResultKHR(in_device, in_operation);
    CheckResult("vkGetDeferredOperationResultKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_operation = GetObjectInfoTable().GetVkDeferredOperationKHRInfo(operation);

    VkResult replay_result = OverrideDeferredOperationJoinKHR(GetDeviceTable(in_device->handle)->DeferredOperationJoinKHR, returnValue, in_device, in_operation);
    CheckResult("vkDeferredOperationJoinKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineInfoKHR* in_pPipelineInfo = pPipelineInfo->GetPointer();
    MapStructHandles(pPipelineInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pExecutableCount = pExecutableCount->IsNull() ? nullptr : pExecutableCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetPipelineExecutablePropertiesKHR", returnValue, device, kDeviceArrayGetPipelineExecutablePropertiesKHR, pExecutableCount, pProperties, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkPipelineExecutablePropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pExecutableCount, VkPipelineExecutablePropertiesKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutablePropertiesKHR(in_device, in_pPipelineInfo, out_pExecutableCount, out_pProperties);
    CheckResult("vkGetPipelineExecutablePropertiesKHR", returnValue, replay_result, call_info);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(device, kDeviceArrayGetPipelineExecutablePropertiesKHR, *out_pExecutableCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineExecutableInfoKHR* in_pExecutableInfo = pExecutableInfo->GetPointer();
    MapStructHandles(pExecutableInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pStatisticCount = pStatisticCount->IsNull() ? nullptr : pStatisticCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetPipelineExecutableStatisticsKHR", returnValue, device, kDeviceArrayGetPipelineExecutableStatisticsKHR, pStatisticCount, pStatistics, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkPipelineExecutableStatisticKHR* out_pStatistics = pStatistics->IsNull() ? nullptr : pStatistics->AllocateOutputData(*out_pStatisticCount, VkPipelineExecutableStatisticKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutableStatisticsKHR(in_device, in_pExecutableInfo, out_pStatisticCount, out_pStatistics);
    CheckResult("vkGetPipelineExecutableStatisticsKHR", returnValue, replay_result, call_info);

    if (pStatistics->IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(device, kDeviceArrayGetPipelineExecutableStatisticsKHR, *out_pStatisticCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineExecutableInfoKHR* in_pExecutableInfo = pExecutableInfo->GetPointer();
    MapStructHandles(pExecutableInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pInternalRepresentationCount = pInternalRepresentationCount->IsNull() ? nullptr : pInternalRepresentationCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetPipelineExecutableInternalRepresentationsKHR", returnValue, device, kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR, pInternalRepresentationCount, pInternalRepresentations, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkPipelineExecutableInternalRepresentationKHR* out_pInternalRepresentations = pInternalRepresentations->IsNull() ? nullptr : pInternalRepresentations->AllocateOutputData(*out_pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutableInternalRepresentationsKHR(in_device, in_pExecutableInfo, out_pInternalRepresentationCount, out_pInternalRepresentations);
    CheckResult("vkGetPipelineExecutableInternalRepresentationsKHR", returnValue, replay_result, call_info);

    if (pInternalRepresentations->IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(device, kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR, *out_pInternalRepresentationCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkMapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryMapInfoKHR>* pMemoryMapInfo,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryMapInfoKHR* in_pMemoryMapInfo = pMemoryMapInfo->GetPointer();
    MapStructHandles(pMemoryMapInfo->GetMetaStructPointer(), GetObjectInfoTable());
    void** out_ppData = ppData->IsNull() ? nullptr : ppData->AllocateOutputData(1);

    VkResult replay_result = GetDeviceTable(in_device)->MapMemory2KHR(in_device, in_pMemoryMapInfo, out_ppData);
    CheckResult("vkMapMemory2KHR", returnValue, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*ppData->GetPointer()), *ppData->GetOutputPointer(), format::ApiCallId::ApiCall_vkMapMemory2KHR, "vkMapMemory2KHR");
}

void VulkanReplayConsumer::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryUnmapInfoKHR>* pMemoryUnmapInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryUnmapInfoKHR* in_pMemoryUnmapInfo = pMemoryUnmapInfo->GetPointer();
    MapStructHandles(pMemoryUnmapInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->UnmapMemory2KHR(in_device, in_pMemoryUnmapInfo);
    CheckResult("vkUnmapMemory2KHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR>* pQualityLevelInfo,
    StructPointerDecoder<Decoded_VkVideoEncodeQualityLevelPropertiesKHR>* pQualityLevelProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* in_pQualityLevelInfo = pQualityLevelInfo->GetPointer();
    VkVideoEncodeQualityLevelPropertiesKHR* out_pQualityLevelProperties = pQualityLevelProperties->IsNull() ? nullptr : pQualityLevelProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR, nullptr });
    InitializeOutputStructPNext(pQualityLevelProperties);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(in_physicalDevice, in_pQualityLevelInfo, out_pQualityLevelProperties);
    CheckResult("vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetEncodedVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersGetInfoKHR>* pVideoSessionParametersInfo,
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR>* pFeedbackInfo,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkVideoEncodeSessionParametersGetInfoKHR* in_pVideoSessionParametersInfo = pVideoSessionParametersInfo->GetPointer();
    MapStructHandles(pVideoSessionParametersInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkVideoEncodeSessionParametersFeedbackInfoKHR* out_pFeedbackInfo = pFeedbackInfo->IsNull() ? nullptr : pFeedbackInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR, nullptr });
    InitializeOutputStructPNext(pFeedbackInfo);
    size_t* out_pDataSize = pDataSize->IsNull() ? nullptr : pDataSize->AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanDeviceInfo>("vkGetEncodedVideoSessionParametersKHR", returnValue, device, kDeviceArrayGetEncodedVideoSessionParametersKHR, pDataSize, pData, &CommonObjectInfoTable::GetVkDeviceInfo));
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(*out_pDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetEncodedVideoSessionParametersKHR(in_device, in_pVideoSessionParametersInfo, out_pFeedbackInfo, out_pDataSize, out_pData);
    CheckResult("vkGetEncodedVideoSessionParametersKHR", returnValue, replay_result, call_info);

    if (pData->IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(device, kDeviceArrayGetEncodedVideoSessionParametersKHR, *out_pDataSize, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVideoEncodeInfoKHR* in_pEncodeInfo = pEncodeInfo->GetPointer();
    MapStructHandles(pEncodeInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdEncodeVideoKHR(in_commandBuffer, in_pEncodeInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEncodeVideoKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdEncodeVideoKHR, in_commandBuffer, in_pEncodeInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkEvent in_event = MapHandle<VulkanEventInfo>(event, &CommonObjectInfoTable::GetVkEventInfo);
    const VkDependencyInfo* in_pDependencyInfo = pDependencyInfo->GetPointer();
    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetEvent2KHR(in_commandBuffer, in_event, in_pDependencyInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetEvent2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdSetEvent2KHR, in_commandBuffer, in_event, in_pDependencyInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkEvent in_event = MapHandle<VulkanEventInfo>(event, &CommonObjectInfoTable::GetVkEventInfo);

    GetDeviceTable(in_commandBuffer)->CmdResetEvent2KHR(in_commandBuffer, in_event, stageMask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdResetEvent2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdResetEvent2KHR, in_commandBuffer, in_event, stageMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkEvent* in_pEvents = MapHandles<VulkanEventInfo>(pEvents, eventCount, &CommonObjectInfoTable::GetVkEventInfo);
    const VkDependencyInfo* in_pDependencyInfos = pDependencyInfos->GetPointer();
    MapStructArrayHandles(pDependencyInfos->GetMetaStructPointer(), pDependencyInfos->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdWaitEvents2KHR(in_commandBuffer, eventCount, in_pEvents, in_pDependencyInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWaitEvents2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdWaitEvents2KHR, in_commandBuffer, eventCount, in_pEvents, in_pDependencyInfos);
    }
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    MapStructHandles(pDependencyInfo->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdPipelineBarrier2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier2KHR, in_commandBuffer, pDependencyInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPipelineBarrier2KHR(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier2KHR, in_commandBuffer->handle, pDependencyInfo->GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteTimestamp2KHR(in_commandBuffer, stage, in_queryPool, query);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWriteTimestamp2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdWriteTimestamp2KHR, in_commandBuffer, stage, in_queryPool, query);
    }
}

void VulkanReplayConsumer::Process_vkQueueSubmit2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    auto in_queue = GetObjectInfoTable().GetVkQueueInfo(queue);

    MapStructArrayHandles(pSubmits->GetMetaStructPointer(), pSubmits->GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(fence);

    VkResult replay_result = OverrideQueueSubmit2(GetDeviceTable(in_queue->handle)->QueueSubmit2KHR, returnValue, in_queue, submitCount, pSubmits, in_fence);
    CheckResult("vkQueueSubmit2KHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteBufferMarker2AMD(in_commandBuffer, stage, in_dstBuffer, dstOffset, marker);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWriteBufferMarker2AMD(call_info, GetDeviceTable(in_commandBuffer)->CmdWriteBufferMarker2AMD, in_commandBuffer, stage, in_dstBuffer, dstOffset, marker);
    }
}

void VulkanReplayConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(queue, &CommonObjectInfoTable::GetVkQueueInfo);
    uint32_t* out_pCheckpointDataCount = pCheckpointDataCount->IsNull() ? nullptr : pCheckpointDataCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanQueueInfo>("vkGetQueueCheckpointData2NV", VK_SUCCESS, queue, kQueueArrayGetQueueCheckpointData2NV, pCheckpointDataCount, pCheckpointData, &CommonObjectInfoTable::GetVkQueueInfo));
    VkCheckpointData2NV* out_pCheckpointData = pCheckpointData->IsNull() ? nullptr : pCheckpointData->AllocateOutputData(*out_pCheckpointDataCount, VkCheckpointData2NV{ VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV, nullptr });

    GetDeviceTable(in_queue)->GetQueueCheckpointData2NV(in_queue, out_pCheckpointDataCount, out_pCheckpointData);

    if (pCheckpointData->IsNull()) { SetOutputArrayCount<VulkanQueueInfo>(queue, kQueueArrayGetQueueCheckpointData2NV, *out_pCheckpointDataCount, &CommonObjectInfoTable::GetVkQueueInfo); }
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyBufferInfo2* in_pCopyBufferInfo = pCopyBufferInfo->GetPointer();
    MapStructHandles(pCopyBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyBuffer2KHR(in_commandBuffer, in_pCopyBufferInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyBuffer2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyBuffer2KHR, in_commandBuffer, in_pCopyBufferInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyImageInfo2* in_pCopyImageInfo = pCopyImageInfo->GetPointer();
    MapStructHandles(pCopyImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyImage2KHR(in_commandBuffer, in_pCopyImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyImage2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyImage2KHR, in_commandBuffer, in_pCopyImageInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyBufferToImageInfo2* in_pCopyBufferToImageInfo = pCopyBufferToImageInfo->GetPointer();
    MapStructHandles(pCopyBufferToImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage2KHR(in_commandBuffer, in_pCopyBufferToImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyBufferToImage2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage2KHR, in_commandBuffer, in_pCopyBufferToImageInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyImageToBufferInfo2* in_pCopyImageToBufferInfo = pCopyImageToBufferInfo->GetPointer();
    MapStructHandles(pCopyImageToBufferInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer2KHR(in_commandBuffer, in_pCopyImageToBufferInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyImageToBuffer2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer2KHR, in_commandBuffer, in_pCopyImageToBufferInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBlitImageInfo2* in_pBlitImageInfo = pBlitImageInfo->GetPointer();
    MapStructHandles(pBlitImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBlitImage2KHR(in_commandBuffer, in_pBlitImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBlitImage2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdBlitImage2KHR, in_commandBuffer, in_pBlitImageInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkResolveImageInfo2* in_pResolveImageInfo = pResolveImageInfo->GetPointer();
    MapStructHandles(pResolveImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdResolveImage2KHR(in_commandBuffer, in_pResolveImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdResolveImage2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdResolveImage2KHR, in_commandBuffer, in_pResolveImageInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdTraceRaysIndirect2KHR(in_commandBuffer, indirectDeviceAddress);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdTraceRaysIndirect2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdTraceRaysIndirect2KHR, in_commandBuffer, indirectDeviceAddress);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceBufferMemoryRequirements* in_pInfo = pInfo->GetPointer();
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetDeviceBufferMemoryRequirementsKHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetDeviceImageMemoryRequirementsKHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = pSparseMemoryRequirementCount->IsNull() ? nullptr : pSparseMemoryRequirementCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetDeviceImageSparseMemoryRequirementsKHR", VK_SUCCESS, device, kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR, pSparseMemoryRequirementCount, pSparseMemoryRequirements, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = pSparseMemoryRequirements->IsNull() ? nullptr : pSparseMemoryRequirements->AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetDeviceImageSparseMemoryRequirementsKHR(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (pSparseMemoryRequirements->IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(device, kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR, *out_pSparseMemoryRequirementCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindIndexBuffer2KHR(in_commandBuffer, in_buffer, offset, size, indexType);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindIndexBuffer2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdBindIndexBuffer2KHR, in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(buffer), offset, size, indexType);
    }
}

void VulkanReplayConsumer::Process_vkGetRenderingAreaGranularityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingAreaInfoKHR>* pRenderingAreaInfo,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkRenderingAreaInfoKHR* in_pRenderingAreaInfo = pRenderingAreaInfo->GetPointer();
    VkExtent2D* out_pGranularity = pGranularity->IsNull() ? nullptr : pGranularity->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetRenderingAreaGranularityKHR(in_device, in_pRenderingAreaInfo, out_pGranularity);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageSubresourceLayoutKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageSubresourceInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkSubresourceLayout2KHR* out_pLayout = pLayout->IsNull() ? nullptr : pLayout->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR, nullptr });
    InitializeOutputStructPNext(pLayout);

    GetDeviceTable(in_device)->GetDeviceImageSubresourceLayoutKHR(in_device, in_pInfo, out_pLayout);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(image, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageSubresource2KHR* in_pSubresource = pSubresource->GetPointer();
    VkSubresourceLayout2KHR* out_pLayout = pLayout->IsNull() ? nullptr : pLayout->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR, nullptr });
    InitializeOutputStructPNext(pLayout);

    GetDeviceTable(in_device)->GetImageSubresourceLayout2KHR(in_device, in_image, in_pSubresource, out_pLayout);
}

void VulkanReplayConsumer::Process_vkCreatePipelineBinariesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineBinaryCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    StructPointerDecoder<Decoded_VkPipelineBinaryHandlesInfoKHR>* pBinaries)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineBinaryCreateInfoKHR* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    SetStructArrayHandleLengths<Decoded_VkPipelineBinaryHandlesInfoKHR>(pBinaries->GetMetaStructPointer(), pBinaries->GetLength());
    VkPipelineBinaryHandlesInfoKHR* out_pBinaries = pBinaries->IsNull() ? nullptr : pBinaries->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR, nullptr });
    InitializeOutputStructPNext(pBinaries);

    VkResult replay_result = GetDeviceTable(in_device)->CreatePipelineBinariesKHR(in_device, in_pCreateInfo, in_pAllocator, out_pBinaries);
    CheckResult("vkCreatePipelineBinariesKHR", returnValue, replay_result, call_info);

    AddStructArrayHandles<Decoded_VkPipelineBinaryHandlesInfoKHR>(device, pBinaries->GetMetaStructPointer(), pBinaries->GetLength(), out_pBinaries, pBinaries->GetLength(), &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkDestroyPipelineBinaryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineBinary,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipelineBinaryKHR in_pipelineBinary = MapHandle<VulkanPipelineBinaryKHRInfo>(pipelineBinary, &CommonObjectInfoTable::GetVkPipelineBinaryKHRInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPipelineBinaryKHR(in_device, in_pipelineBinary, in_pAllocator);
    RemoveHandle(pipelineBinary, &CommonObjectInfoTable::RemoveVkPipelineBinaryKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPipelineKeyKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCreateInfoKHR>* pPipelineCreateInfo,
    StructPointerDecoder<Decoded_VkPipelineBinaryKeyKHR>* pPipelineKey)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineCreateInfoKHR* in_pPipelineCreateInfo = pPipelineCreateInfo->GetPointer();
    VkPipelineBinaryKeyKHR* out_pPipelineKey = pPipelineKey->IsNull() ? nullptr : pPipelineKey->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR, nullptr });
    InitializeOutputStructPNext(pPipelineKey);

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineKeyKHR(in_device, in_pPipelineCreateInfo, out_pPipelineKey);
    CheckResult("vkGetPipelineKeyKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPipelineBinaryDataKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineBinaryDataInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkPipelineBinaryKeyKHR>* pPipelineBinaryKey,
    PointerDecoder<size_t>*                     pPipelineBinaryDataSize,
    PointerDecoder<uint8_t>*                    pPipelineBinaryData)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineBinaryDataInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkPipelineBinaryKeyKHR* out_pPipelineBinaryKey = pPipelineBinaryKey->IsNull() ? nullptr : pPipelineBinaryKey->AllocateOutputData(1, { VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR, nullptr });
    InitializeOutputStructPNext(pPipelineBinaryKey);
    size_t* out_pPipelineBinaryDataSize = pPipelineBinaryDataSize->IsNull() ? nullptr : pPipelineBinaryDataSize->AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanDeviceInfo>("vkGetPipelineBinaryDataKHR", returnValue, device, kDeviceArrayGetPipelineBinaryDataKHR, pPipelineBinaryDataSize, pPipelineBinaryData, &CommonObjectInfoTable::GetVkDeviceInfo));
    void* out_pPipelineBinaryData = pPipelineBinaryData->IsNull() ? nullptr : pPipelineBinaryData->AllocateOutputData(*out_pPipelineBinaryDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineBinaryDataKHR(in_device, in_pInfo, out_pPipelineBinaryKey, out_pPipelineBinaryDataSize, out_pPipelineBinaryData);
    CheckResult("vkGetPipelineBinaryDataKHR", returnValue, replay_result, call_info);

    if (pPipelineBinaryData->IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(device, kDeviceArrayGetPipelineBinaryDataKHR, *out_pPipelineBinaryDataSize, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkReleaseCapturedPipelineDataKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseCapturedPipelineDataInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkReleaseCapturedPipelineDataInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    VkResult replay_result = GetDeviceTable(in_device)->ReleaseCapturedPipelineDataKHR(in_device, in_pInfo, in_pAllocator);
    CheckResult("vkReleaseCapturedPipelineDataKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesKHR>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesKHR, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkCooperativeMatrixPropertiesKHR* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkCooperativeMatrixPropertiesKHR{ VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR", returnValue, replay_result, call_info);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesKHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineStippleKHR(in_commandBuffer, lineStippleFactor, lineStipplePattern);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetLineStippleKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdSetLineStippleKHR, in_commandBuffer, lineStippleFactor, lineStipplePattern);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainKHR>*            pTimeDomains)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pTimeDomainCount = pTimeDomainCount->IsNull() ? nullptr : pTimeDomainCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCalibrateableTimeDomainsKHR", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsKHR, pTimeDomainCount, pTimeDomains, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkTimeDomainKHR* out_pTimeDomains = pTimeDomains->IsNull() ? nullptr : pTimeDomains->AllocateOutputData(*out_pTimeDomainCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsKHR(in_physicalDevice, out_pTimeDomainCount, out_pTimeDomains);
    CheckResult("vkGetPhysicalDeviceCalibrateableTimeDomainsKHR", returnValue, replay_result, call_info);

    if (pTimeDomains->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsKHR, *out_pTimeDomainCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetCalibratedTimestampsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCalibratedTimestampInfoKHR* in_pTimestampInfos = pTimestampInfos->GetPointer();
    uint64_t* out_pTimestamps = pTimestamps->IsNull() ? nullptr : pTimestamps->AllocateOutputData(timestampCount);
    uint64_t* out_pMaxDeviation = pMaxDeviation->IsNull() ? nullptr : pMaxDeviation->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetCalibratedTimestampsKHR(in_device, timestampCount, in_pTimestampInfos, out_pTimestamps, out_pMaxDeviation);
    CheckResult("vkGetCalibratedTimestampsKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfoKHR>* pBindDescriptorSetsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBindDescriptorSetsInfoKHR* in_pBindDescriptorSetsInfo = pBindDescriptorSetsInfo->GetPointer();
    MapStructHandles(pBindDescriptorSetsInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBindDescriptorSets2KHR(in_commandBuffer, in_pBindDescriptorSetsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindDescriptorSets2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdBindDescriptorSets2KHR, in_commandBuffer, in_pBindDescriptorSetsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushConstantsInfoKHR>* pPushConstantsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPushConstantsInfoKHR* in_pPushConstantsInfo = pPushConstantsInfo->GetPointer();
    MapStructHandles(pPushConstantsInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPushConstants2KHR(in_commandBuffer, in_pPushConstantsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPushConstants2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdPushConstants2KHR, in_commandBuffer, in_pPushConstantsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfoKHR>* pPushDescriptorSetInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPushDescriptorSetInfoKHR* in_pPushDescriptorSetInfo = pPushDescriptorSetInfo->GetPointer();
    MapStructHandles(pPushDescriptorSetInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSet2KHR(in_commandBuffer, in_pPushDescriptorSetInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPushDescriptorSet2KHR(call_info, GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSet2KHR, in_commandBuffer, in_pPushDescriptorSetInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT>* pSetDescriptorBufferOffsetsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSetDescriptorBufferOffsetsInfoEXT* in_pSetDescriptorBufferOffsetsInfo = pSetDescriptorBufferOffsetsInfo->GetPointer();
    MapStructHandles(pSetDescriptorBufferOffsetsInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetDescriptorBufferOffsets2EXT(in_commandBuffer, in_pSetDescriptorBufferOffsetsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDescriptorBufferOffsets2EXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDescriptorBufferOffsets2EXT, in_commandBuffer, in_pSetDescriptorBufferOffsetsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT>* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* in_pBindDescriptorBufferEmbeddedSamplersInfo = pBindDescriptorBufferEmbeddedSamplersInfo->GetPointer();
    MapStructHandles(pBindDescriptorBufferEmbeddedSamplersInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBindDescriptorBufferEmbeddedSamplers2EXT(in_commandBuffer, in_pBindDescriptorBufferEmbeddedSamplersInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(call_info, GetDeviceTable(in_commandBuffer)->CmdBindDescriptorBufferEmbeddedSamplers2EXT, in_commandBuffer, in_pBindDescriptorBufferEmbeddedSamplersInfo);
    }
}

void VulkanReplayConsumer::Process_vkFrameBoundaryANDROID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    format::HandleId                            image)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_semaphore = GetObjectInfoTable().GetVkSemaphoreInfo(semaphore);
    auto in_image = GetObjectInfoTable().GetVkImageInfo(image);

    OverrideFrameBoundaryANDROID(GetDeviceTable(in_device->handle)->FrameBoundaryANDROID, in_device, in_semaphore, in_image);
}

void VulkanReplayConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    if (!pCallback->IsNull()) { pCallback->SetHandleLength(1); }
    VulkanDebugReportCallbackEXTInfo handle_info;
    pCallback->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDebugReportCallbackEXT(GetInstanceTable(in_instance->handle)->CreateDebugReportCallbackEXT, returnValue, in_instance, pCreateInfo, pAllocator, pCallback);
    CheckResult("vkCreateDebugReportCallbackEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanDebugReportCallbackEXTInfo>(instance, pCallback->GetPointer(), pCallback->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDebugReportCallbackEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    VkDebugReportCallbackEXT in_callback = MapHandle<VulkanDebugReportCallbackEXTInfo>(callback, &CommonObjectInfoTable::GetVkDebugReportCallbackEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetInstanceTable(in_instance)->DestroyDebugReportCallbackEXT(in_instance, in_callback, in_pAllocator);
    RemoveHandle(callback, &CommonObjectInfoTable::RemoveVkDebugReportCallbackEXTInfo);
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
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDebugMarkerObjectTagInfoEXT* in_pTagInfo = pTagInfo->GetPointer();
    MapStructHandles(pTagInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->DebugMarkerSetObjectTagEXT(in_device, in_pTagInfo);
    CheckResult("vkDebugMarkerSetObjectTagEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDebugMarkerObjectNameInfoEXT* in_pNameInfo = pNameInfo->GetPointer();
    MapStructHandles(pNameInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->DebugMarkerSetObjectNameEXT(in_device, in_pNameInfo);
    CheckResult("vkDebugMarkerSetObjectNameEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDebugMarkerMarkerInfoEXT* in_pMarkerInfo = pMarkerInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDebugMarkerBeginEXT(in_commandBuffer, in_pMarkerInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDebugMarkerBeginEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdDebugMarkerBeginEXT, in_commandBuffer, in_pMarkerInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDebugMarkerEndEXT(in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDebugMarkerEndEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdDebugMarkerEndEXT, in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    OverrideCmdDebugMarkerInsertEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDebugMarkerInsertEXT, in_commandBuffer, pMarkerInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDebugMarkerInsertEXT(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdDebugMarkerInsertEXT, in_commandBuffer->handle, pMarkerInfo->GetPointer());
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<VulkanBufferInfo>(pBuffers, bindingCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pOffsets = pOffsets->GetPointer();
    const VkDeviceSize* in_pSizes = pSizes->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindTransformFeedbackBuffersEXT(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets, in_pSizes);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindTransformFeedbackBuffersEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdBindTransformFeedbackBuffersEXT, in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets, in_pSizes);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pCounterBuffers = MapHandles<VulkanBufferInfo>(pCounterBuffers, counterBufferCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pCounterBufferOffsets = pCounterBufferOffsets->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBeginTransformFeedbackEXT(in_commandBuffer, firstCounterBuffer, counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginTransformFeedbackEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdBeginTransformFeedbackEXT, in_commandBuffer, firstCounterBuffer, counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pCounterBuffers = MapHandles<VulkanBufferInfo>(pCounterBuffers, counterBufferCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pCounterBufferOffsets = pCounterBufferOffsets->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndTransformFeedbackEXT(in_commandBuffer, firstCounterBuffer, counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndTransformFeedbackEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdEndTransformFeedbackEXT, in_commandBuffer, firstCounterBuffer, counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdBeginQueryIndexedEXT(in_commandBuffer, in_queryPool, query, flags, index);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginQueryIndexedEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdBeginQueryIndexedEXT, in_commandBuffer, in_queryPool, query, flags, index);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndQueryIndexedEXT(in_commandBuffer, in_queryPool, query, index);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndQueryIndexedEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdEndQueryIndexedEXT, in_commandBuffer, in_queryPool, query, index);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_counterBuffer = MapHandle<VulkanBufferInfo>(counterBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectByteCountEXT(in_commandBuffer, instanceCount, firstInstance, in_counterBuffer, counterBufferOffset, counterOffset, vertexStride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawIndirectByteCountEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawIndirectByteCountEXT, in_commandBuffer, instanceCount, firstInstance, in_counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    }
}

void VulkanReplayConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImageView in_imageView = MapHandle<VulkanImageViewInfo>(imageView, &CommonObjectInfoTable::GetVkImageViewInfo);
    VkImageViewAddressPropertiesNVX* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX, nullptr });
    InitializeOutputStructPNext(pProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetImageViewAddressNVX(in_device, in_imageView, out_pProperties);
    CheckResult("vkGetImageViewAddressNVX", returnValue, replay_result, call_info);
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCountAMD(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawIndirectCountAMD(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCountAMD, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCountAMD(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawIndexedIndirectCountAMD(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCountAMD, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
    }
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);
    size_t* out_pInfoSize = pInfoSize->IsNull() ? nullptr : pInfoSize->AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanPipelineInfo>("vkGetShaderInfoAMD", returnValue, pipeline, kPipelineArrayGetShaderInfoAMD, pInfoSize, pInfo, &CommonObjectInfoTable::GetVkPipelineInfo));
    void* out_pInfo = pInfo->IsNull() ? nullptr : pInfo->AllocateOutputData(*out_pInfoSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetShaderInfoAMD(in_device, in_pipeline, shaderStage, infoType, out_pInfoSize, out_pInfo);
    CheckResult("vkGetShaderInfoAMD", returnValue, replay_result, call_info);

    if (pInfo->IsNull()) { SetOutputArrayCount<VulkanPipelineInfo>(pipeline, kPipelineArrayGetShaderInfoAMD, *out_pInfoSize, &CommonObjectInfoTable::GetVkPipelineInfo); }
}

void VulkanReplayConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkStreamDescriptorSurfaceCreateInfoGGP* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateStreamDescriptorSurfaceGGP(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateStreamDescriptorSurfaceGGP", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
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
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkExternalImageFormatPropertiesNV* out_pExternalImageFormatProperties = pExternalImageFormatProperties->IsNull() ? nullptr : pExternalImageFormatProperties->AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(in_physicalDevice, format, type, tiling, usage, flags, externalHandleType, out_pExternalImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceExternalImageFormatPropertiesNV", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeviceMemory in_memory = MapHandle<VulkanDeviceMemoryInfo>(memory, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);
    HANDLE* out_pHandle = pHandle->IsNull() ? nullptr : reinterpret_cast<HANDLE*>(pHandle->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandleNV(in_device, in_memory, handleType, out_pHandle);
    CheckResult("vkGetMemoryWin32HandleNV", returnValue, replay_result, call_info);

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
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkViSurfaceCreateInfoNN* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateViSurfaceNN(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateViSurfaceNN", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkConditionalRenderingBeginInfoEXT* in_pConditionalRenderingBegin = pConditionalRenderingBegin->GetPointer();
    MapStructHandles(pConditionalRenderingBegin->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginConditionalRenderingEXT(in_commandBuffer, in_pConditionalRenderingBegin);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginConditionalRenderingEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdBeginConditionalRenderingEXT, in_commandBuffer, in_pConditionalRenderingBegin);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndConditionalRenderingEXT(in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndConditionalRenderingEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdEndConditionalRenderingEXT, in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkViewportWScalingNV* in_pViewportWScalings = pViewportWScalings->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWScalingNV(in_commandBuffer, firstViewport, viewportCount, in_pViewportWScalings);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetViewportWScalingNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetViewportWScalingNV, in_commandBuffer, firstViewport, viewportCount, in_pViewportWScalings);
    }
}

void VulkanReplayConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->ReleaseDisplayEXT(in_physicalDevice, in_display);
    CheckResult("vkReleaseDisplayEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT, "vkAcquireXlibDisplayEXT"));
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->AcquireXlibDisplayEXT(in_physicalDevice, in_dpy, in_display);
    CheckResult("vkAcquireXlibDisplayEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(dpy, format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT, "vkGetRandROutputDisplayEXT"));
    if (!pDisplay->IsNull()) { pDisplay->SetHandleLength(1); }
    VulkanDisplayKHRInfo handle_info;
    pDisplay->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideGetRandROutputDisplayEXT(GetInstanceTable(in_physicalDevice->handle)->GetRandROutputDisplayEXT, returnValue, in_physicalDevice, in_dpy, rrOutput, pDisplay);
    CheckResult("vkGetRandROutputDisplayEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanDisplayKHRInfo>(physicalDevice, pDisplay->GetPointer(), pDisplay->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceCapabilities2EXT for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(surface)->surface_creation_skipped) { return; }
    VkSurfaceCapabilities2EXT* out_pSurfaceCapabilities = pSurfaceCapabilities->IsNull() ? nullptr : pSurfaceCapabilities->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT, nullptr });
    InitializeOutputStructPNext(pSurfaceCapabilities);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(in_physicalDevice, in_surface, out_pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilities2EXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    const VkDisplayPowerInfoEXT* in_pDisplayPowerInfo = pDisplayPowerInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->DisplayPowerControlEXT(in_device, in_display, in_pDisplayPowerInfo);
    CheckResult("vkDisplayPowerControlEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceEventInfoEXT* in_pDeviceEventInfo = pDeviceEventInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pFence->IsNull()) { pFence->SetHandleLength(1); }
    VkFence* out_pFence = pFence->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->RegisterDeviceEventEXT(in_device, in_pDeviceEventInfo, in_pAllocator, out_pFence);
    CheckResult("vkRegisterDeviceEventEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanFenceInfo>(device, pFence->GetPointer(), out_pFence, &CommonObjectInfoTable::AddVkFenceInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    const VkDisplayEventInfoEXT* in_pDisplayEventInfo = pDisplayEventInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pFence->IsNull()) { pFence->SetHandleLength(1); }
    VkFence* out_pFence = pFence->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->RegisterDisplayEventEXT(in_device, in_display, in_pDisplayEventInfo, in_pAllocator, out_pFence);
    CheckResult("vkRegisterDisplayEventEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanFenceInfo>(device, pFence->GetPointer(), out_pFence, &CommonObjectInfoTable::AddVkFenceInfo);
}

void VulkanReplayConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetSwapchainCounterEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }
    uint64_t* out_pCounterValue = pCounterValue->IsNull() ? nullptr : pCounterValue->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainCounterEXT(in_device, in_swapchain, counter, out_pCounterValue);
    CheckResult("vkGetSwapchainCounterEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetRefreshCycleDurationGOOGLE for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }
    VkRefreshCycleDurationGOOGLE* out_pDisplayTimingProperties = pDisplayTimingProperties->IsNull() ? nullptr : pDisplayTimingProperties->AllocateOutputData(1);

    VkResult replay_result = GetDeviceTable(in_device)->GetRefreshCycleDurationGOOGLE(in_device, in_swapchain, out_pDisplayTimingProperties);
    CheckResult("vkGetRefreshCycleDurationGOOGLE", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPastPresentationTimingGOOGLE for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }
    uint32_t* out_pPresentationTimingCount = pPresentationTimingCount->IsNull() ? nullptr : pPresentationTimingCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanSwapchainKHRInfo>("vkGetPastPresentationTimingGOOGLE", returnValue, swapchain, kSwapchainKHRArrayGetPastPresentationTimingGOOGLE, pPresentationTimingCount, pPresentationTimings, &CommonObjectInfoTable::GetVkSwapchainKHRInfo));
    VkPastPresentationTimingGOOGLE* out_pPresentationTimings = pPresentationTimings->IsNull() ? nullptr : pPresentationTimings->AllocateOutputData(*out_pPresentationTimingCount);

    VkResult replay_result = GetDeviceTable(in_device)->GetPastPresentationTimingGOOGLE(in_device, in_swapchain, out_pPresentationTimingCount, out_pPresentationTimings);
    CheckResult("vkGetPastPresentationTimingGOOGLE", returnValue, replay_result, call_info);

    if (pPresentationTimings->IsNull()) { SetOutputArrayCount<VulkanSwapchainKHRInfo>(swapchain, kSwapchainKHRArrayGetPastPresentationTimingGOOGLE, *out_pPresentationTimingCount, &CommonObjectInfoTable::GetVkSwapchainKHRInfo); }
}

void VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRect2D* in_pDiscardRectangles = pDiscardRectangles->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleEXT(in_commandBuffer, firstDiscardRectangle, discardRectangleCount, in_pDiscardRectangles);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDiscardRectangleEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleEXT, in_commandBuffer, firstDiscardRectangle, discardRectangleCount, in_pDiscardRectangles);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleEnableEXT(in_commandBuffer, discardRectangleEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDiscardRectangleEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleEnableEXT, in_commandBuffer, discardRectangleEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleModeEXT(in_commandBuffer, discardRectangleMode);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDiscardRectangleModeEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleModeEXT, in_commandBuffer, discardRectangleMode);
    }
}

void VulkanReplayConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkSetHdrMetadataEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSwapchainKHR* in_pSwapchains = MapHandles<VulkanSwapchainKHRInfo>(pSwapchains, swapchainCount, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
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
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkIOSSurfaceCreateInfoMVK* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateIOSSurfaceMVK(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateIOSSurfaceMVK", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkMacOSSurfaceCreateInfoMVK* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateMacOSSurfaceMVK(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateMacOSSurfaceMVK", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDebugUtilsObjectNameInfoEXT* in_pNameInfo = pNameInfo->GetPointer();
    MapStructHandles(pNameInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VulkanDeviceInfo* device_info     = GetObjectInfoTable().GetVkDeviceInfo(device);
    VkPhysicalDevice  physical_device = device_info->parent;

    VkResult replay_result = GetInstanceTable(physical_device)->SetDebugUtilsObjectNameEXT(in_device, in_pNameInfo);
    CheckResult("vkSetDebugUtilsObjectNameEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDebugUtilsObjectTagInfoEXT* in_pTagInfo = pTagInfo->GetPointer();
    MapStructHandles(pTagInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VulkanDeviceInfo* device_info     = GetObjectInfoTable().GetVkDeviceInfo(device);
    VkPhysicalDevice  physical_device = device_info->parent;

    VkResult replay_result = GetInstanceTable(physical_device)->SetDebugUtilsObjectTagEXT(in_device, in_pTagInfo);
    CheckResult("vkSetDebugUtilsObjectTagEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(queue, &CommonObjectInfoTable::GetVkQueueInfo);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo->GetPointer();

    GetDeviceTable(in_queue)->QueueBeginDebugUtilsLabelEXT(in_queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(queue, &CommonObjectInfoTable::GetVkQueueInfo);

    GetDeviceTable(in_queue)->QueueEndDebugUtilsLabelEXT(in_queue);
}

void VulkanReplayConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(queue, &CommonObjectInfoTable::GetVkQueueInfo);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo->GetPointer();

    GetDeviceTable(in_queue)->QueueInsertDebugUtilsLabelEXT(in_queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = pLabelInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBeginDebugUtilsLabelEXT(in_commandBuffer, in_pLabelInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBeginDebugUtilsLabelEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdBeginDebugUtilsLabelEXT, in_commandBuffer, in_pLabelInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndDebugUtilsLabelEXT(in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdEndDebugUtilsLabelEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdEndDebugUtilsLabelEXT, in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    OverrideCmdInsertDebugUtilsLabelEXT(GetDeviceTable(in_commandBuffer->handle)->CmdInsertDebugUtilsLabelEXT, in_commandBuffer, pLabelInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdInsertDebugUtilsLabelEXT(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdInsertDebugUtilsLabelEXT, in_commandBuffer->handle, pLabelInfo->GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    if (!pMessenger->IsNull()) { pMessenger->SetHandleLength(1); }
    VulkanDebugUtilsMessengerEXTInfo handle_info;
    pMessenger->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateDebugUtilsMessengerEXT(GetInstanceTable(in_instance->handle)->CreateDebugUtilsMessengerEXT, returnValue, in_instance, pCreateInfo, pAllocator, pMessenger);
    CheckResult("vkCreateDebugUtilsMessengerEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanDebugUtilsMessengerEXTInfo>(instance, pMessenger->GetPointer(), pMessenger->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDebugUtilsMessengerEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    VkDebugUtilsMessengerEXT in_messenger = MapHandle<VulkanDebugUtilsMessengerEXTInfo>(messenger, &CommonObjectInfoTable::GetVkDebugUtilsMessengerEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetInstanceTable(in_instance)->DestroyDebugUtilsMessengerEXT(in_instance, in_messenger, in_pAllocator);
    RemoveHandle(messenger, &CommonObjectInfoTable::RemoveVkDebugUtilsMessengerEXTInfo);
}

void VulkanReplayConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    const struct AHardwareBuffer* in_buffer = static_cast<const struct AHardwareBuffer*>(PreProcessExternalObject(buffer, format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID, "vkGetAndroidHardwareBufferPropertiesANDROID"));
    pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID, nullptr });
    InitializeOutputStructPNext(pProperties);

    VkResult replay_result = OverrideGetAndroidHardwareBufferPropertiesANDROID(GetDeviceTable(in_device->handle)->GetAndroidHardwareBufferPropertiesANDROID, returnValue, in_device, in_buffer, pProperties);
    CheckResult("vkGetAndroidHardwareBufferPropertiesANDROID", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    struct AHardwareBuffer** out_pBuffer = pBuffer->IsNull() ? nullptr : reinterpret_cast<struct AHardwareBuffer**>(pBuffer->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryAndroidHardwareBufferANDROID(in_device, in_pInfo, out_pBuffer);
    CheckResult("vkGetMemoryAndroidHardwareBufferANDROID", returnValue, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*pBuffer->GetPointer()), static_cast<void*>(*out_pBuffer), format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID, "vkGetMemoryAndroidHardwareBufferANDROID");
}

void VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSampleLocationsInfoEXT* in_pSampleLocationsInfo = pSampleLocationsInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetSampleLocationsEXT(in_commandBuffer, in_pSampleLocationsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetSampleLocationsEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetSampleLocationsEXT, in_commandBuffer, in_pSampleLocationsInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkMultisamplePropertiesEXT* out_pMultisampleProperties = pMultisampleProperties->IsNull() ? nullptr : pMultisampleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT, nullptr });
    InitializeOutputStructPNext(pMultisampleProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(in_physicalDevice, samples, out_pMultisampleProperties);
}

void VulkanReplayConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(image, &CommonObjectInfoTable::GetVkImageInfo);
    VkImageDrmFormatModifierPropertiesEXT* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT, nullptr });
    InitializeOutputStructPNext(pProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetImageDrmFormatModifierPropertiesEXT(in_device, in_image, out_pProperties);
    CheckResult("vkGetImageDrmFormatModifierPropertiesEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkValidationCacheCreateInfoEXT* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pValidationCache->IsNull()) { pValidationCache->SetHandleLength(1); }
    VkValidationCacheEXT* out_pValidationCache = pValidationCache->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateValidationCacheEXT(in_device, in_pCreateInfo, in_pAllocator, out_pValidationCache);
    CheckResult("vkCreateValidationCacheEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanValidationCacheEXTInfo>(device, pValidationCache->GetPointer(), out_pValidationCache, &CommonObjectInfoTable::AddVkValidationCacheEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkValidationCacheEXT in_validationCache = MapHandle<VulkanValidationCacheEXTInfo>(validationCache, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyValidationCacheEXT(in_device, in_validationCache, in_pAllocator);
    RemoveHandle(validationCache, &CommonObjectInfoTable::RemoveVkValidationCacheEXTInfo);
}

void VulkanReplayConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkValidationCacheEXT in_dstCache = MapHandle<VulkanValidationCacheEXTInfo>(dstCache, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo);
    const VkValidationCacheEXT* in_pSrcCaches = MapHandles<VulkanValidationCacheEXTInfo>(pSrcCaches, srcCacheCount, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo);

    VkResult replay_result = GetDeviceTable(in_device)->MergeValidationCachesEXT(in_device, in_dstCache, srcCacheCount, in_pSrcCaches);
    CheckResult("vkMergeValidationCachesEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkValidationCacheEXT in_validationCache = MapHandle<VulkanValidationCacheEXTInfo>(validationCache, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo);
    size_t* out_pDataSize = pDataSize->IsNull() ? nullptr : pDataSize->AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanValidationCacheEXTInfo>("vkGetValidationCacheDataEXT", returnValue, validationCache, kValidationCacheEXTArrayGetValidationCacheDataEXT, pDataSize, pData, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo));
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(*out_pDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetValidationCacheDataEXT(in_device, in_validationCache, out_pDataSize, out_pData);
    CheckResult("vkGetValidationCacheDataEXT", returnValue, replay_result, call_info);

    if (pData->IsNull()) { SetOutputArrayCount<VulkanValidationCacheEXTInfo>(validationCache, kValidationCacheEXTArrayGetValidationCacheDataEXT, *out_pDataSize, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo); }
}

void VulkanReplayConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImageView in_imageView = MapHandle<VulkanImageViewInfo>(imageView, &CommonObjectInfoTable::GetVkImageViewInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindShadingRateImageNV(in_commandBuffer, in_imageView, imageLayout);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindShadingRateImageNV(call_info, GetDeviceTable(in_commandBuffer)->CmdBindShadingRateImageNV, in_commandBuffer, in_imageView, imageLayout);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkShadingRatePaletteNV* in_pShadingRatePalettes = pShadingRatePalettes->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportShadingRatePaletteNV(in_commandBuffer, firstViewport, viewportCount, in_pShadingRatePalettes);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetViewportShadingRatePaletteNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetViewportShadingRatePaletteNV, in_commandBuffer, firstViewport, viewportCount, in_pShadingRatePalettes);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCoarseSampleOrderCustomNV* in_pCustomSampleOrders = pCustomSampleOrders->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetCoarseSampleOrderNV(in_commandBuffer, sampleOrderType, customSampleOrderCount, in_pCustomSampleOrders);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetCoarseSampleOrderNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetCoarseSampleOrderNV, in_commandBuffer, sampleOrderType, customSampleOrderCount, in_pCustomSampleOrders);
    }
}

void VulkanReplayConsumer::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAccelerationStructureCreateInfoNV* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pAccelerationStructure->IsNull()) { pAccelerationStructure->SetHandleLength(1); }
    VkAccelerationStructureNV* out_pAccelerationStructure = pAccelerationStructure->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateAccelerationStructureNV(in_device, in_pCreateInfo, in_pAllocator, out_pAccelerationStructure);
    CheckResult("vkCreateAccelerationStructureNV", returnValue, replay_result, call_info);

    AddHandle<VulkanAccelerationStructureNVInfo>(device, pAccelerationStructure->GetPointer(), out_pAccelerationStructure, &CommonObjectInfoTable::AddVkAccelerationStructureNVInfo);
}

void VulkanReplayConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkAccelerationStructureNV in_accelerationStructure = MapHandle<VulkanAccelerationStructureNVInfo>(accelerationStructure, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyAccelerationStructureNV(in_device, in_accelerationStructure, in_pAllocator);
    RemoveHandle(accelerationStructure, &CommonObjectInfoTable::RemoveVkAccelerationStructureNVInfo);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkBindAccelerationStructureMemoryInfoNV* in_pBindInfos = pBindInfos->GetPointer();
    MapStructArrayHandles(pBindInfos->GetMetaStructPointer(), pBindInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->BindAccelerationStructureMemoryNV(in_device, bindInfoCount, in_pBindInfos);
    CheckResult("vkBindAccelerationStructureMemoryNV", returnValue, replay_result, call_info);
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkAccelerationStructureInfoNV* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkBuffer in_instanceData = MapHandle<VulkanBufferInfo>(instanceData, &CommonObjectInfoTable::GetVkBufferInfo);
    VkAccelerationStructureNV in_dst = MapHandle<VulkanAccelerationStructureNVInfo>(dst, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    VkAccelerationStructureNV in_src = MapHandle<VulkanAccelerationStructureNVInfo>(src, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    VkBuffer in_scratch = MapHandle<VulkanBufferInfo>(scratch, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdBuildAccelerationStructureNV(in_commandBuffer, in_pInfo, in_instanceData, instanceOffset, update, in_dst, in_src, in_scratch, scratchOffset);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBuildAccelerationStructureNV(call_info, GetDeviceTable(in_commandBuffer)->CmdBuildAccelerationStructureNV, in_commandBuffer, in_pInfo, in_instanceData, instanceOffset, update, in_dst, in_src, in_scratch, scratchOffset);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkAccelerationStructureNV in_dst = MapHandle<VulkanAccelerationStructureNVInfo>(dst, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    VkAccelerationStructureNV in_src = MapHandle<VulkanAccelerationStructureNVInfo>(src, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);

    GetDeviceTable(in_commandBuffer)->CmdCopyAccelerationStructureNV(in_commandBuffer, in_dst, in_src, mode);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyAccelerationStructureNV(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyAccelerationStructureNV, in_commandBuffer, in_dst, in_src, mode);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_raygenShaderBindingTableBuffer = MapHandle<VulkanBufferInfo>(raygenShaderBindingTableBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_missShaderBindingTableBuffer = MapHandle<VulkanBufferInfo>(missShaderBindingTableBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_hitShaderBindingTableBuffer = MapHandle<VulkanBufferInfo>(hitShaderBindingTableBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_callableShaderBindingTableBuffer = MapHandle<VulkanBufferInfo>(callableShaderBindingTableBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdTraceRaysNV(in_commandBuffer, in_raygenShaderBindingTableBuffer, raygenShaderBindingOffset, in_missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, in_hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, in_callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdTraceRaysNV(call_info, GetDeviceTable(in_commandBuffer)->CmdTraceRaysNV, in_commandBuffer, in_raygenShaderBindingTableBuffer, raygenShaderBindingOffset, in_missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, in_hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, in_callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
    }
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipelineCache in_pipelineCache = MapHandle<VulkanPipelineCacheInfo>(pipelineCache, &CommonObjectInfoTable::GetVkPipelineCacheInfo);
    const VkRayTracingPipelineCreateInfoNV* in_pCreateInfos = pCreateInfos->GetPointer();
    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pPipelines->IsNull()) { pPipelines->SetHandleLength(createInfoCount); }
    if (omitted_pipeline_cache_data_) {AllowCompileDuringPipelineCreation(createInfoCount, pCreateInfos->GetPointer());}
    VkPipeline* out_pPipelines = pPipelines->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateRayTracingPipelinesNV(in_device, in_pipelineCache, createInfoCount, in_pCreateInfos, in_pAllocator, out_pPipelines);
    CheckResult("vkCreateRayTracingPipelinesNV", returnValue, replay_result, call_info);

    AddHandles<VulkanPipelineInfo>(device, pPipelines->GetPointer(), pPipelines->GetLength(), out_pPipelines, createInfoCount, &CommonObjectInfoTable::AddVkPipelineInfo);
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
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_pipeline = GetObjectInfoTable().GetVkPipelineInfo(pipeline);
    if (!pData->IsNull()) { pData->AllocateOutputData(dataSize); }

    VkResult replay_result = OverrideGetRayTracingShaderGroupHandlesKHR(GetDeviceTable(in_device->handle)->GetRayTracingShaderGroupHandlesKHR, returnValue, in_device, in_pipeline, firstGroup, groupCount, dataSize, pData);
    CheckResult("vkGetRayTracingShaderGroupHandlesKHR", returnValue, replay_result, call_info);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetRayTracingShaderGroupHandlesNV(in_device, in_pipeline, firstGroup, groupCount, dataSize, out_pData);
    CheckResult("vkGetRayTracingShaderGroupHandlesNV", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkAccelerationStructureNV in_accelerationStructure = MapHandle<VulkanAccelerationStructureNVInfo>(accelerationStructure, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetAccelerationStructureHandleNV(in_device, in_accelerationStructure, dataSize, out_pData);
    CheckResult("vkGetAccelerationStructureHandleNV", returnValue, replay_result, call_info);
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkAccelerationStructureNV* in_pAccelerationStructures = MapHandles<VulkanAccelerationStructureNVInfo>(pAccelerationStructures, accelerationStructureCount, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(in_commandBuffer, accelerationStructureCount, in_pAccelerationStructures, queryType, in_queryPool, firstQuery);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWriteAccelerationStructuresPropertiesNV(call_info, GetDeviceTable(in_commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV, in_commandBuffer, accelerationStructureCount, in_pAccelerationStructures, queryType, in_queryPool, firstQuery);
    }
}

void VulkanReplayConsumer::Process_vkCompileDeferredNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);

    VkResult replay_result = GetDeviceTable(in_device)->CompileDeferredNV(in_device, in_pipeline, shader);
    CheckResult("vkCompileDeferredNV", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const void* in_pHostPointer = PreProcessExternalObject(pHostPointer, format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT, "vkGetMemoryHostPointerPropertiesEXT");
    VkMemoryHostPointerPropertiesEXT* out_pMemoryHostPointerProperties = pMemoryHostPointerProperties->IsNull() ? nullptr : pMemoryHostPointerProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT, nullptr });
    InitializeOutputStructPNext(pMemoryHostPointerProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryHostPointerPropertiesEXT(in_device, handleType, in_pHostPointer, out_pMemoryHostPointerProperties);
    CheckResult("vkGetMemoryHostPointerPropertiesEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteBufferMarkerAMD(in_commandBuffer, pipelineStage, in_dstBuffer, dstOffset, marker);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWriteBufferMarkerAMD(call_info, GetDeviceTable(in_commandBuffer)->CmdWriteBufferMarkerAMD, in_commandBuffer, pipelineStage, in_dstBuffer, dstOffset, marker);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainKHR>*            pTimeDomains)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pTimeDomainCount = pTimeDomainCount->IsNull() ? nullptr : pTimeDomainCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT, pTimeDomainCount, pTimeDomains, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkTimeDomainKHR* out_pTimeDomains = pTimeDomains->IsNull() ? nullptr : pTimeDomains->AllocateOutputData(*out_pTimeDomainCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(in_physicalDevice, out_pTimeDomainCount, out_pTimeDomains);
    CheckResult("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", returnValue, replay_result, call_info);

    if (pTimeDomains->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT, *out_pTimeDomainCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCalibratedTimestampInfoKHR* in_pTimestampInfos = pTimestampInfos->GetPointer();
    uint64_t* out_pTimestamps = pTimestamps->IsNull() ? nullptr : pTimestamps->AllocateOutputData(timestampCount);
    uint64_t* out_pMaxDeviation = pMaxDeviation->IsNull() ? nullptr : pMaxDeviation->AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetCalibratedTimestampsEXT(in_device, timestampCount, in_pTimestampInfos, out_pTimestamps, out_pMaxDeviation);
    CheckResult("vkGetCalibratedTimestampsEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksNV(in_commandBuffer, taskCount, firstTask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawMeshTasksNV(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksNV, in_commandBuffer, taskCount, firstTask);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectNV(in_commandBuffer, in_buffer, offset, drawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawMeshTasksIndirectNV(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectNV, in_commandBuffer, in_buffer, offset, drawCount, stride);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectCountNV(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawMeshTasksIndirectCountNV(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectCountNV, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    PointerDecoder<VkBool32>*                   pExclusiveScissorEnables)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBool32* in_pExclusiveScissorEnables = pExclusiveScissorEnables->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetExclusiveScissorEnableNV(in_commandBuffer, firstExclusiveScissor, exclusiveScissorCount, in_pExclusiveScissorEnables);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetExclusiveScissorEnableNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetExclusiveScissorEnableNV, in_commandBuffer, firstExclusiveScissor, exclusiveScissorCount, in_pExclusiveScissorEnables);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRect2D* in_pExclusiveScissors = pExclusiveScissors->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetExclusiveScissorNV(in_commandBuffer, firstExclusiveScissor, exclusiveScissorCount, in_pExclusiveScissors);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetExclusiveScissorNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetExclusiveScissorNV, in_commandBuffer, firstExclusiveScissor, exclusiveScissorCount, in_pExclusiveScissors);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const void* in_pCheckpointMarker = PreProcessExternalObject(pCheckpointMarker, format::ApiCallId::ApiCall_vkCmdSetCheckpointNV, "vkCmdSetCheckpointNV");

    GetDeviceTable(in_commandBuffer)->CmdSetCheckpointNV(in_commandBuffer, in_pCheckpointMarker);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetCheckpointNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetCheckpointNV, in_commandBuffer, in_pCheckpointMarker);
    }
}

void VulkanReplayConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(queue, &CommonObjectInfoTable::GetVkQueueInfo);
    uint32_t* out_pCheckpointDataCount = pCheckpointDataCount->IsNull() ? nullptr : pCheckpointDataCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanQueueInfo>("vkGetQueueCheckpointDataNV", VK_SUCCESS, queue, kQueueArrayGetQueueCheckpointDataNV, pCheckpointDataCount, pCheckpointData, &CommonObjectInfoTable::GetVkQueueInfo));
    VkCheckpointDataNV* out_pCheckpointData = pCheckpointData->IsNull() ? nullptr : pCheckpointData->AllocateOutputData(*out_pCheckpointDataCount, VkCheckpointDataNV{ VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV, nullptr });

    GetDeviceTable(in_queue)->GetQueueCheckpointDataNV(in_queue, out_pCheckpointDataCount, out_pCheckpointData);

    if (pCheckpointData->IsNull()) { SetOutputArrayCount<VulkanQueueInfo>(queue, kQueueArrayGetQueueCheckpointDataNV, *out_pCheckpointDataCount, &CommonObjectInfoTable::GetVkQueueInfo); }
}

void VulkanReplayConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkInitializePerformanceApiInfoINTEL* in_pInitializeInfo = pInitializeInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->InitializePerformanceApiINTEL(in_device, in_pInitializeInfo);
    CheckResult("vkInitializePerformanceApiINTEL", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);

    GetDeviceTable(in_device)->UninitializePerformanceApiINTEL(in_device);
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPerformanceMarkerInfoINTEL* in_pMarkerInfo = pMarkerInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceMarkerINTEL(in_commandBuffer, in_pMarkerInfo);
    CheckResult("vkCmdSetPerformanceMarkerINTEL", returnValue, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetPerformanceMarkerINTEL(call_info, GetDeviceTable(in_commandBuffer)->CmdSetPerformanceMarkerINTEL, returnValue, in_commandBuffer, in_pMarkerInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPerformanceStreamMarkerInfoINTEL* in_pMarkerInfo = pMarkerInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceStreamMarkerINTEL(in_commandBuffer, in_pMarkerInfo);
    CheckResult("vkCmdSetPerformanceStreamMarkerINTEL", returnValue, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetPerformanceStreamMarkerINTEL(call_info, GetDeviceTable(in_commandBuffer)->CmdSetPerformanceStreamMarkerINTEL, returnValue, in_commandBuffer, in_pMarkerInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPerformanceOverrideInfoINTEL* in_pOverrideInfo = pOverrideInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceOverrideINTEL(in_commandBuffer, in_pOverrideInfo);
    CheckResult("vkCmdSetPerformanceOverrideINTEL", returnValue, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetPerformanceOverrideINTEL(call_info, GetDeviceTable(in_commandBuffer)->CmdSetPerformanceOverrideINTEL, returnValue, in_commandBuffer, in_pOverrideInfo);
    }
}

void VulkanReplayConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPerformanceConfigurationAcquireInfoINTEL* in_pAcquireInfo = pAcquireInfo->GetPointer();
    if (!pConfiguration->IsNull()) { pConfiguration->SetHandleLength(1); }
    VkPerformanceConfigurationINTEL* out_pConfiguration = pConfiguration->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->AcquirePerformanceConfigurationINTEL(in_device, in_pAcquireInfo, out_pConfiguration);
    CheckResult("vkAcquirePerformanceConfigurationINTEL", returnValue, replay_result, call_info);

    AddHandle<VulkanPerformanceConfigurationINTELInfo>(device, pConfiguration->GetPointer(), out_pConfiguration, &CommonObjectInfoTable::AddVkPerformanceConfigurationINTELInfo);
}

void VulkanReplayConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPerformanceConfigurationINTEL in_configuration = MapHandle<VulkanPerformanceConfigurationINTELInfo>(configuration, &CommonObjectInfoTable::GetVkPerformanceConfigurationINTELInfo);

    VkResult replay_result = GetDeviceTable(in_device)->ReleasePerformanceConfigurationINTEL(in_device, in_configuration);
    CheckResult("vkReleasePerformanceConfigurationINTEL", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(queue, &CommonObjectInfoTable::GetVkQueueInfo);
    VkPerformanceConfigurationINTEL in_configuration = MapHandle<VulkanPerformanceConfigurationINTELInfo>(configuration, &CommonObjectInfoTable::GetVkPerformanceConfigurationINTELInfo);

    VkResult replay_result = GetDeviceTable(in_queue)->QueueSetPerformanceConfigurationINTEL(in_queue, in_configuration);
    CheckResult("vkQueueSetPerformanceConfigurationINTEL", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPerformanceValueINTEL* out_pValue = pValue->IsNull() ? nullptr : pValue->AllocateOutputData(1);

    VkResult replay_result = GetDeviceTable(in_device)->GetPerformanceParameterINTEL(in_device, parameter, out_pValue);
    CheckResult("vkGetPerformanceParameterINTEL", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkSetLocalDimmingAMD for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapChain = MapHandle<VulkanSwapchainKHRInfo>(swapChain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);

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
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkImagePipeSurfaceCreateInfoFUCHSIA* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateImagePipeSurfaceFUCHSIA(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateImagePipeSurfaceFUCHSIA", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateMetalSurfaceEXT(GetInstanceTable(in_instance->handle)->CreateMetalSurfaceEXT, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateMetalSurfaceEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetBufferDeviceAddress(GetDeviceTable(in_device->handle)->GetBufferDeviceAddressEXT, returnValue, in_device, pInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(physicalDevice);
    pToolCount->IsNull() ? nullptr : pToolCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceToolPropertiesEXT", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT, pToolCount, pToolProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    if (!pToolProperties->IsNull()) { pToolProperties->AllocateOutputData(*pToolCount->GetOutputPointer(), VkPhysicalDeviceToolProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES, nullptr }); }

    VkResult replay_result = OverrideGetPhysicalDeviceToolProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceToolPropertiesEXT, returnValue, in_physicalDevice, pToolCount, pToolProperties);
    CheckResult("vkGetPhysicalDeviceToolPropertiesEXT", returnValue, replay_result, call_info);

    if (pToolProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT, *pToolCount->GetOutputPointer(), &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = pPropertyCount->IsNull() ? nullptr : pPropertyCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV, pPropertyCount, pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkCooperativeMatrixPropertiesNV* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertyCount, VkCooperativeMatrixPropertiesNV{ VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesNV(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", returnValue, replay_result, call_info);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pCombinationCount = pCombinationCount->IsNull() ? nullptr : pCombinationCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV, pCombinationCount, pCombinations, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkFramebufferMixedSamplesCombinationNV* out_pCombinations = pCombinations->IsNull() ? nullptr : pCombinations->AllocateOutputData(*out_pCombinationCount, VkFramebufferMixedSamplesCombinationNV{ VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(in_physicalDevice, out_pCombinationCount, out_pCombinations);
    CheckResult("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", returnValue, replay_result, call_info);

    if (pCombinations->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV, *out_pCombinationCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfacePresentModes2EXT for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = pSurfaceInfo->GetPointer();
    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    uint32_t* out_pPresentModeCount = pPresentModeCount->IsNull() ? nullptr : pPresentModeCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSurfacePresentModes2EXT", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT, pPresentModeCount, pPresentModes, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkPresentModeKHR* out_pPresentModes = pPresentModes->IsNull() ? nullptr : pPresentModes->AllocateOutputData(*out_pPresentModeCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfacePresentModes2EXT(in_physicalDevice, in_pSurfaceInfo, out_pPresentModeCount, out_pPresentModes);
    CheckResult("vkGetPhysicalDeviceSurfacePresentModes2EXT", returnValue, replay_result, call_info);

    if (pPresentModes->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT, *out_pPresentModeCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    if ((options_.swapchain_option == util::SwapchainOption::kOffscreen) || (options_.force_windowed_origin == true) || (options_.force_windowed == true))
    {
        GFXRECON_LOG_DEBUG("Skip vkAcquireFullScreenExclusiveModeEXT for offscreen or force windowed mode.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->AcquireFullScreenExclusiveModeEXT(in_device, in_swapchain);
    CheckResult("vkAcquireFullScreenExclusiveModeEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkReleaseFullScreenExclusiveModeEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->ReleaseFullScreenExclusiveModeEXT(in_device, in_swapchain);
    CheckResult("vkReleaseFullScreenExclusiveModeEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetDeviceGroupSurfacePresentModes2EXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = pSurfaceInfo->GetPointer();
    if (pSurfaceInfo->GetPointer()->surface == VK_NULL_HANDLE) { return; }
    MapStructHandles(pSurfaceInfo->GetMetaStructPointer(), GetObjectInfoTable());
    auto in_pSurfaceInfo_meta = pSurfaceInfo->GetMetaStructPointer();
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    VkDeviceGroupPresentModeFlagsKHR* out_pModes = pModes->IsNull() ? nullptr : pModes->AllocateOutputData(1, static_cast<VkDeviceGroupPresentModeFlagsKHR>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupSurfacePresentModes2EXT(in_device, in_pSurfaceInfo, out_pModes);
    CheckResult("vkGetDeviceGroupSurfacePresentModes2EXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(instance);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    pSurface->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateHeadlessSurfaceEXT(GetInstanceTable(in_instance->handle)->CreateHeadlessSurfaceEXT, returnValue, in_instance, pCreateInfo, pAllocator, pSurface);
    CheckResult("vkCreateHeadlessSurfaceEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), pSurface->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineStippleEXT(in_commandBuffer, lineStippleFactor, lineStipplePattern);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetLineStippleEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetLineStippleEXT, in_commandBuffer, lineStippleFactor, lineStipplePattern);
    }
}

void VulkanReplayConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_device)->ResetQueryPoolEXT(in_device, in_queryPool, firstQuery, queryCount);
}

void VulkanReplayConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCullModeEXT(in_commandBuffer, cullMode);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetCullModeEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetCullModeEXT, in_commandBuffer, cullMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetFrontFaceEXT(in_commandBuffer, frontFace);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetFrontFaceEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetFrontFaceEXT, in_commandBuffer, frontFace);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveTopologyEXT(in_commandBuffer, primitiveTopology);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetPrimitiveTopologyEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveTopologyEXT, in_commandBuffer, primitiveTopology);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkViewport* in_pViewports = pViewports->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWithCountEXT(in_commandBuffer, viewportCount, in_pViewports);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetViewportWithCountEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetViewportWithCountEXT, in_commandBuffer, viewportCount, in_pViewports);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRect2D* in_pScissors = pScissors->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetScissorWithCountEXT(in_commandBuffer, scissorCount, in_pScissors);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetScissorWithCountEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetScissorWithCountEXT, in_commandBuffer, scissorCount, in_pScissors);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<VulkanBufferInfo>(pBuffers, bindingCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pOffsets = pOffsets->GetPointer();
    const VkDeviceSize* in_pSizes = pSizes->GetPointer();
    const VkDeviceSize* in_pStrides = pStrides->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers2EXT(in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets, in_pSizes, in_pStrides);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindVertexBuffers2EXT(call_info, GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers2EXT, in_commandBuffer, firstBinding, bindingCount, in_pBuffers, in_pOffsets, in_pSizes, in_pStrides);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthTestEnableEXT(in_commandBuffer, depthTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthTestEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthTestEnableEXT, in_commandBuffer, depthTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthWriteEnableEXT(in_commandBuffer, depthWriteEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthWriteEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthWriteEnableEXT, in_commandBuffer, depthWriteEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthCompareOpEXT(in_commandBuffer, depthCompareOp);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthCompareOpEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthCompareOpEXT, in_commandBuffer, depthCompareOp);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBoundsTestEnableEXT(in_commandBuffer, depthBoundsTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthBoundsTestEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthBoundsTestEnableEXT, in_commandBuffer, depthBoundsTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilTestEnableEXT(in_commandBuffer, stencilTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetStencilTestEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetStencilTestEnableEXT, in_commandBuffer, stencilTestEnable);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilOpEXT(in_commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetStencilOpEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetStencilOpEXT, in_commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }
}

void VulkanReplayConsumer::Process_vkCopyMemoryToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfoEXT>* pCopyMemoryToImageInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCopyMemoryToImageInfoEXT* in_pCopyMemoryToImageInfo = pCopyMemoryToImageInfo->GetPointer();
    MapStructHandles(pCopyMemoryToImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMemoryToImageEXT(in_device, in_pCopyMemoryToImageInfo);
    CheckResult("vkCopyMemoryToImageEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyImageToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfoEXT>* pCopyImageToMemoryInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCopyImageToMemoryInfoEXT* in_pCopyImageToMemoryInfo = pCopyImageToMemoryInfo->GetPointer();
    MapStructHandles(pCopyImageToMemoryInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyImageToMemoryEXT(in_device, in_pCopyImageToMemoryInfo);
    CheckResult("vkCopyImageToMemoryEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyImageToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToImageInfoEXT>* pCopyImageToImageInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCopyImageToImageInfoEXT* in_pCopyImageToImageInfo = pCopyImageToImageInfo->GetPointer();
    MapStructHandles(pCopyImageToImageInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyImageToImageEXT(in_device, in_pCopyImageToImageInfo);
    CheckResult("vkCopyImageToImageEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkTransitionImageLayoutEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    transitionCount,
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfoEXT>* pTransitions)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkHostImageLayoutTransitionInfoEXT* in_pTransitions = pTransitions->GetPointer();
    MapStructArrayHandles(pTransitions->GetMetaStructPointer(), pTransitions->GetLength(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->TransitionImageLayoutEXT(in_device, transitionCount, in_pTransitions);
    CheckResult("vkTransitionImageLayoutEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(image, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageSubresource2KHR* in_pSubresource = pSubresource->GetPointer();
    VkSubresourceLayout2KHR* out_pLayout = pLayout->IsNull() ? nullptr : pLayout->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR, nullptr });
    InitializeOutputStructPNext(pLayout);

    GetDeviceTable(in_device)->GetImageSubresourceLayout2EXT(in_device, in_image, in_pSubresource, out_pLayout);
}

void VulkanReplayConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkReleaseSwapchainImagesEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkReleaseSwapchainImagesInfoEXT* in_pReleaseInfo = pReleaseInfo->GetPointer();
    MapStructHandles(pReleaseInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ReleaseSwapchainImagesEXT(in_device, in_pReleaseInfo);
    CheckResult("vkReleaseSwapchainImagesEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkGeneratedCommandsMemoryRequirementsInfoNV* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetGeneratedCommandsMemoryRequirementsNV(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkGeneratedCommandsInfoNV* in_pGeneratedCommandsInfo = pGeneratedCommandsInfo->GetPointer();
    MapStructHandles(pGeneratedCommandsInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPreprocessGeneratedCommandsNV(in_commandBuffer, in_pGeneratedCommandsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPreprocessGeneratedCommandsNV(call_info, GetDeviceTable(in_commandBuffer)->CmdPreprocessGeneratedCommandsNV, in_commandBuffer, in_pGeneratedCommandsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkGeneratedCommandsInfoNV* in_pGeneratedCommandsInfo = pGeneratedCommandsInfo->GetPointer();
    MapStructHandles(pGeneratedCommandsInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdExecuteGeneratedCommandsNV(in_commandBuffer, isPreprocessed, in_pGeneratedCommandsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdExecuteGeneratedCommandsNV(call_info, GetDeviceTable(in_commandBuffer)->CmdExecuteGeneratedCommandsNV, in_commandBuffer, isPreprocessed, in_pGeneratedCommandsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindPipelineShaderGroupNV(in_commandBuffer, pipelineBindPoint, in_pipeline, groupIndex);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindPipelineShaderGroupNV(call_info, GetDeviceTable(in_commandBuffer)->CmdBindPipelineShaderGroupNV, in_commandBuffer, pipelineBindPoint, in_pipeline, groupIndex);
    }
}

void VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkIndirectCommandsLayoutCreateInfoNV* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pIndirectCommandsLayout->IsNull()) { pIndirectCommandsLayout->SetHandleLength(1); }
    VkIndirectCommandsLayoutNV* out_pIndirectCommandsLayout = pIndirectCommandsLayout->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateIndirectCommandsLayoutNV(in_device, in_pCreateInfo, in_pAllocator, out_pIndirectCommandsLayout);
    CheckResult("vkCreateIndirectCommandsLayoutNV", returnValue, replay_result, call_info);

    AddHandle<VulkanIndirectCommandsLayoutNVInfo>(device, pIndirectCommandsLayout->GetPointer(), out_pIndirectCommandsLayout, &CommonObjectInfoTable::AddVkIndirectCommandsLayoutNVInfo);
}

void VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkIndirectCommandsLayoutNV in_indirectCommandsLayout = MapHandle<VulkanIndirectCommandsLayoutNVInfo>(indirectCommandsLayout, &CommonObjectInfoTable::GetVkIndirectCommandsLayoutNVInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyIndirectCommandsLayoutNV(in_device, in_indirectCommandsLayout, in_pAllocator);
    RemoveHandle(indirectCommandsLayout, &CommonObjectInfoTable::RemoveVkIndirectCommandsLayoutNVInfo);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDepthBiasInfoEXT* in_pDepthBiasInfo = pDepthBiasInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBias2EXT(in_commandBuffer, in_pDepthBiasInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthBias2EXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthBias2EXT, in_commandBuffer, in_pDepthBiasInfo);
    }
}

void VulkanReplayConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    format::HandleId                            display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->AcquireDrmDisplayEXT(in_physicalDevice, drmFd, in_display);
    CheckResult("vkAcquireDrmDisplayEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    HandlePointerDecoder<VkDisplayKHR>*         display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    if (!display->IsNull()) { display->SetHandleLength(1); }
    VkDisplayKHR* out_display = display->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDrmDisplayEXT(in_physicalDevice, drmFd, connectorId, out_display);
    CheckResult("vkGetDrmDisplayEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanDisplayKHRInfo>(physicalDevice, display->GetPointer(), out_display, &CommonObjectInfoTable::AddVkDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPrivateDataSlotCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pPrivateDataSlot->IsNull()) { pPrivateDataSlot->SetHandleLength(1); }
    VkPrivateDataSlot* out_pPrivateDataSlot = pPrivateDataSlot->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreatePrivateDataSlotEXT(in_device, in_pCreateInfo, in_pAllocator, out_pPrivateDataSlot);
    CheckResult("vkCreatePrivateDataSlotEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanPrivateDataSlotInfo>(device, pPrivateDataSlot->GetPointer(), out_pPrivateDataSlot, &CommonObjectInfoTable::AddVkPrivateDataSlotInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyPrivateDataSlotEXT(in_device, in_privateDataSlot, in_pAllocator);
    RemoveHandle(privateDataSlot, &CommonObjectInfoTable::RemoveVkPrivateDataSlotInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);

    VkResult replay_result = GetDeviceTable(in_device)->SetPrivateDataEXT(in_device, objectType, in_objectHandle, in_privateDataSlot, data);
    CheckResult("vkSetPrivateDataEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    uint64_t in_objectHandle = MapHandle(objectHandle, objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);
    uint64_t* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(1, static_cast<uint64_t>(0));

    GetDeviceTable(in_device)->GetPrivateDataEXT(in_device, objectType, in_objectHandle, in_privateDataSlot, out_pData);
}

void VulkanReplayConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkFragmentShadingRateCombinerOpKHR* in_combinerOps = combinerOps->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetFragmentShadingRateEnumNV(in_commandBuffer, shadingRate, in_combinerOps);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetFragmentShadingRateEnumNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetFragmentShadingRateEnumNV, in_commandBuffer, shadingRate, in_combinerOps);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts,
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeviceFaultCountsEXT* out_pFaultCounts = pFaultCounts->IsNull() ? nullptr : pFaultCounts->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT, nullptr });
    InitializeOutputStructPNext(pFaultCounts);
    VkDeviceFaultInfoEXT* out_pFaultInfo = pFaultInfo->IsNull() ? nullptr : pFaultInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT, nullptr });
    InitializeOutputStructPNext(pFaultInfo);

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceFaultInfoEXT(in_device, out_pFaultCounts, out_pFaultInfo);
    CheckResult("vkGetDeviceFaultInfoEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->AcquireWinrtDisplayNV(in_physicalDevice, in_display);
    CheckResult("vkAcquireWinrtDisplayNV", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    if (!pDisplay->IsNull()) { pDisplay->SetHandleLength(1); }
    VkDisplayKHR* out_pDisplay = pDisplay->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetWinrtDisplayNV(in_physicalDevice, deviceRelativeId, out_pDisplay);
    CheckResult("vkGetWinrtDisplayNV", returnValue, replay_result, call_info);

    AddHandle<VulkanDisplayKHRInfo>(physicalDevice, pDisplay->GetPointer(), out_pDisplay, &CommonObjectInfoTable::AddVkDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkDirectFBSurfaceCreateInfoEXT* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateDirectFBSurfaceEXT(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateDirectFBSurfaceEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVertexInputBindingDescription2EXT* in_pVertexBindingDescriptions = pVertexBindingDescriptions->GetPointer();
    const VkVertexInputAttributeDescription2EXT* in_pVertexAttributeDescriptions = pVertexAttributeDescriptions->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetVertexInputEXT(in_commandBuffer, vertexBindingDescriptionCount, in_pVertexBindingDescriptions, vertexAttributeDescriptionCount, in_pVertexAttributeDescriptions);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetVertexInputEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetVertexInputEXT, in_commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    }
}

void VulkanReplayConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryGetZirconHandleInfoFUCHSIA* in_pGetZirconHandleInfo = pGetZirconHandleInfo->GetPointer();
    MapStructHandles(pGetZirconHandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    zx_handle_t* out_pZirconHandle = pZirconHandle->IsNull() ? nullptr : pZirconHandle->AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryZirconHandleFUCHSIA(in_device, in_pGetZirconHandleInfo, out_pZirconHandle);
    CheckResult("vkGetMemoryZirconHandleFUCHSIA", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint32_t                                    zirconHandle,
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkMemoryZirconHandlePropertiesFUCHSIA* out_pMemoryZirconHandleProperties = pMemoryZirconHandleProperties->IsNull() ? nullptr : pMemoryZirconHandleProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA, nullptr });
    InitializeOutputStructPNext(pMemoryZirconHandleProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryZirconHandlePropertiesFUCHSIA(in_device, handleType, zirconHandle, out_pMemoryZirconHandleProperties);
    CheckResult("vkGetMemoryZirconHandlePropertiesFUCHSIA", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImportSemaphoreZirconHandleInfoFUCHSIA* in_pImportSemaphoreZirconHandleInfo = pImportSemaphoreZirconHandleInfo->GetPointer();
    MapStructHandles(pImportSemaphoreZirconHandleInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ImportSemaphoreZirconHandleFUCHSIA(in_device, in_pImportSemaphoreZirconHandleInfo);
    CheckResult("vkImportSemaphoreZirconHandleFUCHSIA", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreGetZirconHandleInfoFUCHSIA* in_pGetZirconHandleInfo = pGetZirconHandleInfo->GetPointer();
    MapStructHandles(pGetZirconHandleInfo->GetMetaStructPointer(), GetObjectInfoTable());
    zx_handle_t* out_pZirconHandle = pZirconHandle->IsNull() ? nullptr : pZirconHandle->AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreZirconHandleFUCHSIA(in_device, in_pGetZirconHandleInfo, out_pZirconHandle);
    CheckResult("vkGetSemaphoreZirconHandleFUCHSIA", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImageView in_imageView = MapHandle<VulkanImageViewInfo>(imageView, &CommonObjectInfoTable::GetVkImageViewInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindInvocationMaskHUAWEI(in_commandBuffer, in_imageView, imageLayout);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindInvocationMaskHUAWEI(call_info, GetDeviceTable(in_commandBuffer)->CmdBindInvocationMaskHUAWEI, in_commandBuffer, in_imageView, imageLayout);
    }
}

void VulkanReplayConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo,
    PointerDecoder<uint64_t, void*>*            pAddress)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryGetRemoteAddressInfoNV* in_pMemoryGetRemoteAddressInfo = pMemoryGetRemoteAddressInfo->GetPointer();
    MapStructHandles(pMemoryGetRemoteAddressInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkRemoteAddressNV* out_pAddress = pAddress->IsNull() ? nullptr : reinterpret_cast<VkRemoteAddressNV*>(pAddress->AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryRemoteAddressNV(in_device, in_pMemoryGetRemoteAddressInfo, out_pAddress);
    CheckResult("vkGetMemoryRemoteAddressNV", returnValue, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*pAddress->GetPointer()), static_cast<void*>(*out_pAddress), format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV, "vkGetMemoryRemoteAddressNV");
}

void VulkanReplayConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPatchControlPointsEXT(in_commandBuffer, patchControlPoints);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetPatchControlPointsEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetPatchControlPointsEXT, in_commandBuffer, patchControlPoints);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizerDiscardEnableEXT(in_commandBuffer, rasterizerDiscardEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetRasterizerDiscardEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetRasterizerDiscardEnableEXT, in_commandBuffer, rasterizerDiscardEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBiasEnableEXT(in_commandBuffer, depthBiasEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthBiasEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthBiasEnableEXT, in_commandBuffer, depthBiasEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLogicOpEXT(in_commandBuffer, logicOp);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetLogicOpEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetLogicOpEXT, in_commandBuffer, logicOp);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveRestartEnableEXT(in_commandBuffer, primitiveRestartEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetPrimitiveRestartEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveRestartEnableEXT, in_commandBuffer, primitiveRestartEnable);
    }
}

void VulkanReplayConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkScreenSurfaceCreateInfoQNX* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSurface->IsNull()) { pSurface->SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = pSurface->GetHandlePointer();

    VkResult replay_result = GetInstanceTable(in_instance)->CreateScreenSurfaceQNX(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateScreenSurfaceQNX", returnValue, replay_result, call_info);

    AddHandle<VulkanSurfaceKHRInfo>(instance, pSurface->GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    window)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    struct _screen_window* in_window = static_cast<struct _screen_window*>(PreProcessExternalObject(window, format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX, "vkGetPhysicalDeviceScreenPresentationSupportQNX"));

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceScreenPresentationSupportQNX(in_physicalDevice, queueFamilyIndex, in_window);
}

void VulkanReplayConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBool32* in_pColorWriteEnables = pColorWriteEnables->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorWriteEnableEXT(in_commandBuffer, attachmentCount, in_pColorWriteEnables);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetColorWriteEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetColorWriteEnableEXT, in_commandBuffer, attachmentCount, in_pColorWriteEnables);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkMultiDrawInfoEXT* in_pVertexInfo = pVertexInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDrawMultiEXT(in_commandBuffer, drawCount, in_pVertexInfo, instanceCount, firstInstance, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawMultiEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawMultiEXT, in_commandBuffer, drawCount, in_pVertexInfo, instanceCount, firstInstance, stride);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkMultiDrawIndexedInfoEXT* in_pIndexInfo = pIndexInfo->GetPointer();
    const int32_t* in_pVertexOffset = pVertexOffset->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDrawMultiIndexedEXT(in_commandBuffer, drawCount, in_pIndexInfo, instanceCount, firstInstance, stride, in_pVertexOffset);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawMultiIndexedEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawMultiIndexedEXT, in_commandBuffer, drawCount, in_pIndexInfo, instanceCount, firstInstance, stride, in_pVertexOffset);
    }
}

void VulkanReplayConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromap)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMicromapCreateInfoEXT* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pMicromap->IsNull()) { pMicromap->SetHandleLength(1); }
    VkMicromapEXT* out_pMicromap = pMicromap->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateMicromapEXT(in_device, in_pCreateInfo, in_pAllocator, out_pMicromap);
    CheckResult("vkCreateMicromapEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanMicromapEXTInfo>(device, pMicromap->GetPointer(), out_pMicromap, &CommonObjectInfoTable::AddVkMicromapEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkMicromapEXT in_micromap = MapHandle<VulkanMicromapEXTInfo>(micromap, &CommonObjectInfoTable::GetVkMicromapEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyMicromapEXT(in_device, in_micromap, in_pAllocator);
    RemoveHandle(micromap, &CommonObjectInfoTable::RemoveVkMicromapEXTInfo);
}

void VulkanReplayConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkMicromapBuildInfoEXT* in_pInfos = pInfos->GetPointer();
    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBuildMicromapsEXT(in_commandBuffer, infoCount, in_pInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBuildMicromapsEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdBuildMicromapsEXT, in_commandBuffer, infoCount, in_pInfos);
    }
}

void VulkanReplayConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkMicromapBuildInfoEXT* in_pInfos = pInfos->GetPointer();
    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->BuildMicromapsEXT(in_device, in_deferredOperation, infoCount, in_pInfos);
    CheckResult("vkBuildMicromapsEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkCopyMicromapInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMicromapEXT(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMicromapEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkCopyMicromapToMemoryInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMicromapToMemoryEXT(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMicromapToMemoryEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkCopyMemoryToMicromapInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMemoryToMicromapEXT(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMemoryToMicromapEXT", returnValue, replay_result, call_info);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMicromapEXT* in_pMicromaps = MapHandles<VulkanMicromapEXTInfo>(pMicromaps, micromapCount, &CommonObjectInfoTable::GetVkMicromapEXTInfo);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->WriteMicromapsPropertiesEXT(in_device, micromapCount, in_pMicromaps, queryType, dataSize, out_pData, stride);
    CheckResult("vkWriteMicromapsPropertiesEXT", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyMicromapInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMicromapEXT(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyMicromapEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyMicromapEXT, in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyMicromapToMemoryInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMicromapToMemoryEXT(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyMicromapToMemoryEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyMicromapToMemoryEXT, in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyMemoryToMicromapInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMemoryToMicromapEXT(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyMemoryToMicromapEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyMemoryToMicromapEXT, in_commandBuffer, in_pInfo);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkMicromapEXT* in_pMicromaps = MapHandles<VulkanMicromapEXTInfo>(pMicromaps, micromapCount, &CommonObjectInfoTable::GetVkMicromapEXTInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteMicromapsPropertiesEXT(in_commandBuffer, micromapCount, in_pMicromaps, queryType, in_queryPool, firstQuery);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWriteMicromapsPropertiesEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdWriteMicromapsPropertiesEXT, in_commandBuffer, micromapCount, in_pMicromaps, queryType, in_queryPool, firstQuery);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMicromapBuildInfoEXT* in_pBuildInfo = pBuildInfo->GetPointer();
    MapStructHandles(pBuildInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMicromapBuildSizesInfoEXT* out_pSizeInfo = pSizeInfo->IsNull() ? nullptr : pSizeInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT, nullptr });
    InitializeOutputStructPNext(pSizeInfo);

    GetDeviceTable(in_device)->GetMicromapBuildSizesEXT(in_device, buildType, in_pBuildInfo, out_pSizeInfo);
}

void VulkanReplayConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawClusterHUAWEI(in_commandBuffer, groupCountX, groupCountY, groupCountZ);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawClusterHUAWEI(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawClusterHUAWEI, in_commandBuffer, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawClusterIndirectHUAWEI(in_commandBuffer, in_buffer, offset);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawClusterIndirectHUAWEI(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawClusterIndirectHUAWEI, in_commandBuffer, in_buffer, offset);
    }
}

void VulkanReplayConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeviceMemory in_memory = MapHandle<VulkanDeviceMemoryInfo>(memory, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);

    GetDeviceTable(in_device)->SetDeviceMemoryPriorityEXT(in_device, in_memory, priority);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDescriptorSetBindingReferenceVALVE* in_pBindingReference = pBindingReference->GetPointer();
    MapStructHandles(pBindingReference->GetMetaStructPointer(), GetObjectInfoTable());
    VkDescriptorSetLayoutHostMappingInfoVALVE* out_pHostMapping = pHostMapping->IsNull() ? nullptr : pHostMapping->AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE, nullptr });
    InitializeOutputStructPNext(pHostMapping);

    GetDeviceTable(in_device)->GetDescriptorSetLayoutHostMappingInfoVALVE(in_device, in_pBindingReference, out_pHostMapping);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDescriptorSet in_descriptorSet = MapHandle<VulkanDescriptorSetInfo>(descriptorSet, &CommonObjectInfoTable::GetVkDescriptorSetInfo);
    void** out_ppData = ppData->IsNull() ? nullptr : ppData->AllocateOutputData(1);

    GetDeviceTable(in_device)->GetDescriptorSetHostMappingVALVE(in_device, in_descriptorSet, out_ppData);

    PostProcessExternalObject(VK_SUCCESS, (*ppData->GetPointer()), *ppData->GetOutputPointer(), format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE, "vkGetDescriptorSetHostMappingVALVE");
}

void VulkanReplayConsumer::Process_vkGetPipelineIndirectMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkComputePipelineCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetPipelineIndirectMemoryRequirementsNV(in_device, in_pCreateInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);

    GetDeviceTable(in_commandBuffer)->CmdUpdatePipelineIndirectBufferNV(in_commandBuffer, pipelineBindPoint, in_pipeline);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdUpdatePipelineIndirectBufferNV(call_info, GetDeviceTable(in_commandBuffer)->CmdUpdatePipelineIndirectBufferNV, in_commandBuffer, pipelineBindPoint, in_pipeline);
    }
}

void VulkanReplayConsumer::Process_vkGetPipelineIndirectDeviceAddressNV(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV>* pInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineIndirectDeviceAddressInfoNV* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetPipelineIndirectDeviceAddressNV(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClampEnableEXT(in_commandBuffer, depthClampEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthClampEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthClampEnableEXT, in_commandBuffer, depthClampEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPolygonModeEXT(in_commandBuffer, polygonMode);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetPolygonModeEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetPolygonModeEXT, in_commandBuffer, polygonMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizationSamplesEXT(in_commandBuffer, rasterizationSamples);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetRasterizationSamplesEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetRasterizationSamplesEXT, in_commandBuffer, rasterizationSamples);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSampleMask* in_pSampleMask = pSampleMask->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetSampleMaskEXT(in_commandBuffer, samples, in_pSampleMask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetSampleMaskEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetSampleMaskEXT, in_commandBuffer, samples, in_pSampleMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetAlphaToCoverageEnableEXT(in_commandBuffer, alphaToCoverageEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetAlphaToCoverageEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetAlphaToCoverageEnableEXT, in_commandBuffer, alphaToCoverageEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetAlphaToOneEnableEXT(in_commandBuffer, alphaToOneEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetAlphaToOneEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetAlphaToOneEnableEXT, in_commandBuffer, alphaToOneEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLogicOpEnableEXT(in_commandBuffer, logicOpEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetLogicOpEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetLogicOpEnableEXT, in_commandBuffer, logicOpEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorBlendEnables)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBool32* in_pColorBlendEnables = pColorBlendEnables->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorBlendEnableEXT(in_commandBuffer, firstAttachment, attachmentCount, in_pColorBlendEnables);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetColorBlendEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetColorBlendEnableEXT, in_commandBuffer, firstAttachment, attachmentCount, in_pColorBlendEnables);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkColorBlendEquationEXT* in_pColorBlendEquations = pColorBlendEquations->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorBlendEquationEXT(in_commandBuffer, firstAttachment, attachmentCount, in_pColorBlendEquations);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetColorBlendEquationEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetColorBlendEquationEXT, in_commandBuffer, firstAttachment, attachmentCount, in_pColorBlendEquations);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkColorComponentFlags* in_pColorWriteMasks = pColorWriteMasks->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorWriteMaskEXT(in_commandBuffer, firstAttachment, attachmentCount, in_pColorWriteMasks);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetColorWriteMaskEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetColorWriteMaskEXT, in_commandBuffer, firstAttachment, attachmentCount, in_pColorWriteMasks);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetTessellationDomainOriginEXT(in_commandBuffer, domainOrigin);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetTessellationDomainOriginEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetTessellationDomainOriginEXT, in_commandBuffer, domainOrigin);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizationStreamEXT(in_commandBuffer, rasterizationStream);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetRasterizationStreamEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetRasterizationStreamEXT, in_commandBuffer, rasterizationStream);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetConservativeRasterizationModeEXT(in_commandBuffer, conservativeRasterizationMode);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetConservativeRasterizationModeEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetConservativeRasterizationModeEXT, in_commandBuffer, conservativeRasterizationMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetExtraPrimitiveOverestimationSizeEXT(in_commandBuffer, extraPrimitiveOverestimationSize);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetExtraPrimitiveOverestimationSizeEXT, in_commandBuffer, extraPrimitiveOverestimationSize);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClipEnableEXT(in_commandBuffer, depthClipEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthClipEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthClipEnableEXT, in_commandBuffer, depthClipEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetSampleLocationsEnableEXT(in_commandBuffer, sampleLocationsEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetSampleLocationsEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetSampleLocationsEnableEXT, in_commandBuffer, sampleLocationsEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkColorBlendAdvancedEXT* in_pColorBlendAdvanced = pColorBlendAdvanced->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorBlendAdvancedEXT(in_commandBuffer, firstAttachment, attachmentCount, in_pColorBlendAdvanced);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetColorBlendAdvancedEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetColorBlendAdvancedEXT, in_commandBuffer, firstAttachment, attachmentCount, in_pColorBlendAdvanced);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetProvokingVertexModeEXT(in_commandBuffer, provokingVertexMode);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetProvokingVertexModeEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetProvokingVertexModeEXT, in_commandBuffer, provokingVertexMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineRasterizationModeEXT(in_commandBuffer, lineRasterizationMode);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetLineRasterizationModeEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetLineRasterizationModeEXT, in_commandBuffer, lineRasterizationMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineStippleEnableEXT(in_commandBuffer, stippledLineEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetLineStippleEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetLineStippleEnableEXT, in_commandBuffer, stippledLineEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClipNegativeOneToOneEXT(in_commandBuffer, negativeOneToOne);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthClipNegativeOneToOneEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthClipNegativeOneToOneEXT, in_commandBuffer, negativeOneToOne);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWScalingEnableNV(in_commandBuffer, viewportWScalingEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetViewportWScalingEnableNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetViewportWScalingEnableNV, in_commandBuffer, viewportWScalingEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkViewportSwizzleNV* in_pViewportSwizzles = pViewportSwizzles->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportSwizzleNV(in_commandBuffer, firstViewport, viewportCount, in_pViewportSwizzles);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetViewportSwizzleNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetViewportSwizzleNV, in_commandBuffer, firstViewport, viewportCount, in_pViewportSwizzles);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageToColorEnableNV(in_commandBuffer, coverageToColorEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetCoverageToColorEnableNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetCoverageToColorEnableNV, in_commandBuffer, coverageToColorEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageToColorLocationNV(in_commandBuffer, coverageToColorLocation);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetCoverageToColorLocationNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetCoverageToColorLocationNV, in_commandBuffer, coverageToColorLocation);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationModeNV(in_commandBuffer, coverageModulationMode);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetCoverageModulationModeNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationModeNV, in_commandBuffer, coverageModulationMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationTableEnableNV(in_commandBuffer, coverageModulationTableEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetCoverageModulationTableEnableNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationTableEnableNV, in_commandBuffer, coverageModulationTableEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const float* in_pCoverageModulationTable = pCoverageModulationTable->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationTableNV(in_commandBuffer, coverageModulationTableCount, in_pCoverageModulationTable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetCoverageModulationTableNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationTableNV, in_commandBuffer, coverageModulationTableCount, in_pCoverageModulationTable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetShadingRateImageEnableNV(in_commandBuffer, shadingRateImageEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetShadingRateImageEnableNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetShadingRateImageEnableNV, in_commandBuffer, shadingRateImageEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRepresentativeFragmentTestEnableNV(in_commandBuffer, representativeFragmentTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetRepresentativeFragmentTestEnableNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetRepresentativeFragmentTestEnableNV, in_commandBuffer, representativeFragmentTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageReductionModeNV(in_commandBuffer, coverageReductionMode);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetCoverageReductionModeNV(call_info, GetDeviceTable(in_commandBuffer)->CmdSetCoverageReductionModeNV, in_commandBuffer, coverageReductionMode);
    }
}

void VulkanReplayConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkShaderModule in_shaderModule = MapHandle<VulkanShaderModuleInfo>(shaderModule, &CommonObjectInfoTable::GetVkShaderModuleInfo);
    VkShaderModuleIdentifierEXT* out_pIdentifier = pIdentifier->IsNull() ? nullptr : pIdentifier->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT, nullptr });
    InitializeOutputStructPNext(pIdentifier);

    GetDeviceTable(in_device)->GetShaderModuleIdentifierEXT(in_device, in_shaderModule, out_pIdentifier);
}

void VulkanReplayConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkShaderModuleCreateInfo* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkShaderModuleIdentifierEXT* out_pIdentifier = pIdentifier->IsNull() ? nullptr : pIdentifier->AllocateOutputData(1, { VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT, nullptr });
    InitializeOutputStructPNext(pIdentifier);

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
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkOpticalFlowImageFormatInfoNV* in_pOpticalFlowImageFormatInfo = pOpticalFlowImageFormatInfo->GetPointer();
    uint32_t* out_pFormatCount = pFormatCount->IsNull() ? nullptr : pFormatCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceOpticalFlowImageFormatsNV", returnValue, physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceOpticalFlowImageFormatsNV, pFormatCount, pImageFormatProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkOpticalFlowImageFormatPropertiesNV* out_pImageFormatProperties = pImageFormatProperties->IsNull() ? nullptr : pImageFormatProperties->AllocateOutputData(*out_pFormatCount, VkOpticalFlowImageFormatPropertiesNV{ VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceOpticalFlowImageFormatsNV(in_physicalDevice, in_pOpticalFlowImageFormatInfo, out_pFormatCount, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceOpticalFlowImageFormatsNV", returnValue, replay_result, call_info);

    if (pImageFormatProperties->IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceOpticalFlowImageFormatsNV, *out_pFormatCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkOpticalFlowSessionCreateInfoNV* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pSession->IsNull()) { pSession->SetHandleLength(1); }
    VkOpticalFlowSessionNV* out_pSession = pSession->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateOpticalFlowSessionNV(in_device, in_pCreateInfo, in_pAllocator, out_pSession);
    CheckResult("vkCreateOpticalFlowSessionNV", returnValue, replay_result, call_info);

    AddHandle<VulkanOpticalFlowSessionNVInfo>(device, pSession->GetPointer(), out_pSession, &CommonObjectInfoTable::AddVkOpticalFlowSessionNVInfo);
}

void VulkanReplayConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkOpticalFlowSessionNV in_session = MapHandle<VulkanOpticalFlowSessionNVInfo>(session, &CommonObjectInfoTable::GetVkOpticalFlowSessionNVInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyOpticalFlowSessionNV(in_device, in_session, in_pAllocator);
    RemoveHandle(session, &CommonObjectInfoTable::RemoveVkOpticalFlowSessionNVInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkOpticalFlowSessionNV in_session = MapHandle<VulkanOpticalFlowSessionNVInfo>(session, &CommonObjectInfoTable::GetVkOpticalFlowSessionNVInfo);
    VkImageView in_view = MapHandle<VulkanImageViewInfo>(view, &CommonObjectInfoTable::GetVkImageViewInfo);

    VkResult replay_result = GetDeviceTable(in_device)->BindOpticalFlowSessionImageNV(in_device, in_session, bindingPoint, in_view, layout);
    CheckResult("vkBindOpticalFlowSessionImageNV", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkOpticalFlowSessionNV in_session = MapHandle<VulkanOpticalFlowSessionNVInfo>(session, &CommonObjectInfoTable::GetVkOpticalFlowSessionNVInfo);
    const VkOpticalFlowExecuteInfoNV* in_pExecuteInfo = pExecuteInfo->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdOpticalFlowExecuteNV(in_commandBuffer, in_session, in_pExecuteInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdOpticalFlowExecuteNV(call_info, GetDeviceTable(in_commandBuffer)->CmdOpticalFlowExecuteNV, in_commandBuffer, in_session, in_pExecuteInfo);
    }
}

void VulkanReplayConsumer::Process_vkAntiLagUpdateAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAntiLagDataAMD>* pData)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAntiLagDataAMD* in_pData = pData->GetPointer();

    GetDeviceTable(in_device)->AntiLagUpdateAMD(in_device, in_pData);
}

void VulkanReplayConsumer::Process_vkCreateShadersEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkShaderCreateInfoEXT>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructArrayHandles(pCreateInfos->GetMetaStructPointer(), pCreateInfos->GetLength(), GetObjectInfoTable());
    if (!pShaders->IsNull()) { pShaders->SetHandleLength(createInfoCount); }
    std::vector<VulkanShaderEXTInfo> handle_info(createInfoCount);
    for (size_t i = 0; i < createInfoCount; ++i) { pShaders->SetConsumerData(i, &handle_info[i]); }

    if (UseAsyncOperations())
    {
        auto task = AsyncCreateShadersEXT(call_info, returnValue, in_device, createInfoCount, pCreateInfos, pAllocator, pShaders);
        if(task)
        {
           AddHandlesAsync<VulkanShaderEXTInfo>(device, pShaders->GetPointer(), pShaders->GetLength(), std::move(handle_info), &VulkanObjectInfoTable::AddVkShaderEXTInfo, std::move(task));
           return;
        }
    }
    VkResult replay_result = OverrideCreateShadersEXT(GetDeviceTable(in_device->handle)->CreateShadersEXT, returnValue, in_device, createInfoCount, pCreateInfos, pAllocator, pShaders);
    CheckResult("vkCreateShadersEXT", returnValue, replay_result, call_info);

    AddHandles<VulkanShaderEXTInfo>(device, pShaders->GetPointer(), pShaders->GetLength(), pShaders->GetHandlePointer(), createInfoCount, std::move(handle_info), &CommonObjectInfoTable::AddVkShaderEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shader,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkShaderEXT in_shader = MapHandle<VulkanShaderEXTInfo>(shader, &CommonObjectInfoTable::GetVkShaderEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyShaderEXT(in_device, in_shader, in_pAllocator);
    RemoveHandle(shader, &CommonObjectInfoTable::RemoveVkShaderEXTInfo);
}

void VulkanReplayConsumer::Process_vkGetShaderBinaryDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            shader,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkShaderEXT in_shader = MapHandle<VulkanShaderEXTInfo>(shader, &CommonObjectInfoTable::GetVkShaderEXTInfo);
    size_t* out_pDataSize = pDataSize->IsNull() ? nullptr : pDataSize->AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanShaderEXTInfo>("vkGetShaderBinaryDataEXT", returnValue, shader, kShaderEXTArrayGetShaderBinaryDataEXT, pDataSize, pData, &CommonObjectInfoTable::GetVkShaderEXTInfo));
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(*out_pDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetShaderBinaryDataEXT(in_device, in_shader, out_pDataSize, out_pData);
    CheckResult("vkGetShaderBinaryDataEXT", returnValue, replay_result, call_info);

    if (pData->IsNull()) { SetOutputArrayCount<VulkanShaderEXTInfo>(shader, kShaderEXTArrayGetShaderBinaryDataEXT, *out_pDataSize, &CommonObjectInfoTable::GetVkShaderEXTInfo); }
}

void VulkanReplayConsumer::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    stageCount,
    PointerDecoder<VkShaderStageFlagBits>*      pStages,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkShaderStageFlagBits* in_pStages = pStages->GetPointer();
    const VkShaderEXT* in_pShaders = MapHandles<VulkanShaderEXTInfo>(pShaders, stageCount, &CommonObjectInfoTable::GetVkShaderEXTInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindShadersEXT(in_commandBuffer, stageCount, in_pStages, in_pShaders);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBindShadersEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdBindShadersEXT, in_commandBuffer, stageCount, in_pStages, in_pShaders);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDepthClampModeEXT                         depthClampMode,
    StructPointerDecoder<Decoded_VkDepthClampRangeEXT>* pDepthClampRange)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDepthClampRangeEXT* in_pDepthClampRange = pDepthClampRange->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClampRangeEXT(in_commandBuffer, depthClampMode, in_pDepthClampRange);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetDepthClampRangeEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetDepthClampRangeEXT, in_commandBuffer, depthClampMode, in_pDepthClampRange);
    }
}

void VulkanReplayConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    PointerDecoder<uint32_t>*                   pPropertiesCount,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkFramebuffer in_framebuffer = MapHandle<VulkanFramebufferInfo>(framebuffer, &CommonObjectInfoTable::GetVkFramebufferInfo);
    uint32_t* out_pPropertiesCount = pPropertiesCount->IsNull() ? nullptr : pPropertiesCount->AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanFramebufferInfo>("vkGetFramebufferTilePropertiesQCOM", returnValue, framebuffer, kFramebufferArrayGetFramebufferTilePropertiesQCOM, pPropertiesCount, pProperties, &CommonObjectInfoTable::GetVkFramebufferInfo));
    VkTilePropertiesQCOM* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(*out_pPropertiesCount, VkTilePropertiesQCOM{ VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetFramebufferTilePropertiesQCOM(in_device, in_framebuffer, out_pPropertiesCount, out_pProperties);
    CheckResult("vkGetFramebufferTilePropertiesQCOM", returnValue, replay_result, call_info);

    if (pProperties->IsNull()) { SetOutputArrayCount<VulkanFramebufferInfo>(framebuffer, kFramebufferArrayGetFramebufferTilePropertiesQCOM, *out_pPropertiesCount, &CommonObjectInfoTable::GetVkFramebufferInfo); }
}

void VulkanReplayConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkRenderingInfo* in_pRenderingInfo = pRenderingInfo->GetPointer();
    MapStructHandles(pRenderingInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkTilePropertiesQCOM* out_pProperties = pProperties->IsNull() ? nullptr : pProperties->AllocateOutputData(1, { VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM, nullptr });
    InitializeOutputStructPNext(pProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetDynamicRenderingTilePropertiesQCOM(in_device, in_pRenderingInfo, out_pProperties);
    CheckResult("vkGetDynamicRenderingTilePropertiesQCOM", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSetLatencySleepModeNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkLatencySleepModeInfoNV>* pSleepModeInfo)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkSetLatencySleepModeNV for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }
    const VkLatencySleepModeInfoNV* in_pSleepModeInfo = pSleepModeInfo->GetPointer();

    VkResult replay_result = GetDeviceTable(in_device)->SetLatencySleepModeNV(in_device, in_swapchain, in_pSleepModeInfo);
    CheckResult("vkSetLatencySleepModeNV", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkLatencySleepNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkLatencySleepInfoNV>* pSleepInfo)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkLatencySleepNV for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }
    const VkLatencySleepInfoNV* in_pSleepInfo = pSleepInfo->GetPointer();
    MapStructHandles(pSleepInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->LatencySleepNV(in_device, in_swapchain, in_pSleepInfo);
    CheckResult("vkLatencySleepNV", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSetLatencyMarkerNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkSetLatencyMarkerInfoNV>* pLatencyMarkerInfo)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkSetLatencyMarkerNV for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }
    const VkSetLatencyMarkerInfoNV* in_pLatencyMarkerInfo = pLatencyMarkerInfo->GetPointer();

    GetDeviceTable(in_device)->SetLatencyMarkerNV(in_device, in_swapchain, in_pLatencyMarkerInfo);
}

void VulkanReplayConsumer::Process_vkGetLatencyTimingsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkGetLatencyMarkerInfoNV>* pLatencyMarkerInfo)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetLatencyTimingsNV for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(swapchain)->surface_id)->surface_creation_skipped) { return; }
    VkGetLatencyMarkerInfoNV* out_pLatencyMarkerInfo = pLatencyMarkerInfo->IsNull() ? nullptr : pLatencyMarkerInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV, nullptr });
    InitializeOutputStructPNext(pLatencyMarkerInfo);

    GetDeviceTable(in_device)->GetLatencyTimingsNV(in_device, in_swapchain, out_pLatencyMarkerInfo);
}

void VulkanReplayConsumer::Process_vkQueueNotifyOutOfBandNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkOutOfBandQueueTypeInfoNV>* pQueueTypeInfo)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(queue, &CommonObjectInfoTable::GetVkQueueInfo);
    const VkOutOfBandQueueTypeInfoNV* in_pQueueTypeInfo = pQueueTypeInfo->GetPointer();

    GetDeviceTable(in_queue)->QueueNotifyOutOfBandNV(in_queue, in_pQueueTypeInfo);
}

void VulkanReplayConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetAttachmentFeedbackLoopEnableEXT(in_commandBuffer, aspectMask);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdSetAttachmentFeedbackLoopEnableEXT, in_commandBuffer, aspectMask);
    }
}

void VulkanReplayConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkGeneratedCommandsMemoryRequirementsInfoEXT* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = pMemoryRequirements->IsNull() ? nullptr : pMemoryRequirements->AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(pMemoryRequirements);

    GetDeviceTable(in_device)->GetGeneratedCommandsMemoryRequirementsEXT(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo,
    format::HandleId                            stateCommandBuffer)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkGeneratedCommandsInfoEXT* in_pGeneratedCommandsInfo = pGeneratedCommandsInfo->GetPointer();
    MapStructHandles(pGeneratedCommandsInfo->GetMetaStructPointer(), GetObjectInfoTable());
    VkCommandBuffer in_stateCommandBuffer = MapHandle<VulkanCommandBufferInfo>(stateCommandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdPreprocessGeneratedCommandsEXT(in_commandBuffer, in_pGeneratedCommandsInfo, in_stateCommandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdPreprocessGeneratedCommandsEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdPreprocessGeneratedCommandsEXT, in_commandBuffer, in_pGeneratedCommandsInfo, in_stateCommandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkGeneratedCommandsInfoEXT* in_pGeneratedCommandsInfo = pGeneratedCommandsInfo->GetPointer();
    MapStructHandles(pGeneratedCommandsInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdExecuteGeneratedCommandsEXT(in_commandBuffer, isPreprocessed, in_pGeneratedCommandsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdExecuteGeneratedCommandsEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdExecuteGeneratedCommandsEXT, in_commandBuffer, isPreprocessed, in_pGeneratedCommandsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutEXT>* pIndirectCommandsLayout)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkIndirectCommandsLayoutCreateInfoEXT* in_pCreateInfo = pCreateInfo->GetPointer();
    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pIndirectCommandsLayout->IsNull()) { pIndirectCommandsLayout->SetHandleLength(1); }
    VkIndirectCommandsLayoutEXT* out_pIndirectCommandsLayout = pIndirectCommandsLayout->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateIndirectCommandsLayoutEXT(in_device, in_pCreateInfo, in_pAllocator, out_pIndirectCommandsLayout);
    CheckResult("vkCreateIndirectCommandsLayoutEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanIndirectCommandsLayoutEXTInfo>(device, pIndirectCommandsLayout->GetPointer(), out_pIndirectCommandsLayout, &CommonObjectInfoTable::AddVkIndirectCommandsLayoutEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkIndirectCommandsLayoutEXT in_indirectCommandsLayout = MapHandle<VulkanIndirectCommandsLayoutEXTInfo>(indirectCommandsLayout, &CommonObjectInfoTable::GetVkIndirectCommandsLayoutEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyIndirectCommandsLayoutEXT(in_device, in_indirectCommandsLayout, in_pAllocator);
    RemoveHandle(indirectCommandsLayout, &CommonObjectInfoTable::RemoveVkIndirectCommandsLayoutEXTInfo);
}

void VulkanReplayConsumer::Process_vkCreateIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectExecutionSetCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectExecutionSetEXT>* pIndirectExecutionSet)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkIndirectExecutionSetCreateInfoEXT* in_pCreateInfo = pCreateInfo->GetPointer();
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);
    if (!pIndirectExecutionSet->IsNull()) { pIndirectExecutionSet->SetHandleLength(1); }
    VkIndirectExecutionSetEXT* out_pIndirectExecutionSet = pIndirectExecutionSet->GetHandlePointer();

    VkResult replay_result = GetDeviceTable(in_device)->CreateIndirectExecutionSetEXT(in_device, in_pCreateInfo, in_pAllocator, out_pIndirectExecutionSet);
    CheckResult("vkCreateIndirectExecutionSetEXT", returnValue, replay_result, call_info);

    AddHandle<VulkanIndirectExecutionSetEXTInfo>(device, pIndirectExecutionSet->GetPointer(), out_pIndirectExecutionSet, &CommonObjectInfoTable::AddVkIndirectExecutionSetEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectExecutionSet,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkIndirectExecutionSetEXT in_indirectExecutionSet = MapHandle<VulkanIndirectExecutionSetEXTInfo>(indirectExecutionSet, &CommonObjectInfoTable::GetVkIndirectExecutionSetEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(pAllocator);

    GetDeviceTable(in_device)->DestroyIndirectExecutionSetEXT(in_device, in_indirectExecutionSet, in_pAllocator);
    RemoveHandle(indirectExecutionSet, &CommonObjectInfoTable::RemoveVkIndirectExecutionSetEXTInfo);
}

void VulkanReplayConsumer::Process_vkUpdateIndirectExecutionSetPipelineEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectExecutionSet,
    uint32_t                                    executionSetWriteCount,
    StructPointerDecoder<Decoded_VkWriteIndirectExecutionSetPipelineEXT>* pExecutionSetWrites)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkIndirectExecutionSetEXT in_indirectExecutionSet = MapHandle<VulkanIndirectExecutionSetEXTInfo>(indirectExecutionSet, &CommonObjectInfoTable::GetVkIndirectExecutionSetEXTInfo);
    const VkWriteIndirectExecutionSetPipelineEXT* in_pExecutionSetWrites = pExecutionSetWrites->GetPointer();
    MapStructArrayHandles(pExecutionSetWrites->GetMetaStructPointer(), pExecutionSetWrites->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_device)->UpdateIndirectExecutionSetPipelineEXT(in_device, in_indirectExecutionSet, executionSetWriteCount, in_pExecutionSetWrites);
}

void VulkanReplayConsumer::Process_vkUpdateIndirectExecutionSetShaderEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectExecutionSet,
    uint32_t                                    executionSetWriteCount,
    StructPointerDecoder<Decoded_VkWriteIndirectExecutionSetShaderEXT>* pExecutionSetWrites)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkIndirectExecutionSetEXT in_indirectExecutionSet = MapHandle<VulkanIndirectExecutionSetEXTInfo>(indirectExecutionSet, &CommonObjectInfoTable::GetVkIndirectExecutionSetEXTInfo);
    const VkWriteIndirectExecutionSetShaderEXT* in_pExecutionSetWrites = pExecutionSetWrites->GetPointer();
    MapStructArrayHandles(pExecutionSetWrites->GetMetaStructPointer(), pExecutionSetWrites->GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_device)->UpdateIndirectExecutionSetShaderEXT(in_device, in_indirectExecutionSet, executionSetWriteCount, in_pExecutionSetWrites);
}

void VulkanReplayConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pCreateInfo->GetMetaStructPointer(), GetObjectInfoTable());
    if (!pAccelerationStructure->IsNull()) { pAccelerationStructure->SetHandleLength(1); }
    VulkanAccelerationStructureKHRInfo handle_info;
    pAccelerationStructure->SetConsumerData(0, &handle_info);

    VkResult replay_result = OverrideCreateAccelerationStructureKHR(GetDeviceTable(in_device->handle)->CreateAccelerationStructureKHR, returnValue, in_device, pCreateInfo, pAllocator, pAccelerationStructure);
    CheckResult("vkCreateAccelerationStructureKHR", returnValue, replay_result, call_info);

    AddHandle<VulkanAccelerationStructureKHRInfo>(device, pAccelerationStructure->GetPointer(), pAccelerationStructure->GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkAccelerationStructureKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);
    auto in_accelerationStructure = GetObjectInfoTable().GetVkAccelerationStructureKHRInfo(accelerationStructure);

    OverrideDestroyAccelerationStructureKHR(GetDeviceTable(in_device->handle)->DestroyAccelerationStructureKHR, in_device, in_accelerationStructure, pAllocator);
    RemoveHandle(accelerationStructure, &CommonObjectInfoTable::RemoveVkAccelerationStructureKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());

    OverrideCmdBuildAccelerationStructuresKHR(GetDeviceTable(in_commandBuffer->handle)->CmdBuildAccelerationStructuresKHR, in_commandBuffer, infoCount, pInfos, ppBuildRangeInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBuildAccelerationStructuresKHR(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdBuildAccelerationStructuresKHR, in_commandBuffer->handle, infoCount, pInfos->GetPointer(), ppBuildRangeInfos->GetPointer());
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkAccelerationStructureBuildGeometryInfoKHR* in_pInfos = pInfos->GetPointer();
    MapStructArrayHandles(pInfos->GetMetaStructPointer(), pInfos->GetLength(), GetObjectInfoTable());
    const VkDeviceAddress* in_pIndirectDeviceAddresses = pIndirectDeviceAddresses->GetPointer();
    const uint32_t* in_pIndirectStrides = pIndirectStrides->GetPointer();
    const uint32_t* const* in_ppMaxPrimitiveCounts = ppMaxPrimitiveCounts->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBuildAccelerationStructuresIndirectKHR(in_commandBuffer, infoCount, in_pInfos, in_pIndirectDeviceAddresses, in_pIndirectStrides, in_ppMaxPrimitiveCounts);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdBuildAccelerationStructuresIndirectKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdBuildAccelerationStructuresIndirectKHR, in_commandBuffer, infoCount, in_pInfos, in_pIndirectDeviceAddresses, in_pIndirectStrides, in_ppMaxPrimitiveCounts);
    }
}

void VulkanReplayConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkCopyAccelerationStructureToMemoryInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyAccelerationStructureToMemoryKHR(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyAccelerationStructureToMemoryKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkCopyMemoryToAccelerationStructureInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMemoryToAccelerationStructureKHR(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMemoryToAccelerationStructureKHR", returnValue, replay_result, call_info);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAccelerationStructureKHR* in_pAccelerationStructures = MapHandles<VulkanAccelerationStructureKHRInfo>(pAccelerationStructures, accelerationStructureCount, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->WriteAccelerationStructuresPropertiesKHR(in_device, accelerationStructureCount, in_pAccelerationStructures, queryType, dataSize, out_pData, stride);
    CheckResult("vkWriteAccelerationStructuresPropertiesKHR", returnValue, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdCopyAccelerationStructureKHR(GetDeviceTable(in_commandBuffer->handle)->CmdCopyAccelerationStructureKHR, in_commandBuffer, pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyAccelerationStructureKHR(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdCopyAccelerationStructureKHR, in_commandBuffer->handle, pInfo->GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyAccelerationStructureToMemoryInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyAccelerationStructureToMemoryKHR(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyAccelerationStructureToMemoryKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyAccelerationStructureToMemoryKHR, in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyMemoryToAccelerationStructureInfoKHR* in_pInfo = pInfo->GetPointer();
    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMemoryToAccelerationStructureKHR(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdCopyMemoryToAccelerationStructureKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdCopyMemoryToAccelerationStructureKHR, in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(device);

    MapStructHandles(pInfo->GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetAccelerationStructureDeviceAddressKHR(GetDeviceTable(in_device->handle)->GetAccelerationStructureDeviceAddressKHR, returnValue, in_device, pInfo);
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
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);
    MapHandles<VulkanAccelerationStructureKHRInfo>(pAccelerationStructures, accelerationStructureCount, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(queryPool);

    OverrideCmdWriteAccelerationStructuresPropertiesKHR(GetDeviceTable(in_commandBuffer->handle)->CmdWriteAccelerationStructuresPropertiesKHR, in_commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, in_queryPool, firstQuery);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdWriteAccelerationStructuresPropertiesKHR(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdWriteAccelerationStructuresPropertiesKHR, in_commandBuffer->handle, accelerationStructureCount, pAccelerationStructures->GetHandlePointer(), queryType, in_queryPool->handle, firstQuery);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAccelerationStructureBuildGeometryInfoKHR* in_pBuildInfo = pBuildInfo->GetPointer();
    MapStructHandles(pBuildInfo->GetMetaStructPointer(), GetObjectInfoTable());
    const uint32_t* in_pMaxPrimitiveCounts = pMaxPrimitiveCounts->GetPointer();
    VkAccelerationStructureBuildSizesInfoKHR* out_pSizeInfo = pSizeInfo->IsNull() ? nullptr : pSizeInfo->AllocateOutputData(1, { VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR, nullptr });
    InitializeOutputStructPNext(pSizeInfo);

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
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(commandBuffer);

    OverrideCmdTraceRaysKHR(GetDeviceTable(in_commandBuffer->handle)->CmdTraceRaysKHR, in_commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdTraceRaysKHR(call_info, GetDeviceTable(in_commandBuffer->handle)->CmdTraceRaysKHR, in_commandBuffer->handle, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    }
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
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);
    void* out_pData = pData->IsNull() ? nullptr : pData->AllocateOutputData(dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR(in_device, in_pipeline, firstGroup, groupCount, dataSize, out_pData);
    CheckResult("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", returnValue, replay_result, call_info);
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdTraceRaysIndirectKHR(in_commandBuffer, in_pRaygenShaderBindingTable, in_pMissShaderBindingTable, in_pHitShaderBindingTable, in_pCallableShaderBindingTable, indirectDeviceAddress);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdTraceRaysIndirectKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdTraceRaysIndirectKHR, in_commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
    }
}

void VulkanReplayConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceSize                                returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);

    GetDeviceTable(in_device)->GetRayTracingShaderGroupStackSizeKHR(in_device, in_pipeline, group, groupShader);
}

void VulkanReplayConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRayTracingPipelineStackSizeKHR(in_commandBuffer, pipelineStackSize);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdSetRayTracingPipelineStackSizeKHR(call_info, GetDeviceTable(in_commandBuffer)->CmdSetRayTracingPipelineStackSizeKHR, in_commandBuffer, pipelineStackSize);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksEXT(in_commandBuffer, groupCountX, groupCountY, groupCountZ);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawMeshTasksEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksEXT, in_commandBuffer, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectEXT(in_commandBuffer, in_buffer, offset, drawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawMeshTasksIndirectEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectEXT, in_commandBuffer, in_buffer, offset, drawCount, stride);
    }
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
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectCountEXT(in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);

    if (options_.dumping_resources)
    {
        resource_dumper_.Process_vkCmdDrawMeshTasksIndirectCountEXT(call_info, GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectCountEXT, in_commandBuffer, in_buffer, offset, in_countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

static void InitializeOutputStructPNextImpl(const VkBaseInStructure* in_pnext, VkBaseOutStructure* output_struct)
{
    while(in_pnext)
    {
        switch(in_pnext->sType)
        {
            case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferMemoryBarrier>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageMemoryBarrier>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryBarrier>());
                break;
            }
            case VK_STRUCTURE_TYPE_APPLICATION_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkApplicationInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkInstanceCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceQueueCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBMIT_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubmitInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMappedMemoryRange>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryAllocateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindSparseInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFenceCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSemaphoreCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkEventCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueryPoolCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferViewCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkShaderModuleCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineCacheCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineShaderStageCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkComputePipelineCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineVertexInputStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineInputAssemblyStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineTessellationStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineViewportStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRasterizationStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineMultisampleStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineDepthStencilStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineColorBlendStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineDynamicStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGraphicsPipelineCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineLayoutCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyDescriptorSet>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorPoolCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorSetAllocateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorSetLayoutCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWriteDescriptorSet>());
                break;
            }
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFramebufferCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCommandPoolCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCommandBufferAllocateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCommandBufferInheritanceInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCommandBufferBeginInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassBeginInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSubgroupProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindBufferMemoryInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindImageMemoryInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevice16BitStorageFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryDedicatedRequirements>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryDedicatedAllocateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryAllocateFlagsInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceGroupRenderPassBeginInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceGroupCommandBufferBeginInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceGroupSubmitInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceGroupBindSparseInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindBufferMemoryDeviceGroupInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindImageMemoryDeviceGroupInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceGroupProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceGroupDeviceCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferMemoryRequirementsInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageMemoryRequirementsInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageSparseMemoryRequirementsInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryRequirements2>());
                break;
            }
            case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSparseImageMemoryRequirements2>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFeatures2>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceProperties2>());
                break;
            }
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFormatProperties2>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageFormatProperties2>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageFormatInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyProperties2>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMemoryProperties2>());
                break;
            }
            case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSparseImageFormatProperties2>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSparseImageFormatInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePointClippingProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassInputAttachmentAspectCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewUsageCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineTessellationDomainOriginStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassMultiviewCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMultiviewFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMultiviewProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVariablePointersFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceProtectedMemoryFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceProtectedMemoryProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceQueueInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkProtectedSubmitInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerYcbcrConversionCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerYcbcrConversionInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindImagePlaneMemoryInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImagePlaneMemoryRequirementsInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSamplerYcbcrConversionFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerYcbcrConversionImageFormatProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorUpdateTemplateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExternalImageFormatInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalImageFormatProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExternalBufferInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalBufferProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceIDProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalMemoryImageCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalMemoryBufferCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExportMemoryAllocateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExternalFenceInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalFenceProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExportFenceCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExportSemaphoreCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExternalSemaphoreInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalSemaphoreProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance3Properties>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorSetLayoutSupport>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderDrawParametersFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVulkan11Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVulkan11Properties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVulkan12Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVulkan12Properties>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageFormatListCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAttachmentDescription2>());
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAttachmentReference2>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubpassDescription2>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubpassDependency2>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassCreateInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubpassBeginInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_END_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubpassEndInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevice8BitStorageFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDriverProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderAtomicInt64Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderFloat16Int8Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFloatControlsProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorSetLayoutBindingFlagsCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDescriptorIndexingFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDescriptorIndexingProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorSetVariableDescriptorCountAllocateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorSetVariableDescriptorCountLayoutSupport>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubpassDescriptionDepthStencilResolve>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDepthStencilResolveProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceScalarBlockLayoutFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageStencilUsageCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerReductionModeCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSamplerFilterMinmaxProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVulkanMemoryModelFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImagelessFramebufferFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFramebufferAttachmentImageInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFramebufferAttachmentsCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassAttachmentBeginInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceUniformBufferStandardLayoutFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAttachmentReferenceStencilLayout>());
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAttachmentDescriptionStencilLayout>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceHostQueryResetFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTimelineSemaphoreFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTimelineSemaphoreProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSemaphoreTypeCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTimelineSemaphoreSubmitInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSemaphoreWaitInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSemaphoreSignalInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceBufferDeviceAddressFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferDeviceAddressInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferOpaqueCaptureAddressCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryOpaqueCaptureAddressAllocateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceMemoryOpaqueCaptureAddressInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVulkan13Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVulkan13Properties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineCreationFeedbackCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderTerminateInvocationFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceToolProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePrivateDataFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDevicePrivateDataCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPrivateDataSlotCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineCreationCacheControlFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryBarrier2>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferMemoryBarrier2>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageMemoryBarrier2>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEPENDENCY_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDependencyInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSemaphoreSubmitInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCommandBufferSubmitInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBMIT_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubmitInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSynchronization2Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageRobustnessFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_COPY_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferCopy2>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyBufferInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_COPY_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageCopy2>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyImageInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferImageCopy2>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyBufferToImageInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyImageToBufferInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_BLIT_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageBlit2>());
                break;
            }
            case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBlitImageInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageResolve2>());
                break;
            }
            case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkResolveImageInfo2>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSubgroupSizeControlFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSubgroupSizeControlProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineShaderStageRequiredSubgroupSizeCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceInlineUniformBlockFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceInlineUniformBlockProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWriteDescriptorSetInlineUniformBlock>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorPoolInlineUniformBlockCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTextureCompressionASTCHDRFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingAttachmentInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRenderingCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDynamicRenderingFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCommandBufferInheritanceRenderingInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderIntegerDotProductFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderIntegerDotProductProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTexelBufferAlignmentProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFormatProperties3>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance4Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance4Properties>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceBufferMemoryRequirements>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceImageMemoryRequirements>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPresentInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageSwapchainCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindImageMemorySwapchainInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAcquireNextImageInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceGroupPresentCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceGroupPresentInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceGroupSwapchainCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayModeCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplaySurfaceCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayPresentInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkXlibSurfaceCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkXcbSurfaceCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWaylandSurfaceCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAndroidSurfaceCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWin32SurfaceCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyQueryResultStatusPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyVideoPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoProfileInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoProfileListInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVideoFormatInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoFormatPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoPictureResourceInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoReferenceSlotInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoSessionMemoryRequirementsKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindVideoSessionMemoryInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoSessionCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoSessionParametersCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoSessionParametersUpdateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoBeginCodingInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEndCodingInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoCodingControlInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeUsageInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264CapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264QualityLevelPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264SessionCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264SessionParametersAddInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264SessionParametersCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264SessionParametersGetInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264SessionParametersFeedbackInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264NaluSliceInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264PictureInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264DpbSlotInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264ProfileInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264RateControlInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264RateControlLayerInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264GopRemainingFrameInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265CapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265SessionCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265QualityLevelPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265SessionParametersAddInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265SessionParametersCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265SessionParametersGetInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265SessionParametersFeedbackInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265NaluSliceSegmentInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265PictureInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265DpbSlotInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265ProfileInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265RateControlInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265RateControlLayerInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265GopRemainingFrameInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH264ProfileInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH264CapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH264SessionParametersAddInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH264SessionParametersCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH264PictureInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH264DpbSlotInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingFragmentShadingRateAttachmentInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingFragmentDensityMapAttachmentInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAttachmentSampleCountInfoAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMultiviewPerViewAttributesInfoNVX>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportMemoryWin32HandleInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExportMemoryWin32HandleInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryWin32HandlePropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryGetWin32HandleInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportMemoryFdInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryFdPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryGetFdInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWin32KeyedMutexAcquireReleaseInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportSemaphoreWin32HandleInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExportSemaphoreWin32HandleInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkD3D12FenceSubmitInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSemaphoreGetWin32HandleInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportSemaphoreFdInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSemaphoreGetFdInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePushDescriptorPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPresentRegionsKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSharedPresentSurfaceCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportFenceWin32HandleInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExportFenceWin32HandleInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFenceGetWin32HandleInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportFenceFdInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFenceGetFdInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePerformanceQueryFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePerformanceQueryPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerformanceCounterKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerformanceCounterDescriptionKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueryPoolPerformanceCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAcquireProfilingLockInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerformanceQuerySubmitInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSurfaceInfo2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfaceCapabilities2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfaceFormat2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayProperties2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayPlaneProperties2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayModeProperties2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayPlaneInfo2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayPlaneCapabilities2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePortabilitySubsetFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePortabilitySubsetPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderClockFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH265ProfileInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH265CapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH265SessionParametersAddInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH265SessionParametersCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH265PictureInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeH265DpbSlotInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceQueueGlobalPriorityCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyGlobalPriorityPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFragmentShadingRateAttachmentInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineFragmentShadingRateStateCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentShadingRateFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentShadingRatePropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentShadingRateKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingAttachmentLocationInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingInputAttachmentIndexInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderQuadControlFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfaceProtectedCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePresentWaitFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineExecutablePropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineExecutableInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineExecutableStatisticKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineExecutableInternalRepresentationKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryMapInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryUnmapInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineLibraryCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPresentIdKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePresentIdFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueryPoolVideoEncodeFeedbackCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeUsageInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeRateControlLayerInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeRateControlInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeQualityLevelPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeQualityLevelInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeSessionParametersGetInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeSessionParametersFeedbackInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyCheckpointProperties2NV>());
                break;
            }
            case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCheckpointData2NV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance5FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance5PropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingAreaInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageSubresource2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceImageSubresourceInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubresourceLayout2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineCreateFlags2CreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferUsageFlags2CreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineBinaryFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineBinaryPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDevicePipelineBinaryInternalCacheControlKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineBinaryKeyKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineBinaryCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineBinaryInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkReleaseCapturedPipelineDataInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineBinaryDataInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineBinaryHandlesInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCooperativeMatrixPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeMatrixFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeMatrixPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeAV1ProfileInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeAV1CapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeAV1SessionParametersCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeAV1PictureInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeAV1DpbSlotInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVideoMaintenance1FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoInlineQueryInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineVertexInputDivisorStateCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderFloatControls2FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceIndexTypeUint8FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLineRasterizationFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLineRasterizationPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRasterizationLineStateCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCalibratedTimestampInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderExpectAssumeFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance6FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance6PropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindMemoryStatusKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindDescriptorSetsInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPushConstantsInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPushDescriptorSetInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPushDescriptorSetWithTemplateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSetDescriptorBufferOffsetsInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindDescriptorBufferEmbeddedSamplersInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance7FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance7PropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLayeredApiPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLayeredApiPropertiesListKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLayeredApiVulkanPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDebugReportCallbackCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRasterizationStateRasterizationOrderAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDebugMarkerObjectNameInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDebugMarkerObjectTagInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDebugMarkerMarkerInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDedicatedAllocationImageCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDedicatedAllocationBufferCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDedicatedAllocationMemoryAllocateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTransformFeedbackFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTransformFeedbackPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRasterizationStateStreamCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewHandleInfoNVX>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewAddressPropertiesNVX>());
                break;
            }
            case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTextureLODGatherFormatPropertiesAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkStreamDescriptorSurfaceCreateInfoGGP>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCornerSampledImageFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalMemoryImageCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExportMemoryAllocateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportMemoryWin32HandleInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExportMemoryWin32HandleInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWin32KeyedMutexAcquireReleaseInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkValidationFlagsEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkViSurfaceCreateInfoNN>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewASTCDecodeModeEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceASTCDecodeFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineRobustnessFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineRobustnessPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRobustnessCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkConditionalRenderingBeginInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceConditionalRenderingFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCommandBufferInheritanceConditionalRenderingInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineViewportWScalingStateCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfaceCapabilities2EXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayPowerInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceEventInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayEventInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainCounterCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPresentTimesInfoGOOGLE>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineViewportSwizzleStateCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDiscardRectanglePropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineDiscardRectangleStateCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceConservativeRasterizationPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRasterizationConservativeStateCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDepthClipEnableFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRasterizationDepthClipStateCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkHdrMetadataEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG>());
                break;
            }
            case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkIOSSurfaceCreateInfoMVK>());
                break;
            }
            case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMacOSSurfaceCreateInfoMVK>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDebugUtilsLabelEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDebugUtilsObjectNameInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDebugUtilsMessengerCallbackDataEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDebugUtilsMessengerCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDebugUtilsObjectTagInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAndroidHardwareBufferUsageANDROID>());
                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAndroidHardwareBufferPropertiesANDROID>());
                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAndroidHardwareBufferFormatPropertiesANDROID>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportAndroidHardwareBufferInfoANDROID>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryGetAndroidHardwareBufferInfoANDROID>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalFormatANDROID>());
                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAndroidHardwareBufferFormatProperties2ANDROID>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSampleLocationsInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassSampleLocationsBeginInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineSampleLocationsStateCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSampleLocationsPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMultisamplePropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineColorBlendAdvancedStateCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineCoverageToColorStateCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineCoverageModulationStateCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderSMBuiltinsPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDrmFormatModifierPropertiesListEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageDrmFormatModifierInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageDrmFormatModifierListCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageDrmFormatModifierExplicitCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageDrmFormatModifierPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDrmFormatModifierPropertiesList2EXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkValidationCacheCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkShaderModuleValidationCacheCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineViewportShadingRateImageStateCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShadingRateImageFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShadingRateImagePropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineViewportCoarseSampleOrderStateCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRayTracingShaderGroupCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRayTracingPipelineCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGeometryTrianglesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGeometryAABBNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_GEOMETRY_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGeometryNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindAccelerationStructureMemoryInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWriteDescriptorSetAccelerationStructureNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureMemoryRequirementsInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRepresentativeFragmentTestStateCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageViewImageFormatInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFilterCubicImageViewImageFormatPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportMemoryHostPointerInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryHostPointerPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExternalMemoryHostPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineCompilerControlCreateInfoAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderCorePropertiesAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceMemoryOverallocationCreateInfoAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPresentFrameTokenGGP>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMeshShaderFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMeshShaderPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderImageFootprintFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineViewportExclusiveScissorStateCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExclusiveScissorFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyCheckpointPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCheckpointDataNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>());
                break;
            }
            case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkInitializePerformanceApiInfoINTEL>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueryPoolPerformanceQueryCreateInfoINTEL>());
                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerformanceMarkerInfoINTEL>());
                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerformanceStreamMarkerInfoINTEL>());
                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerformanceOverrideInfoINTEL>());
                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerformanceConfigurationAcquireInfoINTEL>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePCIBusInfoPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayNativeHdrSurfaceCapabilitiesAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainDisplayNativeHdrCreateInfoAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImagePipeSurfaceCreateInfoFUCHSIA>());
                break;
            }
            case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMetalSurfaceCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentDensityMapFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentDensityMapPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassFragmentDensityMapCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderCoreProperties2AMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCoherentMemoryFeaturesAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMemoryBudgetPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMemoryPriorityFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryPriorityAllocateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferDeviceAddressCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkValidationFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCooperativeMatrixPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeMatrixFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeMatrixPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCoverageReductionModeFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineCoverageReductionStateCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFramebufferMixedSamplesCombinationNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceProvokingVertexFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceProvokingVertexPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRasterizationProvokingVertexStateCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfaceFullScreenExclusiveInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfaceCapabilitiesFullScreenExclusiveEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfaceFullScreenExclusiveWin32InfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkHeadlessSurfaceCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceHostImageCopyFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceHostImageCopyPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryToImageCopyEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageToMemoryCopyEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyMemoryToImageInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyImageToMemoryInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyImageToImageInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkHostImageLayoutTransitionInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubresourceHostMemcpySizeEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkHostImageCopyDevicePerformanceQueryEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMapMemoryPlacedFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMapMemoryPlacedPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryMapPlacedInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfacePresentModeEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfacePresentScalingCapabilitiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfacePresentModeCompatibilityEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainPresentFenceInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainPresentModesCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainPresentModeInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainPresentScalingCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkReleaseSwapchainImagesInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGraphicsShaderGroupCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGraphicsPipelineShaderGroupsCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkIndirectCommandsLayoutTokenNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkIndirectCommandsLayoutCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGeneratedCommandsInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGeneratedCommandsMemoryRequirementsInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceInheritedViewportScissorFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCommandBufferInheritanceViewportScissorInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassTransformBeginInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCommandBufferInheritanceRenderPassTransformInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDepthBiasControlFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDepthBiasInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDepthBiasRepresentationInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceMemoryReportCallbackDataEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceDeviceMemoryReportCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRobustness2FeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRobustness2PropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerCustomBorderColorCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCustomBorderColorPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCustomBorderColorFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePresentBarrierFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfaceCapabilitiesPresentBarrierNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainPresentBarrierCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDiagnosticsConfigFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceDiagnosticsConfigCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueryLowLatencySupportNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGraphicsPipelineLibraryCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineFragmentShadingRateEnumStateCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureGeometryMotionTrianglesDataNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureMotionInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentDensityMap2PropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyCommandTransformInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageCompressionControlFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageCompressionControlEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageCompressionPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevice4444FormatsFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFaultFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceFaultCountsEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceFaultInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDirectFBSurfaceCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMutableDescriptorTypeCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVertexInputBindingDescription2EXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVertexInputAttributeDescription2EXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDrmPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceAddressBindingReportFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceAddressBindingCallbackDataEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDepthClipControlFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineViewportDepthClipControlCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportMemoryZirconHandleInfoFUCHSIA>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryZirconHandlePropertiesFUCHSIA>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryGetZirconHandleInfoFUCHSIA>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportSemaphoreZirconHandleInfoFUCHSIA>());
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSemaphoreGetZirconHandleInfoFUCHSIA>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryGetRemoteAddressInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFrameBoundaryFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFrameBoundaryEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubpassResolvePerformanceQueryEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMultisampledRenderToSingleSampledInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkScreenSurfaceCreateInfoQNX>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceColorWriteEnableFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineColorWriteCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageViewMinLodFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewMinLodCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMultiDrawFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMultiDrawPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderTileImageFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderTileImagePropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMicromapBuildInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMicromapCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceOpacityMicromapFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceOpacityMicromapPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMicromapVersionInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyMicromapToMemoryInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyMemoryToMicromapInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyMicromapInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMicromapBuildSizesInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureTrianglesOpacityMicromapEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDisplacementMicromapFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDisplacementMicromapPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureTrianglesDisplacementMicromapNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerBorderColorComponentMappingCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderCorePropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceQueueShaderCoreControlCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSchedulingControlsFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSchedulingControlsPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewSlicedCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorSetBindingReferenceVALVE>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorSetLayoutHostMappingInfoVALVE>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDepthClampZeroOneFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRenderPassStripedFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRenderPassStripedPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassStripeInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassStripeBeginInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassStripeSubmitInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubpassFragmentDensityMapOffsetEndInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkComputePipelineIndirectBufferInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineIndirectDeviceAddressInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLinearColorAttachmentFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewSampleWeightCreateInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageProcessingFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageProcessingPropertiesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceNestedCommandBufferFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceNestedCommandBufferPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalMemoryAcquireUnmodifiedEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExtendedDynamicState3FeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExtendedDynamicState3PropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassCreationControlEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassCreationFeedbackCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassSubpassFeedbackCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDirectDriverLoadingInfoLUNARG>());
                break;
            }
            case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDirectDriverLoadingListLUNARG>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineShaderStageModuleIdentifierCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkShaderModuleIdentifierEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceOpticalFlowFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceOpticalFlowPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkOpticalFlowImageFormatInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkOpticalFlowImageFormatPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkOpticalFlowSessionCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkOpticalFlowSessionCreatePrivateDataInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkOpticalFlowExecuteInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLegacyDitheringFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineProtectedAccessFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExternalFormatResolveFeaturesANDROID>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExternalFormatResolvePropertiesANDROID>());
                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAndroidHardwareBufferFormatResolvePropertiesANDROID>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceAntiLagFeaturesAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAntiLagPresentationInfoAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAntiLagDataAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderObjectFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderObjectPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkShaderCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTilePropertiesFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTilePropertiesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceAmigoProfilingFeaturesSEC>());
                break;
            }
            case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAmigoProfilingSubmitInfoSEC>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkLayerSettingsCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkLatencySleepModeInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkLatencySleepInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSetLatencyMarkerInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkLatencyTimingsFrameReportNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGetLatencyMarkerInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkLatencySubmissionPresentIdNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainLatencyCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkOutOfBandQueueTypeInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkLatencySurfaceCapabilitiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePerStageDescriptorSetFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageProcessing2FeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageProcessing2PropertiesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerBlockMatchWindowCreateInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCubicWeightsFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerCubicWeightsCreateInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBlitImageCubicWeightsInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceYcbcrDegammaFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCubicClampFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLayeredDriverPropertiesMSFT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRawAccessChainsFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCommandBufferInheritanceFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingValidationFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGeneratedCommandsMemoryRequirementsInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkIndirectExecutionSetPipelineInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkIndirectExecutionSetShaderLayoutInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkIndirectExecutionSetShaderInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkIndirectExecutionSetCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGeneratedCommandsInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWriteIndirectExecutionSetPipelineEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkIndirectCommandsLayoutTokenEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkIndirectCommandsLayoutCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGeneratedCommandsPipelineInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGeneratedCommandsShaderInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWriteIndirectExecutionSetShaderEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageAlignmentControlFeaturesMESA>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageAlignmentControlPropertiesMESA>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageAlignmentControlCreateInfoMESA>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDepthClampControlFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineViewportDepthClampControlCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureGeometryTrianglesDataKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureGeometryAabbsDataKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureGeometryInstancesDataKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureGeometryKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureBuildGeometryInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWriteDescriptorSetAccelerationStructureKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceAccelerationStructureFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceAccelerationStructurePropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureDeviceAddressInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureVersionInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyAccelerationStructureToMemoryInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyMemoryToAccelerationStructureInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyAccelerationStructureInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureBuildSizesInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRayTracingShaderGroupCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRayTracingPipelineInterfaceCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRayTracingPipelineCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingPipelineFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingPipelinePropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayQueryFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMeshShaderFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMeshShaderPropertiesEXT>());
                break;
            }
            default:
                break;
        }
        output_struct = output_struct->pNext;
        output_struct->sType = in_pnext->sType;
        in_pnext = in_pnext->pNext;
    }
}

template <typename T>
void InitializeOutputStructPNext(StructPointerDecoder<T> *decoder)
{
    if(decoder->IsNull()) return;
    size_t len = decoder->GetOutputLength();
    auto input = decoder->GetPointer();
    auto output = decoder->GetOutputPointer();
    for( size_t i = 0 ; i < len; ++i )
    {
        const auto* in_pnext = reinterpret_cast<const VkBaseInStructure*>(input[i].pNext);
        if( in_pnext == nullptr ) continue;
        auto* output_struct = reinterpret_cast<VkBaseOutStructure*>(&output[i]);
        InitializeOutputStructPNextImpl(in_pnext, output_struct);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
