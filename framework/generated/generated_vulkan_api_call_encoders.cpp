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

#include "generated/generated_vulkan_api_call_encoders.h"

#include "encode/custom_encoder_commands.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/trace_manager.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "format/api_call_id.h"
#include "generated/generated_vulkan_command_buffer_util.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(TraceManager::Get(), pCreateInfo, pAllocator, pInstance);

    VkResult result = TraceManager::OverrideCreateInstance(pCreateInfo, pAllocator, pInstance);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateInstance);
    if (encoder)
    {
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pInstance, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<const void*, InstanceWrapper, VkInstanceCreateInfo>(result, nullptr, pInstance, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(TraceManager::Get(), result, pCreateInfo, pAllocator, pInstance);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyInstance(
    VkInstance                                  instance,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(TraceManager::Get(), instance, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyInstance);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<InstanceWrapper>(instance, encoder);
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    GetInstanceTable(instance)->DestroyInstance(instance_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(TraceManager::Get(), instance, pAllocator);

    DestroyWrappedHandle<InstanceWrapper>(instance);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(TraceManager::Get(), instance, pPhysicalDeviceCount, pPhysicalDevices);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->EnumeratePhysicalDevices(instance_unwrapped, pPhysicalDeviceCount, pPhysicalDevices);

    if (result >= 0)
    {
        CreateWrappedHandles<InstanceWrapper, NoParentWrapper, PhysicalDeviceWrapper>(instance, NoParentWrapper::kHandleValue, pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceCount, omit_output_data);
        encoder->EncodeHandleArray(pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndGroupCreateApiCallTrace<VkInstance, void*, PhysicalDeviceWrapper, void>(result, instance, nullptr, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0, pPhysicalDevices, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(TraceManager::Get(), result, instance, pPhysicalDeviceCount, pPhysicalDevices);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(TraceManager::Get(), physicalDevice, pFeatures);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures(physicalDevice_unwrapped, pFeatures);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(TraceManager::Get(), physicalDevice, format, pFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties(physicalDevice_unwrapped, format, pFormatProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        EncodeStructPtr(encoder, pFormatProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(TraceManager::Get(), physicalDevice, format, pFormatProperties);
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
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(TraceManager::Get(), physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties(physicalDevice_unwrapped, format, type, tiling, usage, flags, pImageFormatProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        EncodeStructPtr(encoder, pImageFormatProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(TraceManager::Get(), result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(TraceManager::Get(), physicalDevice, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties(physicalDevice_unwrapped, pProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(physicalDevice_unwrapped, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        EncodeStructArray(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(TraceManager::Get(), physicalDevice, pMemoryProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties(physicalDevice_unwrapped, pMemoryProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pMemoryProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(TraceManager::Get(), physicalDevice, pCreateInfo, pAllocator, pDevice);

    VkResult result = TraceManager::Get()->OverrideCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDevice);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDevice, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkPhysicalDevice, DeviceWrapper, VkDeviceCreateInfo>(result, physicalDevice, pDevice, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(TraceManager::Get(), result, physicalDevice, pCreateInfo, pAllocator, pDevice);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDevice(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(TraceManager::Get(), device, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDevice);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DeviceWrapper>(device, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->DestroyDevice(device_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(TraceManager::Get(), device, pAllocator);

    DestroyWrappedHandle<DeviceWrapper>(device);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(TraceManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->GetDeviceQueue(device_unwrapped, queueFamilyIndex, queueIndex, pQueue);

    CreateWrappedHandle<DeviceWrapper, NoParentWrapper, QueueWrapper>(device, NoParentWrapper::kHandleValue, pQueue, TraceManager::GetUniqueId);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceQueue);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeUInt32Value(queueIndex);
        encoder->EncodeHandlePtr(pQueue);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, QueueWrapper, void>(VK_SUCCESS, device, pQueue, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(TraceManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(TraceManager::Get(), queue, submitCount, pSubmits, fence);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);
    const VkSubmitInfo* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    VkResult result = GetDeviceTable(queue)->QueueSubmit(queue_unwrapped, submitCount, pSubmits_unwrapped, fence_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueSubmit);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Value(submitCount);
        EncodeStructArray(encoder, pSubmits, submitCount);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(TraceManager::Get(), result, queue, submitCount, pSubmits, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(
    VkQueue                                     queue)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(TraceManager::Get(), queue);

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    VkResult result = GetDeviceTable(queue)->QueueWaitIdle(queue_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(TraceManager::Get(), result, queue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(
    VkDevice                                    device)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(TraceManager::Get(), device);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->DeviceWaitIdle(device_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDeviceWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(TraceManager::Get(), result, device);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(TraceManager::Get(), device, pAllocateInfo, pAllocator, pMemory);

    VkResult result = TraceManager::Get()->OverrideAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkAllocateMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pMemory, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, DeviceMemoryWrapper, VkMemoryAllocateInfo>(result, device, pMemory, pAllocateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(TraceManager::Get(), result, device, pAllocateInfo, pAllocator, pMemory);

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(TraceManager::Get(), device, memory, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkFreeMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DeviceMemoryWrapper>(memory, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    GetDeviceTable(device)->FreeMemory(device_unwrapped, memory_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(TraceManager::Get(), device, memory, pAllocator);

    DestroyWrappedHandle<DeviceMemoryWrapper>(memory);
}

VKAPI_ATTR VkResult VKAPI_CALL MapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    void**                                      ppData)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(TraceManager::Get(), device, memory, offset, size, flags, ppData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    VkResult result = GetDeviceTable(device)->MapMemory(device_unwrapped, memory_unwrapped, offset, size, flags, ppData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMapMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeVoidPtrPtr(ppData, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(TraceManager::Get(), result, device, memory, offset, size, flags, ppData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(TraceManager::Get(), device, memory);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUnmapMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    GetDeviceTable(device)->UnmapMemory(device_unwrapped, memory_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(TraceManager::Get(), device, memory);
}

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(TraceManager::Get(), device, memoryRangeCount, pMemoryRanges);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMappedMemoryRange* pMemoryRanges_unwrapped = UnwrapStructArrayHandles(pMemoryRanges, memoryRangeCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->FlushMappedMemoryRanges(device_unwrapped, memoryRangeCount, pMemoryRanges_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        EncodeStructArray(encoder, pMemoryRanges, memoryRangeCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(TraceManager::Get(), result, device, memoryRangeCount, pMemoryRanges);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(TraceManager::Get(), device, memoryRangeCount, pMemoryRanges);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMappedMemoryRange* pMemoryRanges_unwrapped = UnwrapStructArrayHandles(pMemoryRanges, memoryRangeCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->InvalidateMappedMemoryRanges(device_unwrapped, memoryRangeCount, pMemoryRanges_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        EncodeStructArray(encoder, pMemoryRanges, memoryRangeCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(TraceManager::Get(), result, device, memoryRangeCount, pMemoryRanges);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize*                               pCommittedMemoryInBytes)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(TraceManager::Get(), device, memory, pCommittedMemoryInBytes);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    GetDeviceTable(device)->GetDeviceMemoryCommitment(device_unwrapped, memory_unwrapped, pCommittedMemoryInBytes);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizePtr(pCommittedMemoryInBytes);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(TraceManager::Get(), device, memory, pCommittedMemoryInBytes);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(TraceManager::Get(), device, buffer, memory, memoryOffset);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    VkResult result = GetDeviceTable(device)->BindBufferMemory(device_unwrapped, buffer_unwrapped, memory_unwrapped, memoryOffset);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(TraceManager::Get(), result, device, buffer, memory, memoryOffset);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(TraceManager::Get(), device, image, memory, memoryOffset);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    VkResult result = GetDeviceTable(device)->BindImageMemory(device_unwrapped, image_unwrapped, memory_unwrapped, memoryOffset);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(TraceManager::Get(), result, device, image, memory, memoryOffset);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(TraceManager::Get(), device, buffer, pMemoryRequirements);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(device)->GetBufferMemoryRequirements(device_unwrapped, buffer_unwrapped, pMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(buffer);
        EncodeStructPtr(encoder, pMemoryRequirements);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(TraceManager::Get(), device, buffer, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(TraceManager::Get(), device, image, pMemoryRequirements);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(device)->GetImageMemoryRequirements(device_unwrapped, image_unwrapped, pMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        EncodeStructPtr(encoder, pMemoryRequirements);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(TraceManager::Get(), device, image, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements*            pSparseMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(TraceManager::Get(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(device)->GetImageSparseMemoryRequirements(device_unwrapped, image_unwrapped, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(TraceManager::Get(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(TraceManager::Get(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(physicalDevice_unwrapped, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(samples);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(TraceManager::Get(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse(
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const VkBindSparseInfo*                     pBindInfo,
    VkFence                                     fence)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(TraceManager::Get(), queue, bindInfoCount, pBindInfo, fence);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);
    const VkBindSparseInfo* pBindInfo_unwrapped = UnwrapStructArrayHandles(pBindInfo, bindInfoCount, handle_unwrap_memory);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    VkResult result = GetDeviceTable(queue)->QueueBindSparse(queue_unwrapped, bindInfoCount, pBindInfo_unwrapped, fence_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueBindSparse);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfo, bindInfoCount);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(TraceManager::Get(), result, queue, bindInfoCount, pBindInfo, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pFence);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateFence(device_unwrapped, pCreateInfo, pAllocator, pFence);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, FenceWrapper>(device, NoParentWrapper::kHandleValue, pFence, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateFence);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFence, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, FenceWrapper, VkFenceCreateInfo>(result, device, pFence, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(TraceManager::Get(), device, fence, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyFence);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(fence);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<FenceWrapper>(fence, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    GetDeviceTable(device)->DestroyFence(device_unwrapped, fence_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(TraceManager::Get(), device, fence, pAllocator);

    DestroyWrappedHandle<FenceWrapper>(fence);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(TraceManager::Get(), device, fenceCount, pFences);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkFence* pFences_unwrapped = UnwrapHandles<VkFence>(pFences, fenceCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ResetFences(device_unwrapped, fenceCount, pFences_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetFences);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleArray(pFences, fenceCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(TraceManager::Get(), result, device, fenceCount, pFences);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(
    VkDevice                                    device,
    VkFence                                     fence)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(TraceManager::Get(), device, fence);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    VkResult result = GetDeviceTable(device)->GetFenceStatus(device_unwrapped, fence_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceStatus);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(TraceManager::Get(), result, device, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(TraceManager::Get(), device, fenceCount, pFences, waitAll, timeout);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkFence* pFences_unwrapped = UnwrapHandles<VkFence>(pFences, fenceCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->WaitForFences(device_unwrapped, fenceCount, pFences_unwrapped, waitAll, timeout);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkWaitForFences);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleArray(pFences, fenceCount);
        encoder->EncodeVkBool32Value(waitAll);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(TraceManager::Get(), result, device, fenceCount, pFences, waitAll, timeout);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pSemaphore);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateSemaphore(device_unwrapped, pCreateInfo, pAllocator, pSemaphore);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SemaphoreWrapper>(device, NoParentWrapper::kHandleValue, pSemaphore, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSemaphore);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSemaphore, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, SemaphoreWrapper, VkSemaphoreCreateInfo>(result, device, pSemaphore, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSemaphore);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(TraceManager::Get(), device, semaphore, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroySemaphore);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(semaphore);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SemaphoreWrapper>(semaphore, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSemaphore semaphore_unwrapped = GetWrappedHandle<VkSemaphore>(semaphore);

    GetDeviceTable(device)->DestroySemaphore(device_unwrapped, semaphore_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(TraceManager::Get(), device, semaphore, pAllocator);

    DestroyWrappedHandle<SemaphoreWrapper>(semaphore);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pEvent);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateEvent(device_unwrapped, pCreateInfo, pAllocator, pEvent);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, EventWrapper>(device, NoParentWrapper::kHandleValue, pEvent, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pEvent, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, EventWrapper, VkEventCreateInfo>(result, device, pEvent, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pEvent);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(TraceManager::Get(), device, event, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<EventWrapper>(event, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    GetDeviceTable(device)->DestroyEvent(device_unwrapped, event_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(TraceManager::Get(), device, event, pAllocator);

    DestroyWrappedHandle<EventWrapper>(event);
}

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(
    VkDevice                                    device,
    VkEvent                                     event)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(TraceManager::Get(), device, event);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    VkResult result = GetDeviceTable(device)->GetEventStatus(device_unwrapped, event_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetEventStatus);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(TraceManager::Get(), device, event);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    VkResult result = GetDeviceTable(device)->SetEvent(device_unwrapped, event_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(TraceManager::Get(), device, event);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    VkResult result = GetDeviceTable(device)->ResetEvent(device_unwrapped, event_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pQueryPool);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateQueryPool(device_unwrapped, pCreateInfo, pAllocator, pQueryPool);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, QueryPoolWrapper>(device, NoParentWrapper::kHandleValue, pQueryPool, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pQueryPool, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, QueryPoolWrapper, VkQueryPoolCreateInfo>(result, device, pQueryPool, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pQueryPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(TraceManager::Get(), device, queryPool, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(queryPool);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<QueryPoolWrapper>(queryPool, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(device)->DestroyQueryPool(device_unwrapped, queryPool_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(TraceManager::Get(), device, queryPool, pAllocator);

    DestroyWrappedHandle<QueryPoolWrapper>(queryPool);
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
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(TraceManager::Get(), device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    VkResult result = GetDeviceTable(device)->GetQueryPoolResults(device_unwrapped, queryPool_unwrapped, firstQuery, queryCount, dataSize, pData, stride, flags);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetQueryPoolResults);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeVkDeviceSizeValue(stride);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(TraceManager::Get(), result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pBuffer);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateBuffer(device_unwrapped, pCreateInfo, pAllocator, pBuffer);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, BufferWrapper>(device, NoParentWrapper::kHandleValue, pBuffer, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pBuffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, BufferWrapper, VkBufferCreateInfo>(result, device, pBuffer, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pBuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(TraceManager::Get(), device, buffer, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(buffer);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<BufferWrapper>(buffer, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(device)->DestroyBuffer(device_unwrapped, buffer_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(TraceManager::Get(), device, buffer, pAllocator);

    DestroyWrappedHandle<BufferWrapper>(buffer);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pView);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferViewCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateBufferView(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pView);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, BufferViewWrapper>(device, NoParentWrapper::kHandleValue, pView, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateBufferView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pView, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, BufferViewWrapper, VkBufferViewCreateInfo>(result, device, pView, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pView);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(TraceManager::Get(), device, bufferView, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyBufferView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(bufferView);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<BufferViewWrapper>(bufferView, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkBufferView bufferView_unwrapped = GetWrappedHandle<VkBufferView>(bufferView);

    GetDeviceTable(device)->DestroyBufferView(device_unwrapped, bufferView_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(TraceManager::Get(), device, bufferView, pAllocator);

    DestroyWrappedHandle<BufferViewWrapper>(bufferView);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pImage);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateImage(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pImage);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ImageWrapper>(device, NoParentWrapper::kHandleValue, pImage, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pImage, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, ImageWrapper, VkImageCreateInfo>(result, device, pImage, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pImage);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(TraceManager::Get(), device, image, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<ImageWrapper>(image, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(device)->DestroyImage(device_unwrapped, image_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(TraceManager::Get(), device, image, pAllocator);

    DestroyWrappedHandle<ImageWrapper>(image);
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(TraceManager::Get(), device, image, pSubresource, pLayout);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(device)->GetImageSubresourceLayout(device_unwrapped, image_unwrapped, pSubresource, pLayout);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        EncodeStructPtr(encoder, pSubresource);
        EncodeStructPtr(encoder, pLayout);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(TraceManager::Get(), device, image, pSubresource, pLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pView);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageViewCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateImageView(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pView);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ImageViewWrapper>(device, NoParentWrapper::kHandleValue, pView, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateImageView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pView, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, ImageViewWrapper, VkImageViewCreateInfo>(result, device, pView, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pView);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(TraceManager::Get(), device, imageView, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyImageView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(imageView);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<ImageViewWrapper>(imageView, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImageView imageView_unwrapped = GetWrappedHandle<VkImageView>(imageView);

    GetDeviceTable(device)->DestroyImageView(device_unwrapped, imageView_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(TraceManager::Get(), device, imageView, pAllocator);

    DestroyWrappedHandle<ImageViewWrapper>(imageView);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pShaderModule);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkShaderModuleCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateShaderModule(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pShaderModule);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ShaderModuleWrapper>(device, NoParentWrapper::kHandleValue, pShaderModule, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateShaderModule);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pShaderModule, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, ShaderModuleWrapper, VkShaderModuleCreateInfo>(result, device, pShaderModule, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pShaderModule);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(TraceManager::Get(), device, shaderModule, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyShaderModule);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(shaderModule);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<ShaderModuleWrapper>(shaderModule, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkShaderModule shaderModule_unwrapped = GetWrappedHandle<VkShaderModule>(shaderModule);

    GetDeviceTable(device)->DestroyShaderModule(device_unwrapped, shaderModule_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(TraceManager::Get(), device, shaderModule, pAllocator);

    DestroyWrappedHandle<ShaderModuleWrapper>(shaderModule);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pPipelineCache);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreatePipelineCache(device_unwrapped, pCreateInfo, pAllocator, pPipelineCache);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PipelineCacheWrapper>(device, NoParentWrapper::kHandleValue, pPipelineCache, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreatePipelineCache);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pPipelineCache, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, PipelineCacheWrapper, VkPipelineCacheCreateInfo>(result, device, pPipelineCache, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pPipelineCache);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(TraceManager::Get(), device, pipelineCache, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipelineCache);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<PipelineCacheWrapper>(pipelineCache, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);

    GetDeviceTable(device)->DestroyPipelineCache(device_unwrapped, pipelineCache_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(TraceManager::Get(), device, pipelineCache, pAllocator);

    DestroyWrappedHandle<PipelineCacheWrapper>(pipelineCache);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(TraceManager::Get(), device, pipelineCache, pDataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);

    VkResult result = GetDeviceTable(device)->GetPipelineCacheData(device_unwrapped, pipelineCache_unwrapped, pDataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPipelineCacheData);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeSizeTPtr(pDataSize, omit_output_data);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(TraceManager::Get(), result, device, pipelineCache, pDataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL MergePipelineCaches(
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const VkPipelineCache*                      pSrcCaches)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(TraceManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache dstCache_unwrapped = GetWrappedHandle<VkPipelineCache>(dstCache);
    const VkPipelineCache* pSrcCaches_unwrapped = UnwrapHandles<VkPipelineCache>(pSrcCaches, srcCacheCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->MergePipelineCaches(device_unwrapped, dstCache_unwrapped, srcCacheCount, pSrcCaches_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMergePipelineCaches);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleArray(pSrcCaches, srcCacheCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(TraceManager::Get(), result, device, dstCache, srcCacheCount, pSrcCaches);

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
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);
    const VkGraphicsPipelineCreateInfo* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateGraphicsPipelines(device_unwrapped, pipelineCache_unwrapped, createInfoCount, pCreateInfos_unwrapped, pAllocator, pPipelines);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, PipelineCacheWrapper, PipelineWrapper>(device, pipelineCache, pPipelines, createInfoCount, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateGraphicsPipelines);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleArray(pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndGroupCreateApiCallTrace<VkDevice, VkPipelineCache, PipelineWrapper, VkGraphicsPipelineCreateInfo>(result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

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
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);
    const VkComputePipelineCreateInfo* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateComputePipelines(device_unwrapped, pipelineCache_unwrapped, createInfoCount, pCreateInfos_unwrapped, pAllocator, pPipelines);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, PipelineCacheWrapper, PipelineWrapper>(device, pipelineCache, pPipelines, createInfoCount, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateComputePipelines);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleArray(pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndGroupCreateApiCallTrace<VkDevice, VkPipelineCache, PipelineWrapper, VkComputePipelineCreateInfo>(result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(TraceManager::Get(), device, pipeline, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipeline);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<PipelineWrapper>(pipeline, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    GetDeviceTable(device)->DestroyPipeline(device_unwrapped, pipeline_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(TraceManager::Get(), device, pipeline, pAllocator);

    DestroyWrappedHandle<PipelineWrapper>(pipeline);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pPipelineLayout);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkPipelineLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreatePipelineLayout(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pPipelineLayout);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PipelineLayoutWrapper>(device, NoParentWrapper::kHandleValue, pPipelineLayout, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreatePipelineLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pPipelineLayout, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, PipelineLayoutWrapper, VkPipelineLayoutCreateInfo>(result, device, pPipelineLayout, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pPipelineLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(TraceManager::Get(), device, pipelineLayout, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipelineLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineLayout);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<PipelineLayoutWrapper>(pipelineLayout, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineLayout pipelineLayout_unwrapped = GetWrappedHandle<VkPipelineLayout>(pipelineLayout);

    GetDeviceTable(device)->DestroyPipelineLayout(device_unwrapped, pipelineLayout_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(TraceManager::Get(), device, pipelineLayout, pAllocator);

    DestroyWrappedHandle<PipelineLayoutWrapper>(pipelineLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pSampler);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSamplerCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateSampler(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pSampler);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SamplerWrapper>(device, NoParentWrapper::kHandleValue, pSampler, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSampler);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSampler, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, SamplerWrapper, VkSamplerCreateInfo>(result, device, pSampler, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSampler);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(TraceManager::Get(), device, sampler, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroySampler);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(sampler);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SamplerWrapper>(sampler, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSampler sampler_unwrapped = GetWrappedHandle<VkSampler>(sampler);

    GetDeviceTable(device)->DestroySampler(device_unwrapped, sampler_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(TraceManager::Get(), device, sampler, pAllocator);

    DestroyWrappedHandle<SamplerWrapper>(sampler);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorSetLayout*                      pSetLayout)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pSetLayout);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateDescriptorSetLayout(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pSetLayout);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorSetLayoutWrapper>(device, NoParentWrapper::kHandleValue, pSetLayout, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSetLayout, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, DescriptorSetLayoutWrapper, VkDescriptorSetLayoutCreateInfo>(result, device, pSetLayout, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSetLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(TraceManager::Get(), device, descriptorSetLayout, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorSetLayout);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DescriptorSetLayoutWrapper>(descriptorSetLayout, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorSetLayout descriptorSetLayout_unwrapped = GetWrappedHandle<VkDescriptorSetLayout>(descriptorSetLayout);

    GetDeviceTable(device)->DestroyDescriptorSetLayout(device_unwrapped, descriptorSetLayout_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(TraceManager::Get(), device, descriptorSetLayout, pAllocator);

    DestroyWrappedHandle<DescriptorSetLayoutWrapper>(descriptorSetLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorPool);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateDescriptorPool(device_unwrapped, pCreateInfo, pAllocator, pDescriptorPool);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorPoolWrapper>(device, NoParentWrapper::kHandleValue, pDescriptorPool, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDescriptorPool, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, DescriptorPoolWrapper, VkDescriptorPoolCreateInfo>(result, device, pDescriptorPool, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(TraceManager::Get(), device, descriptorPool, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorPool);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DescriptorPoolWrapper>(descriptorPool, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorPool descriptorPool_unwrapped = GetWrappedHandle<VkDescriptorPool>(descriptorPool);

    GetDeviceTable(device)->DestroyDescriptorPool(device_unwrapped, descriptorPool_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(TraceManager::Get(), device, descriptorPool, pAllocator);

    DestroyWrappedHandle<DescriptorPoolWrapper>(descriptorPool);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(TraceManager::Get(), device, descriptorPool, flags);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorPool descriptorPool_unwrapped = GetWrappedHandle<VkDescriptorPool>(descriptorPool);

    VkResult result = GetDeviceTable(device)->ResetDescriptorPool(device_unwrapped, descriptorPool_unwrapped, flags);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorPool);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(TraceManager::Get(), result, device, descriptorPool, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(
    VkDevice                                    device,
    const VkDescriptorSetAllocateInfo*          pAllocateInfo,
    VkDescriptorSet*                            pDescriptorSets)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(TraceManager::Get(), device, pAllocateInfo, pDescriptorSets);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorSetAllocateInfo* pAllocateInfo_unwrapped = UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->AllocateDescriptorSets(device_unwrapped, pAllocateInfo_unwrapped, pDescriptorSets);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, DescriptorPoolWrapper, DescriptorSetWrapper>(device, pAllocateInfo->descriptorPool, pDescriptorSets, pAllocateInfo->descriptorSetCount, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkAllocateDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        encoder->EncodeHandleArray(pDescriptorSets, (pAllocateInfo != nullptr) ? (pAllocateInfo->descriptorSetCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndPoolCreateApiCallTrace<VkDevice, DescriptorSetWrapper, VkDescriptorSetAllocateInfo>(result, device, (pAllocateInfo != nullptr) ? (pAllocateInfo->descriptorSetCount) : 0, pDescriptorSets, pAllocateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(TraceManager::Get(), result, device, pAllocateInfo, pDescriptorSets);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(TraceManager::Get(), device, descriptorPool, descriptorSetCount, pDescriptorSets);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorPool descriptorPool_unwrapped = GetWrappedHandle<VkDescriptorPool>(descriptorPool);
    const VkDescriptorSet* pDescriptorSets_unwrapped = UnwrapHandles<VkDescriptorSet>(pDescriptorSets, descriptorSetCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->FreeDescriptorSets(device_unwrapped, descriptorPool_unwrapped, descriptorSetCount, pDescriptorSets_unwrapped);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkFreeDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorPool);
        encoder->EncodeUInt32Value(descriptorSetCount);
        encoder->EncodeHandleArray(pDescriptorSets, descriptorSetCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndDestroyApiCallTrace<DescriptorSetWrapper>(descriptorSetCount, pDescriptorSets, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(TraceManager::Get(), result, device, descriptorPool, descriptorSetCount, pDescriptorSets);

    DestroyWrappedHandles<DescriptorSetWrapper>(pDescriptorSets, descriptorSetCount);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(
    VkDevice                                    device,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const VkCopyDescriptorSet*                  pDescriptorCopies)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(TraceManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUpdateDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        EncodeStructArray(encoder, pDescriptorWrites, descriptorWriteCount);
        encoder->EncodeUInt32Value(descriptorCopyCount);
        EncodeStructArray(encoder, pDescriptorCopies, descriptorCopyCount);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkWriteDescriptorSet* pDescriptorWrites_unwrapped = UnwrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, handle_unwrap_memory);
    const VkCopyDescriptorSet* pDescriptorCopies_unwrapped = UnwrapStructArrayHandles(pDescriptorCopies, descriptorCopyCount, handle_unwrap_memory);

    GetDeviceTable(device)->UpdateDescriptorSets(device_unwrapped, descriptorWriteCount, pDescriptorWrites_unwrapped, descriptorCopyCount, pDescriptorCopies_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(TraceManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFramebuffer*                              pFramebuffer)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pFramebuffer);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkFramebufferCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateFramebuffer(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pFramebuffer);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, FramebufferWrapper>(device, NoParentWrapper::kHandleValue, pFramebuffer, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateFramebuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFramebuffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, FramebufferWrapper, VkFramebufferCreateInfo>(result, device, pFramebuffer, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pFramebuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(TraceManager::Get(), device, framebuffer, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyFramebuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(framebuffer);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<FramebufferWrapper>(framebuffer, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkFramebuffer framebuffer_unwrapped = GetWrappedHandle<VkFramebuffer>(framebuffer);

    GetDeviceTable(device)->DestroyFramebuffer(device_unwrapped, framebuffer_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(TraceManager::Get(), device, framebuffer, pAllocator);

    DestroyWrappedHandle<FramebufferWrapper>(framebuffer);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateRenderPass(device_unwrapped, pCreateInfo, pAllocator, pRenderPass);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, RenderPassWrapper>(device, NoParentWrapper::kHandleValue, pRenderPass, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pRenderPass, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, RenderPassWrapper, VkRenderPassCreateInfo>(result, device, pRenderPass, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(TraceManager::Get(), device, renderPass, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(renderPass);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<RenderPassWrapper>(renderPass, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkRenderPass renderPass_unwrapped = GetWrappedHandle<VkRenderPass>(renderPass);

    GetDeviceTable(device)->DestroyRenderPass(device_unwrapped, renderPass_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(TraceManager::Get(), device, renderPass, pAllocator);

    DestroyWrappedHandle<RenderPassWrapper>(renderPass);
}

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(TraceManager::Get(), device, renderPass, pGranularity);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkRenderPass renderPass_unwrapped = GetWrappedHandle<VkRenderPass>(renderPass);

    GetDeviceTable(device)->GetRenderAreaGranularity(device_unwrapped, renderPass_unwrapped, pGranularity);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRenderAreaGranularity);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(renderPass);
        EncodeStructPtr(encoder, pGranularity);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(TraceManager::Get(), device, renderPass, pGranularity);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pCommandPool);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateCommandPool(device_unwrapped, pCreateInfo, pAllocator, pCommandPool);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, CommandPoolWrapper>(device, NoParentWrapper::kHandleValue, pCommandPool, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pCommandPool, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, CommandPoolWrapper, VkCommandPoolCreateInfo>(result, device, pCommandPool, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pCommandPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(TraceManager::Get(), device, commandPool, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<CommandPoolWrapper>(commandPool, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkCommandPool commandPool_unwrapped = GetWrappedHandle<VkCommandPool>(commandPool);

    GetDeviceTable(device)->DestroyCommandPool(device_unwrapped, commandPool_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(TraceManager::Get(), device, commandPool, pAllocator);

    DestroyWrappedHandle<CommandPoolWrapper>(commandPool);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(TraceManager::Get(), device, commandPool, flags);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkCommandPool commandPool_unwrapped = GetWrappedHandle<VkCommandPool>(commandPool);

    VkResult result = GetDeviceTable(device)->ResetCommandPool(device_unwrapped, commandPool_unwrapped, flags);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(TraceManager::Get(), result, device, commandPool, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(
    VkDevice                                    device,
    const VkCommandBufferAllocateInfo*          pAllocateInfo,
    VkCommandBuffer*                            pCommandBuffers)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(TraceManager::Get(), device, pAllocateInfo, pCommandBuffers);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkCommandBufferAllocateInfo* pAllocateInfo_unwrapped = UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->AllocateCommandBuffers(device_unwrapped, pAllocateInfo_unwrapped, pCommandBuffers);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, CommandPoolWrapper, CommandBufferWrapper>(device, pAllocateInfo->commandPool, pCommandBuffers, pAllocateInfo->commandBufferCount, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkAllocateCommandBuffers);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        encoder->EncodeHandleArray(pCommandBuffers, (pAllocateInfo != nullptr) ? (pAllocateInfo->commandBufferCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndPoolCreateApiCallTrace<VkDevice, CommandBufferWrapper, VkCommandBufferAllocateInfo>(result, device, (pAllocateInfo != nullptr) ? (pAllocateInfo->commandBufferCount) : 0, pCommandBuffers, pAllocateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(TraceManager::Get(), result, device, pAllocateInfo, pCommandBuffers);

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(TraceManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkFreeCommandBuffers);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleArray(pCommandBuffers, commandBufferCount);
        TraceManager::Get()->EndDestroyApiCallTrace<CommandBufferWrapper>(commandBufferCount, pCommandBuffers, encoder);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkCommandPool commandPool_unwrapped = GetWrappedHandle<VkCommandPool>(commandPool);
    const VkCommandBuffer* pCommandBuffers_unwrapped = UnwrapHandles<VkCommandBuffer>(pCommandBuffers, commandBufferCount, handle_unwrap_memory);

    GetDeviceTable(device)->FreeCommandBuffers(device_unwrapped, commandPool_unwrapped, commandBufferCount, pCommandBuffers_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(TraceManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);

    DestroyWrappedHandles<CommandBufferWrapper>(pCommandBuffers, commandBufferCount);
}

VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(TraceManager::Get(), commandBuffer, pBeginInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCommandBufferBeginInfo* pBeginInfo_unwrapped = UnwrapStructPtrHandles(pBeginInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(commandBuffer)->BeginCommandBuffer(commandBuffer_unwrapped, pBeginInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkBeginCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pBeginInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackBeginCommandBufferHandles, pBeginInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(TraceManager::Get(), result, commandBuffer, pBeginInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(
    VkCommandBuffer                             commandBuffer)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(TraceManager::Get(), commandBuffer);

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    VkResult result = GetDeviceTable(commandBuffer)->EndCommandBuffer(commandBuffer_unwrapped);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkEndCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(TraceManager::Get(), result, commandBuffer);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(TraceManager::Get(), commandBuffer, flags);

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    VkResult result = GetDeviceTable(commandBuffer)->ResetCommandBuffer(commandBuffer_unwrapped, flags);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkResetCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(TraceManager::Get(), result, commandBuffer, flags);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(TraceManager::Get(), commandBuffer, pipelineBindPoint, pipeline);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindPipeline);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleValue(pipeline);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindPipelineHandles, pipeline);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    GetDeviceTable(commandBuffer)->CmdBindPipeline(commandBuffer_unwrapped, pipelineBindPoint, pipeline_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(TraceManager::Get(), commandBuffer, pipelineBindPoint, pipeline);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewports);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewport);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewports, viewportCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewport(commandBuffer_unwrapped, firstViewport, viewportCount, pViewports);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(TraceManager::Get(), commandBuffer, firstScissor, scissorCount, pScissors);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetScissor);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstScissor);
        encoder->EncodeUInt32Value(scissorCount);
        EncodeStructArray(encoder, pScissors, scissorCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetScissor(commandBuffer_unwrapped, firstScissor, scissorCount, pScissors);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(TraceManager::Get(), commandBuffer, firstScissor, scissorCount, pScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(TraceManager::Get(), commandBuffer, lineWidth);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetLineWidth);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatValue(lineWidth);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetLineWidth(commandBuffer_unwrapped, lineWidth);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(TraceManager::Get(), commandBuffer, lineWidth);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(TraceManager::Get(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthBias);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatValue(depthBiasConstantFactor);
        encoder->EncodeFloatValue(depthBiasClamp);
        encoder->EncodeFloatValue(depthBiasSlopeFactor);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthBias(commandBuffer_unwrapped, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(TraceManager::Get(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4])
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(TraceManager::Get(), commandBuffer, blendConstants);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetBlendConstants);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatArray(blendConstants, 4);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetBlendConstants(commandBuffer_unwrapped, blendConstants);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(TraceManager::Get(), commandBuffer, blendConstants);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(TraceManager::Get(), commandBuffer, minDepthBounds, maxDepthBounds);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthBounds);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatValue(minDepthBounds);
        encoder->EncodeFloatValue(maxDepthBounds);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthBounds(commandBuffer_unwrapped, minDepthBounds, maxDepthBounds);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(TraceManager::Get(), commandBuffer, minDepthBounds, maxDepthBounds);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(TraceManager::Get(), commandBuffer, faceMask, compareMask);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(compareMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilCompareMask(commandBuffer_unwrapped, faceMask, compareMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(TraceManager::Get(), commandBuffer, faceMask, compareMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(TraceManager::Get(), commandBuffer, faceMask, writeMask);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(writeMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilWriteMask(commandBuffer_unwrapped, faceMask, writeMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(TraceManager::Get(), commandBuffer, faceMask, writeMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(TraceManager::Get(), commandBuffer, faceMask, reference);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilReference);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(reference);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilReference(commandBuffer_unwrapped, faceMask, reference);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(TraceManager::Get(), commandBuffer, faceMask, reference);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets);
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
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindDescriptorSetsHandles, layout, descriptorSetCount, pDescriptorSets);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkPipelineLayout layout_unwrapped = GetWrappedHandle<VkPipelineLayout>(layout);
    const VkDescriptorSet* pDescriptorSets_unwrapped = UnwrapHandles<VkDescriptorSet>(pDescriptorSets, descriptorSetCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBindDescriptorSets(commandBuffer_unwrapped, pipelineBindPoint, layout_unwrapped, firstSet, descriptorSetCount, pDescriptorSets_unwrapped, dynamicOffsetCount, pDynamicOffsets);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, indexType);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeEnumValue(indexType);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindIndexBufferHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdBindIndexBuffer(commandBuffer_unwrapped, buffer_unwrapped, offset, indexType);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, indexType);
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindVertexBuffersHandles, bindingCount, pBuffers);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pBuffers_unwrapped = UnwrapHandles<VkBuffer>(pBuffers, bindingCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBindVertexBuffers(commandBuffer_unwrapped, firstBinding, bindingCount, pBuffers_unwrapped, pOffsets);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(TraceManager::Get(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDraw);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(vertexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstVertex);
        encoder->EncodeUInt32Value(firstInstance);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDraw(commandBuffer_unwrapped, vertexCount, instanceCount, firstVertex, firstInstance);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(TraceManager::Get(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(TraceManager::Get(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexed);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(indexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstIndex);
        encoder->EncodeInt32Value(vertexOffset);
        encoder->EncodeUInt32Value(firstInstance);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndexed(commandBuffer_unwrapped, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(TraceManager::Get(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirect);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndirectHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndirect(commandBuffer_unwrapped, buffer_unwrapped, offset, drawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndexedIndirectHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirect(commandBuffer_unwrapped, buffer_unwrapped, offset, drawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(TraceManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatch);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDispatch(commandBuffer_unwrapped, groupCountX, groupCountY, groupCountZ);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(TraceManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchIndirect);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDispatchIndirectHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdDispatchIndirect(commandBuffer_unwrapped, buffer_unwrapped, offset);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(TraceManager::Get(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcBuffer);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyBufferHandles, srcBuffer, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer srcBuffer_unwrapped = GetWrappedHandle<VkBuffer>(srcBuffer);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdCopyBuffer(commandBuffer_unwrapped, srcBuffer_unwrapped, dstBuffer_unwrapped, regionCount, pRegions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(TraceManager::Get(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyImageHandles, srcImage, dstImage);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage srcImage_unwrapped = GetWrappedHandle<VkImage>(srcImage);
    VkImage dstImage_unwrapped = GetWrappedHandle<VkImage>(dstImage);

    GetDeviceTable(commandBuffer)->CmdCopyImage(commandBuffer_unwrapped, srcImage_unwrapped, srcImageLayout, dstImage_unwrapped, dstImageLayout, regionCount, pRegions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBlitImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        encoder->EncodeEnumValue(filter);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBlitImageHandles, srcImage, dstImage);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage srcImage_unwrapped = GetWrappedHandle<VkImage>(srcImage);
    VkImage dstImage_unwrapped = GetWrappedHandle<VkImage>(dstImage);

    GetDeviceTable(commandBuffer)->CmdBlitImage(commandBuffer_unwrapped, srcImage_unwrapped, srcImageLayout, dstImage_unwrapped, dstImageLayout, regionCount, pRegions, filter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(TraceManager::Get(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcBuffer);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyBufferToImageHandles, srcBuffer, dstImage);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer srcBuffer_unwrapped = GetWrappedHandle<VkBuffer>(srcBuffer);
    VkImage dstImage_unwrapped = GetWrappedHandle<VkImage>(dstImage);

    GetDeviceTable(commandBuffer)->CmdCopyBufferToImage(commandBuffer_unwrapped, srcBuffer_unwrapped, dstImage_unwrapped, dstImageLayout, regionCount, pRegions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(TraceManager::Get(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyImageToBufferHandles, srcImage, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage srcImage_unwrapped = GetWrappedHandle<VkImage>(srcImage);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdCopyImageToBuffer(commandBuffer_unwrapped, srcImage_unwrapped, srcImageLayout, dstBuffer_unwrapped, regionCount, pRegions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdUpdateBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(dataSize);
        encoder->EncodeVoidArray(pData, static_cast<size_t>(dataSize));
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdUpdateBufferHandles, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdUpdateBuffer(commandBuffer_unwrapped, dstBuffer_unwrapped, dstOffset, dataSize, pData);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, size, data);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdFillBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeUInt32Value(data);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdFillBufferHandles, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdFillBuffer(commandBuffer_unwrapped, dstBuffer_unwrapped, dstOffset, size, data);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, size, data);
}

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(TraceManager::Get(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearColorImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(image);
        encoder->EncodeEnumValue(imageLayout);
        EncodeStructPtr(encoder, pColor);
        encoder->EncodeUInt32Value(rangeCount);
        EncodeStructArray(encoder, pRanges, rangeCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdClearColorImageHandles, image);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(commandBuffer)->CmdClearColorImage(commandBuffer_unwrapped, image_unwrapped, imageLayout, pColor, rangeCount, pRanges);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(TraceManager::Get(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(TraceManager::Get(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(image);
        encoder->EncodeEnumValue(imageLayout);
        EncodeStructPtr(encoder, pDepthStencil);
        encoder->EncodeUInt32Value(rangeCount);
        EncodeStructArray(encoder, pRanges, rangeCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdClearDepthStencilImageHandles, image);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(commandBuffer)->CmdClearDepthStencilImage(commandBuffer_unwrapped, image_unwrapped, imageLayout, pDepthStencil, rangeCount, pRanges);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(TraceManager::Get(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(TraceManager::Get(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearAttachments);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(attachmentCount);
        EncodeStructArray(encoder, pAttachments, attachmentCount);
        encoder->EncodeUInt32Value(rectCount);
        EncodeStructArray(encoder, pRects, rectCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdClearAttachments(commandBuffer_unwrapped, attachmentCount, pAttachments, rectCount, pRects);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(TraceManager::Get(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdResolveImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdResolveImageHandles, srcImage, dstImage);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage srcImage_unwrapped = GetWrappedHandle<VkImage>(srcImage);
    VkImage dstImage_unwrapped = GetWrappedHandle<VkImage>(dstImage);

    GetDeviceTable(commandBuffer)->CmdResolveImage(commandBuffer_unwrapped, srcImage_unwrapped, srcImageLayout, dstImage_unwrapped, dstImageLayout, regionCount, pRegions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(TraceManager::Get(), commandBuffer, event, stageMask);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(event);
        encoder->EncodeFlagsValue(stageMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdSetEventHandles, event);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    GetDeviceTable(commandBuffer)->CmdSetEvent(commandBuffer_unwrapped, event_unwrapped, stageMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(TraceManager::Get(), commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(TraceManager::Get(), commandBuffer, event, stageMask);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(event);
        encoder->EncodeFlagsValue(stageMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdResetEventHandles, event);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    GetDeviceTable(commandBuffer)->CmdResetEvent(commandBuffer_unwrapped, event_unwrapped, stageMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(TraceManager::Get(), commandBuffer, event, stageMask);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(TraceManager::Get(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdWaitEvents);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(eventCount);
        encoder->EncodeHandleArray(pEvents, eventCount);
        encoder->EncodeFlagsValue(srcStageMask);
        encoder->EncodeFlagsValue(dstStageMask);
        encoder->EncodeUInt32Value(memoryBarrierCount);
        EncodeStructArray(encoder, pMemoryBarriers, memoryBarrierCount);
        encoder->EncodeUInt32Value(bufferMemoryBarrierCount);
        EncodeStructArray(encoder, pBufferMemoryBarriers, bufferMemoryBarrierCount);
        encoder->EncodeUInt32Value(imageMemoryBarrierCount);
        EncodeStructArray(encoder, pImageMemoryBarriers, imageMemoryBarrierCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdWaitEventsHandles, eventCount, pEvents, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkEvent* pEvents_unwrapped = UnwrapHandles<VkEvent>(pEvents, eventCount, handle_unwrap_memory);
    const VkBufferMemoryBarrier* pBufferMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, handle_unwrap_memory);
    const VkImageMemoryBarrier* pImageMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdWaitEvents(commandBuffer_unwrapped, eventCount, pEvents_unwrapped, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers_unwrapped, imageMemoryBarrierCount, pImageMemoryBarriers_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(TraceManager::Get(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(TraceManager::Get(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdPipelineBarrier);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(srcStageMask);
        encoder->EncodeFlagsValue(dstStageMask);
        encoder->EncodeFlagsValue(dependencyFlags);
        encoder->EncodeUInt32Value(memoryBarrierCount);
        EncodeStructArray(encoder, pMemoryBarriers, memoryBarrierCount);
        encoder->EncodeUInt32Value(bufferMemoryBarrierCount);
        EncodeStructArray(encoder, pBufferMemoryBarriers, bufferMemoryBarrierCount);
        encoder->EncodeUInt32Value(imageMemoryBarrierCount);
        EncodeStructArray(encoder, pImageMemoryBarriers, imageMemoryBarrierCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdPipelineBarrierHandles, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBufferMemoryBarrier* pBufferMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, handle_unwrap_memory);
    const VkImageMemoryBarrier* pImageMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdPipelineBarrier(commandBuffer_unwrapped, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers_unwrapped, imageMemoryBarrierCount, pImageMemoryBarriers_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(TraceManager::Get(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, query, flags);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginQuery);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginQueryHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdBeginQuery(commandBuffer_unwrapped, queryPool_unwrapped, query, flags);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, query, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, query);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndQuery);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdEndQueryHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdEndQuery(commandBuffer_unwrapped, queryPool_unwrapped, query);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, query);
}

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdResetQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdResetQueryPoolHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdResetQueryPool(commandBuffer_unwrapped, queryPool_unwrapped, firstQuery, queryCount);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(TraceManager::Get(), commandBuffer, pipelineStage, queryPool, query);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteTimestamp);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdWriteTimestampHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdWriteTimestamp(commandBuffer_unwrapped, pipelineStage, queryPool_unwrapped, query);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(TraceManager::Get(), commandBuffer, pipelineStage, queryPool, query);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults);
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
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyQueryPoolResultsHandles, queryPool, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdCopyQueryPoolResults(commandBuffer_unwrapped, queryPool_unwrapped, firstQuery, queryCount, dstBuffer_unwrapped, dstOffset, stride, flags);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(TraceManager::Get(), commandBuffer, layout, stageFlags, offset, size, pValues);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdPushConstants);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(layout);
        encoder->EncodeFlagsValue(stageFlags);
        encoder->EncodeUInt32Value(offset);
        encoder->EncodeUInt32Value(size);
        encoder->EncodeVoidArray(pValues, size);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdPushConstantsHandles, layout);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkPipelineLayout layout_unwrapped = GetWrappedHandle<VkPipelineLayout>(layout);

    GetDeviceTable(commandBuffer)->CmdPushConstants(commandBuffer_unwrapped, layout_unwrapped, stageFlags, offset, size, pValues);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(TraceManager::Get(), commandBuffer, layout, stageFlags, offset, size, pValues);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(TraceManager::Get(), commandBuffer, pRenderPassBegin, contents);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderPassBegin);
        encoder->EncodeEnumValue(contents);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginRenderPassHandles, pRenderPassBegin);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginRenderPass(commandBuffer_unwrapped, pRenderPassBegin_unwrapped, contents);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(TraceManager::Get(), commandBuffer, pRenderPassBegin, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(TraceManager::Get(), commandBuffer, contents);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdNextSubpass);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(contents);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdNextSubpass(commandBuffer_unwrapped, contents);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(TraceManager::Get(), commandBuffer, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(
    VkCommandBuffer                             commandBuffer)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(TraceManager::Get(), commandBuffer);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndRenderPass(commandBuffer_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(TraceManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdExecuteCommands);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleArray(pCommandBuffers, commandBufferCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdExecuteCommandsHandles, commandBufferCount, pCommandBuffers);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCommandBuffer* pCommandBuffers_unwrapped = UnwrapHandles<VkCommandBuffer>(pCommandBuffers, commandBufferCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdExecuteCommands(commandBuffer_unwrapped, commandBufferCount, pCommandBuffers_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(TraceManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindBufferMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindBufferMemory2(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindImageMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindImageMemory2(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->GetDeviceGroupPeerMemoryFeatures(device_unwrapped, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(TraceManager::Get(), commandBuffer, deviceMask);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDeviceMask);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDeviceMask(commandBuffer_unwrapped, deviceMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(TraceManager::Get(), commandBuffer, deviceMask);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchBase);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDispatchBase(commandBuffer_unwrapped, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(TraceManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->EnumeratePhysicalDeviceGroups(instance_unwrapped, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<InstanceWrapper, NoParentWrapper, VkPhysicalDeviceGroupProperties>(instance, NoParentWrapper::kHandleValue, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount, omit_output_data);
        EncodeStructArray(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndStructGroupCreateApiCallTrace<VkInstance, PhysicalDeviceWrapper, VkPhysicalDeviceGroupProperties>(result, instance, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, pPhysicalDeviceGroupProperties, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(TraceManager::Get(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetImageMemoryRequirements2(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetBufferMemoryRequirements2(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageSparseMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetImageSparseMemoryRequirements2(device_unwrapped, pInfo_unwrapped, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(TraceManager::Get(), physicalDevice, pFeatures);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures2(physicalDevice_unwrapped, pFeatures);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(TraceManager::Get(), physicalDevice, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice_unwrapped, pProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(TraceManager::Get(), physicalDevice, format, pFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties2(physicalDevice_unwrapped, format, pFormatProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        EncodeStructPtr(encoder, pFormatProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(TraceManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties2(physicalDevice_unwrapped, pImageFormatInfo, pImageFormatProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pImageFormatInfo);
        EncodeStructPtr(encoder, pImageFormatProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(TraceManager::Get(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice_unwrapped, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        EncodeStructArray(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(TraceManager::Get(), physicalDevice, pMemoryProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties2(physicalDevice_unwrapped, pMemoryProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pMemoryProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice_unwrapped, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pFormatInfo);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(TraceManager::Get(), device, commandPool, flags);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkTrimCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkCommandPool commandPool_unwrapped = GetWrappedHandle<VkCommandPool>(commandPool);

    GetDeviceTable(device)->TrimCommandPool(device_unwrapped, commandPool_unwrapped, flags);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(TraceManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(
    VkDevice                                    device,
    const VkDeviceQueueInfo2*                   pQueueInfo,
    VkQueue*                                    pQueue)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(TraceManager::Get(), device, pQueueInfo, pQueue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->GetDeviceQueue2(device_unwrapped, pQueueInfo, pQueue);

    CreateWrappedHandle<DeviceWrapper, NoParentWrapper, QueueWrapper>(device, NoParentWrapper::kHandleValue, pQueue, TraceManager::GetUniqueId);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceQueue2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pQueueInfo);
        encoder->EncodeHandlePtr(pQueue);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, QueueWrapper, void>(VK_SUCCESS, device, pQueue, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(TraceManager::Get(), device, pQueueInfo, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateSamplerYcbcrConversion(device_unwrapped, pCreateInfo, pAllocator, pYcbcrConversion);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SamplerYcbcrConversionWrapper>(device, NoParentWrapper::kHandleValue, pYcbcrConversion, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pYcbcrConversion, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, SamplerYcbcrConversionWrapper, VkSamplerYcbcrConversionCreateInfo>(result, device, pYcbcrConversion, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(TraceManager::Get(), device, ycbcrConversion, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(ycbcrConversion);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SamplerYcbcrConversionWrapper>(ycbcrConversion, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSamplerYcbcrConversion ycbcrConversion_unwrapped = GetWrappedHandle<VkSamplerYcbcrConversion>(ycbcrConversion);

    GetDeviceTable(device)->DestroySamplerYcbcrConversion(device_unwrapped, ycbcrConversion_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(TraceManager::Get(), device, ycbcrConversion, pAllocator);

    DestroyWrappedHandle<SamplerYcbcrConversionWrapper>(ycbcrConversion);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateDescriptorUpdateTemplate(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pDescriptorUpdateTemplate);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorUpdateTemplateWrapper>(device, NoParentWrapper::kHandleValue, pDescriptorUpdateTemplate, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDescriptorUpdateTemplate, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, DescriptorUpdateTemplateWrapper, VkDescriptorUpdateTemplateCreateInfo>(result, device, pDescriptorUpdateTemplate, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorUpdateTemplate descriptorUpdateTemplate_unwrapped = GetWrappedHandle<VkDescriptorUpdateTemplate>(descriptorUpdateTemplate);

    GetDeviceTable(device)->DestroyDescriptorUpdateTemplate(device_unwrapped, descriptorUpdateTemplate_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    DestroyWrappedHandle<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalBufferProperties(physicalDevice_unwrapped, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalBufferInfo);
        EncodeStructPtr(encoder, pExternalBufferProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalFenceProperties(physicalDevice_unwrapped, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalFenceInfo);
        EncodeStructPtr(encoder, pExternalFenceProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice_unwrapped, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalSemaphoreInfo);
        EncodeStructPtr(encoder, pExternalSemaphoreProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(TraceManager::Get(), device, pCreateInfo, pSupport);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetDescriptorSetLayoutSupport(device_unwrapped, pCreateInfo_unwrapped, pSupport);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pSupport);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(TraceManager::Get(), device, pCreateInfo, pSupport);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectCount);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndirectCountHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndirectCount(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCount(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndexedIndirectCountHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirectCount(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateRenderPass2(device_unwrapped, pCreateInfo, pAllocator, pRenderPass);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, RenderPassWrapper>(device, NoParentWrapper::kHandleValue, pRenderPass, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pRenderPass, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, RenderPassWrapper, VkRenderPassCreateInfo2>(result, device, pRenderPass, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderPassBegin);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginRenderPass2Handles, pRenderPassBegin);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginRenderPass2(commandBuffer_unwrapped, pRenderPassBegin_unwrapped, pSubpassBeginInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdNextSubpass2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdNextSubpass2(commandBuffer_unwrapped, pSubpassBeginInfo, pSubpassEndInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassEndInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndRenderPass2(commandBuffer_unwrapped, pSubpassEndInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL ResetQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(TraceManager::Get(), device, queryPool, firstQuery, queryCount);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(device)->ResetQueryPool(device_unwrapped, queryPool_unwrapped, firstQuery, queryCount);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(TraceManager::Get(), device, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValue(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    uint64_t*                                   pValue)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(TraceManager::Get(), device, semaphore, pValue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSemaphore semaphore_unwrapped = GetWrappedHandle<VkSemaphore>(semaphore);

    VkResult result = GetDeviceTable(device)->GetSemaphoreCounterValue(device_unwrapped, semaphore_unwrapped, pValue);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(semaphore);
        encoder->EncodeUInt64Ptr(pValue, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(TraceManager::Get(), result, device, semaphore, pValue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphores(
    VkDevice                                    device,
    const VkSemaphoreWaitInfo*                  pWaitInfo,
    uint64_t                                    timeout)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(TraceManager::Get(), device, pWaitInfo, timeout);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreWaitInfo* pWaitInfo_unwrapped = UnwrapStructPtrHandles(pWaitInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->WaitSemaphores(device_unwrapped, pWaitInfo_unwrapped, timeout);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkWaitSemaphores);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pWaitInfo);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(TraceManager::Get(), result, device, pWaitInfo, timeout);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphore(
    VkDevice                                    device,
    const VkSemaphoreSignalInfo*                pSignalInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(TraceManager::Get(), device, pSignalInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreSignalInfo* pSignalInfo_unwrapped = UnwrapStructPtrHandles(pSignalInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->SignalSemaphore(device_unwrapped, pSignalInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSignalSemaphore);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pSignalInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(TraceManager::Get(), result, device, pSignalInfo);

    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddress(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkDeviceAddress result = GetDeviceTable(device)->GetBufferDeviceAddress(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferDeviceAddress);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVkDeviceAddressValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddress(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    uint64_t result = GetDeviceTable(device)->GetBufferOpaqueCaptureAddress(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress(
    VkDevice                                    device,
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    uint64_t result = GetDeviceTable(device)->GetDeviceMemoryOpaqueCaptureAddress(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(TraceManager::Get(), instance, surface, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroySurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeHandleValue(surface);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SurfaceKHRWrapper>(surface, encoder);
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    GetInstanceTable(instance)->DestroySurfaceKHR(instance_unwrapped, surface_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(TraceManager::Get(), instance, surface, pAllocator);

    DestroyWrappedHandle<SurfaceKHRWrapper>(surface);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(TraceManager::Get(), physicalDevice, queueFamilyIndex, surface, pSupported);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice_unwrapped, queueFamilyIndex, surface_unwrapped, pSupported);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeVkBool32Ptr(pSupported, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, queueFamilyIndex, surface, pSupported);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice_unwrapped, surface_unwrapped, pSurfaceCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        EncodeStructPtr(encoder, pSurfaceCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, surface, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormatKHR*                         pSurfaceFormats)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(TraceManager::Get(), physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice_unwrapped, surface_unwrapped, pSurfaceFormatCount, pSurfaceFormats);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount, omit_output_data);
        EncodeStructArray(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(TraceManager::Get(), physicalDevice, surface, pPresentModeCount, pPresentModes);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice_unwrapped, surface_unwrapped, pPresentModeCount, pPresentModes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeUInt32Ptr(pPresentModeCount, omit_output_data);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, surface, pPresentModeCount, pPresentModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pSwapchain);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSwapchainCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateSwapchainKHR(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pSwapchain);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SwapchainKHRWrapper>(device, NoParentWrapper::kHandleValue, pSwapchain, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSwapchainKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSwapchain, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, SwapchainKHRWrapper, VkSwapchainCreateInfoKHR>(result, device, pSwapchain, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSwapchain);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(TraceManager::Get(), device, swapchain, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroySwapchainKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SwapchainKHRWrapper>(swapchain, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    GetDeviceTable(device)->DestroySwapchainKHR(device_unwrapped, swapchain_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(TraceManager::Get(), device, swapchain, pAllocator);

    DestroyWrappedHandle<SwapchainKHRWrapper>(swapchain);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pSwapchainImageCount,
    VkImage*                                    pSwapchainImages)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(TraceManager::Get(), device, swapchain, pSwapchainImageCount, pSwapchainImages);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->GetSwapchainImagesKHR(device_unwrapped, swapchain_unwrapped, pSwapchainImageCount, pSwapchainImages);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, SwapchainKHRWrapper, ImageWrapper>(device, swapchain, pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeUInt32Ptr(pSwapchainImageCount, omit_output_data);
        encoder->EncodeHandleArray(pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndGroupCreateApiCallTrace<VkDevice, VkSwapchainKHR, ImageWrapper, void>(result, device, swapchain, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0, pSwapchainImages, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(TraceManager::Get(), result, device, swapchain, pSwapchainImageCount, pSwapchainImages);

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
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(TraceManager::Get(), device, swapchain, timeout, semaphore, fence, pImageIndex);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);
    VkSemaphore semaphore_unwrapped = GetWrappedHandle<VkSemaphore>(semaphore);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    VkResult result = GetDeviceTable(device)->AcquireNextImageKHR(device_unwrapped, swapchain_unwrapped, timeout, semaphore_unwrapped, fence_unwrapped, pImageIndex);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireNextImageKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeHandleValue(semaphore);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeUInt32Ptr(pImageIndex, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(TraceManager::Get(), result, device, swapchain, timeout, semaphore, fence, pImageIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(TraceManager::Get(), queue, pPresentInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);
    const VkPresentInfoKHR* pPresentInfo_unwrapped = UnwrapStructPtrHandles(pPresentInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(queue)->QueuePresentKHR(queue_unwrapped, pPresentInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueuePresentKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        EncodeStructPtr(encoder, pPresentInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(TraceManager::Get(), result, queue, pPresentInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR(
    VkDevice                                    device,
    VkDeviceGroupPresentCapabilitiesKHR*        pDeviceGroupPresentCapabilities)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(TraceManager::Get(), device, pDeviceGroupPresentCapabilities);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetDeviceGroupPresentCapabilitiesKHR(device_unwrapped, pDeviceGroupPresentCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pDeviceGroupPresentCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(TraceManager::Get(), result, device, pDeviceGroupPresentCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    VkDeviceGroupPresentModeFlagsKHR*           pModes)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(TraceManager::Get(), device, surface, pModes);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetDeviceTable(device)->GetDeviceGroupSurfacePresentModesKHR(device_unwrapped, surface_unwrapped, pModes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeFlagsPtr(pModes, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(TraceManager::Get(), result, device, surface, pModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pRectCount,
    VkRect2D*                                   pRects)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(TraceManager::Get(), physicalDevice, surface, pRectCount, pRects);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(physicalDevice_unwrapped, surface_unwrapped, pRectCount, pRects);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeUInt32Ptr(pRectCount, omit_output_data);
        EncodeStructArray(encoder, pRects, (pRectCount != nullptr) ? (*pRectCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, surface, pRectCount, pRects);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(
    VkDevice                                    device,
    const VkAcquireNextImageInfoKHR*            pAcquireInfo,
    uint32_t*                                   pImageIndex)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(TraceManager::Get(), device, pAcquireInfo, pImageIndex);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAcquireNextImageInfoKHR* pAcquireInfo_unwrapped = UnwrapStructPtrHandles(pAcquireInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->AcquireNextImage2KHR(device_unwrapped, pAcquireInfo_unwrapped, pImageIndex);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireNextImage2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAcquireInfo);
        encoder->EncodeUInt32Ptr(pImageIndex, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(TraceManager::Get(), result, device, pAcquireInfo, pImageIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPropertiesKHR*                     pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayPropertiesKHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndStructGroupCreateApiCallTrace<VkPhysicalDevice, DisplayKHRWrapper, VkDisplayPropertiesKHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayPropertiesKHR* handle_struct)->DisplayKHRWrapper* { return reinterpret_cast<DisplayKHRWrapper*>(handle_struct->display); }, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayPlanePropertiesKHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndStructGroupCreateApiCallTrace<VkPhysicalDevice, DisplayKHRWrapper, VkDisplayPlanePropertiesKHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayPlanePropertiesKHR* handle_struct)->DisplayKHRWrapper* { return reinterpret_cast<DisplayKHRWrapper*>(handle_struct->currentDisplay); }, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(TraceManager::Get(), physicalDevice, planeIndex, pDisplayCount, pDisplays);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice_unwrapped, planeIndex, pDisplayCount, pDisplays);

    if (result >= 0)
    {
        CreateWrappedHandles<PhysicalDeviceWrapper, NoParentWrapper, DisplayKHRWrapper>(physicalDevice, NoParentWrapper::kHandleValue, pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(planeIndex);
        encoder->EncodeUInt32Ptr(pDisplayCount, omit_output_data);
        encoder->EncodeHandleArray(pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndGroupCreateApiCallTrace<VkPhysicalDevice, void*, DisplayKHRWrapper, void>(result, physicalDevice, nullptr, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0, pDisplays, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, planeIndex, pDisplayCount, pDisplays);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModePropertiesKHR*                 pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->GetDisplayModePropertiesKHR(physicalDevice_unwrapped, display_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, DisplayKHRWrapper, VkDisplayModePropertiesKHR>(physicalDevice, display, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndStructGroupCreateApiCallTrace<VkPhysicalDevice, DisplayModeKHRWrapper, VkDisplayModePropertiesKHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayModePropertiesKHR* handle_struct)->DisplayModeKHRWrapper* { return reinterpret_cast<DisplayModeKHRWrapper*>(handle_struct->displayMode); }, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(TraceManager::Get(), physicalDevice, display, pCreateInfo, pAllocator, pMode);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->CreateDisplayModeKHR(physicalDevice_unwrapped, display_unwrapped, pCreateInfo, pAllocator, pMode);

    if (result >= 0)
    {
        CreateWrappedHandle<PhysicalDeviceWrapper, DisplayKHRWrapper, DisplayModeKHRWrapper>(physicalDevice, display, pMode, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDisplayModeKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pMode, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkPhysicalDevice, DisplayModeKHRWrapper, VkDisplayModeCreateInfoKHR>(result, physicalDevice, pMode, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, display, pCreateInfo, pAllocator, pMode);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    VkDisplayPlaneCapabilitiesKHR*              pCapabilities)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, mode, planeIndex, pCapabilities);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayModeKHR mode_unwrapped = GetWrappedHandle<VkDisplayModeKHR>(mode);

    VkResult result = GetInstanceTable(physicalDevice)->GetDisplayPlaneCapabilitiesKHR(physicalDevice_unwrapped, mode_unwrapped, planeIndex, pCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(mode);
        encoder->EncodeUInt32Value(planeIndex);
        EncodeStructPtr(encoder, pCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, mode, planeIndex, pCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);
    const VkDisplaySurfaceCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetInstanceTable(instance)->CreateDisplayPlaneSurfaceKHR(instance_unwrapped, pCreateInfo_unwrapped, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkDisplaySurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(TraceManager::Get(), device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSwapchainCreateInfoKHR* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, swapchainCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateSharedSwapchainsKHR(device_unwrapped, swapchainCount, pCreateInfos_unwrapped, pAllocator, pSwapchains);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, NoParentWrapper, SwapchainKHRWrapper>(device, NoParentWrapper::kHandleValue, pSwapchains, swapchainCount, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        EncodeStructArray(encoder, pCreateInfos, swapchainCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleArray(pSwapchains, swapchainCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndGroupCreateApiCallTrace<VkDevice, void*, SwapchainKHRWrapper, VkSwapchainCreateInfoKHR>(result, device, nullptr, swapchainCount, pSwapchains, pCreateInfos, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(TraceManager::Get(), result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateXlibSurfaceKHR(
    VkInstance                                  instance,
    const VkXlibSurfaceCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateXlibSurfaceKHR(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkXlibSurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    Display*                                    dpy,
    VisualID                                    visualID)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(TraceManager::Get(), physicalDevice, queueFamilyIndex, dpy, visualID);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice_unwrapped, queueFamilyIndex, dpy, visualID);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeSizeTValue(visualID);
        encoder->EncodeVkBool32Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, queueFamilyIndex, dpy, visualID);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateXcbSurfaceKHR(
    VkInstance                                  instance,
    const VkXcbSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateXcbSurfaceKHR(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkXcbSurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    xcb_connection_t*                           connection,
    xcb_visualid_t                              visual_id)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(TraceManager::Get(), physicalDevice, queueFamilyIndex, connection, visual_id);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice_unwrapped, queueFamilyIndex, connection, visual_id);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(connection);
        encoder->EncodeUInt32Value(visual_id);
        encoder->EncodeVkBool32Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, queueFamilyIndex, connection, visual_id);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateWaylandSurfaceKHR(
    VkInstance                                  instance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateWaylandSurfaceKHR(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkWaylandSurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct wl_display*                          display)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(TraceManager::Get(), physicalDevice, queueFamilyIndex, display);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice_unwrapped, queueFamilyIndex, display);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(display);
        encoder->EncodeVkBool32Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, queueFamilyIndex, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAndroidSurfaceKHR(
    VkInstance                                  instance,
    const VkAndroidSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateAndroidSurfaceKHR(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkAndroidSurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateWin32SurfaceKHR(
    VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateWin32SurfaceKHR(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkWin32SurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(TraceManager::Get(), physicalDevice, queueFamilyIndex);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice_unwrapped, queueFamilyIndex);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVkBool32Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, queueFamilyIndex);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pFeatures);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures2KHR(physicalDevice_unwrapped, pFeatures);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice_unwrapped, pProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, format, pFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(physicalDevice_unwrapped, format, pFormatProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        EncodeStructPtr(encoder, pFormatProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice_unwrapped, pImageFormatInfo, pImageFormatProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pImageFormatInfo);
        EncodeStructPtr(encoder, pImageFormatProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(TraceManager::Get(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice_unwrapped, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        EncodeStructArray(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pMemoryProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(physicalDevice_unwrapped, pMemoryProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pMemoryProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice_unwrapped, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pFormatInfo);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->GetDeviceGroupPeerMemoryFeaturesKHR(device_unwrapped, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(TraceManager::Get(), commandBuffer, deviceMask);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDeviceMaskKHR(commandBuffer_unwrapped, deviceMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(TraceManager::Get(), commandBuffer, deviceMask);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDispatchBaseKHR(commandBuffer_unwrapped, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(TraceManager::Get(), device, commandPool, flags);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkTrimCommandPoolKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkCommandPool commandPool_unwrapped = GetWrappedHandle<VkCommandPool>(commandPool);

    GetDeviceTable(device)->TrimCommandPoolKHR(device_unwrapped, commandPool_unwrapped, flags);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(TraceManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(TraceManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->EnumeratePhysicalDeviceGroupsKHR(instance_unwrapped, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<InstanceWrapper, NoParentWrapper, VkPhysicalDeviceGroupProperties>(instance, NoParentWrapper::kHandleValue, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount, omit_output_data);
        EncodeStructArray(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndStructGroupCreateApiCallTrace<VkInstance, PhysicalDeviceWrapper, VkPhysicalDeviceGroupProperties>(result, instance, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, pPhysicalDeviceGroupProperties, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(TraceManager::Get(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice_unwrapped, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalBufferInfo);
        EncodeStructPtr(encoder, pExternalBufferProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleKHR(
    VkDevice                                    device,
    const VkMemoryGetWin32HandleInfoKHR*        pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetMemoryWin32HandleKHR(device_unwrapped, pGetWin32HandleInfo_unwrapped, pHandle);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandlePropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    VkMemoryWin32HandlePropertiesKHR*           pMemoryWin32HandleProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(TraceManager::Get(), device, handleType, handle, pMemoryWin32HandleProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetMemoryWin32HandlePropertiesKHR(device_unwrapped, handleType, handle, pMemoryWin32HandleProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(handle);
        EncodeStructPtr(encoder, pMemoryWin32HandleProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(TraceManager::Get(), result, device, handleType, handle, pMemoryWin32HandleProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(
    VkDevice                                    device,
    const VkMemoryGetFdInfoKHR*                 pGetFdInfo,
    int*                                        pFd)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(TraceManager::Get(), device, pGetFdInfo, pFd);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMemoryGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetMemoryFdKHR(device_unwrapped, pGetFdInfo_unwrapped, pFd);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    VkMemoryFdPropertiesKHR*                    pMemoryFdProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(TraceManager::Get(), device, handleType, fd, pMemoryFdProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetMemoryFdPropertiesKHR(device_unwrapped, handleType, fd, pMemoryFdProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeInt32Value(fd);
        EncodeStructPtr(encoder, pMemoryFdProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(TraceManager::Get(), result, device, handleType, fd, pMemoryFdProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice_unwrapped, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalSemaphoreInfo);
        EncodeStructPtr(encoder, pExternalSemaphoreProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkImportSemaphoreWin32HandleInfoKHR*  pImportSemaphoreWin32HandleInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(TraceManager::Get(), device, pImportSemaphoreWin32HandleInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreWin32HandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ImportSemaphoreWin32HandleKHR(device_unwrapped, pImportSemaphoreWin32HandleInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pImportSemaphoreWin32HandleInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(TraceManager::Get(), result, device, pImportSemaphoreWin32HandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkSemaphoreGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetSemaphoreWin32HandleKHR(device_unwrapped, pGetWin32HandleInfo_unwrapped, pHandle);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(
    VkDevice                                    device,
    const VkImportSemaphoreFdInfoKHR*           pImportSemaphoreFdInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(TraceManager::Get(), device, pImportSemaphoreFdInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreFdInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ImportSemaphoreFdKHR(device_unwrapped, pImportSemaphoreFdInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pImportSemaphoreFdInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(TraceManager::Get(), result, device, pImportSemaphoreFdInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(
    VkDevice                                    device,
    const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
    int*                                        pFd)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(TraceManager::Get(), device, pGetFdInfo, pFd);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetSemaphoreFdKHR(device_unwrapped, pGetFdInfo_unwrapped, pFd);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(TraceManager::Get(), result, device, pGetFdInfo, pFd);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleValue(layout);
        encoder->EncodeUInt32Value(set);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        EncodeStructArray(encoder, pDescriptorWrites, descriptorWriteCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdPushDescriptorSetKHRHandles, layout, descriptorWriteCount, pDescriptorWrites);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkPipelineLayout layout_unwrapped = GetWrappedHandle<VkPipelineLayout>(layout);
    const VkWriteDescriptorSet* pDescriptorWrites_unwrapped = UnwrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdPushDescriptorSetKHR(commandBuffer_unwrapped, pipelineBindPoint, layout_unwrapped, set, descriptorWriteCount, pDescriptorWrites_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateDescriptorUpdateTemplateKHR(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pDescriptorUpdateTemplate);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorUpdateTemplateWrapper>(device, NoParentWrapper::kHandleValue, pDescriptorUpdateTemplate, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDescriptorUpdateTemplate, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, DescriptorUpdateTemplateWrapper, VkDescriptorUpdateTemplateCreateInfo>(result, device, pDescriptorUpdateTemplate, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorUpdateTemplate descriptorUpdateTemplate_unwrapped = GetWrappedHandle<VkDescriptorUpdateTemplate>(descriptorUpdateTemplate);

    GetDeviceTable(device)->DestroyDescriptorUpdateTemplateKHR(device_unwrapped, descriptorUpdateTemplate_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    DestroyWrappedHandle<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateRenderPass2KHR(device_unwrapped, pCreateInfo, pAllocator, pRenderPass);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, RenderPassWrapper>(device, NoParentWrapper::kHandleValue, pRenderPass, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pRenderPass, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, RenderPassWrapper, VkRenderPassCreateInfo2>(result, device, pRenderPass, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderPassBegin);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginRenderPass2KHRHandles, pRenderPassBegin);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginRenderPass2KHR(commandBuffer_unwrapped, pRenderPassBegin_unwrapped, pSubpassBeginInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdNextSubpass2KHR(commandBuffer_unwrapped, pSubpassBeginInfo, pSubpassEndInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassEndInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndRenderPass2KHR(commandBuffer_unwrapped, pSubpassEndInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassEndInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(TraceManager::Get(), device, swapchain);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->GetSwapchainStatusKHR(device_unwrapped, swapchain_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(TraceManager::Get(), result, device, swapchain);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice_unwrapped, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalFenceInfo);
        EncodeStructPtr(encoder, pExternalFenceProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkImportFenceWin32HandleInfoKHR*      pImportFenceWin32HandleInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(TraceManager::Get(), device, pImportFenceWin32HandleInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pImportFenceWin32HandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ImportFenceWin32HandleKHR(device_unwrapped, pImportFenceWin32HandleInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pImportFenceWin32HandleInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(TraceManager::Get(), result, device, pImportFenceWin32HandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkFenceGetWin32HandleInfoKHR*         pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetFenceWin32HandleKHR(device_unwrapped, pGetWin32HandleInfo_unwrapped, pHandle);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(
    VkDevice                                    device,
    const VkImportFenceFdInfoKHR*               pImportFenceFdInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(TraceManager::Get(), device, pImportFenceFdInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImportFenceFdInfoKHR* pImportFenceFdInfo_unwrapped = UnwrapStructPtrHandles(pImportFenceFdInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ImportFenceFdKHR(device_unwrapped, pImportFenceFdInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pImportFenceFdInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(TraceManager::Get(), result, device, pImportFenceFdInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(
    VkDevice                                    device,
    const VkFenceGetFdInfoKHR*                  pGetFdInfo,
    int*                                        pFd)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(TraceManager::Get(), device, pGetFdInfo, pFd);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkFenceGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetFenceFdKHR(device_unwrapped, pGetFdInfo_unwrapped, pFd);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint32_t*                                   pCounterCount,
    VkPerformanceCounterKHR*                    pCounters,
    VkPerformanceCounterDescriptionKHR*         pCounterDescriptions)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(TraceManager::Get(), physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice_unwrapped, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeUInt32Ptr(pCounterCount, omit_output_data);
        EncodeStructArray(encoder, pCounters, (pCounterCount != nullptr) ? (*pCounterCount) : 0, omit_output_data);
        EncodeStructArray(encoder, pCounterDescriptions, (pCounterCount != nullptr) ? (*pCounterCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkQueryPoolPerformanceCreateInfoKHR*  pPerformanceQueryCreateInfo,
    uint32_t*                                   pNumPasses)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice_unwrapped, pPerformanceQueryCreateInfo, pNumPasses);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pPerformanceQueryCreateInfo);
        encoder->EncodeUInt32Ptr(pNumPasses);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireProfilingLockKHR(
    VkDevice                                    device,
    const VkAcquireProfilingLockInfoKHR*        pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(TraceManager::Get(), device, pInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->AcquireProfilingLockKHR(device_unwrapped, pInfo);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR(
    VkDevice                                    device)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(TraceManager::Get(), device);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->ReleaseProfilingLockKHR(device_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(TraceManager::Get(), device);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice_unwrapped, pSurfaceInfo_unwrapped, pSurfaceCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        EncodeStructPtr(encoder, pSurfaceCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(TraceManager::Get(), result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormat2KHR*                        pSurfaceFormats)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice_unwrapped, pSurfaceInfo_unwrapped, pSurfaceFormatCount, pSurfaceFormats);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount, omit_output_data);
        EncodeStructArray(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(TraceManager::Get(), result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayProperties2KHR*                    pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayProperties2KHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndStructGroupCreateApiCallTrace<VkPhysicalDevice, DisplayKHRWrapper, VkDisplayProperties2KHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayProperties2KHR* handle_struct)->DisplayKHRWrapper* { return reinterpret_cast<DisplayKHRWrapper*>(handle_struct->displayProperties.display); }, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlaneProperties2KHR*               pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayPlaneProperties2KHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndStructGroupCreateApiCallTrace<VkPhysicalDevice, DisplayKHRWrapper, VkDisplayPlaneProperties2KHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayPlaneProperties2KHR* handle_struct)->DisplayKHRWrapper* { return reinterpret_cast<DisplayKHRWrapper*>(handle_struct->displayPlaneProperties.currentDisplay); }, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModeProperties2KHR*                pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->GetDisplayModeProperties2KHR(physicalDevice_unwrapped, display_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, DisplayKHRWrapper, VkDisplayModeProperties2KHR>(physicalDevice, display, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndStructGroupCreateApiCallTrace<VkPhysicalDevice, DisplayModeKHRWrapper, VkDisplayModeProperties2KHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayModeProperties2KHR* handle_struct)->DisplayModeKHRWrapper* { return reinterpret_cast<DisplayModeKHRWrapper*>(handle_struct->displayModeProperties.displayMode); }, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(TraceManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
    VkDisplayPlaneCapabilities2KHR*             pCapabilities)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pDisplayPlaneInfo, pCapabilities);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo_unwrapped = UnwrapStructPtrHandles(pDisplayPlaneInfo, handle_unwrap_memory);

    VkResult result = GetInstanceTable(physicalDevice)->GetDisplayPlaneCapabilities2KHR(physicalDevice_unwrapped, pDisplayPlaneInfo_unwrapped, pCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pDisplayPlaneInfo);
        EncodeStructPtr(encoder, pCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(TraceManager::Get(), result, physicalDevice, pDisplayPlaneInfo, pCapabilities);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetImageMemoryRequirements2KHR(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetBufferMemoryRequirements2KHR(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageSparseMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetImageSparseMemoryRequirements2KHR(device_unwrapped, pInfo_unwrapped, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversionKHR(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateSamplerYcbcrConversionKHR(device_unwrapped, pCreateInfo, pAllocator, pYcbcrConversion);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SamplerYcbcrConversionWrapper>(device, NoParentWrapper::kHandleValue, pYcbcrConversion, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pYcbcrConversion, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, SamplerYcbcrConversionWrapper, VkSamplerYcbcrConversionCreateInfo>(result, device, pYcbcrConversion, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(TraceManager::Get(), device, ycbcrConversion, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(ycbcrConversion);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SamplerYcbcrConversionWrapper>(ycbcrConversion, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSamplerYcbcrConversion ycbcrConversion_unwrapped = GetWrappedHandle<VkSamplerYcbcrConversion>(ycbcrConversion);

    GetDeviceTable(device)->DestroySamplerYcbcrConversionKHR(device_unwrapped, ycbcrConversion_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(TraceManager::Get(), device, ycbcrConversion, pAllocator);

    DestroyWrappedHandle<SamplerYcbcrConversionWrapper>(ycbcrConversion);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindBufferMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindBufferMemory2KHR(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindImageMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindImageMemory2KHR(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pSupport);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetDescriptorSetLayoutSupportKHR(device_unwrapped, pCreateInfo_unwrapped, pSupport);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pSupport);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pSupport);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndirectCountKHRHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndirectCountKHR(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndexedIndirectCountKHRHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirectCountKHR(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValueKHR(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    uint64_t*                                   pValue)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(TraceManager::Get(), device, semaphore, pValue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSemaphore semaphore_unwrapped = GetWrappedHandle<VkSemaphore>(semaphore);

    VkResult result = GetDeviceTable(device)->GetSemaphoreCounterValueKHR(device_unwrapped, semaphore_unwrapped, pValue);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(semaphore);
        encoder->EncodeUInt64Ptr(pValue, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(TraceManager::Get(), result, device, semaphore, pValue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphoresKHR(
    VkDevice                                    device,
    const VkSemaphoreWaitInfo*                  pWaitInfo,
    uint64_t                                    timeout)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(TraceManager::Get(), device, pWaitInfo, timeout);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreWaitInfo* pWaitInfo_unwrapped = UnwrapStructPtrHandles(pWaitInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->WaitSemaphoresKHR(device_unwrapped, pWaitInfo_unwrapped, timeout);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkWaitSemaphoresKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pWaitInfo);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(TraceManager::Get(), result, device, pWaitInfo, timeout);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphoreKHR(
    VkDevice                                    device,
    const VkSemaphoreSignalInfo*                pSignalInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(TraceManager::Get(), device, pSignalInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreSignalInfo* pSignalInfo_unwrapped = UnwrapStructPtrHandles(pSignalInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->SignalSemaphoreKHR(device_unwrapped, pSignalInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSignalSemaphoreKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pSignalInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(TraceManager::Get(), result, device, pSignalInfo);

    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressKHR(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkDeviceAddress result = GetDeviceTable(device)->GetBufferDeviceAddressKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVkDeviceAddressValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddressKHR(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    uint64_t result = GetDeviceTable(device)->GetBufferOpaqueCaptureAddressKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR(
    VkDevice                                    device,
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    uint64_t result = GetDeviceTable(device)->GetDeviceMemoryOpaqueCaptureAddressKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDeferredOperationKHR(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator,
    VkDeferredOperationKHR*                     pDeferredOperation)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(TraceManager::Get(), device, pAllocator, pDeferredOperation);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateDeferredOperationKHR(device_unwrapped, pAllocator, pDeferredOperation);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DeferredOperationKHRWrapper>(device, NoParentWrapper::kHandleValue, pDeferredOperation, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDeferredOperation, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, DeferredOperationKHRWrapper, void>(result, device, pDeferredOperation, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(TraceManager::Get(), result, device, pAllocator, pDeferredOperation);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(TraceManager::Get(), device, operation, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(operation);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DeferredOperationKHRWrapper>(operation, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR operation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(operation);

    GetDeviceTable(device)->DestroyDeferredOperationKHR(device_unwrapped, operation_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(TraceManager::Get(), device, operation, pAllocator);

    DestroyWrappedHandle<DeferredOperationKHRWrapper>(operation);
}

VKAPI_ATTR uint32_t VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(TraceManager::Get(), device, operation);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR operation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(operation);

    uint32_t result = GetDeviceTable(device)->GetDeferredOperationMaxConcurrencyKHR(device_unwrapped, operation_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(operation);
        encoder->EncodeUInt32Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(TraceManager::Get(), result, device, operation);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeferredOperationResultKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(TraceManager::Get(), device, operation);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR operation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(operation);

    VkResult result = GetDeviceTable(device)->GetDeferredOperationResultKHR(device_unwrapped, operation_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(operation);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(TraceManager::Get(), result, device, operation);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeferredOperationJoinKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(TraceManager::Get(), device, operation);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR operation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(operation);

    VkResult result = GetDeviceTable(device)->DeferredOperationJoinKHR(device_unwrapped, operation_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(operation);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(TraceManager::Get(), result, device, operation);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutablePropertiesKHR(
    VkDevice                                    device,
    const VkPipelineInfoKHR*                    pPipelineInfo,
    uint32_t*                                   pExecutableCount,
    VkPipelineExecutablePropertiesKHR*          pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(TraceManager::Get(), device, pPipelineInfo, pExecutableCount, pProperties);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkPipelineInfoKHR* pPipelineInfo_unwrapped = UnwrapStructPtrHandles(pPipelineInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetPipelineExecutablePropertiesKHR(device_unwrapped, pPipelineInfo_unwrapped, pExecutableCount, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pPipelineInfo);
        encoder->EncodeUInt32Ptr(pExecutableCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pExecutableCount != nullptr) ? (*pExecutableCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(TraceManager::Get(), result, device, pPipelineInfo, pExecutableCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableStatisticsKHR(
    VkDevice                                    device,
    const VkPipelineExecutableInfoKHR*          pExecutableInfo,
    uint32_t*                                   pStatisticCount,
    VkPipelineExecutableStatisticKHR*           pStatistics)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(TraceManager::Get(), device, pExecutableInfo, pStatisticCount, pStatistics);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkPipelineExecutableInfoKHR* pExecutableInfo_unwrapped = UnwrapStructPtrHandles(pExecutableInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetPipelineExecutableStatisticsKHR(device_unwrapped, pExecutableInfo_unwrapped, pStatisticCount, pStatistics);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pExecutableInfo);
        encoder->EncodeUInt32Ptr(pStatisticCount, omit_output_data);
        EncodeStructArray(encoder, pStatistics, (pStatisticCount != nullptr) ? (*pStatisticCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(TraceManager::Get(), result, device, pExecutableInfo, pStatisticCount, pStatistics);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR(
    VkDevice                                    device,
    const VkPipelineExecutableInfoKHR*          pExecutableInfo,
    uint32_t*                                   pInternalRepresentationCount,
    VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(TraceManager::Get(), device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkPipelineExecutableInfoKHR* pExecutableInfo_unwrapped = UnwrapStructPtrHandles(pExecutableInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetPipelineExecutableInternalRepresentationsKHR(device_unwrapped, pExecutableInfo_unwrapped, pInternalRepresentationCount, pInternalRepresentations);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pExecutableInfo);
        encoder->EncodeUInt32Ptr(pInternalRepresentationCount, omit_output_data);
        EncodeStructArray(encoder, pInternalRepresentations, (pInternalRepresentationCount != nullptr) ? (*pInternalRepresentationCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(TraceManager::Get(), result, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT(
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pCallback);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateDebugReportCallbackEXT(instance_unwrapped, pCreateInfo, pAllocator, pCallback);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, DebugReportCallbackEXTWrapper>(instance, NoParentWrapper::kHandleValue, pCallback, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pCallback, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, DebugReportCallbackEXTWrapper, VkDebugReportCallbackCreateInfoEXT>(result, instance, pCallback, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pCallback);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(TraceManager::Get(), instance, callback, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeHandleValue(callback);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DebugReportCallbackEXTWrapper>(callback, encoder);
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);
    VkDebugReportCallbackEXT callback_unwrapped = GetWrappedHandle<VkDebugReportCallbackEXT>(callback);

    GetInstanceTable(instance)->DestroyDebugReportCallbackEXT(instance_unwrapped, callback_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(TraceManager::Get(), instance, callback, pAllocator);

    DestroyWrappedHandle<DebugReportCallbackEXTWrapper>(callback);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(TraceManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugReportMessageEXT);
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
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    GetInstanceTable(instance)->DebugReportMessageEXT(instance_unwrapped, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(TraceManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectTagInfoEXT*        pTagInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(TraceManager::Get(), device, pTagInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->DebugMarkerSetObjectTagEXT(device_unwrapped, pTagInfo);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pTagInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(TraceManager::Get(), result, device, pTagInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectNameEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectNameInfoEXT*       pNameInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(TraceManager::Get(), device, pNameInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->DebugMarkerSetObjectNameEXT(device_unwrapped, pNameInfo);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pNameInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(TraceManager::Get(), result, device, pNameInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(TraceManager::Get(), commandBuffer, pMarkerInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer_unwrapped, pMarkerInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(TraceManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(TraceManager::Get(), commandBuffer);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(TraceManager::Get(), commandBuffer, pMarkerInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer_unwrapped, pMarkerInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(TraceManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pSizes, bindingCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindTransformFeedbackBuffersEXTHandles, bindingCount, pBuffers);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pBuffers_unwrapped = UnwrapHandles<VkBuffer>(pBuffers, bindingCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBindTransformFeedbackBuffersEXT(commandBuffer_unwrapped, firstBinding, bindingCount, pBuffers_unwrapped, pOffsets, pSizes);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(TraceManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstCounterBuffer);
        encoder->EncodeUInt32Value(counterBufferCount);
        encoder->EncodeHandleArray(pCounterBuffers, counterBufferCount);
        encoder->EncodeVkDeviceSizeArray(pCounterBufferOffsets, counterBufferCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginTransformFeedbackEXTHandles, counterBufferCount, pCounterBuffers);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pCounterBuffers_unwrapped = UnwrapHandles<VkBuffer>(pCounterBuffers, counterBufferCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginTransformFeedbackEXT(commandBuffer_unwrapped, firstCounterBuffer, counterBufferCount, pCounterBuffers_unwrapped, pCounterBufferOffsets);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(TraceManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(TraceManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstCounterBuffer);
        encoder->EncodeUInt32Value(counterBufferCount);
        encoder->EncodeHandleArray(pCounterBuffers, counterBufferCount);
        encoder->EncodeVkDeviceSizeArray(pCounterBufferOffsets, counterBufferCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdEndTransformFeedbackEXTHandles, counterBufferCount, pCounterBuffers);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pCounterBuffers_unwrapped = UnwrapHandles<VkBuffer>(pCounterBuffers, counterBufferCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdEndTransformFeedbackEXT(commandBuffer_unwrapped, firstCounterBuffer, counterBufferCount, pCounterBuffers_unwrapped, pCounterBufferOffsets);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(TraceManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, query, flags, index);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeUInt32Value(index);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginQueryIndexedEXTHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdBeginQueryIndexedEXT(commandBuffer_unwrapped, queryPool_unwrapped, query, flags, index);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, query, flags, index);
}

VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, query, index);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeUInt32Value(index);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdEndQueryIndexedEXTHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdEndQueryIndexedEXT(commandBuffer_unwrapped, queryPool_unwrapped, query, index);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(TraceManager::Get(), commandBuffer, queryPool, query, index);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(TraceManager::Get(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstInstance);
        encoder->EncodeHandleValue(counterBuffer);
        encoder->EncodeVkDeviceSizeValue(counterBufferOffset);
        encoder->EncodeUInt32Value(counterOffset);
        encoder->EncodeUInt32Value(vertexStride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndirectByteCountEXTHandles, counterBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer counterBuffer_unwrapped = GetWrappedHandle<VkBuffer>(counterBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndirectByteCountEXT(commandBuffer_unwrapped, instanceCount, firstInstance, counterBuffer_unwrapped, counterBufferOffset, counterOffset, vertexStride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(TraceManager::Get(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

VKAPI_ATTR uint32_t VKAPI_CALL GetImageViewHandleNVX(
    VkDevice                                    device,
    const VkImageViewHandleInfoNVX*             pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageViewHandleInfoNVX* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    uint32_t result = GetDeviceTable(device)->GetImageViewHandleNVX(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageViewHandleNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetImageViewAddressNVX(
    VkDevice                                    device,
    VkImageView                                 imageView,
    VkImageViewAddressPropertiesNVX*            pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(TraceManager::Get(), device, imageView, pProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImageView imageView_unwrapped = GetWrappedHandle<VkImageView>(imageView);

    VkResult result = GetDeviceTable(device)->GetImageViewAddressNVX(device_unwrapped, imageView_unwrapped, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageViewAddressNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(imageView);
        EncodeStructPtr(encoder, pProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(TraceManager::Get(), result, device, imageView, pProperties);

    return result;
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndirectCountAMDHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndirectCountAMD(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndexedIndirectCountAMDHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirectCountAMD(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL GetShaderInfoAMD(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    size_t*                                     pInfoSize,
    void*                                       pInfo)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(TraceManager::Get(), device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkResult result = GetDeviceTable(device)->GetShaderInfoAMD(device_unwrapped, pipeline_unwrapped, shaderStage, infoType, pInfoSize, pInfo);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetShaderInfoAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeEnumValue(shaderStage);
        encoder->EncodeEnumValue(infoType);
        encoder->EncodeSizeTPtr(pInfoSize, omit_output_data);
        encoder->EncodeVoidArray(pInfo, (pInfoSize != nullptr) ? (*pInfoSize) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(TraceManager::Get(), result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateStreamDescriptorSurfaceGGP(
    VkInstance                                  instance,
    const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateStreamDescriptorSurfaceGGP(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkStreamDescriptorSurfaceCreateInfoGGP>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

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
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(TraceManager::Get(), physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice_unwrapped, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeFlagsValue(externalHandleType);
        EncodeStructPtr(encoder, pExternalImageFormatProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(TraceManager::Get(), result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleNV(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    HANDLE*                                     pHandle)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(TraceManager::Get(), device, memory, handleType, pHandle);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    VkResult result = GetDeviceTable(device)->GetMemoryWin32HandleNV(device_unwrapped, memory_unwrapped, handleType, pHandle);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeFlagsValue(handleType);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(TraceManager::Get(), result, device, memory, handleType, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateViSurfaceNN(
    VkInstance                                  instance,
    const VkViSurfaceCreateInfoNN*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateViSurfaceNN(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateViSurfaceNN);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkViSurfaceCreateInfoNN>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(TraceManager::Get(), commandBuffer, pConditionalRenderingBegin);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pConditionalRenderingBegin);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginConditionalRenderingEXTHandles, pConditionalRenderingBegin);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin_unwrapped = UnwrapStructPtrHandles(pConditionalRenderingBegin, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginConditionalRenderingEXT(commandBuffer_unwrapped, pConditionalRenderingBegin_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(TraceManager::Get(), commandBuffer, pConditionalRenderingBegin);
}

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(TraceManager::Get(), commandBuffer);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndConditionalRenderingEXT(commandBuffer_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewportWScalings, viewportCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewportWScalingNV(commandBuffer_unwrapped, firstViewport, viewportCount, pViewportWScalings);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(TraceManager::Get(), physicalDevice, display);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->ReleaseDisplayEXT(physicalDevice_unwrapped, display_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkReleaseDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(TraceManager::Get(), result, physicalDevice, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireXlibDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    VkDisplayKHR                                display)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(TraceManager::Get(), physicalDevice, dpy, display);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->AcquireXlibDisplayEXT(physicalDevice_unwrapped, dpy, display_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeHandleValue(display);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(TraceManager::Get(), result, physicalDevice, dpy, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRandROutputDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    RROutput                                    rrOutput,
    VkDisplayKHR*                               pDisplay)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(TraceManager::Get(), physicalDevice, dpy, rrOutput, pDisplay);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetRandROutputDisplayEXT(physicalDevice_unwrapped, dpy, rrOutput, pDisplay);

    if (result >= 0)
    {
        CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DisplayKHRWrapper>(physicalDevice, NoParentWrapper::kHandleValue, pDisplay, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeSizeTValue(rrOutput);
        encoder->EncodeHandlePtr(pDisplay, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkPhysicalDevice, DisplayKHRWrapper, void>(result, physicalDevice, pDisplay, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(TraceManager::Get(), result, physicalDevice, dpy, rrOutput, pDisplay);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilities2EXT*                  pSurfaceCapabilities)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(TraceManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice_unwrapped, surface_unwrapped, pSurfaceCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        EncodeStructPtr(encoder, pSurfaceCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(TraceManager::Get(), result, physicalDevice, surface, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayPowerInfoEXT*                pDisplayPowerInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(TraceManager::Get(), device, display, pDisplayPowerInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetDeviceTable(device)->DisplayPowerControlEXT(device_unwrapped, display_unwrapped, pDisplayPowerInfo);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDisplayPowerControlEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(display);
        EncodeStructPtr(encoder, pDisplayPowerInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(TraceManager::Get(), result, device, display, pDisplayPowerInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(
    VkDevice                                    device,
    const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(TraceManager::Get(), device, pDeviceEventInfo, pAllocator, pFence);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->RegisterDeviceEventEXT(device_unwrapped, pDeviceEventInfo, pAllocator, pFence);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, FenceWrapper>(device, NoParentWrapper::kHandleValue, pFence, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pDeviceEventInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFence, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, FenceWrapper, void>(result, device, pFence, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(TraceManager::Get(), result, device, pDeviceEventInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayEventInfoEXT*                pDisplayEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(TraceManager::Get(), device, display, pDisplayEventInfo, pAllocator, pFence);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetDeviceTable(device)->RegisterDisplayEventEXT(device_unwrapped, display_unwrapped, pDisplayEventInfo, pAllocator, pFence);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, DisplayKHRWrapper, FenceWrapper>(device, display, pFence, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(display);
        EncodeStructPtr(encoder, pDisplayEventInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFence, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, FenceWrapper, void>(result, device, pFence, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(TraceManager::Get(), result, device, display, pDisplayEventInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    uint64_t*                                   pCounterValue)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(TraceManager::Get(), device, swapchain, counter, pCounterValue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->GetSwapchainCounterEXT(device_unwrapped, swapchain_unwrapped, counter, pCounterValue);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeEnumValue(counter);
        encoder->EncodeUInt64Ptr(pCounterValue, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(TraceManager::Get(), result, device, swapchain, counter, pCounterValue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRefreshCycleDurationGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkRefreshCycleDurationGOOGLE*               pDisplayTimingProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(TraceManager::Get(), device, swapchain, pDisplayTimingProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->GetRefreshCycleDurationGOOGLE(device_unwrapped, swapchain_unwrapped, pDisplayTimingProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        EncodeStructPtr(encoder, pDisplayTimingProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(TraceManager::Get(), result, device, swapchain, pDisplayTimingProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPastPresentationTimingGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pPresentationTimingCount,
    VkPastPresentationTimingGOOGLE*             pPresentationTimings)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(TraceManager::Get(), device, swapchain, pPresentationTimingCount, pPresentationTimings);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->GetPastPresentationTimingGOOGLE(device_unwrapped, swapchain_unwrapped, pPresentationTimingCount, pPresentationTimings);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeUInt32Ptr(pPresentationTimingCount, omit_output_data);
        EncodeStructArray(encoder, pPresentationTimings, (pPresentationTimingCount != nullptr) ? (*pPresentationTimingCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(TraceManager::Get(), result, device, swapchain, pPresentationTimingCount, pPresentationTimings);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(TraceManager::Get(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstDiscardRectangle);
        encoder->EncodeUInt32Value(discardRectangleCount);
        EncodeStructArray(encoder, pDiscardRectangles, discardRectangleCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDiscardRectangleEXT(commandBuffer_unwrapped, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(TraceManager::Get(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainKHR*                       pSwapchains,
    const VkHdrMetadataEXT*                     pMetadata)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(TraceManager::Get(), device, swapchainCount, pSwapchains, pMetadata);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetHdrMetadataEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        encoder->EncodeHandleArray(pSwapchains, swapchainCount);
        EncodeStructArray(encoder, pMetadata, swapchainCount);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSwapchainKHR* pSwapchains_unwrapped = UnwrapHandles<VkSwapchainKHR>(pSwapchains, swapchainCount, handle_unwrap_memory);

    GetDeviceTable(device)->SetHdrMetadataEXT(device_unwrapped, swapchainCount, pSwapchains_unwrapped, pMetadata);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(TraceManager::Get(), device, swapchainCount, pSwapchains, pMetadata);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK(
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateIOSSurfaceMVK(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkIOSSurfaceCreateInfoMVK>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateMacOSSurfaceMVK(
    VkInstance                                  instance,
    const VkMacOSSurfaceCreateInfoMVK*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateMacOSSurfaceMVK(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkMacOSSurfaceCreateInfoMVK>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectNameInfoEXT*        pNameInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(TraceManager::Get(), device, pNameInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->SetDebugUtilsObjectNameEXT(device_unwrapped, pNameInfo);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pNameInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(TraceManager::Get(), result, device, pNameInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectTagInfoEXT*         pTagInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(TraceManager::Get(), device, pTagInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->SetDebugUtilsObjectTagEXT(device_unwrapped, pTagInfo);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pTagInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(TraceManager::Get(), result, device, pTagInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), queue, pLabelInfo);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        EncodeStructPtr(encoder, pLabelInfo);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    GetDeviceTable(queue)->QueueBeginDebugUtilsLabelEXT(queue_unwrapped, pLabelInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), queue);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    GetDeviceTable(queue)->QueueEndDebugUtilsLabelEXT(queue_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), queue);
}

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), queue, pLabelInfo);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        EncodeStructPtr(encoder, pLabelInfo);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    GetDeviceTable(queue)->QueueInsertDebugUtilsLabelEXT(queue_unwrapped, pLabelInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), commandBuffer, pLabelInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pLabelInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer_unwrapped, pLabelInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), commandBuffer);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), commandBuffer, pLabelInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pLabelInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer_unwrapped, pLabelInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pMessenger);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateDebugUtilsMessengerEXT(instance_unwrapped, pCreateInfo, pAllocator, pMessenger);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, DebugUtilsMessengerEXTWrapper>(instance, NoParentWrapper::kHandleValue, pMessenger, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pMessenger, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, DebugUtilsMessengerEXTWrapper, VkDebugUtilsMessengerCreateInfoEXT>(result, instance, pMessenger, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pMessenger);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(TraceManager::Get(), instance, messenger, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeHandleValue(messenger);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DebugUtilsMessengerEXTWrapper>(messenger, encoder);
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);
    VkDebugUtilsMessengerEXT messenger_unwrapped = GetWrappedHandle<VkDebugUtilsMessengerEXT>(messenger);

    GetInstanceTable(instance)->DestroyDebugUtilsMessengerEXT(instance_unwrapped, messenger_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(TraceManager::Get(), instance, messenger, pAllocator);

    DestroyWrappedHandle<DebugUtilsMessengerEXTWrapper>(messenger);
}

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(TraceManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeEnumValue(messageSeverity);
        encoder->EncodeFlagsValue(messageTypes);
        EncodeStructPtr(encoder, pCallbackData);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    GetInstanceTable(instance)->SubmitDebugUtilsMessageEXT(instance_unwrapped, messageSeverity, messageTypes, pCallbackData);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(TraceManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);
}

VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                    device,
    const struct AHardwareBuffer*               buffer,
    VkAndroidHardwareBufferPropertiesANDROID*   pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(TraceManager::Get(), device, buffer, pProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetAndroidHardwareBufferPropertiesANDROID(device_unwrapped, buffer, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeVoidPtr(buffer);
        EncodeStructPtr(encoder, pProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(TraceManager::Get(), result, device, buffer, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID(
    VkDevice                                    device,
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
    struct AHardwareBuffer**                    pBuffer)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(TraceManager::Get(), device, pInfo, pBuffer);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetMemoryAndroidHardwareBufferANDROID(device_unwrapped, pInfo_unwrapped, pBuffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVoidPtrPtr(pBuffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(TraceManager::Get(), result, device, pInfo, pBuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(TraceManager::Get(), commandBuffer, pSampleLocationsInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pSampleLocationsInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetSampleLocationsEXT(commandBuffer_unwrapped, pSampleLocationsInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(TraceManager::Get(), commandBuffer, pSampleLocationsInfo);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    VkMultisamplePropertiesEXT*                 pMultisampleProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(TraceManager::Get(), physicalDevice, samples, pMultisampleProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice_unwrapped, samples, pMultisampleProperties);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(samples);
        EncodeStructPtr(encoder, pMultisampleProperties);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(TraceManager::Get(), physicalDevice, samples, pMultisampleProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT(
    VkDevice                                    device,
    VkImage                                     image,
    VkImageDrmFormatModifierPropertiesEXT*      pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(TraceManager::Get(), device, image, pProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    VkResult result = GetDeviceTable(device)->GetImageDrmFormatModifierPropertiesEXT(device_unwrapped, image_unwrapped, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        EncodeStructPtr(encoder, pProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(TraceManager::Get(), result, device, image, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT(
    VkDevice                                    device,
    const VkValidationCacheCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkValidationCacheEXT*                       pValidationCache)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pValidationCache);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateValidationCacheEXT(device_unwrapped, pCreateInfo, pAllocator, pValidationCache);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ValidationCacheEXTWrapper>(device, NoParentWrapper::kHandleValue, pValidationCache, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateValidationCacheEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pValidationCache, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, ValidationCacheEXTWrapper, VkValidationCacheCreateInfoEXT>(result, device, pValidationCache, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pValidationCache);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(TraceManager::Get(), device, validationCache, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(validationCache);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<ValidationCacheEXTWrapper>(validationCache, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkValidationCacheEXT validationCache_unwrapped = GetWrappedHandle<VkValidationCacheEXT>(validationCache);

    GetDeviceTable(device)->DestroyValidationCacheEXT(device_unwrapped, validationCache_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(TraceManager::Get(), device, validationCache, pAllocator);

    DestroyWrappedHandle<ValidationCacheEXTWrapper>(validationCache);
}

VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const VkValidationCacheEXT*                 pSrcCaches)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(TraceManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkValidationCacheEXT dstCache_unwrapped = GetWrappedHandle<VkValidationCacheEXT>(dstCache);
    const VkValidationCacheEXT* pSrcCaches_unwrapped = UnwrapHandles<VkValidationCacheEXT>(pSrcCaches, srcCacheCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->MergeValidationCachesEXT(device_unwrapped, dstCache_unwrapped, srcCacheCount, pSrcCaches_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMergeValidationCachesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleArray(pSrcCaches, srcCacheCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(TraceManager::Get(), result, device, dstCache, srcCacheCount, pSrcCaches);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(TraceManager::Get(), device, validationCache, pDataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkValidationCacheEXT validationCache_unwrapped = GetWrappedHandle<VkValidationCacheEXT>(validationCache);

    VkResult result = GetDeviceTable(device)->GetValidationCacheDataEXT(device_unwrapped, validationCache_unwrapped, pDataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(validationCache);
        encoder->EncodeSizeTPtr(pDataSize, omit_output_data);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(TraceManager::Get(), result, device, validationCache, pDataSize, pData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(TraceManager::Get(), commandBuffer, imageView, imageLayout);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(imageView);
        encoder->EncodeEnumValue(imageLayout);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindShadingRateImageNVHandles, imageView);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImageView imageView_unwrapped = GetWrappedHandle<VkImageView>(imageView);

    GetDeviceTable(commandBuffer)->CmdBindShadingRateImageNV(commandBuffer_unwrapped, imageView_unwrapped, imageLayout);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(TraceManager::Get(), commandBuffer, imageView, imageLayout);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pShadingRatePalettes, viewportCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewportShadingRatePaletteNV(commandBuffer_unwrapped, firstViewport, viewportCount, pShadingRatePalettes);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV(
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(TraceManager::Get(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(sampleOrderType);
        encoder->EncodeUInt32Value(customSampleOrderCount);
        EncodeStructArray(encoder, pCustomSampleOrders, customSampleOrderCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCoarseSampleOrderNV(commandBuffer_unwrapped, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(TraceManager::Get(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureNV(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoNV*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureNV*                  pAccelerationStructure)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pAccelerationStructure);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAccelerationStructureCreateInfoNV* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateAccelerationStructureNV(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pAccelerationStructure);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, AccelerationStructureNVWrapper>(device, NoParentWrapper::kHandleValue, pAccelerationStructure, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pAccelerationStructure, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, AccelerationStructureNVWrapper, VkAccelerationStructureCreateInfoNV>(result, device, pAccelerationStructure, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR(
    VkDevice                                    device,
    VkAccelerationStructureKHR                  accelerationStructure,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(TraceManager::Get(), device, accelerationStructure, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(accelerationStructure);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<AccelerationStructureKHRWrapper>(accelerationStructure, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkAccelerationStructureKHR accelerationStructure_unwrapped = GetWrappedHandle<VkAccelerationStructureKHR>(accelerationStructure);

    GetDeviceTable(device)->DestroyAccelerationStructureKHR(device_unwrapped, accelerationStructure_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(TraceManager::Get(), device, accelerationStructure, pAllocator);

    DestroyWrappedHandle<AccelerationStructureKHRWrapper>(accelerationStructure);
}

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV(
    VkDevice                                    device,
    VkAccelerationStructureKHR                  accelerationStructure,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(TraceManager::Get(), device, accelerationStructure, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(accelerationStructure);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<AccelerationStructureKHRWrapper>(accelerationStructure, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkAccelerationStructureKHR accelerationStructure_unwrapped = GetWrappedHandle<VkAccelerationStructureKHR>(accelerationStructure);

    GetDeviceTable(device)->DestroyAccelerationStructureNV(device_unwrapped, accelerationStructure_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(TraceManager::Get(), device, accelerationStructure, pAllocator);

    DestroyWrappedHandle<AccelerationStructureKHRWrapper>(accelerationStructure);
}

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV(
    VkDevice                                    device,
    const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo,
    VkMemoryRequirements2KHR*                   pMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetAccelerationStructureMemoryRequirementsNV(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL BindAccelerationStructureMemoryKHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindAccelerationStructureMemoryInfoKHR* pBindInfos)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>::Dispatch(TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindAccelerationStructureMemoryInfoKHR* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindAccelerationStructureMemoryKHR(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR>::Dispatch(TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindAccelerationStructureMemoryNV(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindAccelerationStructureMemoryInfoKHR* pBindInfos)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindAccelerationStructureMemoryInfoKHR* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindAccelerationStructureMemoryNV(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureKHR                  dst,
    VkAccelerationStructureKHR                  src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(TraceManager::Get(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeHandleValue(instanceData);
        encoder->EncodeVkDeviceSizeValue(instanceOffset);
        encoder->EncodeVkBool32Value(update);
        encoder->EncodeHandleValue(dst);
        encoder->EncodeHandleValue(src);
        encoder->EncodeHandleValue(scratch);
        encoder->EncodeVkDeviceSizeValue(scratchOffset);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBuildAccelerationStructureNVHandles, pInfo, instanceData, dst, src, scratch);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkAccelerationStructureInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);
    VkBuffer instanceData_unwrapped = GetWrappedHandle<VkBuffer>(instanceData);
    VkAccelerationStructureKHR dst_unwrapped = GetWrappedHandle<VkAccelerationStructureKHR>(dst);
    VkAccelerationStructureKHR src_unwrapped = GetWrappedHandle<VkAccelerationStructureKHR>(src);
    VkBuffer scratch_unwrapped = GetWrappedHandle<VkBuffer>(scratch);

    GetDeviceTable(commandBuffer)->CmdBuildAccelerationStructureNV(commandBuffer_unwrapped, pInfo_unwrapped, instanceData_unwrapped, instanceOffset, update, dst_unwrapped, src_unwrapped, scratch_unwrapped, scratchOffset);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(TraceManager::Get(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureKHR                  dst,
    VkAccelerationStructureKHR                  src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(TraceManager::Get(), commandBuffer, dst, src, mode);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(dst);
        encoder->EncodeHandleValue(src);
        encoder->EncodeEnumValue(mode);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyAccelerationStructureNVHandles, dst, src);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkAccelerationStructureKHR dst_unwrapped = GetWrappedHandle<VkAccelerationStructureKHR>(dst);
    VkAccelerationStructureKHR src_unwrapped = GetWrappedHandle<VkAccelerationStructureKHR>(src);

    GetDeviceTable(commandBuffer)->CmdCopyAccelerationStructureNV(commandBuffer_unwrapped, dst_unwrapped, src_unwrapped, mode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(TraceManager::Get(), commandBuffer, dst, src, mode);
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    VkBuffer                                    missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    VkBuffer                                    hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    VkBuffer                                    callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(TraceManager::Get(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdTraceRaysNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(raygenShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(raygenShaderBindingOffset);
        encoder->EncodeHandleValue(missShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(missShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(missShaderBindingStride);
        encoder->EncodeHandleValue(hitShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(hitShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(hitShaderBindingStride);
        encoder->EncodeHandleValue(callableShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(callableShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(callableShaderBindingStride);
        encoder->EncodeUInt32Value(width);
        encoder->EncodeUInt32Value(height);
        encoder->EncodeUInt32Value(depth);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdTraceRaysNVHandles, raygenShaderBindingTableBuffer, missShaderBindingTableBuffer, hitShaderBindingTableBuffer, callableShaderBindingTableBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer raygenShaderBindingTableBuffer_unwrapped = GetWrappedHandle<VkBuffer>(raygenShaderBindingTableBuffer);
    VkBuffer missShaderBindingTableBuffer_unwrapped = GetWrappedHandle<VkBuffer>(missShaderBindingTableBuffer);
    VkBuffer hitShaderBindingTableBuffer_unwrapped = GetWrappedHandle<VkBuffer>(hitShaderBindingTableBuffer);
    VkBuffer callableShaderBindingTableBuffer_unwrapped = GetWrappedHandle<VkBuffer>(callableShaderBindingTableBuffer);

    GetDeviceTable(commandBuffer)->CmdTraceRaysNV(commandBuffer_unwrapped, raygenShaderBindingTableBuffer_unwrapped, raygenShaderBindingOffset, missShaderBindingTableBuffer_unwrapped, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer_unwrapped, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer_unwrapped, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(TraceManager::Get(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesNV(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkRayTracingPipelineCreateInfoNV*     pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);
    const VkRayTracingPipelineCreateInfoNV* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateRayTracingPipelinesNV(device_unwrapped, pipelineCache_unwrapped, createInfoCount, pCreateInfos_unwrapped, pAllocator, pPipelines);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, PipelineCacheWrapper, PipelineWrapper>(device, pipelineCache, pPipelines, createInfoCount, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleArray(pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndGroupCreateApiCallTrace<VkDevice, VkPipelineCache, PipelineWrapper, VkRayTracingPipelineCreateInfoNV>(result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesKHR(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(TraceManager::Get(), device, pipeline, firstGroup, groupCount, dataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkResult result = GetDeviceTable(device)->GetRayTracingShaderGroupHandlesKHR(device_unwrapped, pipeline_unwrapped, firstGroup, groupCount, dataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(firstGroup);
        encoder->EncodeUInt32Value(groupCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(TraceManager::Get(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesNV(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(TraceManager::Get(), device, pipeline, firstGroup, groupCount, dataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkResult result = GetDeviceTable(device)->GetRayTracingShaderGroupHandlesNV(device_unwrapped, pipeline_unwrapped, firstGroup, groupCount, dataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(firstGroup);
        encoder->EncodeUInt32Value(groupCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(TraceManager::Get(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetAccelerationStructureHandleNV(
    VkDevice                                    device,
    VkAccelerationStructureKHR                  accelerationStructure,
    size_t                                      dataSize,
    void*                                       pData)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(TraceManager::Get(), device, accelerationStructure, dataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkAccelerationStructureKHR accelerationStructure_unwrapped = GetWrappedHandle<VkAccelerationStructureKHR>(accelerationStructure);

    VkResult result = GetDeviceTable(device)->GetAccelerationStructureHandleNV(device_unwrapped, accelerationStructure_unwrapped, dataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(accelerationStructure);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(TraceManager::Get(), result, device, accelerationStructure, dataSize, pData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(TraceManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(accelerationStructureCount);
        encoder->EncodeHandleArray(pAccelerationStructures, accelerationStructureCount);
        encoder->EncodeEnumValue(queryType);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdWriteAccelerationStructuresPropertiesKHRHandles, accelerationStructureCount, pAccelerationStructures, queryPool);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkAccelerationStructureKHR* pAccelerationStructures_unwrapped = UnwrapHandles<VkAccelerationStructureKHR>(pAccelerationStructures, accelerationStructureCount, handle_unwrap_memory);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdWriteAccelerationStructuresPropertiesKHR(commandBuffer_unwrapped, accelerationStructureCount, pAccelerationStructures_unwrapped, queryType, queryPool_unwrapped, firstQuery);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(TraceManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(TraceManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(accelerationStructureCount);
        encoder->EncodeHandleArray(pAccelerationStructures, accelerationStructureCount);
        encoder->EncodeEnumValue(queryType);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdWriteAccelerationStructuresPropertiesNVHandles, accelerationStructureCount, pAccelerationStructures, queryPool);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkAccelerationStructureKHR* pAccelerationStructures_unwrapped = UnwrapHandles<VkAccelerationStructureKHR>(pAccelerationStructures, accelerationStructureCount, handle_unwrap_memory);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(commandBuffer_unwrapped, accelerationStructureCount, pAccelerationStructures_unwrapped, queryType, queryPool_unwrapped, firstQuery);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(TraceManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

VKAPI_ATTR VkResult VKAPI_CALL CompileDeferredNV(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    shader)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(TraceManager::Get(), device, pipeline, shader);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkResult result = GetDeviceTable(device)->CompileDeferredNV(device_unwrapped, pipeline_unwrapped, shader);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCompileDeferredNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(shader);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(TraceManager::Get(), result, device, pipeline, shader);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    const void*                                 pHostPointer,
    VkMemoryHostPointerPropertiesEXT*           pMemoryHostPointerProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(TraceManager::Get(), device, handleType, pHostPointer, pMemoryHostPointerProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetMemoryHostPointerPropertiesEXT(device_unwrapped, handleType, pHostPointer, pMemoryHostPointerProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(pHostPointer);
        EncodeStructPtr(encoder, pMemoryHostPointerProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(TraceManager::Get(), result, device, handleType, pHostPointer, pMemoryHostPointerProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(TraceManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeUInt32Value(marker);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdWriteBufferMarkerAMDHandles, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdWriteBufferMarkerAMD(commandBuffer_unwrapped, pipelineStage, dstBuffer_unwrapped, dstOffset, marker);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(TraceManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pTimeDomainCount,
    VkTimeDomainEXT*                            pTimeDomains)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(TraceManager::Get(), physicalDevice, pTimeDomainCount, pTimeDomains);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice_unwrapped, pTimeDomainCount, pTimeDomains);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pTimeDomainCount, omit_output_data);
        encoder->EncodeEnumArray(pTimeDomains, (pTimeDomainCount != nullptr) ? (*pTimeDomainCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(TraceManager::Get(), result, physicalDevice, pTimeDomainCount, pTimeDomains);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsEXT(
    VkDevice                                    device,
    uint32_t                                    timestampCount,
    const VkCalibratedTimestampInfoEXT*         pTimestampInfos,
    uint64_t*                                   pTimestamps,
    uint64_t*                                   pMaxDeviation)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(TraceManager::Get(), device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetCalibratedTimestampsEXT(device_unwrapped, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(timestampCount);
        EncodeStructArray(encoder, pTimestampInfos, timestampCount);
        encoder->EncodeUInt64Array(pTimestamps, timestampCount, omit_output_data);
        encoder->EncodeUInt64Ptr(pMaxDeviation, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(TraceManager::Get(), result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(TraceManager::Get(), commandBuffer, taskCount, firstTask);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(taskCount);
        encoder->EncodeUInt32Value(firstTask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawMeshTasksNV(commandBuffer_unwrapped, taskCount, firstTask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(TraceManager::Get(), commandBuffer, taskCount, firstTask);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawMeshTasksIndirectNVHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdDrawMeshTasksIndirectNV(commandBuffer_unwrapped, buffer_unwrapped, offset, drawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawMeshTasksIndirectCountNVHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawMeshTasksIndirectCountNV(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(TraceManager::Get(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstExclusiveScissor);
        encoder->EncodeUInt32Value(exclusiveScissorCount);
        EncodeStructArray(encoder, pExclusiveScissors, exclusiveScissorCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetExclusiveScissorNV(commandBuffer_unwrapped, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(TraceManager::Get(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV(
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(TraceManager::Get(), commandBuffer, pCheckpointMarker);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetCheckpointNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVoidPtr(pCheckpointMarker);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCheckpointNV(commandBuffer_unwrapped, pCheckpointMarker);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(TraceManager::Get(), commandBuffer, pCheckpointMarker);
}

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV(
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointDataNV*                         pCheckpointData)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(TraceManager::Get(), queue, pCheckpointDataCount, pCheckpointData);

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    GetDeviceTable(queue)->GetQueueCheckpointDataNV(queue_unwrapped, pCheckpointDataCount, pCheckpointData);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Ptr(pCheckpointDataCount);
        EncodeStructArray(encoder, pCheckpointData, (pCheckpointDataCount != nullptr) ? (*pCheckpointDataCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(TraceManager::Get(), queue, pCheckpointDataCount, pCheckpointData);
}

VKAPI_ATTR VkResult VKAPI_CALL InitializePerformanceApiINTEL(
    VkDevice                                    device,
    const VkInitializePerformanceApiInfoINTEL*  pInitializeInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(TraceManager::Get(), device, pInitializeInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->InitializePerformanceApiINTEL(device_unwrapped, pInitializeInfo);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInitializeInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(TraceManager::Get(), result, device, pInitializeInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL(
    VkDevice                                    device)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(TraceManager::Get(), device);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->UninitializePerformanceApiINTEL(device_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(TraceManager::Get(), device);
}

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(TraceManager::Get(), commandBuffer, pMarkerInfo);

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    VkResult result = GetDeviceTable(commandBuffer)->CmdSetPerformanceMarkerINTEL(commandBuffer_unwrapped, pMarkerInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(TraceManager::Get(), result, commandBuffer, pMarkerInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(TraceManager::Get(), commandBuffer, pMarkerInfo);

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    VkResult result = GetDeviceTable(commandBuffer)->CmdSetPerformanceStreamMarkerINTEL(commandBuffer_unwrapped, pMarkerInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(TraceManager::Get(), result, commandBuffer, pMarkerInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceOverrideINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(TraceManager::Get(), commandBuffer, pOverrideInfo);

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    VkResult result = GetDeviceTable(commandBuffer)->CmdSetPerformanceOverrideINTEL(commandBuffer_unwrapped, pOverrideInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pOverrideInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(TraceManager::Get(), result, commandBuffer, pOverrideInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquirePerformanceConfigurationINTEL(
    VkDevice                                    device,
    const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
    VkPerformanceConfigurationINTEL*            pConfiguration)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(TraceManager::Get(), device, pAcquireInfo, pConfiguration);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->AcquirePerformanceConfigurationINTEL(device_unwrapped, pAcquireInfo, pConfiguration);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PerformanceConfigurationINTELWrapper>(device, NoParentWrapper::kHandleValue, pConfiguration, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAcquireInfo);
        encoder->EncodeHandlePtr(pConfiguration, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, PerformanceConfigurationINTELWrapper, void>(result, device, pConfiguration, nullptr, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(TraceManager::Get(), result, device, pAcquireInfo, pConfiguration);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ReleasePerformanceConfigurationINTEL(
    VkDevice                                    device,
    VkPerformanceConfigurationINTEL             configuration)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(TraceManager::Get(), device, configuration);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPerformanceConfigurationINTEL configuration_unwrapped = GetWrappedHandle<VkPerformanceConfigurationINTEL>(configuration);

    VkResult result = GetDeviceTable(device)->ReleasePerformanceConfigurationINTEL(device_unwrapped, configuration_unwrapped);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(configuration);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndDestroyApiCallTrace<PerformanceConfigurationINTELWrapper>(configuration, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(TraceManager::Get(), result, device, configuration);

    DestroyWrappedHandle<PerformanceConfigurationINTELWrapper>(configuration);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSetPerformanceConfigurationINTEL(
    VkQueue                                     queue,
    VkPerformanceConfigurationINTEL             configuration)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(TraceManager::Get(), queue, configuration);

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);
    VkPerformanceConfigurationINTEL configuration_unwrapped = GetWrappedHandle<VkPerformanceConfigurationINTEL>(configuration);

    VkResult result = GetDeviceTable(queue)->QueueSetPerformanceConfigurationINTEL(queue_unwrapped, configuration_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeHandleValue(configuration);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(TraceManager::Get(), result, queue, configuration);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPerformanceParameterINTEL(
    VkDevice                                    device,
    VkPerformanceParameterTypeINTEL             parameter,
    VkPerformanceValueINTEL*                    pValue)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(TraceManager::Get(), device, parameter, pValue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetPerformanceParameterINTEL(device_unwrapped, parameter, pValue);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(parameter);
        EncodeStructPtr(encoder, pValue, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(TraceManager::Get(), result, device, parameter, pValue);

    return result;
}

VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD(
    VkDevice                                    device,
    VkSwapchainKHR                              swapChain,
    VkBool32                                    localDimmingEnable)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(TraceManager::Get(), device, swapChain, localDimmingEnable);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetLocalDimmingAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapChain);
        encoder->EncodeVkBool32Value(localDimmingEnable);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapChain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapChain);

    GetDeviceTable(device)->SetLocalDimmingAMD(device_unwrapped, swapChain_unwrapped, localDimmingEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(TraceManager::Get(), device, swapChain, localDimmingEnable);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImagePipeSurfaceFUCHSIA(
    VkInstance                                  instance,
    const VkImagePipeSurfaceCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateImagePipeSurfaceFUCHSIA(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkImagePipeSurfaceCreateInfoFUCHSIA>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateMetalSurfaceEXT(
    VkInstance                                  instance,
    const VkMetalSurfaceCreateInfoEXT*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateMetalSurfaceEXT(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkMetalSurfaceCreateInfoEXT>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressEXT(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkDeviceAddress result = GetDeviceTable(device)->GetBufferDeviceAddressEXT(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVkDeviceAddressValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pToolCount,
    VkPhysicalDeviceToolPropertiesEXT*          pToolProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(TraceManager::Get(), physicalDevice, pToolCount, pToolProperties);

    VkResult result = TraceManager::Get()->OverrideGetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pToolCount, omit_output_data);
        EncodeStructArray(encoder, pToolProperties, (pToolCount != nullptr) ? (*pToolCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(TraceManager::Get(), result, physicalDevice, pToolCount, pToolProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkCooperativeMatrixPropertiesNV*            pProperties)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice_unwrapped, pPropertyCount, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pCombinationCount,
    VkFramebufferMixedSamplesCombinationNV*     pCombinations)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(TraceManager::Get(), physicalDevice, pCombinationCount, pCombinations);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice_unwrapped, pCombinationCount, pCombinations);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pCombinationCount, omit_output_data);
        EncodeStructArray(encoder, pCombinations, (pCombinationCount != nullptr) ? (*pCombinationCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(TraceManager::Get(), result, physicalDevice, pCombinationCount, pCombinations);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(TraceManager::Get(), physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice_unwrapped, pSurfaceInfo_unwrapped, pPresentModeCount, pPresentModes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        encoder->EncodeUInt32Ptr(pPresentModeCount, omit_output_data);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(TraceManager::Get(), result, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireFullScreenExclusiveModeEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(TraceManager::Get(), device, swapchain);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->AcquireFullScreenExclusiveModeEXT(device_unwrapped, swapchain_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(TraceManager::Get(), result, device, swapchain);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseFullScreenExclusiveModeEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(TraceManager::Get(), device, swapchain);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->ReleaseFullScreenExclusiveModeEXT(device_unwrapped, swapchain_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(TraceManager::Get(), result, device, swapchain);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT(
    VkDevice                                    device,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkDeviceGroupPresentModeFlagsKHR*           pModes)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(TraceManager::Get(), device, pSurfaceInfo, pModes);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetDeviceGroupSurfacePresentModes2EXT(device_unwrapped, pSurfaceInfo_unwrapped, pModes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pSurfaceInfo);
        encoder->EncodeFlagsPtr(pModes, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(TraceManager::Get(), result, device, pSurfaceInfo, pModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateHeadlessSurfaceEXT(
    VkInstance                                  instance,
    const VkHeadlessSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateHeadlessSurfaceEXT(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkHeadlessSurfaceCreateInfoEXT>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(TraceManager::Get(), commandBuffer, lineStippleFactor, lineStipplePattern);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(lineStippleFactor);
        encoder->EncodeUInt16Value(lineStipplePattern);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetLineStippleEXT(commandBuffer_unwrapped, lineStippleFactor, lineStipplePattern);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(TraceManager::Get(), commandBuffer, lineStippleFactor, lineStipplePattern);
}

VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(TraceManager::Get(), device, queryPool, firstQuery, queryCount);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetQueryPoolEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(device)->ResetQueryPoolEXT(device_unwrapped, queryPool_unwrapped, firstQuery, queryCount);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(TraceManager::Get(), device, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(TraceManager::Get(), commandBuffer, cullMode);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetCullModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(cullMode);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCullModeEXT(commandBuffer_unwrapped, cullMode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(TraceManager::Get(), commandBuffer, cullMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(TraceManager::Get(), commandBuffer, frontFace);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(frontFace);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetFrontFaceEXT(commandBuffer_unwrapped, frontFace);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(TraceManager::Get(), commandBuffer, frontFace);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(TraceManager::Get(), commandBuffer, primitiveTopology);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(primitiveTopology);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetPrimitiveTopologyEXT(commandBuffer_unwrapped, primitiveTopology);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(TraceManager::Get(), commandBuffer, primitiveTopology);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(TraceManager::Get(), commandBuffer, viewportCount, pViewports);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewports, viewportCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewportWithCountEXT(commandBuffer_unwrapped, viewportCount, pViewports);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(TraceManager::Get(), commandBuffer, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(TraceManager::Get(), commandBuffer, scissorCount, pScissors);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(scissorCount);
        EncodeStructArray(encoder, pScissors, scissorCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetScissorWithCountEXT(commandBuffer_unwrapped, scissorCount, pScissors);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(TraceManager::Get(), commandBuffer, scissorCount, pScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2EXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pSizes, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pStrides, bindingCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindVertexBuffers2EXTHandles, bindingCount, pBuffers);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pBuffers_unwrapped = UnwrapHandles<VkBuffer>(pBuffers, bindingCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBindVertexBuffers2EXT(commandBuffer_unwrapped, firstBinding, bindingCount, pBuffers_unwrapped, pOffsets, pSizes, pStrides);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(TraceManager::Get(), commandBuffer, depthTestEnable);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthTestEnable);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthTestEnableEXT(commandBuffer_unwrapped, depthTestEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(TraceManager::Get(), commandBuffer, depthTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(TraceManager::Get(), commandBuffer, depthWriteEnable);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthWriteEnable);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthWriteEnableEXT(commandBuffer_unwrapped, depthWriteEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(TraceManager::Get(), commandBuffer, depthWriteEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(TraceManager::Get(), commandBuffer, depthCompareOp);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(depthCompareOp);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthCompareOpEXT(commandBuffer_unwrapped, depthCompareOp);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(TraceManager::Get(), commandBuffer, depthCompareOp);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(TraceManager::Get(), commandBuffer, depthBoundsTestEnable);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthBoundsTestEnable);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthBoundsTestEnableEXT(commandBuffer_unwrapped, depthBoundsTestEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(TraceManager::Get(), commandBuffer, depthBoundsTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(TraceManager::Get(), commandBuffer, stencilTestEnable);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(stencilTestEnable);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilTestEnableEXT(commandBuffer_unwrapped, stencilTestEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(TraceManager::Get(), commandBuffer, stencilTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(TraceManager::Get(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeEnumValue(failOp);
        encoder->EncodeEnumValue(passOp);
        encoder->EncodeEnumValue(depthFailOp);
        encoder->EncodeEnumValue(compareOp);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilOpEXT(commandBuffer_unwrapped, faceMask, failOp, passOp, depthFailOp, compareOp);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(TraceManager::Get(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV(
    VkDevice                                    device,
    const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetGeneratedCommandsMemoryRequirementsNV(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL CmdPreprocessGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(TraceManager::Get(), commandBuffer, pGeneratedCommandsInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pGeneratedCommandsInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdPreprocessGeneratedCommandsNVHandles, pGeneratedCommandsInfo);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo_unwrapped = UnwrapStructPtrHandles(pGeneratedCommandsInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdPreprocessGeneratedCommandsNV(commandBuffer_unwrapped, pGeneratedCommandsInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(TraceManager::Get(), commandBuffer, pGeneratedCommandsInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(TraceManager::Get(), commandBuffer, isPreprocessed, pGeneratedCommandsInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(isPreprocessed);
        EncodeStructPtr(encoder, pGeneratedCommandsInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdExecuteGeneratedCommandsNVHandles, pGeneratedCommandsInfo);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo_unwrapped = UnwrapStructPtrHandles(pGeneratedCommandsInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdExecuteGeneratedCommandsNV(commandBuffer_unwrapped, isPreprocessed, pGeneratedCommandsInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(TraceManager::Get(), commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(TraceManager::Get(), commandBuffer, pipelineBindPoint, pipeline, groupIndex);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(groupIndex);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindPipelineShaderGroupNVHandles, pipeline);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    GetDeviceTable(commandBuffer)->CmdBindPipelineShaderGroupNV(commandBuffer_unwrapped, pipelineBindPoint, pipeline_unwrapped, groupIndex);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(TraceManager::Get(), commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNV(
    VkDevice                                    device,
    const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkIndirectCommandsLayoutNV*                 pIndirectCommandsLayout)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateIndirectCommandsLayoutNV(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pIndirectCommandsLayout);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, IndirectCommandsLayoutNVWrapper>(device, NoParentWrapper::kHandleValue, pIndirectCommandsLayout, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pIndirectCommandsLayout, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, IndirectCommandsLayoutNVWrapper, VkIndirectCommandsLayoutCreateInfoNV>(result, device, pIndirectCommandsLayout, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNV                  indirectCommandsLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(TraceManager::Get(), device, indirectCommandsLayout, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(indirectCommandsLayout);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<IndirectCommandsLayoutNVWrapper>(indirectCommandsLayout, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkIndirectCommandsLayoutNV indirectCommandsLayout_unwrapped = GetWrappedHandle<VkIndirectCommandsLayoutNV>(indirectCommandsLayout);

    GetDeviceTable(device)->DestroyIndirectCommandsLayoutNV(device_unwrapped, indirectCommandsLayout_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(TraceManager::Get(), device, indirectCommandsLayout, pAllocator);

    DestroyWrappedHandle<IndirectCommandsLayoutNVWrapper>(indirectCommandsLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlotEXT(
    VkDevice                                    device,
    const VkPrivateDataSlotCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPrivateDataSlotEXT*                       pPrivateDataSlot)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pPrivateDataSlot);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreatePrivateDataSlotEXT(device_unwrapped, pCreateInfo, pAllocator, pPrivateDataSlot);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PrivateDataSlotEXTWrapper>(device, NoParentWrapper::kHandleValue, pPrivateDataSlot, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pPrivateDataSlot, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, PrivateDataSlotEXTWrapper, VkPrivateDataSlotCreateInfoEXT>(result, device, pPrivateDataSlot, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pPrivateDataSlot);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT(
    VkDevice                                    device,
    VkPrivateDataSlotEXT                        privateDataSlot,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(TraceManager::Get(), device, privateDataSlot, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(privateDataSlot);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<PrivateDataSlotEXTWrapper>(privateDataSlot, encoder);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPrivateDataSlotEXT privateDataSlot_unwrapped = GetWrappedHandle<VkPrivateDataSlotEXT>(privateDataSlot);

    GetDeviceTable(device)->DestroyPrivateDataSlotEXT(device_unwrapped, privateDataSlot_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(TraceManager::Get(), device, privateDataSlot, pAllocator);

    DestroyWrappedHandle<PrivateDataSlotEXTWrapper>(privateDataSlot);
}

VKAPI_ATTR VkResult VKAPI_CALL SetPrivateDataEXT(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlotEXT                        privateDataSlot,
    uint64_t                                    data)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(TraceManager::Get(), device, objectType, objectHandle, privateDataSlot, data);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPrivateDataSlotEXT privateDataSlot_unwrapped = GetWrappedHandle<VkPrivateDataSlotEXT>(privateDataSlot);

    VkResult result = GetDeviceTable(device)->SetPrivateDataEXT(device_unwrapped, objectType, objectHandle, privateDataSlot_unwrapped, data);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetPrivateDataEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(objectHandle);
        encoder->EncodeHandleValue(privateDataSlot);
        encoder->EncodeUInt64Value(data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(TraceManager::Get(), result, device, objectType, objectHandle, privateDataSlot, data);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlotEXT                        privateDataSlot,
    uint64_t*                                   pData)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(TraceManager::Get(), device, objectType, objectHandle, privateDataSlot, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPrivateDataSlotEXT privateDataSlot_unwrapped = GetWrappedHandle<VkPrivateDataSlotEXT>(privateDataSlot);

    GetDeviceTable(device)->GetPrivateDataEXT(device_unwrapped, objectType, objectHandle, privateDataSlot_unwrapped, pData);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPrivateDataEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(objectHandle);
        encoder->EncodeHandleValue(privateDataSlot);
        encoder->EncodeUInt64Ptr(pData);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(TraceManager::Get(), device, objectType, objectHandle, privateDataSlot, pData);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDirectFBSurfaceEXT(
    VkInstance                                  instance,
    const VkDirectFBSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateDirectFBSurfaceEXT(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkDirectFBSurfaceCreateInfoEXT>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    IDirectFB*                                  dfb)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(TraceManager::Get(), physicalDevice, queueFamilyIndex, dfb);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice_unwrapped, queueFamilyIndex, dfb);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(dfb);
        encoder->EncodeVkBool32Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(TraceManager::Get(), result, physicalDevice, queueFamilyIndex, dfb);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureKHR(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureKHR*                 pAccelerationStructure)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pAccelerationStructure);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateAccelerationStructureKHR(device_unwrapped, pCreateInfo, pAllocator, pAccelerationStructure);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, AccelerationStructureKHRWrapper>(device, NoParentWrapper::kHandleValue, pAccelerationStructure, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pAccelerationStructure, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, AccelerationStructureKHRWrapper, VkAccelerationStructureCreateInfoKHR>(result, device, pAccelerationStructure, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsKHR(
    VkDevice                                    device,
    const VkAccelerationStructureMemoryRequirementsInfoKHR* pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAccelerationStructureMemoryRequirementsInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetAccelerationStructureMemoryRequirementsKHR(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfo,
    VkBuffer                                    indirectBuffer,
    VkDeviceSize                                indirectOffset,
    uint32_t                                    indirectStride)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureIndirectKHR>::Dispatch(TraceManager::Get(), commandBuffer, pInfo, indirectBuffer, indirectOffset, indirectStride);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureIndirectKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeHandleValue(indirectBuffer);
        encoder->EncodeVkDeviceSizeValue(indirectOffset);
        encoder->EncodeUInt32Value(indirectStride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBuildAccelerationStructureIndirectKHRHandles, pInfo, indirectBuffer);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);
    VkBuffer indirectBuffer_unwrapped = GetWrappedHandle<VkBuffer>(indirectBuffer);

    GetDeviceTable(commandBuffer)->CmdBuildAccelerationStructureIndirectKHR(commandBuffer_unwrapped, pInfo_unwrapped, indirectBuffer_unwrapped, indirectOffset, indirectStride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureIndirectKHR>::Dispatch(TraceManager::Get(), commandBuffer, pInfo, indirectBuffer, indirectOffset, indirectStride);
}

VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureKHR(
    VkDevice                                    device,
    const VkCopyAccelerationStructureInfoKHR*   pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkCopyAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CopyAccelerationStructureKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureToMemoryKHR(
    VkDevice                                    device,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CopyAccelerationStructureToMemoryKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToAccelerationStructureKHR(
    VkDevice                                    device,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CopyMemoryToAccelerationStructureKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WriteAccelerationStructuresPropertiesKHR(
    VkDevice                                    device,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    void*                                       pData,
    size_t                                      stride)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(TraceManager::Get(), device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAccelerationStructureKHR* pAccelerationStructures_unwrapped = UnwrapHandles<VkAccelerationStructureKHR>(pAccelerationStructures, accelerationStructureCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->WriteAccelerationStructuresPropertiesKHR(device_unwrapped, accelerationStructureCount, pAccelerationStructures_unwrapped, queryType, dataSize, pData, stride);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(accelerationStructureCount);
        encoder->EncodeHandleArray(pAccelerationStructures, accelerationStructureCount);
        encoder->EncodeEnumValue(queryType);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeSizeTValue(stride);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(TraceManager::Get(), result, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(TraceManager::Get(), commandBuffer, pInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyAccelerationStructureKHRHandles, pInfo);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyAccelerationStructureKHR(commandBuffer_unwrapped, pInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(TraceManager::Get(), commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(TraceManager::Get(), commandBuffer, pInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyAccelerationStructureToMemoryKHRHandles, pInfo);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyAccelerationStructureToMemoryKHR(commandBuffer_unwrapped, pInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(TraceManager::Get(), commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(TraceManager::Get(), commandBuffer, pInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyMemoryToAccelerationStructureKHRHandles, pInfo);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyMemoryToAccelerationStructureKHR(commandBuffer_unwrapped, pInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(TraceManager::Get(), commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedBufferRegionKHR*             pRaygenShaderBindingTable,
    const VkStridedBufferRegionKHR*             pMissShaderBindingTable,
    const VkStridedBufferRegionKHR*             pHitShaderBindingTable,
    const VkStridedBufferRegionKHR*             pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(TraceManager::Get(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdTraceRaysKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRaygenShaderBindingTable);
        EncodeStructPtr(encoder, pMissShaderBindingTable);
        EncodeStructPtr(encoder, pHitShaderBindingTable);
        EncodeStructPtr(encoder, pCallableShaderBindingTable);
        encoder->EncodeUInt32Value(width);
        encoder->EncodeUInt32Value(height);
        encoder->EncodeUInt32Value(depth);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdTraceRaysKHRHandles, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkStridedBufferRegionKHR* pRaygenShaderBindingTable_unwrapped = UnwrapStructPtrHandles(pRaygenShaderBindingTable, handle_unwrap_memory);
    const VkStridedBufferRegionKHR* pMissShaderBindingTable_unwrapped = UnwrapStructPtrHandles(pMissShaderBindingTable, handle_unwrap_memory);
    const VkStridedBufferRegionKHR* pHitShaderBindingTable_unwrapped = UnwrapStructPtrHandles(pHitShaderBindingTable, handle_unwrap_memory);
    const VkStridedBufferRegionKHR* pCallableShaderBindingTable_unwrapped = UnwrapStructPtrHandles(pCallableShaderBindingTable, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdTraceRaysKHR(commandBuffer_unwrapped, pRaygenShaderBindingTable_unwrapped, pMissShaderBindingTable_unwrapped, pHitShaderBindingTable_unwrapped, pCallableShaderBindingTable_unwrapped, width, height, depth);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(TraceManager::Get(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesKHR(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkRayTracingPipelineCreateInfoKHR*    pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);
    const VkRayTracingPipelineCreateInfoKHR* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateRayTracingPipelinesKHR(device_unwrapped, pipelineCache_unwrapped, createInfoCount, pCreateInfos_unwrapped, pAllocator, pPipelines);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, PipelineCacheWrapper, PipelineWrapper>(device, pipelineCache, pPipelines, createInfoCount, TraceManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleArray(pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndGroupCreateApiCallTrace<VkDevice, VkPipelineCache, PipelineWrapper, VkRayTracingPipelineCreateInfoKHR>(result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetAccelerationStructureDeviceAddressKHR(
    VkDevice                                    device,
    const VkAccelerationStructureDeviceAddressInfoKHR* pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAccelerationStructureDeviceAddressInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkDeviceAddress result = GetDeviceTable(device)->GetAccelerationStructureDeviceAddressKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVkDeviceAddressValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingCaptureReplayShaderGroupHandlesKHR(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData)
{
    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(TraceManager::Get(), device, pipeline, firstGroup, groupCount, dataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkResult result = GetDeviceTable(device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR(device_unwrapped, pipeline_unwrapped, firstGroup, groupCount, dataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(firstGroup);
        encoder->EncodeUInt32Value(groupCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(TraceManager::Get(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedBufferRegionKHR*             pRaygenShaderBindingTable,
    const VkStridedBufferRegionKHR*             pMissShaderBindingTable,
    const VkStridedBufferRegionKHR*             pHitShaderBindingTable,
    const VkStridedBufferRegionKHR*             pCallableShaderBindingTable,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(TraceManager::Get(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, buffer, offset);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRaygenShaderBindingTable);
        EncodeStructPtr(encoder, pMissShaderBindingTable);
        EncodeStructPtr(encoder, pHitShaderBindingTable);
        EncodeStructPtr(encoder, pCallableShaderBindingTable);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdTraceRaysIndirectKHRHandles, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, buffer);
    }

    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkStridedBufferRegionKHR* pRaygenShaderBindingTable_unwrapped = UnwrapStructPtrHandles(pRaygenShaderBindingTable, handle_unwrap_memory);
    const VkStridedBufferRegionKHR* pMissShaderBindingTable_unwrapped = UnwrapStructPtrHandles(pMissShaderBindingTable, handle_unwrap_memory);
    const VkStridedBufferRegionKHR* pHitShaderBindingTable_unwrapped = UnwrapStructPtrHandles(pHitShaderBindingTable, handle_unwrap_memory);
    const VkStridedBufferRegionKHR* pCallableShaderBindingTable_unwrapped = UnwrapStructPtrHandles(pCallableShaderBindingTable, handle_unwrap_memory);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdTraceRaysIndirectKHR(commandBuffer_unwrapped, pRaygenShaderBindingTable_unwrapped, pMissShaderBindingTable_unwrapped, pHitShaderBindingTable_unwrapped, pCallableShaderBindingTable_unwrapped, buffer_unwrapped, offset);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(TraceManager::Get(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, buffer, offset);
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR(
    VkDevice                                    device,
    const VkAccelerationStructureVersionKHR*    version)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(TraceManager::Get(), device, version);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetDeviceAccelerationStructureCompatibilityKHR(device_unwrapped, version);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, version);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(TraceManager::Get(), result, device, version);

    return result;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
