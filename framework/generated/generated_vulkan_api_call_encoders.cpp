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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(TraceManager::Get(), pCreateInfo, pAllocator, pInstance);

    VkResult result = TraceManager::GetLayerTable()->CreateInstance(pCreateInfo, pAllocator, pInstance);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<NoParentWrapper, NoParentWrapper, InstanceWrapper>(NoParentWrapper::kHandleValue, NoParentWrapper::kHandleValue, pInstance, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateInstance);
    if (encoder)
    {
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pInstance);
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
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<InstanceWrapper>(instance, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    TraceManager::Get()->GetInstanceTable(instance)->DestroyInstance(instance, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(TraceManager::Get(), instance, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(TraceManager::Get(), instance, pPhysicalDeviceCount, pPhysicalDevices);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandles<InstanceWrapper, NoParentWrapper, PhysicalDeviceWrapper>(instance, NoParentWrapper::kHandleValue, pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceCount);
        encoder->EncodeHandleIdArray(pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures(physicalDevice, pFeatures);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(TraceManager::Get(), physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        EncodeStructPtr(encoder, pImageFormatProperties);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties(physicalDevice, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(TraceManager::Get(), physicalDevice, pCreateInfo, pAllocator, pDevice);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::GetLayerTable()->CreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DeviceWrapper>(physicalDevice, NoParentWrapper::kHandleValue, pDevice, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDevice);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pDevice);
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
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DeviceWrapper>(device, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyDevice(device, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(TraceManager::Get(), device, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(TraceManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    CreateWrappedHandle<DeviceWrapper, NoParentWrapper, QueueWrapper>(device, NoParentWrapper::kHandleValue, pQueue, TraceManager::GetUniqueId);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceQueue);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeUInt32Value(queueIndex);
        encoder->EncodeHandleIdPtr(pQueue);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<QueueWrapper>(&queue, handle_store);
    UnwrapStructArrayHandles(pSubmits, submitCount, handle_store, handle_array_store, handle_unwrap_memory);
    UnwrapHandle<FenceWrapper>(&fence, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(queue)->QueueSubmit(queue, submitCount, pSubmits, fence);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<QueueWrapper>(&queue, &handle_store_iter);
    RewrapStructArrayHandles(pSubmits, submitCount, &handle_store_iter, &handle_array_store_iter);
    RewrapHandle<FenceWrapper>(&fence, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueSubmit);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Value(submitCount);
        EncodeStructArray(encoder, pSubmits, submitCount);
        encoder->EncodeHandleIdValue(fence);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<QueueWrapper>(&queue, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(queue)->QueueWaitIdle(queue);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<QueueWrapper>(&queue, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->DeviceWaitIdle(device);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDeviceWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(TraceManager::Get(), device, pAllocateInfo, pAllocator, pMemory);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pAllocateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->AllocateMemory(device, pAllocateInfo, pAllocator, pMemory);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pAllocateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DeviceMemoryWrapper>(device, NoParentWrapper::kHandleValue, pMemory, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkAllocateMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pMemory);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DeviceMemoryWrapper>(memory, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DeviceMemoryWrapper>(&memory, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->FreeMemory(device, memory, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DeviceMemoryWrapper>(&memory, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(TraceManager::Get(), device, memory, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL MapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    void**                                      ppData)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(TraceManager::Get(), device, memory, offset, size, flags, ppData);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DeviceMemoryWrapper>(&memory, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->MapMemory(device, memory, offset, size, flags, ppData);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DeviceMemoryWrapper>(&memory, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMapMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeVoidPtrPtr(ppData);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DeviceMemoryWrapper>(&memory, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->UnmapMemory(device, memory);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DeviceMemoryWrapper>(&memory, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(TraceManager::Get(), device, memory);
}

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(TraceManager::Get(), device, memoryRangeCount, pMemoryRanges);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructArrayHandles(pMemoryRanges, memoryRangeCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->FlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructArrayHandles(pMemoryRanges, memoryRangeCount, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructArrayHandles(pMemoryRanges, memoryRangeCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->InvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructArrayHandles(pMemoryRanges, memoryRangeCount, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DeviceMemoryWrapper>(&memory, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->GetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DeviceMemoryWrapper>(&memory, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);
    UnwrapHandle<DeviceMemoryWrapper>(&memory, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->BindBufferMemory(device, buffer, memory, memoryOffset);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);
    RewrapHandle<DeviceMemoryWrapper>(&memory, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeHandleIdValue(memory);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ImageWrapper>(&image, handle_store);
    UnwrapHandle<DeviceMemoryWrapper>(&memory, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->BindImageMemory(device, image, memory, memoryOffset);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&image, &handle_store_iter);
    RewrapHandle<DeviceMemoryWrapper>(&memory, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeHandleIdValue(memory);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(buffer);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ImageWrapper>(&image, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->GetImageMemoryRequirements(device, image, pMemoryRequirements);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&image, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ImageWrapper>(&image, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->GetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&image, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<QueueWrapper>(&queue, handle_store);
    UnwrapStructArrayHandles(pBindInfo, bindInfoCount, handle_store, handle_array_store, handle_unwrap_memory);
    UnwrapHandle<FenceWrapper>(&fence, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(queue)->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<QueueWrapper>(&queue, &handle_store_iter);
    RewrapStructArrayHandles(pBindInfo, bindInfoCount, &handle_store_iter, &handle_array_store_iter);
    RewrapHandle<FenceWrapper>(&fence, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueBindSparse);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfo, bindInfoCount);
        encoder->EncodeHandleIdValue(fence);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pFence);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateFence(device, pCreateInfo, pAllocator, pFence);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, FenceWrapper>(device, NoParentWrapper::kHandleValue, pFence, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateFence);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pFence);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(fence);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<FenceWrapper>(fence, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<FenceWrapper>(&fence, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyFence(device, fence, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<FenceWrapper>(&fence, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(TraceManager::Get(), device, fence, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(TraceManager::Get(), device, fenceCount, pFences);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandles<FenceWrapper>(&pFences, fenceCount, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->ResetFences(device, fenceCount, pFences);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandles<FenceWrapper>(&pFences, fenceCount, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetFences);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleIdArray(pFences, fenceCount);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<FenceWrapper>(&fence, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetFenceStatus(device, fence);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<FenceWrapper>(&fence, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceStatus);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(fence);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandles<FenceWrapper>(&pFences, fenceCount, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->WaitForFences(device, fenceCount, pFences, waitAll, timeout);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandles<FenceWrapper>(&pFences, fenceCount, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkWaitForFences);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleIdArray(pFences, fenceCount);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pSemaphore);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SemaphoreWrapper>(device, NoParentWrapper::kHandleValue, pSemaphore, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSemaphore);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSemaphore);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(semaphore);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SemaphoreWrapper>(semaphore, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SemaphoreWrapper>(&semaphore, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroySemaphore(device, semaphore, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SemaphoreWrapper>(&semaphore, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(TraceManager::Get(), device, semaphore, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pEvent);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateEvent(device, pCreateInfo, pAllocator, pEvent);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, EventWrapper>(device, NoParentWrapper::kHandleValue, pEvent, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pEvent);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<EventWrapper>(event, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<EventWrapper>(&event, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyEvent(device, event, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<EventWrapper>(&event, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(TraceManager::Get(), device, event, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(
    VkDevice                                    device,
    VkEvent                                     event)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(TraceManager::Get(), device, event);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<EventWrapper>(&event, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetEventStatus(device, event);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<EventWrapper>(&event, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetEventStatus);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<EventWrapper>(&event, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->SetEvent(device, event);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<EventWrapper>(&event, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<EventWrapper>(&event, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->ResetEvent(device, event);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<EventWrapper>(&event, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pQueryPool);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, QueryPoolWrapper>(device, NoParentWrapper::kHandleValue, pQueryPool, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pQueryPool);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(queryPool);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<QueryPoolWrapper>(queryPool, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyQueryPool(device, queryPool, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(TraceManager::Get(), device, queryPool, pAllocator);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(TraceManager::Get(), device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetQueryPoolResults);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pBuffer);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateBuffer(device, pCreateInfo, pAllocator, pBuffer);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, BufferWrapper>(device, NoParentWrapper::kHandleValue, pBuffer, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pBuffer);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(buffer);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<BufferWrapper>(buffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyBuffer(device, buffer, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(TraceManager::Get(), device, buffer, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pView);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateBufferView(device, pCreateInfo, pAllocator, pView);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, BufferViewWrapper>(device, NoParentWrapper::kHandleValue, pView, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateBufferView);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pView);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(bufferView);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<BufferViewWrapper>(bufferView, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<BufferViewWrapper>(&bufferView, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyBufferView(device, bufferView, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<BufferViewWrapper>(&bufferView, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(TraceManager::Get(), device, bufferView, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pImage);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateImage(device, pCreateInfo, pAllocator, pImage);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ImageWrapper>(device, NoParentWrapper::kHandleValue, pImage, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pImage);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<ImageWrapper>(image, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ImageWrapper>(&image, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyImage(device, image, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&image, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(TraceManager::Get(), device, image, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(TraceManager::Get(), device, image, pSubresource, pLayout);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ImageWrapper>(&image, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->GetImageSubresourceLayout(device, image, pSubresource, pLayout);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&image, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pView);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateImageView(device, pCreateInfo, pAllocator, pView);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ImageViewWrapper>(device, NoParentWrapper::kHandleValue, pView, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateImageView);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pView);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(imageView);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<ImageViewWrapper>(imageView, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ImageViewWrapper>(&imageView, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyImageView(device, imageView, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ImageViewWrapper>(&imageView, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(TraceManager::Get(), device, imageView, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pShaderModule);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ShaderModuleWrapper>(device, NoParentWrapper::kHandleValue, pShaderModule, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateShaderModule);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pShaderModule);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(shaderModule);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<ShaderModuleWrapper>(shaderModule, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ShaderModuleWrapper>(&shaderModule, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyShaderModule(device, shaderModule, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ShaderModuleWrapper>(&shaderModule, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(TraceManager::Get(), device, shaderModule, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pPipelineCache);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PipelineCacheWrapper>(device, NoParentWrapper::kHandleValue, pPipelineCache, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreatePipelineCache);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pPipelineCache);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<PipelineCacheWrapper>(pipelineCache, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineCacheWrapper>(&pipelineCache, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyPipelineCache(device, pipelineCache, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineCacheWrapper>(&pipelineCache, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(TraceManager::Get(), device, pipelineCache, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(TraceManager::Get(), device, pipelineCache, pDataSize, pData);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineCacheWrapper>(&pipelineCache, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetPipelineCacheData(device, pipelineCache, pDataSize, pData);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineCacheWrapper>(&pipelineCache, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPipelineCacheData);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        encoder->EncodeSizeTPtr(pDataSize);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineCacheWrapper>(&dstCache, handle_store);
    UnwrapHandles<PipelineCacheWrapper>(&pSrcCaches, srcCacheCount, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->MergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineCacheWrapper>(&dstCache, &handle_store_iter);
    RewrapHandles<PipelineCacheWrapper>(&pSrcCaches, srcCacheCount, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMergePipelineCaches);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleIdArray(pSrcCaches, srcCacheCount);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineCacheWrapper>(&pipelineCache, handle_store);
    UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineCacheWrapper>(&pipelineCache, &handle_store_iter);
    RewrapStructArrayHandles(pCreateInfos, createInfoCount, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandles<DeviceWrapper, PipelineCacheWrapper, PipelineWrapper>(device, pipelineCache, pPipelines, createInfoCount, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateGraphicsPipelines);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdArray(pPipelines, createInfoCount);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineCacheWrapper>(&pipelineCache, handle_store);
    UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineCacheWrapper>(&pipelineCache, &handle_store_iter);
    RewrapStructArrayHandles(pCreateInfos, createInfoCount, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandles<DeviceWrapper, PipelineCacheWrapper, PipelineWrapper>(device, pipelineCache, pPipelines, createInfoCount, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateComputePipelines);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdArray(pPipelines, createInfoCount);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<PipelineWrapper>(pipeline, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineWrapper>(&pipeline, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyPipeline(device, pipeline, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineWrapper>(&pipeline, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(TraceManager::Get(), device, pipeline, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pPipelineLayout);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PipelineLayoutWrapper>(device, NoParentWrapper::kHandleValue, pPipelineLayout, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreatePipelineLayout);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pPipelineLayout);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineLayout);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<PipelineLayoutWrapper>(pipelineLayout, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineLayoutWrapper>(&pipelineLayout, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyPipelineLayout(device, pipelineLayout, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineLayoutWrapper>(&pipelineLayout, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(TraceManager::Get(), device, pipelineLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pSampler);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateSampler(device, pCreateInfo, pAllocator, pSampler);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SamplerWrapper>(device, NoParentWrapper::kHandleValue, pSampler, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSampler);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSampler);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(sampler);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SamplerWrapper>(sampler, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SamplerWrapper>(&sampler, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroySampler(device, sampler, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SamplerWrapper>(&sampler, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(TraceManager::Get(), device, sampler, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorSetLayout*                      pSetLayout)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pSetLayout);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorSetLayoutWrapper>(device, NoParentWrapper::kHandleValue, pSetLayout, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSetLayout);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorSetLayout);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DescriptorSetLayoutWrapper>(descriptorSetLayout, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DescriptorSetLayoutWrapper>(&descriptorSetLayout, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DescriptorSetLayoutWrapper>(&descriptorSetLayout, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(TraceManager::Get(), device, descriptorSetLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorPool);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorPoolWrapper>(device, NoParentWrapper::kHandleValue, pDescriptorPool, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pDescriptorPool);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorPool);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DescriptorPoolWrapper>(descriptorPool, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DescriptorPoolWrapper>(&descriptorPool, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyDescriptorPool(device, descriptorPool, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DescriptorPoolWrapper>(&descriptorPool, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(TraceManager::Get(), device, descriptorPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(TraceManager::Get(), device, descriptorPool, flags);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DescriptorPoolWrapper>(&descriptorPool, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->ResetDescriptorPool(device, descriptorPool, flags);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DescriptorPoolWrapper>(&descriptorPool, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorPool);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(TraceManager::Get(), device, pAllocateInfo, pDescriptorSets);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pAllocateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->AllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pAllocateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandles<DeviceWrapper, DescriptorPoolWrapper, DescriptorSetWrapper>(device, pAllocateInfo->descriptorPool, pDescriptorSets, pAllocateInfo->descriptorSetCount, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkAllocateDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        encoder->EncodeHandleIdArray(pDescriptorSets, pAllocateInfo->descriptorSetCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndPoolCreateApiCallTrace<VkDevice, DescriptorSetWrapper, VkDescriptorSetAllocateInfo>(result, device, pAllocateInfo->descriptorSetCount, pDescriptorSets, pAllocateInfo, encoder);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DescriptorPoolWrapper>(&descriptorPool, handle_store);
    UnwrapHandles<DescriptorSetWrapper>(&pDescriptorSets, descriptorSetCount, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->FreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DescriptorPoolWrapper>(&descriptorPool, &handle_store_iter);
    RewrapHandles<DescriptorSetWrapper>(&pDescriptorSets, descriptorSetCount, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkFreeDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorPool);
        encoder->EncodeUInt32Value(descriptorSetCount);
        encoder->EncodeHandleIdArray(pDescriptorSets, descriptorSetCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndDestroyApiCallTrace<DescriptorSetWrapper>(descriptorSetCount, pDescriptorSets, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(TraceManager::Get(), result, device, descriptorPool, descriptorSetCount, pDescriptorSets);

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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        EncodeStructArray(encoder, pDescriptorWrites, descriptorWriteCount);
        encoder->EncodeUInt32Value(descriptorCopyCount);
        EncodeStructArray(encoder, pDescriptorCopies, descriptorCopyCount);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, handle_store, handle_array_store, handle_unwrap_memory);
    UnwrapStructArrayHandles(pDescriptorCopies, descriptorCopyCount, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->UpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, &handle_store_iter, &handle_array_store_iter);
    RewrapStructArrayHandles(pDescriptorCopies, descriptorCopyCount, &handle_store_iter, &handle_array_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(TraceManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFramebuffer*                              pFramebuffer)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pFramebuffer);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, FramebufferWrapper>(device, NoParentWrapper::kHandleValue, pFramebuffer, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateFramebuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pFramebuffer);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(framebuffer);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<FramebufferWrapper>(framebuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<FramebufferWrapper>(&framebuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyFramebuffer(device, framebuffer, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<FramebufferWrapper>(&framebuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(TraceManager::Get(), device, framebuffer, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, RenderPassWrapper>(device, NoParentWrapper::kHandleValue, pRenderPass, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pRenderPass);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(renderPass);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<RenderPassWrapper>(renderPass, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<RenderPassWrapper>(&renderPass, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyRenderPass(device, renderPass, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<RenderPassWrapper>(&renderPass, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(TraceManager::Get(), device, renderPass, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(TraceManager::Get(), device, renderPass, pGranularity);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<RenderPassWrapper>(&renderPass, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->GetRenderAreaGranularity(device, renderPass, pGranularity);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<RenderPassWrapper>(&renderPass, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRenderAreaGranularity);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(renderPass);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pCommandPool);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, CommandPoolWrapper>(device, NoParentWrapper::kHandleValue, pCommandPool, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pCommandPool);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<CommandPoolWrapper>(commandPool, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<CommandPoolWrapper>(&commandPool, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyCommandPool(device, commandPool, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<CommandPoolWrapper>(&commandPool, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(TraceManager::Get(), device, commandPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(TraceManager::Get(), device, commandPool, flags);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<CommandPoolWrapper>(&commandPool, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->ResetCommandPool(device, commandPool, flags);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<CommandPoolWrapper>(&commandPool, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(TraceManager::Get(), device, pAllocateInfo, pCommandBuffers);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pAllocateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->AllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pAllocateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandles<DeviceWrapper, CommandPoolWrapper, CommandBufferWrapper>(device, pAllocateInfo->commandPool, pCommandBuffers, pAllocateInfo->commandBufferCount, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkAllocateCommandBuffers);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        encoder->EncodeHandleIdArray(pCommandBuffers, pAllocateInfo->commandBufferCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndPoolCreateApiCallTrace<VkDevice, CommandBufferWrapper, VkCommandBufferAllocateInfo>(result, device, pAllocateInfo->commandBufferCount, pCommandBuffers, pAllocateInfo, encoder);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleIdArray(pCommandBuffers, commandBufferCount);
        TraceManager::Get()->EndDestroyApiCallTrace<CommandBufferWrapper>(commandBufferCount, pCommandBuffers, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<CommandPoolWrapper>(&commandPool, handle_store);
    UnwrapHandles<CommandBufferWrapper>(&pCommandBuffers, commandBufferCount, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<CommandPoolWrapper>(&commandPool, &handle_store_iter);
    RewrapHandles<CommandBufferWrapper>(&pCommandBuffers, commandBufferCount, &handle_array_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(TraceManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(TraceManager::Get(), commandBuffer, pBeginInfo);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapStructHandles(pBeginInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(commandBuffer)->BeginCommandBuffer(commandBuffer, pBeginInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapStructHandles(pBeginInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkBeginCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(commandBuffer)->EndCommandBuffer(commandBuffer);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkEndCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(commandBuffer)->ResetCommandBuffer(commandBuffer, flags);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkResetCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(pipeline);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindPipelineHandles, pipeline);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<PipelineWrapper>(&pipeline, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<PipelineWrapper>(&pipeline, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewports, viewportCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstScissor);
        encoder->EncodeUInt32Value(scissorCount);
        EncodeStructArray(encoder, pScissors, scissorCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(lineWidth);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetLineWidth(commandBuffer, lineWidth);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(depthBiasConstantFactor);
        encoder->EncodeFloatValue(depthBiasClamp);
        encoder->EncodeFloatValue(depthBiasSlopeFactor);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatArray(blendConstants, 4);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetBlendConstants(commandBuffer, blendConstants);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(minDepthBounds);
        encoder->EncodeFloatValue(maxDepthBounds);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(compareMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(writeMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(reference);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetStencilReference(commandBuffer, faceMask, reference);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeUInt32Value(firstSet);
        encoder->EncodeUInt32Value(descriptorSetCount);
        encoder->EncodeHandleIdArray(pDescriptorSets, descriptorSetCount);
        encoder->EncodeUInt32Value(dynamicOffsetCount);
        encoder->EncodeUInt32Array(pDynamicOffsets, dynamicOffsetCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindDescriptorSetsHandles, layout, descriptorSetCount, pDescriptorSets);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<PipelineLayoutWrapper>(&layout, handle_store);
    UnwrapHandles<DescriptorSetWrapper>(&pDescriptorSets, descriptorSetCount, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<PipelineLayoutWrapper>(&layout, &handle_store_iter);
    RewrapHandles<DescriptorSetWrapper>(&pDescriptorSets, descriptorSetCount, &handle_array_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeEnumValue(indexType);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindIndexBufferHandles, buffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleIdArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindVertexBuffersHandles, bindingCount, pBuffers);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandles<BufferWrapper>(&pBuffers, bindingCount, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandles<BufferWrapper>(&pBuffers, bindingCount, &handle_array_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(vertexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstVertex);
        encoder->EncodeUInt32Value(firstInstance);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(indexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstIndex);
        encoder->EncodeInt32Value(vertexOffset);
        encoder->EncodeUInt32Value(firstInstance);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndirectHandles, buffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndexedIndirectHandles, buffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDispatchIndirectHandles, buffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDispatchIndirect(commandBuffer, buffer, offset);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyBufferHandles, srcBuffer, dstBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&srcBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&dstBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&srcBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&dstBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyImageHandles, srcImage, dstImage);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<ImageWrapper>(&srcImage, handle_store);
    UnwrapHandle<ImageWrapper>(&dstImage, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&srcImage, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&dstImage, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        encoder->EncodeEnumValue(filter);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBlitImageHandles, srcImage, dstImage);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<ImageWrapper>(&srcImage, handle_store);
    UnwrapHandle<ImageWrapper>(&dstImage, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&srcImage, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&dstImage, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcBuffer);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyBufferToImageHandles, srcBuffer, dstImage);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&srcBuffer, handle_store);
    UnwrapHandle<ImageWrapper>(&dstImage, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&srcBuffer, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&dstImage, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyImageToBufferHandles, srcImage, dstBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<ImageWrapper>(&srcImage, handle_store);
    UnwrapHandle<BufferWrapper>(&dstBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&srcImage, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&dstBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdUpdateBufferHandles, dstBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&dstBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&dstBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeUInt32Value(data);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdFillBufferHandles, dstBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&dstBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&dstBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeEnumValue(imageLayout);
        EncodeStructPtr(encoder, pColor);
        encoder->EncodeUInt32Value(rangeCount);
        EncodeStructArray(encoder, pRanges, rangeCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdClearColorImageHandles, image);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<ImageWrapper>(&image, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&image, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeEnumValue(imageLayout);
        EncodeStructPtr(encoder, pDepthStencil);
        encoder->EncodeUInt32Value(rangeCount);
        EncodeStructArray(encoder, pRanges, rangeCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdClearDepthStencilImageHandles, image);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<ImageWrapper>(&image, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&image, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(attachmentCount);
        EncodeStructArray(encoder, pAttachments, attachmentCount);
        encoder->EncodeUInt32Value(rectCount);
        EncodeStructArray(encoder, pRects, rectCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdResolveImageHandles, srcImage, dstImage);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<ImageWrapper>(&srcImage, handle_store);
    UnwrapHandle<ImageWrapper>(&dstImage, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&srcImage, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&dstImage, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeFlagsValue(stageMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdSetEventHandles, event);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<EventWrapper>(&event, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetEvent(commandBuffer, event, stageMask);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<EventWrapper>(&event, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeFlagsValue(stageMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdResetEventHandles, event);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<EventWrapper>(&event, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdResetEvent(commandBuffer, event, stageMask);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<EventWrapper>(&event, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(eventCount);
        encoder->EncodeHandleIdArray(pEvents, eventCount);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandles<EventWrapper>(&pEvents, eventCount, handle_array_store, handle_unwrap_memory);
    UnwrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, handle_store, handle_array_store, handle_unwrap_memory);
    UnwrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandles<EventWrapper>(&pEvents, eventCount, &handle_array_store_iter);
    RewrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, &handle_store_iter, &handle_array_store_iter);
    RewrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, &handle_store_iter, &handle_array_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, handle_store, handle_array_store, handle_unwrap_memory);
    UnwrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, &handle_store_iter, &handle_array_store_iter);
    RewrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, &handle_store_iter, &handle_array_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginQueryHandles, queryPool);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginQuery(commandBuffer, queryPool, query, flags);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdEndQueryHandles, queryPool);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndQuery(commandBuffer, queryPool, query);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdResetQueryPoolHandles, queryPool);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdWriteTimestampHandles, queryPool);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(stride);
        encoder->EncodeFlagsValue(flags);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyQueryPoolResultsHandles, queryPool, dstBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);
    UnwrapHandle<BufferWrapper>(&dstBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&dstBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeFlagsValue(stageFlags);
        encoder->EncodeUInt32Value(offset);
        encoder->EncodeUInt32Value(size);
        encoder->EncodeVoidArray(pValues, size);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdPushConstantsHandles, layout);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<PipelineLayoutWrapper>(&layout, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<PipelineLayoutWrapper>(&layout, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderPassBegin);
        encoder->EncodeEnumValue(contents);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginRenderPassHandles, pRenderPassBegin);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapStructHandles(pRenderPassBegin, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapStructHandles(pRenderPassBegin, &handle_store_iter, &handle_array_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(contents);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdNextSubpass(commandBuffer, contents);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(TraceManager::Get(), commandBuffer, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(
    VkCommandBuffer                             commandBuffer)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(TraceManager::Get(), commandBuffer);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndRenderPass(commandBuffer);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleIdArray(pCommandBuffers, commandBufferCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdExecuteCommandsHandles, commandBufferCount, pCommandBuffers);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandles<CommandBufferWrapper>(&pCommandBuffers, commandBufferCount, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandles<CommandBufferWrapper>(&pCommandBuffers, commandBufferCount, &handle_array_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(TraceManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->BindBufferMemory2(device, bindInfoCount, pBindInfos);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructArrayHandles(pBindInfos, bindInfoCount, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->BindImageMemory2(device, bindInfoCount, pBindInfos);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructArrayHandles(pBindInfos, bindInfoCount, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->GetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetDeviceMask(commandBuffer, deviceMask);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(TraceManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedStructArrayHandles<InstanceWrapper, NoParentWrapper, VkPhysicalDeviceGroupProperties>(instance, NoParentWrapper::kHandleValue, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount);
        EncodeStructArray(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->GetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->GetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->GetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(TraceManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pImageFormatInfo);
        EncodeStructPtr(encoder, pImageFormatProperties);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<CommandPoolWrapper>(&commandPool, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->TrimCommandPool(device, commandPool, flags);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<CommandPoolWrapper>(&commandPool, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(TraceManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(
    VkDevice                                    device,
    const VkDeviceQueueInfo2*                   pQueueInfo,
    VkQueue*                                    pQueue)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(TraceManager::Get(), device, pQueueInfo, pQueue);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->GetDeviceQueue2(device, pQueueInfo, pQueue);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    CreateWrappedHandle<DeviceWrapper, NoParentWrapper, QueueWrapper>(device, NoParentWrapper::kHandleValue, pQueue, TraceManager::GetUniqueId);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceQueue2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pQueueInfo);
        encoder->EncodeHandleIdPtr(pQueue);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SamplerYcbcrConversionWrapper>(device, NoParentWrapper::kHandleValue, pYcbcrConversion, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pYcbcrConversion);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(ycbcrConversion);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SamplerYcbcrConversionWrapper>(ycbcrConversion, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SamplerYcbcrConversionWrapper>(&ycbcrConversion, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SamplerYcbcrConversionWrapper>(&ycbcrConversion, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(TraceManager::Get(), device, ycbcrConversion, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorUpdateTemplateWrapper>(device, NoParentWrapper::kHandleValue, pDescriptorUpdateTemplate, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pDescriptorUpdateTemplate);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorUpdateTemplate);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DescriptorUpdateTemplateWrapper>(&descriptorUpdateTemplate, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DescriptorUpdateTemplateWrapper>(&descriptorUpdateTemplate, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->GetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pSupport);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(TraceManager::Get(), device, pCreateInfo, pSupport);
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
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeHandleIdValue(surface);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SurfaceKHRWrapper>(surface, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);
    UnwrapHandle<SurfaceKHRWrapper>(&surface, handle_store);

    TraceManager::Get()->GetInstanceTable(instance)->DestroySurfaceKHR(instance, surface, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);
    RewrapHandle<SurfaceKHRWrapper>(&surface, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(TraceManager::Get(), instance, surface, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(TraceManager::Get(), physicalDevice, queueFamilyIndex, surface, pSupported);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<SurfaceKHRWrapper>(&surface, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<SurfaceKHRWrapper>(&surface, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeVkBool32Ptr(pSupported);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<SurfaceKHRWrapper>(&surface, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<SurfaceKHRWrapper>(&surface, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        EncodeStructPtr(encoder, pSurfaceCapabilities);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(TraceManager::Get(), physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<SurfaceKHRWrapper>(&surface, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<SurfaceKHRWrapper>(&surface, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount);
        EncodeStructArray(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(TraceManager::Get(), physicalDevice, surface, pPresentModeCount, pPresentModes);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<SurfaceKHRWrapper>(&surface, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<SurfaceKHRWrapper>(&surface, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pPresentModeCount);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pSwapchain);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SwapchainKHRWrapper>(device, NoParentWrapper::kHandleValue, pSwapchain, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSwapchainKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSwapchain);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SwapchainKHRWrapper>(swapchain, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SwapchainKHRWrapper>(&swapchain, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroySwapchainKHR(device, swapchain, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SwapchainKHRWrapper>(&swapchain, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(TraceManager::Get(), device, swapchain, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pSwapchainImageCount,
    VkImage*                                    pSwapchainImages)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(TraceManager::Get(), device, swapchain, pSwapchainImageCount, pSwapchainImages);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SwapchainKHRWrapper>(&swapchain, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SwapchainKHRWrapper>(&swapchain, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandles<DeviceWrapper, SwapchainKHRWrapper, ImageWrapper>(device, swapchain, pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt32Ptr(pSwapchainImageCount);
        encoder->EncodeHandleIdArray(pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(TraceManager::Get(), device, swapchain, timeout, semaphore, fence, pImageIndex);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SwapchainKHRWrapper>(&swapchain, handle_store);
    UnwrapHandle<SemaphoreWrapper>(&semaphore, handle_store);
    UnwrapHandle<FenceWrapper>(&fence, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->AcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SwapchainKHRWrapper>(&swapchain, &handle_store_iter);
    RewrapHandle<SemaphoreWrapper>(&semaphore, &handle_store_iter);
    RewrapHandle<FenceWrapper>(&fence, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireNextImageKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeHandleIdValue(semaphore);
        encoder->EncodeHandleIdValue(fence);
        encoder->EncodeUInt32Ptr(pImageIndex);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<QueueWrapper>(&queue, handle_store);
    UnwrapStructHandles(pPresentInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(queue)->QueuePresentKHR(queue, pPresentInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<QueueWrapper>(&queue, &handle_store_iter);
    RewrapStructHandles(pPresentInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueuePresentKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(TraceManager::Get(), device, pDeviceGroupPresentCapabilities);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pDeviceGroupPresentCapabilities);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(TraceManager::Get(), device, surface, pModes);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SurfaceKHRWrapper>(&surface, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SurfaceKHRWrapper>(&surface, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeFlagsPtr(pModes);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(TraceManager::Get(), physicalDevice, surface, pRectCount, pRects);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<SurfaceKHRWrapper>(&surface, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<SurfaceKHRWrapper>(&surface, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pRectCount);
        EncodeStructArray(encoder, pRects, (pRectCount != nullptr) ? (*pRectCount) : 0);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(TraceManager::Get(), device, pAcquireInfo, pImageIndex);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pAcquireInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->AcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pAcquireInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireNextImage2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pAcquireInfo);
        encoder->EncodeUInt32Ptr(pImageIndex);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayPropertiesKHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayPlanePropertiesKHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(TraceManager::Get(), physicalDevice, planeIndex, pDisplayCount, pDisplays);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandles<PhysicalDeviceWrapper, NoParentWrapper, DisplayKHRWrapper>(physicalDevice, NoParentWrapper::kHandleValue, pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(planeIndex);
        encoder->EncodeUInt32Ptr(pDisplayCount);
        encoder->EncodeHandleIdArray(pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<DisplayKHRWrapper>(&display, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<DisplayKHRWrapper>(&display, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, DisplayKHRWrapper, VkDisplayModePropertiesKHR>(physicalDevice, display, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(TraceManager::Get(), physicalDevice, display, pCreateInfo, pAllocator, pMode);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<DisplayKHRWrapper>(&display, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->CreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<DisplayKHRWrapper>(&display, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<PhysicalDeviceWrapper, DisplayKHRWrapper, DisplayModeKHRWrapper>(physicalDevice, display, pMode, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDisplayModeKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pMode);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(TraceManager::Get(), physicalDevice, mode, planeIndex, pCapabilities);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<DisplayModeKHRWrapper>(&mode, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<DisplayModeKHRWrapper>(&mode, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(mode);
        encoder->EncodeUInt32Value(planeIndex);
        EncodeStructPtr(encoder, pCapabilities);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(TraceManager::Get(), device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructArrayHandles(pCreateInfos, swapchainCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructArrayHandles(pCreateInfos, swapchainCount, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandles<DeviceWrapper, NoParentWrapper, SwapchainKHRWrapper>(device, NoParentWrapper::kHandleValue, pSwapchains, swapchainCount, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        EncodeStructArray(encoder, pCreateInfos, swapchainCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdArray(pSwapchains, swapchainCount);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkBool32 result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkBool32 result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkBool32 result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkBool32 result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pImageFormatInfo);
        EncodeStructPtr(encoder, pImageFormatProperties);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->GetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetDeviceMaskKHR(commandBuffer, deviceMask);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<CommandPoolWrapper>(&commandPool, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->TrimCommandPoolKHR(device, commandPool, flags);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<CommandPoolWrapper>(&commandPool, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(TraceManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(TraceManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->EnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedStructArrayHandles<InstanceWrapper, NoParentWrapper, VkPhysicalDeviceGroupProperties>(instance, NoParentWrapper::kHandleValue, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount);
        EncodeStructArray(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pGetWin32HandleInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pGetWin32HandleInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(TraceManager::Get(), device, handleType, handle, pMemoryWin32HandleProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(handle);
        EncodeStructPtr(encoder, pMemoryWin32HandleProperties);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(TraceManager::Get(), device, pGetFdInfo, pFd);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pGetFdInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetMemoryFdKHR(device, pGetFdInfo, pFd);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pGetFdInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(TraceManager::Get(), device, handleType, fd, pMemoryFdProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeInt32Value(fd);
        EncodeStructPtr(encoder, pMemoryFdProperties);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pImportSemaphoreWin32HandleInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->ImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pImportSemaphoreWin32HandleInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pGetWin32HandleInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pGetWin32HandleInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pImportSemaphoreFdInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->ImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pImportSemaphoreFdInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(TraceManager::Get(), device, pGetFdInfo, pFd);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pGetFdInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetSemaphoreFdKHR(device, pGetFdInfo, pFd);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pGetFdInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeUInt32Value(set);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        EncodeStructArray(encoder, pDescriptorWrites, descriptorWriteCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdPushDescriptorSetKHRHandles, layout, descriptorWriteCount, pDescriptorWrites);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<PipelineLayoutWrapper>(&layout, handle_store);
    UnwrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<PipelineLayoutWrapper>(&layout, &handle_store_iter);
    RewrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, &handle_store_iter, &handle_array_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorUpdateTemplateWrapper>(device, NoParentWrapper::kHandleValue, pDescriptorUpdateTemplate, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pDescriptorUpdateTemplate);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorUpdateTemplate);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DescriptorUpdateTemplateWrapper>(&descriptorUpdateTemplate, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DescriptorUpdateTemplateWrapper>(&descriptorUpdateTemplate, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2KHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, RenderPassWrapper>(device, NoParentWrapper::kHandleValue, pRenderPass, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pRenderPass);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, RenderPassWrapper, VkRenderPassCreateInfo2KHR>(result, device, pRenderPass, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderPassBegin);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginRenderPass2KHRHandles, pRenderPassBegin);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapStructHandles(pRenderPassBegin, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapStructHandles(pRenderPassBegin, &handle_store_iter, &handle_array_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo,
    const VkSubpassEndInfoKHR*                  pSubpassEndInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfoKHR*                  pSubpassEndInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassEndInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(TraceManager::Get(), commandBuffer, pSubpassEndInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(TraceManager::Get(), device, swapchain);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SwapchainKHRWrapper>(&swapchain, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetSwapchainStatusKHR(device, swapchain);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SwapchainKHRWrapper>(&swapchain, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pImportFenceWin32HandleInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->ImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pImportFenceWin32HandleInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pGetWin32HandleInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pGetWin32HandleInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pImportFenceFdInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->ImportFenceFdKHR(device, pImportFenceFdInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pImportFenceFdInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(TraceManager::Get(), device, pGetFdInfo, pFd);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pGetFdInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetFenceFdKHR(device, pGetFdInfo, pFd);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pGetFdInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapStructHandles(pSurfaceInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapStructHandles(pSurfaceInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        EncodeStructPtr(encoder, pSurfaceCapabilities);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapStructHandles(pSurfaceInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapStructHandles(pSurfaceInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount);
        EncodeStructArray(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayProperties2KHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlaneProperties2KHR*               pProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayPlaneProperties2KHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(TraceManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<DisplayKHRWrapper>(&display, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<DisplayKHRWrapper>(&display, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, DisplayKHRWrapper, VkDisplayModeProperties2KHR>(physicalDevice, display, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(TraceManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
    VkDisplayPlaneCapabilities2KHR*             pCapabilities)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(TraceManager::Get(), physicalDevice, pDisplayPlaneInfo, pCapabilities);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapStructHandles(pDisplayPlaneInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapStructHandles(pDisplayPlaneInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pDisplayPlaneInfo);
        EncodeStructPtr(encoder, pCapabilities);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->GetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->GetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->GetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SamplerYcbcrConversionWrapper>(device, NoParentWrapper::kHandleValue, pYcbcrConversion, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pYcbcrConversion);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(ycbcrConversion);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<SamplerYcbcrConversionWrapper>(ycbcrConversion, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SamplerYcbcrConversionWrapper>(&ycbcrConversion, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SamplerYcbcrConversionWrapper>(&ycbcrConversion, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(TraceManager::Get(), device, ycbcrConversion, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->BindBufferMemory2KHR(device, bindInfoCount, pBindInfos);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructArrayHandles(pBindInfos, bindInfoCount, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->BindImageMemory2KHR(device, bindInfoCount, pBindInfos);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructArrayHandles(pBindInfos, bindInfoCount, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->GetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndirectCountKHRHandles, buffer, countBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);
    UnwrapHandle<BufferWrapper>(&countBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&countBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndexedIndirectCountKHRHandles, buffer, countBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);
    UnwrapHandle<BufferWrapper>(&countBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&countBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT(
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pCallback);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, DebugReportCallbackEXTWrapper>(instance, NoParentWrapper::kHandleValue, pCallback, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pCallback);
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
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeHandleIdValue(callback);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DebugReportCallbackEXTWrapper>(callback, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);
    UnwrapHandle<DebugReportCallbackEXTWrapper>(&callback, handle_store);

    TraceManager::Get()->GetInstanceTable(instance)->DestroyDebugReportCallbackEXT(instance, callback, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);
    RewrapHandle<DebugReportCallbackEXTWrapper>(&callback, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(TraceManager::Get(), instance, callback, pAllocator);
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
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(object);
        encoder->EncodeSizeTValue(location);
        encoder->EncodeInt32Value(messageCode);
        encoder->EncodeString(pLayerPrefix);
        encoder->EncodeString(pMessage);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    TraceManager::Get()->GetInstanceTable(instance)->DebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(TraceManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectTagInfoEXT*        pTagInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(TraceManager::Get(), device, pTagInfo);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->DebugMarkerSetObjectTagEXT(device, pTagInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->DebugMarkerSetObjectNameEXT(device, pNameInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(TraceManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(TraceManager::Get(), commandBuffer);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleIdArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pSizes, bindingCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindTransformFeedbackBuffersEXTHandles, bindingCount, pBuffers);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandles<BufferWrapper>(&pBuffers, bindingCount, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandles<BufferWrapper>(&pBuffers, bindingCount, &handle_array_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstCounterBuffer);
        encoder->EncodeUInt32Value(counterBufferCount);
        encoder->EncodeHandleIdArray(pCounterBuffers, counterBufferCount);
        encoder->EncodeVkDeviceSizeArray(pCounterBufferOffsets, counterBufferCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginTransformFeedbackEXTHandles, counterBufferCount, pCounterBuffers);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandles<BufferWrapper>(&pCounterBuffers, counterBufferCount, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandles<BufferWrapper>(&pCounterBuffers, counterBufferCount, &handle_array_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstCounterBuffer);
        encoder->EncodeUInt32Value(counterBufferCount);
        encoder->EncodeHandleIdArray(pCounterBuffers, counterBufferCount);
        encoder->EncodeVkDeviceSizeArray(pCounterBufferOffsets, counterBufferCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdEndTransformFeedbackEXTHandles, counterBufferCount, pCounterBuffers);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandles<BufferWrapper>(&pCounterBuffers, counterBufferCount, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandles<BufferWrapper>(&pCounterBuffers, counterBufferCount, &handle_array_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeUInt32Value(index);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginQueryIndexedEXTHandles, queryPool);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeUInt32Value(index);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdEndQueryIndexedEXTHandles, queryPool);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstInstance);
        encoder->EncodeHandleIdValue(counterBuffer);
        encoder->EncodeVkDeviceSizeValue(counterBufferOffset);
        encoder->EncodeUInt32Value(counterOffset);
        encoder->EncodeUInt32Value(vertexStride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndirectByteCountEXTHandles, counterBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&counterBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&counterBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(TraceManager::Get(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

VKAPI_ATTR uint32_t VKAPI_CALL GetImageViewHandleNVX(
    VkDevice                                    device,
    const VkImageViewHandleInfoNVX*             pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);

    uint32_t result = TraceManager::Get()->GetDeviceTable(device)->GetImageViewHandleNVX(device, pInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageViewHandleNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(TraceManager::Get(), result, device, pInfo);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndirectCountAMDHandles, buffer, countBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);
    UnwrapHandle<BufferWrapper>(&countBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&countBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawIndexedIndirectCountAMDHandles, buffer, countBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);
    UnwrapHandle<BufferWrapper>(&countBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&countBuffer, &handle_store_iter);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(TraceManager::Get(), device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineWrapper>(&pipeline, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineWrapper>(&pipeline, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetShaderInfoAMD);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        encoder->EncodeEnumValue(shaderStage);
        encoder->EncodeEnumValue(infoType);
        encoder->EncodeSizeTPtr(pInfoSize);
        encoder->EncodeVoidArray(pInfo, (pInfoSize != nullptr) ? (*pInfoSize) : 0);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateStreamDescriptorSurfaceGGP(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(TraceManager::Get(), physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeFlagsValue(externalHandleType);
        EncodeStructPtr(encoder, pExternalImageFormatProperties);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(TraceManager::Get(), device, memory, handleType, pHandle);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DeviceMemoryWrapper>(&memory, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetMemoryWin32HandleNV(device, memory, handleType, pHandle);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DeviceMemoryWrapper>(&memory, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeFlagsValue(handleType);
        encoder->EncodeVoidPtrPtr(pHandle);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateViSurfaceNN);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pConditionalRenderingBegin);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBeginConditionalRenderingEXTHandles, pConditionalRenderingBegin);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapStructHandles(pConditionalRenderingBegin, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapStructHandles(pConditionalRenderingBegin, &handle_store_iter, &handle_array_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(TraceManager::Get(), commandBuffer, pConditionalRenderingBegin);
}

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(TraceManager::Get(), commandBuffer);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndConditionalRenderingEXT(commandBuffer);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdProcessCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCmdProcessCommandsInfoNVX*          pProcessCommandsInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(TraceManager::Get(), commandBuffer, pProcessCommandsInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pProcessCommandsInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdProcessCommandsNVXHandles, pProcessCommandsInfo);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapStructHandles(pProcessCommandsInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdProcessCommandsNVX(commandBuffer, pProcessCommandsInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapStructHandles(pProcessCommandsInfo, &handle_store_iter, &handle_array_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(TraceManager::Get(), commandBuffer, pProcessCommandsInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdReserveSpaceForCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCmdReserveSpaceForCommandsInfoNVX*  pReserveSpaceInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(TraceManager::Get(), commandBuffer, pReserveSpaceInfo);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pReserveSpaceInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdReserveSpaceForCommandsNVXHandles, pReserveSpaceInfo);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapStructHandles(pReserveSpaceInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdReserveSpaceForCommandsNVX(commandBuffer, pReserveSpaceInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapStructHandles(pReserveSpaceInfo, &handle_store_iter, &handle_array_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(TraceManager::Get(), commandBuffer, pReserveSpaceInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    const VkIndirectCommandsLayoutCreateInfoNVX* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkIndirectCommandsLayoutNVX*                pIndirectCommandsLayout)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateIndirectCommandsLayoutNVX(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, IndirectCommandsLayoutNVXWrapper>(device, NoParentWrapper::kHandleValue, pIndirectCommandsLayout, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pIndirectCommandsLayout);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, IndirectCommandsLayoutNVXWrapper, VkIndirectCommandsLayoutCreateInfoNVX>(result, device, pIndirectCommandsLayout, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNVX                 indirectCommandsLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(TraceManager::Get(), device, indirectCommandsLayout, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(indirectCommandsLayout);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<IndirectCommandsLayoutNVXWrapper>(indirectCommandsLayout, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<IndirectCommandsLayoutNVXWrapper>(&indirectCommandsLayout, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<IndirectCommandsLayoutNVXWrapper>(&indirectCommandsLayout, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(TraceManager::Get(), device, indirectCommandsLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateObjectTableNVX(
    VkDevice                                    device,
    const VkObjectTableCreateInfoNVX*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkObjectTableNVX*                           pObjectTable)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pObjectTable);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateObjectTableNVX(device, pCreateInfo, pAllocator, pObjectTable);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ObjectTableNVXWrapper>(device, NoParentWrapper::kHandleValue, pObjectTable, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateObjectTableNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pObjectTable);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, ObjectTableNVXWrapper, VkObjectTableCreateInfoNVX>(result, device, pObjectTable, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pObjectTable);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyObjectTableNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(TraceManager::Get(), device, objectTable, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyObjectTableNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(objectTable);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<ObjectTableNVXWrapper>(objectTable, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ObjectTableNVXWrapper>(&objectTable, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyObjectTableNVX(device, objectTable, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ObjectTableNVXWrapper>(&objectTable, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(TraceManager::Get(), device, objectTable, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL UnregisterObjectsNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    uint32_t                                    objectCount,
    const VkObjectEntryTypeNVX*                 pObjectEntryTypes,
    const uint32_t*                             pObjectIndices)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(TraceManager::Get(), device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ObjectTableNVXWrapper>(&objectTable, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->UnregisterObjectsNVX(device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ObjectTableNVXWrapper>(&objectTable, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUnregisterObjectsNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(objectTable);
        encoder->EncodeUInt32Value(objectCount);
        encoder->EncodeEnumArray(pObjectEntryTypes, objectCount);
        encoder->EncodeUInt32Array(pObjectIndices, objectCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(TraceManager::Get(), result, device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceGeneratedCommandsPropertiesNVX(
    VkPhysicalDevice                            physicalDevice,
    VkDeviceGeneratedCommandsFeaturesNVX*       pFeatures,
    VkDeviceGeneratedCommandsLimitsNVX*         pLimits)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(TraceManager::Get(), physicalDevice, pFeatures, pLimits);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, pFeatures, pLimits);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        EncodeStructPtr(encoder, pLimits);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(TraceManager::Get(), physicalDevice, pFeatures, pLimits);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewportWScalings, viewportCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(TraceManager::Get(), physicalDevice, display);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<DisplayKHRWrapper>(&display, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->ReleaseDisplayEXT(physicalDevice, display);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<DisplayKHRWrapper>(&display, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkReleaseDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<DisplayKHRWrapper>(&display, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->AcquireXlibDisplayEXT(physicalDevice, dpy, display);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<DisplayKHRWrapper>(&display, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeHandleIdValue(display);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(TraceManager::Get(), physicalDevice, dpy, rrOutput, pDisplay);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DisplayKHRWrapper>(physicalDevice, NoParentWrapper::kHandleValue, pDisplay, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeSizeTValue(rrOutput);
        encoder->EncodeHandleIdPtr(pDisplay);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(TraceManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapHandle<SurfaceKHRWrapper>(&surface, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapHandle<SurfaceKHRWrapper>(&surface, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        EncodeStructPtr(encoder, pSurfaceCapabilities);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DisplayKHRWrapper>(&display, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->DisplayPowerControlEXT(device, display, pDisplayPowerInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DisplayKHRWrapper>(&display, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDisplayPowerControlEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(display);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(TraceManager::Get(), device, pDeviceEventInfo, pAllocator, pFence);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->RegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, FenceWrapper>(device, NoParentWrapper::kHandleValue, pFence, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pDeviceEventInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pFence);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(TraceManager::Get(), device, display, pDisplayEventInfo, pAllocator, pFence);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<DisplayKHRWrapper>(&display, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->RegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<DisplayKHRWrapper>(&display, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, DisplayKHRWrapper, FenceWrapper>(device, display, pFence, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(display);
        EncodeStructPtr(encoder, pDisplayEventInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pFence);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(TraceManager::Get(), device, swapchain, counter, pCounterValue);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SwapchainKHRWrapper>(&swapchain, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SwapchainKHRWrapper>(&swapchain, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeEnumValue(counter);
        encoder->EncodeUInt64Ptr(pCounterValue);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(TraceManager::Get(), device, swapchain, pDisplayTimingProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SwapchainKHRWrapper>(&swapchain, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SwapchainKHRWrapper>(&swapchain, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        EncodeStructPtr(encoder, pDisplayTimingProperties);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(TraceManager::Get(), device, swapchain, pPresentationTimingCount, pPresentationTimings);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SwapchainKHRWrapper>(&swapchain, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SwapchainKHRWrapper>(&swapchain, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt32Ptr(pPresentationTimingCount);
        EncodeStructArray(encoder, pPresentationTimings, (pPresentationTimingCount != nullptr) ? (*pPresentationTimingCount) : 0);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstDiscardRectangle);
        encoder->EncodeUInt32Value(discardRectangleCount);
        EncodeStructArray(encoder, pDiscardRectangles, discardRectangleCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        encoder->EncodeHandleIdArray(pSwapchains, swapchainCount);
        EncodeStructArray(encoder, pMetadata, swapchainCount);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandles<SwapchainKHRWrapper>(&pSwapchains, swapchainCount, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->SetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandles<SwapchainKHRWrapper>(&pSwapchains, swapchainCount, &handle_array_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(TraceManager::Get(), device, swapchainCount, pSwapchains, pMetadata);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK(
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->SetDebugUtilsObjectNameEXT(device, pNameInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->SetDebugUtilsObjectTagEXT(device, pTagInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
        encoder->EncodeHandleIdValue(queue);
        EncodeStructPtr(encoder, pLabelInfo);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<QueueWrapper>(&queue, handle_store);

    TraceManager::Get()->GetDeviceTable(queue)->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<QueueWrapper>(&queue, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), queue);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<QueueWrapper>(&queue, handle_store);

    TraceManager::Get()->GetDeviceTable(queue)->QueueEndDebugUtilsLabelEXT(queue);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<QueueWrapper>(&queue, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(queue);
        EncodeStructPtr(encoder, pLabelInfo);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<QueueWrapper>(&queue, handle_store);

    TraceManager::Get()->GetDeviceTable(queue)->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<QueueWrapper>(&queue, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pLabelInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), commandBuffer);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pLabelInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(TraceManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pMessenger);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, DebugUtilsMessengerEXTWrapper>(instance, NoParentWrapper::kHandleValue, pMessenger, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pMessenger);
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
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeHandleIdValue(messenger);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<DebugUtilsMessengerEXTWrapper>(messenger, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);
    UnwrapHandle<DebugUtilsMessengerEXTWrapper>(&messenger, handle_store);

    TraceManager::Get()->GetInstanceTable(instance)->DestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);
    RewrapHandle<DebugUtilsMessengerEXTWrapper>(&messenger, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(TraceManager::Get(), instance, messenger, pAllocator);
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
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeEnumValue(messageSeverity);
        encoder->EncodeFlagsValue(messageTypes);
        EncodeStructPtr(encoder, pCallbackData);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    TraceManager::Get()->GetInstanceTable(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(TraceManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);
}

VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                    device,
    const struct AHardwareBuffer*               buffer,
    VkAndroidHardwareBufferPropertiesANDROID*   pProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(TraceManager::Get(), device, buffer, pProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeVoidPtr(buffer);
        EncodeStructPtr(encoder, pProperties);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(TraceManager::Get(), device, pInfo, pBuffer);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVoidPtrPtr(pBuffer);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pSampleLocationsInfo);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(TraceManager::Get(), commandBuffer, pSampleLocationsInfo);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    VkMultisamplePropertiesEXT*                 pMultisampleProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(TraceManager::Get(), physicalDevice, samples, pMultisampleProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(TraceManager::Get(), device, image, pProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ImageWrapper>(&image, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ImageWrapper>(&image, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        EncodeStructPtr(encoder, pProperties);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pValidationCache);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ValidationCacheEXTWrapper>(device, NoParentWrapper::kHandleValue, pValidationCache, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateValidationCacheEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pValidationCache);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(validationCache);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<ValidationCacheEXTWrapper>(validationCache, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ValidationCacheEXTWrapper>(&validationCache, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyValidationCacheEXT(device, validationCache, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ValidationCacheEXTWrapper>(&validationCache, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(TraceManager::Get(), device, validationCache, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const VkValidationCacheEXT*                 pSrcCaches)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(TraceManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ValidationCacheEXTWrapper>(&dstCache, handle_store);
    UnwrapHandles<ValidationCacheEXTWrapper>(&pSrcCaches, srcCacheCount, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->MergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ValidationCacheEXTWrapper>(&dstCache, &handle_store_iter);
    RewrapHandles<ValidationCacheEXTWrapper>(&pSrcCaches, srcCacheCount, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMergeValidationCachesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleIdArray(pSrcCaches, srcCacheCount);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(TraceManager::Get(), device, validationCache, pDataSize, pData);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<ValidationCacheEXTWrapper>(&validationCache, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetValidationCacheDataEXT(device, validationCache, pDataSize, pData);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<ValidationCacheEXTWrapper>(&validationCache, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(validationCache);
        encoder->EncodeSizeTPtr(pDataSize);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(imageView);
        encoder->EncodeEnumValue(imageLayout);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBindShadingRateImageNVHandles, imageView);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<ImageViewWrapper>(&imageView, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<ImageViewWrapper>(&imageView, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pShadingRatePalettes, viewportCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(sampleOrderType);
        encoder->EncodeUInt32Value(customSampleOrderCount);
        EncodeStructArray(encoder, pCustomSampleOrders, customSampleOrderCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(TraceManager::Get(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureNV(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoNV*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureNV*                  pAccelerationStructure)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(TraceManager::Get(), device, pCreateInfo, pAllocator, pAccelerationStructure);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pCreateInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pCreateInfo, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, AccelerationStructureNVWrapper>(device, NoParentWrapper::kHandleValue, pAccelerationStructure, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pAccelerationStructure);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkDevice, AccelerationStructureNVWrapper, VkAccelerationStructureCreateInfoNV>(result, device, pAccelerationStructure, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(TraceManager::Get(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV(
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    const VkAllocationCallbacks*                pAllocator)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(TraceManager::Get(), device, accelerationStructure, pAllocator);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(accelerationStructure);
        EncodeStructPtr(encoder, pAllocator);
        TraceManager::Get()->EndDestroyApiCallTrace<AccelerationStructureNVWrapper>(accelerationStructure, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<AccelerationStructureNVWrapper>(&accelerationStructure, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->DestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<AccelerationStructureNVWrapper>(&accelerationStructure, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(TraceManager::Get(), device, accelerationStructure, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV(
    VkDevice                                    device,
    const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo,
    VkMemoryRequirements2KHR*                   pMemoryRequirements)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);

    TraceManager::Get()->GetDeviceTable(device)->GetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL BindAccelerationStructureMemoryNV(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindAccelerationStructureMemoryInfoNV* pBindInfos)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->BindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructArrayHandles(pBindInfos, bindInfoCount, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
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
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(TraceManager::Get(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeHandleIdValue(instanceData);
        encoder->EncodeVkDeviceSizeValue(instanceOffset);
        encoder->EncodeVkBool32Value(update);
        encoder->EncodeHandleIdValue(dst);
        encoder->EncodeHandleIdValue(src);
        encoder->EncodeHandleIdValue(scratch);
        encoder->EncodeVkDeviceSizeValue(scratchOffset);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdBuildAccelerationStructureNVHandles, pInfo, instanceData, dst, src, scratch);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);
    UnwrapHandle<BufferWrapper>(&instanceData, handle_store);
    UnwrapHandle<AccelerationStructureNVWrapper>(&dst, handle_store);
    UnwrapHandle<AccelerationStructureNVWrapper>(&src, handle_store);
    UnwrapHandle<BufferWrapper>(&scratch, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);
    RewrapHandle<BufferWrapper>(&instanceData, &handle_store_iter);
    RewrapHandle<AccelerationStructureNVWrapper>(&dst, &handle_store_iter);
    RewrapHandle<AccelerationStructureNVWrapper>(&src, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&scratch, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(TraceManager::Get(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeNV           mode)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(TraceManager::Get(), commandBuffer, dst, src, mode);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dst);
        encoder->EncodeHandleIdValue(src);
        encoder->EncodeEnumValue(mode);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdCopyAccelerationStructureNVHandles, dst, src);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<AccelerationStructureNVWrapper>(&dst, handle_store);
    UnwrapHandle<AccelerationStructureNVWrapper>(&src, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<AccelerationStructureNVWrapper>(&dst, &handle_store_iter);
    RewrapHandle<AccelerationStructureNVWrapper>(&src, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(raygenShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(raygenShaderBindingOffset);
        encoder->EncodeHandleIdValue(missShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(missShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(missShaderBindingStride);
        encoder->EncodeHandleIdValue(hitShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(hitShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(hitShaderBindingStride);
        encoder->EncodeHandleIdValue(callableShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(callableShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(callableShaderBindingStride);
        encoder->EncodeUInt32Value(width);
        encoder->EncodeUInt32Value(height);
        encoder->EncodeUInt32Value(depth);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdTraceRaysNVHandles, raygenShaderBindingTableBuffer, missShaderBindingTableBuffer, hitShaderBindingTableBuffer, callableShaderBindingTableBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&raygenShaderBindingTableBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&missShaderBindingTableBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&hitShaderBindingTableBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&callableShaderBindingTableBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&raygenShaderBindingTableBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&missShaderBindingTableBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&hitShaderBindingTableBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&callableShaderBindingTableBuffer, &handle_store_iter);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineCacheWrapper>(&pipelineCache, handle_store);
    UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineCacheWrapper>(&pipelineCache, &handle_store_iter);
    RewrapStructArrayHandles(pCreateInfos, createInfoCount, &handle_store_iter, &handle_array_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandles<DeviceWrapper, PipelineCacheWrapper, PipelineWrapper>(device, pipelineCache, pPipelines, createInfoCount, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdArray(pPipelines, createInfoCount);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndGroupCreateApiCallTrace<VkDevice, VkPipelineCache, PipelineWrapper, VkRayTracingPipelineCreateInfoNV>(result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(TraceManager::Get(), device, pipeline, firstGroup, groupCount, dataSize, pData);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineWrapper>(&pipeline, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetRayTracingShaderGroupHandlesNV(device, pipeline, firstGroup, groupCount, dataSize, pData);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineWrapper>(&pipeline, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        encoder->EncodeUInt32Value(firstGroup);
        encoder->EncodeUInt32Value(groupCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(TraceManager::Get(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetAccelerationStructureHandleNV(
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    size_t                                      dataSize,
    void*                                       pData)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(TraceManager::Get(), device, accelerationStructure, dataSize, pData);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<AccelerationStructureNVWrapper>(&accelerationStructure, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<AccelerationStructureNVWrapper>(&accelerationStructure, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(accelerationStructure);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(TraceManager::Get(), result, device, accelerationStructure, dataSize, pData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(TraceManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(accelerationStructureCount);
        encoder->EncodeHandleIdArray(pAccelerationStructures, accelerationStructureCount);
        encoder->EncodeEnumValue(queryType);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdWriteAccelerationStructuresPropertiesNVHandles, accelerationStructureCount, pAccelerationStructures, queryPool);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandles<AccelerationStructureNVWrapper>(&pAccelerationStructures, accelerationStructureCount, handle_array_store, handle_unwrap_memory);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandles<AccelerationStructureNVWrapper>(&pAccelerationStructures, accelerationStructureCount, &handle_array_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(TraceManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

VKAPI_ATTR VkResult VKAPI_CALL CompileDeferredNV(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    shader)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(TraceManager::Get(), device, pipeline, shader);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<PipelineWrapper>(&pipeline, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->CompileDeferredNV(device, pipeline, shader);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<PipelineWrapper>(&pipeline, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCompileDeferredNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(TraceManager::Get(), device, handleType, pHostPointer, pMemoryHostPointerProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(pHostPointer);
        EncodeStructPtr(encoder, pMemoryHostPointerProperties);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeUInt32Value(marker);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdWriteBufferMarkerAMDHandles, dstBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&dstBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&dstBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(TraceManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pTimeDomainCount,
    VkTimeDomainEXT*                            pTimeDomains)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(TraceManager::Get(), physicalDevice, pTimeDomainCount, pTimeDomains);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pTimeDomainCount);
        encoder->EncodeEnumArray(pTimeDomains, (pTimeDomainCount != nullptr) ? (*pTimeDomainCount) : 0);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(TraceManager::Get(), device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(timestampCount);
        EncodeStructArray(encoder, pTimestampInfos, timestampCount);
        encoder->EncodeUInt64Array(pTimestamps, timestampCount);
        encoder->EncodeUInt64Ptr(pMaxDeviation);
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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(taskCount);
        encoder->EncodeUInt32Value(firstTask);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawMeshTasksIndirectNVHandles, buffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder, TrackCmdDrawMeshTasksIndirectCountNVHandles, buffer, countBuffer);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);
    UnwrapHandle<BufferWrapper>(&buffer, handle_store);
    UnwrapHandle<BufferWrapper>(&countBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&buffer, &handle_store_iter);
    RewrapHandle<BufferWrapper>(&countBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstExclusiveScissor);
        encoder->EncodeUInt32Value(exclusiveScissorCount);
        EncodeStructArray(encoder, pExclusiveScissors, exclusiveScissorCount);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

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
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeVoidPtr(pCheckpointMarker);
        TraceManager::Get()->EndCommandApiCallTrace(commandBuffer, encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<CommandBufferWrapper>(&commandBuffer, handle_store);

    TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetCheckpointNV(commandBuffer, pCheckpointMarker);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<CommandBufferWrapper>(&commandBuffer, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(TraceManager::Get(), commandBuffer, pCheckpointMarker);
}

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV(
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointDataNV*                         pCheckpointData)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(TraceManager::Get(), queue, pCheckpointDataCount, pCheckpointData);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<QueueWrapper>(&queue, handle_store);

    TraceManager::Get()->GetDeviceTable(queue)->GetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<QueueWrapper>(&queue, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Ptr(pCheckpointDataCount);
        EncodeStructArray(encoder, pCheckpointData, (pCheckpointDataCount != nullptr) ? (*pCheckpointDataCount) : 0);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(TraceManager::Get(), queue, pCheckpointDataCount, pCheckpointData);
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapChain);
        encoder->EncodeVkBool32Value(localDimmingEnable);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SwapchainKHRWrapper>(&swapChain, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->SetLocalDimmingAMD(device, swapChain, localDimmingEnable);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SwapchainKHRWrapper>(&swapChain, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(TraceManager::Get(), device, swapChain, localDimmingEnable);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImagePipeSurfaceFUCHSIA(
    VkInstance                                  instance,
    const VkImagePipeSurfaceCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkMetalSurfaceCreateInfoEXT>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressEXT(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfoEXT*         pInfo)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(TraceManager::Get(), device, pInfo);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkDeviceAddress result = TraceManager::Get()->GetDeviceTable(device)->GetBufferDeviceAddressEXT(device, pInfo);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVkDeviceAddressValue(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(TraceManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkCooperativeMatrixPropertiesNV*            pProperties)
{
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, pPropertyCount, pProperties);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(TraceManager::Get(), physicalDevice, pCombinationCount, pCombinations);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, pCombinationCount, pCombinations);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pCombinationCount);
        EncodeStructArray(encoder, pCombinations, (pCombinationCount != nullptr) ? (*pCombinationCount) : 0);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(TraceManager::Get(), physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<PhysicalDeviceWrapper>(&physicalDevice, handle_store);
    UnwrapStructHandles(pSurfaceInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<PhysicalDeviceWrapper>(&physicalDevice, &handle_store_iter);
    RewrapStructHandles(pSurfaceInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        encoder->EncodeUInt32Ptr(pPresentModeCount);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SwapchainKHRWrapper>(&swapchain, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->AcquireFullScreenExclusiveModeEXT(device, swapchain);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SwapchainKHRWrapper>(&swapchain, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
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

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<SwapchainKHRWrapper>(&swapchain, handle_store);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->ReleaseFullScreenExclusiveModeEXT(device, swapchain);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<SwapchainKHRWrapper>(&swapchain, &handle_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(TraceManager::Get(), device, pSurfaceInfo, pModes);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    auto handle_array_store = TraceManager::Get()->GetHandleArrayStore();
    auto handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapStructHandles(pSurfaceInfo, handle_store, handle_array_store, handle_unwrap_memory);

    VkResult result = TraceManager::Get()->GetDeviceTable(device)->GetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);

    auto handle_store_iter = handle_store->cbegin();
    auto handle_array_store_iter = handle_array_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapStructHandles(pSurfaceInfo, &handle_store_iter, &handle_array_store_iter);

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pSurfaceInfo);
        encoder->EncodeFlagsPtr(pModes);
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
    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<InstanceWrapper>(&instance, handle_store);

    VkResult result = TraceManager::Get()->GetInstanceTable(instance)->CreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<InstanceWrapper>(&instance, &handle_store_iter);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, TraceManager::GetUniqueId);
    }

    auto encoder = TraceManager::Get()->BeginTrackedApiCallTrace(format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndCreateApiCallTrace<VkInstance, SurfaceKHRWrapper, VkHeadlessSurfaceCreateInfoEXT>(result, instance, pSurface, pCreateInfo, encoder);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
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
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }

    auto handle_store = TraceManager::Get()->GetHandleStore();
    UnwrapHandle<DeviceWrapper>(&device, handle_store);
    UnwrapHandle<QueryPoolWrapper>(&queryPool, handle_store);

    TraceManager::Get()->GetDeviceTable(device)->ResetQueryPoolEXT(device, queryPool, firstQuery, queryCount);

    auto handle_store_iter = handle_store->cbegin();
    RewrapHandle<DeviceWrapper>(&device, &handle_store_iter);
    RewrapHandle<QueryPoolWrapper>(&queryPool, &handle_store_iter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(TraceManager::Get(), device, queryPool, firstQuery, queryCount);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
