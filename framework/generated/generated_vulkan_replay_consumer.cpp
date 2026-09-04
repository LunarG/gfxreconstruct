/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
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
    args::CreateInstance&                       args)
{

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pInstance.IsNull()) { args.pInstance.SetHandleLength(1); }
    VulkanInstanceInfo handle_info;
    args.pInstance.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pInstance.GetPointer());
    VkResult replay_result = OverrideCreateInstance(args.result, &args.pCreateInfo, &args.pAllocator, &args.pInstance);
    CheckResult("vkCreateInstance", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanInstanceInfo>(format::kNullHandleId, args.pInstance.GetPointer(), args.pInstance.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkInstanceInfo);
}

void VulkanReplayConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    args::DestroyInstance&                      args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    OverrideDestroyInstance(GetInstanceTable(in_instance->handle)->DestroyInstance, in_instance, &args.pAllocator);
    RemoveHandle(args.instance, &CommonObjectInfoTable::RemoveVkInstanceInfo);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDevices&             args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);
    args.pPhysicalDeviceCount.IsNull() ? nullptr : args.pPhysicalDeviceCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanInstanceInfo>("vkEnumeratePhysicalDevices", args.result, args.instance, kInstanceArrayEnumeratePhysicalDevices, &args.pPhysicalDeviceCount, &args.pPhysicalDevices, &CommonObjectInfoTable::GetVkInstanceInfo));
    if (!args.pPhysicalDevices.IsNull()) { args.pPhysicalDevices.SetHandleLength(*args.pPhysicalDeviceCount.GetOutputPointer()); }
    std::vector<VulkanPhysicalDeviceInfo> handle_info(*args.pPhysicalDeviceCount.GetOutputPointer());
    for (size_t i = 0; i < *args.pPhysicalDeviceCount.GetOutputPointer(); ++i) { args.pPhysicalDevices.SetConsumerData(i, &handle_info[i]); }

    PushRecaptureHandleIds(args.pPhysicalDevices.GetPointer(), args.pPhysicalDevices.GetLength());
    VkResult replay_result = OverrideEnumeratePhysicalDevices(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDevices, args.result, in_instance, &args.pPhysicalDeviceCount, &args.pPhysicalDevices);
    CheckResult("vkEnumeratePhysicalDevices", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pPhysicalDevices.IsNull()) { SetOutputArrayCount<VulkanInstanceInfo>(args.instance, kInstanceArrayEnumeratePhysicalDevices, *args.pPhysicalDeviceCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkInstanceInfo); }
    AddHandles<VulkanPhysicalDeviceInfo>(args.instance, args.pPhysicalDevices.GetPointer(), args.pPhysicalDevices.GetLength(), args.pPhysicalDevices.GetHandlePointer(), *args.pPhysicalDeviceCount.GetOutputPointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkPhysicalDeviceInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFeatures&            args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkPhysicalDeviceFeatures* out_pFeatures = args.pFeatures.IsNull() ? nullptr : args.pFeatures.AllocateOutputData(1);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFormatProperties&    args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkFormatProperties* out_pFormatProperties = args.pFormatProperties.IsNull() ? nullptr : args.pFormatProperties.AllocateOutputData(1);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties(in_physicalDevice, args.format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceImageFormatProperties& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkImageFormatProperties* out_pImageFormatProperties = args.pImageFormatProperties.IsNull() ? nullptr : args.pImageFormatProperties.AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties(in_physicalDevice, args.format, args.type, args.tiling, args.usage, args.flags, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceProperties&          args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(1);

    OverrideGetPhysicalDeviceProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties, in_physicalDevice, &args.pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyProperties& args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pQueueFamilyPropertyCount.IsNull() ? nullptr : args.pQueueFamilyPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties", VK_SUCCESS, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties, &args.pQueueFamilyPropertyCount, &args.pQueueFamilyProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    if (!args.pQueueFamilyProperties.IsNull()) { args.pQueueFamilyProperties.AllocateOutputData(*args.pQueueFamilyPropertyCount.GetOutputPointer()); }

    OverrideGetPhysicalDeviceQueueFamilyProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceQueueFamilyProperties, in_physicalDevice, &args.pQueueFamilyPropertyCount, &args.pQueueFamilyProperties);

    if (args.pQueueFamilyProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties, *args.pQueueFamilyPropertyCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMemoryProperties&    args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pMemoryProperties.IsNull() ? nullptr : args.pMemoryProperties.AllocateOutputData(1);

    OverrideGetPhysicalDeviceMemoryProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties, in_physicalDevice, &args.pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    args::CreateDevice&                         args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pDevice.IsNull()) { args.pDevice.SetHandleLength(1); }
    VulkanDeviceInfo handle_info;
    args.pDevice.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pDevice.GetPointer());
    VkResult replay_result = OverrideCreateDevice(args.result, in_physicalDevice, &args.pCreateInfo, &args.pAllocator, &args.pDevice);
    CheckResult("vkCreateDevice", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDeviceInfo>(args.physicalDevice, args.pDevice.GetPointer(), args.pDevice.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDeviceInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    args::DestroyDevice&                        args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    OverrideDestroyDevice(GetDeviceTable(in_device->handle)->DestroyDevice, in_device, &args.pAllocator);
    RemoveHandle(args.device, &CommonObjectInfoTable::RemoveVkDeviceInfo);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    args::GetDeviceQueue&                       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    if (!args.pQueue.IsNull()) { args.pQueue.SetHandleLength(1); }
    VulkanQueueInfo handle_info;
    args.pQueue.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pQueue.GetPointer());
    OverrideGetDeviceQueue(GetDeviceTable(in_device->handle)->GetDeviceQueue, in_device, args.queueFamilyIndex, args.queueIndex, &args.pQueue);
    ClearRecaptureHandleIds();

    AddHandle<VulkanQueueInfo>(args.device, args.pQueue.GetPointer(), args.pQueue.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkQueueInfo);
}

void VulkanReplayConsumer::Process_vkQueueSubmit(
    const ApiCallInfo&                          call_info,
    args::QueueSubmit&                          args)
{
    auto in_queue = GetObjectInfoTable().GetVkQueueInfo(args.queue);

    MapStructArrayHandles(args.pSubmits.GetMetaStructPointer(), args.pSubmits.GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(args.fence);

    VkResult replay_result = OverrideQueueSubmit(GetDeviceTable(in_queue->handle)->QueueSubmit, call_info.index, args.result, in_queue, args.submitCount, &args.pSubmits, in_fence);
    CheckResult("vkQueueSubmit", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    args::QueueWaitIdle&                        args)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(args.queue, &CommonObjectInfoTable::GetVkQueueInfo);

    VkResult replay_result = GetDeviceTable(in_queue)->QueueWaitIdle(in_queue);
    CheckResult("vkQueueWaitIdle", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    args::DeviceWaitIdle&                       args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);

    VkResult replay_result = GetDeviceTable(in_device)->DeviceWaitIdle(in_device);
    CheckResult("vkDeviceWaitIdle", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    args::AllocateMemory&                       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pAllocateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pMemory.IsNull()) { args.pMemory.SetHandleLength(1); }
    VulkanDeviceMemoryInfo handle_info;
    args.pMemory.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pMemory.GetPointer());
    VkResult replay_result = OverrideAllocateMemory(GetDeviceTable(in_device->handle)->AllocateMemory, args.result, in_device, &args.pAllocateInfo, &args.pAllocator, &args.pMemory);
    CheckResult("vkAllocateMemory", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDeviceMemoryInfo>(args.device, args.pMemory.GetPointer(), args.pMemory.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDeviceMemoryInfo);
}

void VulkanReplayConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    args::FreeMemory&                           args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(args.memory);

    OverrideFreeMemory(GetDeviceTable(in_device->handle)->FreeMemory, in_device, in_memory, &args.pAllocator);
    RemoveHandle(args.memory, &CommonObjectInfoTable::RemoveVkDeviceMemoryInfo);
}

void VulkanReplayConsumer::Process_vkMapMemory(
    const ApiCallInfo&                          call_info,
    args::MapMemory&                            args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(args.memory);
    void** out_ppData = args.ppData.IsNull() ? nullptr : args.ppData.AllocateOutputData(1);

    VkResult replay_result = OverrideMapMemory(GetDeviceTable(in_device->handle)->MapMemory, args.result, in_device, in_memory, args.offset, args.size, args.flags, out_ppData);
    CheckResult("vkMapMemory", args.result, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*args.ppData.GetPointer()), *args.ppData.GetOutputPointer(), format::ApiCallId::ApiCall_vkMapMemory, "vkMapMemory");
}

void VulkanReplayConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory&                          args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(args.memory);

    OverrideUnmapMemory(GetDeviceTable(in_device->handle)->UnmapMemory, in_device, in_memory);
}

void VulkanReplayConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    args::FlushMappedMemoryRanges&              args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pMemoryRanges.GetMetaStructPointer(), args.pMemoryRanges.GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideFlushMappedMemoryRanges(GetDeviceTable(in_device->handle)->FlushMappedMemoryRanges, args.result, in_device, args.memoryRangeCount, &args.pMemoryRanges);
    CheckResult("vkFlushMappedMemoryRanges", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    args::InvalidateMappedMemoryRanges&         args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pMemoryRanges.GetMetaStructPointer(), args.pMemoryRanges.GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideInvalidateMappedMemoryRanges(GetDeviceTable(in_device->handle)->InvalidateMappedMemoryRanges, args.result, in_device, args.memoryRangeCount, &args.pMemoryRanges);
    CheckResult("vkInvalidateMappedMemoryRanges", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMemoryCommitment&            args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(args.memory);
    args.pCommittedMemoryInBytes.IsNull() ? nullptr : args.pCommittedMemoryInBytes.AllocateOutputData(1, static_cast<VkDeviceSize>(0));

    OverrideGetDeviceMemoryCommitment(GetDeviceTable(in_device->handle)->GetDeviceMemoryCommitment, in_device, in_memory, &args.pCommittedMemoryInBytes);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory&                     args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_buffer = GetObjectInfoTable().GetVkBufferInfo(args.buffer);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(args.memory);

    VkResult replay_result = OverrideBindBufferMemory(GetDeviceTable(in_device->handle)->BindBufferMemory, args.result, in_device, in_buffer, in_memory, args.memoryOffset);
    CheckResult("vkBindBufferMemory", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory&                      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_image = GetObjectInfoTable().GetVkImageInfo(args.image);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(args.memory);

    VkResult replay_result = OverrideBindImageMemory(GetDeviceTable(in_device->handle)->BindImageMemory, args.result, in_device, in_image, in_memory, args.memoryOffset);
    CheckResult("vkBindImageMemory", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetBufferMemoryRequirements&          args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_buffer = GetObjectInfoTable().GetVkBufferInfo(args.buffer);
    args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1);

    OverrideGetBufferMemoryRequirements(GetDeviceTable(in_device->handle)->GetBufferMemoryRequirements, in_device, in_buffer, &args.pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetImageMemoryRequirements&           args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_image = GetObjectInfoTable().GetVkImageInfo(args.image);
    args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1);

    OverrideGetImageMemoryRequirements(GetDeviceTable(in_device->handle)->GetImageMemoryRequirements, in_device, in_image, &args.pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetImageSparseMemoryRequirements&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(args.image, &CommonObjectInfoTable::GetVkImageInfo);
    uint32_t* out_pSparseMemoryRequirementCount = args.pSparseMemoryRequirementCount.IsNull() ? nullptr : args.pSparseMemoryRequirementCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanImageInfo>("vkGetImageSparseMemoryRequirements", VK_SUCCESS, args.image, kImageArrayGetImageSparseMemoryRequirements, &args.pSparseMemoryRequirementCount, &args.pSparseMemoryRequirements, &CommonObjectInfoTable::GetVkImageInfo));
    VkSparseImageMemoryRequirements* out_pSparseMemoryRequirements = args.pSparseMemoryRequirements.IsNull() ? nullptr : args.pSparseMemoryRequirements.AllocateOutputData(*out_pSparseMemoryRequirementCount);

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements(in_device, in_image, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (args.pSparseMemoryRequirements.IsNull()) { SetOutputArrayCount<VulkanImageInfo>(args.image, kImageArrayGetImageSparseMemoryRequirements, *out_pSparseMemoryRequirementCount, &CommonObjectInfoTable::GetVkImageInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSparseImageFormatProperties& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties", VK_SUCCESS, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkSparseImageFormatProperties* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(in_physicalDevice, args.format, args.type, args.samples, args.usage, args.tiling, out_pPropertyCount, out_pProperties);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    args::QueueBindSparse&                      args)
{
    auto in_queue = GetObjectInfoTable().GetVkQueueInfo(args.queue);

    MapStructArrayHandles(args.pBindInfo.GetMetaStructPointer(), args.pBindInfo.GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(args.fence);

    VkResult replay_result = OverrideQueueBindSparse(GetDeviceTable(in_queue->handle)->QueueBindSparse, args.result, in_queue, args.bindInfoCount, &args.pBindInfo, in_fence);
    CheckResult("vkQueueBindSparse", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    args::CreateFence&                          args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkFenceCreateInfo* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pFence.IsNull()) { args.pFence.SetHandleLength(1); }
    VkFence* out_pFence = args.pFence.GetHandlePointer();

    PushRecaptureHandleId(args.pFence.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateFence(in_device, in_pCreateInfo, in_pAllocator, out_pFence);
    CheckResult("vkCreateFence", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanFenceInfo>(args.device, args.pFence.GetPointer(), out_pFence, &CommonObjectInfoTable::AddVkFenceInfo);
}

void VulkanReplayConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    args::DestroyFence&                         args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkFence in_fence = MapHandle<VulkanFenceInfo>(args.fence, &CommonObjectInfoTable::GetVkFenceInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyFence(in_device, in_fence, in_pAllocator);
    RemoveHandle(args.fence, &CommonObjectInfoTable::RemoveVkFenceInfo);
}

void VulkanReplayConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    args::ResetFences&                          args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkFence* in_pFences = MapHandles<VulkanFenceInfo>(&args.pFences, args.fenceCount, &CommonObjectInfoTable::GetVkFenceInfo);

    VkResult replay_result = GetDeviceTable(in_device)->ResetFences(in_device, args.fenceCount, in_pFences);
    CheckResult("vkResetFences", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    args::GetFenceStatus&                       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(args.fence);

    VkResult replay_result = OverrideGetFenceStatus(GetDeviceTable(in_device->handle)->GetFenceStatus, args.result, in_device, in_fence);
    CheckResult("vkGetFenceStatus", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkWaitForFences(
    const ApiCallInfo&                          call_info,
    args::WaitForFences&                        args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    MapHandles<VulkanFenceInfo>(&args.pFences, args.fenceCount, &CommonObjectInfoTable::GetVkFenceInfo);

    VkResult replay_result = OverrideWaitForFences(GetDeviceTable(in_device->handle)->WaitForFences, args.result, in_device, args.fenceCount, &args.pFences, args.waitAll, args.timeout);
    CheckResult("vkWaitForFences", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    args::CreateSemaphore&                      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSemaphore.IsNull()) { args.pSemaphore.SetHandleLength(1); }
    VulkanSemaphoreInfo handle_info;
    args.pSemaphore.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSemaphore.GetPointer());
    VkResult replay_result = OverrideCreateSemaphore(GetDeviceTable(in_device->handle)->CreateSemaphore, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pSemaphore);
    CheckResult("vkCreateSemaphore", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSemaphoreInfo>(args.device, args.pSemaphore.GetPointer(), args.pSemaphore.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSemaphoreInfo);
}

void VulkanReplayConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    args::DestroySemaphore&                     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSemaphore in_semaphore = MapHandle<VulkanSemaphoreInfo>(args.semaphore, &CommonObjectInfoTable::GetVkSemaphoreInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroySemaphore(in_device, in_semaphore, in_pAllocator);
    RemoveHandle(args.semaphore, &CommonObjectInfoTable::RemoveVkSemaphoreInfo);
}

void VulkanReplayConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    args::CreateQueryPool&                      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkQueryPoolCreateInfo* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pQueryPool.IsNull()) { args.pQueryPool.SetHandleLength(1); }
    VkQueryPool* out_pQueryPool = args.pQueryPool.GetHandlePointer();

    PushRecaptureHandleId(args.pQueryPool.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateQueryPool(in_device, in_pCreateInfo, in_pAllocator, out_pQueryPool);
    CheckResult("vkCreateQueryPool", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanQueryPoolInfo>(args.device, args.pQueryPool.GetPointer(), out_pQueryPool, &CommonObjectInfoTable::AddVkQueryPoolInfo);
}

void VulkanReplayConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    args::DestroyQueryPool&                     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(args.queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyQueryPool(in_device, in_queryPool, in_pAllocator);
    RemoveHandle(args.queryPool, &CommonObjectInfoTable::RemoveVkQueryPoolInfo);
}

void VulkanReplayConsumer::Process_vkGetQueryPoolResults(
    const ApiCallInfo&                          call_info,
    args::GetQueryPoolResults&                  args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool);
    if (!args.pData.IsNull()) { args.pData.AllocateOutputData(args.dataSize); }

    VkResult replay_result = OverrideGetQueryPoolResults(GetDeviceTable(in_device->handle)->GetQueryPoolResults, args.result, in_device, in_queryPool, args.firstQuery, args.queryCount, args.dataSize, &args.pData, args.stride, args.flags);
    CheckResult("vkGetQueryPoolResults", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    args::CreateBuffer&                         args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pBuffer.IsNull()) { args.pBuffer.SetHandleLength(1); }
    VulkanBufferInfo handle_info;
    args.pBuffer.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pBuffer.GetPointer());
    VkResult replay_result = OverrideCreateBuffer(GetDeviceTable(in_device->handle)->CreateBuffer, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pBuffer);
    CheckResult("vkCreateBuffer", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanBufferInfo>(args.device, args.pBuffer.GetPointer(), args.pBuffer.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkBufferInfo);
}

void VulkanReplayConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    args::DestroyBuffer&                        args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_buffer = GetObjectInfoTable().GetVkBufferInfo(args.buffer);

    OverrideDestroyBuffer(GetDeviceTable(in_device->handle)->DestroyBuffer, in_device, in_buffer, &args.pAllocator);
    RemoveHandle(args.buffer, &CommonObjectInfoTable::RemoveVkBufferInfo);
}

void VulkanReplayConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    args::CreateImage&                          args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pImage.IsNull()) { args.pImage.SetHandleLength(1); }
    VulkanImageInfo handle_info;
    args.pImage.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pImage.GetPointer());
    VkResult replay_result = OverrideCreateImage(GetDeviceTable(in_device->handle)->CreateImage, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pImage);
    CheckResult("vkCreateImage", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanImageInfo>(args.device, args.pImage.GetPointer(), args.pImage.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkImageInfo);
}

void VulkanReplayConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    args::DestroyImage&                         args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_image = GetObjectInfoTable().GetVkImageInfo(args.image);

    OverrideDestroyImage(GetDeviceTable(in_device->handle)->DestroyImage, in_device, in_image, &args.pAllocator);
    RemoveHandle(args.image, &CommonObjectInfoTable::RemoveVkImageInfo);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout&            args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_image = GetObjectInfoTable().GetVkImageInfo(args.image);
    args.pLayout.IsNull() ? nullptr : args.pLayout.AllocateOutputData(1);

    OverrideGetImageSubresourceLayout(GetDeviceTable(in_device->handle)->GetImageSubresourceLayout, in_device, in_image, &args.pSubresource, &args.pLayout);
}

void VulkanReplayConsumer::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    args::CreateImageView&                      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pView.IsNull()) { args.pView.SetHandleLength(1); }
    VulkanImageViewInfo handle_info;
    args.pView.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pView.GetPointer());
    VkResult replay_result = OverrideCreateImageView(GetDeviceTable(in_device->handle)->CreateImageView, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pView);
    CheckResult("vkCreateImageView", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanImageViewInfo>(args.device, args.pView.GetPointer(), args.pView.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkImageViewInfo);
}

void VulkanReplayConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    args::DestroyImageView&                     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImageView in_imageView = MapHandle<VulkanImageViewInfo>(args.imageView, &CommonObjectInfoTable::GetVkImageViewInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyImageView(in_device, in_imageView, in_pAllocator);
    RemoveHandle(args.imageView, &CommonObjectInfoTable::RemoveVkImageViewInfo);
}

void VulkanReplayConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
    args::CreateCommandPool&                    args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pCommandPool.IsNull()) { args.pCommandPool.SetHandleLength(1); }
    VulkanCommandPoolInfo handle_info;
    args.pCommandPool.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pCommandPool.GetPointer());
    VkResult replay_result = OverrideCreateCommandPool(GetDeviceTable(in_device->handle)->CreateCommandPool, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pCommandPool);
    CheckResult("vkCreateCommandPool", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanCommandPoolInfo>(args.device, args.pCommandPool.GetPointer(), args.pCommandPool.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkCommandPoolInfo);
}

void VulkanReplayConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    args::DestroyCommandPool&                   args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_commandPool = GetObjectInfoTable().GetVkCommandPoolInfo(args.commandPool);

    OverrideDestroyCommandPool(GetDeviceTable(in_device->handle)->DestroyCommandPool, in_device, in_commandPool, &args.pAllocator);
    RemovePoolHandle<VulkanCommandPoolInfo>(args.commandPool, &CommonObjectInfoTable::GetVkCommandPoolInfo, &CommonObjectInfoTable::RemoveVkCommandPoolInfo, &CommonObjectInfoTable::RemoveVkCommandBufferInfo);
}

void VulkanReplayConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    args::ResetCommandPool&                     args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_commandPool = GetObjectInfoTable().GetVkCommandPoolInfo(args.commandPool);

    VkResult replay_result = OverrideResetCommandPool(GetDeviceTable(in_device->handle)->ResetCommandPool, args.result, in_device, in_commandPool, args.flags);
    CheckResult("vkResetCommandPool", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    args::AllocateCommandBuffers&               args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pAllocateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pCommandBuffers.IsNull()) { args.pCommandBuffers.SetHandleLength(args.pAllocateInfo.GetPointer()->commandBufferCount); }
    std::vector<VulkanCommandBufferInfo> handle_info(args.pAllocateInfo.GetPointer()->commandBufferCount);
    for (size_t i = 0; i < args.pAllocateInfo.GetPointer()->commandBufferCount; ++i) { args.pCommandBuffers.SetConsumerData(i, &handle_info[i]); }

    PushRecaptureHandleIds(args.pCommandBuffers.GetPointer(), args.pCommandBuffers.GetLength());
    VkResult replay_result = OverrideAllocateCommandBuffers(GetDeviceTable(in_device->handle)->AllocateCommandBuffers, args.result, in_device, &args.pAllocateInfo, &args.pCommandBuffers);
    CheckResult("vkAllocateCommandBuffers", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddPoolHandles<VulkanCommandPoolInfo, VulkanCommandBufferInfo>(args.device, handle_mapping::GetPoolId(args.pAllocateInfo.GetMetaStructPointer()), args.pCommandBuffers.GetPointer(), args.pCommandBuffers.GetLength(), args.pCommandBuffers.GetHandlePointer(), args.pAllocateInfo.GetPointer()->commandBufferCount, std::move(handle_info), &CommonObjectInfoTable::GetVkCommandPoolInfo, &CommonObjectInfoTable::AddVkCommandBufferInfo);
}

void VulkanReplayConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    args::FreeCommandBuffers&                   args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_commandPool = GetObjectInfoTable().GetVkCommandPoolInfo(args.commandPool);
    MapHandles<VulkanCommandBufferInfo>(&args.pCommandBuffers, args.commandBufferCount, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    OverrideFreeCommandBuffers(GetDeviceTable(in_device->handle)->FreeCommandBuffers, in_device, in_commandPool, args.commandBufferCount, &args.pCommandBuffers);
    RemovePoolHandles<VulkanCommandPoolInfo, VulkanCommandBufferInfo>(args.commandPool, &args.pCommandBuffers, args.commandBufferCount, &CommonObjectInfoTable::GetVkCommandPoolInfo, &CommonObjectInfoTable::RemoveVkCommandBufferInfo);
}

void VulkanReplayConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::BeginCommandBuffer&                   args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pBeginInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideBeginCommandBuffer(GetDeviceTable(in_commandBuffer->handle)->BeginCommandBuffer, call_info.index, args.result, in_commandBuffer, &args.pBeginInfo);
    CheckResult("vkBeginCommandBuffer", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::EndCommandBuffer&                     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->EndCommandBuffer(in_commandBuffer);
    CheckResult("vkEndCommandBuffer", args.result, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkEndCommandBuffer(call_info, GetInjectedDeviceCalls(in_commandBuffer), args.result, in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::ResetCommandBuffer&                   args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    VkResult replay_result = OverrideResetCommandBuffer(GetDeviceTable(in_commandBuffer->handle)->ResetCommandBuffer, args.result, in_commandBuffer, args.flags);
    CheckResult("vkResetCommandBuffer", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer&                        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_srcBuffer = MapHandle<VulkanBufferInfo>(args.srcBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(args.dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkBufferCopy* in_pRegions = args.pRegions.GetPointer();

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyBuffer(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.srcBuffer), GetObjectInfoTable().GetVkBufferInfo(args.dstBuffer), args.regionCount, &args.pRegions, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyBuffer(in_commandBuffer, in_srcBuffer, in_dstBuffer, args.regionCount, in_pRegions);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyBuffer(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.srcBuffer), GetObjectInfoTable().GetVkBufferInfo(args.dstBuffer), args.regionCount, &args.pRegions, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage&                         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_srcImage = MapHandle<VulkanImageInfo>(args.srcImage, &CommonObjectInfoTable::GetVkImageInfo);
    VkImage in_dstImage = MapHandle<VulkanImageInfo>(args.dstImage, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageCopy* in_pRegions = args.pRegions.GetPointer();

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyImage(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkImageInfo(args.srcImage), args.srcImageLayout, GetObjectInfoTable().GetVkImageInfo(args.dstImage), args.dstImageLayout, args.regionCount, &args.pRegions, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyImage(in_commandBuffer, in_srcImage, args.srcImageLayout, in_dstImage, args.dstImageLayout, args.regionCount, in_pRegions);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyImage(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkImageInfo(args.srcImage), args.srcImageLayout, GetObjectInfoTable().GetVkImageInfo(args.dstImage), args.dstImageLayout, args.regionCount, &args.pRegions, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_srcBuffer = MapHandle<VulkanBufferInfo>(args.srcBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkImage in_dstImage = MapHandle<VulkanImageInfo>(args.dstImage, &CommonObjectInfoTable::GetVkImageInfo);
    const VkBufferImageCopy* in_pRegions = args.pRegions.GetPointer();

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyBufferToImage(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.srcBuffer), GetObjectInfoTable().GetVkImageInfo(args.dstImage), args.dstImageLayout, args.regionCount, &args.pRegions, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage(in_commandBuffer, in_srcBuffer, in_dstImage, args.dstImageLayout, args.regionCount, in_pRegions);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyBufferToImage(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.srcBuffer), GetObjectInfoTable().GetVkImageInfo(args.dstImage), args.dstImageLayout, args.regionCount, &args.pRegions, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_srcImage = MapHandle<VulkanImageInfo>(args.srcImage, &CommonObjectInfoTable::GetVkImageInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(args.dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkBufferImageCopy* in_pRegions = args.pRegions.GetPointer();

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyImageToBuffer(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkImageInfo(args.srcImage), args.srcImageLayout, GetObjectInfoTable().GetVkBufferInfo(args.dstBuffer), args.regionCount, &args.pRegions, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer(in_commandBuffer, in_srcImage, args.srcImageLayout, in_dstBuffer, args.regionCount, in_pRegions);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyImageToBuffer(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkImageInfo(args.srcImage), args.srcImageLayout, GetObjectInfoTable().GetVkBufferInfo(args.dstBuffer), args.regionCount, &args.pRegions, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateBuffer&                      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(args.dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    const void* in_pData = args.pData.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdUpdateBuffer(in_commandBuffer, in_dstBuffer, args.dstOffset, args.dataSize, in_pData);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdUpdateBuffer(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_dstBuffer, args.dstOffset, args.dataSize, in_pData);
    }
}

void VulkanReplayConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdFillBuffer&                        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(args.dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdFillBuffer(in_commandBuffer, in_dstBuffer, args.dstOffset, args.size, args.data);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdFillBuffer(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_dstBuffer, args.dstOffset, args.size, args.data);
    }
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier&                   args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructArrayHandles(args.pMemoryBarriers.GetMetaStructPointer(), args.pMemoryBarriers.GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(args.pBufferMemoryBarriers.GetMetaStructPointer(), args.pBufferMemoryBarriers.GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(args.pImageMemoryBarriers.GetMetaStructPointer(), args.pImageMemoryBarriers.GetLength(), GetObjectInfoTable());

    OverrideCmdPipelineBarrier(GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier, in_commandBuffer, args.srcStageMask, args.dstStageMask, args.dependencyFlags, args.memoryBarrierCount, &args.pMemoryBarriers, args.bufferMemoryBarrierCount, &args.pBufferMemoryBarriers, args.imageMemoryBarrierCount, &args.pImageMemoryBarriers);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPipelineBarrier(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.srcStageMask, args.dstStageMask, args.dependencyFlags, args.memoryBarrierCount, args.pMemoryBarriers.GetPointer(), args.bufferMemoryBarrierCount, args.pBufferMemoryBarriers.GetPointer(), args.imageMemoryBarrierCount, args.pImageMemoryBarriers.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    args::CmdBeginQuery&                        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(args.queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdBeginQuery(in_commandBuffer, in_queryPool, args.query, args.flags);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginQuery(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool), args.query, args.flags);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    args::CmdEndQuery&                          args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool);

    OverrideCmdEndQuery(GetDeviceTable(in_commandBuffer->handle)->CmdEndQuery, in_commandBuffer, in_queryPool, args.query);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndQuery(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_queryPool, args.query);
    }
}

void VulkanReplayConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    args::CmdResetQueryPool&                    args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool);

    OverrideCmdResetQueryPool(GetDeviceTable(in_commandBuffer->handle)->CmdResetQueryPool, in_commandBuffer, in_queryPool, args.firstQuery, args.queryCount);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdResetQueryPool(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_queryPool, args.firstQuery, args.queryCount);
    }
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp&                    args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool);

    OverrideCmdWriteTimestamp(GetDeviceTable(in_commandBuffer->handle)->CmdWriteTimestamp, in_commandBuffer, args.pipelineStage, in_queryPool, args.query);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWriteTimestamp(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.pipelineStage, in_queryPool, args.query);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResults&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(args.queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(args.dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdCopyQueryPoolResults(in_commandBuffer, in_queryPool, args.firstQuery, args.queryCount, in_dstBuffer, args.dstOffset, args.stride, args.flags);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyQueryPoolResults(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool), args.firstQuery, args.queryCount, GetObjectInfoTable().GetVkBufferInfo(args.dstBuffer), args.dstOffset, args.stride, args.flags);
    }
}

void VulkanReplayConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteCommands&                   args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    MapHandles<VulkanCommandBufferInfo>(&args.pCommandBuffers, args.commandBufferCount, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    OverrideCmdExecuteCommands(GetDeviceTable(in_commandBuffer->handle)->CmdExecuteCommands, in_commandBuffer, args.commandBufferCount, &args.pCommandBuffers);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdExecuteCommands(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.commandBufferCount, args.pCommandBuffers.GetHandlePointer());
    }
}

void VulkanReplayConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    args::CreateEvent&                          args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkEventCreateInfo* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pEvent.IsNull()) { args.pEvent.SetHandleLength(1); }
    VkEvent* out_pEvent = args.pEvent.GetHandlePointer();

    PushRecaptureHandleId(args.pEvent.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateEvent(in_device, in_pCreateInfo, in_pAllocator, out_pEvent);
    CheckResult("vkCreateEvent", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanEventInfo>(args.device, args.pEvent.GetPointer(), out_pEvent, &CommonObjectInfoTable::AddVkEventInfo);
}

void VulkanReplayConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    args::DestroyEvent&                         args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkEvent in_event = MapHandle<VulkanEventInfo>(args.event, &CommonObjectInfoTable::GetVkEventInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyEvent(in_device, in_event, in_pAllocator);
    RemoveHandle(args.event, &CommonObjectInfoTable::RemoveVkEventInfo);
}

void VulkanReplayConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    args::GetEventStatus&                       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_event = GetObjectInfoTable().GetVkEventInfo(args.event);

    VkResult replay_result = OverrideGetEventStatus(GetDeviceTable(in_device->handle)->GetEventStatus, args.result, in_device, in_event);
    CheckResult("vkGetEventStatus", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    args::SetEvent&                             args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_event = GetObjectInfoTable().GetVkEventInfo(args.event);

    VkResult replay_result = OverrideSetEvent(GetDeviceTable(in_device->handle)->SetEvent, args.result, in_device, in_event);
    CheckResult("vkSetEvent", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    args::ResetEvent&                           args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_event = GetObjectInfoTable().GetVkEventInfo(args.event);

    VkResult replay_result = OverrideResetEvent(GetDeviceTable(in_device->handle)->ResetEvent, args.result, in_device, in_event);
    CheckResult("vkResetEvent", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    args::CreateBufferView&                     args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pView.IsNull()) { args.pView.SetHandleLength(1); }
    VulkanBufferViewInfo handle_info;
    args.pView.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pView.GetPointer());
    VkResult replay_result = OverrideCreateBufferView(GetDeviceTable(in_device->handle)->CreateBufferView, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pView);
    CheckResult("vkCreateBufferView", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanBufferViewInfo>(args.device, args.pView.GetPointer(), args.pView.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkBufferViewInfo);
}

void VulkanReplayConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    args::DestroyBufferView&                    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkBufferView in_bufferView = MapHandle<VulkanBufferViewInfo>(args.bufferView, &CommonObjectInfoTable::GetVkBufferViewInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyBufferView(in_device, in_bufferView, in_pAllocator);
    RemoveHandle(args.bufferView, &CommonObjectInfoTable::RemoveVkBufferViewInfo);
}

void VulkanReplayConsumer::Process_vkCreateShaderModule(
    const ApiCallInfo&                          call_info,
    args::CreateShaderModule&                   args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pShaderModule.IsNull()) { args.pShaderModule.SetHandleLength(1); }
    VulkanShaderModuleInfo handle_info;
    args.pShaderModule.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pShaderModule.GetPointer());
    VkResult replay_result = OverrideCreateShaderModule(GetDeviceTable(in_device->handle)->CreateShaderModule, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pShaderModule);
    CheckResult("vkCreateShaderModule", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanShaderModuleInfo>(args.device, args.pShaderModule.GetPointer(), args.pShaderModule.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkShaderModuleInfo);
}

void VulkanReplayConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    args::DestroyShaderModule&                  args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_shaderModule = GetObjectInfoTable().GetVkShaderModuleInfo(args.shaderModule);

    OverrideDestroyShaderModule(GetDeviceTable(in_device->handle)->DestroyShaderModule, in_device, in_shaderModule, &args.pAllocator);
    RemoveHandle(args.shaderModule, &CommonObjectInfoTable::RemoveVkShaderModuleInfo);
}

void VulkanReplayConsumer::Process_vkCreatePipelineCache(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineCache&                  args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pPipelineCache.IsNull()) { args.pPipelineCache.SetHandleLength(1); }
    VulkanPipelineCacheInfo handle_info;
    args.pPipelineCache.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pPipelineCache.GetPointer());
    VkResult replay_result = OverrideCreatePipelineCache(GetDeviceTable(in_device->handle)->CreatePipelineCache, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pPipelineCache);
    CheckResult("vkCreatePipelineCache", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanPipelineCacheInfo>(args.device, args.pPipelineCache.GetPointer(), args.pPipelineCache.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineCacheInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineCache&                 args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_pipelineCache = GetObjectInfoTable().GetVkPipelineCacheInfo(args.pipelineCache);

    OverrideDestroyPipelineCache(GetDeviceTable(in_device->handle)->DestroyPipelineCache, in_device, in_pipelineCache, &args.pAllocator);
    RemoveHandle(args.pipelineCache, &CommonObjectInfoTable::RemoveVkPipelineCacheInfo);
}

void VulkanReplayConsumer::Process_vkGetPipelineCacheData(
    const ApiCallInfo&                          call_info,
    args::GetPipelineCacheData&                 args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_pipelineCache = GetObjectInfoTable().GetVkPipelineCacheInfo(args.pipelineCache);
    args.pDataSize.IsNull() ? nullptr : args.pDataSize.AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanPipelineCacheInfo>("vkGetPipelineCacheData", args.result, args.pipelineCache, kPipelineCacheArrayGetPipelineCacheData, &args.pDataSize, &args.pData, &CommonObjectInfoTable::GetVkPipelineCacheInfo));
    if (!args.pData.IsNull()) { args.pData.AllocateOutputData(*args.pDataSize.GetOutputPointer()); }

    VkResult replay_result = OverrideGetPipelineCacheData(GetDeviceTable(in_device->handle)->GetPipelineCacheData, args.result, in_device, in_pipelineCache, &args.pDataSize, &args.pData);
    CheckResult("vkGetPipelineCacheData", args.result, replay_result, call_info);

    if (args.pData.IsNull()) { SetOutputArrayCount<VulkanPipelineCacheInfo>(args.pipelineCache, kPipelineCacheArrayGetPipelineCacheData, *args.pDataSize.GetOutputPointer(), &CommonObjectInfoTable::GetVkPipelineCacheInfo); }
}

void VulkanReplayConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    args::MergePipelineCaches&                  args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipelineCache in_dstCache = MapHandle<VulkanPipelineCacheInfo>(args.dstCache, &CommonObjectInfoTable::GetVkPipelineCacheInfo);
    const VkPipelineCache* in_pSrcCaches = MapHandles<VulkanPipelineCacheInfo>(&args.pSrcCaches, args.srcCacheCount, &CommonObjectInfoTable::GetVkPipelineCacheInfo);

    VkResult replay_result = GetDeviceTable(in_device)->MergePipelineCaches(in_device, in_dstCache, args.srcCacheCount, in_pSrcCaches);
    CheckResult("vkMergePipelineCaches", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
    args::CreateComputePipelines&               args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_pipelineCache = GetObjectInfoTable().GetVkPipelineCacheInfo(args.pipelineCache);

    MapStructArrayHandles(args.pCreateInfos.GetMetaStructPointer(), args.pCreateInfos.GetLength(), GetObjectInfoTable());
    if (!args.pPipelines.IsNull()) { args.pPipelines.SetHandleLength(args.createInfoCount); }
    if (omitted_pipeline_cache_data_) { AllowCompileDuringPipelineCreation(args.createInfoCount, args.pCreateInfos.GetPointer()); }
    std::vector<VulkanPipelineInfo> handle_info(args.createInfoCount);
    for (size_t i = 0; i < args.createInfoCount; ++i) { args.pPipelines.SetConsumerData(i, &handle_info[i]); }

    if (UseAsyncOperations())
    {
        auto task = AsyncCreateComputePipelines(GetDeviceTable(in_device->handle)->CreateComputePipelines, args.result, call_info, in_device, in_pipelineCache, args.createInfoCount, &args.pCreateInfos, &args.pAllocator, &args.pPipelines);
        if(task)
        {
           AddHandlesAsync<VulkanPipelineInfo>(args.device, args.pPipelines.GetPointer(), args.pPipelines.GetLength(), std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineInfo, std::move(task));
           return;
        }
    }
    PushRecaptureHandleIds(args.pPipelines.GetPointer(), args.pPipelines.GetLength());
    VkResult replay_result = OverrideCreateComputePipelines(GetDeviceTable(in_device->handle)->CreateComputePipelines, args.result, in_device, in_pipelineCache, args.createInfoCount, &args.pCreateInfos, &args.pAllocator, &args.pPipelines);
    CheckResult("vkCreateComputePipelines", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandles<VulkanPipelineInfo>(args.device, args.pPipelines.GetPointer(), args.pPipelines.GetLength(), args.pPipelines.GetHandlePointer(), args.createInfoCount, std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    args::DestroyPipeline&                      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_pipeline = GetObjectInfoTable().GetVkPipelineInfo(args.pipeline);

    OverrideDestroyPipeline(GetDeviceTable(in_device->handle)->DestroyPipeline, in_device, in_pipeline, &args.pAllocator);
    RemoveHandle(args.pipeline, &CommonObjectInfoTable::RemoveVkPipelineInfo);
}

void VulkanReplayConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineLayout&                 args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pPipelineLayout.IsNull()) { args.pPipelineLayout.SetHandleLength(1); }
    VulkanPipelineLayoutInfo handle_info;
    args.pPipelineLayout.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pPipelineLayout.GetPointer());
    VkResult replay_result = OverrideCreatePipelineLayout(GetDeviceTable(in_device->handle)->CreatePipelineLayout, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pPipelineLayout);
    CheckResult("vkCreatePipelineLayout", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanPipelineLayoutInfo>(args.device, args.pPipelineLayout.GetPointer(), args.pPipelineLayout.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineLayoutInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineLayout&                args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_pipelineLayout = GetObjectInfoTable().GetVkPipelineLayoutInfo(args.pipelineLayout);

    OverrideDestroyPipelineLayout(GetDeviceTable(in_device->handle)->DestroyPipelineLayout, in_device, in_pipelineLayout, &args.pAllocator);
    RemoveHandle(args.pipelineLayout, &CommonObjectInfoTable::RemoveVkPipelineLayoutInfo);
}

void VulkanReplayConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    args::CreateSampler&                        args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSampler.IsNull()) { args.pSampler.SetHandleLength(1); }
    VulkanSamplerInfo handle_info;
    args.pSampler.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSampler.GetPointer());
    VkResult replay_result = OverrideCreateSampler(GetDeviceTable(in_device->handle)->CreateSampler, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pSampler);
    CheckResult("vkCreateSampler", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSamplerInfo>(args.device, args.pSampler.GetPointer(), args.pSampler.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSamplerInfo);
}

void VulkanReplayConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    args::DestroySampler&                       args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSampler in_sampler = MapHandle<VulkanSamplerInfo>(args.sampler, &CommonObjectInfoTable::GetVkSamplerInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroySampler(in_device, in_sampler, in_pAllocator);
    RemoveHandle(args.sampler, &CommonObjectInfoTable::RemoveVkSamplerInfo);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorSetLayout&            args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSetLayout.IsNull()) { args.pSetLayout.SetHandleLength(1); }
    VulkanDescriptorSetLayoutInfo handle_info;
    args.pSetLayout.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSetLayout.GetPointer());
    VkResult replay_result = OverrideCreateDescriptorSetLayout(GetDeviceTable(in_device->handle)->CreateDescriptorSetLayout, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pSetLayout);
    CheckResult("vkCreateDescriptorSetLayout", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDescriptorSetLayoutInfo>(args.device, args.pSetLayout.GetPointer(), args.pSetLayout.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDescriptorSetLayoutInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorSetLayout&           args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDescriptorSetLayout in_descriptorSetLayout = MapHandle<VulkanDescriptorSetLayoutInfo>(args.descriptorSetLayout, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyDescriptorSetLayout(in_device, in_descriptorSetLayout, in_pAllocator);
    RemoveHandle(args.descriptorSetLayout, &CommonObjectInfoTable::RemoveVkDescriptorSetLayoutInfo);
}

void VulkanReplayConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorPool&                 args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pDescriptorPool.IsNull()) { args.pDescriptorPool.SetHandleLength(1); }
    VulkanDescriptorPoolInfo handle_info;
    args.pDescriptorPool.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pDescriptorPool.GetPointer());
    VkResult replay_result = OverrideCreateDescriptorPool(GetDeviceTable(in_device->handle)->CreateDescriptorPool, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pDescriptorPool);
    CheckResult("vkCreateDescriptorPool", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDescriptorPoolInfo>(args.device, args.pDescriptorPool.GetPointer(), args.pDescriptorPool.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDescriptorPoolInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorPool&                args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_descriptorPool = GetObjectInfoTable().GetVkDescriptorPoolInfo(args.descriptorPool);

    OverrideDestroyDescriptorPool(GetDeviceTable(in_device->handle)->DestroyDescriptorPool, in_device, in_descriptorPool, &args.pAllocator);
    RemovePoolHandle<VulkanDescriptorPoolInfo>(args.descriptorPool, &CommonObjectInfoTable::GetVkDescriptorPoolInfo, &CommonObjectInfoTable::RemoveVkDescriptorPoolInfo, &CommonObjectInfoTable::RemoveVkDescriptorSetInfo);
}

void VulkanReplayConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    args::ResetDescriptorPool&                  args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_descriptorPool = GetObjectInfoTable().GetVkDescriptorPoolInfo(args.descriptorPool);

    VkResult replay_result = OverrideResetDescriptorPool(GetDeviceTable(in_device->handle)->ResetDescriptorPool, args.result, in_device, in_descriptorPool, args.flags);
    CheckResult("vkResetDescriptorPool", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::AllocateDescriptorSets&               args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pAllocateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pDescriptorSets.IsNull()) { args.pDescriptorSets.SetHandleLength(args.pAllocateInfo.GetPointer()->descriptorSetCount); }
    std::vector<VulkanDescriptorSetInfo> handle_info(args.pAllocateInfo.GetPointer()->descriptorSetCount);
    for (size_t i = 0; i < args.pAllocateInfo.GetPointer()->descriptorSetCount; ++i) { args.pDescriptorSets.SetConsumerData(i, &handle_info[i]); }

    PushRecaptureHandleIds(args.pDescriptorSets.GetPointer(), args.pDescriptorSets.GetLength());
    VkResult replay_result = OverrideAllocateDescriptorSets(GetDeviceTable(in_device->handle)->AllocateDescriptorSets, args.result, in_device, &args.pAllocateInfo, &args.pDescriptorSets);
    CheckResult("vkAllocateDescriptorSets", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddPoolHandles<VulkanDescriptorPoolInfo, VulkanDescriptorSetInfo>(args.device, handle_mapping::GetPoolId(args.pAllocateInfo.GetMetaStructPointer()), args.pDescriptorSets.GetPointer(), args.pDescriptorSets.GetLength(), args.pDescriptorSets.GetHandlePointer(), args.pAllocateInfo.GetPointer()->descriptorSetCount, std::move(handle_info), &CommonObjectInfoTable::GetVkDescriptorPoolInfo, &CommonObjectInfoTable::AddVkDescriptorSetInfo);
}

void VulkanReplayConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::FreeDescriptorSets&                   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDescriptorPool in_descriptorPool = MapHandle<VulkanDescriptorPoolInfo>(args.descriptorPool, &CommonObjectInfoTable::GetVkDescriptorPoolInfo);
    const VkDescriptorSet* in_pDescriptorSets = MapHandles<VulkanDescriptorSetInfo>(&args.pDescriptorSets, args.descriptorSetCount, &CommonObjectInfoTable::GetVkDescriptorSetInfo);

    VkResult replay_result = GetDeviceTable(in_device)->FreeDescriptorSets(in_device, in_descriptorPool, args.descriptorSetCount, in_pDescriptorSets);
    CheckResult("vkFreeDescriptorSets", args.result, replay_result, call_info);
    RemovePoolHandles<VulkanDescriptorPoolInfo, VulkanDescriptorSetInfo>(args.descriptorPool, &args.pDescriptorSets, args.descriptorSetCount, &CommonObjectInfoTable::GetVkDescriptorPoolInfo, &CommonObjectInfoTable::RemoveVkDescriptorSetInfo);
}

void VulkanReplayConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::UpdateDescriptorSets&                 args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pDescriptorWrites.GetMetaStructPointer(), args.pDescriptorWrites.GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(args.pDescriptorCopies.GetMetaStructPointer(), args.pDescriptorCopies.GetLength(), GetObjectInfoTable());

    OverrideUpdateDescriptorSets(GetDeviceTable(in_device->handle)->UpdateDescriptorSets, in_device, args.descriptorWriteCount, &args.pDescriptorWrites, args.descriptorCopyCount, &args.pDescriptorCopies);
}

void VulkanReplayConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipeline&                      args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_pipeline = GetObjectInfoTable().GetVkPipelineInfo(args.pipeline);

    OverrideCmdBindPipeline(GetDeviceTable(in_commandBuffer->handle)->CmdBindPipeline, in_commandBuffer, args.pipelineBindPoint, in_pipeline);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindPipeline(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.pipelineBindPoint, in_pipeline);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets&                args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_layout = GetObjectInfoTable().GetVkPipelineLayoutInfo(args.layout);
    MapHandles<VulkanDescriptorSetInfo>(&args.pDescriptorSets, args.descriptorSetCount, &CommonObjectInfoTable::GetVkDescriptorSetInfo);

    OverrideCmdBindDescriptorSets(GetDeviceTable(in_commandBuffer->handle)->CmdBindDescriptorSets, in_commandBuffer, args.pipelineBindPoint, in_layout, args.firstSet, args.descriptorSetCount, &args.pDescriptorSets, args.dynamicOffsetCount, &args.pDynamicOffsets);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindDescriptorSets(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.pipelineBindPoint, in_layout, args.firstSet, args.descriptorSetCount, &args.pDescriptorSets, args.dynamicOffsetCount, args.pDynamicOffsets.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearColorImage&                   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(args.image, &CommonObjectInfoTable::GetVkImageInfo);
    const VkClearColorValue* in_pColor = args.pColor.GetPointer();
    const VkImageSubresourceRange* in_pRanges = args.pRanges.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearColorImage(in_commandBuffer, in_image, args.imageLayout, in_pColor, args.rangeCount, in_pRanges);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdClearColorImage(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_image, args.imageLayout, in_pColor, args.rangeCount, in_pRanges);
    }
}

void VulkanReplayConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    args::CmdDispatch&                          args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    OverrideCmdDispatch(GetDeviceTable(in_commandBuffer->handle)->CmdDispatch, in_commandBuffer, args.groupCountX, args.groupCountY, args.groupCountZ);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDispatch(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.groupCountX, args.groupCountY, args.groupCountZ);
    }
}

void VulkanReplayConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect&                  args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_buffer = GetObjectInfoTable().GetVkBufferInfo(args.buffer);

    OverrideCmdDispatchIndirect(GetDeviceTable(in_commandBuffer->handle)->CmdDispatchIndirect, in_commandBuffer, in_buffer, args.offset);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDispatchIndirect(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_buffer, args.offset);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent&                          args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_event = GetObjectInfoTable().GetVkEventInfo(args.event);

    OverrideCmdSetEvent(GetDeviceTable(in_commandBuffer->handle)->CmdSetEvent, in_commandBuffer, in_event, args.stageMask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetEvent(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_event->handle, args.stageMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent&                        args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_event = GetObjectInfoTable().GetVkEventInfo(args.event);

    OverrideCmdResetEvent(GetDeviceTable(in_commandBuffer->handle)->CmdResetEvent, in_commandBuffer, in_event, args.stageMask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdResetEvent(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_event->handle, args.stageMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents&                        args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    MapHandles<VulkanEventInfo>(&args.pEvents, args.eventCount, &CommonObjectInfoTable::GetVkEventInfo);

    MapStructArrayHandles(args.pMemoryBarriers.GetMetaStructPointer(), args.pMemoryBarriers.GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(args.pBufferMemoryBarriers.GetMetaStructPointer(), args.pBufferMemoryBarriers.GetLength(), GetObjectInfoTable());

    MapStructArrayHandles(args.pImageMemoryBarriers.GetMetaStructPointer(), args.pImageMemoryBarriers.GetLength(), GetObjectInfoTable());

    OverrideCmdWaitEvents(GetDeviceTable(in_commandBuffer->handle)->CmdWaitEvents, in_commandBuffer, args.eventCount, &args.pEvents, args.srcStageMask, args.dstStageMask, args.memoryBarrierCount, &args.pMemoryBarriers, args.bufferMemoryBarrierCount, &args.pBufferMemoryBarriers, args.imageMemoryBarrierCount, &args.pImageMemoryBarriers);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWaitEvents(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.eventCount, args.pEvents.GetHandlePointer(), args.srcStageMask, args.dstStageMask, args.memoryBarrierCount, args.pMemoryBarriers.GetPointer(), args.bufferMemoryBarrierCount, args.pBufferMemoryBarriers.GetPointer(), args.imageMemoryBarrierCount, args.pImageMemoryBarriers.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants&                     args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_layout = GetObjectInfoTable().GetVkPipelineLayoutInfo(args.layout);

    OverrideCmdPushConstants(GetDeviceTable(in_commandBuffer->handle)->CmdPushConstants, in_commandBuffer, in_layout, args.stageFlags, args.offset, args.size, &args.pValues);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPushConstants(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_layout->handle, args.stageFlags, args.offset, args.size, args.pValues.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
    args::CreateGraphicsPipelines&              args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_pipelineCache = GetObjectInfoTable().GetVkPipelineCacheInfo(args.pipelineCache);

    MapStructArrayHandles(args.pCreateInfos.GetMetaStructPointer(), args.pCreateInfos.GetLength(), GetObjectInfoTable());
    if (!args.pPipelines.IsNull()) { args.pPipelines.SetHandleLength(args.createInfoCount); }
    if (omitted_pipeline_cache_data_) { AllowCompileDuringPipelineCreation(args.createInfoCount, args.pCreateInfos.GetPointer()); }
    std::vector<VulkanPipelineInfo> handle_info(args.createInfoCount);
    for (size_t i = 0; i < args.createInfoCount; ++i) { args.pPipelines.SetConsumerData(i, &handle_info[i]); }

    if (UseAsyncOperations())
    {
        auto task = AsyncCreateGraphicsPipelines(GetDeviceTable(in_device->handle)->CreateGraphicsPipelines, args.result, call_info, in_device, in_pipelineCache, args.createInfoCount, &args.pCreateInfos, &args.pAllocator, &args.pPipelines);
        if(task)
        {
           AddHandlesAsync<VulkanPipelineInfo>(args.device, args.pPipelines.GetPointer(), args.pPipelines.GetLength(), std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineInfo, std::move(task));
           return;
        }
    }
    PushRecaptureHandleIds(args.pPipelines.GetPointer(), args.pPipelines.GetLength());
    VkResult replay_result = OverrideCreateGraphicsPipelines(GetDeviceTable(in_device->handle)->CreateGraphicsPipelines, args.result, in_device, in_pipelineCache, args.createInfoCount, &args.pCreateInfos, &args.pAllocator, &args.pPipelines);
    CheckResult("vkCreateGraphicsPipelines", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandles<VulkanPipelineInfo>(args.device, args.pPipelines.GetPointer(), args.pPipelines.GetLength(), args.pPipelines.GetHandlePointer(), args.createInfoCount, std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineInfo);
}

void VulkanReplayConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    args::CreateFramebuffer&                    args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pFramebuffer.IsNull()) { args.pFramebuffer.SetHandleLength(1); }
    VulkanFramebufferInfo handle_info;
    args.pFramebuffer.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pFramebuffer.GetPointer());
    VkResult replay_result = OverrideCreateFramebuffer(GetDeviceTable(in_device->handle)->CreateFramebuffer, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pFramebuffer);
    CheckResult("vkCreateFramebuffer", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanFramebufferInfo>(args.device, args.pFramebuffer.GetPointer(), args.pFramebuffer.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkFramebufferInfo);
}

void VulkanReplayConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    args::DestroyFramebuffer&                   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkFramebuffer in_framebuffer = MapHandle<VulkanFramebufferInfo>(args.framebuffer, &CommonObjectInfoTable::GetVkFramebufferInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyFramebuffer(in_device, in_framebuffer, in_pAllocator);
    RemoveHandle(args.framebuffer, &CommonObjectInfoTable::RemoveVkFramebufferInfo);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass&                     args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pRenderPass.IsNull()) { args.pRenderPass.SetHandleLength(1); }
    VulkanRenderPassInfo handle_info;
    args.pRenderPass.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pRenderPass.GetPointer());
    VkResult replay_result = OverrideCreateRenderPass(GetDeviceTable(in_device->handle)->CreateRenderPass, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pRenderPass);
    CheckResult("vkCreateRenderPass", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanRenderPassInfo>(args.device, args.pRenderPass.GetPointer(), args.pRenderPass.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    args::DestroyRenderPass&                    args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_renderPass = GetObjectInfoTable().GetVkRenderPassInfo(args.renderPass);

    OverrideDestroyRenderPass(GetDeviceTable(in_device->handle)->DestroyRenderPass, in_device, in_renderPass, &args.pAllocator);
    RemoveHandle(args.renderPass, &CommonObjectInfoTable::RemoveVkRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    args::GetRenderAreaGranularity&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkRenderPass in_renderPass = MapHandle<VulkanRenderPassInfo>(args.renderPass, &CommonObjectInfoTable::GetVkRenderPassInfo);
    VkExtent2D* out_pGranularity = args.pGranularity.IsNull() ? nullptr : args.pGranularity.AllocateOutputData(1);

    GetDeviceTable(in_device)->GetRenderAreaGranularity(in_device, in_renderPass, out_pGranularity);
}

void VulkanReplayConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewport&                       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkViewport* in_pViewports = args.pViewports.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewport(in_commandBuffer, args.firstViewport, args.viewportCount, in_pViewports);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetViewport(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstViewport, args.viewportCount, in_pViewports);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissor&                        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRect2D* in_pScissors = args.pScissors.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetScissor(in_commandBuffer, args.firstScissor, args.scissorCount, in_pScissors);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetScissor(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstScissor, args.scissorCount, in_pScissors);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineWidth&                      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineWidth(in_commandBuffer, args.lineWidth);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetLineWidth(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.lineWidth);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBias&                      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBias(in_commandBuffer, args.depthBiasConstantFactor, args.depthBiasClamp, args.depthBiasSlopeFactor);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthBias(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthBiasConstantFactor, args.depthBiasClamp, args.depthBiasSlopeFactor);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    args::CmdSetBlendConstants&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const float* in_blendConstants = args.blendConstants.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetBlendConstants(in_commandBuffer, in_blendConstants);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetBlendConstants(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_blendConstants);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBounds&                    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBounds(in_commandBuffer, args.minDepthBounds, args.maxDepthBounds);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthBounds(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.minDepthBounds, args.maxDepthBounds);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilCompareMask&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilCompareMask(in_commandBuffer, args.faceMask, args.compareMask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetStencilCompareMask(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.faceMask, args.compareMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilWriteMask&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilWriteMask(in_commandBuffer, args.faceMask, args.writeMask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetStencilWriteMask(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.faceMask, args.writeMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilReference&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilReference(in_commandBuffer, args.faceMask, args.reference);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetStencilReference(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.faceMask, args.reference);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer&                   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindIndexBuffer(in_commandBuffer, in_buffer, args.offset, args.indexType);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindIndexBuffer(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.buffer), args.offset, args.indexType);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<VulkanBufferInfo>(&args.pBuffers, args.bindingCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pOffsets = args.pOffsets.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers(in_commandBuffer, args.firstBinding, args.bindingCount, in_pBuffers, in_pOffsets);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindVertexBuffers(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstBinding, args.bindingCount, &args.pBuffers, in_pOffsets);
    }
}

void VulkanReplayConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    args::CmdDraw&                              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDraw(in_commandBuffer, args.vertexCount, args.instanceCount, args.firstVertex, args.firstInstance);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDraw(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.vertexCount, args.instanceCount, args.firstVertex, args.firstInstance);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexed&                       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexed(in_commandBuffer, args.indexCount, args.instanceCount, args.firstIndex, args.vertexOffset, args.firstInstance);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndexed(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.indexCount, args.instanceCount, args.firstIndex, args.vertexOffset, args.firstInstance);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect&                      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirect(in_commandBuffer, in_buffer, args.offset, args.drawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndirect(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.buffer), args.offset, args.drawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirect(in_commandBuffer, in_buffer, args.offset, args.drawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndexedIndirect(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.buffer), args.offset, args.drawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage&                         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_srcImage = MapHandle<VulkanImageInfo>(args.srcImage, &CommonObjectInfoTable::GetVkImageInfo);
    VkImage in_dstImage = MapHandle<VulkanImageInfo>(args.dstImage, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageBlit* in_pRegions = args.pRegions.GetPointer();

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdBlitImage(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkImageInfo(args.srcImage), args.srcImageLayout, GetObjectInfoTable().GetVkImageInfo(args.dstImage), args.dstImageLayout, args.regionCount, &args.pRegions, args.filter, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdBlitImage(in_commandBuffer, in_srcImage, args.srcImageLayout, in_dstImage, args.dstImageLayout, args.regionCount, in_pRegions, args.filter);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBlitImage(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkImageInfo(args.srcImage), args.srcImageLayout, GetObjectInfoTable().GetVkImageInfo(args.dstImage), args.dstImageLayout, args.regionCount, &args.pRegions, args.filter, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearDepthStencilImage&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(args.image, &CommonObjectInfoTable::GetVkImageInfo);
    const VkClearDepthStencilValue* in_pDepthStencil = args.pDepthStencil.GetPointer();
    const VkImageSubresourceRange* in_pRanges = args.pRanges.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearDepthStencilImage(in_commandBuffer, in_image, args.imageLayout, in_pDepthStencil, args.rangeCount, in_pRanges);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdClearDepthStencilImage(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_image, args.imageLayout, in_pDepthStencil, args.rangeCount, in_pRanges);
    }
}

void VulkanReplayConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    args::CmdClearAttachments&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkClearAttachment* in_pAttachments = args.pAttachments.GetPointer();
    const VkClearRect* in_pRects = args.pRects.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdClearAttachments(in_commandBuffer, args.attachmentCount, in_pAttachments, args.rectCount, in_pRects);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdClearAttachments(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.attachmentCount, in_pAttachments, args.rectCount, in_pRects);
    }
}

void VulkanReplayConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage&                      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImage in_srcImage = MapHandle<VulkanImageInfo>(args.srcImage, &CommonObjectInfoTable::GetVkImageInfo);
    VkImage in_dstImage = MapHandle<VulkanImageInfo>(args.dstImage, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageResolve* in_pRegions = args.pRegions.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdResolveImage(in_commandBuffer, in_srcImage, args.srcImageLayout, in_dstImage, args.dstImageLayout, args.regionCount, in_pRegions);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdResolveImage(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_srcImage, args.srcImageLayout, in_dstImage, args.dstImageLayout, args.regionCount, in_pRegions);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass&                   args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pRenderPassBegin.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdBeginRenderPass(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass, in_commandBuffer, &args.pRenderPassBegin, args.contents);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginRenderPass(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pRenderPassBegin, args.contents);
    }
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass&                       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass(in_commandBuffer, args.contents);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdNextSubpass(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.contents);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass&                     args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    OverrideCmdEndRenderPass(GetDeviceTable(in_commandBuffer->handle)->CmdEndRenderPass, in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndRenderPass(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle);
    }
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory2&                    args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pBindInfos.GetMetaStructPointer(), args.pBindInfos.GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindBufferMemory2(GetDeviceTable(in_device->handle)->BindBufferMemory2, args.result, in_device, args.bindInfoCount, &args.pBindInfos);
    CheckResult("vkBindBufferMemory2", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory2&                     args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pBindInfos.GetMetaStructPointer(), args.pBindInfos.GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindImageMemory2(GetDeviceTable(in_device->handle)->BindImageMemory2, args.result, in_device, args.bindInfoCount, &args.pBindInfos);
    CheckResult("vkBindImageMemory2", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupPeerMemoryFeatures&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = args.pPeerMemoryFeatures.IsNull() ? nullptr : args.pPeerMemoryFeatures.AllocateOutputData(1, static_cast<VkPeerMemoryFeatureFlags>(0));

    GetDeviceTable(in_device)->GetDeviceGroupPeerMemoryFeatures(in_device, args.heapIndex, args.localDeviceIndex, args.remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetDeviceMask&                     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDeviceMask(in_commandBuffer, args.deviceMask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDeviceMask(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.deviceMask);
    }
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceGroups&        args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);
    args.pPhysicalDeviceGroupCount.IsNull() ? nullptr : args.pPhysicalDeviceGroupCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanInstanceInfo>("vkEnumeratePhysicalDeviceGroups", args.result, args.instance, kInstanceArrayEnumeratePhysicalDeviceGroups, &args.pPhysicalDeviceGroupCount, &args.pPhysicalDeviceGroupProperties, &CommonObjectInfoTable::GetVkInstanceInfo));
    SetStructArrayHandleLengths<Decoded_VkPhysicalDeviceGroupProperties>(args.pPhysicalDeviceGroupProperties.GetMetaStructPointer(), args.pPhysicalDeviceGroupProperties.GetLength());
    if (!args.pPhysicalDeviceGroupProperties.IsNull()) { args.pPhysicalDeviceGroupProperties.AllocateOutputData(*args.pPhysicalDeviceGroupCount.GetOutputPointer(), VkPhysicalDeviceGroupProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, nullptr }); }

    PushRecaptureStructArrayHandleIds(args.pPhysicalDeviceGroupProperties.GetMetaStructPointer(), args.pPhysicalDeviceGroupProperties.GetLength(), this);
    VkResult replay_result = OverrideEnumeratePhysicalDeviceGroups(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDeviceGroups, args.result, in_instance, &args.pPhysicalDeviceGroupCount, &args.pPhysicalDeviceGroupProperties);
    CheckResult("vkEnumeratePhysicalDeviceGroups", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pPhysicalDeviceGroupProperties.IsNull()) { SetOutputArrayCount<VulkanInstanceInfo>(args.instance, kInstanceArrayEnumeratePhysicalDeviceGroups, *args.pPhysicalDeviceGroupCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkInstanceInfo); }
    AddStructArrayHandles<Decoded_VkPhysicalDeviceGroupProperties>(args.instance, args.pPhysicalDeviceGroupProperties.GetMetaStructPointer(), args.pPhysicalDeviceGroupProperties.GetLength(), args.pPhysicalDeviceGroupProperties.GetOutputPointer(), *args.pPhysicalDeviceGroupCount.GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    args::GetImageMemoryRequirements2&          args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    OverrideGetImageMemoryRequirements2(GetDeviceTable(in_device->handle)->GetImageMemoryRequirements2, in_device, &args.pInfo, &args.pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    args::GetBufferMemoryRequirements2&         args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    OverrideGetBufferMemoryRequirements2(GetDeviceTable(in_device->handle)->GetBufferMemoryRequirements2, in_device, &args.pInfo, &args.pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    args::GetImageSparseMemoryRequirements2&    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImageSparseMemoryRequirementsInfo2* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = args.pSparseMemoryRequirementCount.IsNull() ? nullptr : args.pSparseMemoryRequirementCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetImageSparseMemoryRequirements2", VK_SUCCESS, args.device, kDeviceArrayGetImageSparseMemoryRequirements2, &args.pSparseMemoryRequirementCount, &args.pSparseMemoryRequirements, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = args.pSparseMemoryRequirements.IsNull() ? nullptr : args.pSparseMemoryRequirements.AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements2(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (args.pSparseMemoryRequirements.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetImageSparseMemoryRequirements2, *out_pSparseMemoryRequirementCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFeatures2&           args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkPhysicalDeviceFeatures2* out_pFeatures = args.pFeatures.IsNull() ? nullptr : args.pFeatures.AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr });
    InitializeOutputStructPNext(&args.pFeatures);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures2(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceProperties2&         args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(&args.pProperties);

    OverrideGetPhysicalDeviceProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties2, in_physicalDevice, &args.pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFormatProperties2&   args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkFormatProperties2* out_pFormatProperties = args.pFormatProperties.IsNull() ? nullptr : args.pFormatProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(&args.pFormatProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties2(in_physicalDevice, args.format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceImageFormatProperties2& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = args.pImageFormatInfo.GetPointer();
    MapStructHandles(args.pImageFormatInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkImageFormatProperties2* out_pImageFormatProperties = args.pImageFormatProperties.IsNull() ? nullptr : args.pImageFormatProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(&args.pImageFormatProperties);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties2(in_physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties2", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyProperties2& args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pQueueFamilyPropertyCount.IsNull() ? nullptr : args.pQueueFamilyPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties2", VK_SUCCESS, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2, &args.pQueueFamilyPropertyCount, &args.pQueueFamilyProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    if (!args.pQueueFamilyProperties.IsNull()) { args.pQueueFamilyProperties.AllocateOutputData(*args.pQueueFamilyPropertyCount.GetOutputPointer(), VkQueueFamilyProperties2{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, nullptr }); }

    OverrideGetPhysicalDeviceQueueFamilyProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceQueueFamilyProperties2, in_physicalDevice, &args.pQueueFamilyPropertyCount, &args.pQueueFamilyProperties);

    if (args.pQueueFamilyProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2, *args.pQueueFamilyPropertyCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMemoryProperties2&   args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pMemoryProperties.IsNull() ? nullptr : args.pMemoryProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryProperties);

    OverrideGetPhysicalDeviceMemoryProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties2, in_physicalDevice, &args.pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSparseImageFormatProperties2& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = args.pFormatInfo.GetPointer();
    MapStructHandles(args.pFormatInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties2", VK_SUCCESS, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkSparseImageFormatProperties2* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount, VkSparseImageFormatProperties2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(in_physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    args::TrimCommandPool&                      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkCommandPool in_commandPool = MapHandle<VulkanCommandPoolInfo>(args.commandPool, &CommonObjectInfoTable::GetVkCommandPoolInfo);

    GetDeviceTable(in_device)->TrimCommandPool(in_device, in_commandPool, args.flags);
}

void VulkanReplayConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    args::GetDeviceQueue2&                      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pQueueInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pQueue.IsNull()) { args.pQueue.SetHandleLength(1); }
    VulkanQueueInfo handle_info;
    args.pQueue.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pQueue.GetPointer());
    OverrideGetDeviceQueue2(GetDeviceTable(in_device->handle)->GetDeviceQueue2, in_device, &args.pQueueInfo, &args.pQueue);
    ClearRecaptureHandleIds();

    AddHandle<VulkanQueueInfo>(args.device, args.pQueue.GetPointer(), args.pQueue.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkQueueInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalBufferProperties& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = args.pExternalBufferInfo.GetPointer();
    MapStructHandles(args.pExternalBufferInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkExternalBufferProperties* out_pExternalBufferProperties = args.pExternalBufferProperties.IsNull() ? nullptr : args.pExternalBufferProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, nullptr });
    InitializeOutputStructPNext(&args.pExternalBufferProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalBufferProperties(in_physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalFenceProperties& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = args.pExternalFenceInfo.GetPointer();
    MapStructHandles(args.pExternalFenceInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkExternalFenceProperties* out_pExternalFenceProperties = args.pExternalFenceProperties.IsNull() ? nullptr : args.pExternalFenceProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, nullptr });
    InitializeOutputStructPNext(&args.pExternalFenceProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalFenceProperties(in_physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalSemaphoreProperties& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = args.pExternalSemaphoreInfo.GetPointer();
    MapStructHandles(args.pExternalSemaphoreInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = args.pExternalSemaphoreProperties.IsNull() ? nullptr : args.pExternalSemaphoreProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, nullptr });
    InitializeOutputStructPNext(&args.pExternalSemaphoreProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(in_physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

void VulkanReplayConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchBase&                      args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    OverrideCmdDispatchBase(GetDeviceTable(in_commandBuffer->handle)->CmdDispatchBase, in_commandBuffer, args.baseGroupX, args.baseGroupY, args.baseGroupZ, args.groupCountX, args.groupCountY, args.groupCountZ);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDispatchBase(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.baseGroupX, args.baseGroupY, args.baseGroupZ, args.groupCountX, args.groupCountY, args.groupCountZ);
    }
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorUpdateTemplate&       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pDescriptorUpdateTemplate.IsNull()) { args.pDescriptorUpdateTemplate.SetHandleLength(1); }
    VulkanDescriptorUpdateTemplateInfo handle_info;
    args.pDescriptorUpdateTemplate.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pDescriptorUpdateTemplate.GetPointer());
    VkResult replay_result = OverrideCreateDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->CreateDescriptorUpdateTemplate, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pDescriptorUpdateTemplate);
    CheckResult("vkCreateDescriptorUpdateTemplate", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDescriptorUpdateTemplateInfo>(args.device, args.pDescriptorUpdateTemplate.GetPointer(), args.pDescriptorUpdateTemplate.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorUpdateTemplate&      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_descriptorUpdateTemplate = GetObjectInfoTable().GetVkDescriptorUpdateTemplateInfo(args.descriptorUpdateTemplate);

    OverrideDestroyDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->DestroyDescriptorUpdateTemplate, in_device, in_descriptorUpdateTemplate, &args.pAllocator);
    RemoveHandle(args.descriptorUpdateTemplate, &CommonObjectInfoTable::RemoveVkDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutSupport&        args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkDescriptorSetLayoutSupport* out_pSupport = args.pSupport.IsNull() ? nullptr : args.pSupport.AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, nullptr });
    InitializeOutputStructPNext(&args.pSupport);

    GetDeviceTable(in_device)->GetDescriptorSetLayoutSupport(in_device, in_pCreateInfo, out_pSupport);
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    args::CreateSamplerYcbcrConversion&         args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pYcbcrConversion.IsNull()) { args.pYcbcrConversion.SetHandleLength(1); }
    VulkanSamplerYcbcrConversionInfo handle_info;
    args.pYcbcrConversion.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pYcbcrConversion.GetPointer());
    VkResult replay_result = OverrideCreateSamplerYcbcrConversion(GetDeviceTable(in_device->handle)->CreateSamplerYcbcrConversion, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pYcbcrConversion);
    CheckResult("vkCreateSamplerYcbcrConversion", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSamplerYcbcrConversionInfo>(args.device, args.pYcbcrConversion.GetPointer(), args.pYcbcrConversion.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    args::DestroySamplerYcbcrConversion&        args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSamplerYcbcrConversion in_ycbcrConversion = MapHandle<VulkanSamplerYcbcrConversionInfo>(args.ycbcrConversion, &CommonObjectInfoTable::GetVkSamplerYcbcrConversionInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroySamplerYcbcrConversion(in_device, in_ycbcrConversion, in_pAllocator);
    RemoveHandle(args.ycbcrConversion, &CommonObjectInfoTable::RemoveVkSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    args::ResetQueryPool&                       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool);

    OverrideResetQueryPool(GetDeviceTable(in_device->handle)->ResetQueryPool, in_device, in_queryPool, args.firstQuery, args.queryCount);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreCounterValue(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreCounterValue&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSemaphore in_semaphore = MapHandle<VulkanSemaphoreInfo>(args.semaphore, &CommonObjectInfoTable::GetVkSemaphoreInfo);
    uint64_t* out_pValue = args.pValue.IsNull() ? nullptr : args.pValue.AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreCounterValue(in_device, in_semaphore, out_pValue);
    CheckResult("vkGetSemaphoreCounterValue", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    args::WaitSemaphores&                       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pWaitInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideWaitSemaphores(GetDeviceTable(in_device->handle)->WaitSemaphores, args.result, in_device, &args.pWaitInfo, args.timeout);
    CheckResult("vkWaitSemaphores", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    args::SignalSemaphore&                      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreSignalInfo* in_pSignalInfo = args.pSignalInfo.GetPointer();
    MapStructHandles(args.pSignalInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->SignalSemaphore(in_device, in_pSignalInfo);
    CheckResult("vkSignalSemaphore", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    args::GetBufferDeviceAddress&               args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetBufferDeviceAddress(GetDeviceTable(in_device->handle)->GetBufferDeviceAddress, args.result, in_device, &args.pInfo);
}

void VulkanReplayConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    args::GetBufferOpaqueCaptureAddress&        args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkBufferDeviceAddressInfo* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetBufferOpaqueCaptureAddress(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMemoryOpaqueCaptureAddress&  args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetDeviceMemoryOpaqueCaptureAddress(GetDeviceTable(in_device->handle)->GetDeviceMemoryOpaqueCaptureAddress, in_device, &args.pInfo);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(args.countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCount(in_commandBuffer, in_buffer, args.offset, in_countBuffer, args.countBufferOffset, args.maxDrawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndirectCount(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.buffer), args.offset, GetObjectInfoTable().GetVkBufferInfo(args.countBuffer), args.countBufferOffset, args.maxDrawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(args.countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCount(in_commandBuffer, in_buffer, args.offset, in_countBuffer, args.countBufferOffset, args.maxDrawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndexedIndirectCount(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.buffer), args.offset, GetObjectInfoTable().GetVkBufferInfo(args.countBuffer), args.countBufferOffset, args.maxDrawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass2&                    args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pRenderPass.IsNull()) { args.pRenderPass.SetHandleLength(1); }
    VulkanRenderPassInfo handle_info;
    args.pRenderPass.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pRenderPass.GetPointer());
    VkResult replay_result = OverrideCreateRenderPass2(GetDeviceTable(in_device->handle)->CreateRenderPass2, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pRenderPass);
    CheckResult("vkCreateRenderPass2", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanRenderPassInfo>(args.device, args.pRenderPass.GetPointer(), args.pRenderPass.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2&                  args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pRenderPassBegin.GetMetaStructPointer(), GetObjectInfoTable());

    MapStructHandles(args.pSubpassBeginInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdBeginRenderPass2(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass2, in_commandBuffer, &args.pRenderPassBegin, &args.pSubpassBeginInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginRenderPass2(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pRenderPassBegin, &args.pSubpassBeginInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass2&                      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSubpassBeginInfo* in_pSubpassBeginInfo = args.pSubpassBeginInfo.GetPointer();
    MapStructHandles(args.pSubpassBeginInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkSubpassEndInfo* in_pSubpassEndInfo = args.pSubpassEndInfo.GetPointer();
    MapStructHandles(args.pSubpassEndInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass2(in_commandBuffer, in_pSubpassBeginInfo, in_pSubpassEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdNextSubpass2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pSubpassBeginInfo, &args.pSubpassEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass2&                    args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pSubpassEndInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdEndRenderPass2(GetDeviceTable(in_commandBuffer->handle)->CmdEndRenderPass2, in_commandBuffer, &args.pSubpassEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndRenderPass2(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pSubpassEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceToolProperties&      args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pToolCount.IsNull() ? nullptr : args.pToolCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceToolProperties", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolProperties, &args.pToolCount, &args.pToolProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    if (!args.pToolProperties.IsNull()) { args.pToolProperties.AllocateOutputData(*args.pToolCount.GetOutputPointer(), VkPhysicalDeviceToolProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES, nullptr }); }

    VkResult replay_result = OverrideGetPhysicalDeviceToolProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceToolProperties, args.result, in_physicalDevice, &args.pToolCount, &args.pToolProperties);
    CheckResult("vkGetPhysicalDeviceToolProperties", args.result, replay_result, call_info);

    if (args.pToolProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolProperties, *args.pToolCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    args::CreatePrivateDataSlot&                args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPrivateDataSlotCreateInfo* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pPrivateDataSlot.IsNull()) { args.pPrivateDataSlot.SetHandleLength(1); }
    VkPrivateDataSlot* out_pPrivateDataSlot = args.pPrivateDataSlot.GetHandlePointer();

    PushRecaptureHandleId(args.pPrivateDataSlot.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreatePrivateDataSlot(in_device, in_pCreateInfo, in_pAllocator, out_pPrivateDataSlot);
    CheckResult("vkCreatePrivateDataSlot", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanPrivateDataSlotInfo>(args.device, args.pPrivateDataSlot.GetPointer(), out_pPrivateDataSlot, &CommonObjectInfoTable::AddVkPrivateDataSlotInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    args::DestroyPrivateDataSlot&               args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(args.privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyPrivateDataSlot(in_device, in_privateDataSlot, in_pAllocator);
    RemoveHandle(args.privateDataSlot, &CommonObjectInfoTable::RemoveVkPrivateDataSlotInfo);
}

void VulkanReplayConsumer::Process_vkSetPrivateData(
    const ApiCallInfo&                          call_info,
    args::SetPrivateData&                       args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    uint64_t in_objectHandle = MapHandle(args.objectHandle, args.objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(args.privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);

    VkResult replay_result = GetDeviceTable(in_device)->SetPrivateData(in_device, args.objectType, in_objectHandle, in_privateDataSlot, args.data);
    CheckResult("vkSetPrivateData", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
    args::GetPrivateData&                       args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    uint64_t in_objectHandle = MapHandle(args.objectHandle, args.objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(args.privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);
    uint64_t* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(1, static_cast<uint64_t>(0));

    GetDeviceTable(in_device)->GetPrivateData(in_device, args.objectType, in_objectHandle, in_privateDataSlot, out_pData);
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2&                  args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pDependencyInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdPipelineBarrier2(GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier2, in_commandBuffer, &args.pDependencyInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPipelineBarrier2(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.pDependencyInfo.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp2&                   args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool);

    OverrideCmdWriteTimestamp2(GetDeviceTable(in_commandBuffer->handle)->CmdWriteTimestamp2, in_commandBuffer, args.stage, in_queryPool, args.query);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWriteTimestamp2(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.stage, in_queryPool, args.query);
    }
}

void VulkanReplayConsumer::Process_vkQueueSubmit2(
    const ApiCallInfo&                          call_info,
    args::QueueSubmit2&                         args)
{
    auto in_queue = GetObjectInfoTable().GetVkQueueInfo(args.queue);

    MapStructArrayHandles(args.pSubmits.GetMetaStructPointer(), args.pSubmits.GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(args.fence);

    VkResult replay_result = OverrideQueueSubmit2(GetDeviceTable(in_queue->handle)->QueueSubmit2, call_info.index, args.result, in_queue, args.submitCount, &args.pSubmits, in_fence);
    CheckResult("vkQueueSubmit2", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2&                       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyBufferInfo2* in_pCopyBufferInfo = args.pCopyBufferInfo.GetPointer();
    MapStructHandles(args.pCopyBufferInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyBuffer2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyBufferInfo, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyBuffer2(in_commandBuffer, in_pCopyBufferInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyBuffer2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyBufferInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2&                        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyImageInfo2* in_pCopyImageInfo = args.pCopyImageInfo.GetPointer();
    MapStructHandles(args.pCopyImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyImage2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyImageInfo, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyImage2(in_commandBuffer, in_pCopyImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyImage2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyImageInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2&                args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyBufferToImageInfo2* in_pCopyBufferToImageInfo = args.pCopyBufferToImageInfo.GetPointer();
    MapStructHandles(args.pCopyBufferToImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyBufferToImage2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyBufferToImageInfo, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage2(in_commandBuffer, in_pCopyBufferToImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyBufferToImage2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyBufferToImageInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2&                args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyImageToBufferInfo2* in_pCopyImageToBufferInfo = args.pCopyImageToBufferInfo.GetPointer();
    MapStructHandles(args.pCopyImageToBufferInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyImageToBuffer2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyImageToBufferInfo, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer2(in_commandBuffer, in_pCopyImageToBufferInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyImageToBuffer2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyImageToBufferInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetDeviceBufferMemoryRequirements&    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceBufferMemoryRequirements* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    GetDeviceTable(in_device)->GetDeviceBufferMemoryRequirements(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageMemoryRequirements&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    GetDeviceTable(in_device)->GetDeviceImageMemoryRequirements(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSparseMemoryRequirements& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = args.pSparseMemoryRequirementCount.IsNull() ? nullptr : args.pSparseMemoryRequirementCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetDeviceImageSparseMemoryRequirements", VK_SUCCESS, args.device, kDeviceArrayGetDeviceImageSparseMemoryRequirements, &args.pSparseMemoryRequirementCount, &args.pSparseMemoryRequirements, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = args.pSparseMemoryRequirements.IsNull() ? nullptr : args.pSparseMemoryRequirements.AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetDeviceImageSparseMemoryRequirements(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (args.pSparseMemoryRequirements.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetDeviceImageSparseMemoryRequirements, *out_pSparseMemoryRequirementCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2&                         args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_event = GetObjectInfoTable().GetVkEventInfo(args.event);

    MapStructHandles(args.pDependencyInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdSetEvent2(GetDeviceTable(in_commandBuffer->handle)->CmdSetEvent2, in_commandBuffer, in_event, &args.pDependencyInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetEvent2(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_event->handle, args.pDependencyInfo.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent2&                       args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_event = GetObjectInfoTable().GetVkEventInfo(args.event);

    OverrideCmdResetEvent2(GetDeviceTable(in_commandBuffer->handle)->CmdResetEvent2, in_commandBuffer, in_event, args.stageMask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdResetEvent2(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_event->handle, args.stageMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2&                       args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    MapHandles<VulkanEventInfo>(&args.pEvents, args.eventCount, &CommonObjectInfoTable::GetVkEventInfo);

    MapStructArrayHandles(args.pDependencyInfos.GetMetaStructPointer(), args.pDependencyInfos.GetLength(), GetObjectInfoTable());

    OverrideCmdWaitEvents2(GetDeviceTable(in_commandBuffer->handle)->CmdWaitEvents2, in_commandBuffer, args.eventCount, &args.pEvents, &args.pDependencyInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWaitEvents2(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.eventCount, args.pEvents.GetHandlePointer(), args.pDependencyInfos.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2&                        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBlitImageInfo2* in_pBlitImageInfo = args.pBlitImageInfo.GetPointer();
    MapStructHandles(args.pBlitImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdBlitImage2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pBlitImageInfo, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdBlitImage2(in_commandBuffer, in_pBlitImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBlitImage2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pBlitImageInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2&                     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkResolveImageInfo2* in_pResolveImageInfo = args.pResolveImageInfo.GetPointer();
    MapStructHandles(args.pResolveImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdResolveImage2(in_commandBuffer, in_pResolveImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdResolveImage2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pResolveImageInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRendering&                    args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pRenderingInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdBeginRendering(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRendering, in_commandBuffer, &args.pRenderingInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginRendering(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pRenderingInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering&                      args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    OverrideCmdEndRendering(GetDeviceTable(in_commandBuffer->handle)->CmdEndRendering, in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndRendering(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    args::CmdSetCullMode&                       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCullMode(in_commandBuffer, args.cullMode);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetCullMode(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.cullMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    args::CmdSetFrontFace&                      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetFrontFace(in_commandBuffer, args.frontFace);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetFrontFace(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.frontFace);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveTopology&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveTopology(in_commandBuffer, args.primitiveTopology);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetPrimitiveTopology(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.primitiveTopology);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWithCount&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkViewport* in_pViewports = args.pViewports.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWithCount(in_commandBuffer, args.viewportCount, in_pViewports);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetViewportWithCount(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.viewportCount, in_pViewports);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissorWithCount&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRect2D* in_pScissors = args.pScissors.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetScissorWithCount(in_commandBuffer, args.scissorCount, in_pScissors);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetScissorWithCount(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.scissorCount, in_pScissors);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2&                args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<VulkanBufferInfo>(&args.pBuffers, args.bindingCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pOffsets = args.pOffsets.GetPointer();
    const VkDeviceSize* in_pSizes = args.pSizes.GetPointer();
    const VkDeviceSize* in_pStrides = args.pStrides.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers2(in_commandBuffer, args.firstBinding, args.bindingCount, in_pBuffers, in_pOffsets, in_pSizes, in_pStrides);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindVertexBuffers2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstBinding, args.bindingCount, &args.pBuffers, in_pOffsets, in_pSizes, in_pStrides);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthTestEnable&                args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthTestEnable(in_commandBuffer, args.depthTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthTestEnable(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthWriteEnable&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthWriteEnable(in_commandBuffer, args.depthWriteEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthWriteEnable(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthWriteEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthCompareOp&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthCompareOp(in_commandBuffer, args.depthCompareOp);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthCompareOp(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthCompareOp);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBoundsTestEnable&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBoundsTestEnable(in_commandBuffer, args.depthBoundsTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthBoundsTestEnable(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthBoundsTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilTestEnable&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilTestEnable(in_commandBuffer, args.stencilTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetStencilTestEnable(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.stencilTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilOp&                      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilOp(in_commandBuffer, args.faceMask, args.failOp, args.passOp, args.depthFailOp, args.compareOp);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetStencilOp(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.faceMask, args.failOp, args.passOp, args.depthFailOp, args.compareOp);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizerDiscardEnable&        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizerDiscardEnable(in_commandBuffer, args.rasterizerDiscardEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetRasterizerDiscardEnable(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.rasterizerDiscardEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBiasEnable&                args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBiasEnable(in_commandBuffer, args.depthBiasEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthBiasEnable(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthBiasEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartEnable&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveRestartEnable(in_commandBuffer, args.primitiveRestartEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetPrimitiveRestartEnable(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.primitiveRestartEnable);
    }
}

void VulkanReplayConsumer::Process_vkMapMemory2(
    const ApiCallInfo&                          call_info,
    args::MapMemory2&                           args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pMemoryMapInfo.GetMetaStructPointer(), GetObjectInfoTable());
    void** out_ppData = args.ppData.IsNull() ? nullptr : args.ppData.AllocateOutputData(1);

    VkResult replay_result = OverrideMapMemory2(GetDeviceTable(in_device->handle)->MapMemory2, args.result, in_device, &args.pMemoryMapInfo, out_ppData);
    CheckResult("vkMapMemory2", args.result, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*args.ppData.GetPointer()), *args.ppData.GetOutputPointer(), format::ApiCallId::ApiCall_vkMapMemory2, "vkMapMemory2");
}

void VulkanReplayConsumer::Process_vkUnmapMemory2(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory2&                         args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pMemoryUnmapInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideUnmapMemory2(GetDeviceTable(in_device->handle)->UnmapMemory2, args.result, in_device, &args.pMemoryUnmapInfo);
    CheckResult("vkUnmapMemory2", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSubresourceLayout&      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageSubresourceInfo* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkSubresourceLayout2* out_pLayout = args.pLayout.IsNull() ? nullptr : args.pLayout.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2, nullptr });
    InitializeOutputStructPNext(&args.pLayout);

    GetDeviceTable(in_device)->GetDeviceImageSubresourceLayout(in_device, in_pInfo, out_pLayout);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout2(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout2&           args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(args.image, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageSubresource2* in_pSubresource = args.pSubresource.GetPointer();
    MapStructHandles(args.pSubresource.GetMetaStructPointer(), GetObjectInfoTable());
    VkSubresourceLayout2* out_pLayout = args.pLayout.IsNull() ? nullptr : args.pLayout.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2, nullptr });
    InitializeOutputStructPNext(&args.pLayout);

    GetDeviceTable(in_device)->GetImageSubresourceLayout2(in_device, in_image, in_pSubresource, out_pLayout);
}

void VulkanReplayConsumer::Process_vkCopyMemoryToImage(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToImage&                    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCopyMemoryToImageInfo* in_pCopyMemoryToImageInfo = args.pCopyMemoryToImageInfo.GetPointer();
    MapStructHandles(args.pCopyMemoryToImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMemoryToImage(in_device, in_pCopyMemoryToImageInfo);
    CheckResult("vkCopyMemoryToImage", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyImageToMemory(
    const ApiCallInfo&                          call_info,
    args::CopyImageToMemory&                    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCopyImageToMemoryInfo* in_pCopyImageToMemoryInfo = args.pCopyImageToMemoryInfo.GetPointer();
    MapStructHandles(args.pCopyImageToMemoryInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyImageToMemory(in_device, in_pCopyImageToMemoryInfo);
    CheckResult("vkCopyImageToMemory", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyImageToImage(
    const ApiCallInfo&                          call_info,
    args::CopyImageToImage&                     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCopyImageToImageInfo* in_pCopyImageToImageInfo = args.pCopyImageToImageInfo.GetPointer();
    MapStructHandles(args.pCopyImageToImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyImageToImage(in_device, in_pCopyImageToImageInfo);
    CheckResult("vkCopyImageToImage", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkTransitionImageLayout(
    const ApiCallInfo&                          call_info,
    args::TransitionImageLayout&                args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkHostImageLayoutTransitionInfo* in_pTransitions = args.pTransitions.GetPointer();
    MapStructArrayHandles(args.pTransitions.GetMetaStructPointer(), args.pTransitions.GetLength(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->TransitionImageLayout(in_device, args.transitionCount, in_pTransitions);
    CheckResult("vkTransitionImageLayout", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSet(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipelineLayout in_layout = MapHandle<VulkanPipelineLayoutInfo>(args.layout, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);
    const VkWriteDescriptorSet* in_pDescriptorWrites = args.pDescriptorWrites.GetPointer();
    MapStructArrayHandles(args.pDescriptorWrites.GetMetaStructPointer(), args.pDescriptorWrites.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSet(in_commandBuffer, args.pipelineBindPoint, in_layout, args.set, args.descriptorWriteCount, in_pDescriptorWrites);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPushDescriptorSet(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.pipelineBindPoint, GetObjectInfoTable().GetVkPipelineLayoutInfo(args.layout), args.set, args.descriptorWriteCount, &args.pDescriptorWrites);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2&               args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pBindDescriptorSetsInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdBindDescriptorSets2(GetDeviceTable(in_commandBuffer->handle)->CmdBindDescriptorSets2, in_commandBuffer, &args.pBindDescriptorSetsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindDescriptorSets2(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pBindDescriptorSetsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdPushConstants2(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants2&                    args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pPushConstantsInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdPushConstants2(GetDeviceTable(in_commandBuffer->handle)->CmdPushConstants2, in_commandBuffer, &args.pPushConstantsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPushConstants2(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.pPushConstantsInfo.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2&                args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPushDescriptorSetInfo* in_pPushDescriptorSetInfo = args.pPushDescriptorSetInfo.GetPointer();
    MapStructHandles(args.pPushDescriptorSetInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSet2(in_commandBuffer, in_pPushDescriptorSetInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPushDescriptorSet2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pPushDescriptorSetInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLineStipple(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStipple&                    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineStipple(in_commandBuffer, args.lineStippleFactor, args.lineStipplePattern);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetLineStipple(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.lineStippleFactor, args.lineStipplePattern);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindIndexBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindIndexBuffer2(in_commandBuffer, in_buffer, args.offset, args.size, args.indexType);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindIndexBuffer2(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_buffer, args.offset, args.size, args.indexType);
    }
}

void VulkanReplayConsumer::Process_vkGetRenderingAreaGranularity(
    const ApiCallInfo&                          call_info,
    args::GetRenderingAreaGranularity&          args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkRenderingAreaInfo* in_pRenderingAreaInfo = args.pRenderingAreaInfo.GetPointer();
    MapStructHandles(args.pRenderingAreaInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkExtent2D* out_pGranularity = args.pGranularity.IsNull() ? nullptr : args.pGranularity.AllocateOutputData(1);

    GetDeviceTable(in_device)->GetRenderingAreaGranularity(in_device, in_pRenderingAreaInfo, out_pGranularity);
}

void VulkanReplayConsumer::Process_vkCmdSetRenderingAttachmentLocations(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingAttachmentLocations&   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRenderingAttachmentLocationInfo* in_pLocationInfo = args.pLocationInfo.GetPointer();
    MapStructHandles(args.pLocationInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetRenderingAttachmentLocations(in_commandBuffer, in_pLocationInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetRenderingAttachmentLocations(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pLocationInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRenderingInputAttachmentIndices(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingInputAttachmentIndices& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRenderingInputAttachmentIndexInfo* in_pInputAttachmentIndexInfo = args.pInputAttachmentIndexInfo.GetPointer();
    MapStructHandles(args.pInputAttachmentIndexInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetRenderingInputAttachmentIndices(in_commandBuffer, in_pInputAttachmentIndexInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetRenderingInputAttachmentIndices(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInputAttachmentIndexInfo);
    }
}

void VulkanReplayConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySurfaceKHR&                    args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);
    auto in_surface = GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }

    OverrideDestroySurfaceKHR(GetInstanceTable(in_instance->handle)->DestroySurfaceKHR, in_instance, in_surface, &args.pAllocator);
    RemoveHandle(args.surface, &CommonObjectInfoTable::RemoveVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceSupportKHR&   args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceSupportKHR for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(args.surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface)->surface_creation_skipped) { return; }
    VkBool32* out_pSupported = args.pSupported.IsNull() ? nullptr : args.pSupported.AllocateOutputData(1, static_cast<VkBool32>(0));

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(in_physicalDevice, args.queueFamilyIndex, in_surface, out_pSupported);
    CheckResult("vkGetPhysicalDeviceSurfaceSupportKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceCapabilitiesKHR& args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceCapabilitiesKHR for offscreen.");
        return;
    }
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    auto in_surface = GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    args.pSurfaceCapabilities.IsNull() ? nullptr : args.pSurfaceCapabilities.AllocateOutputData(1);

    VkResult replay_result = OverrideGetPhysicalDeviceSurfaceCapabilitiesKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceCapabilitiesKHR, args.result, in_physicalDevice, in_surface, &args.pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilitiesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceFormatsKHR&   args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceFormatsKHR for offscreen.");
        return;
    }
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    auto in_surface = GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface);
    if (in_surface == nullptr || in_surface->surface_creation_skipped) { return; }
    args.pSurfaceFormatCount.IsNull() ? nullptr : args.pSurfaceFormatCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanSurfaceKHRInfo>("vkGetPhysicalDeviceSurfaceFormatsKHR", args.result, args.surface, kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR, &args.pSurfaceFormatCount, &args.pSurfaceFormats, &CommonObjectInfoTable::GetVkSurfaceKHRInfo));
    if (!args.pSurfaceFormats.IsNull()) { args.pSurfaceFormats.AllocateOutputData(*args.pSurfaceFormatCount.GetOutputPointer()); }

    VkResult replay_result = OverrideGetPhysicalDeviceSurfaceFormatsKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceFormatsKHR, args.result, in_physicalDevice, in_surface, &args.pSurfaceFormatCount, &args.pSurfaceFormats);
    CheckResult("vkGetPhysicalDeviceSurfaceFormatsKHR", args.result, replay_result, call_info);

    if (args.pSurfaceFormats.IsNull()) { SetOutputArrayCount<VulkanSurfaceKHRInfo>(args.surface, kSurfaceKHRArrayGetPhysicalDeviceSurfaceFormatsKHR, *args.pSurfaceFormatCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkSurfaceKHRInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfacePresentModesKHR& args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfacePresentModesKHR for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(args.surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface)->surface_creation_skipped) { return; }
    uint32_t* out_pPresentModeCount = args.pPresentModeCount.IsNull() ? nullptr : args.pPresentModeCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanSurfaceKHRInfo>("vkGetPhysicalDeviceSurfacePresentModesKHR", args.result, args.surface, kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR, &args.pPresentModeCount, &args.pPresentModes, &CommonObjectInfoTable::GetVkSurfaceKHRInfo));
    VkPresentModeKHR* out_pPresentModes = args.pPresentModes.IsNull() ? nullptr : args.pPresentModes.AllocateOutputData(*out_pPresentModeCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(in_physicalDevice, in_surface, out_pPresentModeCount, out_pPresentModes);
    CheckResult("vkGetPhysicalDeviceSurfacePresentModesKHR", args.result, replay_result, call_info);

    if (args.pPresentModes.IsNull()) { SetOutputArrayCount<VulkanSurfaceKHRInfo>(args.surface, kSurfaceKHRArrayGetPhysicalDeviceSurfacePresentModesKHR, *out_pPresentModeCount, &CommonObjectInfoTable::GetVkSurfaceKHRInfo); }
}

void VulkanReplayConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSwapchainKHR&                   args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSwapchain.IsNull()) { args.pSwapchain.SetHandleLength(1); }
    VulkanSwapchainKHRInfo handle_info;
    args.pSwapchain.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSwapchain.GetPointer());
    VkResult replay_result = OverrideCreateSwapchainKHR(GetDeviceTable(in_device->handle)->CreateSwapchainKHR, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pSwapchain);
    CheckResult("vkCreateSwapchainKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSwapchainKHRInfo>(args.device, args.pSwapchain.GetPointer(), args.pSwapchain.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSwapchainKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySwapchainKHR&                  args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_swapchain = GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain);

    OverrideDestroySwapchainKHR(GetDeviceTable(in_device->handle)->DestroySwapchainKHR, in_device, in_swapchain, &args.pAllocator);
    RemoveHandle(args.swapchain, &CommonObjectInfoTable::RemoveVkSwapchainKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainImagesKHR&                args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_swapchain = GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain);
    args.pSwapchainImageCount.IsNull() ? nullptr : args.pSwapchainImageCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanSwapchainKHRInfo>("vkGetSwapchainImagesKHR", args.result, args.swapchain, kSwapchainKHRArrayGetSwapchainImagesKHR, &args.pSwapchainImageCount, &args.pSwapchainImages, &CommonObjectInfoTable::GetVkSwapchainKHRInfo));
    if (!args.pSwapchainImages.IsNull()) { args.pSwapchainImages.SetHandleLength(*args.pSwapchainImageCount.GetOutputPointer()); }
    std::vector<VulkanImageInfo> handle_info(*args.pSwapchainImageCount.GetOutputPointer());
    for (size_t i = 0; i < *args.pSwapchainImageCount.GetOutputPointer(); ++i) { args.pSwapchainImages.SetConsumerData(i, &handle_info[i]); }

    PushRecaptureHandleIds(args.pSwapchainImages.GetPointer(), args.pSwapchainImages.GetLength());
    VkResult replay_result = OverrideGetSwapchainImagesKHR(GetDeviceTable(in_device->handle)->GetSwapchainImagesKHR, args.result, in_device, in_swapchain, &args.pSwapchainImageCount, &args.pSwapchainImages);
    CheckResult("vkGetSwapchainImagesKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pSwapchainImages.IsNull()) { SetOutputArrayCount<VulkanSwapchainKHRInfo>(args.swapchain, kSwapchainKHRArrayGetSwapchainImagesKHR, *args.pSwapchainImageCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkSwapchainKHRInfo); }
    AddHandles<VulkanImageInfo>(args.device, args.pSwapchainImages.GetPointer(), args.pSwapchainImages.GetLength(), args.pSwapchainImages.GetHandlePointer(), *args.pSwapchainImageCount.GetOutputPointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkImageInfo);
}

void VulkanReplayConsumer::Process_vkAcquireNextImageKHR(
    const ApiCallInfo&                          call_info,
    args::AcquireNextImageKHR&                  args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_swapchain = GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain);
    auto in_semaphore = GetObjectInfoTable().GetVkSemaphoreInfo(args.semaphore);
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(args.fence);
    args.pImageIndex.IsNull() ? nullptr : args.pImageIndex.AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = OverrideAcquireNextImageKHR(GetDeviceTable(in_device->handle)->AcquireNextImageKHR, args.result, in_device, in_swapchain, args.timeout, in_semaphore, in_fence, &args.pImageIndex);
    CheckResult("vkAcquireNextImageKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    args::QueuePresentKHR&                      args)
{
    auto in_queue = GetObjectInfoTable().GetVkQueueInfo(args.queue);

    MapStructHandles(args.pPresentInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideQueuePresentKHR(GetDeviceTable(in_queue->handle)->QueuePresentKHR, args.result, in_queue, &args.pPresentInfo);
    CheckResult("vkQueuePresentKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupPresentCapabilitiesKHR& args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetDeviceGroupPresentCapabilitiesKHR for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeviceGroupPresentCapabilitiesKHR* out_pDeviceGroupPresentCapabilities = args.pDeviceGroupPresentCapabilities.IsNull() ? nullptr : args.pDeviceGroupPresentCapabilities.AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR, nullptr });
    InitializeOutputStructPNext(&args.pDeviceGroupPresentCapabilities);

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupPresentCapabilitiesKHR(in_device, out_pDeviceGroupPresentCapabilities);
    CheckResult("vkGetDeviceGroupPresentCapabilitiesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupSurfacePresentModesKHR& args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetDeviceGroupSurfacePresentModesKHR for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(args.surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface)->surface_creation_skipped) { return; }
    VkDeviceGroupPresentModeFlagsKHR* out_pModes = args.pModes.IsNull() ? nullptr : args.pModes.AllocateOutputData(1, static_cast<VkDeviceGroupPresentModeFlagsKHR>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupSurfacePresentModesKHR(in_device, in_surface, out_pModes);
    CheckResult("vkGetDeviceGroupSurfacePresentModesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDevicePresentRectanglesKHR& args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDevicePresentRectanglesKHR for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(args.surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface)->surface_creation_skipped) { return; }
    uint32_t* out_pRectCount = args.pRectCount.IsNull() ? nullptr : args.pRectCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanSurfaceKHRInfo>("vkGetPhysicalDevicePresentRectanglesKHR", args.result, args.surface, kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR, &args.pRectCount, &args.pRects, &CommonObjectInfoTable::GetVkSurfaceKHRInfo));
    VkRect2D* out_pRects = args.pRects.IsNull() ? nullptr : args.pRects.AllocateOutputData(*out_pRectCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(in_physicalDevice, in_surface, out_pRectCount, out_pRects);
    CheckResult("vkGetPhysicalDevicePresentRectanglesKHR", args.result, replay_result, call_info);

    if (args.pRects.IsNull()) { SetOutputArrayCount<VulkanSurfaceKHRInfo>(args.surface, kSurfaceKHRArrayGetPhysicalDevicePresentRectanglesKHR, *out_pRectCount, &CommonObjectInfoTable::GetVkSurfaceKHRInfo); }
}

void VulkanReplayConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    args::AcquireNextImage2KHR&                 args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pAcquireInfo.GetMetaStructPointer(), GetObjectInfoTable());
    args.pImageIndex.IsNull() ? nullptr : args.pImageIndex.AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = OverrideAcquireNextImage2KHR(GetDeviceTable(in_device->handle)->AcquireNextImage2KHR, args.result, in_device, &args.pAcquireInfo, &args.pImageIndex);
    CheckResult("vkAcquireNextImage2KHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayPropertiesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPropertiesKHR", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkDisplayPropertiesKHR* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount);

    PushRecaptureStructArrayHandleIds(args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), this);
    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPropertiesKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPropertiesKHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayPropertiesKHR>(args.physicalDevice, args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayPlanePropertiesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkDisplayPlanePropertiesKHR* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount);

    PushRecaptureStructArrayHandleIds(args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), this);
    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlanePropertiesKHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayPlanePropertiesKHR>(args.physicalDevice, args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayPlaneSupportedDisplaysKHR&  args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pDisplayCount = args.pDisplayCount.IsNull() ? nullptr : args.pDisplayCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetDisplayPlaneSupportedDisplaysKHR", args.result, args.physicalDevice, kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR, &args.pDisplayCount, &args.pDisplays, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    if (!args.pDisplays.IsNull()) { args.pDisplays.SetHandleLength(*out_pDisplayCount); }
    VkDisplayKHR* out_pDisplays = args.pDisplays.GetHandlePointer();

    PushRecaptureHandleIds(args.pDisplays.GetPointer(), args.pDisplays.GetLength());
    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(in_physicalDevice, args.planeIndex, out_pDisplayCount, out_pDisplays);
    CheckResult("vkGetDisplayPlaneSupportedDisplaysKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pDisplays.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetDisplayPlaneSupportedDisplaysKHR, *out_pDisplayCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    AddHandles<VulkanDisplayKHRInfo>(args.physicalDevice, args.pDisplays.GetPointer(), args.pDisplays.GetLength(), out_pDisplays, *out_pDisplayCount, &CommonObjectInfoTable::AddVkDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayModePropertiesKHR&          args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(args.display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDisplayKHRInfo>("vkGetDisplayModePropertiesKHR", args.result, args.display, kDisplayKHRArrayGetDisplayModePropertiesKHR, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkDisplayKHRInfo));
    VkDisplayModePropertiesKHR* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount);

    PushRecaptureStructArrayHandleIds(args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), this);
    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayModePropertiesKHR(in_physicalDevice, in_display, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetDisplayModePropertiesKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanDisplayKHRInfo>(args.display, kDisplayKHRArrayGetDisplayModePropertiesKHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkDisplayKHRInfo); }
    AddStructArrayHandles<Decoded_VkDisplayModePropertiesKHR>(args.physicalDevice, args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDisplayModeKHR&                 args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(args.display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    const VkDisplayModeCreateInfoKHR* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pMode.IsNull()) { args.pMode.SetHandleLength(1); }
    VkDisplayModeKHR* out_pMode = args.pMode.GetHandlePointer();

    PushRecaptureHandleId(args.pMode.GetPointer());
    VkResult replay_result = GetInstanceTable(in_physicalDevice)->CreateDisplayModeKHR(in_physicalDevice, in_display, in_pCreateInfo, in_pAllocator, out_pMode);
    CheckResult("vkCreateDisplayModeKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDisplayModeKHRInfo>(args.physicalDevice, args.pMode.GetPointer(), out_pMode, &CommonObjectInfoTable::AddVkDisplayModeKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayPlaneCapabilitiesKHR&       args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayModeKHR in_mode = MapHandle<VulkanDisplayModeKHRInfo>(args.mode, &CommonObjectInfoTable::GetVkDisplayModeKHRInfo);
    VkDisplayPlaneCapabilitiesKHR* out_pCapabilities = args.pCapabilities.IsNull() ? nullptr : args.pCapabilities.AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneCapabilitiesKHR(in_physicalDevice, in_mode, args.planeIndex, out_pCapabilities);
    CheckResult("vkGetDisplayPlaneCapabilitiesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDisplayPlaneSurfaceKHR&         args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    args.pSurface.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = OverrideCreateDisplayPlaneSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateDisplayPlaneSurfaceKHR, args.result, in_instance, &args.pCreateInfo, &args.pAllocator, &args.pSurface);
    CheckResult("vkCreateDisplayPlaneSurfaceKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), args.pSurface.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSharedSwapchainsKHR&            args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pCreateInfos.GetMetaStructPointer(), args.pCreateInfos.GetLength(), GetObjectInfoTable());
    if (!args.pSwapchains.IsNull()) { args.pSwapchains.SetHandleLength(args.swapchainCount); }
    std::vector<VulkanSwapchainKHRInfo> handle_info(args.swapchainCount);
    for (size_t i = 0; i < args.swapchainCount; ++i) { args.pSwapchains.SetConsumerData(i, &handle_info[i]); }

    PushRecaptureHandleIds(args.pSwapchains.GetPointer(), args.pSwapchains.GetLength());
    VkResult replay_result = OverrideCreateSharedSwapchainsKHR(GetDeviceTable(in_device->handle)->CreateSharedSwapchainsKHR, args.result, in_device, args.swapchainCount, &args.pCreateInfos, &args.pAllocator, &args.pSwapchains);
    CheckResult("vkCreateSharedSwapchainsKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandles<VulkanSwapchainKHRInfo>(args.device, args.pSwapchains.GetPointer(), args.pSwapchains.GetLength(), args.pSwapchains.GetHandlePointer(), args.swapchainCount, std::move(handle_info), &CommonObjectInfoTable::AddVkSwapchainKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateXlibSurfaceKHR&                 args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    args.pSurface.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = OverrideCreateXlibSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateXlibSurfaceKHR, args.result, in_instance, &args.pCreateInfo, &args.pAllocator, &args.pSurface);
    CheckResult("vkCreateXlibSurfaceKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), args.pSurface.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceXlibPresentationSupportKHR& args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(args.dpy, format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR, "vkGetPhysicalDeviceXlibPresentationSupportKHR"));

    OverrideGetPhysicalDeviceXlibPresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceXlibPresentationSupportKHR, in_physicalDevice, args.queueFamilyIndex, in_dpy, args.visualID);
}

void VulkanReplayConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateXcbSurfaceKHR&                  args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    args.pSurface.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = OverrideCreateXcbSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateXcbSurfaceKHR, args.result, in_instance, &args.pCreateInfo, &args.pAllocator, &args.pSurface);
    CheckResult("vkCreateXcbSurfaceKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), args.pSurface.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceXcbPresentationSupportKHR& args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    xcb_connection_t* in_connection = static_cast<xcb_connection_t*>(PreProcessExternalObject(args.connection, format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR, "vkGetPhysicalDeviceXcbPresentationSupportKHR"));

    OverrideGetPhysicalDeviceXcbPresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceXcbPresentationSupportKHR, in_physicalDevice, args.queueFamilyIndex, in_connection, args.visual_id);
}

void VulkanReplayConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateWaylandSurfaceKHR&              args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    args.pSurface.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = OverrideCreateWaylandSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateWaylandSurfaceKHR, args.result, in_instance, &args.pCreateInfo, &args.pAllocator, &args.pSurface);
    CheckResult("vkCreateWaylandSurfaceKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), args.pSurface.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceWaylandPresentationSupportKHR& args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    struct wl_display* in_display = static_cast<struct wl_display*>(PreProcessExternalObject(args.display, format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR, "vkGetPhysicalDeviceWaylandPresentationSupportKHR"));

    OverrideGetPhysicalDeviceWaylandPresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceWaylandPresentationSupportKHR, in_physicalDevice, args.queueFamilyIndex, in_display);
}

void VulkanReplayConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateAndroidSurfaceKHR&              args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    args.pSurface.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = OverrideCreateAndroidSurfaceKHR(GetInstanceTable(in_instance->handle)->CreateAndroidSurfaceKHR, args.result, in_instance, &args.pCreateInfo, &args.pAllocator, &args.pSurface);
    CheckResult("vkCreateAndroidSurfaceKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), args.pSurface.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateWin32SurfaceKHR&                args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    args.pSurface.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = OverrideCreateWin32SurfaceKHR(GetInstanceTable(in_instance->handle)->CreateWin32SurfaceKHR, args.result, in_instance, &args.pCreateInfo, &args.pAllocator, &args.pSurface);
    CheckResult("vkCreateWin32SurfaceKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), args.pSurface.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceWin32PresentationSupportKHR& args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);

    OverrideGetPhysicalDeviceWin32PresentationSupportKHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceWin32PresentationSupportKHR, in_physicalDevice, args.queueFamilyIndex);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceVideoCapabilitiesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkVideoProfileInfoKHR* in_pVideoProfile = args.pVideoProfile.GetPointer();
    MapStructHandles(args.pVideoProfile.GetMetaStructPointer(), GetObjectInfoTable());
    VkVideoCapabilitiesKHR* out_pCapabilities = args.pCapabilities.IsNull() ? nullptr : args.pCapabilities.AllocateOutputData(1, { VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR, nullptr });
    InitializeOutputStructPNext(&args.pCapabilities);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceVideoCapabilitiesKHR(in_physicalDevice, in_pVideoProfile, out_pCapabilities);
    CheckResult("vkGetPhysicalDeviceVideoCapabilitiesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceVideoFormatPropertiesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceVideoFormatInfoKHR* in_pVideoFormatInfo = args.pVideoFormatInfo.GetPointer();
    MapStructHandles(args.pVideoFormatInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pVideoFormatPropertyCount = args.pVideoFormatPropertyCount.IsNull() ? nullptr : args.pVideoFormatPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceVideoFormatPropertiesKHR", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceVideoFormatPropertiesKHR, &args.pVideoFormatPropertyCount, &args.pVideoFormatProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkVideoFormatPropertiesKHR* out_pVideoFormatProperties = args.pVideoFormatProperties.IsNull() ? nullptr : args.pVideoFormatProperties.AllocateOutputData(*out_pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR{ VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceVideoFormatPropertiesKHR(in_physicalDevice, in_pVideoFormatInfo, out_pVideoFormatPropertyCount, out_pVideoFormatProperties);
    CheckResult("vkGetPhysicalDeviceVideoFormatPropertiesKHR", args.result, replay_result, call_info);

    if (args.pVideoFormatProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceVideoFormatPropertiesKHR, *out_pVideoFormatPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    args::CreateVideoSessionKHR&                args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pVideoSession.IsNull()) { args.pVideoSession.SetHandleLength(1); }
    VulkanVideoSessionKHRInfo handle_info;
    args.pVideoSession.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pVideoSession.GetPointer());
    VkResult replay_result = OverrideCreateVideoSessionKHR(GetDeviceTable(in_device->handle)->CreateVideoSessionKHR, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pVideoSession);
    CheckResult("vkCreateVideoSessionKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanVideoSessionKHRInfo>(args.device, args.pVideoSession.GetPointer(), args.pVideoSession.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkVideoSessionKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyVideoSessionKHR&               args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_videoSession = GetObjectInfoTable().GetVkVideoSessionKHRInfo(args.videoSession);

    OverrideDestroyVideoSessionKHR(GetDeviceTable(in_device->handle)->DestroyVideoSessionKHR, in_device, in_videoSession, &args.pAllocator);
    RemoveHandle(args.videoSession, &CommonObjectInfoTable::RemoveVkVideoSessionKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetVideoSessionMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetVideoSessionMemoryRequirementsKHR& args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_videoSession = GetObjectInfoTable().GetVkVideoSessionKHRInfo(args.videoSession);
    args.pMemoryRequirementsCount.IsNull() ? nullptr : args.pMemoryRequirementsCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanVideoSessionKHRInfo>("vkGetVideoSessionMemoryRequirementsKHR", args.result, args.videoSession, kVideoSessionKHRArrayGetVideoSessionMemoryRequirementsKHR, &args.pMemoryRequirementsCount, &args.pMemoryRequirements, &CommonObjectInfoTable::GetVkVideoSessionKHRInfo));
    if (!args.pMemoryRequirements.IsNull()) { args.pMemoryRequirements.AllocateOutputData(*args.pMemoryRequirementsCount.GetOutputPointer(), VkVideoSessionMemoryRequirementsKHR{ VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR, nullptr }); }

    VkResult replay_result = OverrideGetVideoSessionMemoryRequirementsKHR(GetDeviceTable(in_device->handle)->GetVideoSessionMemoryRequirementsKHR, args.result, in_device, in_videoSession, &args.pMemoryRequirementsCount, &args.pMemoryRequirements);
    CheckResult("vkGetVideoSessionMemoryRequirementsKHR", args.result, replay_result, call_info);

    if (args.pMemoryRequirements.IsNull()) { SetOutputArrayCount<VulkanVideoSessionKHRInfo>(args.videoSession, kVideoSessionKHRArrayGetVideoSessionMemoryRequirementsKHR, *args.pMemoryRequirementsCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkVideoSessionKHRInfo); }
}

void VulkanReplayConsumer::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::BindVideoSessionMemoryKHR&            args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_videoSession = GetObjectInfoTable().GetVkVideoSessionKHRInfo(args.videoSession);

    MapStructArrayHandles(args.pBindSessionMemoryInfos.GetMetaStructPointer(), args.pBindSessionMemoryInfos.GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindVideoSessionMemoryKHR(GetDeviceTable(in_device->handle)->BindVideoSessionMemoryKHR, args.result, in_device, in_videoSession, args.bindSessionMemoryInfoCount, &args.pBindSessionMemoryInfos);
    CheckResult("vkBindVideoSessionMemoryKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::CreateVideoSessionParametersKHR&      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkVideoSessionParametersCreateInfoKHR* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pVideoSessionParameters.IsNull()) { args.pVideoSessionParameters.SetHandleLength(1); }
    VkVideoSessionParametersKHR* out_pVideoSessionParameters = args.pVideoSessionParameters.GetHandlePointer();

    PushRecaptureHandleId(args.pVideoSessionParameters.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateVideoSessionParametersKHR(in_device, in_pCreateInfo, in_pAllocator, out_pVideoSessionParameters);
    CheckResult("vkCreateVideoSessionParametersKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanVideoSessionParametersKHRInfo>(args.device, args.pVideoSessionParameters.GetPointer(), out_pVideoSessionParameters, &CommonObjectInfoTable::AddVkVideoSessionParametersKHRInfo);
}

void VulkanReplayConsumer::Process_vkUpdateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::UpdateVideoSessionParametersKHR&      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkVideoSessionParametersKHR in_videoSessionParameters = MapHandle<VulkanVideoSessionParametersKHRInfo>(args.videoSessionParameters, &CommonObjectInfoTable::GetVkVideoSessionParametersKHRInfo);
    const VkVideoSessionParametersUpdateInfoKHR* in_pUpdateInfo = args.pUpdateInfo.GetPointer();
    MapStructHandles(args.pUpdateInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->UpdateVideoSessionParametersKHR(in_device, in_videoSessionParameters, in_pUpdateInfo);
    CheckResult("vkUpdateVideoSessionParametersKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyVideoSessionParametersKHR&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkVideoSessionParametersKHR in_videoSessionParameters = MapHandle<VulkanVideoSessionParametersKHRInfo>(args.videoSessionParameters, &CommonObjectInfoTable::GetVkVideoSessionParametersKHRInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyVideoSessionParametersKHR(in_device, in_videoSessionParameters, in_pAllocator);
    RemoveHandle(args.videoSessionParameters, &CommonObjectInfoTable::RemoveVkVideoSessionParametersKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginVideoCodingKHR&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVideoBeginCodingInfoKHR* in_pBeginInfo = args.pBeginInfo.GetPointer();
    MapStructHandles(args.pBeginInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginVideoCodingKHR(in_commandBuffer, in_pBeginInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginVideoCodingKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pBeginInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndVideoCodingKHR&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVideoEndCodingInfoKHR* in_pEndCodingInfo = args.pEndCodingInfo.GetPointer();
    MapStructHandles(args.pEndCodingInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdEndVideoCodingKHR(in_commandBuffer, in_pEndCodingInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndVideoCodingKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pEndCodingInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdControlVideoCodingKHR&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVideoCodingControlInfoKHR* in_pCodingControlInfo = args.pCodingControlInfo.GetPointer();
    MapStructHandles(args.pCodingControlInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdControlVideoCodingKHR(in_commandBuffer, in_pCodingControlInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdControlVideoCodingKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pCodingControlInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDecodeVideoKHR&                    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVideoDecodeInfoKHR* in_pDecodeInfo = args.pDecodeInfo.GetPointer();
    MapStructHandles(args.pDecodeInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDecodeVideoKHR(in_commandBuffer, in_pDecodeInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDecodeVideoKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pDecodeInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderingKHR&                 args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pRenderingInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdBeginRendering(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderingKHR, in_commandBuffer, &args.pRenderingInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginRenderingKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pRenderingInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderingKHR&                   args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    OverrideCmdEndRendering(GetDeviceTable(in_commandBuffer->handle)->CmdEndRenderingKHR, in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndRenderingKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFeatures2KHR&        args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkPhysicalDeviceFeatures2* out_pFeatures = args.pFeatures.IsNull() ? nullptr : args.pFeatures.AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2, nullptr });
    InitializeOutputStructPNext(&args.pFeatures);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFeatures2KHR(in_physicalDevice, out_pFeatures);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceProperties2KHR&      args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(&args.pProperties);

    OverrideGetPhysicalDeviceProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceProperties2KHR, in_physicalDevice, &args.pProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFormatProperties2KHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkFormatProperties2* out_pFormatProperties = args.pFormatProperties.IsNull() ? nullptr : args.pFormatProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(&args.pFormatProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(in_physicalDevice, args.format, out_pFormatProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceImageFormatProperties2KHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceImageFormatInfo2* in_pImageFormatInfo = args.pImageFormatInfo.GetPointer();
    MapStructHandles(args.pImageFormatInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkImageFormatProperties2* out_pImageFormatProperties = args.pImageFormatProperties.IsNull() ? nullptr : args.pImageFormatProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(&args.pImageFormatProperties);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(in_physicalDevice, in_pImageFormatInfo, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceImageFormatProperties2KHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyProperties2KHR& args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pQueueFamilyPropertyCount.IsNull() ? nullptr : args.pQueueFamilyPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyProperties2KHR", VK_SUCCESS, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR, &args.pQueueFamilyPropertyCount, &args.pQueueFamilyProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    if (!args.pQueueFamilyProperties.IsNull()) { args.pQueueFamilyProperties.AllocateOutputData(*args.pQueueFamilyPropertyCount.GetOutputPointer(), VkQueueFamilyProperties2{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2, nullptr }); }

    OverrideGetPhysicalDeviceQueueFamilyProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceQueueFamilyProperties2KHR, in_physicalDevice, &args.pQueueFamilyPropertyCount, &args.pQueueFamilyProperties);

    if (args.pQueueFamilyProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyProperties2KHR, *args.pQueueFamilyPropertyCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMemoryProperties2KHR& args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pMemoryProperties.IsNull() ? nullptr : args.pMemoryProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryProperties);

    OverrideGetPhysicalDeviceMemoryProperties2(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceMemoryProperties2KHR, in_physicalDevice, &args.pMemoryProperties);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSparseImageFormatProperties2KHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceSparseImageFormatInfo2* in_pFormatInfo = args.pFormatInfo.GetPointer();
    MapStructHandles(args.pFormatInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSparseImageFormatProperties2KHR", VK_SUCCESS, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkSparseImageFormatProperties2* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount, VkSparseImageFormatProperties2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2, nullptr });

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(in_physicalDevice, in_pFormatInfo, out_pPropertyCount, out_pProperties);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSparseImageFormatProperties2KHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupPeerMemoryFeaturesKHR&  args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPeerMemoryFeatureFlags* out_pPeerMemoryFeatures = args.pPeerMemoryFeatures.IsNull() ? nullptr : args.pPeerMemoryFeatures.AllocateOutputData(1, static_cast<VkPeerMemoryFeatureFlags>(0));

    GetDeviceTable(in_device)->GetDeviceGroupPeerMemoryFeaturesKHR(in_device, args.heapIndex, args.localDeviceIndex, args.remoteDeviceIndex, out_pPeerMemoryFeatures);
}

void VulkanReplayConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetDeviceMaskKHR&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDeviceMaskKHR(in_commandBuffer, args.deviceMask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDeviceMaskKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.deviceMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchBaseKHR&                   args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    OverrideCmdDispatchBase(GetDeviceTable(in_commandBuffer->handle)->CmdDispatchBaseKHR, in_commandBuffer, args.baseGroupX, args.baseGroupY, args.baseGroupZ, args.groupCountX, args.groupCountY, args.groupCountZ);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDispatchBaseKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.baseGroupX, args.baseGroupY, args.baseGroupZ, args.groupCountX, args.groupCountY, args.groupCountZ);
    }
}

void VulkanReplayConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    args::TrimCommandPoolKHR&                   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkCommandPool in_commandPool = MapHandle<VulkanCommandPoolInfo>(args.commandPool, &CommonObjectInfoTable::GetVkCommandPoolInfo);

    GetDeviceTable(in_device)->TrimCommandPoolKHR(in_device, in_commandPool, args.flags);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceGroupsKHR&     args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);
    args.pPhysicalDeviceGroupCount.IsNull() ? nullptr : args.pPhysicalDeviceGroupCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanInstanceInfo>("vkEnumeratePhysicalDeviceGroupsKHR", args.result, args.instance, kInstanceArrayEnumeratePhysicalDeviceGroupsKHR, &args.pPhysicalDeviceGroupCount, &args.pPhysicalDeviceGroupProperties, &CommonObjectInfoTable::GetVkInstanceInfo));
    SetStructArrayHandleLengths<Decoded_VkPhysicalDeviceGroupProperties>(args.pPhysicalDeviceGroupProperties.GetMetaStructPointer(), args.pPhysicalDeviceGroupProperties.GetLength());
    if (!args.pPhysicalDeviceGroupProperties.IsNull()) { args.pPhysicalDeviceGroupProperties.AllocateOutputData(*args.pPhysicalDeviceGroupCount.GetOutputPointer(), VkPhysicalDeviceGroupProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES, nullptr }); }

    PushRecaptureStructArrayHandleIds(args.pPhysicalDeviceGroupProperties.GetMetaStructPointer(), args.pPhysicalDeviceGroupProperties.GetLength(), this);
    VkResult replay_result = OverrideEnumeratePhysicalDeviceGroups(GetInstanceTable(in_instance->handle)->EnumeratePhysicalDeviceGroupsKHR, args.result, in_instance, &args.pPhysicalDeviceGroupCount, &args.pPhysicalDeviceGroupProperties);
    CheckResult("vkEnumeratePhysicalDeviceGroupsKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pPhysicalDeviceGroupProperties.IsNull()) { SetOutputArrayCount<VulkanInstanceInfo>(args.instance, kInstanceArrayEnumeratePhysicalDeviceGroupsKHR, *args.pPhysicalDeviceGroupCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkInstanceInfo); }
    AddStructArrayHandles<Decoded_VkPhysicalDeviceGroupProperties>(args.instance, args.pPhysicalDeviceGroupProperties.GetMetaStructPointer(), args.pPhysicalDeviceGroupProperties.GetLength(), args.pPhysicalDeviceGroupProperties.GetOutputPointer(), *args.pPhysicalDeviceGroupCount.GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalBufferPropertiesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalBufferInfo* in_pExternalBufferInfo = args.pExternalBufferInfo.GetPointer();
    MapStructHandles(args.pExternalBufferInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkExternalBufferProperties* out_pExternalBufferProperties = args.pExternalBufferProperties.IsNull() ? nullptr : args.pExternalBufferProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES, nullptr });
    InitializeOutputStructPNext(&args.pExternalBufferProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(in_physicalDevice, in_pExternalBufferInfo, out_pExternalBufferProperties);
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryWin32HandleKHR&              args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = args.pGetWin32HandleInfo.GetPointer();
    MapStructHandles(args.pGetWin32HandleInfo.GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = args.pHandle.IsNull() ? nullptr : reinterpret_cast<HANDLE*>(args.pHandle.AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetMemoryWin32HandleKHR", args.result, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*args.pHandle.GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR, "vkGetMemoryWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryWin32HandlePropertiesKHR&    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    HANDLE in_handle = static_cast<HANDLE>(PreProcessExternalObject(args.handle, format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR, "vkGetMemoryWin32HandlePropertiesKHR"));
    VkMemoryWin32HandlePropertiesKHR* out_pMemoryWin32HandleProperties = args.pMemoryWin32HandleProperties.IsNull() ? nullptr : args.pMemoryWin32HandleProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR, nullptr });
    InitializeOutputStructPNext(&args.pMemoryWin32HandleProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandlePropertiesKHR(in_device, args.handleType, in_handle, out_pMemoryWin32HandleProperties);
    CheckResult("vkGetMemoryWin32HandlePropertiesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryFdKHR&                       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pGetFdInfo.GetMetaStructPointer(), GetObjectInfoTable());
    args.pFd.IsNull() ? nullptr : args.pFd.AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = OverrideGetMemoryFdKHR(GetDeviceTable(in_device->handle)->GetMemoryFdKHR, args.result, in_device, &args.pGetFdInfo, &args.pFd);
    CheckResult("vkGetMemoryFdKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetMemoryFdPropertiesKHR&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkMemoryFdPropertiesKHR* out_pMemoryFdProperties = args.pMemoryFdProperties.IsNull() ? nullptr : args.pMemoryFdProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR, nullptr });
    InitializeOutputStructPNext(&args.pMemoryFdProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryFdPropertiesKHR(in_device, args.handleType, args.fd, out_pMemoryFdProperties);
    CheckResult("vkGetMemoryFdPropertiesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalSemaphorePropertiesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalSemaphoreInfo* in_pExternalSemaphoreInfo = args.pExternalSemaphoreInfo.GetPointer();
    MapStructHandles(args.pExternalSemaphoreInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkExternalSemaphoreProperties* out_pExternalSemaphoreProperties = args.pExternalSemaphoreProperties.IsNull() ? nullptr : args.pExternalSemaphoreProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES, nullptr });
    InitializeOutputStructPNext(&args.pExternalSemaphoreProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(in_physicalDevice, in_pExternalSemaphoreInfo, out_pExternalSemaphoreProperties);
}

void VulkanReplayConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::ImportSemaphoreWin32HandleKHR&        args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pImportSemaphoreWin32HandleInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideImportSemaphoreWin32HandleKHR(GetDeviceTable(in_device->handle)->ImportSemaphoreWin32HandleKHR, args.result, in_device, &args.pImportSemaphoreWin32HandleInfo);
    CheckResult("vkImportSemaphoreWin32HandleKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreWin32HandleKHR&           args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = args.pGetWin32HandleInfo.GetPointer();
    MapStructHandles(args.pGetWin32HandleInfo.GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = args.pHandle.IsNull() ? nullptr : reinterpret_cast<HANDLE*>(args.pHandle.AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetSemaphoreWin32HandleKHR", args.result, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*args.pHandle.GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR, "vkGetSemaphoreWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    args::ImportSemaphoreFdKHR&                 args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pImportSemaphoreFdInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideImportSemaphoreFdKHR(GetDeviceTable(in_device->handle)->ImportSemaphoreFdKHR, args.result, in_device, &args.pImportSemaphoreFdInfo);
    CheckResult("vkImportSemaphoreFdKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreFdKHR&                    args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pGetFdInfo.GetMetaStructPointer(), GetObjectInfoTable());
    args.pFd.IsNull() ? nullptr : args.pFd.AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = OverrideGetSemaphoreFdKHR(GetDeviceTable(in_device->handle)->GetSemaphoreFdKHR, args.result, in_device, &args.pGetFdInfo, &args.pFd);
    CheckResult("vkGetSemaphoreFdKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSetKHR&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipelineLayout in_layout = MapHandle<VulkanPipelineLayoutInfo>(args.layout, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);
    const VkWriteDescriptorSet* in_pDescriptorWrites = args.pDescriptorWrites.GetPointer();
    MapStructArrayHandles(args.pDescriptorWrites.GetMetaStructPointer(), args.pDescriptorWrites.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSetKHR(in_commandBuffer, args.pipelineBindPoint, in_layout, args.set, args.descriptorWriteCount, in_pDescriptorWrites);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPushDescriptorSetKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.pipelineBindPoint, GetObjectInfoTable().GetVkPipelineLayoutInfo(args.layout), args.set, args.descriptorWriteCount, &args.pDescriptorWrites);
    }
}

void VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorUpdateTemplateKHR&    args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pDescriptorUpdateTemplate.IsNull()) { args.pDescriptorUpdateTemplate.SetHandleLength(1); }
    VulkanDescriptorUpdateTemplateInfo handle_info;
    args.pDescriptorUpdateTemplate.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pDescriptorUpdateTemplate.GetPointer());
    VkResult replay_result = OverrideCreateDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->CreateDescriptorUpdateTemplateKHR, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pDescriptorUpdateTemplate);
    CheckResult("vkCreateDescriptorUpdateTemplateKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDescriptorUpdateTemplateInfo>(args.device, args.pDescriptorUpdateTemplate.GetPointer(), args.pDescriptorUpdateTemplate.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorUpdateTemplateKHR&   args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_descriptorUpdateTemplate = GetObjectInfoTable().GetVkDescriptorUpdateTemplateInfo(args.descriptorUpdateTemplate);

    OverrideDestroyDescriptorUpdateTemplate(GetDeviceTable(in_device->handle)->DestroyDescriptorUpdateTemplateKHR, in_device, in_descriptorUpdateTemplate, &args.pAllocator);
    RemoveHandle(args.descriptorUpdateTemplate, &CommonObjectInfoTable::RemoveVkDescriptorUpdateTemplateInfo);
}

void VulkanReplayConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass2KHR&                 args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pRenderPass.IsNull()) { args.pRenderPass.SetHandleLength(1); }
    VulkanRenderPassInfo handle_info;
    args.pRenderPass.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pRenderPass.GetPointer());
    VkResult replay_result = OverrideCreateRenderPass2(GetDeviceTable(in_device->handle)->CreateRenderPass2KHR, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pRenderPass);
    CheckResult("vkCreateRenderPass2KHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanRenderPassInfo>(args.device, args.pRenderPass.GetPointer(), args.pRenderPass.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkRenderPassInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2KHR&               args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pRenderPassBegin.GetMetaStructPointer(), GetObjectInfoTable());

    MapStructHandles(args.pSubpassBeginInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdBeginRenderPass2(GetDeviceTable(in_commandBuffer->handle)->CmdBeginRenderPass2KHR, in_commandBuffer, &args.pRenderPassBegin, &args.pSubpassBeginInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginRenderPass2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pRenderPassBegin, &args.pSubpassBeginInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass2KHR&                   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSubpassBeginInfo* in_pSubpassBeginInfo = args.pSubpassBeginInfo.GetPointer();
    MapStructHandles(args.pSubpassBeginInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkSubpassEndInfo* in_pSubpassEndInfo = args.pSubpassEndInfo.GetPointer();
    MapStructHandles(args.pSubpassEndInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdNextSubpass2KHR(in_commandBuffer, in_pSubpassBeginInfo, in_pSubpassEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdNextSubpass2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pSubpassBeginInfo, &args.pSubpassEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass2KHR&                 args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pSubpassEndInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdEndRenderPass2(GetDeviceTable(in_commandBuffer->handle)->CmdEndRenderPass2KHR, in_commandBuffer, &args.pSubpassEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndRenderPass2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pSubpassEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainStatusKHR&                args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetSwapchainStatusKHR for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainStatusKHR(in_device, in_swapchain);
    CheckResult("vkGetSwapchainStatusKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalFencePropertiesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalFenceInfo* in_pExternalFenceInfo = args.pExternalFenceInfo.GetPointer();
    MapStructHandles(args.pExternalFenceInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkExternalFenceProperties* out_pExternalFenceProperties = args.pExternalFenceProperties.IsNull() ? nullptr : args.pExternalFenceProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES, nullptr });
    InitializeOutputStructPNext(&args.pExternalFenceProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(in_physicalDevice, in_pExternalFenceInfo, out_pExternalFenceProperties);
}

void VulkanReplayConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::ImportFenceWin32HandleKHR&            args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImportFenceWin32HandleInfoKHR* in_pImportFenceWin32HandleInfo = args.pImportFenceWin32HandleInfo.GetPointer();
    MapStructHandles(args.pImportFenceWin32HandleInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ImportFenceWin32HandleKHR(in_device, in_pImportFenceWin32HandleInfo);
    CheckResult("vkImportFenceWin32HandleKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    args::GetFenceWin32HandleKHR&               args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkFenceGetWin32HandleInfoKHR* in_pGetWin32HandleInfo = args.pGetWin32HandleInfo.GetPointer();
    MapStructHandles(args.pGetWin32HandleInfo.GetMetaStructPointer(), GetObjectInfoTable());
    HANDLE* out_pHandle = args.pHandle.IsNull() ? nullptr : reinterpret_cast<HANDLE*>(args.pHandle.AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetFenceWin32HandleKHR(in_device, in_pGetWin32HandleInfo, out_pHandle);
    CheckResult("vkGetFenceWin32HandleKHR", args.result, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*args.pHandle.GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR, "vkGetFenceWin32HandleKHR");
}

void VulkanReplayConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    args::ImportFenceFdKHR&                     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImportFenceFdInfoKHR* in_pImportFenceFdInfo = args.pImportFenceFdInfo.GetPointer();
    MapStructHandles(args.pImportFenceFdInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ImportFenceFdKHR(in_device, in_pImportFenceFdInfo);
    CheckResult("vkImportFenceFdKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    args::GetFenceFdKHR&                        args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkFenceGetFdInfoKHR* in_pGetFdInfo = args.pGetFdInfo.GetPointer();
    MapStructHandles(args.pGetFdInfo.GetMetaStructPointer(), GetObjectInfoTable());
    int* out_pFd = args.pFd.IsNull() ? nullptr : args.pFd.AllocateOutputData(1, static_cast<int>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetFenceFdKHR(in_device, in_pGetFdInfo, out_pFd);
    CheckResult("vkGetFenceFdKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pCounterCount = args.pCounterCount.IsNull() ? nullptr : args.pCounterCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", args.result, args.physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, &args.pCounterCount, &args.pCounterDescriptions, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkPerformanceCounterKHR* out_pCounters = args.pCounters.IsNull() ? nullptr : args.pCounters.AllocateOutputData(*out_pCounterCount, VkPerformanceCounterKHR{ VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR, nullptr });
    VkPerformanceCounterDescriptionKHR* out_pCounterDescriptions = args.pCounterDescriptions.IsNull() ? nullptr : args.pCounterDescriptions.AllocateOutputData(*out_pCounterCount, VkPerformanceCounterDescriptionKHR{ VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(in_physicalDevice, args.queueFamilyIndex, out_pCounterCount, out_pCounters, out_pCounterDescriptions);
    CheckResult("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", args.result, replay_result, call_info);

    if (args.pCounters.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, *out_pCounterCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    if (args.pCounterDescriptions.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, *out_pCounterCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkQueryPoolPerformanceCreateInfoKHR* in_pPerformanceQueryCreateInfo = args.pPerformanceQueryCreateInfo.GetPointer();
    MapStructHandles(args.pPerformanceQueryCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pNumPasses = args.pNumPasses.IsNull() ? nullptr : args.pNumPasses.AllocateOutputData(1, static_cast<uint32_t>(0));

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(in_physicalDevice, in_pPerformanceQueryCreateInfo, out_pNumPasses);
}

void VulkanReplayConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    args::AcquireProfilingLockKHR&              args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideAcquireProfilingLockKHR(GetDeviceTable(in_device->handle)->AcquireProfilingLockKHR, args.result, in_device, &args.pInfo);
    CheckResult("vkAcquireProfilingLockKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseProfilingLockKHR&              args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);

    GetDeviceTable(in_device)->ReleaseProfilingLockKHR(in_device);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceCapabilities2KHR& args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceCapabilities2KHR for offscreen.");
        return;
    }
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);

    MapStructHandles(args.pSurfaceInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (args.pSurfaceInfo.GetPointer()->surface == VK_NULL_HANDLE) { return; }
    auto in_pSurfaceInfo_meta = args.pSurfaceInfo.GetMetaStructPointer();
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    args.pSurfaceCapabilities.IsNull() ? nullptr : args.pSurfaceCapabilities.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR, nullptr });
    InitializeOutputStructPNext(&args.pSurfaceCapabilities);

    VkResult replay_result = OverrideGetPhysicalDeviceSurfaceCapabilities2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceCapabilities2KHR, args.result, in_physicalDevice, &args.pSurfaceInfo, &args.pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilities2KHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceFormats2KHR&  args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceFormats2KHR for offscreen.");
        return;
    }
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);

    MapStructHandles(args.pSurfaceInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (args.pSurfaceInfo.GetPointer()->surface == VK_NULL_HANDLE) { return; }
    auto in_pSurfaceInfo_meta = args.pSurfaceInfo.GetMetaStructPointer();
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    args.pSurfaceFormatCount.IsNull() ? nullptr : args.pSurfaceFormatCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSurfaceFormats2KHR", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR, &args.pSurfaceFormatCount, &args.pSurfaceFormats, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    if (!args.pSurfaceFormats.IsNull()) { args.pSurfaceFormats.AllocateOutputData(*args.pSurfaceFormatCount.GetOutputPointer(), VkSurfaceFormat2KHR{ VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR, nullptr }); }

    VkResult replay_result = OverrideGetPhysicalDeviceSurfaceFormats2KHR(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceSurfaceFormats2KHR, args.result, in_physicalDevice, &args.pSurfaceInfo, &args.pSurfaceFormatCount, &args.pSurfaceFormats);
    CheckResult("vkGetPhysicalDeviceSurfaceFormats2KHR", args.result, replay_result, call_info);

    if (args.pSurfaceFormats.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfaceFormats2KHR, *args.pSurfaceFormatCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayProperties2KHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayProperties2KHR", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkDisplayProperties2KHR* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount, VkDisplayProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR, nullptr });

    PushRecaptureStructArrayHandleIds(args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), this);
    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayProperties2KHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayProperties2KHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayProperties2KHR>(args.physicalDevice, args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDisplayPlaneProperties2KHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkDisplayPlaneProperties2KHR* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount, VkDisplayPlaneProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR, nullptr });

    PushRecaptureStructArrayHandleIds(args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), this);
    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceDisplayPlaneProperties2KHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    AddStructArrayHandles<Decoded_VkDisplayPlaneProperties2KHR>(args.physicalDevice, args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetDisplayModeProperties2KHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayModeProperties2KHR&         args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(args.display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDisplayKHRInfo>("vkGetDisplayModeProperties2KHR", args.result, args.display, kDisplayKHRArrayGetDisplayModeProperties2KHR, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkDisplayKHRInfo));
    VkDisplayModeProperties2KHR* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount, VkDisplayModeProperties2KHR{ VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR, nullptr });

    PushRecaptureStructArrayHandleIds(args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), this);
    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayModeProperties2KHR(in_physicalDevice, in_display, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetDisplayModeProperties2KHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanDisplayKHRInfo>(args.display, kDisplayKHRArrayGetDisplayModeProperties2KHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkDisplayKHRInfo); }
    AddStructArrayHandles<Decoded_VkDisplayModeProperties2KHR>(args.physicalDevice, args.pProperties.GetMetaStructPointer(), args.pProperties.GetLength(), out_pProperties, *out_pPropertyCount, &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    args::GetDisplayPlaneCapabilities2KHR&      args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkDisplayPlaneInfo2KHR* in_pDisplayPlaneInfo = args.pDisplayPlaneInfo.GetPointer();
    MapStructHandles(args.pDisplayPlaneInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkDisplayPlaneCapabilities2KHR* out_pCapabilities = args.pCapabilities.IsNull() ? nullptr : args.pCapabilities.AllocateOutputData(1, { VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR, nullptr });
    InitializeOutputStructPNext(&args.pCapabilities);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDisplayPlaneCapabilities2KHR(in_physicalDevice, in_pDisplayPlaneInfo, out_pCapabilities);
    CheckResult("vkGetDisplayPlaneCapabilities2KHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    args::GetImageMemoryRequirements2KHR&       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    OverrideGetImageMemoryRequirements2(GetDeviceTable(in_device->handle)->GetImageMemoryRequirements2KHR, in_device, &args.pInfo, &args.pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    args::GetBufferMemoryRequirements2KHR&      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    OverrideGetBufferMemoryRequirements2(GetDeviceTable(in_device->handle)->GetBufferMemoryRequirements2KHR, in_device, &args.pInfo, &args.pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    args::GetImageSparseMemoryRequirements2KHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImageSparseMemoryRequirementsInfo2* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = args.pSparseMemoryRequirementCount.IsNull() ? nullptr : args.pSparseMemoryRequirementCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetImageSparseMemoryRequirements2KHR", VK_SUCCESS, args.device, kDeviceArrayGetImageSparseMemoryRequirements2KHR, &args.pSparseMemoryRequirementCount, &args.pSparseMemoryRequirements, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = args.pSparseMemoryRequirements.IsNull() ? nullptr : args.pSparseMemoryRequirements.AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetImageSparseMemoryRequirements2KHR(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (args.pSparseMemoryRequirements.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetImageSparseMemoryRequirements2KHR, *out_pSparseMemoryRequirementCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSamplerYcbcrConversionKHR&      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pYcbcrConversion.IsNull()) { args.pYcbcrConversion.SetHandleLength(1); }
    VulkanSamplerYcbcrConversionInfo handle_info;
    args.pYcbcrConversion.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pYcbcrConversion.GetPointer());
    VkResult replay_result = OverrideCreateSamplerYcbcrConversionKHR(GetDeviceTable(in_device->handle)->CreateSamplerYcbcrConversionKHR, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pYcbcrConversion);
    CheckResult("vkCreateSamplerYcbcrConversionKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSamplerYcbcrConversionInfo>(args.device, args.pYcbcrConversion.GetPointer(), args.pYcbcrConversion.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySamplerYcbcrConversionKHR&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSamplerYcbcrConversion in_ycbcrConversion = MapHandle<VulkanSamplerYcbcrConversionInfo>(args.ycbcrConversion, &CommonObjectInfoTable::GetVkSamplerYcbcrConversionInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroySamplerYcbcrConversionKHR(in_device, in_ycbcrConversion, in_pAllocator);
    RemoveHandle(args.ycbcrConversion, &CommonObjectInfoTable::RemoveVkSamplerYcbcrConversionInfo);
}

void VulkanReplayConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory2KHR&                 args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pBindInfos.GetMetaStructPointer(), args.pBindInfos.GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindBufferMemory2(GetDeviceTable(in_device->handle)->BindBufferMemory2KHR, args.result, in_device, args.bindInfoCount, &args.pBindInfos);
    CheckResult("vkBindBufferMemory2KHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory2KHR&                  args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pBindInfos.GetMetaStructPointer(), args.pBindInfos.GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindImageMemory2(GetDeviceTable(in_device->handle)->BindImageMemory2KHR, args.result, in_device, args.bindInfoCount, &args.pBindInfos);
    CheckResult("vkBindImageMemory2KHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutSupportKHR&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDescriptorSetLayoutCreateInfo* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkDescriptorSetLayoutSupport* out_pSupport = args.pSupport.IsNull() ? nullptr : args.pSupport.AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT, nullptr });
    InitializeOutputStructPNext(&args.pSupport);

    GetDeviceTable(in_device)->GetDescriptorSetLayoutSupportKHR(in_device, in_pCreateInfo, out_pSupport);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountKHR&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(args.countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCountKHR(in_commandBuffer, in_buffer, args.offset, in_countBuffer, args.countBufferOffset, args.maxDrawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndirectCountKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.buffer), args.offset, GetObjectInfoTable().GetVkBufferInfo(args.countBuffer), args.countBufferOffset, args.maxDrawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountKHR&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(args.countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCountKHR(in_commandBuffer, in_buffer, args.offset, in_countBuffer, args.countBufferOffset, args.maxDrawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndexedIndirectCountKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.buffer), args.offset, GetObjectInfoTable().GetVkBufferInfo(args.countBuffer), args.countBufferOffset, args.maxDrawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkGetSemaphoreCounterValueKHR(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreCounterValueKHR&          args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSemaphore in_semaphore = MapHandle<VulkanSemaphoreInfo>(args.semaphore, &CommonObjectInfoTable::GetVkSemaphoreInfo);
    uint64_t* out_pValue = args.pValue.IsNull() ? nullptr : args.pValue.AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreCounterValueKHR(in_device, in_semaphore, out_pValue);
    CheckResult("vkGetSemaphoreCounterValueKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    args::WaitSemaphoresKHR&                    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreWaitInfo* in_pWaitInfo = args.pWaitInfo.GetPointer();
    MapStructHandles(args.pWaitInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->WaitSemaphoresKHR(in_device, in_pWaitInfo, args.timeout);
    CheckResult("vkWaitSemaphoresKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    args::SignalSemaphoreKHR&                   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreSignalInfo* in_pSignalInfo = args.pSignalInfo.GetPointer();
    MapStructHandles(args.pSignalInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->SignalSemaphoreKHR(in_device, in_pSignalInfo);
    CheckResult("vkSignalSemaphoreKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceFragmentShadingRatesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pFragmentShadingRateCount = args.pFragmentShadingRateCount.IsNull() ? nullptr : args.pFragmentShadingRateCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceFragmentShadingRatesKHR", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR, &args.pFragmentShadingRateCount, &args.pFragmentShadingRates, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkPhysicalDeviceFragmentShadingRateKHR* out_pFragmentShadingRates = args.pFragmentShadingRates.IsNull() ? nullptr : args.pFragmentShadingRates.AllocateOutputData(*out_pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceFragmentShadingRatesKHR(in_physicalDevice, out_pFragmentShadingRateCount, out_pFragmentShadingRates);
    CheckResult("vkGetPhysicalDeviceFragmentShadingRatesKHR", args.result, replay_result, call_info);

    if (args.pFragmentShadingRates.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceFragmentShadingRatesKHR, *out_pFragmentShadingRateCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetFragmentShadingRateKHR&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkExtent2D* in_pFragmentSize = args.pFragmentSize.GetPointer();
    const VkFragmentShadingRateCombinerOpKHR* in_combinerOps = args.combinerOps.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetFragmentShadingRateKHR(in_commandBuffer, in_pFragmentSize, in_combinerOps);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetFragmentShadingRateKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pFragmentSize, in_combinerOps);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingAttachmentLocationsKHR& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRenderingAttachmentLocationInfo* in_pLocationInfo = args.pLocationInfo.GetPointer();
    MapStructHandles(args.pLocationInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetRenderingAttachmentLocationsKHR(in_commandBuffer, in_pLocationInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetRenderingAttachmentLocationsKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pLocationInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingInputAttachmentIndicesKHR& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRenderingInputAttachmentIndexInfo* in_pInputAttachmentIndexInfo = args.pInputAttachmentIndexInfo.GetPointer();
    MapStructHandles(args.pInputAttachmentIndexInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetRenderingInputAttachmentIndicesKHR(in_commandBuffer, in_pInputAttachmentIndexInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetRenderingInputAttachmentIndicesKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInputAttachmentIndexInfo);
    }
}

void VulkanReplayConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
    args::WaitForPresentKHR&                    args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkWaitForPresentKHR for offscreen.");
        return;
    }
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_swapchain = GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain);

    VkResult replay_result = OverrideWaitForPresentKHR(GetDeviceTable(in_device->handle)->WaitForPresentKHR, args.result, in_device, in_swapchain, args.presentId, args.timeout);
    CheckResult("vkWaitForPresentKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetBufferDeviceAddressKHR&            args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetBufferDeviceAddress(GetDeviceTable(in_device->handle)->GetBufferDeviceAddressKHR, args.result, in_device, &args.pInfo);
}

void VulkanReplayConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetBufferOpaqueCaptureAddressKHR&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkBufferDeviceAddressInfo* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetBufferOpaqueCaptureAddressKHR(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMemoryOpaqueCaptureAddressKHR& args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetDeviceMemoryOpaqueCaptureAddress(GetDeviceTable(in_device->handle)->GetDeviceMemoryOpaqueCaptureAddressKHR, in_device, &args.pInfo);
}

void VulkanReplayConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDeferredOperationKHR&           args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pDeferredOperation.IsNull()) { args.pDeferredOperation.SetHandleLength(1); }
    VkDeferredOperationKHR* out_pDeferredOperation = args.pDeferredOperation.GetHandlePointer();

    PushRecaptureHandleId(args.pDeferredOperation.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateDeferredOperationKHR(in_device, in_pAllocator, out_pDeferredOperation);
    CheckResult("vkCreateDeferredOperationKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDeferredOperationKHRInfo>(args.device, args.pDeferredOperation.GetPointer(), out_pDeferredOperation, &CommonObjectInfoTable::AddVkDeferredOperationKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyDeferredOperationKHR&          args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_operation = MapHandle<VulkanDeferredOperationKHRInfo>(args.operation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyDeferredOperationKHR(in_device, in_operation, in_pAllocator);
    RemoveHandle(args.operation, &CommonObjectInfoTable::RemoveVkDeferredOperationKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeferredOperationMaxConcurrencyKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_operation = MapHandle<VulkanDeferredOperationKHRInfo>(args.operation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);

    GetDeviceTable(in_device)->GetDeferredOperationMaxConcurrencyKHR(in_device, in_operation);
}

void VulkanReplayConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeferredOperationResultKHR&        args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_operation = MapHandle<VulkanDeferredOperationKHRInfo>(args.operation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);

    VkResult replay_result = GetDeviceTable(in_device)->GetDeferredOperationResultKHR(in_device, in_operation);
    CheckResult("vkGetDeferredOperationResultKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    args::DeferredOperationJoinKHR&             args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_operation = GetObjectInfoTable().GetVkDeferredOperationKHRInfo(args.operation);

    VkResult replay_result = OverrideDeferredOperationJoinKHR(GetDeviceTable(in_device->handle)->DeferredOperationJoinKHR, args.result, in_device, in_operation);
    CheckResult("vkDeferredOperationJoinKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineExecutablePropertiesKHR&   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineInfoKHR* in_pPipelineInfo = args.pPipelineInfo.GetPointer();
    MapStructHandles(args.pPipelineInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pExecutableCount = args.pExecutableCount.IsNull() ? nullptr : args.pExecutableCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetPipelineExecutablePropertiesKHR", args.result, args.device, kDeviceArrayGetPipelineExecutablePropertiesKHR, &args.pExecutableCount, &args.pProperties, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkPipelineExecutablePropertiesKHR* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pExecutableCount, VkPipelineExecutablePropertiesKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutablePropertiesKHR(in_device, in_pPipelineInfo, out_pExecutableCount, out_pProperties);
    CheckResult("vkGetPipelineExecutablePropertiesKHR", args.result, replay_result, call_info);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetPipelineExecutablePropertiesKHR, *out_pExecutableCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineExecutableStatisticsKHR&   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineExecutableInfoKHR* in_pExecutableInfo = args.pExecutableInfo.GetPointer();
    MapStructHandles(args.pExecutableInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pStatisticCount = args.pStatisticCount.IsNull() ? nullptr : args.pStatisticCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetPipelineExecutableStatisticsKHR", args.result, args.device, kDeviceArrayGetPipelineExecutableStatisticsKHR, &args.pStatisticCount, &args.pStatistics, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkPipelineExecutableStatisticKHR* out_pStatistics = args.pStatistics.IsNull() ? nullptr : args.pStatistics.AllocateOutputData(*out_pStatisticCount, VkPipelineExecutableStatisticKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutableStatisticsKHR(in_device, in_pExecutableInfo, out_pStatisticCount, out_pStatistics);
    CheckResult("vkGetPipelineExecutableStatisticsKHR", args.result, replay_result, call_info);

    if (args.pStatistics.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetPipelineExecutableStatisticsKHR, *out_pStatisticCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineExecutableInternalRepresentationsKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineExecutableInfoKHR* in_pExecutableInfo = args.pExecutableInfo.GetPointer();
    MapStructHandles(args.pExecutableInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pInternalRepresentationCount = args.pInternalRepresentationCount.IsNull() ? nullptr : args.pInternalRepresentationCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetPipelineExecutableInternalRepresentationsKHR", args.result, args.device, kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR, &args.pInternalRepresentationCount, &args.pInternalRepresentations, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkPipelineExecutableInternalRepresentationKHR* out_pInternalRepresentations = args.pInternalRepresentations.IsNull() ? nullptr : args.pInternalRepresentations.AllocateOutputData(*out_pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR{ VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineExecutableInternalRepresentationsKHR(in_device, in_pExecutableInfo, out_pInternalRepresentationCount, out_pInternalRepresentations);
    CheckResult("vkGetPipelineExecutableInternalRepresentationsKHR", args.result, replay_result, call_info);

    if (args.pInternalRepresentations.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetPipelineExecutableInternalRepresentationsKHR, *out_pInternalRepresentationCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkMapMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::MapMemory2KHR&                        args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pMemoryMapInfo.GetMetaStructPointer(), GetObjectInfoTable());
    void** out_ppData = args.ppData.IsNull() ? nullptr : args.ppData.AllocateOutputData(1);

    VkResult replay_result = OverrideMapMemory2(GetDeviceTable(in_device->handle)->MapMemory2KHR, args.result, in_device, &args.pMemoryMapInfo, out_ppData);
    CheckResult("vkMapMemory2KHR", args.result, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*args.ppData.GetPointer()), *args.ppData.GetOutputPointer(), format::ApiCallId::ApiCall_vkMapMemory2KHR, "vkMapMemory2KHR");
}

void VulkanReplayConsumer::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory2KHR&                      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pMemoryUnmapInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = OverrideUnmapMemory2(GetDeviceTable(in_device->handle)->UnmapMemory2KHR, args.result, in_device, &args.pMemoryUnmapInfo);
    CheckResult("vkUnmapMemory2KHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* in_pQualityLevelInfo = args.pQualityLevelInfo.GetPointer();
    MapStructHandles(args.pQualityLevelInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkVideoEncodeQualityLevelPropertiesKHR* out_pQualityLevelProperties = args.pQualityLevelProperties.IsNull() ? nullptr : args.pQualityLevelProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR, nullptr });
    InitializeOutputStructPNext(&args.pQualityLevelProperties);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(in_physicalDevice, in_pQualityLevelInfo, out_pQualityLevelProperties);
    CheckResult("vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetEncodedVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::GetEncodedVideoSessionParametersKHR&  args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkVideoEncodeSessionParametersGetInfoKHR* in_pVideoSessionParametersInfo = args.pVideoSessionParametersInfo.GetPointer();
    MapStructHandles(args.pVideoSessionParametersInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkVideoEncodeSessionParametersFeedbackInfoKHR* out_pFeedbackInfo = args.pFeedbackInfo.IsNull() ? nullptr : args.pFeedbackInfo.AllocateOutputData(1, { VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR, nullptr });
    InitializeOutputStructPNext(&args.pFeedbackInfo);
    size_t* out_pDataSize = args.pDataSize.IsNull() ? nullptr : args.pDataSize.AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanDeviceInfo>("vkGetEncodedVideoSessionParametersKHR", args.result, args.device, kDeviceArrayGetEncodedVideoSessionParametersKHR, &args.pDataSize, &args.pData, &CommonObjectInfoTable::GetVkDeviceInfo));
    void* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(*out_pDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetEncodedVideoSessionParametersKHR(in_device, in_pVideoSessionParametersInfo, out_pFeedbackInfo, out_pDataSize, out_pData);
    CheckResult("vkGetEncodedVideoSessionParametersKHR", args.result, replay_result, call_info);

    if (args.pData.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetEncodedVideoSessionParametersKHR, *out_pDataSize, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEncodeVideoKHR&                    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVideoEncodeInfoKHR* in_pEncodeInfo = args.pEncodeInfo.GetPointer();
    MapStructHandles(args.pEncodeInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdEncodeVideoKHR(in_commandBuffer, in_pEncodeInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEncodeVideoKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pEncodeInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2KHR&                      args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_event = GetObjectInfoTable().GetVkEventInfo(args.event);

    MapStructHandles(args.pDependencyInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdSetEvent2(GetDeviceTable(in_commandBuffer->handle)->CmdSetEvent2KHR, in_commandBuffer, in_event, &args.pDependencyInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetEvent2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_event->handle, args.pDependencyInfo.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent2KHR&                    args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_event = GetObjectInfoTable().GetVkEventInfo(args.event);

    OverrideCmdResetEvent2(GetDeviceTable(in_commandBuffer->handle)->CmdResetEvent2KHR, in_commandBuffer, in_event, args.stageMask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdResetEvent2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_event->handle, args.stageMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2KHR&                    args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    MapHandles<VulkanEventInfo>(&args.pEvents, args.eventCount, &CommonObjectInfoTable::GetVkEventInfo);

    MapStructArrayHandles(args.pDependencyInfos.GetMetaStructPointer(), args.pDependencyInfos.GetLength(), GetObjectInfoTable());

    OverrideCmdWaitEvents2(GetDeviceTable(in_commandBuffer->handle)->CmdWaitEvents2KHR, in_commandBuffer, args.eventCount, &args.pEvents, &args.pDependencyInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWaitEvents2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.eventCount, args.pEvents.GetHandlePointer(), args.pDependencyInfos.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2KHR&               args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pDependencyInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdPipelineBarrier2KHR(GetDeviceTable(in_commandBuffer->handle)->CmdPipelineBarrier2KHR, in_commandBuffer, &args.pDependencyInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPipelineBarrier2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.pDependencyInfo.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp2KHR&                args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool);

    OverrideCmdWriteTimestamp2(GetDeviceTable(in_commandBuffer->handle)->CmdWriteTimestamp2KHR, in_commandBuffer, args.stage, in_queryPool, args.query);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWriteTimestamp2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.stage, in_queryPool, args.query);
    }
}

void VulkanReplayConsumer::Process_vkQueueSubmit2KHR(
    const ApiCallInfo&                          call_info,
    args::QueueSubmit2KHR&                      args)
{
    auto in_queue = GetObjectInfoTable().GetVkQueueInfo(args.queue);

    MapStructArrayHandles(args.pSubmits.GetMetaStructPointer(), args.pSubmits.GetLength(), GetObjectInfoTable());
    auto in_fence = GetObjectInfoTable().GetVkFenceInfo(args.fence);

    VkResult replay_result = OverrideQueueSubmit2(GetDeviceTable(in_queue->handle)->QueueSubmit2KHR, call_info.index, args.result, in_queue, args.submitCount, &args.pSubmits, in_fence);
    CheckResult("vkQueueSubmit2KHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdBindIndexBuffer3KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer3KHR&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBindIndexBuffer3InfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBindIndexBuffer3KHR(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindIndexBuffer3KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers3KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers3KHR&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBindVertexBuffer3InfoKHR* in_pBindingInfos = args.pBindingInfos.GetPointer();
    MapStructArrayHandles(args.pBindingInfos.GetMetaStructPointer(), args.pBindingInfos.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers3KHR(in_commandBuffer, args.firstBinding, args.bindingCount, in_pBindingInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindVertexBuffers3KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstBinding, args.bindingCount, in_pBindingInfos);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect2KHR&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDrawIndirect2InfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirect2KHR(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndirect2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect2KHR&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDrawIndirect2InfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirect2KHR(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndexedIndirect2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdDispatchIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect2KHR&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDispatchIndirect2InfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDispatchIndirect2KHR(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDispatchIndirect2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryKHR&                     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyDeviceMemoryInfoKHR* in_pCopyMemoryInfo = args.pCopyMemoryInfo.GetPointer();
    MapStructHandles(args.pCopyMemoryInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMemoryKHR(in_commandBuffer, in_pCopyMemoryInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyMemoryKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pCopyMemoryInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyMemoryToImageKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageKHR&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyDeviceMemoryImageInfoKHR* in_pCopyMemoryInfo = args.pCopyMemoryInfo.GetPointer();
    MapStructHandles(args.pCopyMemoryInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMemoryToImageKHR(in_commandBuffer, in_pCopyMemoryInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyMemoryToImageKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pCopyMemoryInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToMemoryKHR&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyDeviceMemoryImageInfoKHR* in_pCopyMemoryInfo = args.pCopyMemoryInfo.GetPointer();
    MapStructHandles(args.pCopyMemoryInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToMemoryKHR(in_commandBuffer, in_pCopyMemoryInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyImageToMemoryKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pCopyMemoryInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdUpdateMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateMemoryKHR&                   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDeviceAddressRangeKHR* in_pDstRange = args.pDstRange.GetPointer();
    const void* in_pData = args.pData.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdUpdateMemoryKHR(in_commandBuffer, in_pDstRange, args.dstFlags, args.dataSize, in_pData);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdUpdateMemoryKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pDstRange, args.dstFlags, args.dataSize, in_pData);
    }
}

void VulkanReplayConsumer::Process_vkCmdFillMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdFillMemoryKHR&                     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDeviceAddressRangeKHR* in_pDstRange = args.pDstRange.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdFillMemoryKHR(in_commandBuffer, in_pDstRange, args.dstFlags, args.data);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdFillMemoryKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pDstRange, args.dstFlags, args.data);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResultsToMemoryKHR&   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(args.queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);
    const VkStridedDeviceAddressRangeKHR* in_pDstRange = args.pDstRange.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdCopyQueryPoolResultsToMemoryKHR(in_commandBuffer, in_queryPool, args.firstQuery, args.queryCount, in_pDstRange, args.dstFlags, args.queryResultFlags);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyQueryPoolResultsToMemoryKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool), args.firstQuery, args.queryCount, &args.pDstRange, args.dstFlags, args.queryResultFlags);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount2KHR&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDrawIndirectCount2InfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCount2KHR(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndirectCount2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount2KHR&      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDrawIndirectCount2InfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCount2KHR(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndexedIndirectCount2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginConditionalRendering2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRendering2EXT&     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkConditionalRenderingBeginInfo2EXT* in_pConditionalRenderingBegin = args.pConditionalRenderingBegin.GetPointer();
    MapStructHandles(args.pConditionalRenderingBegin.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginConditionalRendering2EXT(in_commandBuffer, in_pConditionalRenderingBegin);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginConditionalRendering2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pConditionalRenderingBegin);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindTransformFeedbackBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffers2EXT&  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBindTransformFeedbackBuffer2InfoEXT* in_pBindingInfos = args.pBindingInfos.GetPointer();
    MapStructArrayHandles(args.pBindingInfos.GetMetaStructPointer(), args.pBindingInfos.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBindTransformFeedbackBuffers2EXT(in_commandBuffer, args.firstBinding, args.bindingCount, in_pBindingInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindTransformFeedbackBuffers2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstBinding, args.bindingCount, in_pBindingInfos);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedback2EXT&        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBindTransformFeedbackBuffer2InfoEXT* in_pCounterInfos = args.pCounterInfos.GetPointer();
    MapStructArrayHandles(args.pCounterInfos.GetMetaStructPointer(), args.pCounterInfos.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginTransformFeedback2EXT(in_commandBuffer, args.firstCounterRange, args.counterRangeCount, in_pCounterInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginTransformFeedback2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstCounterRange, args.counterRangeCount, in_pCounterInfos);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedback2EXT&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBindTransformFeedbackBuffer2InfoEXT* in_pCounterInfos = args.pCounterInfos.GetPointer();
    MapStructArrayHandles(args.pCounterInfos.GetMetaStructPointer(), args.pCounterInfos.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdEndTransformFeedback2EXT(in_commandBuffer, args.firstCounterRange, args.counterRangeCount, in_pCounterInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndTransformFeedback2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstCounterRange, args.counterRangeCount, in_pCounterInfos);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectByteCount2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCount2EXT&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBindTransformFeedbackBuffer2InfoEXT* in_pCounterInfo = args.pCounterInfo.GetPointer();
    MapStructHandles(args.pCounterInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectByteCount2EXT(in_commandBuffer, args.instanceCount, args.firstInstance, in_pCounterInfo, args.counterOffset, args.vertexStride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndirectByteCount2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.instanceCount, args.firstInstance, in_pCounterInfo, args.counterOffset, args.vertexStride);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirect2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirect2EXT&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDrawIndirect2InfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirect2EXT(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawMeshTasksIndirect2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCount2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCount2EXT&    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDrawIndirectCount2InfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectCount2EXT(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawMeshTasksIndirectCount2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdWriteMarkerToMemoryAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteMarkerToMemoryAMD&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkMemoryMarkerInfoAMD* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdWriteMarkerToMemoryAMD(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWriteMarkerToMemoryAMD(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCreateAccelerationStructure2KHR(
    const ApiCallInfo&                          call_info,
    args::CreateAccelerationStructure2KHR&      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAccelerationStructureCreateInfo2KHR* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pAccelerationStructure.IsNull()) { args.pAccelerationStructure.SetHandleLength(1); }
    VkAccelerationStructureKHR* out_pAccelerationStructure = args.pAccelerationStructure.GetHandlePointer();

    PushRecaptureHandleId(args.pAccelerationStructure.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateAccelerationStructure2KHR(in_device, in_pCreateInfo, in_pAllocator, out_pAccelerationStructure);
    CheckResult("vkCreateAccelerationStructure2KHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanAccelerationStructureKHRInfo>(args.device, args.pAccelerationStructure.GetPointer(), out_pAccelerationStructure, &CommonObjectInfoTable::AddVkAccelerationStructureKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2KHR&                    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyBufferInfo2* in_pCopyBufferInfo = args.pCopyBufferInfo.GetPointer();
    MapStructHandles(args.pCopyBufferInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyBuffer2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyBufferInfo, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyBuffer2KHR(in_commandBuffer, in_pCopyBufferInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyBuffer2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyBufferInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2KHR&                     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyImageInfo2* in_pCopyImageInfo = args.pCopyImageInfo.GetPointer();
    MapStructHandles(args.pCopyImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyImage2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyImageInfo, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyImage2KHR(in_commandBuffer, in_pCopyImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyImage2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyImageInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2KHR&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyBufferToImageInfo2* in_pCopyBufferToImageInfo = args.pCopyBufferToImageInfo.GetPointer();
    MapStructHandles(args.pCopyBufferToImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyBufferToImage2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyBufferToImageInfo, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyBufferToImage2KHR(in_commandBuffer, in_pCopyBufferToImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyBufferToImage2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyBufferToImageInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2KHR&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyImageToBufferInfo2* in_pCopyImageToBufferInfo = args.pCopyImageToBufferInfo.GetPointer();
    MapStructHandles(args.pCopyImageToBufferInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyImageToBuffer2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyImageToBufferInfo, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdCopyImageToBuffer2KHR(in_commandBuffer, in_pCopyImageToBufferInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyImageToBuffer2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pCopyImageToBufferInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2KHR&                     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBlitImageInfo2* in_pBlitImageInfo = args.pBlitImageInfo.GetPointer();
    MapStructHandles(args.pBlitImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdBlitImage2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pBlitImageInfo, true);
    }

    GetDeviceTable(in_commandBuffer)->CmdBlitImage2KHR(in_commandBuffer, in_pBlitImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBlitImage2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pBlitImageInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2KHR&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkResolveImageInfo2* in_pResolveImageInfo = args.pResolveImageInfo.GetPointer();
    MapStructHandles(args.pResolveImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdResolveImage2KHR(in_commandBuffer, in_pResolveImageInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdResolveImage2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pResolveImageInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysIndirect2KHR&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdTraceRaysIndirect2KHR(in_commandBuffer, args.indirectDeviceAddress);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdTraceRaysIndirect2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.indirectDeviceAddress);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceBufferMemoryRequirementsKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceBufferMemoryRequirements* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    GetDeviceTable(in_device)->GetDeviceBufferMemoryRequirementsKHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageMemoryRequirementsKHR&  args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    GetDeviceTable(in_device)->GetDeviceImageMemoryRequirementsKHR(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSparseMemoryRequirementsKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageMemoryRequirements* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSparseMemoryRequirementCount = args.pSparseMemoryRequirementCount.IsNull() ? nullptr : args.pSparseMemoryRequirementCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetDeviceImageSparseMemoryRequirementsKHR", VK_SUCCESS, args.device, kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR, &args.pSparseMemoryRequirementCount, &args.pSparseMemoryRequirements, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkSparseImageMemoryRequirements2* out_pSparseMemoryRequirements = args.pSparseMemoryRequirements.IsNull() ? nullptr : args.pSparseMemoryRequirements.AllocateOutputData(*out_pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2{ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2, nullptr });

    GetDeviceTable(in_device)->GetDeviceImageSparseMemoryRequirementsKHR(in_device, in_pInfo, out_pSparseMemoryRequirementCount, out_pSparseMemoryRequirements);

    if (args.pSparseMemoryRequirements.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetDeviceImageSparseMemoryRequirementsKHR, *out_pSparseMemoryRequirementCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2KHR&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindIndexBuffer2KHR(in_commandBuffer, in_buffer, args.offset, args.size, args.indexType);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindIndexBuffer2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.buffer), args.offset, args.size, args.indexType);
    }
}

void VulkanReplayConsumer::Process_vkGetRenderingAreaGranularityKHR(
    const ApiCallInfo&                          call_info,
    args::GetRenderingAreaGranularityKHR&       args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkRenderingAreaInfo* in_pRenderingAreaInfo = args.pRenderingAreaInfo.GetPointer();
    MapStructHandles(args.pRenderingAreaInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkExtent2D* out_pGranularity = args.pGranularity.IsNull() ? nullptr : args.pGranularity.AllocateOutputData(1);

    GetDeviceTable(in_device)->GetRenderingAreaGranularityKHR(in_device, in_pRenderingAreaInfo, out_pGranularity);
}

void VulkanReplayConsumer::Process_vkGetDeviceImageSubresourceLayoutKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceImageSubresourceLayoutKHR&   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceImageSubresourceInfo* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkSubresourceLayout2* out_pLayout = args.pLayout.IsNull() ? nullptr : args.pLayout.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2, nullptr });
    InitializeOutputStructPNext(&args.pLayout);

    GetDeviceTable(in_device)->GetDeviceImageSubresourceLayoutKHR(in_device, in_pInfo, out_pLayout);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout2KHR(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout2KHR&        args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(args.image, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageSubresource2* in_pSubresource = args.pSubresource.GetPointer();
    MapStructHandles(args.pSubresource.GetMetaStructPointer(), GetObjectInfoTable());
    VkSubresourceLayout2* out_pLayout = args.pLayout.IsNull() ? nullptr : args.pLayout.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2, nullptr });
    InitializeOutputStructPNext(&args.pLayout);

    GetDeviceTable(in_device)->GetImageSubresourceLayout2KHR(in_device, in_image, in_pSubresource, out_pLayout);
}

void VulkanReplayConsumer::Process_vkWaitForPresent2KHR(
    const ApiCallInfo&                          call_info,
    args::WaitForPresent2KHR&                   args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkWaitForPresent2KHR for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }
    const VkPresentWait2InfoKHR* in_pPresentWait2Info = args.pPresentWait2Info.GetPointer();
    MapStructHandles(args.pPresentWait2Info.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->WaitForPresent2KHR(in_device, in_swapchain, in_pPresentWait2Info);
    CheckResult("vkWaitForPresent2KHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreatePipelineBinariesKHR(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineBinariesKHR&            args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    SetStructArrayHandleLengths<Decoded_VkPipelineBinaryHandlesInfoKHR>(args.pBinaries.GetMetaStructPointer(), args.pBinaries.GetLength());
    args.pBinaries.IsNull() ? nullptr : args.pBinaries.AllocateOutputData(1, { VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR, nullptr });
    InitializeOutputStructPNext(&args.pBinaries);

    PushRecaptureStructHandleIds(args.pBinaries.GetMetaStructPointer(), this);
    VkResult replay_result = OverrideCreatePipelineBinariesKHR(GetDeviceTable(in_device->handle)->CreatePipelineBinariesKHR, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pBinaries);
    CheckResult("vkCreatePipelineBinariesKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddStructHandles(args.device, args.pBinaries.GetMetaStructPointer(), args.pBinaries.GetOutputPointer(), &GetObjectInfoTable());
}

void VulkanReplayConsumer::Process_vkDestroyPipelineBinaryKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineBinaryKHR&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipelineBinaryKHR in_pipelineBinary = MapHandle<VulkanPipelineBinaryKHRInfo>(args.pipelineBinary, &CommonObjectInfoTable::GetVkPipelineBinaryKHRInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyPipelineBinaryKHR(in_device, in_pipelineBinary, in_pAllocator);
    RemoveHandle(args.pipelineBinary, &CommonObjectInfoTable::RemoveVkPipelineBinaryKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPipelineKeyKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineKeyKHR&                    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineCreateInfoKHR* in_pPipelineCreateInfo = args.pPipelineCreateInfo.GetPointer();
    MapStructHandles(args.pPipelineCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkPipelineBinaryKeyKHR* out_pPipelineKey = args.pPipelineKey.IsNull() ? nullptr : args.pPipelineKey.AllocateOutputData(1, { VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR, nullptr });
    InitializeOutputStructPNext(&args.pPipelineKey);

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineKeyKHR(in_device, in_pPipelineCreateInfo, out_pPipelineKey);
    CheckResult("vkGetPipelineKeyKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPipelineBinaryDataKHR(
    const ApiCallInfo&                          call_info,
    args::GetPipelineBinaryDataKHR&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineBinaryDataInfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkPipelineBinaryKeyKHR* out_pPipelineBinaryKey = args.pPipelineBinaryKey.IsNull() ? nullptr : args.pPipelineBinaryKey.AllocateOutputData(1, { VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR, nullptr });
    InitializeOutputStructPNext(&args.pPipelineBinaryKey);
    size_t* out_pPipelineBinaryDataSize = args.pPipelineBinaryDataSize.IsNull() ? nullptr : args.pPipelineBinaryDataSize.AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanDeviceInfo>("vkGetPipelineBinaryDataKHR", args.result, args.device, kDeviceArrayGetPipelineBinaryDataKHR, &args.pPipelineBinaryDataSize, &args.pPipelineBinaryData, &CommonObjectInfoTable::GetVkDeviceInfo));
    void* out_pPipelineBinaryData = args.pPipelineBinaryData.IsNull() ? nullptr : args.pPipelineBinaryData.AllocateOutputData(*out_pPipelineBinaryDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetPipelineBinaryDataKHR(in_device, in_pInfo, out_pPipelineBinaryKey, out_pPipelineBinaryDataSize, out_pPipelineBinaryData);
    CheckResult("vkGetPipelineBinaryDataKHR", args.result, replay_result, call_info);

    if (args.pPipelineBinaryData.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetPipelineBinaryDataKHR, *out_pPipelineBinaryDataSize, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkReleaseCapturedPipelineDataKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseCapturedPipelineDataKHR&       args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkReleaseCapturedPipelineDataInfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    VkResult replay_result = GetDeviceTable(in_device)->ReleaseCapturedPipelineDataKHR(in_device, in_pInfo, in_pAllocator);
    CheckResult("vkReleaseCapturedPipelineDataKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkReleaseSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseSwapchainImagesKHR&            args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkReleaseSwapchainImagesKHR for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkReleaseSwapchainImagesInfoKHR* in_pReleaseInfo = args.pReleaseInfo.GetPointer();
    MapStructHandles(args.pReleaseInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ReleaseSwapchainImagesKHR(in_device, in_pReleaseInfo);
    CheckResult("vkReleaseSwapchainImagesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeMatrixPropertiesKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesKHR, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkCooperativeMatrixPropertiesKHR* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount, VkCooperativeMatrixPropertiesKHR{ VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesKHR(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR", args.result, replay_result, call_info);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesKHR, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleKHR&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineStippleKHR(in_commandBuffer, args.lineStippleFactor, args.lineStipplePattern);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetLineStippleKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.lineStippleFactor, args.lineStipplePattern);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCalibrateableTimeDomainsKHR& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pTimeDomainCount = args.pTimeDomainCount.IsNull() ? nullptr : args.pTimeDomainCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCalibrateableTimeDomainsKHR", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsKHR, &args.pTimeDomainCount, &args.pTimeDomains, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkTimeDomainKHR* out_pTimeDomains = args.pTimeDomains.IsNull() ? nullptr : args.pTimeDomains.AllocateOutputData(*out_pTimeDomainCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsKHR(in_physicalDevice, out_pTimeDomainCount, out_pTimeDomains);
    CheckResult("vkGetPhysicalDeviceCalibrateableTimeDomainsKHR", args.result, replay_result, call_info);

    if (args.pTimeDomains.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsKHR, *out_pTimeDomainCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetCalibratedTimestampsKHR(
    const ApiCallInfo&                          call_info,
    args::GetCalibratedTimestampsKHR&           args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCalibratedTimestampInfoKHR* in_pTimestampInfos = args.pTimestampInfos.GetPointer();
    MapStructArrayHandles(args.pTimestampInfos.GetMetaStructPointer(), args.pTimestampInfos.GetLength(), GetObjectInfoTable());
    uint64_t* out_pTimestamps = args.pTimestamps.IsNull() ? nullptr : args.pTimestamps.AllocateOutputData(args.timestampCount);
    uint64_t* out_pMaxDeviation = args.pMaxDeviation.IsNull() ? nullptr : args.pMaxDeviation.AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetCalibratedTimestampsKHR(in_device, args.timestampCount, in_pTimestampInfos, out_pTimestamps, out_pMaxDeviation);
    CheckResult("vkGetCalibratedTimestampsKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2KHR&            args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pBindDescriptorSetsInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdBindDescriptorSets2(GetDeviceTable(in_commandBuffer->handle)->CmdBindDescriptorSets2KHR, in_commandBuffer, &args.pBindDescriptorSetsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindDescriptorSets2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pBindDescriptorSetsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants2KHR&                 args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pPushConstantsInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdPushConstants2(GetDeviceTable(in_commandBuffer->handle)->CmdPushConstants2KHR, in_commandBuffer, &args.pPushConstantsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPushConstants2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.pPushConstantsInfo.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2KHR&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPushDescriptorSetInfo* in_pPushDescriptorSetInfo = args.pPushDescriptorSetInfo.GetPointer();
    MapStructHandles(args.pPushDescriptorSetInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPushDescriptorSet2KHR(in_commandBuffer, in_pPushDescriptorSetInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPushDescriptorSet2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, &args.pPushDescriptorSetInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDescriptorBufferOffsets2EXT&    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSetDescriptorBufferOffsetsInfoEXT* in_pSetDescriptorBufferOffsetsInfo = args.pSetDescriptorBufferOffsetsInfo.GetPointer();
    MapStructHandles(args.pSetDescriptorBufferOffsetsInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetDescriptorBufferOffsets2EXT(in_commandBuffer, in_pSetDescriptorBufferOffsetsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDescriptorBufferOffsets2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pSetDescriptorBufferOffsetsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBufferEmbeddedSamplers2EXT& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* in_pBindDescriptorBufferEmbeddedSamplersInfo = args.pBindDescriptorBufferEmbeddedSamplersInfo.GetPointer();
    MapStructHandles(args.pBindDescriptorBufferEmbeddedSamplersInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBindDescriptorBufferEmbeddedSamplers2EXT(in_commandBuffer, in_pBindDescriptorBufferEmbeddedSamplersInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pBindDescriptorBufferEmbeddedSamplersInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyMemoryIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryIndirectKHR&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyMemoryIndirectInfoKHR* in_pCopyMemoryIndirectInfo = args.pCopyMemoryIndirectInfo.GetPointer();
    MapStructHandles(args.pCopyMemoryIndirectInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMemoryIndirectKHR(in_commandBuffer, in_pCopyMemoryIndirectInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyMemoryIndirectKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pCopyMemoryIndirectInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageIndirectKHR&      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyMemoryToImageIndirectInfoKHR* in_pCopyMemoryToImageIndirectInfo = args.pCopyMemoryToImageIndirectInfo.GetPointer();
    MapStructHandles(args.pCopyMemoryToImageIndirectInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMemoryToImageIndirectKHR(in_commandBuffer, in_pCopyMemoryToImageIndirectInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyMemoryToImageIndirectKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pCopyMemoryToImageIndirectInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceFaultReportsKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceFaultReportsKHR&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    uint32_t* out_pFaultCounts = args.pFaultCounts.IsNull() ? nullptr : args.pFaultCounts.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetDeviceFaultReportsKHR", args.result, args.device, kDeviceArrayGetDeviceFaultReportsKHR, &args.pFaultCounts, &args.pFaultInfo, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkDeviceFaultInfoKHR* out_pFaultInfo = args.pFaultInfo.IsNull() ? nullptr : args.pFaultInfo.AllocateOutputData(*out_pFaultCounts, VkDeviceFaultInfoKHR{ VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_KHR, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceFaultReportsKHR(in_device, args.timeout, out_pFaultCounts, out_pFaultInfo);
    CheckResult("vkGetDeviceFaultReportsKHR", args.result, replay_result, call_info);

    if (args.pFaultInfo.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetDeviceFaultReportsKHR, *out_pFaultCounts, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetDeviceFaultDebugInfoKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceFaultDebugInfoKHR&           args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeviceFaultDebugInfoKHR* out_pDebugInfo = args.pDebugInfo.IsNull() ? nullptr : args.pDebugInfo.AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_FAULT_DEBUG_INFO_KHR, nullptr });
    InitializeOutputStructPNext(&args.pDebugInfo);

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceFaultDebugInfoKHR(in_device, out_pDebugInfo);
    CheckResult("vkGetDeviceFaultDebugInfoKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdEndRendering2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering2KHR&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRenderingEndInfoKHR* in_pRenderingEndInfo = args.pRenderingEndInfo.GetPointer();
    MapStructHandles(args.pRenderingEndInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdEndRendering2KHR(in_commandBuffer, in_pRenderingEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndRendering2KHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pRenderingEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkFrameBoundaryANDROID(
    const ApiCallInfo&                          call_info,
    args::FrameBoundaryANDROID&                 args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_semaphore = GetObjectInfoTable().GetVkSemaphoreInfo(args.semaphore);
    auto in_image = GetObjectInfoTable().GetVkImageInfo(args.image);

    OverrideFrameBoundaryANDROID(GetDeviceTable(in_device->handle)->FrameBoundaryANDROID, in_device, in_semaphore, in_image);
}

void VulkanReplayConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDebugReportCallbackEXT&         args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pCallback.IsNull()) { args.pCallback.SetHandleLength(1); }
    VulkanDebugReportCallbackEXTInfo handle_info;
    args.pCallback.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pCallback.GetPointer());
    VkResult replay_result = OverrideCreateDebugReportCallbackEXT(GetInstanceTable(in_instance->handle)->CreateDebugReportCallbackEXT, args.result, in_instance, &args.pCreateInfo, &args.pAllocator, &args.pCallback);
    CheckResult("vkCreateDebugReportCallbackEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDebugReportCallbackEXTInfo>(args.instance, args.pCallback.GetPointer(), args.pCallback.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDebugReportCallbackEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyDebugReportCallbackEXT&        args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    VkDebugReportCallbackEXT in_callback = MapHandle<VulkanDebugReportCallbackEXTInfo>(args.callback, &CommonObjectInfoTable::GetVkDebugReportCallbackEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetInstanceTable(in_instance)->DestroyDebugReportCallbackEXT(in_instance, in_callback, in_pAllocator);
    RemoveHandle(args.callback, &CommonObjectInfoTable::RemoveVkDebugReportCallbackEXTInfo);
}

void VulkanReplayConsumer::Process_vkDebugReportMessageEXT(
    const ApiCallInfo&                          call_info,
    args::DebugReportMessageEXT&                args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    uint64_t in_object = MapHandle(args.object, args.objectType);
    const char* in_pLayerPrefix = args.pLayerPrefix.GetPointer();
    const char* in_pMessage = args.pMessage.GetPointer();

    GetInstanceTable(in_instance)->DebugReportMessageEXT(in_instance, args.flags, args.objectType, in_object, args.location, args.messageCode, in_pLayerPrefix, in_pMessage);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    args::DebugMarkerSetObjectTagEXT&           args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDebugMarkerObjectTagInfoEXT* in_pTagInfo = args.pTagInfo.GetPointer();
    MapStructHandles(args.pTagInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->DebugMarkerSetObjectTagEXT(in_device, in_pTagInfo);
    CheckResult("vkDebugMarkerSetObjectTagEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    args::DebugMarkerSetObjectNameEXT&          args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDebugMarkerObjectNameInfoEXT* in_pNameInfo = args.pNameInfo.GetPointer();
    MapStructHandles(args.pNameInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->DebugMarkerSetObjectNameEXT(in_device, in_pNameInfo);
    CheckResult("vkDebugMarkerSetObjectNameEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerBeginEXT&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDebugMarkerMarkerInfoEXT* in_pMarkerInfo = args.pMarkerInfo.GetPointer();
    MapStructHandles(args.pMarkerInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDebugMarkerBeginEXT(in_commandBuffer, in_pMarkerInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDebugMarkerBeginEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pMarkerInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerEndEXT&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDebugMarkerEndEXT(in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDebugMarkerEndEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerInsertEXT&              args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pMarkerInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdDebugMarkerInsertEXT(GetDeviceTable(in_commandBuffer->handle)->CmdDebugMarkerInsertEXT, in_commandBuffer, &args.pMarkerInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDebugMarkerInsertEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.pMarkerInfo.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffersEXT&   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<VulkanBufferInfo>(&args.pBuffers, args.bindingCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pOffsets = args.pOffsets.GetPointer();
    const VkDeviceSize* in_pSizes = args.pSizes.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindTransformFeedbackBuffersEXT(in_commandBuffer, args.firstBinding, args.bindingCount, in_pBuffers, in_pOffsets, in_pSizes);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindTransformFeedbackBuffersEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstBinding, args.bindingCount, in_pBuffers, in_pOffsets, in_pSizes);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedbackEXT&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pCounterBuffers = MapHandles<VulkanBufferInfo>(&args.pCounterBuffers, args.counterBufferCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pCounterBufferOffsets = args.pCounterBufferOffsets.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBeginTransformFeedbackEXT(in_commandBuffer, args.firstCounterBuffer, args.counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginTransformFeedbackEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstCounterBuffer, args.counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedbackEXT&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pCounterBuffers = MapHandles<VulkanBufferInfo>(&args.pCounterBuffers, args.counterBufferCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pCounterBufferOffsets = args.pCounterBufferOffsets.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdEndTransformFeedbackEXT(in_commandBuffer, args.firstCounterBuffer, args.counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndTransformFeedbackEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstCounterBuffer, args.counterBufferCount, in_pCounterBuffers, in_pCounterBufferOffsets);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginQueryIndexedEXT&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(args.queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdBeginQueryIndexedEXT(in_commandBuffer, in_queryPool, args.query, args.flags, args.index);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginQueryIndexedEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool), args.query, args.flags, args.index);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndQueryIndexedEXT&                args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool);

    OverrideCmdEndQueryIndexedEXT(GetDeviceTable(in_commandBuffer->handle)->CmdEndQueryIndexedEXT, in_commandBuffer, in_queryPool, args.query, args.index);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndQueryIndexedEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, in_queryPool, args.query, args.index);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCountEXT&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_counterBuffer = MapHandle<VulkanBufferInfo>(args.counterBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectByteCountEXT(in_commandBuffer, args.instanceCount, args.firstInstance, in_counterBuffer, args.counterBufferOffset, args.counterOffset, args.vertexStride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndirectByteCountEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.instanceCount, args.firstInstance, in_counterBuffer, args.counterBufferOffset, args.counterOffset, args.vertexStride);
    }
}

void VulkanReplayConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    args::GetImageViewHandleNVX&                args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImageViewHandleInfoNVX* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetImageViewHandleNVX(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetImageViewHandle64NVX(
    const ApiCallInfo&                          call_info,
    args::GetImageViewHandle64NVX&              args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImageViewHandleInfoNVX* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetImageViewHandle64NVX(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    args::GetImageViewAddressNVX&               args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImageView in_imageView = MapHandle<VulkanImageViewInfo>(args.imageView, &CommonObjectInfoTable::GetVkImageViewInfo);
    VkImageViewAddressPropertiesNVX* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX, nullptr });
    InitializeOutputStructPNext(&args.pProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetImageViewAddressNVX(in_device, in_imageView, out_pProperties);
    CheckResult("vkGetImageViewAddressNVX", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceCombinedImageSamplerIndexNVX(
    const ApiCallInfo&                          call_info,
    args::GetDeviceCombinedImageSamplerIndexNVX& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);

    GetDeviceTable(in_device)->GetDeviceCombinedImageSamplerIndexNVX(in_device, args.imageViewIndex, args.samplerIndex);
}

void VulkanReplayConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountAMD&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(args.countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndirectCountAMD(in_commandBuffer, in_buffer, args.offset, in_countBuffer, args.countBufferOffset, args.maxDrawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndirectCountAMD(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.buffer), args.offset, GetObjectInfoTable().GetVkBufferInfo(args.countBuffer), args.countBufferOffset, args.maxDrawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountAMD&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(args.countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawIndexedIndirectCountAMD(in_commandBuffer, in_buffer, args.offset, in_countBuffer, args.countBufferOffset, args.maxDrawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawIndexedIndirectCountAMD(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, GetObjectInfoTable().GetVkBufferInfo(args.buffer), args.offset, GetObjectInfoTable().GetVkBufferInfo(args.countBuffer), args.countBufferOffset, args.maxDrawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkGetShaderInfoAMD(
    const ApiCallInfo&                          call_info,
    args::GetShaderInfoAMD&                     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(args.pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);
    size_t* out_pInfoSize = args.pInfoSize.IsNull() ? nullptr : args.pInfoSize.AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanPipelineInfo>("vkGetShaderInfoAMD", args.result, args.pipeline, kPipelineArrayGetShaderInfoAMD, &args.pInfoSize, &args.pInfo, &CommonObjectInfoTable::GetVkPipelineInfo));
    void* out_pInfo = args.pInfo.IsNull() ? nullptr : args.pInfo.AllocateOutputData(*out_pInfoSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetShaderInfoAMD(in_device, in_pipeline, args.shaderStage, args.infoType, out_pInfoSize, out_pInfo);
    CheckResult("vkGetShaderInfoAMD", args.result, replay_result, call_info);

    if (args.pInfo.IsNull()) { SetOutputArrayCount<VulkanPipelineInfo>(args.pipeline, kPipelineArrayGetShaderInfoAMD, *out_pInfoSize, &CommonObjectInfoTable::GetVkPipelineInfo); }
}

void VulkanReplayConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    args::CreateStreamDescriptorSurfaceGGP&     args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkStreamDescriptorSurfaceCreateInfoGGP* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = args.pSurface.GetHandlePointer();

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = GetInstanceTable(in_instance)->CreateStreamDescriptorSurfaceGGP(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateStreamDescriptorSurfaceGGP", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalImageFormatPropertiesNV& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkExternalImageFormatPropertiesNV* out_pExternalImageFormatProperties = args.pExternalImageFormatProperties.IsNull() ? nullptr : args.pExternalImageFormatProperties.AllocateOutputData(1);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(in_physicalDevice, args.format, args.type, args.tiling, args.usage, args.flags, args.externalHandleType, out_pExternalImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceExternalImageFormatPropertiesNV", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
    args::GetMemoryWin32HandleNV&               args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeviceMemory in_memory = MapHandle<VulkanDeviceMemoryInfo>(args.memory, &CommonObjectInfoTable::GetVkDeviceMemoryInfo);
    HANDLE* out_pHandle = args.pHandle.IsNull() ? nullptr : reinterpret_cast<HANDLE*>(args.pHandle.AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryWin32HandleNV(in_device, in_memory, args.handleType, out_pHandle);
    CheckResult("vkGetMemoryWin32HandleNV", args.result, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*args.pHandle.GetPointer()), static_cast<void*>(*out_pHandle), format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV, "vkGetMemoryWin32HandleNV");
}

void VulkanReplayConsumer::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    args::CreateViSurfaceNN&                    args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkViSurfaceCreateInfoNN* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = args.pSurface.GetHandlePointer();

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = GetInstanceTable(in_instance)->CreateViSurfaceNN(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateViSurfaceNN", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRenderingEXT&      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkConditionalRenderingBeginInfoEXT* in_pConditionalRenderingBegin = args.pConditionalRenderingBegin.GetPointer();
    MapStructHandles(args.pConditionalRenderingBegin.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginConditionalRenderingEXT(in_commandBuffer, in_pConditionalRenderingBegin);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginConditionalRenderingEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pConditionalRenderingBegin);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndConditionalRenderingEXT&        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndConditionalRenderingEXT(in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndConditionalRenderingEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWScalingNV&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkViewportWScalingNV* in_pViewportWScalings = args.pViewportWScalings.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWScalingNV(in_commandBuffer, args.firstViewport, args.viewportCount, in_pViewportWScalings);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetViewportWScalingNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstViewport, args.viewportCount, in_pViewportWScalings);
    }
}

void VulkanReplayConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseDisplayEXT&                    args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(args.display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->ReleaseDisplayEXT(in_physicalDevice, in_display);
    CheckResult("vkReleaseDisplayEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::AcquireXlibDisplayEXT&                args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(args.dpy, format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT, "vkAcquireXlibDisplayEXT"));
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(args.display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->AcquireXlibDisplayEXT(in_physicalDevice, in_dpy, in_display);
    CheckResult("vkAcquireXlibDisplayEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::GetRandROutputDisplayEXT&             args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    Display* in_dpy = static_cast<Display*>(PreProcessExternalObject(args.dpy, format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT, "vkGetRandROutputDisplayEXT"));
    if (!args.pDisplay.IsNull()) { args.pDisplay.SetHandleLength(1); }
    VulkanDisplayKHRInfo handle_info;
    args.pDisplay.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pDisplay.GetPointer());
    VkResult replay_result = OverrideGetRandROutputDisplayEXT(GetInstanceTable(in_physicalDevice->handle)->GetRandROutputDisplayEXT, args.result, in_physicalDevice, in_dpy, args.rrOutput, &args.pDisplay);
    CheckResult("vkGetRandROutputDisplayEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDisplayKHRInfo>(args.physicalDevice, args.pDisplay.GetPointer(), args.pDisplay.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfaceCapabilities2EXT& args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfaceCapabilities2EXT for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkSurfaceKHR in_surface = MapHandle<VulkanSurfaceKHRInfo>(args.surface, &CommonObjectInfoTable::GetVkSurfaceKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(args.surface)->surface_creation_skipped) { return; }
    VkSurfaceCapabilities2EXT* out_pSurfaceCapabilities = args.pSurfaceCapabilities.IsNull() ? nullptr : args.pSurfaceCapabilities.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT, nullptr });
    InitializeOutputStructPNext(&args.pSurfaceCapabilities);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(in_physicalDevice, in_surface, out_pSurfaceCapabilities);
    CheckResult("vkGetPhysicalDeviceSurfaceCapabilities2EXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    args::DisplayPowerControlEXT&               args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(args.display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    const VkDisplayPowerInfoEXT* in_pDisplayPowerInfo = args.pDisplayPowerInfo.GetPointer();
    MapStructHandles(args.pDisplayPowerInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->DisplayPowerControlEXT(in_device, in_display, in_pDisplayPowerInfo);
    CheckResult("vkDisplayPowerControlEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    args::RegisterDeviceEventEXT&               args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceEventInfoEXT* in_pDeviceEventInfo = args.pDeviceEventInfo.GetPointer();
    MapStructHandles(args.pDeviceEventInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pFence.IsNull()) { args.pFence.SetHandleLength(1); }
    VkFence* out_pFence = args.pFence.GetHandlePointer();

    PushRecaptureHandleId(args.pFence.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->RegisterDeviceEventEXT(in_device, in_pDeviceEventInfo, in_pAllocator, out_pFence);
    CheckResult("vkRegisterDeviceEventEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanFenceInfo>(args.device, args.pFence.GetPointer(), out_pFence, &CommonObjectInfoTable::AddVkFenceInfo);
}

void VulkanReplayConsumer::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
    args::RegisterDisplayEventEXT&              args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(args.display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);
    const VkDisplayEventInfoEXT* in_pDisplayEventInfo = args.pDisplayEventInfo.GetPointer();
    MapStructHandles(args.pDisplayEventInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pFence.IsNull()) { args.pFence.SetHandleLength(1); }
    VkFence* out_pFence = args.pFence.GetHandlePointer();

    PushRecaptureHandleId(args.pFence.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->RegisterDisplayEventEXT(in_device, in_display, in_pDisplayEventInfo, in_pAllocator, out_pFence);
    CheckResult("vkRegisterDisplayEventEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanFenceInfo>(args.device, args.pFence.GetPointer(), out_pFence, &CommonObjectInfoTable::AddVkFenceInfo);
}

void VulkanReplayConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainCounterEXT&               args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetSwapchainCounterEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }
    uint64_t* out_pCounterValue = args.pCounterValue.IsNull() ? nullptr : args.pCounterValue.AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainCounterEXT(in_device, in_swapchain, args.counter, out_pCounterValue);
    CheckResult("vkGetSwapchainCounterEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    args::GetRefreshCycleDurationGOOGLE&        args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetRefreshCycleDurationGOOGLE for offscreen.");
        return;
    }
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_swapchain = GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain);
    args.pDisplayTimingProperties.IsNull() ? nullptr : args.pDisplayTimingProperties.AllocateOutputData(1);

    VkResult replay_result = OverrideGetRefreshCycleDurationGOOGLE(GetDeviceTable(in_device->handle)->GetRefreshCycleDurationGOOGLE, args.result, in_device, in_swapchain, &args.pDisplayTimingProperties);
    CheckResult("vkGetRefreshCycleDurationGOOGLE", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
    args::GetPastPresentationTimingGOOGLE&      args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPastPresentationTimingGOOGLE for offscreen.");
        return;
    }
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_swapchain = GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain);
    args.pPresentationTimingCount.IsNull() ? nullptr : args.pPresentationTimingCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanSwapchainKHRInfo>("vkGetPastPresentationTimingGOOGLE", args.result, args.swapchain, kSwapchainKHRArrayGetPastPresentationTimingGOOGLE, &args.pPresentationTimingCount, &args.pPresentationTimings, &CommonObjectInfoTable::GetVkSwapchainKHRInfo));
    if (!args.pPresentationTimings.IsNull()) { args.pPresentationTimings.AllocateOutputData(*args.pPresentationTimingCount.GetOutputPointer()); }

    VkResult replay_result = OverrideGetPastPresentationTimingGOOGLE(GetDeviceTable(in_device->handle)->GetPastPresentationTimingGOOGLE, args.result, in_device, in_swapchain, &args.pPresentationTimingCount, &args.pPresentationTimings);
    CheckResult("vkGetPastPresentationTimingGOOGLE", args.result, replay_result, call_info);

    if (args.pPresentationTimings.IsNull()) { SetOutputArrayCount<VulkanSwapchainKHRInfo>(args.swapchain, kSwapchainKHRArrayGetPastPresentationTimingGOOGLE, *args.pPresentationTimingCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkSwapchainKHRInfo); }
}

void VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleEXT&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRect2D* in_pDiscardRectangles = args.pDiscardRectangles.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleEXT(in_commandBuffer, args.firstDiscardRectangle, args.discardRectangleCount, in_pDiscardRectangles);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDiscardRectangleEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstDiscardRectangle, args.discardRectangleCount, in_pDiscardRectangles);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleEnableEXT&      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleEnableEXT(in_commandBuffer, args.discardRectangleEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDiscardRectangleEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.discardRectangleEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleModeEXT&        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDiscardRectangleModeEXT(in_commandBuffer, args.discardRectangleMode);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDiscardRectangleModeEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.discardRectangleMode);
    }
}

void VulkanReplayConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    args::SetHdrMetadataEXT&                    args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkSetHdrMetadataEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSwapchainKHR* in_pSwapchains = MapHandles<VulkanSwapchainKHRInfo>(&args.pSwapchains, args.swapchainCount, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    const VkHdrMetadataEXT* in_pMetadata = args.pMetadata.GetPointer();
    MapStructArrayHandles(args.pMetadata.GetMetaStructPointer(), args.pMetadata.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_device)->SetHdrMetadataEXT(in_device, args.swapchainCount, in_pSwapchains, in_pMetadata);
}

void VulkanReplayConsumer::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    args::CreateIOSSurfaceMVK&                  args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkIOSSurfaceCreateInfoMVK* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = args.pSurface.GetHandlePointer();

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = GetInstanceTable(in_instance)->CreateIOSSurfaceMVK(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateIOSSurfaceMVK", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    args::CreateMacOSSurfaceMVK&                args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkMacOSSurfaceCreateInfoMVK* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = args.pSurface.GetHandlePointer();

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = GetInstanceTable(in_instance)->CreateMacOSSurfaceMVK(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateMacOSSurfaceMVK", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    args::SetDebugUtilsObjectNameEXT&           args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    VulkanDeviceInfo* device_info     = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    VkPhysicalDevice  physical_device = device_info->parent;

    VkResult replay_result = OverrideSetDebugUtilsObjectNameEXT(GetInstanceTable(physical_device)->SetDebugUtilsObjectNameEXT, args.result, in_device, &args.pNameInfo);
    CheckResult("vkSetDebugUtilsObjectNameEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    args::SetDebugUtilsObjectTagEXT&            args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pTagInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VulkanDeviceInfo* device_info     = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    VkPhysicalDevice  physical_device = device_info->parent;

    VkResult replay_result = OverrideSetDebugUtilsObjectTagEXT(GetInstanceTable(physical_device)->SetDebugUtilsObjectTagEXT, args.result, in_device, &args.pTagInfo);
    CheckResult("vkSetDebugUtilsObjectTagEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::QueueBeginDebugUtilsLabelEXT&         args)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(args.queue, &CommonObjectInfoTable::GetVkQueueInfo);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = args.pLabelInfo.GetPointer();
    MapStructHandles(args.pLabelInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_queue)->QueueBeginDebugUtilsLabelEXT(in_queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::QueueEndDebugUtilsLabelEXT&           args)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(args.queue, &CommonObjectInfoTable::GetVkQueueInfo);

    GetDeviceTable(in_queue)->QueueEndDebugUtilsLabelEXT(in_queue);
}

void VulkanReplayConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::QueueInsertDebugUtilsLabelEXT&        args)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(args.queue, &CommonObjectInfoTable::GetVkQueueInfo);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = args.pLabelInfo.GetPointer();
    MapStructHandles(args.pLabelInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_queue)->QueueInsertDebugUtilsLabelEXT(in_queue, in_pLabelInfo);
}

void VulkanReplayConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginDebugUtilsLabelEXT&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDebugUtilsLabelEXT* in_pLabelInfo = args.pLabelInfo.GetPointer();
    MapStructHandles(args.pLabelInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginDebugUtilsLabelEXT(in_commandBuffer, in_pLabelInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginDebugUtilsLabelEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pLabelInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndDebugUtilsLabelEXT&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndDebugUtilsLabelEXT(in_commandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndDebugUtilsLabelEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer);
    }
}

void VulkanReplayConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdInsertDebugUtilsLabelEXT&          args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pLabelInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdInsertDebugUtilsLabelEXT(GetDeviceTable(in_commandBuffer->handle)->CmdInsertDebugUtilsLabelEXT, in_commandBuffer, &args.pLabelInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdInsertDebugUtilsLabelEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.pLabelInfo.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDebugUtilsMessengerEXT&         args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pMessenger.IsNull()) { args.pMessenger.SetHandleLength(1); }
    VulkanDebugUtilsMessengerEXTInfo handle_info;
    args.pMessenger.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pMessenger.GetPointer());
    VkResult replay_result = OverrideCreateDebugUtilsMessengerEXT(GetInstanceTable(in_instance->handle)->CreateDebugUtilsMessengerEXT, args.result, in_instance, &args.pCreateInfo, &args.pAllocator, &args.pMessenger);
    CheckResult("vkCreateDebugUtilsMessengerEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDebugUtilsMessengerEXTInfo>(args.instance, args.pMessenger.GetPointer(), args.pMessenger.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDebugUtilsMessengerEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyDebugUtilsMessengerEXT&        args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    VkDebugUtilsMessengerEXT in_messenger = MapHandle<VulkanDebugUtilsMessengerEXTInfo>(args.messenger, &CommonObjectInfoTable::GetVkDebugUtilsMessengerEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetInstanceTable(in_instance)->DestroyDebugUtilsMessengerEXT(in_instance, in_messenger, in_pAllocator);
    RemoveHandle(args.messenger, &CommonObjectInfoTable::RemoveVkDebugUtilsMessengerEXTInfo);
}

void VulkanReplayConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    args::SubmitDebugUtilsMessageEXT&           args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkDebugUtilsMessengerCallbackDataEXT* in_pCallbackData = args.pCallbackData.GetPointer();
    MapStructHandles(args.pCallbackData.GetMetaStructPointer(), GetObjectInfoTable());

    GetInstanceTable(in_instance)->SubmitDebugUtilsMessageEXT(in_instance, args.messageSeverity, args.messageTypes, in_pCallbackData);
}

void VulkanReplayConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    const ApiCallInfo&                          call_info,
    args::GetAndroidHardwareBufferPropertiesANDROID& args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    const struct AHardwareBuffer* in_buffer = static_cast<const struct AHardwareBuffer*>(PreProcessExternalObject(args.buffer, format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID, "vkGetAndroidHardwareBufferPropertiesANDROID"));
    args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID, nullptr });
    InitializeOutputStructPNext(&args.pProperties);

    VkResult replay_result = OverrideGetAndroidHardwareBufferPropertiesANDROID(GetDeviceTable(in_device->handle)->GetAndroidHardwareBufferPropertiesANDROID, args.result, in_device, in_buffer, &args.pProperties);
    CheckResult("vkGetAndroidHardwareBufferPropertiesANDROID", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    args::GetMemoryAndroidHardwareBufferANDROID& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    struct AHardwareBuffer** out_pBuffer = args.pBuffer.IsNull() ? nullptr : reinterpret_cast<struct AHardwareBuffer**>(args.pBuffer.AllocateOutputData(1));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryAndroidHardwareBufferANDROID(in_device, in_pInfo, out_pBuffer);
    CheckResult("vkGetMemoryAndroidHardwareBufferANDROID", args.result, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*args.pBuffer.GetPointer()), static_cast<void*>(*out_pBuffer), format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID, "vkGetMemoryAndroidHardwareBufferANDROID");
}

void VulkanReplayConsumer::Process_vkCreateGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CreateGpaSessionAMD&                  args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkGpaSessionCreateInfoAMD* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pGpaSession.IsNull()) { args.pGpaSession.SetHandleLength(1); }
    VkGpaSessionAMD* out_pGpaSession = args.pGpaSession.GetHandlePointer();

    PushRecaptureHandleId(args.pGpaSession.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateGpaSessionAMD(in_device, in_pCreateInfo, in_pAllocator, out_pGpaSession);
    CheckResult("vkCreateGpaSessionAMD", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanGpaSessionAMDInfo>(args.device, args.pGpaSession.GetPointer(), out_pGpaSession, &CommonObjectInfoTable::AddVkGpaSessionAMDInfo);
}

void VulkanReplayConsumer::Process_vkDestroyGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::DestroyGpaSessionAMD&                 args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkGpaSessionAMD in_gpaSession = MapHandle<VulkanGpaSessionAMDInfo>(args.gpaSession, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyGpaSessionAMD(in_device, in_gpaSession, in_pAllocator);
    RemoveHandle(args.gpaSession, &CommonObjectInfoTable::RemoveVkGpaSessionAMDInfo);
}

void VulkanReplayConsumer::Process_vkSetGpaDeviceClockModeAMD(
    const ApiCallInfo&                          call_info,
    args::SetGpaDeviceClockModeAMD&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkGpaDeviceClockModeInfoAMD* out_pInfo = args.pInfo.IsNull() ? nullptr : args.pInfo.AllocateOutputData(1, { VK_STRUCTURE_TYPE_GPA_DEVICE_CLOCK_MODE_INFO_AMD, nullptr });
    InitializeOutputStructPNext(&args.pInfo);

    VkResult replay_result = GetDeviceTable(in_device)->SetGpaDeviceClockModeAMD(in_device, out_pInfo);
    CheckResult("vkSetGpaDeviceClockModeAMD", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetGpaDeviceClockInfoAMD(
    const ApiCallInfo&                          call_info,
    args::GetGpaDeviceClockInfoAMD&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkGpaDeviceGetClockInfoAMD* out_pInfo = args.pInfo.IsNull() ? nullptr : args.pInfo.AllocateOutputData(1, { VK_STRUCTURE_TYPE_GPA_DEVICE_GET_CLOCK_INFO_AMD, nullptr });
    InitializeOutputStructPNext(&args.pInfo);

    VkResult replay_result = GetDeviceTable(in_device)->GetGpaDeviceClockInfoAMD(in_device, out_pInfo);
    CheckResult("vkGetGpaDeviceClockInfoAMD", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdBeginGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CmdBeginGpaSessionAMD&                args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkGpaSessionAMD in_gpaSession = MapHandle<VulkanGpaSessionAMDInfo>(args.gpaSession, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo);

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdBeginGpaSessionAMD(in_commandBuffer, in_gpaSession);
    CheckResult("vkCmdBeginGpaSessionAMD", args.result, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginGpaSessionAMD(call_info, GetInjectedDeviceCalls(in_commandBuffer), args.result, in_commandBuffer, in_gpaSession);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CmdEndGpaSessionAMD&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkGpaSessionAMD in_gpaSession = MapHandle<VulkanGpaSessionAMDInfo>(args.gpaSession, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo);

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdEndGpaSessionAMD(in_commandBuffer, in_gpaSession);
    CheckResult("vkCmdEndGpaSessionAMD", args.result, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndGpaSessionAMD(call_info, GetInjectedDeviceCalls(in_commandBuffer), args.result, in_commandBuffer, in_gpaSession);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    args::CmdBeginGpaSampleAMD&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkGpaSessionAMD in_gpaSession = MapHandle<VulkanGpaSessionAMDInfo>(args.gpaSession, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo);
    const VkGpaSampleBeginInfoAMD* in_pGpaSampleBeginInfo = args.pGpaSampleBeginInfo.GetPointer();
    MapStructHandles(args.pGpaSampleBeginInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pSampleID = args.pSampleID.IsNull() ? nullptr : args.pSampleID.AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdBeginGpaSampleAMD(in_commandBuffer, in_gpaSession, in_pGpaSampleBeginInfo, out_pSampleID);
    CheckResult("vkCmdBeginGpaSampleAMD", args.result, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginGpaSampleAMD(call_info, GetInjectedDeviceCalls(in_commandBuffer), args.result, in_commandBuffer, in_gpaSession, in_pGpaSampleBeginInfo, out_pSampleID);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    args::CmdEndGpaSampleAMD&                   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkGpaSessionAMD in_gpaSession = MapHandle<VulkanGpaSessionAMDInfo>(args.gpaSession, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo);

    GetDeviceTable(in_commandBuffer)->CmdEndGpaSampleAMD(in_commandBuffer, in_gpaSession, args.sampleID);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndGpaSampleAMD(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_gpaSession, args.sampleID);
    }
}

void VulkanReplayConsumer::Process_vkGetGpaSessionStatusAMD(
    const ApiCallInfo&                          call_info,
    args::GetGpaSessionStatusAMD&               args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkGpaSessionAMD in_gpaSession = MapHandle<VulkanGpaSessionAMDInfo>(args.gpaSession, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo);

    VkResult replay_result = GetDeviceTable(in_device)->GetGpaSessionStatusAMD(in_device, in_gpaSession);
    CheckResult("vkGetGpaSessionStatusAMD", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetGpaSessionResultsAMD(
    const ApiCallInfo&                          call_info,
    args::GetGpaSessionResultsAMD&              args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkGpaSessionAMD in_gpaSession = MapHandle<VulkanGpaSessionAMDInfo>(args.gpaSession, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo);
    size_t* out_pSizeInBytes = args.pSizeInBytes.IsNull() ? nullptr : args.pSizeInBytes.AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanGpaSessionAMDInfo>("vkGetGpaSessionResultsAMD", args.result, args.gpaSession, kGpaSessionAMDArrayGetGpaSessionResultsAMD, &args.pSizeInBytes, &args.pData, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo));
    void* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(*out_pSizeInBytes);

    VkResult replay_result = GetDeviceTable(in_device)->GetGpaSessionResultsAMD(in_device, in_gpaSession, args.sampleID, out_pSizeInBytes, out_pData);
    CheckResult("vkGetGpaSessionResultsAMD", args.result, replay_result, call_info);

    if (args.pData.IsNull()) { SetOutputArrayCount<VulkanGpaSessionAMDInfo>(args.gpaSession, kGpaSessionAMDArrayGetGpaSessionResultsAMD, *out_pSizeInBytes, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo); }
}

void VulkanReplayConsumer::Process_vkResetGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::ResetGpaSessionAMD&                   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkGpaSessionAMD in_gpaSession = MapHandle<VulkanGpaSessionAMDInfo>(args.gpaSession, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo);

    VkResult replay_result = GetDeviceTable(in_device)->ResetGpaSessionAMD(in_device, in_gpaSession);
    CheckResult("vkResetGpaSessionAMD", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdCopyGpaSessionResultsAMD(
    const ApiCallInfo&                          call_info,
    args::CmdCopyGpaSessionResultsAMD&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkGpaSessionAMD in_gpaSession = MapHandle<VulkanGpaSessionAMDInfo>(args.gpaSession, &CommonObjectInfoTable::GetVkGpaSessionAMDInfo);

    GetDeviceTable(in_commandBuffer)->CmdCopyGpaSessionResultsAMD(in_commandBuffer, in_gpaSession);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyGpaSessionResultsAMD(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_gpaSession);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleLocationsEXT&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSampleLocationsInfoEXT* in_pSampleLocationsInfo = args.pSampleLocationsInfo.GetPointer();
    MapStructHandles(args.pSampleLocationsInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetSampleLocationsEXT(in_commandBuffer, in_pSampleLocationsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetSampleLocationsEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pSampleLocationsInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceMultisamplePropertiesEXT& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkMultisamplePropertiesEXT* out_pMultisampleProperties = args.pMultisampleProperties.IsNull() ? nullptr : args.pMultisampleProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT, nullptr });
    InitializeOutputStructPNext(&args.pMultisampleProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(in_physicalDevice, args.samples, out_pMultisampleProperties);
}

void VulkanReplayConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetImageDrmFormatModifierPropertiesEXT& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(args.image, &CommonObjectInfoTable::GetVkImageInfo);
    VkImageDrmFormatModifierPropertiesEXT* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT, nullptr });
    InitializeOutputStructPNext(&args.pProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetImageDrmFormatModifierPropertiesEXT(in_device, in_image, out_pProperties);
    CheckResult("vkGetImageDrmFormatModifierPropertiesEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    args::CreateValidationCacheEXT&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkValidationCacheCreateInfoEXT* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pValidationCache.IsNull()) { args.pValidationCache.SetHandleLength(1); }
    VkValidationCacheEXT* out_pValidationCache = args.pValidationCache.GetHandlePointer();

    PushRecaptureHandleId(args.pValidationCache.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateValidationCacheEXT(in_device, in_pCreateInfo, in_pAllocator, out_pValidationCache);
    CheckResult("vkCreateValidationCacheEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanValidationCacheEXTInfo>(args.device, args.pValidationCache.GetPointer(), out_pValidationCache, &CommonObjectInfoTable::AddVkValidationCacheEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyValidationCacheEXT&            args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkValidationCacheEXT in_validationCache = MapHandle<VulkanValidationCacheEXTInfo>(args.validationCache, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyValidationCacheEXT(in_device, in_validationCache, in_pAllocator);
    RemoveHandle(args.validationCache, &CommonObjectInfoTable::RemoveVkValidationCacheEXTInfo);
}

void VulkanReplayConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
    args::MergeValidationCachesEXT&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkValidationCacheEXT in_dstCache = MapHandle<VulkanValidationCacheEXTInfo>(args.dstCache, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo);
    const VkValidationCacheEXT* in_pSrcCaches = MapHandles<VulkanValidationCacheEXTInfo>(&args.pSrcCaches, args.srcCacheCount, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo);

    VkResult replay_result = GetDeviceTable(in_device)->MergeValidationCachesEXT(in_device, in_dstCache, args.srcCacheCount, in_pSrcCaches);
    CheckResult("vkMergeValidationCachesEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
    args::GetValidationCacheDataEXT&            args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkValidationCacheEXT in_validationCache = MapHandle<VulkanValidationCacheEXTInfo>(args.validationCache, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo);
    size_t* out_pDataSize = args.pDataSize.IsNull() ? nullptr : args.pDataSize.AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanValidationCacheEXTInfo>("vkGetValidationCacheDataEXT", args.result, args.validationCache, kValidationCacheEXTArrayGetValidationCacheDataEXT, &args.pDataSize, &args.pData, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo));
    void* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(*out_pDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetValidationCacheDataEXT(in_device, in_validationCache, out_pDataSize, out_pData);
    CheckResult("vkGetValidationCacheDataEXT", args.result, replay_result, call_info);

    if (args.pData.IsNull()) { SetOutputArrayCount<VulkanValidationCacheEXTInfo>(args.validationCache, kValidationCacheEXTArrayGetValidationCacheDataEXT, *out_pDataSize, &CommonObjectInfoTable::GetVkValidationCacheEXTInfo); }
}

void VulkanReplayConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadingRateImageNV&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImageView in_imageView = MapHandle<VulkanImageViewInfo>(args.imageView, &CommonObjectInfoTable::GetVkImageViewInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindShadingRateImageNV(in_commandBuffer, in_imageView, args.imageLayout);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindShadingRateImageNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_imageView, args.imageLayout);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportShadingRatePaletteNV&   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkShadingRatePaletteNV* in_pShadingRatePalettes = args.pShadingRatePalettes.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportShadingRatePaletteNV(in_commandBuffer, args.firstViewport, args.viewportCount, in_pShadingRatePalettes);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetViewportShadingRatePaletteNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstViewport, args.viewportCount, in_pShadingRatePalettes);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoarseSampleOrderNV&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCoarseSampleOrderCustomNV* in_pCustomSampleOrders = args.pCustomSampleOrders.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetCoarseSampleOrderNV(in_commandBuffer, args.sampleOrderType, args.customSampleOrderCount, in_pCustomSampleOrders);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetCoarseSampleOrderNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.sampleOrderType, args.customSampleOrderCount, in_pCustomSampleOrders);
    }
}

void VulkanReplayConsumer::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CreateAccelerationStructureNV&        args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pAccelerationStructure.IsNull()) { args.pAccelerationStructure.SetHandleLength(1); }
    VulkanAccelerationStructureNVInfo handle_info;
    args.pAccelerationStructure.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pAccelerationStructure.GetPointer());
    VkResult replay_result = OverrideCreateAccelerationStructureNV(GetDeviceTable(in_device->handle)->CreateAccelerationStructureNV, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pAccelerationStructure);
    CheckResult("vkCreateAccelerationStructureNV", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanAccelerationStructureNVInfo>(args.device, args.pAccelerationStructure.GetPointer(), args.pAccelerationStructure.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkAccelerationStructureNVInfo);
}

void VulkanReplayConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::DestroyAccelerationStructureNV&       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_accelerationStructure = GetObjectInfoTable().GetVkAccelerationStructureNVInfo(args.accelerationStructure);

    OverrideDestroyAccelerationStructureNV(GetDeviceTable(in_device->handle)->DestroyAccelerationStructureNV, in_device, in_accelerationStructure, &args.pAllocator);
    RemoveHandle(args.accelerationStructure, &CommonObjectInfoTable::RemoveVkAccelerationStructureNVInfo);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureMemoryRequirementsNV& args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    OverrideGetAccelerationStructureMemoryRequirementsNV(GetDeviceTable(in_device->handle)->GetAccelerationStructureMemoryRequirementsNV, in_device, &args.pInfo, &args.pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    args::BindAccelerationStructureMemoryNV&    args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pBindInfos.GetMetaStructPointer(), args.pBindInfos.GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindAccelerationStructureMemoryNV(GetDeviceTable(in_device->handle)->BindAccelerationStructureMemoryNV, args.result, in_device, args.bindInfoCount, &args.pBindInfos);
    CheckResult("vkBindAccelerationStructureMemoryNV", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructureNV&      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkAccelerationStructureInfoNV* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkBuffer in_instanceData = MapHandle<VulkanBufferInfo>(args.instanceData, &CommonObjectInfoTable::GetVkBufferInfo);
    VkAccelerationStructureNV in_dst = MapHandle<VulkanAccelerationStructureNVInfo>(args.dst, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    VkAccelerationStructureNV in_src = MapHandle<VulkanAccelerationStructureNVInfo>(args.src, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    VkBuffer in_scratch = MapHandle<VulkanBufferInfo>(args.scratch, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdBuildAccelerationStructureNV(in_commandBuffer, in_pInfo, in_instanceData, args.instanceOffset, args.update, in_dst, in_src, in_scratch, args.scratchOffset);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBuildAccelerationStructureNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo, in_instanceData, args.instanceOffset, args.update, in_dst, in_src, in_scratch, args.scratchOffset);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureNV&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkAccelerationStructureNV in_dst = MapHandle<VulkanAccelerationStructureNVInfo>(args.dst, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    VkAccelerationStructureNV in_src = MapHandle<VulkanAccelerationStructureNVInfo>(args.src, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);

    GetDeviceTable(in_commandBuffer)->CmdCopyAccelerationStructureNV(in_commandBuffer, in_dst, in_src, args.mode);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyAccelerationStructureNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_dst, in_src, args.mode);
    }
}

void VulkanReplayConsumer::Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysNV&                       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_raygenShaderBindingTableBuffer = MapHandle<VulkanBufferInfo>(args.raygenShaderBindingTableBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_missShaderBindingTableBuffer = MapHandle<VulkanBufferInfo>(args.missShaderBindingTableBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_hitShaderBindingTableBuffer = MapHandle<VulkanBufferInfo>(args.hitShaderBindingTableBuffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_callableShaderBindingTableBuffer = MapHandle<VulkanBufferInfo>(args.callableShaderBindingTableBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdTraceRaysNV(in_commandBuffer, in_raygenShaderBindingTableBuffer, args.raygenShaderBindingOffset, in_missShaderBindingTableBuffer, args.missShaderBindingOffset, args.missShaderBindingStride, in_hitShaderBindingTableBuffer, args.hitShaderBindingOffset, args.hitShaderBindingStride, in_callableShaderBindingTableBuffer, args.callableShaderBindingOffset, args.callableShaderBindingStride, args.width, args.height, args.depth);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdTraceRaysNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_raygenShaderBindingTableBuffer, args.raygenShaderBindingOffset, in_missShaderBindingTableBuffer, args.missShaderBindingOffset, args.missShaderBindingStride, in_hitShaderBindingTableBuffer, args.hitShaderBindingOffset, args.hitShaderBindingStride, in_callableShaderBindingTableBuffer, args.callableShaderBindingOffset, args.callableShaderBindingStride, args.width, args.height, args.depth);
    }
}

void VulkanReplayConsumer::Process_vkCreateRayTracingPipelinesNV(
    const ApiCallInfo&                          call_info,
    args::CreateRayTracingPipelinesNV&          args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_pipelineCache = GetObjectInfoTable().GetVkPipelineCacheInfo(args.pipelineCache);

    MapStructArrayHandles(args.pCreateInfos.GetMetaStructPointer(), args.pCreateInfos.GetLength(), GetObjectInfoTable());
    if (!args.pPipelines.IsNull()) { args.pPipelines.SetHandleLength(args.createInfoCount); }
    if (omitted_pipeline_cache_data_) { AllowCompileDuringPipelineCreation(args.createInfoCount, args.pCreateInfos.GetPointer()); }
    std::vector<VulkanPipelineInfo> handle_info(args.createInfoCount);
    for (size_t i = 0; i < args.createInfoCount; ++i) { args.pPipelines.SetConsumerData(i, &handle_info[i]); }

    PushRecaptureHandleIds(args.pPipelines.GetPointer(), args.pPipelines.GetLength());
    VkResult replay_result = OverrideCreateRayTracingPipelinesNV(GetDeviceTable(in_device->handle)->CreateRayTracingPipelinesNV, args.result, in_device, in_pipelineCache, args.createInfoCount, &args.pCreateInfos, &args.pAllocator, &args.pPipelines);
    CheckResult("vkCreateRayTracingPipelinesNV", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandles<VulkanPipelineInfo>(args.device, args.pPipelines.GetPointer(), args.pPipelines.GetLength(), args.pPipelines.GetHandlePointer(), args.createInfoCount, std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineInfo);
}

void VulkanReplayConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingShaderGroupHandlesKHR&   args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_pipeline = GetObjectInfoTable().GetVkPipelineInfo(args.pipeline);
    if (!args.pData.IsNull()) { args.pData.AllocateOutputData(args.dataSize); }

    VkResult replay_result = OverrideGetRayTracingShaderGroupHandlesKHR(GetDeviceTable(in_device->handle)->GetRayTracingShaderGroupHandlesKHR, args.result, in_device, in_pipeline, args.firstGroup, args.groupCount, args.dataSize, &args.pData);
    CheckResult("vkGetRayTracingShaderGroupHandlesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingShaderGroupHandlesNV&    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(args.pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);
    void* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(args.dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetRayTracingShaderGroupHandlesNV(in_device, in_pipeline, args.firstGroup, args.groupCount, args.dataSize, out_pData);
    CheckResult("vkGetRayTracingShaderGroupHandlesNV", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureHandleNV&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkAccelerationStructureNV in_accelerationStructure = MapHandle<VulkanAccelerationStructureNVInfo>(args.accelerationStructure, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    void* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(args.dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetAccelerationStructureHandleNV(in_device, in_accelerationStructure, args.dataSize, out_pData);
    CheckResult("vkGetAccelerationStructureHandleNV", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesNV& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkAccelerationStructureNV* in_pAccelerationStructures = MapHandles<VulkanAccelerationStructureNVInfo>(&args.pAccelerationStructures, args.accelerationStructureCount, &CommonObjectInfoTable::GetVkAccelerationStructureNVInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(args.queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(in_commandBuffer, args.accelerationStructureCount, in_pAccelerationStructures, args.queryType, in_queryPool, args.firstQuery);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWriteAccelerationStructuresPropertiesNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.accelerationStructureCount, &args.pAccelerationStructures, args.queryType, GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool), args.firstQuery);
    }
}

void VulkanReplayConsumer::Process_vkCompileDeferredNV(
    const ApiCallInfo&                          call_info,
    args::CompileDeferredNV&                    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(args.pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);

    VkResult replay_result = GetDeviceTable(in_device)->CompileDeferredNV(in_device, in_pipeline, args.shader);
    CheckResult("vkCompileDeferredNV", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetMemoryHostPointerPropertiesEXT&    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const void* in_pHostPointer = PreProcessExternalObject(args.pHostPointer, format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT, "vkGetMemoryHostPointerPropertiesEXT");
    VkMemoryHostPointerPropertiesEXT* out_pMemoryHostPointerProperties = args.pMemoryHostPointerProperties.IsNull() ? nullptr : args.pMemoryHostPointerProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT, nullptr });
    InitializeOutputStructPNext(&args.pMemoryHostPointerProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryHostPointerPropertiesEXT(in_device, args.handleType, in_pHostPointer, out_pMemoryHostPointerProperties);
    CheckResult("vkGetMemoryHostPointerPropertiesEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarkerAMD&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(args.dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteBufferMarkerAMD(in_commandBuffer, args.pipelineStage, in_dstBuffer, args.dstOffset, args.marker);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWriteBufferMarkerAMD(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.pipelineStage, in_dstBuffer, args.dstOffset, args.marker);
    }
}

void VulkanReplayConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarker2AMD&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_dstBuffer = MapHandle<VulkanBufferInfo>(args.dstBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteBufferMarker2AMD(in_commandBuffer, args.stage, in_dstBuffer, args.dstOffset, args.marker);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWriteBufferMarker2AMD(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.stage, in_dstBuffer, args.dstOffset, args.marker);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCalibrateableTimeDomainsEXT& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pTimeDomainCount = args.pTimeDomainCount.IsNull() ? nullptr : args.pTimeDomainCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT, &args.pTimeDomainCount, &args.pTimeDomains, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkTimeDomainKHR* out_pTimeDomains = args.pTimeDomains.IsNull() ? nullptr : args.pTimeDomains.AllocateOutputData(*out_pTimeDomainCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(in_physicalDevice, out_pTimeDomainCount, out_pTimeDomains);
    CheckResult("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", args.result, replay_result, call_info);

    if (args.pTimeDomains.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCalibrateableTimeDomainsEXT, *out_pTimeDomainCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    args::GetCalibratedTimestampsEXT&           args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCalibratedTimestampInfoKHR* in_pTimestampInfos = args.pTimestampInfos.GetPointer();
    MapStructArrayHandles(args.pTimestampInfos.GetMetaStructPointer(), args.pTimestampInfos.GetLength(), GetObjectInfoTable());
    uint64_t* out_pTimestamps = args.pTimestamps.IsNull() ? nullptr : args.pTimestamps.AllocateOutputData(args.timestampCount);
    uint64_t* out_pMaxDeviation = args.pMaxDeviation.IsNull() ? nullptr : args.pMaxDeviation.AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetCalibratedTimestampsEXT(in_device, args.timestampCount, in_pTimestampInfos, out_pTimestamps, out_pMaxDeviation);
    CheckResult("vkGetCalibratedTimestampsEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksNV&                   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksNV(in_commandBuffer, args.taskCount, args.firstTask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawMeshTasksNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.taskCount, args.firstTask);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectNV&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectNV(in_commandBuffer, in_buffer, args.offset, args.drawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawMeshTasksIndirectNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_buffer, args.offset, args.drawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountNV&      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(args.countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectCountNV(in_commandBuffer, in_buffer, args.offset, in_countBuffer, args.countBufferOffset, args.maxDrawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawMeshTasksIndirectCountNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_buffer, args.offset, in_countBuffer, args.countBufferOffset, args.maxDrawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetExclusiveScissorEnableNV&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBool32* in_pExclusiveScissorEnables = args.pExclusiveScissorEnables.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetExclusiveScissorEnableNV(in_commandBuffer, args.firstExclusiveScissor, args.exclusiveScissorCount, in_pExclusiveScissorEnables);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetExclusiveScissorEnableNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstExclusiveScissor, args.exclusiveScissorCount, in_pExclusiveScissorEnables);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetExclusiveScissorNV&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRect2D* in_pExclusiveScissors = args.pExclusiveScissors.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetExclusiveScissorNV(in_commandBuffer, args.firstExclusiveScissor, args.exclusiveScissorCount, in_pExclusiveScissors);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetExclusiveScissorNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstExclusiveScissor, args.exclusiveScissorCount, in_pExclusiveScissors);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCheckpointNV&                   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const void* in_pCheckpointMarker = PreProcessExternalObject(args.pCheckpointMarker, format::ApiCallId::ApiCall_vkCmdSetCheckpointNV, "vkCmdSetCheckpointNV");

    GetDeviceTable(in_commandBuffer)->CmdSetCheckpointNV(in_commandBuffer, in_pCheckpointMarker);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetCheckpointNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pCheckpointMarker);
    }
}

void VulkanReplayConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    args::GetQueueCheckpointDataNV&             args)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(args.queue, &CommonObjectInfoTable::GetVkQueueInfo);
    uint32_t* out_pCheckpointDataCount = args.pCheckpointDataCount.IsNull() ? nullptr : args.pCheckpointDataCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanQueueInfo>("vkGetQueueCheckpointDataNV", VK_SUCCESS, args.queue, kQueueArrayGetQueueCheckpointDataNV, &args.pCheckpointDataCount, &args.pCheckpointData, &CommonObjectInfoTable::GetVkQueueInfo));
    VkCheckpointDataNV* out_pCheckpointData = args.pCheckpointData.IsNull() ? nullptr : args.pCheckpointData.AllocateOutputData(*out_pCheckpointDataCount, VkCheckpointDataNV{ VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV, nullptr });

    GetDeviceTable(in_queue)->GetQueueCheckpointDataNV(in_queue, out_pCheckpointDataCount, out_pCheckpointData);

    if (args.pCheckpointData.IsNull()) { SetOutputArrayCount<VulkanQueueInfo>(args.queue, kQueueArrayGetQueueCheckpointDataNV, *out_pCheckpointDataCount, &CommonObjectInfoTable::GetVkQueueInfo); }
}

void VulkanReplayConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    args::GetQueueCheckpointData2NV&            args)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(args.queue, &CommonObjectInfoTable::GetVkQueueInfo);
    uint32_t* out_pCheckpointDataCount = args.pCheckpointDataCount.IsNull() ? nullptr : args.pCheckpointDataCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanQueueInfo>("vkGetQueueCheckpointData2NV", VK_SUCCESS, args.queue, kQueueArrayGetQueueCheckpointData2NV, &args.pCheckpointDataCount, &args.pCheckpointData, &CommonObjectInfoTable::GetVkQueueInfo));
    VkCheckpointData2NV* out_pCheckpointData = args.pCheckpointData.IsNull() ? nullptr : args.pCheckpointData.AllocateOutputData(*out_pCheckpointDataCount, VkCheckpointData2NV{ VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV, nullptr });

    GetDeviceTable(in_queue)->GetQueueCheckpointData2NV(in_queue, out_pCheckpointDataCount, out_pCheckpointData);

    if (args.pCheckpointData.IsNull()) { SetOutputArrayCount<VulkanQueueInfo>(args.queue, kQueueArrayGetQueueCheckpointData2NV, *out_pCheckpointDataCount, &CommonObjectInfoTable::GetVkQueueInfo); }
}

void VulkanReplayConsumer::Process_vkSetSwapchainPresentTimingQueueSizeEXT(
    const ApiCallInfo&                          call_info,
    args::SetSwapchainPresentTimingQueueSizeEXT& args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkSetSwapchainPresentTimingQueueSizeEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->SetSwapchainPresentTimingQueueSizeEXT(in_device, in_swapchain, args.size);
    CheckResult("vkSetSwapchainPresentTimingQueueSizeEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetSwapchainTimingPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainTimingPropertiesEXT&      args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetSwapchainTimingPropertiesEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }
    VkSwapchainTimingPropertiesEXT* out_pSwapchainTimingProperties = args.pSwapchainTimingProperties.IsNull() ? nullptr : args.pSwapchainTimingProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SWAPCHAIN_TIMING_PROPERTIES_EXT, nullptr });
    InitializeOutputStructPNext(&args.pSwapchainTimingProperties);
    uint64_t* out_pSwapchainTimingPropertiesCounter = args.pSwapchainTimingPropertiesCounter.IsNull() ? nullptr : args.pSwapchainTimingPropertiesCounter.AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainTimingPropertiesEXT(in_device, in_swapchain, out_pSwapchainTimingProperties, out_pSwapchainTimingPropertiesCounter);
    CheckResult("vkGetSwapchainTimingPropertiesEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetSwapchainTimeDomainPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetSwapchainTimeDomainPropertiesEXT&  args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetSwapchainTimeDomainPropertiesEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }
    VkSwapchainTimeDomainPropertiesEXT* out_pSwapchainTimeDomainProperties = args.pSwapchainTimeDomainProperties.IsNull() ? nullptr : args.pSwapchainTimeDomainProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SWAPCHAIN_TIME_DOMAIN_PROPERTIES_EXT, nullptr });
    InitializeOutputStructPNext(&args.pSwapchainTimeDomainProperties);
    uint64_t* out_pTimeDomainsCounter = args.pTimeDomainsCounter.IsNull() ? nullptr : args.pTimeDomainsCounter.AllocateOutputData(1, static_cast<uint64_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSwapchainTimeDomainPropertiesEXT(in_device, in_swapchain, out_pSwapchainTimeDomainProperties, out_pTimeDomainsCounter);
    CheckResult("vkGetSwapchainTimeDomainPropertiesEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPastPresentationTimingEXT(
    const ApiCallInfo&                          call_info,
    args::GetPastPresentationTimingEXT&         args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPastPresentationTimingEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPastPresentationTimingInfoEXT* in_pPastPresentationTimingInfo = args.pPastPresentationTimingInfo.GetPointer();
    MapStructHandles(args.pPastPresentationTimingInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkPastPresentationTimingPropertiesEXT* out_pPastPresentationTimingProperties = args.pPastPresentationTimingProperties.IsNull() ? nullptr : args.pPastPresentationTimingProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_PROPERTIES_EXT, nullptr });
    InitializeOutputStructPNext(&args.pPastPresentationTimingProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetPastPresentationTimingEXT(in_device, in_pPastPresentationTimingInfo, out_pPastPresentationTimingProperties);
    CheckResult("vkGetPastPresentationTimingEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    args::InitializePerformanceApiINTEL&        args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkInitializePerformanceApiInfoINTEL* in_pInitializeInfo = args.pInitializeInfo.GetPointer();
    MapStructHandles(args.pInitializeInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->InitializePerformanceApiINTEL(in_device, in_pInitializeInfo);
    CheckResult("vkInitializePerformanceApiINTEL", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    args::UninitializePerformanceApiINTEL&      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);

    GetDeviceTable(in_device)->UninitializePerformanceApiINTEL(in_device);
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceMarkerINTEL&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPerformanceMarkerInfoINTEL* in_pMarkerInfo = args.pMarkerInfo.GetPointer();
    MapStructHandles(args.pMarkerInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceMarkerINTEL(in_commandBuffer, in_pMarkerInfo);
    CheckResult("vkCmdSetPerformanceMarkerINTEL", args.result, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetPerformanceMarkerINTEL(call_info, GetInjectedDeviceCalls(in_commandBuffer), args.result, in_commandBuffer, in_pMarkerInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceStreamMarkerINTEL&   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPerformanceStreamMarkerInfoINTEL* in_pMarkerInfo = args.pMarkerInfo.GetPointer();
    MapStructHandles(args.pMarkerInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceStreamMarkerINTEL(in_commandBuffer, in_pMarkerInfo);
    CheckResult("vkCmdSetPerformanceStreamMarkerINTEL", args.result, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetPerformanceStreamMarkerINTEL(call_info, GetInjectedDeviceCalls(in_commandBuffer), args.result, in_commandBuffer, in_pMarkerInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceOverrideINTEL&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPerformanceOverrideInfoINTEL* in_pOverrideInfo = args.pOverrideInfo.GetPointer();
    MapStructHandles(args.pOverrideInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_commandBuffer)->CmdSetPerformanceOverrideINTEL(in_commandBuffer, in_pOverrideInfo);
    CheckResult("vkCmdSetPerformanceOverrideINTEL", args.result, replay_result, call_info);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetPerformanceOverrideINTEL(call_info, GetInjectedDeviceCalls(in_commandBuffer), args.result, in_commandBuffer, in_pOverrideInfo);
    }
}

void VulkanReplayConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    args::AcquirePerformanceConfigurationINTEL& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPerformanceConfigurationAcquireInfoINTEL* in_pAcquireInfo = args.pAcquireInfo.GetPointer();
    MapStructHandles(args.pAcquireInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pConfiguration.IsNull()) { args.pConfiguration.SetHandleLength(1); }
    VkPerformanceConfigurationINTEL* out_pConfiguration = args.pConfiguration.GetHandlePointer();

    PushRecaptureHandleId(args.pConfiguration.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->AcquirePerformanceConfigurationINTEL(in_device, in_pAcquireInfo, out_pConfiguration);
    CheckResult("vkAcquirePerformanceConfigurationINTEL", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanPerformanceConfigurationINTELInfo>(args.device, args.pConfiguration.GetPointer(), out_pConfiguration, &CommonObjectInfoTable::AddVkPerformanceConfigurationINTELInfo);
}

void VulkanReplayConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    args::ReleasePerformanceConfigurationINTEL& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPerformanceConfigurationINTEL in_configuration = MapHandle<VulkanPerformanceConfigurationINTELInfo>(args.configuration, &CommonObjectInfoTable::GetVkPerformanceConfigurationINTELInfo);

    VkResult replay_result = GetDeviceTable(in_device)->ReleasePerformanceConfigurationINTEL(in_device, in_configuration);
    CheckResult("vkReleasePerformanceConfigurationINTEL", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    args::QueueSetPerformanceConfigurationINTEL& args)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(args.queue, &CommonObjectInfoTable::GetVkQueueInfo);
    VkPerformanceConfigurationINTEL in_configuration = MapHandle<VulkanPerformanceConfigurationINTELInfo>(args.configuration, &CommonObjectInfoTable::GetVkPerformanceConfigurationINTELInfo);

    VkResult replay_result = GetDeviceTable(in_queue)->QueueSetPerformanceConfigurationINTEL(in_queue, in_configuration);
    CheckResult("vkQueueSetPerformanceConfigurationINTEL", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    args::GetPerformanceParameterINTEL&         args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPerformanceValueINTEL* out_pValue = args.pValue.IsNull() ? nullptr : args.pValue.AllocateOutputData(1);

    VkResult replay_result = GetDeviceTable(in_device)->GetPerformanceParameterINTEL(in_device, args.parameter, out_pValue);
    CheckResult("vkGetPerformanceParameterINTEL", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    args::SetLocalDimmingAMD&                   args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkSetLocalDimmingAMD for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapChain = MapHandle<VulkanSwapchainKHRInfo>(args.swapChain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapChain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapChain)->surface_id)->surface_creation_skipped) { return; }

    GetDeviceTable(in_device)->SetLocalDimmingAMD(in_device, in_swapChain, args.localDimmingEnable);
}

void VulkanReplayConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::CreateImagePipeSurfaceFUCHSIA&        args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkImagePipeSurfaceCreateInfoFUCHSIA* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = args.pSurface.GetHandlePointer();

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = GetInstanceTable(in_instance)->CreateImagePipeSurfaceFUCHSIA(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateImagePipeSurfaceFUCHSIA", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateMetalSurfaceEXT&                args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    args.pSurface.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = OverrideCreateMetalSurfaceEXT(GetInstanceTable(in_instance->handle)->CreateMetalSurfaceEXT, args.result, in_instance, &args.pCreateInfo, &args.pAllocator, &args.pSurface);
    CheckResult("vkCreateMetalSurfaceEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), args.pSurface.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    args::GetBufferDeviceAddressEXT&            args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetBufferDeviceAddress(GetDeviceTable(in_device->handle)->GetBufferDeviceAddressEXT, args.result, in_device, &args.pInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceToolPropertiesEXT&   args)
{
    auto in_physicalDevice = GetObjectInfoTable().GetVkPhysicalDeviceInfo(args.physicalDevice);
    args.pToolCount.IsNull() ? nullptr : args.pToolCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceToolPropertiesEXT", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT, &args.pToolCount, &args.pToolProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    if (!args.pToolProperties.IsNull()) { args.pToolProperties.AllocateOutputData(*args.pToolCount.GetOutputPointer(), VkPhysicalDeviceToolProperties{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES, nullptr }); }

    VkResult replay_result = OverrideGetPhysicalDeviceToolProperties(GetInstanceTable(in_physicalDevice->handle)->GetPhysicalDeviceToolPropertiesEXT, args.result, in_physicalDevice, &args.pToolCount, &args.pToolProperties);
    CheckResult("vkGetPhysicalDeviceToolPropertiesEXT", args.result, replay_result, call_info);

    if (args.pToolProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceToolPropertiesEXT, *args.pToolCount.GetOutputPointer(), &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeMatrixPropertiesNV& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkCooperativeMatrixPropertiesNV* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount, VkCooperativeMatrixPropertiesNV{ VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesNV(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", args.result, replay_result, call_info);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixPropertiesNV, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pCombinationCount = args.pCombinationCount.IsNull() ? nullptr : args.pCombinationCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV, &args.pCombinationCount, &args.pCombinations, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkFramebufferMixedSamplesCombinationNV* out_pCombinations = args.pCombinations.IsNull() ? nullptr : args.pCombinations.AllocateOutputData(*out_pCombinationCount, VkFramebufferMixedSamplesCombinationNV{ VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(in_physicalDevice, out_pCombinationCount, out_pCombinations);
    CheckResult("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", args.result, replay_result, call_info);

    if (args.pCombinations.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV, *out_pCombinationCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceSurfacePresentModes2EXT& args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetPhysicalDeviceSurfacePresentModes2EXT for offscreen.");
        return;
    }
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = args.pSurfaceInfo.GetPointer();
    MapStructHandles(args.pSurfaceInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (args.pSurfaceInfo.GetPointer()->surface == VK_NULL_HANDLE) { return; }
    auto in_pSurfaceInfo_meta = args.pSurfaceInfo.GetMetaStructPointer();
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    uint32_t* out_pPresentModeCount = args.pPresentModeCount.IsNull() ? nullptr : args.pPresentModeCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceSurfacePresentModes2EXT", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT, &args.pPresentModeCount, &args.pPresentModes, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkPresentModeKHR* out_pPresentModes = args.pPresentModes.IsNull() ? nullptr : args.pPresentModes.AllocateOutputData(*out_pPresentModeCount);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceSurfacePresentModes2EXT(in_physicalDevice, in_pSurfaceInfo, out_pPresentModeCount, out_pPresentModes);
    CheckResult("vkGetPhysicalDeviceSurfacePresentModes2EXT", args.result, replay_result, call_info);

    if (args.pPresentModes.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceSurfacePresentModes2EXT, *out_pPresentModeCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    args::AcquireFullScreenExclusiveModeEXT&    args)
{
    if ((options_.swapchain_option == util::SwapchainOption::kOffscreen) || (options_.force_windowed_origin == true) || (options_.force_windowed == true))
    {
        GFXRECON_LOG_DEBUG("Skip vkAcquireFullScreenExclusiveModeEXT for offscreen or force windowed mode.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->AcquireFullScreenExclusiveModeEXT(in_device, in_swapchain);
    CheckResult("vkAcquireFullScreenExclusiveModeEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseFullScreenExclusiveModeEXT&    args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkReleaseFullScreenExclusiveModeEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }

    VkResult replay_result = GetDeviceTable(in_device)->ReleaseFullScreenExclusiveModeEXT(in_device, in_swapchain);
    CheckResult("vkReleaseFullScreenExclusiveModeEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    args::GetDeviceGroupSurfacePresentModes2EXT& args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetDeviceGroupSurfacePresentModes2EXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPhysicalDeviceSurfaceInfo2KHR* in_pSurfaceInfo = args.pSurfaceInfo.GetPointer();
    MapStructHandles(args.pSurfaceInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (args.pSurfaceInfo.GetPointer()->surface == VK_NULL_HANDLE) { return; }
    auto in_pSurfaceInfo_meta = args.pSurfaceInfo.GetMetaStructPointer();
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(in_pSurfaceInfo_meta->surface)->surface_creation_skipped) { return; }
    VkDeviceGroupPresentModeFlagsKHR* out_pModes = args.pModes.IsNull() ? nullptr : args.pModes.AllocateOutputData(1, static_cast<VkDeviceGroupPresentModeFlagsKHR>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceGroupSurfacePresentModes2EXT(in_device, in_pSurfaceInfo, out_pModes);
    CheckResult("vkGetDeviceGroupSurfacePresentModes2EXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateHeadlessSurfaceEXT&             args)
{
    auto in_instance = GetObjectInfoTable().GetVkInstanceInfo(args.instance);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VulkanSurfaceKHRInfo handle_info;
    args.pSurface.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = OverrideCreateHeadlessSurfaceEXT(GetInstanceTable(in_instance->handle)->CreateHeadlessSurfaceEXT, args.result, in_instance, &args.pCreateInfo, &args.pAllocator, &args.pSurface);
    CheckResult("vkCreateHeadlessSurfaceEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), args.pSurface.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleEXT&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineStippleEXT(in_commandBuffer, args.lineStippleFactor, args.lineStipplePattern);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetLineStippleEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.lineStippleFactor, args.lineStipplePattern);
    }
}

void VulkanReplayConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    args::ResetQueryPoolEXT&                    args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool);

    OverrideResetQueryPool(GetDeviceTable(in_device->handle)->ResetQueryPoolEXT, in_device, in_queryPool, args.firstQuery, args.queryCount);
}

void VulkanReplayConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetCullModeEXT&                    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCullModeEXT(in_commandBuffer, args.cullMode);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetCullModeEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.cullMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetFrontFaceEXT&                   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetFrontFaceEXT(in_commandBuffer, args.frontFace);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetFrontFaceEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.frontFace);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveTopologyEXT&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveTopologyEXT(in_commandBuffer, args.primitiveTopology);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetPrimitiveTopologyEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.primitiveTopology);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWithCountEXT&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkViewport* in_pViewports = args.pViewports.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWithCountEXT(in_commandBuffer, args.viewportCount, in_pViewports);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetViewportWithCountEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.viewportCount, in_pViewports);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissorWithCountEXT&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRect2D* in_pScissors = args.pScissors.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetScissorWithCountEXT(in_commandBuffer, args.scissorCount, in_pScissors);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetScissorWithCountEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.scissorCount, in_pScissors);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2EXT&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuffer* in_pBuffers = MapHandles<VulkanBufferInfo>(&args.pBuffers, args.bindingCount, &CommonObjectInfoTable::GetVkBufferInfo);
    const VkDeviceSize* in_pOffsets = args.pOffsets.GetPointer();
    const VkDeviceSize* in_pSizes = args.pSizes.GetPointer();
    const VkDeviceSize* in_pStrides = args.pStrides.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBindVertexBuffers2EXT(in_commandBuffer, args.firstBinding, args.bindingCount, in_pBuffers, in_pOffsets, in_pSizes, in_pStrides);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindVertexBuffers2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstBinding, args.bindingCount, &args.pBuffers, in_pOffsets, in_pSizes, in_pStrides);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthTestEnableEXT&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthTestEnableEXT(in_commandBuffer, args.depthTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthTestEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthWriteEnableEXT&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthWriteEnableEXT(in_commandBuffer, args.depthWriteEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthWriteEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthWriteEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthCompareOpEXT&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthCompareOpEXT(in_commandBuffer, args.depthCompareOp);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthCompareOpEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthCompareOp);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBoundsTestEnableEXT&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBoundsTestEnableEXT(in_commandBuffer, args.depthBoundsTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthBoundsTestEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthBoundsTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilTestEnableEXT&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilTestEnableEXT(in_commandBuffer, args.stencilTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetStencilTestEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.stencilTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilOpEXT&                   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetStencilOpEXT(in_commandBuffer, args.faceMask, args.failOp, args.passOp, args.depthFailOp, args.compareOp);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetStencilOpEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.faceMask, args.failOp, args.passOp, args.depthFailOp, args.compareOp);
    }
}

void VulkanReplayConsumer::Process_vkCopyMemoryToImageEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToImageEXT&                 args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCopyMemoryToImageInfo* in_pCopyMemoryToImageInfo = args.pCopyMemoryToImageInfo.GetPointer();
    MapStructHandles(args.pCopyMemoryToImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMemoryToImageEXT(in_device, in_pCopyMemoryToImageInfo);
    CheckResult("vkCopyMemoryToImageEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyImageToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CopyImageToMemoryEXT&                 args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCopyImageToMemoryInfo* in_pCopyImageToMemoryInfo = args.pCopyImageToMemoryInfo.GetPointer();
    MapStructHandles(args.pCopyImageToMemoryInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyImageToMemoryEXT(in_device, in_pCopyImageToMemoryInfo);
    CheckResult("vkCopyImageToMemoryEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyImageToImageEXT(
    const ApiCallInfo&                          call_info,
    args::CopyImageToImageEXT&                  args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkCopyImageToImageInfo* in_pCopyImageToImageInfo = args.pCopyImageToImageInfo.GetPointer();
    MapStructHandles(args.pCopyImageToImageInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyImageToImageEXT(in_device, in_pCopyImageToImageInfo);
    CheckResult("vkCopyImageToImageEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkTransitionImageLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::TransitionImageLayoutEXT&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkHostImageLayoutTransitionInfo* in_pTransitions = args.pTransitions.GetPointer();
    MapStructArrayHandles(args.pTransitions.GetMetaStructPointer(), args.pTransitions.GetLength(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->TransitionImageLayoutEXT(in_device, args.transitionCount, in_pTransitions);
    CheckResult("vkTransitionImageLayoutEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    args::GetImageSubresourceLayout2EXT&        args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkImage in_image = MapHandle<VulkanImageInfo>(args.image, &CommonObjectInfoTable::GetVkImageInfo);
    const VkImageSubresource2* in_pSubresource = args.pSubresource.GetPointer();
    MapStructHandles(args.pSubresource.GetMetaStructPointer(), GetObjectInfoTable());
    VkSubresourceLayout2* out_pLayout = args.pLayout.IsNull() ? nullptr : args.pLayout.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2, nullptr });
    InitializeOutputStructPNext(&args.pLayout);

    GetDeviceTable(in_device)->GetImageSubresourceLayout2EXT(in_device, in_image, in_pSubresource, out_pLayout);
}

void VulkanReplayConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseSwapchainImagesEXT&            args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkReleaseSwapchainImagesEXT for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkReleaseSwapchainImagesInfoKHR* in_pReleaseInfo = args.pReleaseInfo.GetPointer();
    MapStructHandles(args.pReleaseInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ReleaseSwapchainImagesEXT(in_device, in_pReleaseInfo);
    CheckResult("vkReleaseSwapchainImagesEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    args::GetGeneratedCommandsMemoryRequirementsNV& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkGeneratedCommandsMemoryRequirementsInfoNV* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    GetDeviceTable(in_device)->GetGeneratedCommandsMemoryRequirementsNV(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsNV&     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkGeneratedCommandsInfoNV* in_pGeneratedCommandsInfo = args.pGeneratedCommandsInfo.GetPointer();
    MapStructHandles(args.pGeneratedCommandsInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdPreprocessGeneratedCommandsNV(in_commandBuffer, in_pGeneratedCommandsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPreprocessGeneratedCommandsNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pGeneratedCommandsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsNV&        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkGeneratedCommandsInfoNV* in_pGeneratedCommandsInfo = args.pGeneratedCommandsInfo.GetPointer();
    MapStructHandles(args.pGeneratedCommandsInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdExecuteGeneratedCommandsNV(in_commandBuffer, args.isPreprocessed, in_pGeneratedCommandsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdExecuteGeneratedCommandsNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.isPreprocessed, in_pGeneratedCommandsInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipelineShaderGroupNV&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(args.pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindPipelineShaderGroupNV(in_commandBuffer, args.pipelineBindPoint, in_pipeline, args.groupIndex);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindPipelineShaderGroupNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.pipelineBindPoint, in_pipeline, args.groupIndex);
    }
}

void VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectCommandsLayoutNV&       args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkIndirectCommandsLayoutCreateInfoNV* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pIndirectCommandsLayout.IsNull()) { args.pIndirectCommandsLayout.SetHandleLength(1); }
    VkIndirectCommandsLayoutNV* out_pIndirectCommandsLayout = args.pIndirectCommandsLayout.GetHandlePointer();

    PushRecaptureHandleId(args.pIndirectCommandsLayout.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateIndirectCommandsLayoutNV(in_device, in_pCreateInfo, in_pAllocator, out_pIndirectCommandsLayout);
    CheckResult("vkCreateIndirectCommandsLayoutNV", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanIndirectCommandsLayoutNVInfo>(args.device, args.pIndirectCommandsLayout.GetPointer(), out_pIndirectCommandsLayout, &CommonObjectInfoTable::AddVkIndirectCommandsLayoutNVInfo);
}

void VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectCommandsLayoutNV&      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkIndirectCommandsLayoutNV in_indirectCommandsLayout = MapHandle<VulkanIndirectCommandsLayoutNVInfo>(args.indirectCommandsLayout, &CommonObjectInfoTable::GetVkIndirectCommandsLayoutNVInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyIndirectCommandsLayoutNV(in_device, in_indirectCommandsLayout, in_pAllocator);
    RemoveHandle(args.indirectCommandsLayout, &CommonObjectInfoTable::RemoveVkIndirectCommandsLayoutNVInfo);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBias2EXT&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDepthBiasInfoEXT* in_pDepthBiasInfo = args.pDepthBiasInfo.GetPointer();
    MapStructHandles(args.pDepthBiasInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBias2EXT(in_commandBuffer, in_pDepthBiasInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthBias2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pDepthBiasInfo);
    }
}

void VulkanReplayConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::AcquireDrmDisplayEXT&                 args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(args.display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->AcquireDrmDisplayEXT(in_physicalDevice, args.drmFd, in_display);
    CheckResult("vkAcquireDrmDisplayEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::GetDrmDisplayEXT&                     args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    if (!args.display.IsNull()) { args.display.SetHandleLength(1); }
    VkDisplayKHR* out_display = args.display.GetHandlePointer();

    PushRecaptureHandleId(args.display.GetPointer());
    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetDrmDisplayEXT(in_physicalDevice, args.drmFd, args.connectorId, out_display);
    CheckResult("vkGetDrmDisplayEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDisplayKHRInfo>(args.physicalDevice, args.display.GetPointer(), out_display, &CommonObjectInfoTable::AddVkDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    args::CreatePrivateDataSlotEXT&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPrivateDataSlotCreateInfo* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pPrivateDataSlot.IsNull()) { args.pPrivateDataSlot.SetHandleLength(1); }
    VkPrivateDataSlot* out_pPrivateDataSlot = args.pPrivateDataSlot.GetHandlePointer();

    PushRecaptureHandleId(args.pPrivateDataSlot.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreatePrivateDataSlotEXT(in_device, in_pCreateInfo, in_pAllocator, out_pPrivateDataSlot);
    CheckResult("vkCreatePrivateDataSlotEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanPrivateDataSlotInfo>(args.device, args.pPrivateDataSlot.GetPointer(), out_pPrivateDataSlot, &CommonObjectInfoTable::AddVkPrivateDataSlotInfo);
}

void VulkanReplayConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyPrivateDataSlotEXT&            args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(args.privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyPrivateDataSlotEXT(in_device, in_privateDataSlot, in_pAllocator);
    RemoveHandle(args.privateDataSlot, &CommonObjectInfoTable::RemoveVkPrivateDataSlotInfo);
}

void VulkanReplayConsumer::Process_vkSetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    args::SetPrivateDataEXT&                    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    uint64_t in_objectHandle = MapHandle(args.objectHandle, args.objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(args.privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);

    VkResult replay_result = GetDeviceTable(in_device)->SetPrivateDataEXT(in_device, args.objectType, in_objectHandle, in_privateDataSlot, args.data);
    CheckResult("vkSetPrivateDataEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    args::GetPrivateDataEXT&                    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    uint64_t in_objectHandle = MapHandle(args.objectHandle, args.objectType);
    VkPrivateDataSlot in_privateDataSlot = MapHandle<VulkanPrivateDataSlotInfo>(args.privateDataSlot, &CommonObjectInfoTable::GetVkPrivateDataSlotInfo);
    uint64_t* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(1, static_cast<uint64_t>(0));

    GetDeviceTable(in_device)->GetPrivateDataEXT(in_device, args.objectType, in_objectHandle, in_privateDataSlot, out_pData);
}

void VulkanReplayConsumer::Process_vkQueueSetPerfHintQCOM(
    const ApiCallInfo&                          call_info,
    args::QueueSetPerfHintQCOM&                 args)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(args.queue, &CommonObjectInfoTable::GetVkQueueInfo);
    const VkPerfHintInfoQCOM* in_pPerfHintInfo = args.pPerfHintInfo.GetPointer();
    MapStructHandles(args.pPerfHintInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_queue)->QueueSetPerfHintQCOM(in_queue, in_pPerfHintInfo);
    CheckResult("vkQueueSetPerfHintQCOM", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdDispatchTileQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchTileQCOM&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDispatchTileInfoQCOM* in_pDispatchTileInfo = args.pDispatchTileInfo.GetPointer();
    MapStructHandles(args.pDispatchTileInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDispatchTileQCOM(in_commandBuffer, in_pDispatchTileInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDispatchTileQCOM(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pDispatchTileInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdBeginPerTileExecutionQCOM&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPerTileBeginInfoQCOM* in_pPerTileBeginInfo = args.pPerTileBeginInfo.GetPointer();
    MapStructHandles(args.pPerTileBeginInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginPerTileExecutionQCOM(in_commandBuffer, in_pPerTileBeginInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginPerTileExecutionQCOM(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pPerTileBeginInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdEndPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdEndPerTileExecutionQCOM&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkPerTileEndInfoQCOM* in_pPerTileEndInfo = args.pPerTileEndInfo.GetPointer();
    MapStructHandles(args.pPerTileEndInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdEndPerTileExecutionQCOM(in_commandBuffer, in_pPerTileEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndPerTileExecutionQCOM(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pPerTileEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutSizeEXT(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutSizeEXT&        args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDescriptorSetLayout in_layout = MapHandle<VulkanDescriptorSetLayoutInfo>(args.layout, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo);
    VkDeviceSize* out_pLayoutSizeInBytes = args.pLayoutSizeInBytes.IsNull() ? nullptr : args.pLayoutSizeInBytes.AllocateOutputData(1, static_cast<VkDeviceSize>(0));

    GetDeviceTable(in_device)->GetDescriptorSetLayoutSizeEXT(in_device, in_layout, out_pLayoutSizeInBytes);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutBindingOffsetEXT(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutBindingOffsetEXT& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDescriptorSetLayout in_layout = MapHandle<VulkanDescriptorSetLayoutInfo>(args.layout, &CommonObjectInfoTable::GetVkDescriptorSetLayoutInfo);
    VkDeviceSize* out_pOffset = args.pOffset.IsNull() ? nullptr : args.pOffset.AllocateOutputData(1, static_cast<VkDeviceSize>(0));

    GetDeviceTable(in_device)->GetDescriptorSetLayoutBindingOffsetEXT(in_device, in_layout, args.binding, out_pOffset);
}

void VulkanReplayConsumer::Process_vkGetDescriptorEXT(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorEXT&                     args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pDescriptorInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pDescriptor.IsNull()) { args.pDescriptor.AllocateOutputData(args.dataSize); }

    OverrideGetDescriptorEXT(GetDeviceTable(in_device->handle)->GetDescriptorEXT, in_device, &args.pDescriptorInfo, args.dataSize, &args.pDescriptor);
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBuffersEXT&          args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructArrayHandles(args.pBindingInfos.GetMetaStructPointer(), args.pBindingInfos.GetLength(), GetObjectInfoTable());

    OverrideCmdBindDescriptorBuffersEXT(GetDeviceTable(in_commandBuffer->handle)->CmdBindDescriptorBuffersEXT, in_commandBuffer, args.bufferCount, &args.pBindingInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindDescriptorBuffersEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.bufferCount, args.pBindingInfos.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDescriptorBufferOffsetsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDescriptorBufferOffsetsEXT&     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipelineLayout in_layout = MapHandle<VulkanPipelineLayoutInfo>(args.layout, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);
    const uint32_t* in_pBufferIndices = args.pBufferIndices.GetPointer();
    const VkDeviceSize* in_pOffsets = args.pOffsets.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetDescriptorBufferOffsetsEXT(in_commandBuffer, args.pipelineBindPoint, in_layout, args.firstSet, args.setCount, in_pBufferIndices, in_pOffsets);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDescriptorBufferOffsetsEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.pipelineBindPoint, in_layout, args.firstSet, args.setCount, in_pBufferIndices, in_pOffsets);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBufferEmbeddedSamplersEXT& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipelineLayout in_layout = MapHandle<VulkanPipelineLayoutInfo>(args.layout, &CommonObjectInfoTable::GetVkPipelineLayoutInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindDescriptorBufferEmbeddedSamplersEXT(in_commandBuffer, args.pipelineBindPoint, in_layout, args.set);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.pipelineBindPoint, in_layout, args.set);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetFragmentShadingRateEnumNV&      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkFragmentShadingRateCombinerOpKHR* in_combinerOps = args.combinerOps.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetFragmentShadingRateEnumNV(in_commandBuffer, args.shadingRate, in_combinerOps);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetFragmentShadingRateEnumNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.shadingRate, in_combinerOps);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    args::GetDeviceFaultInfoEXT&                args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeviceFaultCountsEXT* out_pFaultCounts = args.pFaultCounts.IsNull() ? nullptr : args.pFaultCounts.AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT, nullptr });
    InitializeOutputStructPNext(&args.pFaultCounts);
    VkDeviceFaultInfoEXT* out_pFaultInfo = args.pFaultInfo.IsNull() ? nullptr : args.pFaultInfo.AllocateOutputData(1, { VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT, nullptr });
    InitializeOutputStructPNext(&args.pFaultInfo);

    VkResult replay_result = GetDeviceTable(in_device)->GetDeviceFaultInfoEXT(in_device, out_pFaultCounts, out_pFaultInfo);
    CheckResult("vkGetDeviceFaultInfoEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    args::AcquireWinrtDisplayNV&                args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    VkDisplayKHR in_display = MapHandle<VulkanDisplayKHRInfo>(args.display, &CommonObjectInfoTable::GetVkDisplayKHRInfo);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->AcquireWinrtDisplayNV(in_physicalDevice, in_display);
    CheckResult("vkAcquireWinrtDisplayNV", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    args::GetWinrtDisplayNV&                    args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    if (!args.pDisplay.IsNull()) { args.pDisplay.SetHandleLength(1); }
    VkDisplayKHR* out_pDisplay = args.pDisplay.GetHandlePointer();

    PushRecaptureHandleId(args.pDisplay.GetPointer());
    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetWinrtDisplayNV(in_physicalDevice, args.deviceRelativeId, out_pDisplay);
    CheckResult("vkGetWinrtDisplayNV", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDisplayKHRInfo>(args.physicalDevice, args.pDisplay.GetPointer(), out_pDisplay, &CommonObjectInfoTable::AddVkDisplayKHRInfo);
}

void VulkanReplayConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDirectFBSurfaceEXT&             args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkDirectFBSurfaceCreateInfoEXT* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = args.pSurface.GetHandlePointer();

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = GetInstanceTable(in_instance)->CreateDirectFBSurfaceEXT(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateDirectFBSurfaceEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceDirectFBPresentationSupportEXT& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    IDirectFB* in_dfb = static_cast<IDirectFB*>(PreProcessExternalObject(args.dfb, format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT"));

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceDirectFBPresentationSupportEXT(in_physicalDevice, args.queueFamilyIndex, in_dfb);
}

void VulkanReplayConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetVertexInputEXT&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkVertexInputBindingDescription2EXT* in_pVertexBindingDescriptions = args.pVertexBindingDescriptions.GetPointer();
    MapStructArrayHandles(args.pVertexBindingDescriptions.GetMetaStructPointer(), args.pVertexBindingDescriptions.GetLength(), GetObjectInfoTable());
    const VkVertexInputAttributeDescription2EXT* in_pVertexAttributeDescriptions = args.pVertexAttributeDescriptions.GetPointer();
    MapStructArrayHandles(args.pVertexAttributeDescriptions.GetMetaStructPointer(), args.pVertexAttributeDescriptions.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetVertexInputEXT(in_commandBuffer, args.vertexBindingDescriptionCount, in_pVertexBindingDescriptions, args.vertexAttributeDescriptionCount, in_pVertexAttributeDescriptions);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetVertexInputEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.vertexBindingDescriptionCount, &args.pVertexBindingDescriptions, args.vertexAttributeDescriptionCount, &args.pVertexAttributeDescriptions);
    }
}

void VulkanReplayConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::GetMemoryZirconHandleFUCHSIA&         args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryGetZirconHandleInfoFUCHSIA* in_pGetZirconHandleInfo = args.pGetZirconHandleInfo.GetPointer();
    MapStructHandles(args.pGetZirconHandleInfo.GetMetaStructPointer(), GetObjectInfoTable());
    zx_handle_t* out_pZirconHandle = args.pZirconHandle.IsNull() ? nullptr : args.pZirconHandle.AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryZirconHandleFUCHSIA(in_device, in_pGetZirconHandleInfo, out_pZirconHandle);
    CheckResult("vkGetMemoryZirconHandleFUCHSIA", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::GetMemoryZirconHandlePropertiesFUCHSIA& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkMemoryZirconHandlePropertiesFUCHSIA* out_pMemoryZirconHandleProperties = args.pMemoryZirconHandleProperties.IsNull() ? nullptr : args.pMemoryZirconHandleProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA, nullptr });
    InitializeOutputStructPNext(&args.pMemoryZirconHandleProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryZirconHandlePropertiesFUCHSIA(in_device, args.handleType, args.zirconHandle, out_pMemoryZirconHandleProperties);
    CheckResult("vkGetMemoryZirconHandlePropertiesFUCHSIA", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::ImportSemaphoreZirconHandleFUCHSIA&   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkImportSemaphoreZirconHandleInfoFUCHSIA* in_pImportSemaphoreZirconHandleInfo = args.pImportSemaphoreZirconHandleInfo.GetPointer();
    MapStructHandles(args.pImportSemaphoreZirconHandleInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ImportSemaphoreZirconHandleFUCHSIA(in_device, in_pImportSemaphoreZirconHandleInfo);
    CheckResult("vkImportSemaphoreZirconHandleFUCHSIA", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::GetSemaphoreZirconHandleFUCHSIA&      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkSemaphoreGetZirconHandleInfoFUCHSIA* in_pGetZirconHandleInfo = args.pGetZirconHandleInfo.GetPointer();
    MapStructHandles(args.pGetZirconHandleInfo.GetMetaStructPointer(), GetObjectInfoTable());
    zx_handle_t* out_pZirconHandle = args.pZirconHandle.IsNull() ? nullptr : args.pZirconHandle.AllocateOutputData(1, static_cast<uint32_t>(0));

    VkResult replay_result = GetDeviceTable(in_device)->GetSemaphoreZirconHandleFUCHSIA(in_device, in_pGetZirconHandleInfo, out_pZirconHandle);
    CheckResult("vkGetSemaphoreZirconHandleFUCHSIA", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdBindInvocationMaskHUAWEI&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkImageView in_imageView = MapHandle<VulkanImageViewInfo>(args.imageView, &CommonObjectInfoTable::GetVkImageViewInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindInvocationMaskHUAWEI(in_commandBuffer, in_imageView, args.imageLayout);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindInvocationMaskHUAWEI(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_imageView, args.imageLayout);
    }
}

void VulkanReplayConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    args::GetMemoryRemoteAddressNV&             args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pMemoryGetRemoteAddressInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkRemoteAddressNV* out_pAddress = args.pAddress.IsNull() ? nullptr : reinterpret_cast<VkRemoteAddressNV*>(args.pAddress.AllocateOutputData(1));

    VkResult replay_result = OverrideGetMemoryRemoteAddressNV(GetDeviceTable(in_device->handle)->GetMemoryRemoteAddressNV, args.result, in_device, &args.pMemoryGetRemoteAddressInfo, out_pAddress);
    CheckResult("vkGetMemoryRemoteAddressNV", args.result, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*args.pAddress.GetPointer()), static_cast<void*>(*out_pAddress), format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV, "vkGetMemoryRemoteAddressNV");
}

void VulkanReplayConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPatchControlPointsEXT&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPatchControlPointsEXT(in_commandBuffer, args.patchControlPoints);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetPatchControlPointsEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.patchControlPoints);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizerDiscardEnableEXT&     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizerDiscardEnableEXT(in_commandBuffer, args.rasterizerDiscardEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetRasterizerDiscardEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.rasterizerDiscardEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBiasEnableEXT&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthBiasEnableEXT(in_commandBuffer, args.depthBiasEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthBiasEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthBiasEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLogicOpEXT&                     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLogicOpEXT(in_commandBuffer, args.logicOp);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetLogicOpEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.logicOp);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartEnableEXT&      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveRestartEnableEXT(in_commandBuffer, args.primitiveRestartEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetPrimitiveRestartEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.primitiveRestartEnable);
    }
}

void VulkanReplayConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    args::CreateScreenSurfaceQNX&               args)
{
    VkInstance in_instance = MapHandle<VulkanInstanceInfo>(args.instance, &CommonObjectInfoTable::GetVkInstanceInfo);
    const VkScreenSurfaceCreateInfoQNX* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pSurface.IsNull()) { args.pSurface.SetHandleLength(1); }
    VkSurfaceKHR* out_pSurface = args.pSurface.GetHandlePointer();

    PushRecaptureHandleId(args.pSurface.GetPointer());
    VkResult replay_result = GetInstanceTable(in_instance)->CreateScreenSurfaceQNX(in_instance, in_pCreateInfo, in_pAllocator, out_pSurface);
    CheckResult("vkCreateScreenSurfaceQNX", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanSurfaceKHRInfo>(args.instance, args.pSurface.GetPointer(), out_pSurface, &CommonObjectInfoTable::AddVkSurfaceKHRInfo);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceScreenPresentationSupportQNX& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    struct _screen_window* in_window = static_cast<struct _screen_window*>(PreProcessExternalObject(args.window, format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX, "vkGetPhysicalDeviceScreenPresentationSupportQNX"));

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceScreenPresentationSupportQNX(in_physicalDevice, args.queueFamilyIndex, in_window);
}

void VulkanReplayConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorWriteEnableEXT&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBool32* in_pColorWriteEnables = args.pColorWriteEnables.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorWriteEnableEXT(in_commandBuffer, args.attachmentCount, in_pColorWriteEnables);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetColorWriteEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.attachmentCount, in_pColorWriteEnables);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMultiEXT&                      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkMultiDrawInfoEXT* in_pVertexInfo = args.pVertexInfo.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDrawMultiEXT(in_commandBuffer, args.drawCount, in_pVertexInfo, args.instanceCount, args.firstInstance, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawMultiEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.drawCount, in_pVertexInfo, args.instanceCount, args.firstInstance, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMultiIndexedEXT&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkMultiDrawIndexedInfoEXT* in_pIndexInfo = args.pIndexInfo.GetPointer();
    const int32_t* in_pVertexOffset = args.pVertexOffset.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdDrawMultiIndexedEXT(in_commandBuffer, args.drawCount, in_pIndexInfo, args.instanceCount, args.firstInstance, args.stride, in_pVertexOffset);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawMultiIndexedEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.drawCount, in_pIndexInfo, args.instanceCount, args.firstInstance, args.stride, in_pVertexOffset);
    }
}

void VulkanReplayConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CreateMicromapEXT&                    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMicromapCreateInfoEXT* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pMicromap.IsNull()) { args.pMicromap.SetHandleLength(1); }
    VkMicromapEXT* out_pMicromap = args.pMicromap.GetHandlePointer();

    PushRecaptureHandleId(args.pMicromap.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateMicromapEXT(in_device, in_pCreateInfo, in_pAllocator, out_pMicromap);
    CheckResult("vkCreateMicromapEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanMicromapEXTInfo>(args.device, args.pMicromap.GetPointer(), out_pMicromap, &CommonObjectInfoTable::AddVkMicromapEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyMicromapEXT&                   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkMicromapEXT in_micromap = MapHandle<VulkanMicromapEXTInfo>(args.micromap, &CommonObjectInfoTable::GetVkMicromapEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyMicromapEXT(in_device, in_micromap, in_pAllocator);
    RemoveHandle(args.micromap, &CommonObjectInfoTable::RemoveVkMicromapEXTInfo);
}

void VulkanReplayConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBuildMicromapsEXT&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkMicromapBuildInfoEXT* in_pInfos = args.pInfos.GetPointer();
    MapStructArrayHandles(args.pInfos.GetMetaStructPointer(), args.pInfos.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBuildMicromapsEXT(in_commandBuffer, args.infoCount, in_pInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBuildMicromapsEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.infoCount, in_pInfos);
    }
}

void VulkanReplayConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    args::BuildMicromapsEXT&                    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(args.deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkMicromapBuildInfoEXT* in_pInfos = args.pInfos.GetPointer();
    MapStructArrayHandles(args.pInfos.GetMetaStructPointer(), args.pInfos.GetLength(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->BuildMicromapsEXT(in_device, in_deferredOperation, args.infoCount, in_pInfos);
    CheckResult("vkBuildMicromapsEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMicromapEXT&                      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(args.deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkCopyMicromapInfoEXT* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMicromapEXT(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMicromapEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMicromapToMemoryEXT&              args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(args.deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkCopyMicromapToMemoryInfoEXT* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMicromapToMemoryEXT(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMicromapToMemoryEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToMicromapEXT&              args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(args.deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkCopyMemoryToMicromapInfoEXT* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMemoryToMicromapEXT(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMemoryToMicromapEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::WriteMicromapsPropertiesEXT&          args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMicromapEXT* in_pMicromaps = MapHandles<VulkanMicromapEXTInfo>(&args.pMicromaps, args.micromapCount, &CommonObjectInfoTable::GetVkMicromapEXTInfo);
    void* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(args.dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->WriteMicromapsPropertiesEXT(in_device, args.micromapCount, in_pMicromaps, args.queryType, args.dataSize, out_pData, args.stride);
    CheckResult("vkWriteMicromapsPropertiesEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMicromapEXT&                   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyMicromapInfoEXT* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMicromapEXT(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyMicromapEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMicromapToMemoryEXT&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyMicromapToMemoryInfoEXT* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMicromapToMemoryEXT(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyMicromapToMemoryEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToMicromapEXT&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyMemoryToMicromapInfoEXT* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMemoryToMicromapEXT(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyMemoryToMicromapEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::CmdWriteMicromapsPropertiesEXT&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkMicromapEXT* in_pMicromaps = MapHandles<VulkanMicromapEXTInfo>(&args.pMicromaps, args.micromapCount, &CommonObjectInfoTable::GetVkMicromapEXTInfo);
    VkQueryPool in_queryPool = MapHandle<VulkanQueryPoolInfo>(args.queryPool, &CommonObjectInfoTable::GetVkQueryPoolInfo);

    GetDeviceTable(in_commandBuffer)->CmdWriteMicromapsPropertiesEXT(in_commandBuffer, args.micromapCount, in_pMicromaps, args.queryType, in_queryPool, args.firstQuery);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWriteMicromapsPropertiesEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.micromapCount, &args.pMicromaps, args.queryType, GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool), args.firstQuery);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    args::GetDeviceMicromapCompatibilityEXT&    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMicromapVersionInfoEXT* in_pVersionInfo = args.pVersionInfo.GetPointer();
    MapStructHandles(args.pVersionInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkAccelerationStructureCompatibilityKHR* out_pCompatibility = args.pCompatibility.IsNull() ? nullptr : args.pCompatibility.AllocateOutputData(1, static_cast<VkAccelerationStructureCompatibilityKHR>(0));

    GetDeviceTable(in_device)->GetDeviceMicromapCompatibilityEXT(in_device, in_pVersionInfo, out_pCompatibility);
}

void VulkanReplayConsumer::Process_vkGetMicromapBuildSizesEXT(
    const ApiCallInfo&                          call_info,
    args::GetMicromapBuildSizesEXT&             args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMicromapBuildInfoEXT* in_pBuildInfo = args.pBuildInfo.GetPointer();
    MapStructHandles(args.pBuildInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkMicromapBuildSizesInfoEXT* out_pSizeInfo = args.pSizeInfo.IsNull() ? nullptr : args.pSizeInfo.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT, nullptr });
    InitializeOutputStructPNext(&args.pSizeInfo);

    GetDeviceTable(in_device)->GetMicromapBuildSizesEXT(in_device, args.buildType, in_pBuildInfo, out_pSizeInfo);
}

void VulkanReplayConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterHUAWEI&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawClusterHUAWEI(in_commandBuffer, args.groupCountX, args.groupCountY, args.groupCountZ);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawClusterHUAWEI(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.groupCountX, args.groupCountY, args.groupCountZ);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterIndirectHUAWEI&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawClusterIndirectHUAWEI(in_commandBuffer, in_buffer, args.offset);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawClusterIndirectHUAWEI(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_buffer, args.offset);
    }
}

void VulkanReplayConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    args::SetDeviceMemoryPriorityEXT&           args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_memory = GetObjectInfoTable().GetVkDeviceMemoryInfo(args.memory);

    OverrideSetDeviceMemoryPriorityEXT(GetDeviceTable(in_device->handle)->SetDeviceMemoryPriorityEXT, in_device, in_memory, args.priority);
}

void VulkanReplayConsumer::Process_vkCmdSetDispatchParametersARM(
    const ApiCallInfo&                          call_info,
    args::CmdSetDispatchParametersARM&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDispatchParametersARM* in_pDispatchParameters = args.pDispatchParameters.GetPointer();
    MapStructHandles(args.pDispatchParameters.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetDispatchParametersARM(in_commandBuffer, in_pDispatchParameters);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDispatchParametersARM(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pDispatchParameters);
    }
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetLayoutHostMappingInfoVALVE& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDescriptorSetBindingReferenceVALVE* in_pBindingReference = args.pBindingReference.GetPointer();
    MapStructHandles(args.pBindingReference.GetMetaStructPointer(), GetObjectInfoTable());
    VkDescriptorSetLayoutHostMappingInfoVALVE* out_pHostMapping = args.pHostMapping.IsNull() ? nullptr : args.pHostMapping.AllocateOutputData(1, { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE, nullptr });
    InitializeOutputStructPNext(&args.pHostMapping);

    GetDeviceTable(in_device)->GetDescriptorSetLayoutHostMappingInfoVALVE(in_device, in_pBindingReference, out_pHostMapping);
}

void VulkanReplayConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    args::GetDescriptorSetHostMappingVALVE&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDescriptorSet in_descriptorSet = MapHandle<VulkanDescriptorSetInfo>(args.descriptorSet, &CommonObjectInfoTable::GetVkDescriptorSetInfo);
    void** out_ppData = args.ppData.IsNull() ? nullptr : args.ppData.AllocateOutputData(1);

    GetDeviceTable(in_device)->GetDescriptorSetHostMappingVALVE(in_device, in_descriptorSet, out_ppData);

    PostProcessExternalObject(VK_SUCCESS, (*args.ppData.GetPointer()), *args.ppData.GetOutputPointer(), format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE, "vkGetDescriptorSetHostMappingVALVE");
}

void VulkanReplayConsumer::Process_vkGetPipelineIndirectMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    args::GetPipelineIndirectMemoryRequirementsNV& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkComputePipelineCreateInfo* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    GetDeviceTable(in_device)->GetPipelineIndirectMemoryRequirementsNV(in_device, in_pCreateInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    args::CmdUpdatePipelineIndirectBufferNV&    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(args.pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);

    GetDeviceTable(in_commandBuffer)->CmdUpdatePipelineIndirectBufferNV(in_commandBuffer, args.pipelineBindPoint, in_pipeline);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdUpdatePipelineIndirectBufferNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.pipelineBindPoint, in_pipeline);
    }
}

void VulkanReplayConsumer::Process_vkGetPipelineIndirectDeviceAddressNV(
    const ApiCallInfo&                          call_info,
    args::GetPipelineIndirectDeviceAddressNV&   args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPipelineIndirectDeviceAddressInfoNV* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->GetPipelineIndirectDeviceAddressNV(in_device, in_pInfo);
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClampEnableEXT&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClampEnableEXT(in_commandBuffer, args.depthClampEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthClampEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthClampEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPolygonModeEXT&                 args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPolygonModeEXT(in_commandBuffer, args.polygonMode);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetPolygonModeEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.polygonMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizationSamplesEXT&        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizationSamplesEXT(in_commandBuffer, args.rasterizationSamples);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetRasterizationSamplesEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.rasterizationSamples);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleMaskEXT&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkSampleMask* in_pSampleMask = args.pSampleMask.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetSampleMaskEXT(in_commandBuffer, args.samples, in_pSampleMask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetSampleMaskEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.samples, in_pSampleMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAlphaToCoverageEnableEXT&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetAlphaToCoverageEnableEXT(in_commandBuffer, args.alphaToCoverageEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetAlphaToCoverageEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.alphaToCoverageEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAlphaToOneEnableEXT&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetAlphaToOneEnableEXT(in_commandBuffer, args.alphaToOneEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetAlphaToOneEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.alphaToOneEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLogicOpEnableEXT&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLogicOpEnableEXT(in_commandBuffer, args.logicOpEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetLogicOpEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.logicOpEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendEnableEXT&            args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBool32* in_pColorBlendEnables = args.pColorBlendEnables.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorBlendEnableEXT(in_commandBuffer, args.firstAttachment, args.attachmentCount, in_pColorBlendEnables);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetColorBlendEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstAttachment, args.attachmentCount, in_pColorBlendEnables);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendEquationEXT&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkColorBlendEquationEXT* in_pColorBlendEquations = args.pColorBlendEquations.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorBlendEquationEXT(in_commandBuffer, args.firstAttachment, args.attachmentCount, in_pColorBlendEquations);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetColorBlendEquationEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstAttachment, args.attachmentCount, in_pColorBlendEquations);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorWriteMaskEXT&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkColorComponentFlags* in_pColorWriteMasks = args.pColorWriteMasks.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorWriteMaskEXT(in_commandBuffer, args.firstAttachment, args.attachmentCount, in_pColorWriteMasks);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetColorWriteMaskEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstAttachment, args.attachmentCount, in_pColorWriteMasks);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetTessellationDomainOriginEXT&    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetTessellationDomainOriginEXT(in_commandBuffer, args.domainOrigin);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetTessellationDomainOriginEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.domainOrigin);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizationStreamEXT&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRasterizationStreamEXT(in_commandBuffer, args.rasterizationStream);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetRasterizationStreamEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.rasterizationStream);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetConservativeRasterizationModeEXT& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetConservativeRasterizationModeEXT(in_commandBuffer, args.conservativeRasterizationMode);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetConservativeRasterizationModeEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.conservativeRasterizationMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetExtraPrimitiveOverestimationSizeEXT& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetExtraPrimitiveOverestimationSizeEXT(in_commandBuffer, args.extraPrimitiveOverestimationSize);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.extraPrimitiveOverestimationSize);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClipEnableEXT&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClipEnableEXT(in_commandBuffer, args.depthClipEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthClipEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthClipEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleLocationsEnableEXT&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetSampleLocationsEnableEXT(in_commandBuffer, args.sampleLocationsEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetSampleLocationsEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.sampleLocationsEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendAdvancedEXT&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkColorBlendAdvancedEXT* in_pColorBlendAdvanced = args.pColorBlendAdvanced.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetColorBlendAdvancedEXT(in_commandBuffer, args.firstAttachment, args.attachmentCount, in_pColorBlendAdvanced);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetColorBlendAdvancedEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstAttachment, args.attachmentCount, in_pColorBlendAdvanced);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetProvokingVertexModeEXT&         args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetProvokingVertexModeEXT(in_commandBuffer, args.provokingVertexMode);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetProvokingVertexModeEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.provokingVertexMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineRasterizationModeEXT&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineRasterizationModeEXT(in_commandBuffer, args.lineRasterizationMode);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetLineRasterizationModeEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.lineRasterizationMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleEnableEXT&           args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetLineStippleEnableEXT(in_commandBuffer, args.stippledLineEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetLineStippleEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.stippledLineEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClipNegativeOneToOneEXT&   args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClipNegativeOneToOneEXT(in_commandBuffer, args.negativeOneToOne);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthClipNegativeOneToOneEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.negativeOneToOne);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWScalingEnableNV&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetViewportWScalingEnableNV(in_commandBuffer, args.viewportWScalingEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetViewportWScalingEnableNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.viewportWScalingEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportSwizzleNV&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkViewportSwizzleNV* in_pViewportSwizzles = args.pViewportSwizzles.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetViewportSwizzleNV(in_commandBuffer, args.firstViewport, args.viewportCount, in_pViewportSwizzles);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetViewportSwizzleNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.firstViewport, args.viewportCount, in_pViewportSwizzles);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageToColorEnableNV&        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageToColorEnableNV(in_commandBuffer, args.coverageToColorEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetCoverageToColorEnableNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.coverageToColorEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageToColorLocationNV&      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageToColorLocationNV(in_commandBuffer, args.coverageToColorLocation);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetCoverageToColorLocationNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.coverageToColorLocation);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationModeNV&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationModeNV(in_commandBuffer, args.coverageModulationMode);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetCoverageModulationModeNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.coverageModulationMode);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationTableEnableNV& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationTableEnableNV(in_commandBuffer, args.coverageModulationTableEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetCoverageModulationTableEnableNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.coverageModulationTableEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationTableNV&      args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const float* in_pCoverageModulationTable = args.pCoverageModulationTable.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageModulationTableNV(in_commandBuffer, args.coverageModulationTableCount, in_pCoverageModulationTable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetCoverageModulationTableNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.coverageModulationTableCount, in_pCoverageModulationTable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetShadingRateImageEnableNV&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetShadingRateImageEnableNV(in_commandBuffer, args.shadingRateImageEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetShadingRateImageEnableNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.shadingRateImageEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetRepresentativeFragmentTestEnableNV& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRepresentativeFragmentTestEnableNV(in_commandBuffer, args.representativeFragmentTestEnable);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetRepresentativeFragmentTestEnableNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.representativeFragmentTestEnable);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageReductionModeNV&        args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetCoverageReductionModeNV(in_commandBuffer, args.coverageReductionMode);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetCoverageReductionModeNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.coverageReductionMode);
    }
}

void VulkanReplayConsumer::Process_vkCreateTensorARM(
    const ApiCallInfo&                          call_info,
    args::CreateTensorARM&                      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pTensor.IsNull()) { args.pTensor.SetHandleLength(1); }
    VulkanTensorARMInfo handle_info;
    args.pTensor.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pTensor.GetPointer());
    VkResult replay_result = OverrideCreateTensorARM(GetDeviceTable(in_device->handle)->CreateTensorARM, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pTensor);
    CheckResult("vkCreateTensorARM", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanTensorARMInfo>(args.device, args.pTensor.GetPointer(), args.pTensor.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkTensorARMInfo);
}

void VulkanReplayConsumer::Process_vkDestroyTensorARM(
    const ApiCallInfo&                          call_info,
    args::DestroyTensorARM&                     args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_tensor = GetObjectInfoTable().GetVkTensorARMInfo(args.tensor);

    OverrideDestroyTensorARM(GetDeviceTable(in_device->handle)->DestroyTensorARM, in_device, in_tensor, &args.pAllocator);
    RemoveHandle(args.tensor, &CommonObjectInfoTable::RemoveVkTensorARMInfo);
}

void VulkanReplayConsumer::Process_vkCreateTensorViewARM(
    const ApiCallInfo&                          call_info,
    args::CreateTensorViewARM&                  args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkTensorViewCreateInfoARM* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pView.IsNull()) { args.pView.SetHandleLength(1); }
    VkTensorViewARM* out_pView = args.pView.GetHandlePointer();

    PushRecaptureHandleId(args.pView.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateTensorViewARM(in_device, in_pCreateInfo, in_pAllocator, out_pView);
    CheckResult("vkCreateTensorViewARM", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanTensorViewARMInfo>(args.device, args.pView.GetPointer(), out_pView, &CommonObjectInfoTable::AddVkTensorViewARMInfo);
}

void VulkanReplayConsumer::Process_vkDestroyTensorViewARM(
    const ApiCallInfo&                          call_info,
    args::DestroyTensorViewARM&                 args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkTensorViewARM in_tensorView = MapHandle<VulkanTensorViewARMInfo>(args.tensorView, &CommonObjectInfoTable::GetVkTensorViewARMInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyTensorViewARM(in_device, in_tensorView, in_pAllocator);
    RemoveHandle(args.tensorView, &CommonObjectInfoTable::RemoveVkTensorViewARMInfo);
}

void VulkanReplayConsumer::Process_vkGetTensorMemoryRequirementsARM(
    const ApiCallInfo&                          call_info,
    args::GetTensorMemoryRequirementsARM&       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    OverrideGetTensorMemoryRequirementsARM(GetDeviceTable(in_device->handle)->GetTensorMemoryRequirementsARM, in_device, &args.pInfo, &args.pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkBindTensorMemoryARM(
    const ApiCallInfo&                          call_info,
    args::BindTensorMemoryARM&                  args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pBindInfos.GetMetaStructPointer(), args.pBindInfos.GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindTensorMemoryARM(GetDeviceTable(in_device->handle)->BindTensorMemoryARM, args.result, in_device, args.bindInfoCount, &args.pBindInfos);
    CheckResult("vkBindTensorMemoryARM", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetDeviceTensorMemoryRequirementsARM(
    const ApiCallInfo&                          call_info,
    args::GetDeviceTensorMemoryRequirementsARM& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDeviceTensorMemoryRequirementsARM* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    GetDeviceTable(in_device)->GetDeviceTensorMemoryRequirementsARM(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkCmdCopyTensorARM(
    const ApiCallInfo&                          call_info,
    args::CmdCopyTensorARM&                     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyTensorInfoARM* in_pCopyTensorInfo = args.pCopyTensorInfo.GetPointer();
    MapStructHandles(args.pCopyTensorInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyTensorARM(in_commandBuffer, in_pCopyTensorInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyTensorARM(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pCopyTensorInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceExternalTensorPropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceExternalTensorPropertiesARM& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceExternalTensorInfoARM* in_pExternalTensorInfo = args.pExternalTensorInfo.GetPointer();
    MapStructHandles(args.pExternalTensorInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkExternalTensorPropertiesARM* out_pExternalTensorProperties = args.pExternalTensorProperties.IsNull() ? nullptr : args.pExternalTensorProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_EXTERNAL_TENSOR_PROPERTIES_ARM, nullptr });
    InitializeOutputStructPNext(&args.pExternalTensorProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceExternalTensorPropertiesARM(in_physicalDevice, in_pExternalTensorInfo, out_pExternalTensorProperties);
}

void VulkanReplayConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    args::GetShaderModuleIdentifierEXT&         args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkShaderModule in_shaderModule = MapHandle<VulkanShaderModuleInfo>(args.shaderModule, &CommonObjectInfoTable::GetVkShaderModuleInfo);
    VkShaderModuleIdentifierEXT* out_pIdentifier = args.pIdentifier.IsNull() ? nullptr : args.pIdentifier.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT, nullptr });
    InitializeOutputStructPNext(&args.pIdentifier);

    GetDeviceTable(in_device)->GetShaderModuleIdentifierEXT(in_device, in_shaderModule, out_pIdentifier);
}

void VulkanReplayConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    args::GetShaderModuleCreateInfoIdentifierEXT& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkShaderModuleCreateInfo* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkShaderModuleIdentifierEXT* out_pIdentifier = args.pIdentifier.IsNull() ? nullptr : args.pIdentifier.AllocateOutputData(1, { VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT, nullptr });
    InitializeOutputStructPNext(&args.pIdentifier);

    GetDeviceTable(in_device)->GetShaderModuleCreateInfoIdentifierEXT(in_device, in_pCreateInfo, out_pIdentifier);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceOpticalFlowImageFormatsNV& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkOpticalFlowImageFormatInfoNV* in_pOpticalFlowImageFormatInfo = args.pOpticalFlowImageFormatInfo.GetPointer();
    MapStructHandles(args.pOpticalFlowImageFormatInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pFormatCount = args.pFormatCount.IsNull() ? nullptr : args.pFormatCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceOpticalFlowImageFormatsNV", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceOpticalFlowImageFormatsNV, &args.pFormatCount, &args.pImageFormatProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkOpticalFlowImageFormatPropertiesNV* out_pImageFormatProperties = args.pImageFormatProperties.IsNull() ? nullptr : args.pImageFormatProperties.AllocateOutputData(*out_pFormatCount, VkOpticalFlowImageFormatPropertiesNV{ VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceOpticalFlowImageFormatsNV(in_physicalDevice, in_pOpticalFlowImageFormatInfo, out_pFormatCount, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceOpticalFlowImageFormatsNV", args.result, replay_result, call_info);

    if (args.pImageFormatProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceOpticalFlowImageFormatsNV, *out_pFormatCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    args::CreateOpticalFlowSessionNV&           args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkOpticalFlowSessionCreateInfoNV* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pSession.IsNull()) { args.pSession.SetHandleLength(1); }
    VkOpticalFlowSessionNV* out_pSession = args.pSession.GetHandlePointer();

    PushRecaptureHandleId(args.pSession.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateOpticalFlowSessionNV(in_device, in_pCreateInfo, in_pAllocator, out_pSession);
    CheckResult("vkCreateOpticalFlowSessionNV", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanOpticalFlowSessionNVInfo>(args.device, args.pSession.GetPointer(), out_pSession, &CommonObjectInfoTable::AddVkOpticalFlowSessionNVInfo);
}

void VulkanReplayConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    args::DestroyOpticalFlowSessionNV&          args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkOpticalFlowSessionNV in_session = MapHandle<VulkanOpticalFlowSessionNVInfo>(args.session, &CommonObjectInfoTable::GetVkOpticalFlowSessionNVInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyOpticalFlowSessionNV(in_device, in_session, in_pAllocator);
    RemoveHandle(args.session, &CommonObjectInfoTable::RemoveVkOpticalFlowSessionNVInfo);
}

void VulkanReplayConsumer::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    args::BindOpticalFlowSessionImageNV&        args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkOpticalFlowSessionNV in_session = MapHandle<VulkanOpticalFlowSessionNVInfo>(args.session, &CommonObjectInfoTable::GetVkOpticalFlowSessionNVInfo);
    VkImageView in_view = MapHandle<VulkanImageViewInfo>(args.view, &CommonObjectInfoTable::GetVkImageViewInfo);

    VkResult replay_result = GetDeviceTable(in_device)->BindOpticalFlowSessionImageNV(in_device, in_session, args.bindingPoint, in_view, args.layout);
    CheckResult("vkBindOpticalFlowSessionImageNV", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    args::CmdOpticalFlowExecuteNV&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkOpticalFlowSessionNV in_session = MapHandle<VulkanOpticalFlowSessionNVInfo>(args.session, &CommonObjectInfoTable::GetVkOpticalFlowSessionNVInfo);
    const VkOpticalFlowExecuteInfoNV* in_pExecuteInfo = args.pExecuteInfo.GetPointer();
    MapStructHandles(args.pExecuteInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdOpticalFlowExecuteNV(in_commandBuffer, in_session, in_pExecuteInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdOpticalFlowExecuteNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_session, in_pExecuteInfo);
    }
}

void VulkanReplayConsumer::Process_vkAntiLagUpdateAMD(
    const ApiCallInfo&                          call_info,
    args::AntiLagUpdateAMD&                     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAntiLagDataAMD* in_pData = args.pData.GetPointer();
    MapStructHandles(args.pData.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->AntiLagUpdateAMD(in_device, in_pData);
}

void VulkanReplayConsumer::Process_vkCreateShadersEXT(
    const ApiCallInfo&                          call_info,
    args::CreateShadersEXT&                     args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pCreateInfos.GetMetaStructPointer(), args.pCreateInfos.GetLength(), GetObjectInfoTable());
    if (!args.pShaders.IsNull()) { args.pShaders.SetHandleLength(args.createInfoCount); }
    std::vector<VulkanShaderEXTInfo> handle_info(args.createInfoCount);
    for (size_t i = 0; i < args.createInfoCount; ++i) { args.pShaders.SetConsumerData(i, &handle_info[i]); }

    if (UseAsyncOperations())
    {
        auto task = AsyncCreateShadersEXT(GetDeviceTable(in_device->handle)->CreateShadersEXT, args.result, call_info, in_device, args.createInfoCount, &args.pCreateInfos, &args.pAllocator, &args.pShaders);
        if(task)
        {
           AddHandlesAsync<VulkanShaderEXTInfo>(args.device, args.pShaders.GetPointer(), args.pShaders.GetLength(), std::move(handle_info), &CommonObjectInfoTable::AddVkShaderEXTInfo, std::move(task));
           return;
        }
    }
    PushRecaptureHandleIds(args.pShaders.GetPointer(), args.pShaders.GetLength());
    VkResult replay_result = OverrideCreateShadersEXT(GetDeviceTable(in_device->handle)->CreateShadersEXT, args.result, in_device, args.createInfoCount, &args.pCreateInfos, &args.pAllocator, &args.pShaders);
    CheckResult("vkCreateShadersEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandles<VulkanShaderEXTInfo>(args.device, args.pShaders.GetPointer(), args.pShaders.GetLength(), args.pShaders.GetHandlePointer(), args.createInfoCount, std::move(handle_info), &CommonObjectInfoTable::AddVkShaderEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyShaderEXT&                     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkShaderEXT in_shader = MapHandle<VulkanShaderEXTInfo>(args.shader, &CommonObjectInfoTable::GetVkShaderEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyShaderEXT(in_device, in_shader, in_pAllocator);
    RemoveHandle(args.shader, &CommonObjectInfoTable::RemoveVkShaderEXTInfo);
}

void VulkanReplayConsumer::Process_vkGetShaderBinaryDataEXT(
    const ApiCallInfo&                          call_info,
    args::GetShaderBinaryDataEXT&               args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkShaderEXT in_shader = MapHandle<VulkanShaderEXTInfo>(args.shader, &CommonObjectInfoTable::GetVkShaderEXTInfo);
    size_t* out_pDataSize = args.pDataSize.IsNull() ? nullptr : args.pDataSize.AllocateOutputData(1, GetOutputArrayCount<size_t, VulkanShaderEXTInfo>("vkGetShaderBinaryDataEXT", args.result, args.shader, kShaderEXTArrayGetShaderBinaryDataEXT, &args.pDataSize, &args.pData, &CommonObjectInfoTable::GetVkShaderEXTInfo));
    void* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(*out_pDataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetShaderBinaryDataEXT(in_device, in_shader, out_pDataSize, out_pData);
    CheckResult("vkGetShaderBinaryDataEXT", args.result, replay_result, call_info);

    if (args.pData.IsNull()) { SetOutputArrayCount<VulkanShaderEXTInfo>(args.shader, kShaderEXTArrayGetShaderBinaryDataEXT, *out_pDataSize, &CommonObjectInfoTable::GetVkShaderEXTInfo); }
}

void VulkanReplayConsumer::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadersEXT&                    args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkShaderStageFlagBits* in_pStages = args.pStages.GetPointer();
    const VkShaderEXT* in_pShaders = MapHandles<VulkanShaderEXTInfo>(&args.pShaders, args.stageCount, &CommonObjectInfoTable::GetVkShaderEXTInfo);

    GetDeviceTable(in_commandBuffer)->CmdBindShadersEXT(in_commandBuffer, args.stageCount, in_pStages, in_pShaders);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindShadersEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.stageCount, in_pStages, in_pShaders);
    }
}

void VulkanReplayConsumer::Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClampRangeEXT&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDepthClampRangeEXT* in_pDepthClampRange = args.pDepthClampRange.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdSetDepthClampRangeEXT(in_commandBuffer, args.depthClampMode, in_pDepthClampRange);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetDepthClampRangeEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.depthClampMode, in_pDepthClampRange);
    }
}

void VulkanReplayConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    args::GetFramebufferTilePropertiesQCOM&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkFramebuffer in_framebuffer = MapHandle<VulkanFramebufferInfo>(args.framebuffer, &CommonObjectInfoTable::GetVkFramebufferInfo);
    uint32_t* out_pPropertiesCount = args.pPropertiesCount.IsNull() ? nullptr : args.pPropertiesCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanFramebufferInfo>("vkGetFramebufferTilePropertiesQCOM", args.result, args.framebuffer, kFramebufferArrayGetFramebufferTilePropertiesQCOM, &args.pPropertiesCount, &args.pProperties, &CommonObjectInfoTable::GetVkFramebufferInfo));
    VkTilePropertiesQCOM* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertiesCount, VkTilePropertiesQCOM{ VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetFramebufferTilePropertiesQCOM(in_device, in_framebuffer, out_pPropertiesCount, out_pProperties);
    CheckResult("vkGetFramebufferTilePropertiesQCOM", args.result, replay_result, call_info);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanFramebufferInfo>(args.framebuffer, kFramebufferArrayGetFramebufferTilePropertiesQCOM, *out_pPropertiesCount, &CommonObjectInfoTable::GetVkFramebufferInfo); }
}

void VulkanReplayConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    args::GetDynamicRenderingTilePropertiesQCOM& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkRenderingInfo* in_pRenderingInfo = args.pRenderingInfo.GetPointer();
    MapStructHandles(args.pRenderingInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkTilePropertiesQCOM* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM, nullptr });
    InitializeOutputStructPNext(&args.pProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetDynamicRenderingTilePropertiesQCOM(in_device, in_pRenderingInfo, out_pProperties);
    CheckResult("vkGetDynamicRenderingTilePropertiesQCOM", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCooperativeVectorPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeVectorPropertiesNV& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCooperativeVectorPropertiesNV", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeVectorPropertiesNV, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkCooperativeVectorPropertiesNV* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount, VkCooperativeVectorPropertiesNV{ VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCooperativeVectorPropertiesNV(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceCooperativeVectorPropertiesNV", args.result, replay_result, call_info);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeVectorPropertiesNV, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    args::ConvertCooperativeVectorMatrixNV&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkConvertCooperativeVectorMatrixInfoNV* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->ConvertCooperativeVectorMatrixNV(in_device, in_pInfo);
    CheckResult("vkConvertCooperativeVectorMatrixNV", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    args::CmdConvertCooperativeVectorMatrixNV&  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkConvertCooperativeVectorMatrixInfoNV* in_pInfos = args.pInfos.GetPointer();
    MapStructArrayHandles(args.pInfos.GetMetaStructPointer(), args.pInfos.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdConvertCooperativeVectorMatrixNV(in_commandBuffer, args.infoCount, in_pInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdConvertCooperativeVectorMatrixNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.infoCount, in_pInfos);
    }
}

void VulkanReplayConsumer::Process_vkSetLatencySleepModeNV(
    const ApiCallInfo&                          call_info,
    args::SetLatencySleepModeNV&                args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkSetLatencySleepModeNV for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }
    const VkLatencySleepModeInfoNV* in_pSleepModeInfo = args.pSleepModeInfo.GetPointer();
    MapStructHandles(args.pSleepModeInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->SetLatencySleepModeNV(in_device, in_swapchain, in_pSleepModeInfo);
    CheckResult("vkSetLatencySleepModeNV", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkLatencySleepNV(
    const ApiCallInfo&                          call_info,
    args::LatencySleepNV&                       args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkLatencySleepNV for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }
    const VkLatencySleepInfoNV* in_pSleepInfo = args.pSleepInfo.GetPointer();
    MapStructHandles(args.pSleepInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->LatencySleepNV(in_device, in_swapchain, in_pSleepInfo);
    CheckResult("vkLatencySleepNV", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkSetLatencyMarkerNV(
    const ApiCallInfo&                          call_info,
    args::SetLatencyMarkerNV&                   args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkSetLatencyMarkerNV for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }
    const VkSetLatencyMarkerInfoNV* in_pLatencyMarkerInfo = args.pLatencyMarkerInfo.GetPointer();
    MapStructHandles(args.pLatencyMarkerInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_device)->SetLatencyMarkerNV(in_device, in_swapchain, in_pLatencyMarkerInfo);
}

void VulkanReplayConsumer::Process_vkGetLatencyTimingsNV(
    const ApiCallInfo&                          call_info,
    args::GetLatencyTimingsNV&                  args)
{
    if (options_.swapchain_option == util::SwapchainOption::kOffscreen)
    {
        GFXRECON_LOG_DEBUG("Skip vkGetLatencyTimingsNV for offscreen.");
        return;
    }
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkSwapchainKHR in_swapchain = MapHandle<VulkanSwapchainKHRInfo>(args.swapchain, &CommonObjectInfoTable::GetVkSwapchainKHRInfo);
    if (GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id) == nullptr || GetObjectInfoTable().GetVkSurfaceKHRInfo(GetObjectInfoTable().GetVkSwapchainKHRInfo(args.swapchain)->surface_id)->surface_creation_skipped) { return; }
    VkGetLatencyMarkerInfoNV* out_pLatencyMarkerInfo = args.pLatencyMarkerInfo.IsNull() ? nullptr : args.pLatencyMarkerInfo.AllocateOutputData(1, { VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV, nullptr });
    InitializeOutputStructPNext(&args.pLatencyMarkerInfo);

    GetDeviceTable(in_device)->GetLatencyTimingsNV(in_device, in_swapchain, out_pLatencyMarkerInfo);
}

void VulkanReplayConsumer::Process_vkQueueNotifyOutOfBandNV(
    const ApiCallInfo&                          call_info,
    args::QueueNotifyOutOfBandNV&               args)
{
    VkQueue in_queue = MapHandle<VulkanQueueInfo>(args.queue, &CommonObjectInfoTable::GetVkQueueInfo);
    const VkOutOfBandQueueTypeInfoNV* in_pQueueTypeInfo = args.pQueueTypeInfo.GetPointer();
    MapStructHandles(args.pQueueTypeInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_queue)->QueueNotifyOutOfBandNV(in_queue, in_pQueueTypeInfo);
}

void VulkanReplayConsumer::Process_vkCreateDataGraphPipelinesARM(
    const ApiCallInfo&                          call_info,
    args::CreateDataGraphPipelinesARM&          args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_deferredOperation = GetObjectInfoTable().GetVkDeferredOperationKHRInfo(args.deferredOperation);
    auto in_pipelineCache = GetObjectInfoTable().GetVkPipelineCacheInfo(args.pipelineCache);

    MapStructArrayHandles(args.pCreateInfos.GetMetaStructPointer(), args.pCreateInfos.GetLength(), GetObjectInfoTable());
    if (!args.pPipelines.IsNull()) { args.pPipelines.SetHandleLength(args.createInfoCount); }
    std::vector<VulkanPipelineInfo> handle_info(args.createInfoCount);
    for (size_t i = 0; i < args.createInfoCount; ++i) { args.pPipelines.SetConsumerData(i, &handle_info[i]); }

    PushRecaptureHandleIds(args.pPipelines.GetPointer(), args.pPipelines.GetLength());
    VkResult replay_result = OverrideCreateDataGraphPipelinesARM(GetDeviceTable(in_device->handle)->CreateDataGraphPipelinesARM, args.result, in_device, in_deferredOperation, in_pipelineCache, args.createInfoCount, &args.pCreateInfos, &args.pAllocator, &args.pPipelines);
    CheckResult("vkCreateDataGraphPipelinesARM", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandles<VulkanPipelineInfo>(args.device, args.pPipelines.GetPointer(), args.pPipelines.GetLength(), args.pPipelines.GetHandlePointer(), args.createInfoCount, std::move(handle_info), &CommonObjectInfoTable::AddVkPipelineInfo);
}

void VulkanReplayConsumer::Process_vkCreateDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    args::CreateDataGraphPipelineSessionARM&    args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pSession.IsNull()) { args.pSession.SetHandleLength(1); }
    VulkanDataGraphPipelineSessionARMInfo handle_info;
    args.pSession.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pSession.GetPointer());
    VkResult replay_result = OverrideCreateDataGraphPipelineSessionARM(GetDeviceTable(in_device->handle)->CreateDataGraphPipelineSessionARM, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pSession);
    CheckResult("vkCreateDataGraphPipelineSessionARM", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanDataGraphPipelineSessionARMInfo>(args.device, args.pSession.GetPointer(), args.pSession.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkDataGraphPipelineSessionARMInfo);
}

void VulkanReplayConsumer::Process_vkGetDataGraphPipelineSessionBindPointRequirementsARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelineSessionBindPointRequirementsARM& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDataGraphPipelineSessionBindPointRequirementsInfoARM* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pBindPointRequirementCount = args.pBindPointRequirementCount.IsNull() ? nullptr : args.pBindPointRequirementCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetDataGraphPipelineSessionBindPointRequirementsARM", args.result, args.device, kDeviceArrayGetDataGraphPipelineSessionBindPointRequirementsARM, &args.pBindPointRequirementCount, &args.pBindPointRequirements, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkDataGraphPipelineSessionBindPointRequirementARM* out_pBindPointRequirements = args.pBindPointRequirements.IsNull() ? nullptr : args.pBindPointRequirements.AllocateOutputData(*out_pBindPointRequirementCount, VkDataGraphPipelineSessionBindPointRequirementARM{ VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetDataGraphPipelineSessionBindPointRequirementsARM(in_device, in_pInfo, out_pBindPointRequirementCount, out_pBindPointRequirements);
    CheckResult("vkGetDataGraphPipelineSessionBindPointRequirementsARM", args.result, replay_result, call_info);

    if (args.pBindPointRequirements.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetDataGraphPipelineSessionBindPointRequirementsARM, *out_pBindPointRequirementCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetDataGraphPipelineSessionMemoryRequirementsARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelineSessionMemoryRequirementsARM& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDataGraphPipelineSessionMemoryRequirementsInfoARM* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    GetDeviceTable(in_device)->GetDataGraphPipelineSessionMemoryRequirementsARM(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkBindDataGraphPipelineSessionMemoryARM(
    const ApiCallInfo&                          call_info,
    args::BindDataGraphPipelineSessionMemoryARM& args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructArrayHandles(args.pBindInfos.GetMetaStructPointer(), args.pBindInfos.GetLength(), GetObjectInfoTable());

    VkResult replay_result = OverrideBindDataGraphPipelineSessionMemoryARM(GetDeviceTable(in_device->handle)->BindDataGraphPipelineSessionMemoryARM, args.result, in_device, args.bindInfoCount, &args.pBindInfos);
    CheckResult("vkBindDataGraphPipelineSessionMemoryARM", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkDestroyDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    args::DestroyDataGraphPipelineSessionARM&   args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_session = GetObjectInfoTable().GetVkDataGraphPipelineSessionARMInfo(args.session);

    OverrideDestroyDataGraphPipelineSessionARM(GetDeviceTable(in_device->handle)->DestroyDataGraphPipelineSessionARM, in_device, in_session, &args.pAllocator);
    RemoveHandle(args.session, &CommonObjectInfoTable::RemoveVkDataGraphPipelineSessionARMInfo);
}

void VulkanReplayConsumer::Process_vkCmdDispatchDataGraphARM(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchDataGraphARM&              args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkDataGraphPipelineSessionARM in_session = MapHandle<VulkanDataGraphPipelineSessionARMInfo>(args.session, &CommonObjectInfoTable::GetVkDataGraphPipelineSessionARMInfo);
    const VkDataGraphPipelineDispatchInfoARM* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDispatchDataGraphARM(in_commandBuffer, in_session, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDispatchDataGraphARM(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_session, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetDataGraphPipelineAvailablePropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelineAvailablePropertiesARM& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDataGraphPipelineInfoARM* in_pPipelineInfo = args.pPipelineInfo.GetPointer();
    MapStructHandles(args.pPipelineInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pPropertiesCount = args.pPropertiesCount.IsNull() ? nullptr : args.pPropertiesCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanDeviceInfo>("vkGetDataGraphPipelineAvailablePropertiesARM", args.result, args.device, kDeviceArrayGetDataGraphPipelineAvailablePropertiesARM, &args.pPropertiesCount, &args.pProperties, &CommonObjectInfoTable::GetVkDeviceInfo));
    VkDataGraphPipelinePropertyARM* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertiesCount);

    VkResult replay_result = GetDeviceTable(in_device)->GetDataGraphPipelineAvailablePropertiesARM(in_device, in_pPipelineInfo, out_pPropertiesCount, out_pProperties);
    CheckResult("vkGetDataGraphPipelineAvailablePropertiesARM", args.result, replay_result, call_info);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanDeviceInfo>(args.device, kDeviceArrayGetDataGraphPipelineAvailablePropertiesARM, *out_pPropertiesCount, &CommonObjectInfoTable::GetVkDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetDataGraphPipelinePropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetDataGraphPipelinePropertiesARM&    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkDataGraphPipelineInfoARM* in_pPipelineInfo = args.pPipelineInfo.GetPointer();
    MapStructHandles(args.pPipelineInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkDataGraphPipelinePropertyQueryResultARM* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(args.propertiesCount, VkDataGraphPipelinePropertyQueryResultARM{ VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_PROPERTY_QUERY_RESULT_ARM, nullptr });

    VkResult replay_result = GetDeviceTable(in_device)->GetDataGraphPipelinePropertiesARM(in_device, in_pPipelineInfo, args.propertiesCount, out_pProperties);
    CheckResult("vkGetDataGraphPipelinePropertiesARM", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pQueueFamilyDataGraphPropertyCount = args.pQueueFamilyDataGraphPropertyCount.IsNull() ? nullptr : args.pQueueFamilyDataGraphPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM, &args.pQueueFamilyDataGraphPropertyCount, &args.pQueueFamilyDataGraphProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkQueueFamilyDataGraphPropertiesARM* out_pQueueFamilyDataGraphProperties = args.pQueueFamilyDataGraphProperties.IsNull() ? nullptr : args.pQueueFamilyDataGraphProperties.AllocateOutputData(*out_pQueueFamilyDataGraphPropertyCount, VkQueueFamilyDataGraphPropertiesARM{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROPERTIES_ARM, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(in_physicalDevice, args.queueFamilyIndex, out_pQueueFamilyDataGraphPropertyCount, out_pQueueFamilyDataGraphProperties);
    CheckResult("vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM", args.result, replay_result, call_info);

    if (args.pQueueFamilyDataGraphProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM, *out_pQueueFamilyDataGraphPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* in_pQueueFamilyDataGraphProcessingEngineInfo = args.pQueueFamilyDataGraphProcessingEngineInfo.GetPointer();
    MapStructHandles(args.pQueueFamilyDataGraphProcessingEngineInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkQueueFamilyDataGraphProcessingEnginePropertiesARM* out_pQueueFamilyDataGraphProcessingEngineProperties = args.pQueueFamilyDataGraphProcessingEngineProperties.IsNull() ? nullptr : args.pQueueFamilyDataGraphProcessingEngineProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM, nullptr });
    InitializeOutputStructPNext(&args.pQueueFamilyDataGraphProcessingEngineProperties);

    GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(in_physicalDevice, in_pQueueFamilyDataGraphProcessingEngineInfo, out_pQueueFamilyDataGraphProcessingEngineProperties);
}

void VulkanReplayConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAttachmentFeedbackLoopEnableEXT& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetAttachmentFeedbackLoopEnableEXT(in_commandBuffer, args.aspectMask);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.aspectMask);
    }
}

void VulkanReplayConsumer::Process_vkCmdBindTileMemoryQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdBindTileMemoryQCOM&                args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkTileMemoryBindInfoQCOM* in_pTileMemoryBindInfo = args.pTileMemoryBindInfo.GetPointer();
    MapStructHandles(args.pTileMemoryBindInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBindTileMemoryQCOM(in_commandBuffer, in_pTileMemoryBindInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBindTileMemoryQCOM(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pTileMemoryBindInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdDecompressMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDecompressMemoryEXT&               args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkDecompressMemoryInfoEXT* in_pDecompressMemoryInfoEXT = args.pDecompressMemoryInfoEXT.GetPointer();
    MapStructHandles(args.pDecompressMemoryInfoEXT.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdDecompressMemoryEXT(in_commandBuffer, in_pDecompressMemoryInfoEXT);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDecompressMemoryEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pDecompressMemoryInfoEXT);
    }
}

void VulkanReplayConsumer::Process_vkCmdDecompressMemoryIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDecompressMemoryIndirectCountEXT&  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDecompressMemoryIndirectCountEXT(in_commandBuffer, args.decompressionMethod, args.indirectCommandsAddress, args.indirectCommandsCountAddress, args.maxDecompressionCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDecompressMemoryIndirectCountEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.decompressionMethod, args.indirectCommandsAddress, args.indirectCommandsCountAddress, args.maxDecompressionCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkGetPartitionedAccelerationStructuresBuildSizesNV(
    const ApiCallInfo&                          call_info,
    args::GetPartitionedAccelerationStructuresBuildSizesNV& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkPartitionedAccelerationStructureInstancesInputNV* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkAccelerationStructureBuildSizesInfoKHR* out_pSizeInfo = args.pSizeInfo.IsNull() ? nullptr : args.pSizeInfo.AllocateOutputData(1, { VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR, nullptr });
    InitializeOutputStructPNext(&args.pSizeInfo);

    GetDeviceTable(in_device)->GetPartitionedAccelerationStructuresBuildSizesNV(in_device, in_pInfo, out_pSizeInfo);
}

void VulkanReplayConsumer::Process_vkCmdBuildPartitionedAccelerationStructuresNV(
    const ApiCallInfo&                          call_info,
    args::CmdBuildPartitionedAccelerationStructuresNV& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBuildPartitionedAccelerationStructureInfoNV* in_pBuildInfo = args.pBuildInfo.GetPointer();
    MapStructHandles(args.pBuildInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBuildPartitionedAccelerationStructuresNV(in_commandBuffer, in_pBuildInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBuildPartitionedAccelerationStructuresNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pBuildInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsEXT(
    const ApiCallInfo&                          call_info,
    args::GetGeneratedCommandsMemoryRequirementsEXT& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkGeneratedCommandsMemoryRequirementsInfoEXT* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkMemoryRequirements2* out_pMemoryRequirements = args.pMemoryRequirements.IsNull() ? nullptr : args.pMemoryRequirements.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2, nullptr });
    InitializeOutputStructPNext(&args.pMemoryRequirements);

    GetDeviceTable(in_device)->GetGeneratedCommandsMemoryRequirementsEXT(in_device, in_pInfo, out_pMemoryRequirements);
}

void VulkanReplayConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsEXT&    args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pGeneratedCommandsInfo.GetMetaStructPointer(), GetObjectInfoTable());
    auto in_stateCommandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.stateCommandBuffer);

    OverrideCmdPreprocessGeneratedCommandsEXT(GetDeviceTable(in_commandBuffer->handle)->CmdPreprocessGeneratedCommandsEXT, in_commandBuffer, &args.pGeneratedCommandsInfo, in_stateCommandBuffer);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdPreprocessGeneratedCommandsEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.pGeneratedCommandsInfo.GetPointer(), in_stateCommandBuffer->handle);
    }
}

void VulkanReplayConsumer::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsEXT&       args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pGeneratedCommandsInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideCmdExecuteGeneratedCommandsEXT(GetDeviceTable(in_commandBuffer->handle)->CmdExecuteGeneratedCommandsEXT, in_commandBuffer, args.isPreprocessed, &args.pGeneratedCommandsInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdExecuteGeneratedCommandsEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.isPreprocessed, args.pGeneratedCommandsInfo.GetPointer());
    }
}

void VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectCommandsLayoutEXT&      args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkIndirectCommandsLayoutCreateInfoEXT* in_pCreateInfo = args.pCreateInfo.GetPointer();
    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);
    if (!args.pIndirectCommandsLayout.IsNull()) { args.pIndirectCommandsLayout.SetHandleLength(1); }
    VkIndirectCommandsLayoutEXT* out_pIndirectCommandsLayout = args.pIndirectCommandsLayout.GetHandlePointer();

    PushRecaptureHandleId(args.pIndirectCommandsLayout.GetPointer());
    VkResult replay_result = GetDeviceTable(in_device)->CreateIndirectCommandsLayoutEXT(in_device, in_pCreateInfo, in_pAllocator, out_pIndirectCommandsLayout);
    CheckResult("vkCreateIndirectCommandsLayoutEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanIndirectCommandsLayoutEXTInfo>(args.device, args.pIndirectCommandsLayout.GetPointer(), out_pIndirectCommandsLayout, &CommonObjectInfoTable::AddVkIndirectCommandsLayoutEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectCommandsLayoutEXT&     args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkIndirectCommandsLayoutEXT in_indirectCommandsLayout = MapHandle<VulkanIndirectCommandsLayoutEXTInfo>(args.indirectCommandsLayout, &CommonObjectInfoTable::GetVkIndirectCommandsLayoutEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyIndirectCommandsLayoutEXT(in_device, in_indirectCommandsLayout, in_pAllocator);
    RemoveHandle(args.indirectCommandsLayout, &CommonObjectInfoTable::RemoveVkIndirectCommandsLayoutEXTInfo);
}

void VulkanReplayConsumer::Process_vkCreateIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectExecutionSetEXT&        args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    if (!args.pIndirectExecutionSet.IsNull()) { args.pIndirectExecutionSet.SetHandleLength(1); }
    VulkanIndirectExecutionSetEXTInfo handle_info;
    args.pIndirectExecutionSet.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pIndirectExecutionSet.GetPointer());
    VkResult replay_result = OverrideCreateIndirectExecutionSetEXT(GetDeviceTable(in_device->handle)->CreateIndirectExecutionSetEXT, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pIndirectExecutionSet);
    CheckResult("vkCreateIndirectExecutionSetEXT", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanIndirectExecutionSetEXTInfo>(args.device, args.pIndirectExecutionSet.GetPointer(), args.pIndirectExecutionSet.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkIndirectExecutionSetEXTInfo);
}

void VulkanReplayConsumer::Process_vkDestroyIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectExecutionSetEXT&       args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkIndirectExecutionSetEXT in_indirectExecutionSet = MapHandle<VulkanIndirectExecutionSetEXTInfo>(args.indirectExecutionSet, &CommonObjectInfoTable::GetVkIndirectExecutionSetEXTInfo);
    const VkAllocationCallbacks* in_pAllocator = GetAllocationCallbacks(&args.pAllocator);

    GetDeviceTable(in_device)->DestroyIndirectExecutionSetEXT(in_device, in_indirectExecutionSet, in_pAllocator);
    RemoveHandle(args.indirectExecutionSet, &CommonObjectInfoTable::RemoveVkIndirectExecutionSetEXTInfo);
}

void VulkanReplayConsumer::Process_vkUpdateIndirectExecutionSetPipelineEXT(
    const ApiCallInfo&                          call_info,
    args::UpdateIndirectExecutionSetPipelineEXT& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkIndirectExecutionSetEXT in_indirectExecutionSet = MapHandle<VulkanIndirectExecutionSetEXTInfo>(args.indirectExecutionSet, &CommonObjectInfoTable::GetVkIndirectExecutionSetEXTInfo);
    const VkWriteIndirectExecutionSetPipelineEXT* in_pExecutionSetWrites = args.pExecutionSetWrites.GetPointer();
    MapStructArrayHandles(args.pExecutionSetWrites.GetMetaStructPointer(), args.pExecutionSetWrites.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_device)->UpdateIndirectExecutionSetPipelineEXT(in_device, in_indirectExecutionSet, args.executionSetWriteCount, in_pExecutionSetWrites);
}

void VulkanReplayConsumer::Process_vkUpdateIndirectExecutionSetShaderEXT(
    const ApiCallInfo&                          call_info,
    args::UpdateIndirectExecutionSetShaderEXT&  args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkIndirectExecutionSetEXT in_indirectExecutionSet = MapHandle<VulkanIndirectExecutionSetEXTInfo>(args.indirectExecutionSet, &CommonObjectInfoTable::GetVkIndirectExecutionSetEXTInfo);
    const VkWriteIndirectExecutionSetShaderEXT* in_pExecutionSetWrites = args.pExecutionSetWrites.GetPointer();
    MapStructArrayHandles(args.pExecutionSetWrites.GetMetaStructPointer(), args.pExecutionSetWrites.GetLength(), GetObjectInfoTable());

    GetDeviceTable(in_device)->UpdateIndirectExecutionSetShaderEXT(in_device, in_indirectExecutionSet, args.executionSetWriteCount, in_pExecutionSetWrites);
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkCooperativeMatrixFlexibleDimensionsPropertiesNV* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount, VkCooperativeMatrixFlexibleDimensionsPropertiesNV{ VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(in_physicalDevice, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV", args.result, replay_result, call_info);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetMemoryMetalHandleEXT(
    const ApiCallInfo&                          call_info,
    args::GetMemoryMetalHandleEXT&              args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkMemoryGetMetalHandleInfoEXT* in_pGetMetalHandleInfo = args.pGetMetalHandleInfo.GetPointer();
    MapStructHandles(args.pGetMetalHandleInfo.GetMetaStructPointer(), GetObjectInfoTable());
    void** out_pHandle = args.pHandle.IsNull() ? nullptr : args.pHandle.AllocateOutputData(1);

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryMetalHandleEXT(in_device, in_pGetMetalHandleInfo, out_pHandle);
    CheckResult("vkGetMemoryMetalHandleEXT", args.result, replay_result, call_info);

    PostProcessExternalObject(replay_result, (*args.pHandle.GetPointer()), *args.pHandle.GetOutputPointer(), format::ApiCallId::ApiCall_vkGetMemoryMetalHandleEXT, "vkGetMemoryMetalHandleEXT");
}

void VulkanReplayConsumer::Process_vkGetMemoryMetalHandlePropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::GetMemoryMetalHandlePropertiesEXT&    args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const void* in_pHandle = PreProcessExternalObject(args.pHandle, format::ApiCallId::ApiCall_vkGetMemoryMetalHandlePropertiesEXT, "vkGetMemoryMetalHandlePropertiesEXT");
    VkMemoryMetalHandlePropertiesEXT* out_pMemoryMetalHandleProperties = args.pMemoryMetalHandleProperties.IsNull() ? nullptr : args.pMemoryMetalHandleProperties.AllocateOutputData(1, { VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT, nullptr });
    InitializeOutputStructPNext(&args.pMemoryMetalHandleProperties);

    VkResult replay_result = GetDeviceTable(in_device)->GetMemoryMetalHandlePropertiesEXT(in_device, args.handleType, in_pHandle, out_pMemoryMetalHandleProperties);
    CheckResult("vkGetMemoryMetalHandlePropertiesEXT", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(
    const ApiCallInfo&                          call_info,
    args::EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    uint32_t* out_pCounterCount = args.pCounterCount.IsNull() ? nullptr : args.pCounterCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM", args.result, args.physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM, &args.pCounterCount, &args.pCounterDescriptions, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkPerformanceCounterARM* out_pCounters = args.pCounters.IsNull() ? nullptr : args.pCounters.AllocateOutputData(*out_pCounterCount, VkPerformanceCounterARM{ VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_ARM, nullptr });
    VkPerformanceCounterDescriptionARM* out_pCounterDescriptions = args.pCounterDescriptions.IsNull() ? nullptr : args.pCounterDescriptions.AllocateOutputData(*out_pCounterCount, VkPerformanceCounterDescriptionARM{ VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_ARM, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(in_physicalDevice, args.queueFamilyIndex, out_pCounterCount, out_pCounters, out_pCounterDescriptions);
    CheckResult("vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM", args.result, replay_result, call_info);

    if (args.pCounters.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM, *out_pCounterCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
    if (args.pCounterDescriptions.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM, *out_pCounterCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdEndRendering2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering2EXT&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkRenderingEndInfoKHR* in_pRenderingEndInfo = args.pRenderingEndInfo.GetPointer();
    MapStructHandles(args.pRenderingEndInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdEndRendering2EXT(in_commandBuffer, in_pRenderingEndInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdEndRendering2EXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pRenderingEndInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdBeginCustomResolveEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginCustomResolveEXT&             args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkBeginCustomResolveInfoEXT* in_pBeginCustomResolveInfo = args.pBeginCustomResolveInfo.GetPointer();
    MapStructHandles(args.pBeginCustomResolveInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdBeginCustomResolveEXT(in_commandBuffer, in_pBeginCustomResolveInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBeginCustomResolveEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pBeginCustomResolveInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkQueueFamilyDataGraphPropertiesARM* in_pQueueFamilyDataGraphProperties = args.pQueueFamilyDataGraphProperties.GetPointer();
    MapStructHandles(args.pQueueFamilyDataGraphProperties.GetMetaStructPointer(), GetObjectInfoTable());
    const VkDataGraphOpticalFlowImageFormatInfoARM* in_pOpticalFlowImageFormatInfo = args.pOpticalFlowImageFormatInfo.GetPointer();
    MapStructHandles(args.pOpticalFlowImageFormatInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pFormatCount = args.pFormatCount.IsNull() ? nullptr : args.pFormatCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM, &args.pFormatCount, &args.pImageFormatProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkDataGraphOpticalFlowImageFormatPropertiesARM* out_pImageFormatProperties = args.pImageFormatProperties.IsNull() ? nullptr : args.pImageFormatProperties.AllocateOutputData(*out_pFormatCount, VkDataGraphOpticalFlowImageFormatPropertiesARM{ VK_STRUCTURE_TYPE_DATA_GRAPH_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_ARM, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(in_physicalDevice, args.queueFamilyIndex, in_pQueueFamilyDataGraphProperties, in_pOpticalFlowImageFormatInfo, out_pFormatCount, out_pImageFormatProperties);
    CheckResult("vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM", args.result, replay_result, call_info);

    if (args.pImageFormatProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM, *out_pFormatCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkQueueFamilyDataGraphPropertiesARM* in_pQueueFamilyDataGraphProperties = args.pQueueFamilyDataGraphProperties.GetPointer();
    MapStructHandles(args.pQueueFamilyDataGraphProperties.GetMetaStructPointer(), GetObjectInfoTable());
    VkBaseOutStructure* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(1);
    InitializeOutputStructPNext(&args.pProperties);

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(in_physicalDevice, args.queueFamilyIndex, in_pQueueFamilyDataGraphProperties, out_pProperties);
    CheckResult("vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdSetComputeOccupancyPriorityNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetComputeOccupancyPriorityNV&     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkComputeOccupancyPriorityParametersNV* in_pParameters = args.pParameters.GetPointer();
    MapStructHandles(args.pParameters.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdSetComputeOccupancyPriorityNV(in_commandBuffer, in_pParameters);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetComputeOccupancyPriorityNV(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pParameters);
    }
}

void VulkanReplayConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixProperties2EXT(
    const ApiCallInfo&                          call_info,
    args::GetPhysicalDeviceCooperativeMatrixProperties2EXT& args)
{
    VkPhysicalDevice in_physicalDevice = MapHandle<VulkanPhysicalDeviceInfo>(args.physicalDevice, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo);
    const VkPhysicalDeviceCooperativeMatrixInfo2EXT* in_pCooperativeMatrixInfo = args.pCooperativeMatrixInfo.GetPointer();
    MapStructHandles(args.pCooperativeMatrixInfo.GetMetaStructPointer(), GetObjectInfoTable());
    uint32_t* out_pPropertyCount = args.pPropertyCount.IsNull() ? nullptr : args.pPropertyCount.AllocateOutputData(1, GetOutputArrayCount<uint32_t, VulkanPhysicalDeviceInfo>("vkGetPhysicalDeviceCooperativeMatrixProperties2EXT", args.result, args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixProperties2EXT, &args.pPropertyCount, &args.pProperties, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo));
    VkCooperativeMatrixProperties2EXT* out_pProperties = args.pProperties.IsNull() ? nullptr : args.pProperties.AllocateOutputData(*out_pPropertyCount, VkCooperativeMatrixProperties2EXT{ VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_2_EXT, nullptr });

    VkResult replay_result = GetInstanceTable(in_physicalDevice)->GetPhysicalDeviceCooperativeMatrixProperties2EXT(in_physicalDevice, in_pCooperativeMatrixInfo, out_pPropertyCount, out_pProperties);
    CheckResult("vkGetPhysicalDeviceCooperativeMatrixProperties2EXT", args.result, replay_result, call_info);

    if (args.pProperties.IsNull()) { SetOutputArrayCount<VulkanPhysicalDeviceInfo>(args.physicalDevice, kPhysicalDeviceArrayGetPhysicalDeviceCooperativeMatrixProperties2EXT, *out_pPropertyCount, &CommonObjectInfoTable::GetVkPhysicalDeviceInfo); }
}

void VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartIndexEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartIndexEXT&       args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetPrimitiveRestartIndexEXT(in_commandBuffer, args.primitiveRestartIndex);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetPrimitiveRestartIndexEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.primitiveRestartIndex);
    }
}

void VulkanReplayConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CreateAccelerationStructureKHR&       args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pCreateInfo.GetMetaStructPointer(), GetObjectInfoTable());
    if (!args.pAccelerationStructure.IsNull()) { args.pAccelerationStructure.SetHandleLength(1); }
    VulkanAccelerationStructureKHRInfo handle_info;
    args.pAccelerationStructure.SetConsumerData(0, &handle_info);

    PushRecaptureHandleId(args.pAccelerationStructure.GetPointer());
    VkResult replay_result = OverrideCreateAccelerationStructureKHR(GetDeviceTable(in_device->handle)->CreateAccelerationStructureKHR, args.result, in_device, &args.pCreateInfo, &args.pAllocator, &args.pAccelerationStructure);
    CheckResult("vkCreateAccelerationStructureKHR", args.result, replay_result, call_info);
    ClearRecaptureHandleIds();

    AddHandle<VulkanAccelerationStructureKHRInfo>(args.device, args.pAccelerationStructure.GetPointer(), args.pAccelerationStructure.GetHandlePointer(), std::move(handle_info), &CommonObjectInfoTable::AddVkAccelerationStructureKHRInfo);
}

void VulkanReplayConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyAccelerationStructureKHR&      args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);
    auto in_accelerationStructure = GetObjectInfoTable().GetVkAccelerationStructureKHRInfo(args.accelerationStructure);

    OverrideDestroyAccelerationStructureKHR(GetDeviceTable(in_device->handle)->DestroyAccelerationStructureKHR, in_device, in_accelerationStructure, &args.pAllocator);
    RemoveHandle(args.accelerationStructure, &CommonObjectInfoTable::RemoveVkAccelerationStructureKHRInfo);
}

void VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresKHR&    args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructArrayHandles(args.pInfos.GetMetaStructPointer(), args.pInfos.GetLength(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdBuildAccelerationStructuresKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.infoCount, &args.pInfos, &args.ppBuildRangeInfos, true);
    }

    OverrideCmdBuildAccelerationStructuresKHR(GetDeviceTable(in_commandBuffer->handle)->CmdBuildAccelerationStructuresKHR, in_commandBuffer, args.infoCount, &args.pInfos, &args.ppBuildRangeInfos);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBuildAccelerationStructuresKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.infoCount, &args.pInfos, &args.ppBuildRangeInfos, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresIndirectKHR& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkAccelerationStructureBuildGeometryInfoKHR* in_pInfos = args.pInfos.GetPointer();
    MapStructArrayHandles(args.pInfos.GetMetaStructPointer(), args.pInfos.GetLength(), GetObjectInfoTable());
    const VkDeviceAddress* in_pIndirectDeviceAddresses = args.pIndirectDeviceAddresses.GetPointer();
    const uint32_t* in_pIndirectStrides = args.pIndirectStrides.GetPointer();
    const uint32_t* const* in_ppMaxPrimitiveCounts = args.ppMaxPrimitiveCounts.GetPointer();

    GetDeviceTable(in_commandBuffer)->CmdBuildAccelerationStructuresIndirectKHR(in_commandBuffer, args.infoCount, in_pInfos, in_pIndirectDeviceAddresses, in_pIndirectStrides, in_ppMaxPrimitiveCounts);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdBuildAccelerationStructuresIndirectKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.infoCount, in_pInfos, in_pIndirectDeviceAddresses, in_pIndirectStrides, in_ppMaxPrimitiveCounts);
    }
}

void VulkanReplayConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CopyAccelerationStructureToMemoryKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(args.deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkCopyAccelerationStructureToMemoryInfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyAccelerationStructureToMemoryKHR(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyAccelerationStructureToMemoryKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CopyMemoryToAccelerationStructureKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkDeferredOperationKHR in_deferredOperation = MapHandle<VulkanDeferredOperationKHRInfo>(args.deferredOperation, &CommonObjectInfoTable::GetVkDeferredOperationKHRInfo);
    const VkCopyMemoryToAccelerationStructureInfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    VkResult replay_result = GetDeviceTable(in_device)->CopyMemoryToAccelerationStructureKHR(in_device, in_deferredOperation, in_pInfo);
    CheckResult("vkCopyMemoryToAccelerationStructureKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::WriteAccelerationStructuresPropertiesKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAccelerationStructureKHR* in_pAccelerationStructures = MapHandles<VulkanAccelerationStructureKHRInfo>(&args.pAccelerationStructures, args.accelerationStructureCount, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);
    void* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(args.dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->WriteAccelerationStructuresPropertiesKHR(in_device, args.accelerationStructureCount, in_pAccelerationStructures, args.queryType, args.dataSize, out_pData, args.stride);
    CheckResult("vkWriteAccelerationStructuresPropertiesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureKHR&      args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    if (options_.dumping_resources && options_.dump_resources_before)
    {
        resource_dumper_->Process_vkCmdCopyAccelerationStructureKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pInfo, true);
    }

    OverrideCmdCopyAccelerationStructureKHR(GetDeviceTable(in_commandBuffer->handle)->CmdCopyAccelerationStructureKHR, in_commandBuffer, &args.pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyAccelerationStructureKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pInfo, false);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureToMemoryKHR& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyAccelerationStructureToMemoryInfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyAccelerationStructureToMemoryKHR(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyAccelerationStructureToMemoryKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToAccelerationStructureKHR& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    const VkCopyMemoryToAccelerationStructureInfoKHR* in_pInfo = args.pInfo.GetPointer();
    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    GetDeviceTable(in_commandBuffer)->CmdCopyMemoryToAccelerationStructureKHR(in_commandBuffer, in_pInfo);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdCopyMemoryToAccelerationStructureKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_pInfo);
    }
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureDeviceAddressKHR& args)
{
    auto in_device = GetObjectInfoTable().GetVkDeviceInfo(args.device);

    MapStructHandles(args.pInfo.GetMetaStructPointer(), GetObjectInfoTable());

    OverrideGetAccelerationStructureDeviceAddressKHR(GetDeviceTable(in_device->handle)->GetAccelerationStructureDeviceAddressKHR, args.result, in_device, &args.pInfo);
}

void VulkanReplayConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesKHR& args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
    MapHandles<VulkanAccelerationStructureKHRInfo>(&args.pAccelerationStructures, args.accelerationStructureCount, &CommonObjectInfoTable::GetVkAccelerationStructureKHRInfo);
    auto in_queryPool = GetObjectInfoTable().GetVkQueryPoolInfo(args.queryPool);

    OverrideCmdWriteAccelerationStructuresPropertiesKHR(GetDeviceTable(in_commandBuffer->handle)->CmdWriteAccelerationStructuresPropertiesKHR, in_commandBuffer, args.accelerationStructureCount, &args.pAccelerationStructures, args.queryType, in_queryPool, args.firstQuery);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdWriteAccelerationStructuresPropertiesKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, args.accelerationStructureCount, &args.pAccelerationStructures, args.queryType, in_queryPool, args.firstQuery);
    }
}

void VulkanReplayConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    args::GetDeviceAccelerationStructureCompatibilityKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAccelerationStructureVersionInfoKHR* in_pVersionInfo = args.pVersionInfo.GetPointer();
    MapStructHandles(args.pVersionInfo.GetMetaStructPointer(), GetObjectInfoTable());
    VkAccelerationStructureCompatibilityKHR* out_pCompatibility = args.pCompatibility.IsNull() ? nullptr : args.pCompatibility.AllocateOutputData(1, static_cast<VkAccelerationStructureCompatibilityKHR>(0));

    GetDeviceTable(in_device)->GetDeviceAccelerationStructureCompatibilityKHR(in_device, in_pVersionInfo, out_pCompatibility);
}

void VulkanReplayConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo&                          call_info,
    args::GetAccelerationStructureBuildSizesKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    const VkAccelerationStructureBuildGeometryInfoKHR* in_pBuildInfo = args.pBuildInfo.GetPointer();
    MapStructHandles(args.pBuildInfo.GetMetaStructPointer(), GetObjectInfoTable());
    const uint32_t* in_pMaxPrimitiveCounts = args.pMaxPrimitiveCounts.GetPointer();
    VkAccelerationStructureBuildSizesInfoKHR* out_pSizeInfo = args.pSizeInfo.IsNull() ? nullptr : args.pSizeInfo.AllocateOutputData(1, { VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR, nullptr });
    InitializeOutputStructPNext(&args.pSizeInfo);

    GetDeviceTable(in_device)->GetAccelerationStructureBuildSizesKHR(in_device, args.buildType, in_pBuildInfo, in_pMaxPrimitiveCounts, out_pSizeInfo);
}

void VulkanReplayConsumer::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysKHR&                      args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    OverrideCmdTraceRaysKHR(GetDeviceTable(in_commandBuffer->handle)->CmdTraceRaysKHR, in_commandBuffer, &args.pRaygenShaderBindingTable, &args.pMissShaderBindingTable, &args.pHitShaderBindingTable, &args.pCallableShaderBindingTable, args.width, args.height, args.depth);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdTraceRaysKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pRaygenShaderBindingTable, &args.pMissShaderBindingTable, &args.pHitShaderBindingTable, &args.pCallableShaderBindingTable, args.width, args.height, args.depth);
    }
}

void VulkanReplayConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingCaptureReplayShaderGroupHandlesKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(args.pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);
    void* out_pData = args.pData.IsNull() ? nullptr : args.pData.AllocateOutputData(args.dataSize);

    VkResult replay_result = GetDeviceTable(in_device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR(in_device, in_pipeline, args.firstGroup, args.groupCount, args.dataSize, out_pData);
    CheckResult("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", args.result, replay_result, call_info);
}

void VulkanReplayConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysIndirectKHR&              args)
{
    auto in_commandBuffer = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);

    OverrideCmdTraceRaysIndirectKHR(GetDeviceTable(in_commandBuffer->handle)->CmdTraceRaysIndirectKHR, in_commandBuffer, &args.pRaygenShaderBindingTable, &args.pMissShaderBindingTable, &args.pHitShaderBindingTable, &args.pCallableShaderBindingTable, args.indirectDeviceAddress);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdTraceRaysIndirectKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer->handle), in_commandBuffer->handle, &args.pRaygenShaderBindingTable, &args.pMissShaderBindingTable, &args.pHitShaderBindingTable, &args.pCallableShaderBindingTable, args.indirectDeviceAddress);
    }
}

void VulkanReplayConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    const ApiCallInfo&                          call_info,
    args::GetRayTracingShaderGroupStackSizeKHR& args)
{
    VkDevice in_device = MapHandle<VulkanDeviceInfo>(args.device, &CommonObjectInfoTable::GetVkDeviceInfo);
    VkPipeline in_pipeline = MapHandle<VulkanPipelineInfo>(args.pipeline, &CommonObjectInfoTable::GetVkPipelineInfo);

    GetDeviceTable(in_device)->GetRayTracingShaderGroupStackSizeKHR(in_device, in_pipeline, args.group, args.groupShader);
}

void VulkanReplayConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRayTracingPipelineStackSizeKHR& args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdSetRayTracingPipelineStackSizeKHR(in_commandBuffer, args.pipelineStackSize);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdSetRayTracingPipelineStackSizeKHR(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.pipelineStackSize);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksEXT&                  args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksEXT(in_commandBuffer, args.groupCountX, args.groupCountY, args.groupCountZ);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawMeshTasksEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, args.groupCountX, args.groupCountY, args.groupCountZ);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectEXT&          args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectEXT(in_commandBuffer, in_buffer, args.offset, args.drawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawMeshTasksIndirectEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_buffer, args.offset, args.drawCount, args.stride);
    }
}

void VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountEXT&     args)
{
    VkCommandBuffer in_commandBuffer = MapHandle<VulkanCommandBufferInfo>(args.commandBuffer, &CommonObjectInfoTable::GetVkCommandBufferInfo);
    VkBuffer in_buffer = MapHandle<VulkanBufferInfo>(args.buffer, &CommonObjectInfoTable::GetVkBufferInfo);
    VkBuffer in_countBuffer = MapHandle<VulkanBufferInfo>(args.countBuffer, &CommonObjectInfoTable::GetVkBufferInfo);

    GetDeviceTable(in_commandBuffer)->CmdDrawMeshTasksIndirectCountEXT(in_commandBuffer, in_buffer, args.offset, in_countBuffer, args.countBufferOffset, args.maxDrawCount, args.stride);

    if (options_.dumping_resources)
    {
        resource_dumper_->Process_vkCmdDrawMeshTasksIndirectCountEXT(call_info, GetInjectedDeviceCalls(in_commandBuffer), in_commandBuffer, in_buffer, args.offset, in_countBuffer, args.countBufferOffset, args.maxDrawCount, args.stride);
    }
}

void InitializeOutputStructPNextImpl(const VkBaseInStructure* in_pnext, VkBaseOutStructure* output_struct)
{
    while(in_pnext)
    {
        switch(in_pnext->sType)
        {
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
            case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkEventCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferViewCreateInfo>());
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
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineColorBlendStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineDepthStencilStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineDynamicStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineInputAssemblyStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineMultisampleStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRasterizationStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineTessellationStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineVertexInputStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineViewportStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGraphicsPipelineCreateInfo>());
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
            case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassBeginInfo>());
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
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewUsageCreateInfo>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSubgroupProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevice16BitStorageFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVariablePointersFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorUpdateTemplateCreateInfo>());
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
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceGroupRenderPassBeginInfo>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderDrawParametersFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDriverProperties>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVulkanMemoryModelFeatures>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevice8BitStorageFeatures>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceScalarBlockLayoutFeatures>());
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
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassCreateInfo2>());
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
            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageStencilUsageCreateInfo>());
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
            case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassAttachmentBeginInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFramebufferAttachmentsCreateInfo>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceToolProperties>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTextureCompressionASTCHDRFeatures>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineCreationCacheControlFeatures>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVulkan14Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVulkan14Properties>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceQueueGlobalPriorityCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceGlobalPriorityQueryFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyGlobalPriorityProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceIndexTypeUint8Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryMapInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryUnmapInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance5Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance5Properties>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubresourceLayout2>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageSubresource2>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceImageSubresourceInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferUsageFlags2CreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance6Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance6Properties>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindMemoryStatus>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceHostImageCopyFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceHostImageCopyProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryToImageCopy>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageToMemoryCopy>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyMemoryToImageInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyImageToMemoryInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyImageToImageInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkHostImageLayoutTransitionInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSubresourceHostMemcpySize>());
                break;
            }
            case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkHostImageCopyDevicePerformanceQuery>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderSubgroupRotateFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderFloatControls2Features>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderExpectAssumeFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineCreateFlags2CreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePushDescriptorProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindDescriptorSetsInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPushConstantsInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPushDescriptorSetInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPushDescriptorSetWithTemplateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineProtectedAccessFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineRobustnessFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineRobustnessProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRobustnessCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLineRasterizationFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceLineRasterizationProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineRasterizationLineStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVertexAttributeDivisorProperties>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineVertexInputDivisorStateCreateInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVertexAttributeDivisorFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingAreaInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDynamicRenderingLocalReadFeatures>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingAttachmentLocationInfo>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingInputAttachmentIndexInfo>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderBfloat16FeaturesKHR>());
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
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingFragmentShadingRateAttachmentInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CONSTANT_DATA_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderConstantDataFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderAbortFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_FAULT_SHADER_ABORT_MESSAGE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceFaultShaderAbortMessageInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderAbortPropertiesKHR>());
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
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_COPY_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceMemoryCopyKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_DEVICE_MEMORY_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyDeviceMemoryInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_IMAGE_COPY_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceMemoryImageCopyKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_DEVICE_MEMORY_IMAGE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyDeviceMemoryImageInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_RANGE_BARRIER_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryRangeBarrierKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_RANGE_BARRIERS_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryRangeBarriersInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_ADDRESS_COMMANDS_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_INDEX_BUFFER_3_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindIndexBuffer3InfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_VERTEX_BUFFER_3_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindVertexBuffer3InfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DRAW_INDIRECT_2_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDrawIndirect2InfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DRAW_INDIRECT_COUNT_2_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDrawIndirectCount2InfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPATCH_INDIRECT_2_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDispatchIndirect2InfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_2_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkConditionalRenderingBeginInfo2EXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_TRANSFORM_FEEDBACK_BUFFER_2_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindTransformFeedbackBuffer2InfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_MARKER_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryMarkerInfoAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureCreateInfo2KHR>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderUntypedPointersFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfaceCapabilitiesPresentId2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPresentId2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePresentId2FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfaceCapabilitiesPresentWait2KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePresentWait2FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_WAIT_2_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPresentWait2InfoKHR>());
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
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfacePresentModeKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfacePresentScalingCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSurfacePresentModeCompatibilityKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainPresentFenceInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainPresentModesCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainPresentModeInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainPresentScalingCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkReleaseSwapchainImagesInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INTERNALLY_SYNCHRONIZED_QUEUES_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVideoEncodeAV1FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1CapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1QualityLevelPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1SessionCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1SessionParametersCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1PictureInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1DpbSlotInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1ProfileInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1GopRemainingFrameInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1RateControlInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1RateControlLayerInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVideoDecodeVP9FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeVP9ProfileInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeVP9CapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoDecodeVP9PictureInfoKHR>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAttachmentFeedbackLoopInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCalibratedTimestampInfoKHR>());
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
            case VK_STRUCTURE_TYPE_COPY_MEMORY_INDIRECT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyMemoryIndirectInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INDIRECT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyMemoryToImageIndirectInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeIntraRefreshCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeSessionIntraRefreshCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeIntraRefreshInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoReferenceIntraRefreshInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeQuantizationMapCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoFormatQuantizationMapPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeQuantizationMapInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH264QuantizationMapCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeH265QuantizationMapCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoFormatH265QuantizationMapPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeAV1QuantizationMapCapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoFormatAV1QuantizationMapPropertiesKHR>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFaultFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFaultPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceFaultInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_FAULT_DEBUG_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceFaultDebugInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryBarrierAccessFlags3KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance8FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderFmaFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance9FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance9PropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyOwnershipTransferPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_FEEDBACK_2_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_FEEDBACK_2_CAPABILITIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeFeedback2CapabilitiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_PER_PARTITION_FEEDBACK_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDepthClampZeroOneFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRobustness2FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRobustness2PropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MICROMAP_DATA_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureGeometryMicromapDataKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceOpacityMicromapFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceOpacityMicromapPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureTrianglesOpacityMicromapKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance10FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance10PropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_END_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingEndInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingAttachmentFlagsInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkResolveImageModeInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_11_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMaintenance11FeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OPTIMAL_IMAGE_TRANSFER_GRANULARITY_PROPERTIES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_4_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFormatProperties4KHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_USAGE_FLAGS_2_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageUsageFlags2CreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_CREATE_FLAGS_2_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageCreateFlags2CreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_2_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewUsage2CreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_FLAGS_FEATURES_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExtendedFlagsFeaturesKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_2_CREATE_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageStencilUsage2CreateInfoKHR>());
                break;
            }
            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_2_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSharedPresentSurfaceCapabilities2KHR>());
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
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMultiviewPerViewAttributesInfoNVX>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_FEATURES_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceGpaFeaturesAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_PROPERTIES_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceGpaPropertiesAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_PROPERTIES_2_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceGpaProperties2AMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_GPA_SAMPLE_BEGIN_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGpaSampleBeginInfoAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_GPA_DEVICE_CLOCK_MODE_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGpaDeviceClockModeInfoAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_GPA_DEVICE_GET_CLOCK_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGpaDeviceGetClockInfoAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_GPA_SESSION_CREATE_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkGpaSessionCreateInfoAMD>());
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAttachmentSampleCountInfoAMD>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_CONVERSION_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ELAPSED_TIMER_QUERY_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePresentTimingFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_TIMING_SURFACE_CAPABILITIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPresentTimingSurfaceCapabilitiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_CALIBRATED_TIMESTAMP_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainCalibratedTimestampInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_TIMING_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainTimingPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_TIME_DOMAIN_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainTimeDomainPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPastPresentationTimingInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPastPresentationTimingEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPastPresentationTimingPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_TIMING_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPresentTimingInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_TIMINGS_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPresentTimingsInfoEXT>());
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
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderingFragmentDensityMapAttachmentInfoEXT>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_3D_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT>());
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
            case VK_STRUCTURE_TYPE_PERF_HINT_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerfHintInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceQueuePerfHintFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_PROPERTIES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceQueuePerfHintPropertiesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_3_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageProcessing3FeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MULTIPLE_WAIT_QUEUES_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MULTIPLE_WAIT_QUEUES_PROPERTIES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SPLIT_BARRIER_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderSplitBarrierFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SPLIT_BARRIER_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderSplitBarrierPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTileShadingFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTileShadingPropertiesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassTileShadingCreateInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerTileBeginInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PER_TILE_END_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerTileEndInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPATCH_TILE_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDispatchTileInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDescriptorBufferPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDescriptorBufferFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorAddressInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorBufferBindingInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorBufferBindingPushDescriptorBufferHandleEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorGetInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBufferCaptureDescriptorDataInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageCaptureDescriptorDataInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageViewCaptureDescriptorDataInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSamplerCaptureDescriptorDataInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkOpaqueCaptureDescriptorDataCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureCaptureDescriptorDataInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeRgbConversionCapabilitiesVALVE>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeProfileRgbConversionInfoVALVE>());
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkVideoEncodeSessionRgbConversionCreateInfoVALVE>());
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
            case VK_STRUCTURE_TYPE_DISPATCH_PARAMETERS_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDispatchParametersARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_DISPATCH_PARAMETERS_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassFragmentDensityMapOffsetEndInfoEXT>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureGeometryLinearSweptSpheresDataNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureGeometrySpheresDataNV>());
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
            case VK_STRUCTURE_TYPE_TENSOR_DESCRIPTION_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorDescriptionARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_VIEW_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorViewCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_MEMORY_REQUIREMENTS_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorMemoryRequirementsInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_TENSOR_MEMORY_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindTensorMemoryInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_TENSOR_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWriteDescriptorSetTensorARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_FORMAT_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorFormatPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTensorPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorMemoryBarrierARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorDependencyInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTensorFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_TENSOR_MEMORY_REQUIREMENTS_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDeviceTensorMemoryRequirementsARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_COPY_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorCopyARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_TENSOR_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCopyTensorInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_TENSOR_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryDedicatedAllocateInfoTensorARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_TENSOR_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceExternalTensorInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_TENSOR_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalTensorPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_TENSOR_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkExternalMemoryTensorCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDescriptorBufferTensorFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDescriptorBufferTensorPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_GET_TENSOR_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDescriptorGetTensorInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_CAPTURE_DESCRIPTOR_DATA_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorCaptureDescriptorDataInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorViewCaptureDescriptorDataInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_TENSORS_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkFrameBoundaryTensorsARM>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeVectorPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeVectorFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCooperativeVectorPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkConvertCooperativeVectorMatrixInfoNV>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDataGraphFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineConstantARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineResourceInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_COMPILER_CONTROL_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineCompilerControlCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineShaderModuleCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineSessionCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineSessionBindPointRequirementsInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineSessionBindPointRequirementARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineSessionMemoryRequirementsInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBindDataGraphPipelineSessionMemoryInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_PROPERTY_QUERY_RESULT_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelinePropertyQueryResultARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_IDENTIFIER_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineIdentifierCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_DISPATCH_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineDispatchInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyDataGraphPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PROCESSING_ENGINE_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphProcessingEngineCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyDataGraphProcessingEnginePropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_TENSOR_SEMI_STRUCTURED_SPARSITY_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTileMemoryHeapFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceTileMemoryHeapPropertiesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTileMemoryRequirementsQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTileMemoryBindInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTileMemorySizeInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DECOMPRESS_MEMORY_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDecompressMemoryInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMemoryDecompressionFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMemoryDecompressionPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplaySurfaceStereoCreateInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDisplayModeStereoPropertiesNV>());
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
            case VK_STRUCTURE_TYPE_TENSOR_ROLLING_BACKING_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorRollingBackingCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_EXPLICIT_TILING_FORMAT_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkTensorExplicitTilingFormatPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderFloat8FeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingValidationFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPartitionedAccelerationStructureFlagsNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkWriteDescriptorSetPartitionedAccelerationStructureNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPartitionedAccelerationStructureInstancesInputNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBuildPartitionedAccelerationStructureInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkAccelerationStructureBuildSizesInfoKHR>());
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
            case VK_STRUCTURE_TYPE_PUSH_CONSTANT_BANK_INFO_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPushConstantBankInfoNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePushConstantBankFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePushConstantBankPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT>());
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceHdrVividFeaturesHUAWEI>());
                break;
            }
            case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkHdrVividDynamicMetadataHUAWEI>());
                break;
            }
            case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCooperativeMatrixFlexibleDimensionsPropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeMatrix2FeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeMatrix2PropertiesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineOpacityMicromapFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImportMemoryMetalHandleInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryMetalHandlePropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkMemoryGetMetalHandleInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePerformanceCountersByRegionFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePerformanceCountersByRegionPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerformanceCounterARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPerformanceCounterDescriptionARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkRenderPassPerformanceCountersByRegionBeginInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFormatPackFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE>());
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPipelineFragmentDensityMapLayeredCreateInfoVALVE>());
                break;
            }
            case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSetPresentConfigNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePresentMeteringFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SWAPCHAIN_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_FLAGS_SURFACE_CAPABILITIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkSwapchainFlagsSurfaceCapabilitiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShader64BitIndexingFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCustomResolveFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_BEGIN_CUSTOM_RESOLVE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkBeginCustomResolveInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCustomResolveCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_BUILTIN_MODEL_CREATE_INFO_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineBuiltinModelCreateInfoQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDataGraphModelFeaturesQCOM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_OPTICAL_FLOW_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_OPTICAL_FLOW_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkQueueFamilyDataGraphOpticalFlowPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineOpticalFlowCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphOpticalFlowImageFormatPropertiesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_OPTICAL_FLOW_IMAGE_FORMAT_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphOpticalFlowImageFormatInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_DISPATCH_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineOpticalFlowDispatchInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_IMAGE_LAYOUT_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineResourceInfoImageLayoutARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CONNECTION_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineSingleNodeConnectionARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineSingleNodeCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderLongVectorFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_PROPERTIES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderLongVectorPropertiesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_COMPUTE_OCCUPANCY_PRIORITY_PARAMETERS_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkComputeOccupancyPriorityParametersNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_OCCUPANCY_PRIORITY_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_2_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkCooperativeMatrixProperties2EXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_INFO_2_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeMatrixInfo2EXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_MAINTENANCE_1_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_PARTITIONED_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OCP_MICROSCALING_TYPES_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MIXED_FLOAT_DOT_PRODUCT_FEATURES_VALVE:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE>());
                break;
            }
            case VK_STRUCTURE_TYPE_THROTTLE_HINT_SUBMIT_INFO_SEC:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkThrottleHintSubmitInfoSEC>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_THROTTLE_HINT_FEATURES_SEC:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceThrottleHintFeaturesSEC>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_NEURAL_ACCELERATOR_STATISTICS_FEATURES_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_NEURAL_STATISTICS_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineNeuralStatisticsCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_NEURAL_STATISTICS_CREATE_INFO_ARM:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_RESTART_INDEX_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_TILING_CONTROL_FEATURES_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceImageTilingControlFeaturesEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_TILING_CONTROL_CREATE_INFO_EXT:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkImageTilingControlCreateInfoEXT>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_DECODE_VECTOR_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV>());
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_BASE_HANDLE_FEATURES_NV:
            {
                output_struct->pNext = reinterpret_cast<VkBaseOutStructure*>(DecodeAllocator::Allocate<VkPhysicalDevicePrivateDataBaseHandleFeaturesNV>());
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
