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

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/api_call_id.h"
#include "format/trace_manager.h"
#include "format/parameter_encoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance)
{
    VkResult result = dispatch_CreateInstance(pCreateInfo, pAllocator, pInstance);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateInstance);
    if (encoder)
    {
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pInstance);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyInstance(
    VkInstance                                  instance,
    const VkAllocationCallbacks*                pAllocator)
{
    get_instance_table(instance)->DestroyInstance(instance, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyInstance);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
{
    VkResult result = get_instance_table(instance)->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkEnumeratePhysicalDevices);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceCount);
        encoder->EncodeHandleArray(pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceFeatures(physicalDevice, pFeatures);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFeatures);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encode_struct_ptr(encoder, pFormatProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkImageFormatProperties*                    pImageFormatProperties)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        encode_struct_ptr(encoder, pImageFormatProperties);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceProperties(physicalDevice, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceMemoryProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pMemoryProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
{
    VkResult result = dispatch_CreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateDevice);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDevice);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDevice(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyDevice(device, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyDevice);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue)
{
    get_device_table(device)->GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceQueue);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeUInt32Value(queueIndex);
        encoder->EncodeHandlePtr(pQueue);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence)
{
    VkResult result = get_device_table(queue)->QueueSubmit(queue, submitCount, pSubmits, fence);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkQueueSubmit);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Value(submitCount);
        encode_struct_array(encoder, pSubmits, submitCount);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(
    VkQueue                                     queue)
{
    VkResult result = get_device_table(queue)->QueueWaitIdle(queue);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkQueueWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(
    VkDevice                                    device)
{
    VkResult result = get_device_table(device)->DeviceWaitIdle(device);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDeviceWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory)
{
    VkResult result = get_device_table(device)->AllocateMemory(device, pAllocateInfo, pAllocator, pMemory);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkAllocateMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pAllocateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pMemory);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->FreeMemory(device, memory, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkFreeMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL MapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    void**                                      ppData)
{
    VkResult result = get_device_table(device)->MapMemory(device, memory, offset, size, flags, ppData);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkMapMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeVoidPtrPtr(ppData);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL UnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory)
{
    get_device_table(device)->UnmapMemory(device, memory);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkUnmapMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    VkResult result = get_device_table(device)->FlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkFlushMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        encode_struct_array(encoder, pMemoryRanges, memoryRangeCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    VkResult result = get_device_table(device)->InvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkInvalidateMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        encode_struct_array(encoder, pMemoryRanges, memoryRangeCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize*                               pCommittedMemoryInBytes)
{
    get_device_table(device)->GetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceMemoryCommitment);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizePtr(pCommittedMemoryInBytes);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    VkResult result = get_device_table(device)->BindBufferMemory(device, buffer, memory, memoryOffset);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkBindBufferMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    VkResult result = get_device_table(device)->BindImageMemory(device, image, memory, memoryOffset);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkBindImageMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    get_device_table(device)->GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetBufferMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(buffer);
        encode_struct_ptr(encoder, pMemoryRequirements);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    get_device_table(device)->GetImageMemoryRequirements(device, image, pMemoryRequirements);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetImageMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        encode_struct_ptr(encoder, pMemoryRequirements);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements*            pSparseMemoryRequirements)
{
    get_device_table(device)->GetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetImageSparseMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties*              pProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(samples);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse(
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const VkBindSparseInfo*                     pBindInfo,
    VkFence                                     fence)
{
    VkResult result = get_device_table(queue)->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkQueueBindSparse);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfo, bindInfoCount);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    VkResult result = get_device_table(device)->CreateFence(device, pCreateInfo, pAllocator, pFence);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateFence);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFence);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyFence(device, fence, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyFence);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(fence);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL ResetFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences)
{
    VkResult result = get_device_table(device)->ResetFences(device, fenceCount, pFences);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkResetFences);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleArray(pFences, fenceCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(
    VkDevice                                    device,
    VkFence                                     fence)
{
    VkResult result = get_device_table(device)->GetFenceStatus(device, fence);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetFenceStatus);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    VkResult result = get_device_table(device)->WaitForFences(device, fenceCount, pFences, waitAll, timeout);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkWaitForFences);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleArray(pFences, fenceCount);
        encoder->EncodeVkBool32Value(waitAll);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore)
{
    VkResult result = get_device_table(device)->CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateSemaphore);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSemaphore);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroySemaphore(device, semaphore, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroySemaphore);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(semaphore);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent)
{
    VkResult result = get_device_table(device)->CreateEvent(device, pCreateInfo, pAllocator, pEvent);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pEvent);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyEvent(device, event, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(
    VkDevice                                    device,
    VkEvent                                     event)
{
    VkResult result = get_device_table(device)->GetEventStatus(device, event);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetEventStatus);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    VkResult result = get_device_table(device)->SetEvent(device, event);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    VkResult result = get_device_table(device)->ResetEvent(device, event);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool)
{
    VkResult result = get_device_table(device)->CreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pQueryPool);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyQueryPool(device, queryPool, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(queryPool);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    void*                                       pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    VkResult result = get_device_table(device)->GetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetQueryPoolResults);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        encoder->EncodeVkDeviceSizeValue(stride);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer)
{
    VkResult result = get_device_table(device)->CreateBuffer(device, pCreateInfo, pAllocator, pBuffer);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pBuffer);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyBuffer(device, buffer, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(buffer);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView)
{
    VkResult result = get_device_table(device)->CreateBufferView(device, pCreateInfo, pAllocator, pView);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateBufferView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pView);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyBufferView(device, bufferView, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyBufferView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(bufferView);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage)
{
    VkResult result = get_device_table(device)->CreateImage(device, pCreateInfo, pAllocator, pImage);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pImage);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyImage(device, image, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout)
{
    get_device_table(device)->GetImageSubresourceLayout(device, image, pSubresource, pLayout);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetImageSubresourceLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        encode_struct_ptr(encoder, pSubresource);
        encode_struct_ptr(encoder, pLayout);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView)
{
    VkResult result = get_device_table(device)->CreateImageView(device, pCreateInfo, pAllocator, pView);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateImageView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pView);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyImageView(device, imageView, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyImageView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(imageView);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule)
{
    VkResult result = get_device_table(device)->CreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateShaderModule);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pShaderModule);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyShaderModule(device, shaderModule, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyShaderModule);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(shaderModule);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache)
{
    VkResult result = get_device_table(device)->CreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreatePipelineCache);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pPipelineCache);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyPipelineCache(device, pipelineCache, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyPipelineCache);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    VkResult result = get_device_table(device)->GetPipelineCacheData(device, pipelineCache, pDataSize, pData);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPipelineCacheData);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeSizeTPtr(pDataSize);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL MergePipelineCaches(
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const VkPipelineCache*                      pSrcCaches)
{
    VkResult result = get_device_table(device)->MergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkMergePipelineCaches);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleArray(pSrcCaches, srcCacheCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    VkResult result = get_device_table(device)->CreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateGraphicsPipelines);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        encode_struct_array(encoder, pCreateInfos, createInfoCount);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandleArray(pPipelines, createInfoCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    VkResult result = get_device_table(device)->CreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateComputePipelines);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        encode_struct_array(encoder, pCreateInfos, createInfoCount);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandleArray(pPipelines, createInfoCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyPipeline(device, pipeline, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyPipeline);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout)
{
    VkResult result = get_device_table(device)->CreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreatePipelineLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pPipelineLayout);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyPipelineLayout(device, pipelineLayout, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyPipelineLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineLayout);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler)
{
    VkResult result = get_device_table(device)->CreateSampler(device, pCreateInfo, pAllocator, pSampler);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateSampler);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSampler);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroySampler(device, sampler, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroySampler);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(sampler);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorSetLayout*                      pSetLayout)
{
    VkResult result = get_device_table(device)->CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateDescriptorSetLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSetLayout);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyDescriptorSetLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorSetLayout);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool)
{
    VkResult result = get_device_table(device)->CreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDescriptorPool);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyDescriptorPool(device, descriptorPool, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorPool);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    VkResult result = get_device_table(device)->ResetDescriptorPool(device, descriptorPool, flags);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkResetDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorPool);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(
    VkDevice                                    device,
    const VkDescriptorSetAllocateInfo*          pAllocateInfo,
    VkDescriptorSet*                            pDescriptorSets)
{
    VkResult result = get_device_table(device)->AllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkAllocateDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pAllocateInfo);
        encoder->EncodeHandleArray(pDescriptorSets, pAllocateInfo->descriptorSetCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets)
{
    VkResult result = get_device_table(device)->FreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkFreeDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorPool);
        encoder->EncodeUInt32Value(descriptorSetCount);
        encoder->EncodeHandleArray(pDescriptorSets, descriptorSetCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(
    VkDevice                                    device,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const VkCopyDescriptorSet*                  pDescriptorCopies)
{
    get_device_table(device)->UpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkUpdateDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        encode_struct_array(encoder, pDescriptorWrites, descriptorWriteCount);
        encoder->EncodeUInt32Value(descriptorCopyCount);
        encode_struct_array(encoder, pDescriptorCopies, descriptorCopyCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFramebuffer*                              pFramebuffer)
{
    VkResult result = get_device_table(device)->CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateFramebuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFramebuffer);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyFramebuffer(device, framebuffer, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyFramebuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(framebuffer);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    VkResult result = get_device_table(device)->CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pRenderPass);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyRenderPass(device, renderPass, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(renderPass);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity)
{
    get_device_table(device)->GetRenderAreaGranularity(device, renderPass, pGranularity);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetRenderAreaGranularity);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(renderPass);
        encode_struct_ptr(encoder, pGranularity);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool)
{
    VkResult result = get_device_table(device)->CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pCommandPool);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyCommandPool(device, commandPool, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags)
{
    VkResult result = get_device_table(device)->ResetCommandPool(device, commandPool, flags);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkResetCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(
    VkDevice                                    device,
    const VkCommandBufferAllocateInfo*          pAllocateInfo,
    VkCommandBuffer*                            pCommandBuffers)
{
    VkResult result = get_device_table(device)->AllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkAllocateCommandBuffers);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pAllocateInfo);
        encoder->EncodeHandleArray(pCommandBuffers, pAllocateInfo->commandBufferCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    get_device_table(device)->FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkFreeCommandBuffers);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleArray(pCommandBuffers, commandBufferCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo)
{
    VkResult result = get_device_table(commandBuffer)->BeginCommandBuffer(commandBuffer, pBeginInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkBeginCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pBeginInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(
    VkCommandBuffer                             commandBuffer)
{
    VkResult result = get_device_table(commandBuffer)->EndCommandBuffer(commandBuffer);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkEndCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    VkResult result = get_device_table(commandBuffer)->ResetCommandBuffer(commandBuffer, flags);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkResetCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{
    get_device_table(commandBuffer)->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdBindPipeline);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleValue(pipeline);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    get_device_table(commandBuffer)->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetViewport);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        encode_struct_array(encoder, pViewports, viewportCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    get_device_table(commandBuffer)->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetScissor);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstScissor);
        encoder->EncodeUInt32Value(scissorCount);
        encode_struct_array(encoder, pScissors, scissorCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{
    get_device_table(commandBuffer)->CmdSetLineWidth(commandBuffer, lineWidth);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetLineWidth);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatValue(lineWidth);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    get_device_table(commandBuffer)->CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetDepthBias);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatValue(depthBiasConstantFactor);
        encoder->EncodeFloatValue(depthBiasClamp);
        encoder->EncodeFloatValue(depthBiasSlopeFactor);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4])
{
    get_device_table(commandBuffer)->CmdSetBlendConstants(commandBuffer, blendConstants);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetBlendConstants);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatArray(blendConstants, 4);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    get_device_table(commandBuffer)->CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetDepthBounds);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatValue(minDepthBounds);
        encoder->EncodeFloatValue(maxDepthBounds);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    get_device_table(commandBuffer)->CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetStencilCompareMask);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(compareMask);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    get_device_table(commandBuffer)->CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetStencilWriteMask);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(writeMask);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    get_device_table(commandBuffer)->CmdSetStencilReference(commandBuffer, faceMask, reference);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetStencilReference);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(reference);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets)
{
    get_device_table(commandBuffer)->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdBindDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleValue(layout);
        encoder->EncodeUInt32Value(firstSet);
        encoder->EncodeUInt32Value(descriptorSetCount);
        encoder->EncodeHandleArray(pDescriptorSets, descriptorSetCount);
        encoder->EncodeUInt32Value(dynamicOffsetCount);
        encoder->EncodeUInt32Array(pDynamicOffsets, dynamicOffsetCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    get_device_table(commandBuffer)->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdBindIndexBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeEnumValue(indexType);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets)
{
    get_device_table(commandBuffer)->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdBindVertexBuffers);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    get_device_table(commandBuffer)->CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDraw);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(vertexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstVertex);
        encoder->EncodeUInt32Value(firstInstance);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    get_device_table(commandBuffer)->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndexed);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(indexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstIndex);
        encoder->EncodeInt32Value(vertexOffset);
        encoder->EncodeUInt32Value(firstInstance);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    get_device_table(commandBuffer)->CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndirect);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    get_device_table(commandBuffer)->CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndexedIndirect);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    get_device_table(commandBuffer)->CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDispatch);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    get_device_table(commandBuffer)->CmdDispatchIndirect(commandBuffer, buffer, offset);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDispatchIndirect);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions)
{
    get_device_table(commandBuffer)->CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdCopyBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcBuffer);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions)
{
    get_device_table(commandBuffer)->CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdCopyImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter)
{
    get_device_table(commandBuffer)->CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdBlitImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        encoder->EncodeEnumValue(filter);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    get_device_table(commandBuffer)->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdCopyBufferToImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcBuffer);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    get_device_table(commandBuffer)->CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdCopyImageToBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData)
{
    get_device_table(commandBuffer)->CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdUpdateBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    get_device_table(commandBuffer)->CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdFillBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeUInt32Value(data);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    get_device_table(commandBuffer)->CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdClearColorImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(image);
        encoder->EncodeEnumValue(imageLayout);
        encode_struct_ptr(encoder, pColor);
        encoder->EncodeUInt32Value(rangeCount);
        encode_struct_array(encoder, pRanges, rangeCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    get_device_table(commandBuffer)->CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdClearDepthStencilImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(image);
        encoder->EncodeEnumValue(imageLayout);
        encode_struct_ptr(encoder, pDepthStencil);
        encoder->EncodeUInt32Value(rangeCount);
        encode_struct_array(encoder, pRanges, rangeCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects)
{
    get_device_table(commandBuffer)->CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdClearAttachments);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(attachmentCount);
        encode_struct_array(encoder, pAttachments, attachmentCount);
        encoder->EncodeUInt32Value(rectCount);
        encode_struct_array(encoder, pRects, rectCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions)
{
    get_device_table(commandBuffer)->CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdResolveImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    get_device_table(commandBuffer)->CmdSetEvent(commandBuffer, event, stageMask);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(event);
        encoder->EncodeFlagsValue(stageMask);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    get_device_table(commandBuffer)->CmdResetEvent(commandBuffer, event, stageMask);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(event);
        encoder->EncodeFlagsValue(stageMask);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    get_device_table(commandBuffer)->CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdWaitEvents);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(eventCount);
        encoder->EncodeHandleArray(pEvents, eventCount);
        encoder->EncodeFlagsValue(srcStageMask);
        encoder->EncodeFlagsValue(dstStageMask);
        encoder->EncodeUInt32Value(memoryBarrierCount);
        encode_struct_array(encoder, pMemoryBarriers, memoryBarrierCount);
        encoder->EncodeUInt32Value(bufferMemoryBarrierCount);
        encode_struct_array(encoder, pBufferMemoryBarriers, bufferMemoryBarrierCount);
        encoder->EncodeUInt32Value(imageMemoryBarrierCount);
        encode_struct_array(encoder, pImageMemoryBarriers, imageMemoryBarrierCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    get_device_table(commandBuffer)->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdPipelineBarrier);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(srcStageMask);
        encoder->EncodeFlagsValue(dstStageMask);
        encoder->EncodeFlagsValue(dependencyFlags);
        encoder->EncodeUInt32Value(memoryBarrierCount);
        encode_struct_array(encoder, pMemoryBarriers, memoryBarrierCount);
        encoder->EncodeUInt32Value(bufferMemoryBarrierCount);
        encode_struct_array(encoder, pBufferMemoryBarriers, bufferMemoryBarrierCount);
        encoder->EncodeUInt32Value(imageMemoryBarrierCount);
        encode_struct_array(encoder, pImageMemoryBarriers, imageMemoryBarrierCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    get_device_table(commandBuffer)->CmdBeginQuery(commandBuffer, queryPool, query, flags);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdBeginQuery);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    get_device_table(commandBuffer)->CmdEndQuery(commandBuffer, queryPool, query);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdEndQuery);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    get_device_table(commandBuffer)->CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdResetQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    get_device_table(commandBuffer)->CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdWriteTimestamp);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    get_device_table(commandBuffer)->CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdCopyQueryPoolResults);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(stride);
        encoder->EncodeFlagsValue(flags);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues)
{
    get_device_table(commandBuffer)->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdPushConstants);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(layout);
        encoder->EncodeFlagsValue(stageFlags);
        encoder->EncodeUInt32Value(offset);
        encoder->EncodeUInt32Value(size);
        encoder->EncodeVoidArray(pValues, size);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents)
{
    get_device_table(commandBuffer)->CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdBeginRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pRenderPassBegin);
        encoder->EncodeEnumValue(contents);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{
    get_device_table(commandBuffer)->CmdNextSubpass(commandBuffer, contents);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdNextSubpass);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(contents);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(
    VkCommandBuffer                             commandBuffer)
{
    get_device_table(commandBuffer)->CmdEndRenderPass(commandBuffer);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdEndRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    get_device_table(commandBuffer)->CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdExecuteCommands);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleArray(pCommandBuffers, commandBufferCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    VkResult result = get_device_table(device)->BindBufferMemory2(device, bindInfoCount, pBindInfos);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkBindBufferMemory2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    VkResult result = get_device_table(device)->BindImageMemory2(device, bindInfoCount, pBindInfos);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkBindImageMemory2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    get_device_table(device)->GetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceGroupPeerMemoryFeatures);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    get_device_table(commandBuffer)->CmdSetDeviceMask(commandBuffer, deviceMask);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetDeviceMask);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    get_device_table(commandBuffer)->CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDispatchBase);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    VkResult result = get_instance_table(instance)->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkEnumeratePhysicalDeviceGroups);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount);
        encode_struct_array(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    get_device_table(device)->GetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetImageMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pInfo);
        encode_struct_ptr(encoder, pMemoryRequirements);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    get_device_table(device)->GetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetBufferMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pInfo);
        encode_struct_ptr(encoder, pMemoryRequirements);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    get_device_table(device)->GetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetImageSparseMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFeatures2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encode_struct_ptr(encoder, pFormatProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pImageFormatInfo);
        encode_struct_ptr(encoder, pImageFormatProperties);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceMemoryProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pMemoryProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pFormatInfo);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    get_device_table(device)->TrimCommandPool(device, commandPool, flags);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkTrimCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(
    VkDevice                                    device,
    const VkDeviceQueueInfo2*                   pQueueInfo,
    VkQueue*                                    pQueue)
{
    get_device_table(device)->GetDeviceQueue2(device, pQueueInfo, pQueue);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceQueue2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pQueueInfo);
        encoder->EncodeHandlePtr(pQueue);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    VkResult result = get_device_table(device)->CreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateSamplerYcbcrConversion);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pYcbcrConversion);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroySamplerYcbcrConversion);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(ycbcrConversion);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    VkResult result = get_device_table(device)->CreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateDescriptorUpdateTemplate);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDescriptorUpdateTemplate);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyDescriptorUpdateTemplate);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplate(
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const void*                                 pData)
{
    get_device_table(device)->UpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkUpdateDescriptorSetWithTemplate);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorSet);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);
        encoder->EncodeVoidPtr(pData);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalBufferProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalBufferInfo);
        encode_struct_ptr(encoder, pExternalBufferProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalFenceProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalFenceInfo);
        encode_struct_ptr(encoder, pExternalFenceProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalSemaphoreProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalSemaphoreInfo);
        encode_struct_ptr(encoder, pExternalSemaphoreProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    get_device_table(device)->GetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDescriptorSetLayoutSupport);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pSupport);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator)
{
    get_instance_table(instance)->DestroySurfaceKHR(instance, surface, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroySurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeHandleValue(surface);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeVkBool32Ptr(pSupported);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encode_struct_ptr(encoder, pSurfaceCapabilities);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormatKHR*                         pSurfaceFormats)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceFormatsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount);
        encode_struct_array(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeUInt32Ptr(pPresentModeCount);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain)
{
    VkResult result = get_device_table(device)->CreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateSwapchainKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSwapchain);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroySwapchainKHR(device, swapchain, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroySwapchainKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pSwapchainImageCount,
    VkImage*                                    pSwapchainImages)
{
    VkResult result = get_device_table(device)->GetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetSwapchainImagesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeUInt32Ptr(pSwapchainImageCount);
        encoder->EncodeHandleArray(pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    uint32_t*                                   pImageIndex)
{
    VkResult result = get_device_table(device)->AcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkAcquireNextImageKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeHandleValue(semaphore);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeUInt32Ptr(pImageIndex);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo)
{
    VkResult result = get_device_table(queue)->QueuePresentKHR(queue, pPresentInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkQueuePresentKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encode_struct_ptr(encoder, pPresentInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR(
    VkDevice                                    device,
    VkDeviceGroupPresentCapabilitiesKHR*        pDeviceGroupPresentCapabilities)
{
    VkResult result = get_device_table(device)->GetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceGroupPresentCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pDeviceGroupPresentCapabilities);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    VkDeviceGroupPresentModeFlagsKHR*           pModes)
{
    VkResult result = get_device_table(device)->GetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceGroupSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeFlagsPtr(pModes);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pRectCount,
    VkRect2D*                                   pRects)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDevicePresentRectanglesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeUInt32Ptr(pRectCount);
        encode_struct_array(encoder, pRects, (pRectCount != nullptr) ? (*pRectCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(
    VkDevice                                    device,
    const VkAcquireNextImageInfoKHR*            pAcquireInfo,
    uint32_t*                                   pImageIndex)
{
    VkResult result = get_device_table(device)->AcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkAcquireNextImage2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pAcquireInfo);
        encoder->EncodeUInt32Ptr(pImageIndex);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPropertiesKHR*                     pProperties)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceDisplayPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays)
{
    VkResult result = get_instance_table(physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDisplayPlaneSupportedDisplaysKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(planeIndex);
        encoder->EncodeUInt32Ptr(pDisplayCount);
        encoder->EncodeHandleArray(pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModePropertiesKHR*                 pProperties)
{
    VkResult result = get_instance_table(physicalDevice)->GetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDisplayModePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode)
{
    VkResult result = get_instance_table(physicalDevice)->CreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateDisplayModeKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pMode);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    VkDisplayPlaneCapabilitiesKHR*              pCapabilities)
{
    VkResult result = get_instance_table(physicalDevice)->GetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDisplayPlaneCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(mode);
        encoder->EncodeUInt32Value(planeIndex);
        encode_struct_ptr(encoder, pCapabilities);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result = get_instance_table(instance)->CreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateDisplayPlaneSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains)
{
    VkResult result = get_device_table(device)->CreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateSharedSwapchainsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        encode_struct_array(encoder, pCreateInfos, swapchainCount);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandleArray(pSwapchains, swapchainCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

#ifdef VK_USE_PLATFORM_XLIB_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateXlibSurfaceKHR(
    VkInstance                                  instance,
    const VkXlibSurfaceCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result = get_instance_table(instance)->CreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateXlibSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    Display*                                    dpy,
    VisualID                                    visualID)
{
    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceXlibPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeDisplayPtr(dpy);
        encoder->EncodeVisualIDValue(visualID);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateXcbSurfaceKHR(
    VkInstance                                  instance,
    const VkXcbSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result = get_instance_table(instance)->CreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateXcbSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    xcb_connection_t*                           connection,
    xcb_visualid_t                              visual_id)
{
    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceXcbPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeXcb_ConnectionPtr(connection);
        encoder->EncodeXcb_VisualidValue(visual_id);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateWaylandSurfaceKHR(
    VkInstance                                  instance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result = get_instance_table(instance)->CreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateWaylandSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct wl_display*                          display)
{
    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceWaylandPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeWl_DisplayPtr(display);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateMirSurfaceKHR(
    VkInstance                                  instance,
    const VkMirSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result = get_instance_table(instance)->CreateMirSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateMirSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceMirPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    MirConnection*                              connection)
{
    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceMirPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceMirPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeMirConnectionPtr(connection);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateAndroidSurfaceKHR(
    VkInstance                                  instance,
    const VkAndroidSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result = get_instance_table(instance)->CreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateAndroidSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateWin32SurfaceKHR(
    VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result = get_instance_table(instance)->CreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateWin32SurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceWin32PresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFeatures2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encode_struct_ptr(encoder, pFormatProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pImageFormatInfo);
        encode_struct_ptr(encoder, pImageFormatProperties);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceMemoryProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pMemoryProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pFormatInfo);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    get_device_table(device)->GetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceGroupPeerMemoryFeaturesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    get_device_table(commandBuffer)->CmdSetDeviceMaskKHR(commandBuffer, deviceMask);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetDeviceMaskKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    get_device_table(commandBuffer)->CmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDispatchBaseKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    get_device_table(device)->TrimCommandPoolKHR(device, commandPool, flags);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkTrimCommandPoolKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    VkResult result = get_instance_table(instance)->EnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkEnumeratePhysicalDeviceGroupsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount);
        encode_struct_array(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalBufferPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalBufferInfo);
        encode_struct_ptr(encoder, pExternalBufferProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleKHR(
    VkDevice                                    device,
    const VkMemoryGetWin32HandleInfoKHR*        pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    VkResult result = get_device_table(device)->GetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandlePropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    VkMemoryWin32HandlePropertiesKHR*           pMemoryWin32HandleProperties)
{
    VkResult result = get_device_table(device)->GetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryWin32HandlePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(handle);
        encode_struct_ptr(encoder, pMemoryWin32HandleProperties);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(
    VkDevice                                    device,
    const VkMemoryGetFdInfoKHR*                 pGetFdInfo,
    int*                                        pFd)
{
    VkResult result = get_device_table(device)->GetMemoryFdKHR(device, pGetFdInfo, pFd);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    VkMemoryFdPropertiesKHR*                    pMemoryFdProperties)
{
    VkResult result = get_device_table(device)->GetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryFdPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeInt32Value(fd);
        encode_struct_ptr(encoder, pMemoryFdProperties);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalSemaphoreInfo);
        encode_struct_ptr(encoder, pExternalSemaphoreProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkImportSemaphoreWin32HandleInfoKHR*  pImportSemaphoreWin32HandleInfo)
{
    VkResult result = get_device_table(device)->ImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkImportSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pImportSemaphoreWin32HandleInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkSemaphoreGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    VkResult result = get_device_table(device)->GetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(
    VkDevice                                    device,
    const VkImportSemaphoreFdInfoKHR*           pImportSemaphoreFdInfo)
{
    VkResult result = get_device_table(device)->ImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkImportSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pImportSemaphoreFdInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(
    VkDevice                                    device,
    const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
    int*                                        pFd)
{
    VkResult result = get_device_table(device)->GetSemaphoreFdKHR(device, pGetFdInfo, pFd);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites)
{
    get_device_table(commandBuffer)->CmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdPushDescriptorSetKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleValue(layout);
        encoder->EncodeUInt32Value(set);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        encode_struct_array(encoder, pDescriptorWrites, descriptorWriteCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetWithTemplateKHR(
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    const void*                                 pData)
{
    get_device_table(commandBuffer)->CmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdPushDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);
        encoder->EncodeHandleValue(layout);
        encoder->EncodeUInt32Value(set);
        encoder->EncodeVoidPtr(pData);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    VkResult result = get_device_table(device)->CreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateDescriptorUpdateTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDescriptorUpdateTemplate);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyDescriptorUpdateTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSetWithTemplateKHR(
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const void*                                 pData)
{
    get_device_table(device)->UpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkUpdateDescriptorSetWithTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorSet);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);
        encoder->EncodeVoidPtr(pData);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2KHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    VkResult result = get_device_table(device)->CreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pRenderPass);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo)
{
    get_device_table(commandBuffer)->CmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdBeginRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pRenderPassBegin);
        encode_struct_ptr(encoder, pSubpassBeginInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo,
    const VkSubpassEndInfoKHR*                  pSubpassEndInfo)
{
    get_device_table(commandBuffer)->CmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdNextSubpass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pSubpassBeginInfo);
        encode_struct_ptr(encoder, pSubpassEndInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfoKHR*                  pSubpassEndInfo)
{
    get_device_table(commandBuffer)->CmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdEndRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pSubpassEndInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    VkResult result = get_device_table(device)->GetSwapchainStatusKHR(device, swapchain);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetSwapchainStatusKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalFencePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalFenceInfo);
        encode_struct_ptr(encoder, pExternalFenceProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL ImportFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkImportFenceWin32HandleInfoKHR*      pImportFenceWin32HandleInfo)
{
    VkResult result = get_device_table(device)->ImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkImportFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pImportFenceWin32HandleInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkFenceGetWin32HandleInfoKHR*         pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    VkResult result = get_device_table(device)->GetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(
    VkDevice                                    device,
    const VkImportFenceFdInfoKHR*               pImportFenceFdInfo)
{
    VkResult result = get_device_table(device)->ImportFenceFdKHR(device, pImportFenceFdInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkImportFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pImportFenceFdInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(
    VkDevice                                    device,
    const VkFenceGetFdInfoKHR*                  pGetFdInfo,
    int*                                        pFd)
{
    VkResult result = get_device_table(device)->GetFenceFdKHR(device, pGetFdInfo, pFd);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pSurfaceInfo);
        encode_struct_ptr(encoder, pSurfaceCapabilities);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormat2KHR*                        pSurfaceFormats)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceFormats2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pSurfaceInfo);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount);
        encode_struct_array(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayProperties2KHR*                    pProperties)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceDisplayProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlaneProperties2KHR*               pProperties)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModeProperties2KHR*                pProperties)
{
    VkResult result = get_instance_table(physicalDevice)->GetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDisplayModeProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
    VkDisplayPlaneCapabilities2KHR*             pCapabilities)
{
    VkResult result = get_instance_table(physicalDevice)->GetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDisplayPlaneCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pDisplayPlaneInfo);
        encode_struct_ptr(encoder, pCapabilities);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    get_device_table(device)->GetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetImageMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pInfo);
        encode_struct_ptr(encoder, pMemoryRequirements);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    get_device_table(device)->GetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetBufferMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pInfo);
        encode_struct_ptr(encoder, pMemoryRequirements);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    get_device_table(device)->GetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetImageSparseMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversionKHR(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    VkResult result = get_device_table(device)->CreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateSamplerYcbcrConversionKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pYcbcrConversion);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroySamplerYcbcrConversionKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(ycbcrConversion);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    VkResult result = get_device_table(device)->BindBufferMemory2KHR(device, bindInfoCount, pBindInfos);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkBindBufferMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    VkResult result = get_device_table(device)->BindImageMemory2KHR(device, bindInfoCount, pBindInfos);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkBindImageMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    get_device_table(device)->GetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetDescriptorSetLayoutSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pSupport);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    get_device_table(commandBuffer)->CmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndirectCountKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    get_device_table(commandBuffer)->CmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndexedIndirectCountKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT(
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback)
{
    VkResult result = get_instance_table(instance)->CreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateDebugReportCallbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pCallback);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const VkAllocationCallbacks*                pAllocator)
{
    get_instance_table(instance)->DestroyDebugReportCallbackEXT(instance, callback, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyDebugReportCallbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeHandleValue(callback);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT(
    VkInstance                                  instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const char*                                 pLayerPrefix,
    const char*                                 pMessage)
{
    get_instance_table(instance)->DebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDebugReportMessageEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(object);
        encoder->EncodeSizeTValue(location);
        encoder->EncodeInt32Value(messageCode);
        encoder->EncodeString(pLayerPrefix);
        encoder->EncodeString(pMessage);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectTagInfoEXT*        pTagInfo)
{
    VkResult result = get_device_table(device)->DebugMarkerSetObjectTagEXT(device, pTagInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDebugMarkerSetObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pTagInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectNameEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectNameInfoEXT*       pNameInfo)
{
    VkResult result = get_device_table(device)->DebugMarkerSetObjectNameEXT(device, pNameInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDebugMarkerSetObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pNameInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    get_device_table(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDebugMarkerBeginEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pMarkerInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer)
{
    get_device_table(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDebugMarkerEndEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    get_device_table(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDebugMarkerInsertEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pMarkerInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    get_device_table(commandBuffer)->CmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndirectCountAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    get_device_table(commandBuffer)->CmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndexedIndirectCountAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL GetShaderInfoAMD(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    size_t*                                     pInfoSize,
    void*                                       pInfo)
{
    VkResult result = get_device_table(device)->GetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetShaderInfoAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeEnumValue(shaderStage);
        encoder->EncodeEnumValue(infoType);
        encoder->EncodeSizeTPtr(pInfoSize);
        encoder->EncodeVoidArray(pInfo, (pInfoSize != nullptr) ? (*pInfoSize) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    VkExternalImageFormatPropertiesNV*          pExternalImageFormatProperties)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeFlagsValue(externalHandleType);
        encode_struct_ptr(encoder, pExternalImageFormatProperties);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleNV(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    HANDLE*                                     pHandle)
{
    VkResult result = get_device_table(device)->GetMemoryWin32HandleNV(device, memory, handleType, pHandle);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryWin32HandleNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeFlagsValue(handleType);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_VI_NN
VKAPI_ATTR VkResult VKAPI_CALL CreateViSurfaceNN(
    VkInstance                                  instance,
    const VkViSurfaceCreateInfoNN*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result = get_instance_table(instance)->CreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateViSurfaceNN);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_VI_NN */

VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin)
{
    get_device_table(commandBuffer)->CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdBeginConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pConditionalRenderingBegin);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer)
{
    get_device_table(commandBuffer)->CmdEndConditionalRenderingEXT(commandBuffer);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdEndConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdProcessCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCmdProcessCommandsInfoNVX*          pProcessCommandsInfo)
{
    get_device_table(commandBuffer)->CmdProcessCommandsNVX(commandBuffer, pProcessCommandsInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdProcessCommandsNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pProcessCommandsInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdReserveSpaceForCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCmdReserveSpaceForCommandsInfoNVX*  pReserveSpaceInfo)
{
    get_device_table(commandBuffer)->CmdReserveSpaceForCommandsNVX(commandBuffer, pReserveSpaceInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdReserveSpaceForCommandsNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pReserveSpaceInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    const VkIndirectCommandsLayoutCreateInfoNVX* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkIndirectCommandsLayoutNVX*                pIndirectCommandsLayout)
{
    VkResult result = get_device_table(device)->CreateIndirectCommandsLayoutNVX(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateIndirectCommandsLayoutNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pIndirectCommandsLayout);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNVX                 indirectCommandsLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyIndirectCommandsLayoutNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(indirectCommandsLayout);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateObjectTableNVX(
    VkDevice                                    device,
    const VkObjectTableCreateInfoNVX*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkObjectTableNVX*                           pObjectTable)
{
    VkResult result = get_device_table(device)->CreateObjectTableNVX(device, pCreateInfo, pAllocator, pObjectTable);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateObjectTableNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pObjectTable);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyObjectTableNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyObjectTableNVX(device, objectTable, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyObjectTableNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(objectTable);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterObjectsNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    uint32_t                                    objectCount,
    const VkObjectTableEntryNVX* const*         ppObjectTableEntries,
    const uint32_t*                             pObjectIndices)
{
    VkResult result = get_device_table(device)->RegisterObjectsNVX(device, objectTable, objectCount, ppObjectTableEntries, pObjectIndices);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkRegisterObjectsNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(objectTable);
        encoder->EncodeUInt32Value(objectCount);
        encode_struct_array(encoder, ppObjectTableEntries, objectCount);
        encoder->EncodeUInt32Array(pObjectIndices, objectCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL UnregisterObjectsNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    uint32_t                                    objectCount,
    const VkObjectEntryTypeNVX*                 pObjectEntryTypes,
    const uint32_t*                             pObjectIndices)
{
    VkResult result = get_device_table(device)->UnregisterObjectsNVX(device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkUnregisterObjectsNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(objectTable);
        encoder->EncodeUInt32Value(objectCount);
        encoder->EncodeEnumArray(pObjectEntryTypes, objectCount);
        encoder->EncodeUInt32Array(pObjectIndices, objectCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceGeneratedCommandsPropertiesNVX(
    VkPhysicalDevice                            physicalDevice,
    VkDeviceGeneratedCommandsFeaturesNVX*       pFeatures,
    VkDeviceGeneratedCommandsLimitsNVX*         pLimits)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, pFeatures, pLimits);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures);
        encode_struct_ptr(encoder, pLimits);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings)
{
    get_device_table(commandBuffer)->CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetViewportWScalingNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        encode_struct_array(encoder, pViewportWScalings, viewportCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{
    VkResult result = get_instance_table(physicalDevice)->ReleaseDisplayEXT(physicalDevice, display);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkReleaseDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
VKAPI_ATTR VkResult VKAPI_CALL AcquireXlibDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    VkDisplayKHR                                display)
{
    VkResult result = get_instance_table(physicalDevice)->AcquireXlibDisplayEXT(physicalDevice, dpy, display);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkAcquireXlibDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeDisplayPtr(dpy);
        encoder->EncodeHandleValue(display);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRandROutputDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    RROutput                                    rrOutput,
    VkDisplayKHR*                               pDisplay)
{
    VkResult result = get_instance_table(physicalDevice)->GetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetRandROutputDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeDisplayPtr(dpy);
        encoder->EncodeRROutputValue(rrOutput);
        encoder->EncodeHandlePtr(pDisplay);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilities2EXT*                  pSurfaceCapabilities)
{
    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilities2EXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encode_struct_ptr(encoder, pSurfaceCapabilities);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayPowerInfoEXT*                pDisplayPowerInfo)
{
    VkResult result = get_device_table(device)->DisplayPowerControlEXT(device, display, pDisplayPowerInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDisplayPowerControlEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(display);
        encode_struct_ptr(encoder, pDisplayPowerInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(
    VkDevice                                    device,
    const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    VkResult result = get_device_table(device)->RegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkRegisterDeviceEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pDeviceEventInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFence);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayEventInfoEXT*                pDisplayEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    VkResult result = get_device_table(device)->RegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkRegisterDisplayEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(display);
        encode_struct_ptr(encoder, pDisplayEventInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFence);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    uint64_t*                                   pCounterValue)
{
    VkResult result = get_device_table(device)->GetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetSwapchainCounterEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeEnumValue(counter);
        encoder->EncodeUInt64Ptr(pCounterValue);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRefreshCycleDurationGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkRefreshCycleDurationGOOGLE*               pDisplayTimingProperties)
{
    VkResult result = get_device_table(device)->GetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetRefreshCycleDurationGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encode_struct_ptr(encoder, pDisplayTimingProperties);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPastPresentationTimingGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pPresentationTimingCount,
    VkPastPresentationTimingGOOGLE*             pPresentationTimings)
{
    VkResult result = get_device_table(device)->GetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPastPresentationTimingGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeUInt32Ptr(pPresentationTimingCount);
        encode_struct_array(encoder, pPresentationTimings, (pPresentationTimingCount != nullptr) ? (*pPresentationTimingCount) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles)
{
    get_device_table(commandBuffer)->CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetDiscardRectangleEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstDiscardRectangle);
        encoder->EncodeUInt32Value(discardRectangleCount);
        encode_struct_array(encoder, pDiscardRectangles, discardRectangleCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainKHR*                       pSwapchains,
    const VkHdrMetadataEXT*                     pMetadata)
{
    get_device_table(device)->SetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkSetHdrMetadataEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        encoder->EncodeHandleArray(pSwapchains, swapchainCount);
        encode_struct_array(encoder, pMetadata, swapchainCount);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

#ifdef VK_USE_PLATFORM_IOS_MVK
VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK(
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result = get_instance_table(instance)->CreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateIOSSurfaceMVK);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
VKAPI_ATTR VkResult VKAPI_CALL CreateMacOSSurfaceMVK(
    VkInstance                                  instance,
    const VkMacOSSurfaceCreateInfoMVK*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result = get_instance_table(instance)->CreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateMacOSSurfaceMVK);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_MACOS_MVK */

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectNameInfoEXT*        pNameInfo)
{
    VkResult result = get_device_table(device)->SetDebugUtilsObjectNameEXT(device, pNameInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkSetDebugUtilsObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pNameInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectTagInfoEXT*         pTagInfo)
{
    VkResult result = get_device_table(device)->SetDebugUtilsObjectTagEXT(device, pTagInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkSetDebugUtilsObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pTagInfo);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    get_device_table(queue)->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkQueueBeginDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encode_struct_ptr(encoder, pLabelInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue)
{
    get_device_table(queue)->QueueEndDebugUtilsLabelEXT(queue);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkQueueEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    get_device_table(queue)->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkQueueInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encode_struct_ptr(encoder, pLabelInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    get_device_table(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdBeginDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pLabelInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer)
{
    get_device_table(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    get_device_table(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pLabelInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger)
{
    VkResult result = get_instance_table(instance)->CreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pMessenger);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const VkAllocationCallbacks*                pAllocator)
{
    get_instance_table(instance)->DestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeHandleValue(messenger);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
{
    get_instance_table(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkSubmitDebugUtilsMessageEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeEnumValue(messageSeverity);
        encoder->EncodeFlagsValue(messageTypes);
        encode_struct_ptr(encoder, pCallbackData);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                    device,
    const struct AHardwareBuffer*               buffer,
    VkAndroidHardwareBufferPropertiesANDROID*   pProperties)
{
    VkResult result = get_device_table(device)->GetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetAndroidHardwareBufferPropertiesANDROID);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeAHardwareBufferPtr(buffer);
        encode_struct_ptr(encoder, pProperties);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID(
    VkDevice                                    device,
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
    struct AHardwareBuffer**                    pBuffer)
{
    VkResult result = get_device_table(device)->GetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryAndroidHardwareBufferANDROID);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pInfo);
        encoder->EncodeAHardwareBufferPtrPtr(pBuffer);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo)
{
    get_device_table(commandBuffer)->CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdSetSampleLocationsEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encode_struct_ptr(encoder, pSampleLocationsInfo);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    VkMultisamplePropertiesEXT*                 pMultisampleProperties)
{
    get_instance_table(physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceMultisamplePropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(samples);
        encode_struct_ptr(encoder, pMultisampleProperties);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT(
    VkDevice                                    device,
    const VkValidationCacheCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkValidationCacheEXT*                       pValidationCache)
{
    VkResult result = get_device_table(device)->CreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCreateValidationCacheEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pValidationCache);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const VkAllocationCallbacks*                pAllocator)
{
    get_device_table(device)->DestroyValidationCacheEXT(device, validationCache, pAllocator);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkDestroyValidationCacheEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(validationCache);
        encode_struct_ptr(encoder, pAllocator);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const VkValidationCacheEXT*                 pSrcCaches)
{
    VkResult result = get_device_table(device)->MergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkMergeValidationCachesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleArray(pSrcCaches, srcCacheCount);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    VkResult result = get_device_table(device)->GetValidationCacheDataEXT(device, validationCache, pDataSize, pData);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetValidationCacheDataEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(validationCache);
        encoder->EncodeSizeTPtr(pDataSize);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    const void*                                 pHostPointer,
    VkMemoryHostPointerPropertiesEXT*           pMemoryHostPointerProperties)
{
    VkResult result = get_device_table(device)->GetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryHostPointerPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(pHostPointer);
        encode_struct_ptr(encoder, pMemoryHostPointerProperties);
        encoder->EncodeEnumValue(result);
        get_trace_manager()->EndApiCallTrace(encoder);
    }

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    get_device_table(commandBuffer)->CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_vkCmdWriteBufferMarkerAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeUInt32Value(marker);
        get_trace_manager()->EndApiCallTrace(encoder);
    }
}

BRIMSTONE_END_NAMESPACE(brimstone)
