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

#include "generated/generated_vulkan_api_call_encoders.h"

#include "encode/custom_vulkan_encoder_commands.h"
#include "encode/custom_vulkan_array_size_2d.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_capture_manager.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "format/api_call_id.h"
#include "generated/generated_vulkan_command_buffer_util.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireUniqueStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(VulkanCaptureManager::Get(), pCreateInfo, pAllocator, pInstance);

    VkResult result = VulkanCaptureManager::OverrideCreateInstance(pCreateInfo, pAllocator, pInstance);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateInstance);
    if (encoder)
    {
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pInstance, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<const void*, InstanceWrapper, VkInstanceCreateInfo>(result, nullptr, pInstance, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(VulkanCaptureManager::Get(), result, pCreateInfo, pAllocator, pInstance);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyInstance(
    VkInstance                                  instance,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(VulkanCaptureManager::Get(), instance, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyInstance);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<InstanceWrapper>(instance);
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    GetInstanceTable(instance)->DestroyInstance(instance_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(VulkanCaptureManager::Get(), instance, pAllocator);

    DestroyWrappedHandle<InstanceWrapper>(instance);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(VulkanCaptureManager::Get(), instance, pPhysicalDeviceCount, pPhysicalDevices);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->EnumeratePhysicalDevices(instance_unwrapped, pPhysicalDeviceCount, pPhysicalDevices);

    if (result >= 0)
    {
        CreateWrappedHandles<InstanceWrapper, NoParentWrapper, PhysicalDeviceWrapper>(instance, NoParentWrapper::kHandleValue, pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceCount, omit_output_data);
        encoder->EncodeHandleArray(pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndGroupCreateApiCallCapture<VkInstance, void*, PhysicalDeviceWrapper, void>(result, instance, nullptr, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0, pPhysicalDevices, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(VulkanCaptureManager::Get(), result, instance, pPhysicalDeviceCount, pPhysicalDevices);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFeatures);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures(physicalDevice_unwrapped, pFeatures);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, format, pFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties(physicalDevice_unwrapped, format, pFormatProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        EncodeStructPtr(encoder, pFormatProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, format, pFormatProperties);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties(physicalDevice_unwrapped, format, type, tiling, usage, flags, pImageFormatProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties);
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
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties(physicalDevice_unwrapped, pProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(physicalDevice_unwrapped, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        EncodeStructArray(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pMemoryProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties(physicalDevice_unwrapped, pMemoryProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pMemoryProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pCreateInfo, pAllocator, pDevice);

    VkResult result = VulkanCaptureManager::Get()->OverrideCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDevice);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDevice, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkPhysicalDevice, DeviceWrapper, VkDeviceCreateInfo>(result, physicalDevice, pDevice, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pCreateInfo, pAllocator, pDevice);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDevice(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(VulkanCaptureManager::Get(), device, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyDevice);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<DeviceWrapper>(device);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->DestroyDevice(device_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(VulkanCaptureManager::Get(), device, pAllocator);

    DestroyWrappedHandle<DeviceWrapper>(device);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(VulkanCaptureManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->GetDeviceQueue(device_unwrapped, queueFamilyIndex, queueIndex, pQueue);

    CreateWrappedHandle<DeviceWrapper, NoParentWrapper, QueueWrapper>(device, NoParentWrapper::kHandleValue, pQueue, VulkanCaptureManager::GetUniqueId);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceQueue);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeUInt32Value(queueIndex);
        encoder->EncodeHandlePtr(pQueue);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, QueueWrapper, void>(VK_SUCCESS, device, pQueue, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(VulkanCaptureManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(VulkanCaptureManager::Get(), queue, submitCount, pSubmits, fence);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);
    const VkSubmitInfo* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    VkResult result = GetDeviceTable(queue)->QueueSubmit(queue_unwrapped, submitCount, pSubmits_unwrapped, fence_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkQueueSubmit);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Value(submitCount);
        EncodeStructArray(encoder, pSubmits, submitCount);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(VulkanCaptureManager::Get(), result, queue, submitCount, pSubmits, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(
    VkQueue                                     queue)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(VulkanCaptureManager::Get(), queue);

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    VkResult result = GetDeviceTable(queue)->QueueWaitIdle(queue_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkQueueWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(VulkanCaptureManager::Get(), result, queue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(
    VkDevice                                    device)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(VulkanCaptureManager::Get(), device);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->DeviceWaitIdle(device_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkDeviceWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(VulkanCaptureManager::Get(), result, device);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(VulkanCaptureManager::Get(), device, pAllocateInfo, pAllocator, pMemory);

    VkResult result = VulkanCaptureManager::Get()->OverrideAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkAllocateMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pMemory, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, DeviceMemoryWrapper, VkMemoryAllocateInfo>(result, device, pMemory, pAllocateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(VulkanCaptureManager::Get(), result, device, pAllocateInfo, pAllocator, pMemory);

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(VulkanCaptureManager::Get(), device, memory, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkFreeMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<DeviceMemoryWrapper>(memory);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    GetDeviceTable(device)->FreeMemory(device_unwrapped, memory_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(VulkanCaptureManager::Get(), device, memory, pAllocator);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(VulkanCaptureManager::Get(), device, memory, offset, size, flags, ppData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    VkResult result = GetDeviceTable(device)->MapMemory(device_unwrapped, memory_unwrapped, offset, size, flags, ppData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkMapMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeVoidPtrPtr(ppData, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(VulkanCaptureManager::Get(), result, device, memory, offset, size, flags, ppData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(VulkanCaptureManager::Get(), device, memory);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkUnmapMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    GetDeviceTable(device)->UnmapMemory(device_unwrapped, memory_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(VulkanCaptureManager::Get(), device, memory);
}

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(VulkanCaptureManager::Get(), device, memoryRangeCount, pMemoryRanges);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMappedMemoryRange* pMemoryRanges_unwrapped = UnwrapStructArrayHandles(pMemoryRanges, memoryRangeCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->FlushMappedMemoryRanges(device_unwrapped, memoryRangeCount, pMemoryRanges_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        EncodeStructArray(encoder, pMemoryRanges, memoryRangeCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(VulkanCaptureManager::Get(), result, device, memoryRangeCount, pMemoryRanges);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(VulkanCaptureManager::Get(), device, memoryRangeCount, pMemoryRanges);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMappedMemoryRange* pMemoryRanges_unwrapped = UnwrapStructArrayHandles(pMemoryRanges, memoryRangeCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->InvalidateMappedMemoryRanges(device_unwrapped, memoryRangeCount, pMemoryRanges_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        EncodeStructArray(encoder, pMemoryRanges, memoryRangeCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(VulkanCaptureManager::Get(), result, device, memoryRangeCount, pMemoryRanges);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize*                               pCommittedMemoryInBytes)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(VulkanCaptureManager::Get(), device, memory, pCommittedMemoryInBytes);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    GetDeviceTable(device)->GetDeviceMemoryCommitment(device_unwrapped, memory_unwrapped, pCommittedMemoryInBytes);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizePtr(pCommittedMemoryInBytes);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(VulkanCaptureManager::Get(), device, memory, pCommittedMemoryInBytes);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(VulkanCaptureManager::Get(), device, buffer, memory, memoryOffset);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    VkResult result = GetDeviceTable(device)->BindBufferMemory(device_unwrapped, buffer_unwrapped, memory_unwrapped, memoryOffset);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkBindBufferMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(VulkanCaptureManager::Get(), result, device, buffer, memory, memoryOffset);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(VulkanCaptureManager::Get(), device, image, memory, memoryOffset);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    VkResult result = GetDeviceTable(device)->BindImageMemory(device_unwrapped, image_unwrapped, memory_unwrapped, memoryOffset);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkBindImageMemory);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(VulkanCaptureManager::Get(), result, device, image, memory, memoryOffset);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, buffer, pMemoryRequirements);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(device)->GetBufferMemoryRequirements(device_unwrapped, buffer_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(buffer);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, buffer, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, image, pMemoryRequirements);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(device)->GetImageMemoryRequirements(device_unwrapped, image_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, image, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements*            pSparseMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(device)->GetImageSparseMemoryRequirements(device_unwrapped, image_unwrapped, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(physicalDevice_unwrapped, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties);
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
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse(
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const VkBindSparseInfo*                     pBindInfo,
    VkFence                                     fence)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(VulkanCaptureManager::Get(), queue, bindInfoCount, pBindInfo, fence);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);
    const VkBindSparseInfo* pBindInfo_unwrapped = UnwrapStructArrayHandles(pBindInfo, bindInfoCount, handle_unwrap_memory);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    VkResult result = GetDeviceTable(queue)->QueueBindSparse(queue_unwrapped, bindInfoCount, pBindInfo_unwrapped, fence_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkQueueBindSparse);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfo, bindInfoCount);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(VulkanCaptureManager::Get(), result, queue, bindInfoCount, pBindInfo, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pFence);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateFence(device_unwrapped, pCreateInfo, pAllocator, pFence);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, FenceWrapper>(device, NoParentWrapper::kHandleValue, pFence, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateFence);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFence, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, FenceWrapper, VkFenceCreateInfo>(result, device, pFence, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(VulkanCaptureManager::Get(), device, fence, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyFence);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(fence);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<FenceWrapper>(fence);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    GetDeviceTable(device)->DestroyFence(device_unwrapped, fence_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(VulkanCaptureManager::Get(), device, fence, pAllocator);

    DestroyWrappedHandle<FenceWrapper>(fence);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(VulkanCaptureManager::Get(), device, fenceCount, pFences);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkFence* pFences_unwrapped = UnwrapHandles<VkFence>(pFences, fenceCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ResetFences(device_unwrapped, fenceCount, pFences_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkResetFences);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleArray(pFences, fenceCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(VulkanCaptureManager::Get(), result, device, fenceCount, pFences);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(
    VkDevice                                    device,
    VkFence                                     fence)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(VulkanCaptureManager::Get(), device, fence);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    VkResult result = GetDeviceTable(device)->GetFenceStatus(device_unwrapped, fence_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetFenceStatus);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(VulkanCaptureManager::Get(), result, device, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(VulkanCaptureManager::Get(), device, fenceCount, pFences, waitAll, timeout);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkFence* pFences_unwrapped = UnwrapHandles<VkFence>(pFences, fenceCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->WaitForFences(device_unwrapped, fenceCount, pFences_unwrapped, waitAll, timeout);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkWaitForFences);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleArray(pFences, fenceCount);
        encoder->EncodeVkBool32Value(waitAll);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(VulkanCaptureManager::Get(), result, device, fenceCount, pFences, waitAll, timeout);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pSemaphore);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateSemaphore(device_unwrapped, pCreateInfo, pAllocator, pSemaphore);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SemaphoreWrapper>(device, NoParentWrapper::kHandleValue, pSemaphore, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateSemaphore);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSemaphore, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, SemaphoreWrapper, VkSemaphoreCreateInfo>(result, device, pSemaphore, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pSemaphore);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(VulkanCaptureManager::Get(), device, semaphore, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroySemaphore);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(semaphore);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<SemaphoreWrapper>(semaphore);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSemaphore semaphore_unwrapped = GetWrappedHandle<VkSemaphore>(semaphore);

    GetDeviceTable(device)->DestroySemaphore(device_unwrapped, semaphore_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(VulkanCaptureManager::Get(), device, semaphore, pAllocator);

    DestroyWrappedHandle<SemaphoreWrapper>(semaphore);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pEvent);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateEvent(device_unwrapped, pCreateInfo, pAllocator, pEvent);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, EventWrapper>(device, NoParentWrapper::kHandleValue, pEvent, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pEvent, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, EventWrapper, VkEventCreateInfo>(result, device, pEvent, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pEvent);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(VulkanCaptureManager::Get(), device, event, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<EventWrapper>(event);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    GetDeviceTable(device)->DestroyEvent(device_unwrapped, event_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(VulkanCaptureManager::Get(), device, event, pAllocator);

    DestroyWrappedHandle<EventWrapper>(event);
}

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(
    VkDevice                                    device,
    VkEvent                                     event)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(VulkanCaptureManager::Get(), device, event);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    VkResult result = GetDeviceTable(device)->GetEventStatus(device_unwrapped, event_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetEventStatus);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(VulkanCaptureManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(VulkanCaptureManager::Get(), device, event);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    VkResult result = GetDeviceTable(device)->SetEvent(device_unwrapped, event_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(VulkanCaptureManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(VulkanCaptureManager::Get(), device, event);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    VkResult result = GetDeviceTable(device)->ResetEvent(device_unwrapped, event_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(event);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(VulkanCaptureManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pQueryPool);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateQueryPool(device_unwrapped, pCreateInfo, pAllocator, pQueryPool);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, QueryPoolWrapper>(device, NoParentWrapper::kHandleValue, pQueryPool, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pQueryPool, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, QueryPoolWrapper, VkQueryPoolCreateInfo>(result, device, pQueryPool, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pQueryPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(VulkanCaptureManager::Get(), device, queryPool, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(queryPool);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<QueryPoolWrapper>(queryPool);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(device)->DestroyQueryPool(device_unwrapped, queryPool_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(VulkanCaptureManager::Get(), device, queryPool, pAllocator);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(VulkanCaptureManager::Get(), device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    VkResult result = GetDeviceTable(device)->GetQueryPoolResults(device_unwrapped, queryPool_unwrapped, firstQuery, queryCount, dataSize, pData, stride, flags);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetQueryPoolResults);
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
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(VulkanCaptureManager::Get(), result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pBuffer);

    VkResult result = VulkanCaptureManager::Get()->OverrideCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pBuffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, BufferWrapper, VkBufferCreateInfo>(result, device, pBuffer, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pBuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(VulkanCaptureManager::Get(), device, buffer, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(buffer);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<BufferWrapper>(buffer);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(device)->DestroyBuffer(device_unwrapped, buffer_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(VulkanCaptureManager::Get(), device, buffer, pAllocator);

    DestroyWrappedHandle<BufferWrapper>(buffer);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pView);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferViewCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateBufferView(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pView);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, BufferViewWrapper>(device, NoParentWrapper::kHandleValue, pView, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateBufferView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pView, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, BufferViewWrapper, VkBufferViewCreateInfo>(result, device, pView, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pView);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(VulkanCaptureManager::Get(), device, bufferView, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyBufferView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(bufferView);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<BufferViewWrapper>(bufferView);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkBufferView bufferView_unwrapped = GetWrappedHandle<VkBufferView>(bufferView);

    GetDeviceTable(device)->DestroyBufferView(device_unwrapped, bufferView_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(VulkanCaptureManager::Get(), device, bufferView, pAllocator);

    DestroyWrappedHandle<BufferViewWrapper>(bufferView);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pImage);

    VkResult result = VulkanCaptureManager::Get()->OverrideCreateImage(device, pCreateInfo, pAllocator, pImage);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pImage, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, ImageWrapper, VkImageCreateInfo>(result, device, pImage, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pImage);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(VulkanCaptureManager::Get(), device, image, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<ImageWrapper>(image);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(device)->DestroyImage(device_unwrapped, image_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(VulkanCaptureManager::Get(), device, image, pAllocator);

    DestroyWrappedHandle<ImageWrapper>(image);
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(VulkanCaptureManager::Get(), device, image, pSubresource, pLayout);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(device)->GetImageSubresourceLayout(device_unwrapped, image_unwrapped, pSubresource, pLayout);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        EncodeStructPtr(encoder, pSubresource);
        EncodeStructPtr(encoder, pLayout);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(VulkanCaptureManager::Get(), device, image, pSubresource, pLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pView);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageViewCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateImageView(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pView);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ImageViewWrapper>(device, NoParentWrapper::kHandleValue, pView, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateImageView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pView, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, ImageViewWrapper, VkImageViewCreateInfo>(result, device, pView, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pView);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(VulkanCaptureManager::Get(), device, imageView, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyImageView);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(imageView);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<ImageViewWrapper>(imageView);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImageView imageView_unwrapped = GetWrappedHandle<VkImageView>(imageView);

    GetDeviceTable(device)->DestroyImageView(device_unwrapped, imageView_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(VulkanCaptureManager::Get(), device, imageView, pAllocator);

    DestroyWrappedHandle<ImageViewWrapper>(imageView);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pShaderModule);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkShaderModuleCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateShaderModule(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pShaderModule);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ShaderModuleWrapper>(device, NoParentWrapper::kHandleValue, pShaderModule, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateShaderModule);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pShaderModule, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, ShaderModuleWrapper, VkShaderModuleCreateInfo>(result, device, pShaderModule, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pShaderModule);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(VulkanCaptureManager::Get(), device, shaderModule, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyShaderModule);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(shaderModule);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<ShaderModuleWrapper>(shaderModule);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkShaderModule shaderModule_unwrapped = GetWrappedHandle<VkShaderModule>(shaderModule);

    GetDeviceTable(device)->DestroyShaderModule(device_unwrapped, shaderModule_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(VulkanCaptureManager::Get(), device, shaderModule, pAllocator);

    DestroyWrappedHandle<ShaderModuleWrapper>(shaderModule);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pPipelineCache);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreatePipelineCache(device_unwrapped, pCreateInfo, pAllocator, pPipelineCache);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PipelineCacheWrapper>(device, NoParentWrapper::kHandleValue, pPipelineCache, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreatePipelineCache);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pPipelineCache, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, PipelineCacheWrapper, VkPipelineCacheCreateInfo>(result, device, pPipelineCache, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pPipelineCache);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(VulkanCaptureManager::Get(), device, pipelineCache, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyPipelineCache);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<PipelineCacheWrapper>(pipelineCache);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);

    GetDeviceTable(device)->DestroyPipelineCache(device_unwrapped, pipelineCache_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(VulkanCaptureManager::Get(), device, pipelineCache, pAllocator);

    DestroyWrappedHandle<PipelineCacheWrapper>(pipelineCache);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(VulkanCaptureManager::Get(), device, pipelineCache, pDataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);

    VkResult result = GetDeviceTable(device)->GetPipelineCacheData(device_unwrapped, pipelineCache_unwrapped, pDataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPipelineCacheData);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeSizeTPtr(pDataSize, omit_output_data);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(VulkanCaptureManager::Get(), result, device, pipelineCache, pDataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL MergePipelineCaches(
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const VkPipelineCache*                      pSrcCaches)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(VulkanCaptureManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache dstCache_unwrapped = GetWrappedHandle<VkPipelineCache>(dstCache);
    const VkPipelineCache* pSrcCaches_unwrapped = UnwrapHandles<VkPipelineCache>(pSrcCaches, srcCacheCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->MergePipelineCaches(device_unwrapped, dstCache_unwrapped, srcCacheCount, pSrcCaches_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkMergePipelineCaches);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleArray(pSrcCaches, srcCacheCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(VulkanCaptureManager::Get(), result, device, dstCache, srcCacheCount, pSrcCaches);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(VulkanCaptureManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);
    const VkGraphicsPipelineCreateInfo* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateGraphicsPipelines(device_unwrapped, pipelineCache_unwrapped, createInfoCount, pCreateInfos_unwrapped, pAllocator, pPipelines);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, PipelineCacheWrapper, PipelineWrapper>(device, pipelineCache, pPipelines, createInfoCount, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateGraphicsPipelines);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleArray(pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndGroupCreateApiCallCapture<VkDevice, VkPipelineCache, PipelineWrapper, VkGraphicsPipelineCreateInfo>(result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(VulkanCaptureManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(VulkanCaptureManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);
    const VkComputePipelineCreateInfo* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateComputePipelines(device_unwrapped, pipelineCache_unwrapped, createInfoCount, pCreateInfos_unwrapped, pAllocator, pPipelines);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, PipelineCacheWrapper, PipelineWrapper>(device, pipelineCache, pPipelines, createInfoCount, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateComputePipelines);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleArray(pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndGroupCreateApiCallCapture<VkDevice, VkPipelineCache, PipelineWrapper, VkComputePipelineCreateInfo>(result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(VulkanCaptureManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(VulkanCaptureManager::Get(), device, pipeline, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyPipeline);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<PipelineWrapper>(pipeline);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    GetDeviceTable(device)->DestroyPipeline(device_unwrapped, pipeline_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(VulkanCaptureManager::Get(), device, pipeline, pAllocator);

    DestroyWrappedHandle<PipelineWrapper>(pipeline);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pPipelineLayout);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkPipelineLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreatePipelineLayout(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pPipelineLayout);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PipelineLayoutWrapper>(device, NoParentWrapper::kHandleValue, pPipelineLayout, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreatePipelineLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pPipelineLayout, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, PipelineLayoutWrapper, VkPipelineLayoutCreateInfo>(result, device, pPipelineLayout, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pPipelineLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(VulkanCaptureManager::Get(), device, pipelineLayout, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyPipelineLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineLayout);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<PipelineLayoutWrapper>(pipelineLayout);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineLayout pipelineLayout_unwrapped = GetWrappedHandle<VkPipelineLayout>(pipelineLayout);

    GetDeviceTable(device)->DestroyPipelineLayout(device_unwrapped, pipelineLayout_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(VulkanCaptureManager::Get(), device, pipelineLayout, pAllocator);

    DestroyWrappedHandle<PipelineLayoutWrapper>(pipelineLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pSampler);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSamplerCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateSampler(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pSampler);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SamplerWrapper>(device, NoParentWrapper::kHandleValue, pSampler, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateSampler);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSampler, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, SamplerWrapper, VkSamplerCreateInfo>(result, device, pSampler, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pSampler);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(VulkanCaptureManager::Get(), device, sampler, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroySampler);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(sampler);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<SamplerWrapper>(sampler);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSampler sampler_unwrapped = GetWrappedHandle<VkSampler>(sampler);

    GetDeviceTable(device)->DestroySampler(device_unwrapped, sampler_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(VulkanCaptureManager::Get(), device, sampler, pAllocator);

    DestroyWrappedHandle<SamplerWrapper>(sampler);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorSetLayout*                      pSetLayout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pSetLayout);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateDescriptorSetLayout(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pSetLayout);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorSetLayoutWrapper>(device, NoParentWrapper::kHandleValue, pSetLayout, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSetLayout, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, DescriptorSetLayoutWrapper, VkDescriptorSetLayoutCreateInfo>(result, device, pSetLayout, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pSetLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(VulkanCaptureManager::Get(), device, descriptorSetLayout, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorSetLayout);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<DescriptorSetLayoutWrapper>(descriptorSetLayout);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorSetLayout descriptorSetLayout_unwrapped = GetWrappedHandle<VkDescriptorSetLayout>(descriptorSetLayout);

    GetDeviceTable(device)->DestroyDescriptorSetLayout(device_unwrapped, descriptorSetLayout_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(VulkanCaptureManager::Get(), device, descriptorSetLayout, pAllocator);

    DestroyWrappedHandle<DescriptorSetLayoutWrapper>(descriptorSetLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pDescriptorPool);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateDescriptorPool(device_unwrapped, pCreateInfo, pAllocator, pDescriptorPool);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorPoolWrapper>(device, NoParentWrapper::kHandleValue, pDescriptorPool, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDescriptorPool, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, DescriptorPoolWrapper, VkDescriptorPoolCreateInfo>(result, device, pDescriptorPool, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(VulkanCaptureManager::Get(), device, descriptorPool, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorPool);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<DescriptorPoolWrapper>(descriptorPool);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorPool descriptorPool_unwrapped = GetWrappedHandle<VkDescriptorPool>(descriptorPool);

    GetDeviceTable(device)->DestroyDescriptorPool(device_unwrapped, descriptorPool_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(VulkanCaptureManager::Get(), device, descriptorPool, pAllocator);

    DestroyWrappedHandle<DescriptorPoolWrapper>(descriptorPool);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(VulkanCaptureManager::Get(), device, descriptorPool, flags);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorPool descriptorPool_unwrapped = GetWrappedHandle<VkDescriptorPool>(descriptorPool);

    VkResult result = GetDeviceTable(device)->ResetDescriptorPool(device_unwrapped, descriptorPool_unwrapped, flags);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkResetDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorPool);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(VulkanCaptureManager::Get(), result, device, descriptorPool, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(
    VkDevice                                    device,
    const VkDescriptorSetAllocateInfo*          pAllocateInfo,
    VkDescriptorSet*                            pDescriptorSets)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(VulkanCaptureManager::Get(), device, pAllocateInfo, pDescriptorSets);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorSetAllocateInfo* pAllocateInfo_unwrapped = UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->AllocateDescriptorSets(device_unwrapped, pAllocateInfo_unwrapped, pDescriptorSets);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, DescriptorPoolWrapper, DescriptorSetWrapper>(device, pAllocateInfo->descriptorPool, pDescriptorSets, pAllocateInfo->descriptorSetCount, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkAllocateDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        encoder->EncodeHandleArray(pDescriptorSets, (pAllocateInfo != nullptr) ? (pAllocateInfo->descriptorSetCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndPoolCreateApiCallCapture<VkDevice, DescriptorSetWrapper, VkDescriptorSetAllocateInfo>(result, device, (pAllocateInfo != nullptr) ? (pAllocateInfo->descriptorSetCount) : 0, pDescriptorSets, pAllocateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(VulkanCaptureManager::Get(), result, device, pAllocateInfo, pDescriptorSets);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(VulkanCaptureManager::Get(), device, descriptorPool, descriptorSetCount, pDescriptorSets);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorPool descriptorPool_unwrapped = GetWrappedHandle<VkDescriptorPool>(descriptorPool);
    const VkDescriptorSet* pDescriptorSets_unwrapped = UnwrapHandles<VkDescriptorSet>(pDescriptorSets, descriptorSetCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->FreeDescriptorSets(device_unwrapped, descriptorPool_unwrapped, descriptorSetCount, pDescriptorSets_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkFreeDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorPool);
        encoder->EncodeUInt32Value(descriptorSetCount);
        encoder->EncodeHandleArray(pDescriptorSets, descriptorSetCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<DescriptorSetWrapper>(descriptorSetCount, pDescriptorSets);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(VulkanCaptureManager::Get(), result, device, descriptorPool, descriptorSetCount, pDescriptorSets);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(VulkanCaptureManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkUpdateDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        EncodeStructArray(encoder, pDescriptorWrites, descriptorWriteCount);
        encoder->EncodeUInt32Value(descriptorCopyCount);
        EncodeStructArray(encoder, pDescriptorCopies, descriptorCopyCount);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkWriteDescriptorSet* pDescriptorWrites_unwrapped = UnwrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, handle_unwrap_memory);
    const VkCopyDescriptorSet* pDescriptorCopies_unwrapped = UnwrapStructArrayHandles(pDescriptorCopies, descriptorCopyCount, handle_unwrap_memory);

    GetDeviceTable(device)->UpdateDescriptorSets(device_unwrapped, descriptorWriteCount, pDescriptorWrites_unwrapped, descriptorCopyCount, pDescriptorCopies_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(VulkanCaptureManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFramebuffer*                              pFramebuffer)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pFramebuffer);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkFramebufferCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateFramebuffer(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pFramebuffer);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, FramebufferWrapper>(device, NoParentWrapper::kHandleValue, pFramebuffer, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateFramebuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFramebuffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, FramebufferWrapper, VkFramebufferCreateInfo>(result, device, pFramebuffer, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pFramebuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(VulkanCaptureManager::Get(), device, framebuffer, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyFramebuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(framebuffer);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<FramebufferWrapper>(framebuffer);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkFramebuffer framebuffer_unwrapped = GetWrappedHandle<VkFramebuffer>(framebuffer);

    GetDeviceTable(device)->DestroyFramebuffer(device_unwrapped, framebuffer_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(VulkanCaptureManager::Get(), device, framebuffer, pAllocator);

    DestroyWrappedHandle<FramebufferWrapper>(framebuffer);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateRenderPass(device_unwrapped, pCreateInfo, pAllocator, pRenderPass);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, RenderPassWrapper>(device, NoParentWrapper::kHandleValue, pRenderPass, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pRenderPass, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, RenderPassWrapper, VkRenderPassCreateInfo>(result, device, pRenderPass, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(VulkanCaptureManager::Get(), device, renderPass, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(renderPass);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<RenderPassWrapper>(renderPass);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkRenderPass renderPass_unwrapped = GetWrappedHandle<VkRenderPass>(renderPass);

    GetDeviceTable(device)->DestroyRenderPass(device_unwrapped, renderPass_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(VulkanCaptureManager::Get(), device, renderPass, pAllocator);

    DestroyWrappedHandle<RenderPassWrapper>(renderPass);
}

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(VulkanCaptureManager::Get(), device, renderPass, pGranularity);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkRenderPass renderPass_unwrapped = GetWrappedHandle<VkRenderPass>(renderPass);

    GetDeviceTable(device)->GetRenderAreaGranularity(device_unwrapped, renderPass_unwrapped, pGranularity);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetRenderAreaGranularity);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(renderPass);
        EncodeStructPtr(encoder, pGranularity);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(VulkanCaptureManager::Get(), device, renderPass, pGranularity);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pCommandPool);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateCommandPool(device_unwrapped, pCreateInfo, pAllocator, pCommandPool);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, CommandPoolWrapper>(device, NoParentWrapper::kHandleValue, pCommandPool, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pCommandPool, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, CommandPoolWrapper, VkCommandPoolCreateInfo>(result, device, pCommandPool, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pCommandPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(VulkanCaptureManager::Get(), device, commandPool, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<CommandPoolWrapper>(commandPool);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkCommandPool commandPool_unwrapped = GetWrappedHandle<VkCommandPool>(commandPool);

    GetDeviceTable(device)->DestroyCommandPool(device_unwrapped, commandPool_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(VulkanCaptureManager::Get(), device, commandPool, pAllocator);

    DestroyWrappedHandle<CommandPoolWrapper>(commandPool);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(VulkanCaptureManager::Get(), device, commandPool, flags);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkCommandPool commandPool_unwrapped = GetWrappedHandle<VkCommandPool>(commandPool);

    VkResult result = GetDeviceTable(device)->ResetCommandPool(device_unwrapped, commandPool_unwrapped, flags);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkResetCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(VulkanCaptureManager::Get(), result, device, commandPool, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(
    VkDevice                                    device,
    const VkCommandBufferAllocateInfo*          pAllocateInfo,
    VkCommandBuffer*                            pCommandBuffers)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(VulkanCaptureManager::Get(), device, pAllocateInfo, pCommandBuffers);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkCommandBufferAllocateInfo* pAllocateInfo_unwrapped = UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->AllocateCommandBuffers(device_unwrapped, pAllocateInfo_unwrapped, pCommandBuffers);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, CommandPoolWrapper, CommandBufferWrapper>(device, pAllocateInfo->commandPool, pCommandBuffers, pAllocateInfo->commandBufferCount, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkAllocateCommandBuffers);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        encoder->EncodeHandleArray(pCommandBuffers, (pAllocateInfo != nullptr) ? (pAllocateInfo->commandBufferCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndPoolCreateApiCallCapture<VkDevice, CommandBufferWrapper, VkCommandBufferAllocateInfo>(result, device, (pAllocateInfo != nullptr) ? (pAllocateInfo->commandBufferCount) : 0, pCommandBuffers, pAllocateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(VulkanCaptureManager::Get(), result, device, pAllocateInfo, pCommandBuffers);

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(VulkanCaptureManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkFreeCommandBuffers);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleArray(pCommandBuffers, commandBufferCount);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<CommandBufferWrapper>(commandBufferCount, pCommandBuffers);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkCommandPool commandPool_unwrapped = GetWrappedHandle<VkCommandPool>(commandPool);
    const VkCommandBuffer* pCommandBuffers_unwrapped = UnwrapHandles<VkCommandBuffer>(pCommandBuffers, commandBufferCount, handle_unwrap_memory);

    GetDeviceTable(device)->FreeCommandBuffers(device_unwrapped, commandPool_unwrapped, commandBufferCount, pCommandBuffers_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(VulkanCaptureManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);

    DestroyWrappedHandles<CommandBufferWrapper>(pCommandBuffers, commandBufferCount);
}

VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pBeginInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCommandBufferBeginInfo* pBeginInfo_unwrapped = UnwrapStructPtrHandles(pBeginInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(commandBuffer)->BeginCommandBuffer(commandBuffer_unwrapped, pBeginInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkBeginCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pBeginInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackBeginCommandBufferHandles, pBeginInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(VulkanCaptureManager::Get(), result, commandBuffer, pBeginInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(
    VkCommandBuffer                             commandBuffer)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    VkResult result = GetDeviceTable(commandBuffer)->EndCommandBuffer(commandBuffer_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkEndCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(VulkanCaptureManager::Get(), result, commandBuffer);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, flags);

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    VkResult result = GetDeviceTable(commandBuffer)->ResetCommandBuffer(commandBuffer_unwrapped, flags);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkResetCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(VulkanCaptureManager::Get(), result, commandBuffer, flags);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineBindPoint, pipeline);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBindPipeline);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleValue(pipeline);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBindPipelineHandles, pipeline);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    GetDeviceTable(commandBuffer)->CmdBindPipeline(commandBuffer_unwrapped, pipelineBindPoint, pipeline_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineBindPoint, pipeline);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstViewport, viewportCount, pViewports);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetViewport);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewports, viewportCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewport(commandBuffer_unwrapped, firstViewport, viewportCount, pViewports);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstViewport, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstScissor, scissorCount, pScissors);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetScissor);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstScissor);
        encoder->EncodeUInt32Value(scissorCount);
        EncodeStructArray(encoder, pScissors, scissorCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetScissor(commandBuffer_unwrapped, firstScissor, scissorCount, pScissors);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstScissor, scissorCount, pScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, lineWidth);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetLineWidth);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatValue(lineWidth);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetLineWidth(commandBuffer_unwrapped, lineWidth);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, lineWidth);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthBias);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatValue(depthBiasConstantFactor);
        encoder->EncodeFloatValue(depthBiasClamp);
        encoder->EncodeFloatValue(depthBiasSlopeFactor);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthBias(commandBuffer_unwrapped, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4])
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, blendConstants);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetBlendConstants);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatArray(blendConstants, 4);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetBlendConstants(commandBuffer_unwrapped, blendConstants);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, blendConstants);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, minDepthBounds, maxDepthBounds);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthBounds);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatValue(minDepthBounds);
        encoder->EncodeFloatValue(maxDepthBounds);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthBounds(commandBuffer_unwrapped, minDepthBounds, maxDepthBounds);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, minDepthBounds, maxDepthBounds);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, faceMask, compareMask);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(compareMask);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilCompareMask(commandBuffer_unwrapped, faceMask, compareMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, faceMask, compareMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, faceMask, writeMask);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(writeMask);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilWriteMask(commandBuffer_unwrapped, faceMask, writeMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, faceMask, writeMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, faceMask, reference);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetStencilReference);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(reference);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilReference(commandBuffer_unwrapped, faceMask, reference);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, faceMask, reference);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets);
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
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBindDescriptorSetsHandles, layout, descriptorSetCount, pDescriptorSets);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkPipelineLayout layout_unwrapped = GetWrappedHandle<VkPipelineLayout>(layout);
    const VkDescriptorSet* pDescriptorSets_unwrapped = UnwrapHandles<VkDescriptorSet>(pDescriptorSets, descriptorSetCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBindDescriptorSets(commandBuffer_unwrapped, pipelineBindPoint, layout_unwrapped, firstSet, descriptorSetCount, pDescriptorSets_unwrapped, dynamicOffsetCount, pDynamicOffsets);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, indexType);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeEnumValue(indexType);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBindIndexBufferHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdBindIndexBuffer(commandBuffer_unwrapped, buffer_unwrapped, offset, indexType);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, indexType);
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBindVertexBuffersHandles, bindingCount, pBuffers);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pBuffers_unwrapped = UnwrapHandles<VkBuffer>(pBuffers, bindingCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBindVertexBuffers(commandBuffer_unwrapped, firstBinding, bindingCount, pBuffers_unwrapped, pOffsets);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDraw);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(vertexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstVertex);
        encoder->EncodeUInt32Value(firstInstance);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDraw(commandBuffer_unwrapped, vertexCount, instanceCount, firstVertex, firstInstance);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawIndexed);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(indexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstIndex);
        encoder->EncodeInt32Value(vertexOffset);
        encoder->EncodeUInt32Value(firstInstance);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndexed(commandBuffer_unwrapped, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawIndirect);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawIndirectHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndirect(commandBuffer_unwrapped, buffer_unwrapped, offset, drawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawIndexedIndirectHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirect(commandBuffer_unwrapped, buffer_unwrapped, offset, drawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDispatch);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDispatch(commandBuffer_unwrapped, groupCountX, groupCountY, groupCountZ);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDispatchIndirect);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDispatchIndirectHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdDispatchIndirect(commandBuffer_unwrapped, buffer_unwrapped, offset);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcBuffer);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyBufferHandles, srcBuffer, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer srcBuffer_unwrapped = GetWrappedHandle<VkBuffer>(srcBuffer);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdCopyBuffer(commandBuffer_unwrapped, srcBuffer_unwrapped, dstBuffer_unwrapped, regionCount, pRegions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyImageHandles, srcImage, dstImage);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage srcImage_unwrapped = GetWrappedHandle<VkImage>(srcImage);
    VkImage dstImage_unwrapped = GetWrappedHandle<VkImage>(dstImage);

    GetDeviceTable(commandBuffer)->CmdCopyImage(commandBuffer_unwrapped, srcImage_unwrapped, srcImageLayout, dstImage_unwrapped, dstImageLayout, regionCount, pRegions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBlitImage);
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
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBlitImageHandles, srcImage, dstImage);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage srcImage_unwrapped = GetWrappedHandle<VkImage>(srcImage);
    VkImage dstImage_unwrapped = GetWrappedHandle<VkImage>(dstImage);

    GetDeviceTable(commandBuffer)->CmdBlitImage(commandBuffer_unwrapped, srcImage_unwrapped, srcImageLayout, dstImage_unwrapped, dstImageLayout, regionCount, pRegions, filter);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcBuffer);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyBufferToImageHandles, srcBuffer, dstImage);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer srcBuffer_unwrapped = GetWrappedHandle<VkBuffer>(srcBuffer);
    VkImage dstImage_unwrapped = GetWrappedHandle<VkImage>(dstImage);

    GetDeviceTable(commandBuffer)->CmdCopyBufferToImage(commandBuffer_unwrapped, srcBuffer_unwrapped, dstImage_unwrapped, dstImageLayout, regionCount, pRegions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyImageToBufferHandles, srcImage, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage srcImage_unwrapped = GetWrappedHandle<VkImage>(srcImage);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdCopyImageToBuffer(commandBuffer_unwrapped, srcImage_unwrapped, srcImageLayout, dstBuffer_unwrapped, regionCount, pRegions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdUpdateBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(dataSize);
        encoder->EncodeVoidArray(pData, static_cast<size_t>(dataSize));
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdUpdateBufferHandles, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdUpdateBuffer(commandBuffer_unwrapped, dstBuffer_unwrapped, dstOffset, dataSize, pData);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, dstBuffer, dstOffset, size, data);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdFillBuffer);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeUInt32Value(data);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdFillBufferHandles, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdFillBuffer(commandBuffer_unwrapped, dstBuffer_unwrapped, dstOffset, size, data);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, dstBuffer, dstOffset, size, data);
}

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdClearColorImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(image);
        encoder->EncodeEnumValue(imageLayout);
        EncodeStructPtr(encoder, pColor);
        encoder->EncodeUInt32Value(rangeCount);
        EncodeStructArray(encoder, pRanges, rangeCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdClearColorImageHandles, image);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(commandBuffer)->CmdClearColorImage(commandBuffer_unwrapped, image_unwrapped, imageLayout, pColor, rangeCount, pRanges);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(image);
        encoder->EncodeEnumValue(imageLayout);
        EncodeStructPtr(encoder, pDepthStencil);
        encoder->EncodeUInt32Value(rangeCount);
        EncodeStructArray(encoder, pRanges, rangeCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdClearDepthStencilImageHandles, image);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(commandBuffer)->CmdClearDepthStencilImage(commandBuffer_unwrapped, image_unwrapped, imageLayout, pDepthStencil, rangeCount, pRanges);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdClearAttachments);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(attachmentCount);
        EncodeStructArray(encoder, pAttachments, attachmentCount);
        encoder->EncodeUInt32Value(rectCount);
        EncodeStructArray(encoder, pRects, rectCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdClearAttachments(commandBuffer_unwrapped, attachmentCount, pAttachments, rectCount, pRects);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdResolveImage);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdResolveImageHandles, srcImage, dstImage);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImage srcImage_unwrapped = GetWrappedHandle<VkImage>(srcImage);
    VkImage dstImage_unwrapped = GetWrappedHandle<VkImage>(dstImage);

    GetDeviceTable(commandBuffer)->CmdResolveImage(commandBuffer_unwrapped, srcImage_unwrapped, srcImageLayout, dstImage_unwrapped, dstImageLayout, regionCount, pRegions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, stageMask);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(event);
        encoder->EncodeFlagsValue(stageMask);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdSetEventHandles, event);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    GetDeviceTable(commandBuffer)->CmdSetEvent(commandBuffer_unwrapped, event_unwrapped, stageMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, stageMask);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(event);
        encoder->EncodeFlagsValue(stageMask);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdResetEventHandles, event);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    GetDeviceTable(commandBuffer)->CmdResetEvent(commandBuffer_unwrapped, event_unwrapped, stageMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, stageMask);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWaitEvents);
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
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWaitEventsHandles, eventCount, pEvents, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkEvent* pEvents_unwrapped = UnwrapHandles<VkEvent>(pEvents, eventCount, handle_unwrap_memory);
    const VkBufferMemoryBarrier* pBufferMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, handle_unwrap_memory);
    const VkImageMemoryBarrier* pImageMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdWaitEvents(commandBuffer_unwrapped, eventCount, pEvents_unwrapped, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers_unwrapped, imageMemoryBarrierCount, pImageMemoryBarriers_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdPipelineBarrier);
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
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdPipelineBarrierHandles, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBufferMemoryBarrier* pBufferMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pBufferMemoryBarriers, bufferMemoryBarrierCount, handle_unwrap_memory);
    const VkImageMemoryBarrier* pImageMemoryBarriers_unwrapped = UnwrapStructArrayHandles(pImageMemoryBarriers, imageMemoryBarrierCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdPipelineBarrier(commandBuffer_unwrapped, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers_unwrapped, imageMemoryBarrierCount, pImageMemoryBarriers_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, query, flags);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginQuery);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBeginQueryHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdBeginQuery(commandBuffer_unwrapped, queryPool_unwrapped, query, flags);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, query, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, query);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndQuery);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdEndQueryHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdEndQuery(commandBuffer_unwrapped, queryPool_unwrapped, query);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, query);
}

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, firstQuery, queryCount);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdResetQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdResetQueryPoolHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdResetQueryPool(commandBuffer_unwrapped, queryPool_unwrapped, firstQuery, queryCount);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineStage, queryPool, query);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWriteTimestamp);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWriteTimestampHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdWriteTimestamp(commandBuffer_unwrapped, pipelineStage, queryPool_unwrapped, query);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineStage, queryPool, query);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults);
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
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyQueryPoolResultsHandles, queryPool, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdCopyQueryPoolResults(commandBuffer_unwrapped, queryPool_unwrapped, firstQuery, queryCount, dstBuffer_unwrapped, dstOffset, stride, flags);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, layout, stageFlags, offset, size, pValues);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdPushConstants);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(layout);
        encoder->EncodeFlagsValue(stageFlags);
        encoder->EncodeUInt32Value(offset);
        encoder->EncodeUInt32Value(size);
        encoder->EncodeVoidArray(pValues, size);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdPushConstantsHandles, layout);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkPipelineLayout layout_unwrapped = GetWrappedHandle<VkPipelineLayout>(layout);

    GetDeviceTable(commandBuffer)->CmdPushConstants(commandBuffer_unwrapped, layout_unwrapped, stageFlags, offset, size, pValues);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, layout, stageFlags, offset, size, pValues);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRenderPassBegin, contents);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderPassBegin);
        encoder->EncodeEnumValue(contents);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBeginRenderPassHandles, pRenderPassBegin);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginRenderPass(commandBuffer_unwrapped, pRenderPassBegin_unwrapped, contents);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRenderPassBegin, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, contents);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdNextSubpass);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(contents);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdNextSubpass(commandBuffer_unwrapped, contents);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(
    VkCommandBuffer                             commandBuffer)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndRenderPass(commandBuffer_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdExecuteCommands);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleArray(pCommandBuffers, commandBufferCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdExecuteCommandsHandles, commandBufferCount, pCommandBuffers);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCommandBuffer* pCommandBuffers_unwrapped = UnwrapHandles<VkCommandBuffer>(pCommandBuffers, commandBufferCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdExecuteCommands(commandBuffer_unwrapped, commandBufferCount, pCommandBuffers_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(VulkanCaptureManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindBufferMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindBufferMemory2(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkBindBufferMemory2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(VulkanCaptureManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(VulkanCaptureManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindImageMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindImageMemory2(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkBindImageMemory2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(VulkanCaptureManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(VulkanCaptureManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->GetDeviceGroupPeerMemoryFeatures(device_unwrapped, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(VulkanCaptureManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, deviceMask);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDeviceMask);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDeviceMask(commandBuffer_unwrapped, deviceMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, deviceMask);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDispatchBase);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDispatchBase(commandBuffer_unwrapped, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(VulkanCaptureManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->EnumeratePhysicalDeviceGroups(instance_unwrapped, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<InstanceWrapper, NoParentWrapper, VkPhysicalDeviceGroupProperties>(instance, NoParentWrapper::kHandleValue, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount, omit_output_data);
        EncodeStructArray(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndStructGroupCreateApiCallCapture<VkInstance, PhysicalDeviceWrapper, VkPhysicalDeviceGroupProperties>(result, instance, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, pPhysicalDeviceGroupProperties, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(VulkanCaptureManager::Get(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetImageMemoryRequirements2(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetBufferMemoryRequirements2(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageSparseMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetImageSparseMemoryRequirements2(device_unwrapped, pInfo_unwrapped, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFeatures);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures2(physicalDevice_unwrapped, pFeatures);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice_unwrapped, pProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, format, pFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties2(physicalDevice_unwrapped, format, pFormatProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        EncodeStructPtr(encoder, pFormatProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties2(physicalDevice_unwrapped, pImageFormatInfo, pImageFormatProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pImageFormatInfo);
        EncodeStructPtr(encoder, pImageFormatProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice_unwrapped, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        EncodeStructArray(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pMemoryProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties2(physicalDevice_unwrapped, pMemoryProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pMemoryProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice_unwrapped, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pFormatInfo);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(VulkanCaptureManager::Get(), device, commandPool, flags);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkTrimCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkCommandPool commandPool_unwrapped = GetWrappedHandle<VkCommandPool>(commandPool);

    GetDeviceTable(device)->TrimCommandPool(device_unwrapped, commandPool_unwrapped, flags);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(VulkanCaptureManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(
    VkDevice                                    device,
    const VkDeviceQueueInfo2*                   pQueueInfo,
    VkQueue*                                    pQueue)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(VulkanCaptureManager::Get(), device, pQueueInfo, pQueue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->GetDeviceQueue2(device_unwrapped, pQueueInfo, pQueue);

    CreateWrappedHandle<DeviceWrapper, NoParentWrapper, QueueWrapper>(device, NoParentWrapper::kHandleValue, pQueue, VulkanCaptureManager::GetUniqueId);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceQueue2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pQueueInfo);
        encoder->EncodeHandlePtr(pQueue);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, QueueWrapper, void>(VK_SUCCESS, device, pQueue, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(VulkanCaptureManager::Get(), device, pQueueInfo, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateSamplerYcbcrConversion(device_unwrapped, pCreateInfo, pAllocator, pYcbcrConversion);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SamplerYcbcrConversionWrapper>(device, NoParentWrapper::kHandleValue, pYcbcrConversion, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pYcbcrConversion, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, SamplerYcbcrConversionWrapper, VkSamplerYcbcrConversionCreateInfo>(result, device, pYcbcrConversion, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(VulkanCaptureManager::Get(), device, ycbcrConversion, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(ycbcrConversion);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<SamplerYcbcrConversionWrapper>(ycbcrConversion);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSamplerYcbcrConversion ycbcrConversion_unwrapped = GetWrappedHandle<VkSamplerYcbcrConversion>(ycbcrConversion);

    GetDeviceTable(device)->DestroySamplerYcbcrConversion(device_unwrapped, ycbcrConversion_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(VulkanCaptureManager::Get(), device, ycbcrConversion, pAllocator);

    DestroyWrappedHandle<SamplerYcbcrConversionWrapper>(ycbcrConversion);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateDescriptorUpdateTemplate(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pDescriptorUpdateTemplate);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorUpdateTemplateWrapper>(device, NoParentWrapper::kHandleValue, pDescriptorUpdateTemplate, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDescriptorUpdateTemplate, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, DescriptorUpdateTemplateWrapper, VkDescriptorUpdateTemplateCreateInfo>(result, device, pDescriptorUpdateTemplate, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(VulkanCaptureManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorUpdateTemplate descriptorUpdateTemplate_unwrapped = GetWrappedHandle<VkDescriptorUpdateTemplate>(descriptorUpdateTemplate);

    GetDeviceTable(device)->DestroyDescriptorUpdateTemplate(device_unwrapped, descriptorUpdateTemplate_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(VulkanCaptureManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    DestroyWrappedHandle<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalBufferProperties(physicalDevice_unwrapped, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalBufferInfo);
        EncodeStructPtr(encoder, pExternalBufferProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalFenceProperties(physicalDevice_unwrapped, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalFenceInfo);
        EncodeStructPtr(encoder, pExternalFenceProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice_unwrapped, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalSemaphoreInfo);
        EncodeStructPtr(encoder, pExternalSemaphoreProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pSupport);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetDescriptorSetLayoutSupport(device_unwrapped, pCreateInfo_unwrapped, pSupport);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pSupport);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pSupport);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawIndirectCount);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawIndirectCountHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndirectCount(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCount>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawIndexedIndirectCountHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirectCount(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateRenderPass2(device_unwrapped, pCreateInfo, pAllocator, pRenderPass);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, RenderPassWrapper>(device, NoParentWrapper::kHandleValue, pRenderPass, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateRenderPass2);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pRenderPass, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, RenderPassWrapper, VkRenderPassCreateInfo2>(result, device, pRenderPass, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderPassBegin);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBeginRenderPass2Handles, pRenderPassBegin);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginRenderPass2(commandBuffer_unwrapped, pRenderPassBegin_unwrapped, pSubpassBeginInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdNextSubpass2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdNextSubpass2(commandBuffer_unwrapped, pSubpassBeginInfo, pSubpassEndInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pSubpassEndInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndRenderPass2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndRenderPass2(commandBuffer_unwrapped, pSubpassEndInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL ResetQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(VulkanCaptureManager::Get(), device, queryPool, firstQuery, queryCount);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkResetQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(device)->ResetQueryPool(device_unwrapped, queryPool_unwrapped, firstQuery, queryCount);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPool>::Dispatch(VulkanCaptureManager::Get(), device, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValue(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    uint64_t*                                   pValue)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(VulkanCaptureManager::Get(), device, semaphore, pValue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSemaphore semaphore_unwrapped = GetWrappedHandle<VkSemaphore>(semaphore);

    VkResult result = GetDeviceTable(device)->GetSemaphoreCounterValue(device_unwrapped, semaphore_unwrapped, pValue);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(semaphore);
        encoder->EncodeUInt64Ptr(pValue, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue>::Dispatch(VulkanCaptureManager::Get(), result, device, semaphore, pValue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphores(
    VkDevice                                    device,
    const VkSemaphoreWaitInfo*                  pWaitInfo,
    uint64_t                                    timeout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(VulkanCaptureManager::Get(), device, pWaitInfo, timeout);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreWaitInfo* pWaitInfo_unwrapped = UnwrapStructPtrHandles(pWaitInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->WaitSemaphores(device_unwrapped, pWaitInfo_unwrapped, timeout);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkWaitSemaphores);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pWaitInfo);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphores>::Dispatch(VulkanCaptureManager::Get(), result, device, pWaitInfo, timeout);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphore(
    VkDevice                                    device,
    const VkSemaphoreSignalInfo*                pSignalInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(VulkanCaptureManager::Get(), device, pSignalInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreSignalInfo* pSignalInfo_unwrapped = UnwrapStructPtrHandles(pSignalInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->SignalSemaphore(device_unwrapped, pSignalInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSignalSemaphore);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pSignalInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphore>::Dispatch(VulkanCaptureManager::Get(), result, device, pSignalInfo);

    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddress(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(VulkanCaptureManager::Get(), device, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkDeviceAddress result = GetDeviceTable(device)->GetBufferDeviceAddress(device_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetBufferDeviceAddress);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVkDeviceAddressValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddress>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddress(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(VulkanCaptureManager::Get(), device, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    uint64_t result = GetDeviceTable(device)->GetBufferOpaqueCaptureAddress(device_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt64Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddress(
    VkDevice                                    device,
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(VulkanCaptureManager::Get(), device, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    uint64_t result = GetDeviceTable(device)->GetDeviceMemoryOpaqueCaptureAddress(device_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt64Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pToolCount,
    VkPhysicalDeviceToolProperties*             pToolProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pToolCount, pToolProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceToolProperties(physicalDevice_unwrapped, pToolCount, pToolProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pToolCount, omit_output_data);
        EncodeStructArray(encoder, pToolProperties, (pToolCount != nullptr) ? (*pToolCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pToolCount, pToolProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlot(
    VkDevice                                    device,
    const VkPrivateDataSlotCreateInfo*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPrivateDataSlot*                          pPrivateDataSlot)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pPrivateDataSlot);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreatePrivateDataSlot(device_unwrapped, pCreateInfo, pAllocator, pPrivateDataSlot);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PrivateDataSlotWrapper>(device, NoParentWrapper::kHandleValue, pPrivateDataSlot, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreatePrivateDataSlot);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pPrivateDataSlot, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, PrivateDataSlotWrapper, VkPrivateDataSlotCreateInfo>(result, device, pPrivateDataSlot, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlot>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pPrivateDataSlot);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlot(
    VkDevice                                    device,
    VkPrivateDataSlot                           privateDataSlot,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(VulkanCaptureManager::Get(), device, privateDataSlot, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(privateDataSlot);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<PrivateDataSlotWrapper>(privateDataSlot);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPrivateDataSlot privateDataSlot_unwrapped = GetWrappedHandle<VkPrivateDataSlot>(privateDataSlot);

    GetDeviceTable(device)->DestroyPrivateDataSlot(device_unwrapped, privateDataSlot_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot>::Dispatch(VulkanCaptureManager::Get(), device, privateDataSlot, pAllocator);

    DestroyWrappedHandle<PrivateDataSlotWrapper>(privateDataSlot);
}

VKAPI_ATTR VkResult VKAPI_CALL SetPrivateData(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t                                    data)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(VulkanCaptureManager::Get(), device, objectType, objectHandle, privateDataSlot, data);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    uint64_t objectHandle_unwrapped = GetWrappedHandle(objectHandle, objectType);
    VkPrivateDataSlot privateDataSlot_unwrapped = GetWrappedHandle<VkPrivateDataSlot>(privateDataSlot);

    VkResult result = GetDeviceTable(device)->SetPrivateData(device_unwrapped, objectType, objectHandle_unwrapped, privateDataSlot_unwrapped, data);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSetPrivateData);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(GetWrappedId(objectHandle, objectType));
        encoder->EncodeHandleValue(privateDataSlot);
        encoder->EncodeUInt64Value(data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateData>::Dispatch(VulkanCaptureManager::Get(), result, device, objectType, objectHandle, privateDataSlot, data);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPrivateData(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t*                                   pData)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(VulkanCaptureManager::Get(), device, objectType, objectHandle, privateDataSlot, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    uint64_t objectHandle_unwrapped = GetWrappedHandle(objectHandle, objectType);
    VkPrivateDataSlot privateDataSlot_unwrapped = GetWrappedHandle<VkPrivateDataSlot>(privateDataSlot);

    GetDeviceTable(device)->GetPrivateData(device_unwrapped, objectType, objectHandle_unwrapped, privateDataSlot_unwrapped, pData);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPrivateData);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(GetWrappedId(objectHandle, objectType));
        encoder->EncodeHandleValue(privateDataSlot);
        encoder->EncodeUInt64Ptr(pData);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateData>::Dispatch(VulkanCaptureManager::Get(), device, objectType, objectHandle, privateDataSlot, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, pDependencyInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetEvent2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(event);
        EncodeStructPtr(encoder, pDependencyInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdSetEvent2Handles, event, pDependencyInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);
    const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdSetEvent2(commandBuffer_unwrapped, event_unwrapped, pDependencyInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, pDependencyInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, stageMask);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdResetEvent2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(event);
        encoder->EncodeFlags64Value(stageMask);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdResetEvent2Handles, event);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    GetDeviceTable(commandBuffer)->CmdResetEvent2(commandBuffer_unwrapped, event_unwrapped, stageMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, eventCount, pEvents, pDependencyInfos);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWaitEvents2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(eventCount);
        encoder->EncodeHandleArray(pEvents, eventCount);
        EncodeStructArray(encoder, pDependencyInfos, eventCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWaitEvents2Handles, eventCount, pEvents, pDependencyInfos);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkEvent* pEvents_unwrapped = UnwrapHandles<VkEvent>(pEvents, eventCount, handle_unwrap_memory);
    const VkDependencyInfo* pDependencyInfos_unwrapped = UnwrapStructArrayHandles(pDependencyInfos, eventCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdWaitEvents2(commandBuffer_unwrapped, eventCount, pEvents_unwrapped, pDependencyInfos_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, eventCount, pEvents, pDependencyInfos);
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pDependencyInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdPipelineBarrier2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pDependencyInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdPipelineBarrier2Handles, pDependencyInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdPipelineBarrier2(commandBuffer_unwrapped, pDependencyInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pDependencyInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stage, queryPool, query);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWriteTimestamp2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlags64Value(stage);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWriteTimestamp2Handles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdWriteTimestamp2(commandBuffer_unwrapped, stage, queryPool_unwrapped, query);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stage, queryPool, query);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo2*                        pSubmits,
    VkFence                                     fence)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(VulkanCaptureManager::Get(), queue, submitCount, pSubmits, fence);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);
    const VkSubmitInfo2* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    VkResult result = GetDeviceTable(queue)->QueueSubmit2(queue_unwrapped, submitCount, pSubmits_unwrapped, fence_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkQueueSubmit2);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Value(submitCount);
        EncodeStructArray(encoder, pSubmits, submitCount);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2>::Dispatch(VulkanCaptureManager::Get(), result, queue, submitCount, pSubmits, fence);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyBufferInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyBuffer2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pCopyBufferInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyBuffer2Handles, pCopyBufferInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyBufferInfo2* pCopyBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyBuffer2(commandBuffer_unwrapped, pCopyBufferInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyBufferInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyImageInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyImage2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pCopyImageInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyImage2Handles, pCopyImageInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyImageInfo2* pCopyImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyImage2(commandBuffer_unwrapped, pCopyImageInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyBufferToImageInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pCopyBufferToImageInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyBufferToImage2Handles, pCopyBufferToImageInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferToImageInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyBufferToImage2(commandBuffer_unwrapped, pCopyBufferToImageInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyBufferToImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyImageToBufferInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pCopyImageToBufferInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyImageToBuffer2Handles, pCopyImageToBufferInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageToBufferInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyImageToBuffer2(commandBuffer_unwrapped, pCopyImageToBufferInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyImageToBufferInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pBlitImageInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBlitImage2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pBlitImageInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBlitImage2Handles, pBlitImageInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBlitImageInfo2* pBlitImageInfo_unwrapped = UnwrapStructPtrHandles(pBlitImageInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBlitImage2(commandBuffer_unwrapped, pBlitImageInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pBlitImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pResolveImageInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdResolveImage2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pResolveImageInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdResolveImage2Handles, pResolveImageInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkResolveImageInfo2* pResolveImageInfo_unwrapped = UnwrapStructPtrHandles(pResolveImageInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdResolveImage2(commandBuffer_unwrapped, pResolveImageInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pResolveImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRendering(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRenderingInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginRendering);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderingInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBeginRenderingHandles, pRenderingInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkRenderingInfo* pRenderingInfo_unwrapped = UnwrapStructPtrHandles(pRenderingInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginRendering(commandBuffer_unwrapped, pRenderingInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRendering>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRenderingInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRendering(
    VkCommandBuffer                             commandBuffer)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndRendering);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndRendering(commandBuffer_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRendering>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCullMode(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, cullMode);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetCullMode);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(cullMode);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCullMode(commandBuffer_unwrapped, cullMode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullMode>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, cullMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFace(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, frontFace);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetFrontFace);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(frontFace);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetFrontFace(commandBuffer_unwrapped, frontFace);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFace>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, frontFace);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopology(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, primitiveTopology);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(primitiveTopology);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetPrimitiveTopology(commandBuffer_unwrapped, primitiveTopology);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, primitiveTopology);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, viewportCount, pViewports);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetViewportWithCount);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewports, viewportCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewportWithCount(commandBuffer_unwrapped, viewportCount, pViewports);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCount>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCount(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, scissorCount, pScissors);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetScissorWithCount);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(scissorCount);
        EncodeStructArray(encoder, pScissors, scissorCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetScissorWithCount(commandBuffer_unwrapped, scissorCount, pScissors);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCount>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, scissorCount, pScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers2(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pSizes, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pStrides, bindingCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBindVertexBuffers2Handles, bindingCount, pBuffers);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pBuffers_unwrapped = UnwrapHandles<VkBuffer>(pBuffers, bindingCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBindVertexBuffers2(commandBuffer_unwrapped, firstBinding, bindingCount, pBuffers_unwrapped, pOffsets, pSizes, pStrides);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthTestEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthTestEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthTestEnable(commandBuffer_unwrapped, depthTestEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthWriteEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthWriteEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthWriteEnable(commandBuffer_unwrapped, depthWriteEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthWriteEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOp(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthCompareOp);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(depthCompareOp);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthCompareOp(commandBuffer_unwrapped, depthCompareOp);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthCompareOp);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthBoundsTestEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthBoundsTestEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthBoundsTestEnable(commandBuffer_unwrapped, depthBoundsTestEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthBoundsTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stencilTestEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(stencilTestEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilTestEnable(commandBuffer_unwrapped, stencilTestEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stencilTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOp(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetStencilOp);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeEnumValue(failOp);
        encoder->EncodeEnumValue(passOp);
        encoder->EncodeEnumValue(depthFailOp);
        encoder->EncodeEnumValue(compareOp);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilOp(commandBuffer_unwrapped, faceMask, failOp, passOp, depthFailOp, compareOp);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOp>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, rasterizerDiscardEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(rasterizerDiscardEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetRasterizerDiscardEnable(commandBuffer_unwrapped, rasterizerDiscardEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, rasterizerDiscardEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthBiasEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthBiasEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthBiasEnable(commandBuffer_unwrapped, depthBiasEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthBiasEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnable(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, primitiveRestartEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(primitiveRestartEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetPrimitiveRestartEnable(commandBuffer_unwrapped, primitiveRestartEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, primitiveRestartEnable);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirements(
    VkDevice                                    device,
    const VkDeviceBufferMemoryRequirements*     pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDeviceBufferMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetDeviceBufferMemoryRequirements(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirements(
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetDeviceImageMemoryRequirements(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirements(
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetDeviceImageSparseMemoryRequirements(device_unwrapped, pInfo_unwrapped, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), instance, surface, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroySurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeHandleValue(surface);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<SurfaceKHRWrapper>(surface);
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    GetInstanceTable(instance)->DestroySurfaceKHR(instance_unwrapped, surface_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), instance, surface, pAllocator);

    DestroyWrappedHandle<SurfaceKHRWrapper>(surface);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, queueFamilyIndex, surface, pSupported);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice_unwrapped, queueFamilyIndex, surface_unwrapped, pSupported);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeVkBool32Ptr(pSupported, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, queueFamilyIndex, surface, pSupported);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice_unwrapped, surface_unwrapped, pSurfaceCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        EncodeStructPtr(encoder, pSurfaceCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, surface, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormatKHR*                         pSurfaceFormats)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice_unwrapped, surface_unwrapped, pSurfaceFormatCount, pSurfaceFormats);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount, omit_output_data);
        EncodeStructArray(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, surface, pPresentModeCount, pPresentModes);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice_unwrapped, surface_unwrapped, pPresentModeCount, pPresentModes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeUInt32Ptr(pPresentModeCount, omit_output_data);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, surface, pPresentModeCount, pPresentModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pSwapchain);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSwapchainCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateSwapchainKHR(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pSwapchain);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SwapchainKHRWrapper>(device, NoParentWrapper::kHandleValue, pSwapchain, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateSwapchainKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSwapchain, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, SwapchainKHRWrapper, VkSwapchainCreateInfoKHR>(result, device, pSwapchain, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pSwapchain);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(VulkanCaptureManager::Get(), device, swapchain, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroySwapchainKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<SwapchainKHRWrapper>(swapchain);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    GetDeviceTable(device)->DestroySwapchainKHR(device_unwrapped, swapchain_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(VulkanCaptureManager::Get(), device, swapchain, pAllocator);

    DestroyWrappedHandle<SwapchainKHRWrapper>(swapchain);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pSwapchainImageCount,
    VkImage*                                    pSwapchainImages)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(VulkanCaptureManager::Get(), device, swapchain, pSwapchainImageCount, pSwapchainImages);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->GetSwapchainImagesKHR(device_unwrapped, swapchain_unwrapped, pSwapchainImageCount, pSwapchainImages);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, SwapchainKHRWrapper, ImageWrapper>(device, swapchain, pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeUInt32Ptr(pSwapchainImageCount, omit_output_data);
        encoder->EncodeHandleArray(pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndGroupCreateApiCallCapture<VkDevice, VkSwapchainKHR, ImageWrapper, void>(result, device, swapchain, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0, pSwapchainImages, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, swapchain, pSwapchainImageCount, pSwapchainImages);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(VulkanCaptureManager::Get(), device, swapchain, timeout, semaphore, fence, pImageIndex);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);
    VkSemaphore semaphore_unwrapped = GetWrappedHandle<VkSemaphore>(semaphore);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    VkResult result = GetDeviceTable(device)->AcquireNextImageKHR(device_unwrapped, swapchain_unwrapped, timeout, semaphore_unwrapped, fence_unwrapped, pImageIndex);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkAcquireNextImageKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeHandleValue(semaphore);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeUInt32Ptr(pImageIndex, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, swapchain, timeout, semaphore, fence, pImageIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireUniqueStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(VulkanCaptureManager::Get(), queue, pPresentInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);
    const VkPresentInfoKHR* pPresentInfo_unwrapped = UnwrapStructPtrHandles(pPresentInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(queue)->QueuePresentKHR(queue_unwrapped, pPresentInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkQueuePresentKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        EncodeStructPtr(encoder, pPresentInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(VulkanCaptureManager::Get(), result, queue, pPresentInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR(
    VkDevice                                    device,
    VkDeviceGroupPresentCapabilitiesKHR*        pDeviceGroupPresentCapabilities)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(VulkanCaptureManager::Get(), device, pDeviceGroupPresentCapabilities);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetDeviceGroupPresentCapabilitiesKHR(device_unwrapped, pDeviceGroupPresentCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pDeviceGroupPresentCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pDeviceGroupPresentCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    VkDeviceGroupPresentModeFlagsKHR*           pModes)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(VulkanCaptureManager::Get(), device, surface, pModes);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetDeviceTable(device)->GetDeviceGroupSurfacePresentModesKHR(device_unwrapped, surface_unwrapped, pModes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeFlagsPtr(pModes, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, surface, pModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pRectCount,
    VkRect2D*                                   pRects)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, surface, pRectCount, pRects);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(physicalDevice_unwrapped, surface_unwrapped, pRectCount, pRects);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        encoder->EncodeUInt32Ptr(pRectCount, omit_output_data);
        EncodeStructArray(encoder, pRects, (pRectCount != nullptr) ? (*pRectCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, surface, pRectCount, pRects);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(
    VkDevice                                    device,
    const VkAcquireNextImageInfoKHR*            pAcquireInfo,
    uint32_t*                                   pImageIndex)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(VulkanCaptureManager::Get(), device, pAcquireInfo, pImageIndex);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAcquireNextImageInfoKHR* pAcquireInfo_unwrapped = UnwrapStructPtrHandles(pAcquireInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->AcquireNextImage2KHR(device_unwrapped, pAcquireInfo_unwrapped, pImageIndex);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkAcquireNextImage2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAcquireInfo);
        encoder->EncodeUInt32Ptr(pImageIndex, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pAcquireInfo, pImageIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPropertiesKHR*                     pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayPropertiesKHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndStructGroupCreateApiCallCapture<VkPhysicalDevice, DisplayKHRWrapper, VkDisplayPropertiesKHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayPropertiesKHR* handle_struct)->DisplayKHRWrapper* { return reinterpret_cast<DisplayKHRWrapper*>(handle_struct->display); });
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayPlanePropertiesKHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndStructGroupCreateApiCallCapture<VkPhysicalDevice, DisplayKHRWrapper, VkDisplayPlanePropertiesKHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayPlanePropertiesKHR* handle_struct)->DisplayKHRWrapper* { return reinterpret_cast<DisplayKHRWrapper*>(handle_struct->currentDisplay); });
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, planeIndex, pDisplayCount, pDisplays);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice_unwrapped, planeIndex, pDisplayCount, pDisplays);

    if (result >= 0)
    {
        CreateWrappedHandles<PhysicalDeviceWrapper, NoParentWrapper, DisplayKHRWrapper>(physicalDevice, NoParentWrapper::kHandleValue, pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(planeIndex);
        encoder->EncodeUInt32Ptr(pDisplayCount, omit_output_data);
        encoder->EncodeHandleArray(pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndGroupCreateApiCallCapture<VkPhysicalDevice, void*, DisplayKHRWrapper, void>(result, physicalDevice, nullptr, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0, pDisplays, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, planeIndex, pDisplayCount, pDisplays);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModePropertiesKHR*                 pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->GetDisplayModePropertiesKHR(physicalDevice_unwrapped, display_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, DisplayKHRWrapper, VkDisplayModePropertiesKHR>(physicalDevice, display, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndStructGroupCreateApiCallCapture<VkPhysicalDevice, DisplayModeKHRWrapper, VkDisplayModePropertiesKHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayModePropertiesKHR* handle_struct)->DisplayModeKHRWrapper* { return reinterpret_cast<DisplayModeKHRWrapper*>(handle_struct->displayMode); });
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, display, pCreateInfo, pAllocator, pMode);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->CreateDisplayModeKHR(physicalDevice_unwrapped, display_unwrapped, pCreateInfo, pAllocator, pMode);

    if (result >= 0)
    {
        CreateWrappedHandle<PhysicalDeviceWrapper, DisplayKHRWrapper, DisplayModeKHRWrapper>(physicalDevice, display, pMode, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDisplayModeKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pMode, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkPhysicalDevice, DisplayModeKHRWrapper, VkDisplayModeCreateInfoKHR>(result, physicalDevice, pMode, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, display, pCreateInfo, pAllocator, pMode);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    VkDisplayPlaneCapabilitiesKHR*              pCapabilities)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, mode, planeIndex, pCapabilities);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayModeKHR mode_unwrapped = GetWrappedHandle<VkDisplayModeKHR>(mode);

    VkResult result = GetInstanceTable(physicalDevice)->GetDisplayPlaneCapabilitiesKHR(physicalDevice_unwrapped, mode_unwrapped, planeIndex, pCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(mode);
        encoder->EncodeUInt32Value(planeIndex);
        EncodeStructPtr(encoder, pCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, mode, planeIndex, pCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);
    const VkDisplaySurfaceCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetInstanceTable(instance)->CreateDisplayPlaneSurfaceKHR(instance_unwrapped, pCreateInfo_unwrapped, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkDisplaySurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(VulkanCaptureManager::Get(), device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSwapchainCreateInfoKHR* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, swapchainCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateSharedSwapchainsKHR(device_unwrapped, swapchainCount, pCreateInfos_unwrapped, pAllocator, pSwapchains);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, NoParentWrapper, SwapchainKHRWrapper>(device, NoParentWrapper::kHandleValue, pSwapchains, swapchainCount, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        EncodeStructArray(encoder, pCreateInfos, swapchainCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleArray(pSwapchains, swapchainCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndGroupCreateApiCallCapture<VkDevice, void*, SwapchainKHRWrapper, VkSwapchainCreateInfoKHR>(result, device, nullptr, swapchainCount, pSwapchains, pCreateInfos);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateXlibSurfaceKHR(
    VkInstance                                  instance,
    const VkXlibSurfaceCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateXlibSurfaceKHR(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkXlibSurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    Display*                                    dpy,
    VisualID                                    visualID)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, queueFamilyIndex, dpy, visualID);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice_unwrapped, queueFamilyIndex, dpy, visualID);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeSizeTValue(visualID);
        encoder->EncodeVkBool32Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, queueFamilyIndex, dpy, visualID);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateXcbSurfaceKHR(
    VkInstance                                  instance,
    const VkXcbSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateXcbSurfaceKHR(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkXcbSurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    xcb_connection_t*                           connection,
    xcb_visualid_t                              visual_id)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, queueFamilyIndex, connection, visual_id);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice_unwrapped, queueFamilyIndex, connection, visual_id);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(connection);
        encoder->EncodeUInt32Value(visual_id);
        encoder->EncodeVkBool32Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, queueFamilyIndex, connection, visual_id);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateWaylandSurfaceKHR(
    VkInstance                                  instance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateWaylandSurfaceKHR(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkWaylandSurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct wl_display*                          display)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, queueFamilyIndex, display);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice_unwrapped, queueFamilyIndex, display);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(display);
        encoder->EncodeVkBool32Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, queueFamilyIndex, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAndroidSurfaceKHR(
    VkInstance                                  instance,
    const VkAndroidSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateAndroidSurfaceKHR(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkAndroidSurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateWin32SurfaceKHR(
    VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateWin32SurfaceKHR(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkWin32SurfaceCreateInfoKHR>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, queueFamilyIndex);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice_unwrapped, queueFamilyIndex);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVkBool32Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, queueFamilyIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkVideoProfileInfoKHR*                pVideoProfile,
    VkVideoCapabilitiesKHR*                     pCapabilities)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pVideoProfile, pCapabilities);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceVideoCapabilitiesKHR(physicalDevice_unwrapped, pVideoProfile, pCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pVideoProfile);
        EncodeStructPtr(encoder, pCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pVideoProfile, pCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceVideoFormatPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceVideoFormatInfoKHR*   pVideoFormatInfo,
    uint32_t*                                   pVideoFormatPropertyCount,
    VkVideoFormatPropertiesKHR*                 pVideoFormatProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice_unwrapped, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pVideoFormatInfo);
        encoder->EncodeUInt32Ptr(pVideoFormatPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pVideoFormatProperties, (pVideoFormatPropertyCount != nullptr) ? (*pVideoFormatPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateVideoSessionKHR(
    VkDevice                                    device,
    const VkVideoSessionCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkVideoSessionKHR*                          pVideoSession)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pVideoSession);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateVideoSessionKHR(device_unwrapped, pCreateInfo, pAllocator, pVideoSession);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, VideoSessionKHRWrapper>(device, NoParentWrapper::kHandleValue, pVideoSession, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateVideoSessionKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pVideoSession, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, VideoSessionKHRWrapper, VkVideoSessionCreateInfoKHR>(result, device, pVideoSession, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pVideoSession);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionKHR(
    VkDevice                                    device,
    VkVideoSessionKHR                           videoSession,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(VulkanCaptureManager::Get(), device, videoSession, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(videoSession);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<VideoSessionKHRWrapper>(videoSession);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkVideoSessionKHR videoSession_unwrapped = GetWrappedHandle<VkVideoSessionKHR>(videoSession);

    GetDeviceTable(device)->DestroyVideoSessionKHR(device_unwrapped, videoSession_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR>::Dispatch(VulkanCaptureManager::Get(), device, videoSession, pAllocator);

    DestroyWrappedHandle<VideoSessionKHRWrapper>(videoSession);
}

VKAPI_ATTR VkResult VKAPI_CALL GetVideoSessionMemoryRequirementsKHR(
    VkDevice                                    device,
    VkVideoSessionKHR                           videoSession,
    uint32_t*                                   pMemoryRequirementsCount,
    VkVideoSessionMemoryRequirementsKHR*        pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(VulkanCaptureManager::Get(), device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkVideoSessionKHR videoSession_unwrapped = GetWrappedHandle<VkVideoSessionKHR>(videoSession);

    VkResult result = GetDeviceTable(device)->GetVideoSessionMemoryRequirementsKHR(device_unwrapped, videoSession_unwrapped, pMemoryRequirementsCount, pMemoryRequirements);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(videoSession);
        encoder->EncodeUInt32Ptr(pMemoryRequirementsCount, omit_output_data);
        EncodeStructArray(encoder, pMemoryRequirements, (pMemoryRequirementsCount != nullptr) ? (*pMemoryRequirementsCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindVideoSessionMemoryKHR(
    VkDevice                                    device,
    VkVideoSessionKHR                           videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    const VkBindVideoSessionMemoryInfoKHR*      pBindSessionMemoryInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(VulkanCaptureManager::Get(), device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkVideoSessionKHR videoSession_unwrapped = GetWrappedHandle<VkVideoSessionKHR>(videoSession);
    const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos_unwrapped = UnwrapStructArrayHandles(pBindSessionMemoryInfos, bindSessionMemoryInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindVideoSessionMemoryKHR(device_unwrapped, videoSession_unwrapped, bindSessionMemoryInfoCount, pBindSessionMemoryInfos_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(videoSession);
        encoder->EncodeUInt32Value(bindSessionMemoryInfoCount);
        EncodeStructArray(encoder, pBindSessionMemoryInfos, bindSessionMemoryInfoCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateVideoSessionParametersKHR(
    VkDevice                                    device,
    const VkVideoSessionParametersCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkVideoSessionParametersKHR*                pVideoSessionParameters)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pVideoSessionParameters);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkVideoSessionParametersCreateInfoKHR* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateVideoSessionParametersKHR(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pVideoSessionParameters);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, VideoSessionParametersKHRWrapper>(device, NoParentWrapper::kHandleValue, pVideoSessionParameters, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pVideoSessionParameters, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, VideoSessionParametersKHRWrapper, VkVideoSessionParametersCreateInfoKHR>(result, device, pVideoSessionParameters, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pVideoSessionParameters);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL UpdateVideoSessionParametersKHR(
    VkDevice                                    device,
    VkVideoSessionParametersKHR                 videoSessionParameters,
    const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(VulkanCaptureManager::Get(), device, videoSessionParameters, pUpdateInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkVideoSessionParametersKHR videoSessionParameters_unwrapped = GetWrappedHandle<VkVideoSessionParametersKHR>(videoSessionParameters);

    VkResult result = GetDeviceTable(device)->UpdateVideoSessionParametersKHR(device_unwrapped, videoSessionParameters_unwrapped, pUpdateInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(videoSessionParameters);
        EncodeStructPtr(encoder, pUpdateInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, videoSessionParameters, pUpdateInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyVideoSessionParametersKHR(
    VkDevice                                    device,
    VkVideoSessionParametersKHR                 videoSessionParameters,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(VulkanCaptureManager::Get(), device, videoSessionParameters, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(videoSessionParameters);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<VideoSessionParametersKHRWrapper>(videoSessionParameters);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkVideoSessionParametersKHR videoSessionParameters_unwrapped = GetWrappedHandle<VkVideoSessionParametersKHR>(videoSessionParameters);

    GetDeviceTable(device)->DestroyVideoSessionParametersKHR(device_unwrapped, videoSessionParameters_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR>::Dispatch(VulkanCaptureManager::Get(), device, videoSessionParameters, pAllocator);

    DestroyWrappedHandle<VideoSessionParametersKHRWrapper>(videoSessionParameters);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pBeginInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pBeginInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBeginVideoCodingKHRHandles, pBeginInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkVideoBeginCodingInfoKHR* pBeginInfo_unwrapped = UnwrapStructPtrHandles(pBeginInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginVideoCodingKHR(commandBuffer_unwrapped, pBeginInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pEndCodingInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pEndCodingInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndVideoCodingKHR(commandBuffer_unwrapped, pEndCodingInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pEndCodingInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdControlVideoCodingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCodingControlInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pCodingControlInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdControlVideoCodingKHR(commandBuffer_unwrapped, pCodingControlInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCodingControlInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDecodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pDecodeInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pDecodeInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDecodeVideoKHRHandles, pDecodeInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkVideoDecodeInfoKHR* pDecodeInfo_unwrapped = UnwrapStructPtrHandles(pDecodeInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdDecodeVideoKHR(commandBuffer_unwrapped, pDecodeInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pDecodeInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderingKHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInfo*                      pRenderingInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRenderingInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderingInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBeginRenderingKHRHandles, pRenderingInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkRenderingInfo* pRenderingInfo_unwrapped = UnwrapStructPtrHandles(pRenderingInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginRenderingKHR(commandBuffer_unwrapped, pRenderingInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRenderingInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderingKHR(
    VkCommandBuffer                             commandBuffer)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndRenderingKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndRenderingKHR(commandBuffer_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderingKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFeatures);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures2KHR(physicalDevice_unwrapped, pFeatures);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice_unwrapped, pProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, format, pFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(physicalDevice_unwrapped, format, pFormatProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        EncodeStructPtr(encoder, pFormatProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice_unwrapped, pImageFormatInfo, pImageFormatProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pImageFormatInfo);
        EncodeStructPtr(encoder, pImageFormatProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice_unwrapped, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        EncodeStructArray(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pMemoryProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(physicalDevice_unwrapped, pMemoryProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pMemoryProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice_unwrapped, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pFormatInfo);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(VulkanCaptureManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->GetDeviceGroupPeerMemoryFeaturesKHR(device_unwrapped, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(VulkanCaptureManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, deviceMask);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDeviceMaskKHR(commandBuffer_unwrapped, deviceMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, deviceMask);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDispatchBaseKHR(commandBuffer_unwrapped, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(VulkanCaptureManager::Get(), device, commandPool, flags);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkTrimCommandPoolKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkCommandPool commandPool_unwrapped = GetWrappedHandle<VkCommandPool>(commandPool);

    GetDeviceTable(device)->TrimCommandPoolKHR(device_unwrapped, commandPool_unwrapped, flags);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(VulkanCaptureManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(VulkanCaptureManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->EnumeratePhysicalDeviceGroupsKHR(instance_unwrapped, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<InstanceWrapper, NoParentWrapper, VkPhysicalDeviceGroupProperties>(instance, NoParentWrapper::kHandleValue, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount, omit_output_data);
        EncodeStructArray(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndStructGroupCreateApiCallCapture<VkInstance, PhysicalDeviceWrapper, VkPhysicalDeviceGroupProperties>(result, instance, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, pPhysicalDeviceGroupProperties, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(VulkanCaptureManager::Get(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice_unwrapped, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalBufferInfo);
        EncodeStructPtr(encoder, pExternalBufferProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleKHR(
    VkDevice                                    device,
    const VkMemoryGetWin32HandleInfoKHR*        pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(VulkanCaptureManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetMemoryWin32HandleKHR(device_unwrapped, pGetWin32HandleInfo_unwrapped, pHandle);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandlePropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    VkMemoryWin32HandlePropertiesKHR*           pMemoryWin32HandleProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), device, handleType, handle, pMemoryWin32HandleProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetMemoryWin32HandlePropertiesKHR(device_unwrapped, handleType, handle, pMemoryWin32HandleProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(handle);
        EncodeStructPtr(encoder, pMemoryWin32HandleProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, handleType, handle, pMemoryWin32HandleProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(
    VkDevice                                    device,
    const VkMemoryGetFdInfoKHR*                 pGetFdInfo,
    int*                                        pFd)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(VulkanCaptureManager::Get(), device, pGetFdInfo, pFd);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMemoryGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetMemoryFdKHR(device_unwrapped, pGetFdInfo_unwrapped, pFd);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMemoryFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    VkMemoryFdPropertiesKHR*                    pMemoryFdProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), device, handleType, fd, pMemoryFdProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetMemoryFdPropertiesKHR(device_unwrapped, handleType, fd, pMemoryFdProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeInt32Value(fd);
        EncodeStructPtr(encoder, pMemoryFdProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, handleType, fd, pMemoryFdProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice_unwrapped, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalSemaphoreInfo);
        EncodeStructPtr(encoder, pExternalSemaphoreProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkImportSemaphoreWin32HandleInfoKHR*  pImportSemaphoreWin32HandleInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(VulkanCaptureManager::Get(), device, pImportSemaphoreWin32HandleInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreWin32HandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ImportSemaphoreWin32HandleKHR(device_unwrapped, pImportSemaphoreWin32HandleInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pImportSemaphoreWin32HandleInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pImportSemaphoreWin32HandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkSemaphoreGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(VulkanCaptureManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetSemaphoreWin32HandleKHR(device_unwrapped, pGetWin32HandleInfo_unwrapped, pHandle);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(
    VkDevice                                    device,
    const VkImportSemaphoreFdInfoKHR*           pImportSemaphoreFdInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(VulkanCaptureManager::Get(), device, pImportSemaphoreFdInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreFdInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ImportSemaphoreFdKHR(device_unwrapped, pImportSemaphoreFdInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pImportSemaphoreFdInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pImportSemaphoreFdInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(
    VkDevice                                    device,
    const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
    int*                                        pFd)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(VulkanCaptureManager::Get(), device, pGetFdInfo, pFd);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetSemaphoreFdKHR(device_unwrapped, pGetFdInfo_unwrapped, pFd);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pGetFdInfo, pFd);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleValue(layout);
        encoder->EncodeUInt32Value(set);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        EncodeStructArray(encoder, pDescriptorWrites, descriptorWriteCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdPushDescriptorSetKHRHandles, layout, descriptorWriteCount, pDescriptorWrites);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkPipelineLayout layout_unwrapped = GetWrappedHandle<VkPipelineLayout>(layout);
    const VkWriteDescriptorSet* pDescriptorWrites_unwrapped = UnwrapStructArrayHandles(pDescriptorWrites, descriptorWriteCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdPushDescriptorSetKHR(commandBuffer_unwrapped, pipelineBindPoint, layout_unwrapped, set, descriptorWriteCount, pDescriptorWrites_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateDescriptorUpdateTemplateKHR(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pDescriptorUpdateTemplate);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DescriptorUpdateTemplateWrapper>(device, NoParentWrapper::kHandleValue, pDescriptorUpdateTemplate, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDescriptorUpdateTemplate, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, DescriptorUpdateTemplateWrapper, VkDescriptorUpdateTemplateCreateInfo>(result, device, pDescriptorUpdateTemplate, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(VulkanCaptureManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorUpdateTemplate);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorUpdateTemplate descriptorUpdateTemplate_unwrapped = GetWrappedHandle<VkDescriptorUpdateTemplate>(descriptorUpdateTemplate);

    GetDeviceTable(device)->DestroyDescriptorUpdateTemplateKHR(device_unwrapped, descriptorUpdateTemplate_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(VulkanCaptureManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    DestroyWrappedHandle<DescriptorUpdateTemplateWrapper>(descriptorUpdateTemplate);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateRenderPass2KHR(device_unwrapped, pCreateInfo, pAllocator, pRenderPass);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, RenderPassWrapper>(device, NoParentWrapper::kHandleValue, pRenderPass, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pRenderPass, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, RenderPassWrapper, VkRenderPassCreateInfo2>(result, device, pRenderPass, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderPassBegin);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBeginRenderPass2KHRHandles, pRenderPassBegin);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkRenderPassBeginInfo* pRenderPassBegin_unwrapped = UnwrapStructPtrHandles(pRenderPassBegin, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginRenderPass2KHR(commandBuffer_unwrapped, pRenderPassBegin_unwrapped, pSubpassBeginInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfo*                   pSubpassBeginInfo,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdNextSubpass2KHR(commandBuffer_unwrapped, pSubpassBeginInfo, pSubpassEndInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfo*                     pSubpassEndInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pSubpassEndInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndRenderPass2KHR(commandBuffer_unwrapped, pSubpassEndInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pSubpassEndInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(VulkanCaptureManager::Get(), device, swapchain);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->GetSwapchainStatusKHR(device_unwrapped, swapchain_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, swapchain);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice_unwrapped, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalFenceInfo);
        EncodeStructPtr(encoder, pExternalFenceProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkImportFenceWin32HandleInfoKHR*      pImportFenceWin32HandleInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(VulkanCaptureManager::Get(), device, pImportFenceWin32HandleInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pImportFenceWin32HandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ImportFenceWin32HandleKHR(device_unwrapped, pImportFenceWin32HandleInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pImportFenceWin32HandleInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pImportFenceWin32HandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkFenceGetWin32HandleInfoKHR*         pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(VulkanCaptureManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo_unwrapped = UnwrapStructPtrHandles(pGetWin32HandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetFenceWin32HandleKHR(device_unwrapped, pGetWin32HandleInfo_unwrapped, pHandle);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(
    VkDevice                                    device,
    const VkImportFenceFdInfoKHR*               pImportFenceFdInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(VulkanCaptureManager::Get(), device, pImportFenceFdInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImportFenceFdInfoKHR* pImportFenceFdInfo_unwrapped = UnwrapStructPtrHandles(pImportFenceFdInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ImportFenceFdKHR(device_unwrapped, pImportFenceFdInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkImportFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pImportFenceFdInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pImportFenceFdInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(
    VkDevice                                    device,
    const VkFenceGetFdInfoKHR*                  pGetFdInfo,
    int*                                        pFd)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(VulkanCaptureManager::Get(), device, pGetFdInfo, pFd);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkFenceGetFdInfoKHR* pGetFdInfo_unwrapped = UnwrapStructPtrHandles(pGetFdInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetFenceFdKHR(device_unwrapped, pGetFdInfo_unwrapped, pFd);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint32_t*                                   pCounterCount,
    VkPerformanceCounterKHR*                    pCounters,
    VkPerformanceCounterDescriptionKHR*         pCounterDescriptions)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice_unwrapped, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeUInt32Ptr(pCounterCount, omit_output_data);
        EncodeStructArray(encoder, pCounters, (pCounterCount != nullptr) ? (*pCounterCount) : 0, omit_output_data);
        EncodeStructArray(encoder, pCounterDescriptions, (pCounterCount != nullptr) ? (*pCounterCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkQueryPoolPerformanceCreateInfoKHR*  pPerformanceQueryCreateInfo,
    uint32_t*                                   pNumPasses)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice_unwrapped, pPerformanceQueryCreateInfo, pNumPasses);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pPerformanceQueryCreateInfo);
        encoder->EncodeUInt32Ptr(pNumPasses);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireProfilingLockKHR(
    VkDevice                                    device,
    const VkAcquireProfilingLockInfoKHR*        pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->AcquireProfilingLockKHR(device_unwrapped, pInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL ReleaseProfilingLockKHR(
    VkDevice                                    device)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(VulkanCaptureManager::Get(), device);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->ReleaseProfilingLockKHR(device_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR>::Dispatch(VulkanCaptureManager::Get(), device);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice_unwrapped, pSurfaceInfo_unwrapped, pSurfaceCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        EncodeStructPtr(encoder, pSurfaceCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormat2KHR*                        pSurfaceFormats)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice_unwrapped, pSurfaceInfo_unwrapped, pSurfaceFormatCount, pSurfaceFormats);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount, omit_output_data);
        EncodeStructArray(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayProperties2KHR*                    pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayProperties2KHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndStructGroupCreateApiCallCapture<VkPhysicalDevice, DisplayKHRWrapper, VkDisplayProperties2KHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayProperties2KHR* handle_struct)->DisplayKHRWrapper* { return reinterpret_cast<DisplayKHRWrapper*>(handle_struct->displayProperties.display); });
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlaneProperties2KHR*               pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, NoParentWrapper, VkDisplayPlaneProperties2KHR>(physicalDevice, NoParentWrapper::kHandleValue, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndStructGroupCreateApiCallCapture<VkPhysicalDevice, DisplayKHRWrapper, VkDisplayPlaneProperties2KHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayPlaneProperties2KHR* handle_struct)->DisplayKHRWrapper* { return reinterpret_cast<DisplayKHRWrapper*>(handle_struct->displayPlaneProperties.currentDisplay); });
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModeProperties2KHR*                pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->GetDisplayModeProperties2KHR(physicalDevice_unwrapped, display_unwrapped, pPropertyCount, pProperties);

    if (result >= 0)
    {
        CreateWrappedStructArrayHandles<PhysicalDeviceWrapper, DisplayKHRWrapper, VkDisplayModeProperties2KHR>(physicalDevice, display, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndStructGroupCreateApiCallCapture<VkPhysicalDevice, DisplayModeKHRWrapper, VkDisplayModeProperties2KHR>(result, physicalDevice, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, pProperties, [](VkDisplayModeProperties2KHR* handle_struct)->DisplayModeKHRWrapper* { return reinterpret_cast<DisplayModeKHRWrapper*>(handle_struct->displayModeProperties.displayMode); });
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
    VkDisplayPlaneCapabilities2KHR*             pCapabilities)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pDisplayPlaneInfo, pCapabilities);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo_unwrapped = UnwrapStructPtrHandles(pDisplayPlaneInfo, handle_unwrap_memory);

    VkResult result = GetInstanceTable(physicalDevice)->GetDisplayPlaneCapabilities2KHR(physicalDevice_unwrapped, pDisplayPlaneInfo_unwrapped, pCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pDisplayPlaneInfo);
        EncodeStructPtr(encoder, pCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pDisplayPlaneInfo, pCapabilities);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetImageMemoryRequirements2KHR(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetBufferMemoryRequirements2KHR(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageSparseMemoryRequirementsInfo2* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetImageSparseMemoryRequirements2KHR(device_unwrapped, pInfo_unwrapped, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversionKHR(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateSamplerYcbcrConversionKHR(device_unwrapped, pCreateInfo, pAllocator, pYcbcrConversion);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, SamplerYcbcrConversionWrapper>(device, NoParentWrapper::kHandleValue, pYcbcrConversion, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pYcbcrConversion, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, SamplerYcbcrConversionWrapper, VkSamplerYcbcrConversionCreateInfo>(result, device, pYcbcrConversion, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(VulkanCaptureManager::Get(), device, ycbcrConversion, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(ycbcrConversion);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<SamplerYcbcrConversionWrapper>(ycbcrConversion);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSamplerYcbcrConversion ycbcrConversion_unwrapped = GetWrappedHandle<VkSamplerYcbcrConversion>(ycbcrConversion);

    GetDeviceTable(device)->DestroySamplerYcbcrConversionKHR(device_unwrapped, ycbcrConversion_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(VulkanCaptureManager::Get(), device, ycbcrConversion, pAllocator);

    DestroyWrappedHandle<SamplerYcbcrConversionWrapper>(ycbcrConversion);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(VulkanCaptureManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindBufferMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindBufferMemory2KHR(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkBindBufferMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(VulkanCaptureManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(VulkanCaptureManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindImageMemoryInfo* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindImageMemory2KHR(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkBindImageMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(VulkanCaptureManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pSupport);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorSetLayoutCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetDescriptorSetLayoutSupportKHR(device_unwrapped, pCreateInfo_unwrapped, pSupport);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pSupport);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pSupport);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawIndirectCountKHRHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndirectCountKHR(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawIndexedIndirectCountKHRHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirectCountKHR(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreCounterValueKHR(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    uint64_t*                                   pValue)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(VulkanCaptureManager::Get(), device, semaphore, pValue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSemaphore semaphore_unwrapped = GetWrappedHandle<VkSemaphore>(semaphore);

    VkResult result = GetDeviceTable(device)->GetSemaphoreCounterValueKHR(device_unwrapped, semaphore_unwrapped, pValue);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(semaphore);
        encoder->EncodeUInt64Ptr(pValue, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, semaphore, pValue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitSemaphoresKHR(
    VkDevice                                    device,
    const VkSemaphoreWaitInfo*                  pWaitInfo,
    uint64_t                                    timeout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(VulkanCaptureManager::Get(), device, pWaitInfo, timeout);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreWaitInfo* pWaitInfo_unwrapped = UnwrapStructPtrHandles(pWaitInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->WaitSemaphoresKHR(device_unwrapped, pWaitInfo_unwrapped, timeout);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkWaitSemaphoresKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pWaitInfo);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitSemaphoresKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pWaitInfo, timeout);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SignalSemaphoreKHR(
    VkDevice                                    device,
    const VkSemaphoreSignalInfo*                pSignalInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(VulkanCaptureManager::Get(), device, pSignalInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreSignalInfo* pSignalInfo_unwrapped = UnwrapStructPtrHandles(pSignalInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->SignalSemaphoreKHR(device_unwrapped, pSignalInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSignalSemaphoreKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pSignalInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSignalSemaphoreKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pSignalInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceFragmentShadingRatesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pFragmentShadingRateCount,
    VkPhysicalDeviceFragmentShadingRateKHR*     pFragmentShadingRates)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice_unwrapped, pFragmentShadingRateCount, pFragmentShadingRates);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pFragmentShadingRateCount, omit_output_data);
        EncodeStructArray(encoder, pFragmentShadingRates, (pFragmentShadingRateCount != nullptr) ? (*pFragmentShadingRateCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateKHR(
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2])
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pFragmentSize, combinerOps);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pFragmentSize);
        encoder->EncodeEnumArray(combinerOps, 2);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetFragmentShadingRateKHR(commandBuffer_unwrapped, pFragmentSize, combinerOps);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pFragmentSize, combinerOps);
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForPresentKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(VulkanCaptureManager::Get(), device, swapchain, presentId, timeout);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->WaitForPresentKHR(device_unwrapped, swapchain_unwrapped, presentId, timeout);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkWaitForPresentKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeUInt64Value(presentId);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForPresentKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, swapchain, presentId, timeout);

    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressKHR(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkDeviceAddress result = GetDeviceTable(device)->GetBufferDeviceAddressKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVkDeviceAddressValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetBufferOpaqueCaptureAddressKHR(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    uint64_t result = GetDeviceTable(device)->GetBufferOpaqueCaptureAddressKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt64Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR uint64_t VKAPI_CALL GetDeviceMemoryOpaqueCaptureAddressKHR(
    VkDevice                                    device,
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    uint64_t result = GetDeviceTable(device)->GetDeviceMemoryOpaqueCaptureAddressKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt64Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDeferredOperationKHR(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator,
    VkDeferredOperationKHR*                     pDeferredOperation)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(VulkanCaptureManager::Get(), device, pAllocator, pDeferredOperation);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateDeferredOperationKHR(device_unwrapped, pAllocator, pDeferredOperation);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DeferredOperationKHRWrapper>(device, NoParentWrapper::kHandleValue, pDeferredOperation, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pDeferredOperation, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, DeferredOperationKHRWrapper, void>(result, device, pDeferredOperation, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pAllocator, pDeferredOperation);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDeferredOperationKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(VulkanCaptureManager::Get(), device, operation, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(operation);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<DeferredOperationKHRWrapper>(operation);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR operation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(operation);

    GetDeviceTable(device)->DestroyDeferredOperationKHR(device_unwrapped, operation_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR>::Dispatch(VulkanCaptureManager::Get(), device, operation, pAllocator);

    DestroyWrappedHandle<DeferredOperationKHRWrapper>(operation);
}

VKAPI_ATTR uint32_t VKAPI_CALL GetDeferredOperationMaxConcurrencyKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(VulkanCaptureManager::Get(), device, operation);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR operation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(operation);

    uint32_t result = GetDeviceTable(device)->GetDeferredOperationMaxConcurrencyKHR(device_unwrapped, operation_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(operation);
        encoder->EncodeUInt32Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, operation);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeferredOperationResultKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(VulkanCaptureManager::Get(), device, operation);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR operation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(operation);

    VkResult result = GetDeviceTable(device)->GetDeferredOperationResultKHR(device_unwrapped, operation_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(operation);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, operation);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeferredOperationJoinKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      operation)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(VulkanCaptureManager::Get(), device, operation);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR operation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(operation);

    VkResult result = GetDeviceTable(device)->DeferredOperationJoinKHR(device_unwrapped, operation_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(operation);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, operation);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutablePropertiesKHR(
    VkDevice                                    device,
    const VkPipelineInfoKHR*                    pPipelineInfo,
    uint32_t*                                   pExecutableCount,
    VkPipelineExecutablePropertiesKHR*          pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), device, pPipelineInfo, pExecutableCount, pProperties);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkPipelineInfoKHR* pPipelineInfo_unwrapped = UnwrapStructPtrHandles(pPipelineInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetPipelineExecutablePropertiesKHR(device_unwrapped, pPipelineInfo_unwrapped, pExecutableCount, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pPipelineInfo);
        encoder->EncodeUInt32Ptr(pExecutableCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pExecutableCount != nullptr) ? (*pExecutableCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pPipelineInfo, pExecutableCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableStatisticsKHR(
    VkDevice                                    device,
    const VkPipelineExecutableInfoKHR*          pExecutableInfo,
    uint32_t*                                   pStatisticCount,
    VkPipelineExecutableStatisticKHR*           pStatistics)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(VulkanCaptureManager::Get(), device, pExecutableInfo, pStatisticCount, pStatistics);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkPipelineExecutableInfoKHR* pExecutableInfo_unwrapped = UnwrapStructPtrHandles(pExecutableInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetPipelineExecutableStatisticsKHR(device_unwrapped, pExecutableInfo_unwrapped, pStatisticCount, pStatistics);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pExecutableInfo);
        encoder->EncodeUInt32Ptr(pStatisticCount, omit_output_data);
        EncodeStructArray(encoder, pStatistics, (pStatisticCount != nullptr) ? (*pStatisticCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pExecutableInfo, pStatisticCount, pStatistics);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineExecutableInternalRepresentationsKHR(
    VkDevice                                    device,
    const VkPipelineExecutableInfoKHR*          pExecutableInfo,
    uint32_t*                                   pInternalRepresentationCount,
    VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(VulkanCaptureManager::Get(), device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkPipelineExecutableInfoKHR* pExecutableInfo_unwrapped = UnwrapStructPtrHandles(pExecutableInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetPipelineExecutableInternalRepresentationsKHR(device_unwrapped, pExecutableInfo_unwrapped, pInternalRepresentationCount, pInternalRepresentations);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pExecutableInfo);
        encoder->EncodeUInt32Ptr(pInternalRepresentationCount, omit_output_data);
        EncodeStructArray(encoder, pInternalRepresentations, (pInternalRepresentationCount != nullptr) ? (*pInternalRepresentationCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdEncodeVideoKHR(
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pEncodeInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pEncodeInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdEncodeVideoKHRHandles, pEncodeInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkVideoEncodeInfoKHR* pEncodeInfo_unwrapped = UnwrapStructPtrHandles(pEncodeInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdEncodeVideoKHR(commandBuffer_unwrapped, pEncodeInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pEncodeInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, pDependencyInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetEvent2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(event);
        EncodeStructPtr(encoder, pDependencyInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdSetEvent2KHRHandles, event, pDependencyInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);
    const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdSetEvent2KHR(commandBuffer_unwrapped, event_unwrapped, pDependencyInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, pDependencyInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent2KHR(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, stageMask);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdResetEvent2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(event);
        encoder->EncodeFlags64Value(stageMask);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdResetEvent2KHRHandles, event);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkEvent event_unwrapped = GetWrappedHandle<VkEvent>(event);

    GetDeviceTable(commandBuffer)->CmdResetEvent2KHR(commandBuffer_unwrapped, event_unwrapped, stageMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents2KHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, eventCount, pEvents, pDependencyInfos);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(eventCount);
        encoder->EncodeHandleArray(pEvents, eventCount);
        EncodeStructArray(encoder, pDependencyInfos, eventCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWaitEvents2KHRHandles, eventCount, pEvents, pDependencyInfos);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkEvent* pEvents_unwrapped = UnwrapHandles<VkEvent>(pEvents, eventCount, handle_unwrap_memory);
    const VkDependencyInfo* pDependencyInfos_unwrapped = UnwrapStructArrayHandles(pDependencyInfos, eventCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdWaitEvents2KHR(commandBuffer_unwrapped, eventCount, pEvents_unwrapped, pDependencyInfos_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, eventCount, pEvents, pDependencyInfos);
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pDependencyInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pDependencyInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdPipelineBarrier2KHRHandles, pDependencyInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkDependencyInfo* pDependencyInfo_unwrapped = UnwrapStructPtrHandles(pDependencyInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdPipelineBarrier2KHR(commandBuffer_unwrapped, pDependencyInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pDependencyInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp2KHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stage, queryPool, query);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlags64Value(stage);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWriteTimestamp2KHRHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdWriteTimestamp2KHR(commandBuffer_unwrapped, stage, queryPool_unwrapped, query);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stage, queryPool, query);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit2KHR(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo2*                        pSubmits,
    VkFence                                     fence)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(VulkanCaptureManager::Get(), queue, submitCount, pSubmits, fence);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);
    const VkSubmitInfo2* pSubmits_unwrapped = UnwrapStructArrayHandles(pSubmits, submitCount, handle_unwrap_memory);
    VkFence fence_unwrapped = GetWrappedHandle<VkFence>(fence);

    VkResult result = GetDeviceTable(queue)->QueueSubmit2KHR(queue_unwrapped, submitCount, pSubmits_unwrapped, fence_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkQueueSubmit2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Value(submitCount);
        EncodeStructArray(encoder, pSubmits, submitCount);
        encoder->EncodeHandleValue(fence);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit2KHR>::Dispatch(VulkanCaptureManager::Get(), result, queue, submitCount, pSubmits, fence);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarker2AMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stage, dstBuffer, dstOffset, marker);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlags64Value(stage);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeUInt32Value(marker);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWriteBufferMarker2AMDHandles, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdWriteBufferMarker2AMD(commandBuffer_unwrapped, stage, dstBuffer_unwrapped, dstOffset, marker);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stage, dstBuffer, dstOffset, marker);
}

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointData2NV(
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointData2NV*                        pCheckpointData)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(VulkanCaptureManager::Get(), queue, pCheckpointDataCount, pCheckpointData);

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    GetDeviceTable(queue)->GetQueueCheckpointData2NV(queue_unwrapped, pCheckpointDataCount, pCheckpointData);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Ptr(pCheckpointDataCount);
        EncodeStructArray(encoder, pCheckpointData, (pCheckpointDataCount != nullptr) ? (*pCheckpointDataCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV>::Dispatch(VulkanCaptureManager::Get(), queue, pCheckpointDataCount, pCheckpointData);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyBufferInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pCopyBufferInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyBuffer2KHRHandles, pCopyBufferInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyBufferInfo2* pCopyBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyBuffer2KHR(commandBuffer_unwrapped, pCopyBufferInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyBufferInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyImageInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyImage2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pCopyImageInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyImage2KHRHandles, pCopyImageInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyImageInfo2* pCopyImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyImage2KHR(commandBuffer_unwrapped, pCopyImageInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyBufferToImageInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pCopyBufferToImageInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyBufferToImage2KHRHandles, pCopyBufferToImageInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo_unwrapped = UnwrapStructPtrHandles(pCopyBufferToImageInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyBufferToImage2KHR(commandBuffer_unwrapped, pCopyBufferToImageInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyBufferToImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyImageToBufferInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pCopyImageToBufferInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyImageToBuffer2KHRHandles, pCopyImageToBufferInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo_unwrapped = UnwrapStructPtrHandles(pCopyImageToBufferInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyImageToBuffer2KHR(commandBuffer_unwrapped, pCopyImageToBufferInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCopyImageToBufferInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pBlitImageInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBlitImage2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pBlitImageInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBlitImage2KHRHandles, pBlitImageInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBlitImageInfo2* pBlitImageInfo_unwrapped = UnwrapStructPtrHandles(pBlitImageInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBlitImage2KHR(commandBuffer_unwrapped, pBlitImageInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pBlitImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pResolveImageInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdResolveImage2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pResolveImageInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdResolveImage2KHRHandles, pResolveImageInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkResolveImageInfo2* pResolveImageInfo_unwrapped = UnwrapStructPtrHandles(pResolveImageInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdResolveImage2KHR(commandBuffer_unwrapped, pResolveImageInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pResolveImageInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirect2KHR(
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, indirectDeviceAddress);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkDeviceAddressValue(indirectDeviceAddress);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdTraceRaysIndirect2KHR(commandBuffer_unwrapped, indirectDeviceAddress);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, indirectDeviceAddress);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceBufferMemoryRequirementsKHR(
    VkDevice                                    device,
    const VkDeviceBufferMemoryRequirements*     pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDeviceBufferMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetDeviceBufferMemoryRequirementsKHR(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageMemoryRequirementsKHR(
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetDeviceImageMemoryRequirementsKHR(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceImageSparseMemoryRequirementsKHR(
    VkDevice                                    device,
    const VkDeviceImageMemoryRequirements*      pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDeviceImageMemoryRequirements* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetDeviceImageSparseMemoryRequirementsKHR(device_unwrapped, pInfo_unwrapped, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT(
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pCallback);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateDebugReportCallbackEXT(instance_unwrapped, pCreateInfo, pAllocator, pCallback);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, DebugReportCallbackEXTWrapper>(instance, NoParentWrapper::kHandleValue, pCallback, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pCallback, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, DebugReportCallbackEXTWrapper, VkDebugReportCallbackCreateInfoEXT>(result, instance, pCallback, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pCallback);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(VulkanCaptureManager::Get(), instance, callback, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeHandleValue(callback);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<DebugReportCallbackEXTWrapper>(callback);
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);
    VkDebugReportCallbackEXT callback_unwrapped = GetWrappedHandle<VkDebugReportCallbackEXT>(callback);

    GetInstanceTable(instance)->DestroyDebugReportCallbackEXT(instance_unwrapped, callback_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(VulkanCaptureManager::Get(), instance, callback, pAllocator);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(VulkanCaptureManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkDebugReportMessageEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(GetWrappedId(object, objectType));
        encoder->EncodeSizeTValue(location);
        encoder->EncodeInt32Value(messageCode);
        encoder->EncodeString(pLayerPrefix);
        encoder->EncodeString(pMessage);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);
    uint64_t object_unwrapped = GetWrappedHandle(object, objectType);

    GetInstanceTable(instance)->DebugReportMessageEXT(instance_unwrapped, flags, objectType, object_unwrapped, location, messageCode, pLayerPrefix, pMessage);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(VulkanCaptureManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectTagInfoEXT*        pTagInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(VulkanCaptureManager::Get(), device, pTagInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDebugMarkerObjectTagInfoEXT* pTagInfo_unwrapped = UnwrapStructPtrHandles(pTagInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->DebugMarkerSetObjectTagEXT(device_unwrapped, pTagInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pTagInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pTagInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectNameEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectNameInfoEXT*       pNameInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(VulkanCaptureManager::Get(), device, pNameInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDebugMarkerObjectNameInfoEXT* pNameInfo_unwrapped = UnwrapStructPtrHandles(pNameInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->DebugMarkerSetObjectNameEXT(device_unwrapped, pNameInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pNameInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pNameInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pMarkerInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer_unwrapped, pMarkerInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pMarkerInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer_unwrapped, pMarkerInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pSizes, bindingCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBindTransformFeedbackBuffersEXTHandles, bindingCount, pBuffers);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pBuffers_unwrapped = UnwrapHandles<VkBuffer>(pBuffers, bindingCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBindTransformFeedbackBuffersEXT(commandBuffer_unwrapped, firstBinding, bindingCount, pBuffers_unwrapped, pOffsets, pSizes);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstCounterBuffer);
        encoder->EncodeUInt32Value(counterBufferCount);
        encoder->EncodeHandleArray(pCounterBuffers, counterBufferCount);
        encoder->EncodeVkDeviceSizeArray(pCounterBufferOffsets, counterBufferCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBeginTransformFeedbackEXTHandles, counterBufferCount, pCounterBuffers);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pCounterBuffers_unwrapped = UnwrapHandles<VkBuffer>(pCounterBuffers, counterBufferCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginTransformFeedbackEXT(commandBuffer_unwrapped, firstCounterBuffer, counterBufferCount, pCounterBuffers_unwrapped, pCounterBufferOffsets);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstCounterBuffer);
        encoder->EncodeUInt32Value(counterBufferCount);
        encoder->EncodeHandleArray(pCounterBuffers, counterBufferCount);
        encoder->EncodeVkDeviceSizeArray(pCounterBufferOffsets, counterBufferCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdEndTransformFeedbackEXTHandles, counterBufferCount, pCounterBuffers);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pCounterBuffers_unwrapped = UnwrapHandles<VkBuffer>(pCounterBuffers, counterBufferCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdEndTransformFeedbackEXT(commandBuffer_unwrapped, firstCounterBuffer, counterBufferCount, pCounterBuffers_unwrapped, pCounterBufferOffsets);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, query, flags, index);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeUInt32Value(index);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBeginQueryIndexedEXTHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdBeginQueryIndexedEXT(commandBuffer_unwrapped, queryPool_unwrapped, query, flags, index);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, query, flags, index);
}

VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, query, index);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeUInt32Value(index);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdEndQueryIndexedEXTHandles, queryPool);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdEndQueryIndexedEXT(commandBuffer_unwrapped, queryPool_unwrapped, query, index);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, queryPool, query, index);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstInstance);
        encoder->EncodeHandleValue(counterBuffer);
        encoder->EncodeVkDeviceSizeValue(counterBufferOffset);
        encoder->EncodeUInt32Value(counterOffset);
        encoder->EncodeUInt32Value(vertexStride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawIndirectByteCountEXTHandles, counterBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer counterBuffer_unwrapped = GetWrappedHandle<VkBuffer>(counterBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndirectByteCountEXT(commandBuffer_unwrapped, instanceCount, firstInstance, counterBuffer_unwrapped, counterBufferOffset, counterOffset, vertexStride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

VKAPI_ATTR uint32_t VKAPI_CALL GetImageViewHandleNVX(
    VkDevice                                    device,
    const VkImageViewHandleInfoNVX*             pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(VulkanCaptureManager::Get(), device, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImageViewHandleInfoNVX* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    uint32_t result = GetDeviceTable(device)->GetImageViewHandleNVX(device_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageViewHandleNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewHandleNVX>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetImageViewAddressNVX(
    VkDevice                                    device,
    VkImageView                                 imageView,
    VkImageViewAddressPropertiesNVX*            pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(VulkanCaptureManager::Get(), device, imageView, pProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImageView imageView_unwrapped = GetWrappedHandle<VkImageView>(imageView);

    VkResult result = GetDeviceTable(device)->GetImageViewAddressNVX(device_unwrapped, imageView_unwrapped, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageViewAddressNVX);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(imageView);
        EncodeStructPtr(encoder, pProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageViewAddressNVX>::Dispatch(VulkanCaptureManager::Get(), result, device, imageView, pProperties);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawIndirectCountAMDHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndirectCountAMD(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawIndexedIndirectCountAMDHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirectCountAMD(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL GetShaderInfoAMD(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    size_t*                                     pInfoSize,
    void*                                       pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(VulkanCaptureManager::Get(), device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkResult result = GetDeviceTable(device)->GetShaderInfoAMD(device_unwrapped, pipeline_unwrapped, shaderStage, infoType, pInfoSize, pInfo);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetShaderInfoAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeEnumValue(shaderStage);
        encoder->EncodeEnumValue(infoType);
        encoder->EncodeSizeTPtr(pInfoSize, omit_output_data);
        encoder->EncodeVoidArray(pInfo, (pInfoSize != nullptr) ? (*pInfoSize) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(VulkanCaptureManager::Get(), result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateStreamDescriptorSurfaceGGP(
    VkInstance                                  instance,
    const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateStreamDescriptorSurfaceGGP(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkStreamDescriptorSurfaceCreateInfoGGP>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice_unwrapped, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
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
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleNV(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    HANDLE*                                     pHandle)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(VulkanCaptureManager::Get(), device, memory, handleType, pHandle);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    VkResult result = GetDeviceTable(device)->GetMemoryWin32HandleNV(device_unwrapped, memory_unwrapped, handleType, pHandle);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeFlagsValue(handleType);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(VulkanCaptureManager::Get(), result, device, memory, handleType, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateViSurfaceNN(
    VkInstance                                  instance,
    const VkViSurfaceCreateInfoNN*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateViSurfaceNN(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateViSurfaceNN);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkViSurfaceCreateInfoNN>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pConditionalRenderingBegin);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pConditionalRenderingBegin);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBeginConditionalRenderingEXTHandles, pConditionalRenderingBegin);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin_unwrapped = UnwrapStructPtrHandles(pConditionalRenderingBegin, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBeginConditionalRenderingEXT(commandBuffer_unwrapped, pConditionalRenderingBegin_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pConditionalRenderingBegin);
}

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndConditionalRenderingEXT(commandBuffer_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewportWScalings, viewportCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewportWScalingNV(commandBuffer_unwrapped, firstViewport, viewportCount, pViewportWScalings);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, display);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->ReleaseDisplayEXT(physicalDevice_unwrapped, display_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkReleaseDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireXlibDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    VkDisplayKHR                                display)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, dpy, display);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->AcquireXlibDisplayEXT(physicalDevice_unwrapped, dpy, display_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeHandleValue(display);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, dpy, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRandROutputDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    RROutput                                    rrOutput,
    VkDisplayKHR*                               pDisplay)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, dpy, rrOutput, pDisplay);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetRandROutputDisplayEXT(physicalDevice_unwrapped, dpy, rrOutput, pDisplay);

    if (result >= 0)
    {
        CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DisplayKHRWrapper>(physicalDevice, NoParentWrapper::kHandleValue, pDisplay, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeSizeTValue(rrOutput);
        encoder->EncodeHandlePtr(pDisplay, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkPhysicalDevice, DisplayKHRWrapper, void>(result, physicalDevice, pDisplay, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, dpy, rrOutput, pDisplay);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilities2EXT*                  pSurfaceCapabilities)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkSurfaceKHR surface_unwrapped = GetWrappedHandle<VkSurfaceKHR>(surface);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice_unwrapped, surface_unwrapped, pSurfaceCapabilities);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(surface);
        EncodeStructPtr(encoder, pSurfaceCapabilities, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, surface, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayPowerInfoEXT*                pDisplayPowerInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(VulkanCaptureManager::Get(), device, display, pDisplayPowerInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetDeviceTable(device)->DisplayPowerControlEXT(device_unwrapped, display_unwrapped, pDisplayPowerInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkDisplayPowerControlEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(display);
        EncodeStructPtr(encoder, pDisplayPowerInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, display, pDisplayPowerInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(
    VkDevice                                    device,
    const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(VulkanCaptureManager::Get(), device, pDeviceEventInfo, pAllocator, pFence);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->RegisterDeviceEventEXT(device_unwrapped, pDeviceEventInfo, pAllocator, pFence);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, FenceWrapper>(device, NoParentWrapper::kHandleValue, pFence, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pDeviceEventInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFence, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, FenceWrapper, void>(result, device, pFence, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pDeviceEventInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayEventInfoEXT*                pDisplayEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(VulkanCaptureManager::Get(), device, display, pDisplayEventInfo, pAllocator, pFence);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetDeviceTable(device)->RegisterDisplayEventEXT(device_unwrapped, display_unwrapped, pDisplayEventInfo, pAllocator, pFence);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, DisplayKHRWrapper, FenceWrapper>(device, display, pFence, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(display);
        EncodeStructPtr(encoder, pDisplayEventInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pFence, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, FenceWrapper, void>(result, device, pFence, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, display, pDisplayEventInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    uint64_t*                                   pCounterValue)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(VulkanCaptureManager::Get(), device, swapchain, counter, pCounterValue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->GetSwapchainCounterEXT(device_unwrapped, swapchain_unwrapped, counter, pCounterValue);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeEnumValue(counter);
        encoder->EncodeUInt64Ptr(pCounterValue, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, swapchain, counter, pCounterValue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRefreshCycleDurationGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkRefreshCycleDurationGOOGLE*               pDisplayTimingProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(VulkanCaptureManager::Get(), device, swapchain, pDisplayTimingProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->GetRefreshCycleDurationGOOGLE(device_unwrapped, swapchain_unwrapped, pDisplayTimingProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        EncodeStructPtr(encoder, pDisplayTimingProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(VulkanCaptureManager::Get(), result, device, swapchain, pDisplayTimingProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPastPresentationTimingGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pPresentationTimingCount,
    VkPastPresentationTimingGOOGLE*             pPresentationTimings)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(VulkanCaptureManager::Get(), device, swapchain, pPresentationTimingCount, pPresentationTimings);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->GetPastPresentationTimingGOOGLE(device_unwrapped, swapchain_unwrapped, pPresentationTimingCount, pPresentationTimings);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeUInt32Ptr(pPresentationTimingCount, omit_output_data);
        EncodeStructArray(encoder, pPresentationTimings, (pPresentationTimingCount != nullptr) ? (*pPresentationTimingCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(VulkanCaptureManager::Get(), result, device, swapchain, pPresentationTimingCount, pPresentationTimings);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstDiscardRectangle);
        encoder->EncodeUInt32Value(discardRectangleCount);
        EncodeStructArray(encoder, pDiscardRectangles, discardRectangleCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDiscardRectangleEXT(commandBuffer_unwrapped, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainKHR*                       pSwapchains,
    const VkHdrMetadataEXT*                     pMetadata)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(VulkanCaptureManager::Get(), device, swapchainCount, pSwapchains, pMetadata);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSetHdrMetadataEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        encoder->EncodeHandleArray(pSwapchains, swapchainCount);
        EncodeStructArray(encoder, pMetadata, swapchainCount);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSwapchainKHR* pSwapchains_unwrapped = UnwrapHandles<VkSwapchainKHR>(pSwapchains, swapchainCount, handle_unwrap_memory);

    GetDeviceTable(device)->SetHdrMetadataEXT(device_unwrapped, swapchainCount, pSwapchains_unwrapped, pMetadata);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(VulkanCaptureManager::Get(), device, swapchainCount, pSwapchains, pMetadata);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK(
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateIOSSurfaceMVK(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkIOSSurfaceCreateInfoMVK>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateMacOSSurfaceMVK(
    VkInstance                                  instance,
    const VkMacOSSurfaceCreateInfoMVK*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateMacOSSurfaceMVK(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkMacOSSurfaceCreateInfoMVK>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectNameInfoEXT*        pNameInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(VulkanCaptureManager::Get(), device, pNameInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDebugUtilsObjectNameInfoEXT* pNameInfo_unwrapped = UnwrapStructPtrHandles(pNameInfo, handle_unwrap_memory);

    auto device_wrapper = reinterpret_cast<DeviceWrapper*>(device);
    auto physical_device = reinterpret_cast<VkPhysicalDevice>(device_wrapper->physical_device);
    VkResult result = GetInstanceTable(physical_device)->SetDebugUtilsObjectNameEXT(device_unwrapped, pNameInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pNameInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pNameInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectTagInfoEXT*         pTagInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(VulkanCaptureManager::Get(), device, pTagInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDebugUtilsObjectTagInfoEXT* pTagInfo_unwrapped = UnwrapStructPtrHandles(pTagInfo, handle_unwrap_memory);

    auto device_wrapper = reinterpret_cast<DeviceWrapper*>(device);
    auto physical_device = reinterpret_cast<VkPhysicalDevice>(device_wrapper->physical_device);
    VkResult result = GetInstanceTable(physical_device)->SetDebugUtilsObjectTagEXT(device_unwrapped, pTagInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pTagInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pTagInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), queue, pLabelInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        EncodeStructPtr(encoder, pLabelInfo);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    GetDeviceTable(queue)->QueueBeginDebugUtilsLabelEXT(queue_unwrapped, pLabelInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), queue);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    GetDeviceTable(queue)->QueueEndDebugUtilsLabelEXT(queue_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), queue);
}

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), queue, pLabelInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        EncodeStructPtr(encoder, pLabelInfo);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    GetDeviceTable(queue)->QueueInsertDebugUtilsLabelEXT(queue_unwrapped, pLabelInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pLabelInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pLabelInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer_unwrapped, pLabelInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pLabelInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pLabelInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer_unwrapped, pLabelInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pMessenger);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateDebugUtilsMessengerEXT(instance_unwrapped, pCreateInfo, pAllocator, pMessenger);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, DebugUtilsMessengerEXTWrapper>(instance, NoParentWrapper::kHandleValue, pMessenger, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pMessenger, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, DebugUtilsMessengerEXTWrapper, VkDebugUtilsMessengerCreateInfoEXT>(result, instance, pMessenger, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pMessenger);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(VulkanCaptureManager::Get(), instance, messenger, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeHandleValue(messenger);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<DebugUtilsMessengerEXTWrapper>(messenger);
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);
    VkDebugUtilsMessengerEXT messenger_unwrapped = GetWrappedHandle<VkDebugUtilsMessengerEXT>(messenger);

    GetInstanceTable(instance)->DestroyDebugUtilsMessengerEXT(instance_unwrapped, messenger_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(VulkanCaptureManager::Get(), instance, messenger, pAllocator);

    DestroyWrappedHandle<DebugUtilsMessengerEXTWrapper>(messenger);
}

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(VulkanCaptureManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        encoder->EncodeEnumValue(messageSeverity);
        encoder->EncodeFlagsValue(messageTypes);
        EncodeStructPtr(encoder, pCallbackData);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    GetInstanceTable(instance)->SubmitDebugUtilsMessageEXT(instance_unwrapped, messageSeverity, messageTypes, pCallbackData);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(VulkanCaptureManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);
}

VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                    device,
    const struct AHardwareBuffer*               buffer,
    VkAndroidHardwareBufferPropertiesANDROID*   pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(VulkanCaptureManager::Get(), device, buffer, pProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetAndroidHardwareBufferPropertiesANDROID(device_unwrapped, buffer, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeVoidPtr(buffer);
        EncodeStructPtr(encoder, pProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(VulkanCaptureManager::Get(), result, device, buffer, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID(
    VkDevice                                    device,
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
    struct AHardwareBuffer**                    pBuffer)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pBuffer);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetMemoryAndroidHardwareBufferANDROID(device_unwrapped, pInfo_unwrapped, pBuffer);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVoidPtrPtr(pBuffer, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo, pBuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pSampleLocationsInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pSampleLocationsInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetSampleLocationsEXT(commandBuffer_unwrapped, pSampleLocationsInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pSampleLocationsInfo);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    VkMultisamplePropertiesEXT*                 pMultisampleProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, samples, pMultisampleProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    GetInstanceTable(physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice_unwrapped, samples, pMultisampleProperties);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeEnumValue(samples);
        EncodeStructPtr(encoder, pMultisampleProperties);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, samples, pMultisampleProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT(
    VkDevice                                    device,
    VkImage                                     image,
    VkImageDrmFormatModifierPropertiesEXT*      pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), device, image, pProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    VkResult result = GetDeviceTable(device)->GetImageDrmFormatModifierPropertiesEXT(device_unwrapped, image_unwrapped, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        EncodeStructPtr(encoder, pProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, image, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT(
    VkDevice                                    device,
    const VkValidationCacheCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkValidationCacheEXT*                       pValidationCache)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pValidationCache);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateValidationCacheEXT(device_unwrapped, pCreateInfo, pAllocator, pValidationCache);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, ValidationCacheEXTWrapper>(device, NoParentWrapper::kHandleValue, pValidationCache, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateValidationCacheEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pValidationCache, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, ValidationCacheEXTWrapper, VkValidationCacheCreateInfoEXT>(result, device, pValidationCache, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pValidationCache);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(VulkanCaptureManager::Get(), device, validationCache, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(validationCache);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<ValidationCacheEXTWrapper>(validationCache);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkValidationCacheEXT validationCache_unwrapped = GetWrappedHandle<VkValidationCacheEXT>(validationCache);

    GetDeviceTable(device)->DestroyValidationCacheEXT(device_unwrapped, validationCache_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(VulkanCaptureManager::Get(), device, validationCache, pAllocator);

    DestroyWrappedHandle<ValidationCacheEXTWrapper>(validationCache);
}

VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const VkValidationCacheEXT*                 pSrcCaches)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(VulkanCaptureManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkValidationCacheEXT dstCache_unwrapped = GetWrappedHandle<VkValidationCacheEXT>(dstCache);
    const VkValidationCacheEXT* pSrcCaches_unwrapped = UnwrapHandles<VkValidationCacheEXT>(pSrcCaches, srcCacheCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->MergeValidationCachesEXT(device_unwrapped, dstCache_unwrapped, srcCacheCount, pSrcCaches_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkMergeValidationCachesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleArray(pSrcCaches, srcCacheCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, dstCache, srcCacheCount, pSrcCaches);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(VulkanCaptureManager::Get(), device, validationCache, pDataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkValidationCacheEXT validationCache_unwrapped = GetWrappedHandle<VkValidationCacheEXT>(validationCache);

    VkResult result = GetDeviceTable(device)->GetValidationCacheDataEXT(device_unwrapped, validationCache_unwrapped, pDataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(validationCache);
        encoder->EncodeSizeTPtr(pDataSize, omit_output_data);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, validationCache, pDataSize, pData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, imageView, imageLayout);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(imageView);
        encoder->EncodeEnumValue(imageLayout);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBindShadingRateImageNVHandles, imageView);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImageView imageView_unwrapped = GetWrappedHandle<VkImageView>(imageView);

    GetDeviceTable(commandBuffer)->CmdBindShadingRateImageNV(commandBuffer_unwrapped, imageView_unwrapped, imageLayout);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, imageView, imageLayout);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pShadingRatePalettes, viewportCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewportShadingRatePaletteNV(commandBuffer_unwrapped, firstViewport, viewportCount, pShadingRatePalettes);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV(
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(sampleOrderType);
        encoder->EncodeUInt32Value(customSampleOrderCount);
        EncodeStructArray(encoder, pCustomSampleOrders, customSampleOrderCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCoarseSampleOrderNV(commandBuffer_unwrapped, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureNV(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoNV*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureNV*                  pAccelerationStructure)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pAccelerationStructure);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAccelerationStructureCreateInfoNV* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateAccelerationStructureNV(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pAccelerationStructure);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, AccelerationStructureNVWrapper>(device, NoParentWrapper::kHandleValue, pAccelerationStructure, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pAccelerationStructure, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, AccelerationStructureNVWrapper, VkAccelerationStructureCreateInfoNV>(result, device, pAccelerationStructure, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV(
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(VulkanCaptureManager::Get(), device, accelerationStructure, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(accelerationStructure);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<AccelerationStructureNVWrapper>(accelerationStructure);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkAccelerationStructureNV accelerationStructure_unwrapped = GetWrappedHandle<VkAccelerationStructureNV>(accelerationStructure);

    GetDeviceTable(device)->DestroyAccelerationStructureNV(device_unwrapped, accelerationStructure_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(VulkanCaptureManager::Get(), device, accelerationStructure, pAllocator);

    DestroyWrappedHandle<AccelerationStructureNVWrapper>(accelerationStructure);
}

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV(
    VkDevice                                    device,
    const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo,
    VkMemoryRequirements2KHR*                   pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetAccelerationStructureMemoryRequirementsNV(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL BindAccelerationStructureMemoryNV(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindAccelerationStructureMemoryInfoNV* pBindInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(VulkanCaptureManager::Get(), device, bindInfoCount, pBindInfos);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBindAccelerationStructureMemoryInfoNV* pBindInfos_unwrapped = UnwrapStructArrayHandles(pBindInfos, bindInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BindAccelerationStructureMemoryNV(device_unwrapped, bindInfoCount, pBindInfos_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(VulkanCaptureManager::Get(), result, device, bindInfoCount, pBindInfos);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV);
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
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBuildAccelerationStructureNVHandles, pInfo, instanceData, dst, src, scratch);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkAccelerationStructureInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);
    VkBuffer instanceData_unwrapped = GetWrappedHandle<VkBuffer>(instanceData);
    VkAccelerationStructureNV dst_unwrapped = GetWrappedHandle<VkAccelerationStructureNV>(dst);
    VkAccelerationStructureNV src_unwrapped = GetWrappedHandle<VkAccelerationStructureNV>(src);
    VkBuffer scratch_unwrapped = GetWrappedHandle<VkBuffer>(scratch);

    GetDeviceTable(commandBuffer)->CmdBuildAccelerationStructureNV(commandBuffer_unwrapped, pInfo_unwrapped, instanceData_unwrapped, instanceOffset, update, dst_unwrapped, src_unwrapped, scratch_unwrapped, scratchOffset);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, dst, src, mode);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(dst);
        encoder->EncodeHandleValue(src);
        encoder->EncodeEnumValue(mode);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyAccelerationStructureNVHandles, dst, src);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkAccelerationStructureNV dst_unwrapped = GetWrappedHandle<VkAccelerationStructureNV>(dst);
    VkAccelerationStructureNV src_unwrapped = GetWrappedHandle<VkAccelerationStructureNV>(src);

    GetDeviceTable(commandBuffer)->CmdCopyAccelerationStructureNV(commandBuffer_unwrapped, dst_unwrapped, src_unwrapped, mode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, dst, src, mode);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdTraceRaysNV);
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
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdTraceRaysNVHandles, raygenShaderBindingTableBuffer, missShaderBindingTableBuffer, hitShaderBindingTableBuffer, callableShaderBindingTableBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer raygenShaderBindingTableBuffer_unwrapped = GetWrappedHandle<VkBuffer>(raygenShaderBindingTableBuffer);
    VkBuffer missShaderBindingTableBuffer_unwrapped = GetWrappedHandle<VkBuffer>(missShaderBindingTableBuffer);
    VkBuffer hitShaderBindingTableBuffer_unwrapped = GetWrappedHandle<VkBuffer>(hitShaderBindingTableBuffer);
    VkBuffer callableShaderBindingTableBuffer_unwrapped = GetWrappedHandle<VkBuffer>(callableShaderBindingTableBuffer);

    GetDeviceTable(commandBuffer)->CmdTraceRaysNV(commandBuffer_unwrapped, raygenShaderBindingTableBuffer_unwrapped, raygenShaderBindingOffset, missShaderBindingTableBuffer_unwrapped, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer_unwrapped, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer_unwrapped, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesNV(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkRayTracingPipelineCreateInfoNV*     pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(VulkanCaptureManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipelineCache pipelineCache_unwrapped = GetWrappedHandle<VkPipelineCache>(pipelineCache);
    const VkRayTracingPipelineCreateInfoNV* pCreateInfos_unwrapped = UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateRayTracingPipelinesNV(device_unwrapped, pipelineCache_unwrapped, createInfoCount, pCreateInfos_unwrapped, pAllocator, pPipelines);

    if (result >= 0)
    {
        CreateWrappedHandles<DeviceWrapper, PipelineCacheWrapper, PipelineWrapper>(device, pipelineCache, pPipelines, createInfoCount, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleArray(pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndGroupCreateApiCallCapture<VkDevice, VkPipelineCache, PipelineWrapper, VkRayTracingPipelineCreateInfoNV>(result, device, pipelineCache, createInfoCount, pPipelines, pCreateInfos);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(VulkanCaptureManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(VulkanCaptureManager::Get(), device, pipeline, firstGroup, groupCount, dataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkResult result = GetDeviceTable(device)->GetRayTracingShaderGroupHandlesKHR(device_unwrapped, pipeline_unwrapped, firstGroup, groupCount, dataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(firstGroup);
        encoder->EncodeUInt32Value(groupCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(VulkanCaptureManager::Get(), device, pipeline, firstGroup, groupCount, dataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkResult result = GetDeviceTable(device)->GetRayTracingShaderGroupHandlesNV(device_unwrapped, pipeline_unwrapped, firstGroup, groupCount, dataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(firstGroup);
        encoder->EncodeUInt32Value(groupCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(VulkanCaptureManager::Get(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetAccelerationStructureHandleNV(
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    size_t                                      dataSize,
    void*                                       pData)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(VulkanCaptureManager::Get(), device, accelerationStructure, dataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkAccelerationStructureNV accelerationStructure_unwrapped = GetWrappedHandle<VkAccelerationStructureNV>(accelerationStructure);

    VkResult result = GetDeviceTable(device)->GetAccelerationStructureHandleNV(device_unwrapped, accelerationStructure_unwrapped, dataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(accelerationStructure);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(VulkanCaptureManager::Get(), result, device, accelerationStructure, dataSize, pData);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(accelerationStructureCount);
        encoder->EncodeHandleArray(pAccelerationStructures, accelerationStructureCount);
        encoder->EncodeEnumValue(queryType);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWriteAccelerationStructuresPropertiesNVHandles, accelerationStructureCount, pAccelerationStructures, queryPool);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkAccelerationStructureNV* pAccelerationStructures_unwrapped = UnwrapHandles<VkAccelerationStructureNV>(pAccelerationStructures, accelerationStructureCount, handle_unwrap_memory);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(commandBuffer_unwrapped, accelerationStructureCount, pAccelerationStructures_unwrapped, queryType, queryPool_unwrapped, firstQuery);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

VKAPI_ATTR VkResult VKAPI_CALL CompileDeferredNV(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    shader)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(VulkanCaptureManager::Get(), device, pipeline, shader);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkResult result = GetDeviceTable(device)->CompileDeferredNV(device_unwrapped, pipeline_unwrapped, shader);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkCompileDeferredNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(shader);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(VulkanCaptureManager::Get(), result, device, pipeline, shader);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    const void*                                 pHostPointer,
    VkMemoryHostPointerPropertiesEXT*           pMemoryHostPointerProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), device, handleType, pHostPointer, pMemoryHostPointerProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetMemoryHostPointerPropertiesEXT(device_unwrapped, handleType, pHostPointer, pMemoryHostPointerProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(pHostPointer);
        EncodeStructPtr(encoder, pMemoryHostPointerProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, handleType, pHostPointer, pMemoryHostPointerProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeUInt32Value(marker);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWriteBufferMarkerAMDHandles, dstBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer dstBuffer_unwrapped = GetWrappedHandle<VkBuffer>(dstBuffer);

    GetDeviceTable(commandBuffer)->CmdWriteBufferMarkerAMD(commandBuffer_unwrapped, pipelineStage, dstBuffer_unwrapped, dstOffset, marker);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pTimeDomainCount,
    VkTimeDomainEXT*                            pTimeDomains)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pTimeDomainCount, pTimeDomains);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice_unwrapped, pTimeDomainCount, pTimeDomains);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pTimeDomainCount, omit_output_data);
        encoder->EncodeEnumArray(pTimeDomains, (pTimeDomainCount != nullptr) ? (*pTimeDomainCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pTimeDomainCount, pTimeDomains);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsEXT(
    VkDevice                                    device,
    uint32_t                                    timestampCount,
    const VkCalibratedTimestampInfoEXT*         pTimestampInfos,
    uint64_t*                                   pTimestamps,
    uint64_t*                                   pMaxDeviation)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(VulkanCaptureManager::Get(), device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetCalibratedTimestampsEXT(device_unwrapped, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(timestampCount);
        EncodeStructArray(encoder, pTimestampInfos, timestampCount);
        encoder->EncodeUInt64Array(pTimestamps, timestampCount, omit_output_data);
        encoder->EncodeUInt64Ptr(pMaxDeviation, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, taskCount, firstTask);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(taskCount);
        encoder->EncodeUInt32Value(firstTask);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawMeshTasksNV(commandBuffer_unwrapped, taskCount, firstTask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, taskCount, firstTask);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawMeshTasksIndirectNVHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdDrawMeshTasksIndirectNV(commandBuffer_unwrapped, buffer_unwrapped, offset, drawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawMeshTasksIndirectCountNVHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawMeshTasksIndirectCountNV(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstExclusiveScissor);
        encoder->EncodeUInt32Value(exclusiveScissorCount);
        EncodeStructArray(encoder, pExclusiveScissors, exclusiveScissorCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetExclusiveScissorNV(commandBuffer_unwrapped, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV(
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCheckpointMarker);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetCheckpointNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVoidPtr(pCheckpointMarker);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCheckpointNV(commandBuffer_unwrapped, pCheckpointMarker);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pCheckpointMarker);
}

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV(
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointDataNV*                         pCheckpointData)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(VulkanCaptureManager::Get(), queue, pCheckpointDataCount, pCheckpointData);

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);

    GetDeviceTable(queue)->GetQueueCheckpointDataNV(queue_unwrapped, pCheckpointDataCount, pCheckpointData);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeUInt32Ptr(pCheckpointDataCount);
        EncodeStructArray(encoder, pCheckpointData, (pCheckpointDataCount != nullptr) ? (*pCheckpointDataCount) : 0);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(VulkanCaptureManager::Get(), queue, pCheckpointDataCount, pCheckpointData);
}

VKAPI_ATTR VkResult VKAPI_CALL InitializePerformanceApiINTEL(
    VkDevice                                    device,
    const VkInitializePerformanceApiInfoINTEL*  pInitializeInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(VulkanCaptureManager::Get(), device, pInitializeInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->InitializePerformanceApiINTEL(device_unwrapped, pInitializeInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInitializeInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL>::Dispatch(VulkanCaptureManager::Get(), result, device, pInitializeInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UninitializePerformanceApiINTEL(
    VkDevice                                    device)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(VulkanCaptureManager::Get(), device);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->UninitializePerformanceApiINTEL(device_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL>::Dispatch(VulkanCaptureManager::Get(), device);
}

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pMarkerInfo);

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    VkResult result = GetDeviceTable(commandBuffer)->CmdSetPerformanceMarkerINTEL(commandBuffer_unwrapped, pMarkerInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL>::Dispatch(VulkanCaptureManager::Get(), result, commandBuffer, pMarkerInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceStreamMarkerINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pMarkerInfo);

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    VkResult result = GetDeviceTable(commandBuffer)->CmdSetPerformanceStreamMarkerINTEL(commandBuffer_unwrapped, pMarkerInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL>::Dispatch(VulkanCaptureManager::Get(), result, commandBuffer, pMarkerInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CmdSetPerformanceOverrideINTEL(
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pOverrideInfo);

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    VkResult result = GetDeviceTable(commandBuffer)->CmdSetPerformanceOverrideINTEL(commandBuffer_unwrapped, pOverrideInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pOverrideInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL>::Dispatch(VulkanCaptureManager::Get(), result, commandBuffer, pOverrideInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquirePerformanceConfigurationINTEL(
    VkDevice                                    device,
    const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
    VkPerformanceConfigurationINTEL*            pConfiguration)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(VulkanCaptureManager::Get(), device, pAcquireInfo, pConfiguration);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->AcquirePerformanceConfigurationINTEL(device_unwrapped, pAcquireInfo, pConfiguration);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PerformanceConfigurationINTELWrapper>(device, NoParentWrapper::kHandleValue, pConfiguration, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pAcquireInfo);
        encoder->EncodeHandlePtr(pConfiguration, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, PerformanceConfigurationINTELWrapper, void>(result, device, pConfiguration, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL>::Dispatch(VulkanCaptureManager::Get(), result, device, pAcquireInfo, pConfiguration);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ReleasePerformanceConfigurationINTEL(
    VkDevice                                    device,
    VkPerformanceConfigurationINTEL             configuration)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(VulkanCaptureManager::Get(), device, configuration);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPerformanceConfigurationINTEL configuration_unwrapped = GetWrappedHandle<VkPerformanceConfigurationINTEL>(configuration);

    VkResult result = GetDeviceTable(device)->ReleasePerformanceConfigurationINTEL(device_unwrapped, configuration_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(configuration);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<PerformanceConfigurationINTELWrapper>(configuration);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL>::Dispatch(VulkanCaptureManager::Get(), result, device, configuration);

    DestroyWrappedHandle<PerformanceConfigurationINTELWrapper>(configuration);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSetPerformanceConfigurationINTEL(
    VkQueue                                     queue,
    VkPerformanceConfigurationINTEL             configuration)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(VulkanCaptureManager::Get(), queue, configuration);

    VkQueue queue_unwrapped = GetWrappedHandle<VkQueue>(queue);
    VkPerformanceConfigurationINTEL configuration_unwrapped = GetWrappedHandle<VkPerformanceConfigurationINTEL>(configuration);

    VkResult result = GetDeviceTable(queue)->QueueSetPerformanceConfigurationINTEL(queue_unwrapped, configuration_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(queue);
        encoder->EncodeHandleValue(configuration);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL>::Dispatch(VulkanCaptureManager::Get(), result, queue, configuration);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPerformanceParameterINTEL(
    VkDevice                                    device,
    VkPerformanceParameterTypeINTEL             parameter,
    VkPerformanceValueINTEL*                    pValue)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(VulkanCaptureManager::Get(), device, parameter, pValue);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetPerformanceParameterINTEL(device_unwrapped, parameter, pValue);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(parameter);
        EncodeStructPtr(encoder, pValue, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL>::Dispatch(VulkanCaptureManager::Get(), result, device, parameter, pValue);

    return result;
}

VKAPI_ATTR void VKAPI_CALL SetLocalDimmingAMD(
    VkDevice                                    device,
    VkSwapchainKHR                              swapChain,
    VkBool32                                    localDimmingEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(VulkanCaptureManager::Get(), device, swapChain, localDimmingEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSetLocalDimmingAMD);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapChain);
        encoder->EncodeVkBool32Value(localDimmingEnable);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapChain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapChain);

    GetDeviceTable(device)->SetLocalDimmingAMD(device_unwrapped, swapChain_unwrapped, localDimmingEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetLocalDimmingAMD>::Dispatch(VulkanCaptureManager::Get(), device, swapChain, localDimmingEnable);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImagePipeSurfaceFUCHSIA(
    VkInstance                                  instance,
    const VkImagePipeSurfaceCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateImagePipeSurfaceFUCHSIA(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkImagePipeSurfaceCreateInfoFUCHSIA>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateMetalSurfaceEXT(
    VkInstance                                  instance,
    const VkMetalSurfaceCreateInfoEXT*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateMetalSurfaceEXT(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkMetalSurfaceCreateInfoEXT>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressEXT(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfo*            pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(VulkanCaptureManager::Get(), device, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkBufferDeviceAddressInfo* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkDeviceAddress result = GetDeviceTable(device)->GetBufferDeviceAddressEXT(device_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVkDeviceAddressValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceToolPropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pToolCount,
    VkPhysicalDeviceToolProperties*             pToolProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pToolCount, pToolProperties);

    VkResult result = VulkanCaptureManager::Get()->OverrideGetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pToolCount, omit_output_data);
        EncodeStructArray(encoder, pToolProperties, (pToolCount != nullptr) ? (*pToolCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pToolCount, pToolProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCooperativeMatrixPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkCooperativeMatrixPropertiesNV*            pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice_unwrapped, pPropertyCount, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pCombinationCount,
    VkFramebufferMixedSamplesCombinationNV*     pCombinations)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pCombinationCount, pCombinations);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice_unwrapped, pCombinationCount, pCombinations);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pCombinationCount, omit_output_data);
        EncodeStructArray(encoder, pCombinations, (pCombinationCount != nullptr) ? (*pCombinationCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pCombinationCount, pCombinations);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModes2EXT(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice_unwrapped, pSurfaceInfo_unwrapped, pPresentModeCount, pPresentModes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        encoder->EncodeUInt32Ptr(pPresentModeCount, omit_output_data);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireFullScreenExclusiveModeEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(VulkanCaptureManager::Get(), device, swapchain);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->AcquireFullScreenExclusiveModeEXT(device_unwrapped, swapchain_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, swapchain);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseFullScreenExclusiveModeEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(VulkanCaptureManager::Get(), device, swapchain);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkSwapchainKHR swapchain_unwrapped = GetWrappedHandle<VkSwapchainKHR>(swapchain);

    VkResult result = GetDeviceTable(device)->ReleaseFullScreenExclusiveModeEXT(device_unwrapped, swapchain_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(swapchain);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, swapchain);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModes2EXT(
    VkDevice                                    device,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkDeviceGroupPresentModeFlagsKHR*           pModes)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(VulkanCaptureManager::Get(), device, pSurfaceInfo, pModes);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo_unwrapped = UnwrapStructPtrHandles(pSurfaceInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetDeviceGroupSurfacePresentModes2EXT(device_unwrapped, pSurfaceInfo_unwrapped, pModes);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pSurfaceInfo);
        encoder->EncodeFlagsPtr(pModes, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pSurfaceInfo, pModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateHeadlessSurfaceEXT(
    VkInstance                                  instance,
    const VkHeadlessSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateHeadlessSurfaceEXT(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkHeadlessSurfaceCreateInfoEXT>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, lineStippleFactor, lineStipplePattern);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(lineStippleFactor);
        encoder->EncodeUInt16Value(lineStipplePattern);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetLineStippleEXT(commandBuffer_unwrapped, lineStippleFactor, lineStipplePattern);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, lineStippleFactor, lineStipplePattern);
}

VKAPI_ATTR void VKAPI_CALL ResetQueryPoolEXT(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(VulkanCaptureManager::Get(), device, queryPool, firstQuery, queryCount);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkResetQueryPoolEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(device)->ResetQueryPoolEXT(device_unwrapped, queryPool_unwrapped, firstQuery, queryCount);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetQueryPoolEXT>::Dispatch(VulkanCaptureManager::Get(), device, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCullModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, cullMode);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetCullModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(cullMode);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCullModeEXT(commandBuffer_unwrapped, cullMode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCullModeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, cullMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetFrontFaceEXT(
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, frontFace);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(frontFace);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetFrontFaceEXT(commandBuffer_unwrapped, frontFace);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, frontFace);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveTopologyEXT(
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, primitiveTopology);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(primitiveTopology);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetPrimitiveTopologyEXT(commandBuffer_unwrapped, primitiveTopology);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, primitiveTopology);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, viewportCount, pViewports);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewports, viewportCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewportWithCountEXT(commandBuffer_unwrapped, viewportCount, pViewports);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissorWithCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, scissorCount, pScissors);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(scissorCount);
        EncodeStructArray(encoder, pScissors, scissorCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetScissorWithCountEXT(commandBuffer_unwrapped, scissorCount, pScissors);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, scissorCount, pScissors);
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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pSizes, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pStrides, bindingCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBindVertexBuffers2EXTHandles, bindingCount, pBuffers);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkBuffer* pBuffers_unwrapped = UnwrapHandles<VkBuffer>(pBuffers, bindingCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBindVertexBuffers2EXT(commandBuffer_unwrapped, firstBinding, bindingCount, pBuffers_unwrapped, pOffsets, pSizes, pStrides);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthTestEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthTestEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthTestEnableEXT(commandBuffer_unwrapped, depthTestEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthWriteEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthWriteEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthWriteEnableEXT(commandBuffer_unwrapped, depthWriteEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthWriteEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthCompareOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthCompareOp);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(depthCompareOp);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthCompareOpEXT(commandBuffer_unwrapped, depthCompareOp);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthCompareOp);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBoundsTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthBoundsTestEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthBoundsTestEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthBoundsTestEnableEXT(commandBuffer_unwrapped, depthBoundsTestEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthBoundsTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilTestEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stencilTestEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(stencilTestEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilTestEnableEXT(commandBuffer_unwrapped, stencilTestEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stencilTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeEnumValue(failOp);
        encoder->EncodeEnumValue(passOp);
        encoder->EncodeEnumValue(depthFailOp);
        encoder->EncodeEnumValue(compareOp);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetStencilOpEXT(commandBuffer_unwrapped, faceMask, failOp, passOp, depthFailOp, compareOp);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseSwapchainImagesEXT(
    VkDevice                                    device,
    const VkReleaseSwapchainImagesInfoEXT*      pReleaseInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(VulkanCaptureManager::Get(), device, pReleaseInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkReleaseSwapchainImagesInfoEXT* pReleaseInfo_unwrapped = UnwrapStructPtrHandles(pReleaseInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ReleaseSwapchainImagesEXT(device_unwrapped, pReleaseInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pReleaseInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pReleaseInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetGeneratedCommandsMemoryRequirementsNV(
    VkDevice                                    device,
    const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetGeneratedCommandsMemoryRequirementsNV(device_unwrapped, pInfo_unwrapped, pMemoryRequirements);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV>::Dispatch(VulkanCaptureManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL CmdPreprocessGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pGeneratedCommandsInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pGeneratedCommandsInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdPreprocessGeneratedCommandsNVHandles, pGeneratedCommandsInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo_unwrapped = UnwrapStructPtrHandles(pGeneratedCommandsInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdPreprocessGeneratedCommandsNV(commandBuffer_unwrapped, pGeneratedCommandsInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pGeneratedCommandsInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteGeneratedCommandsNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, isPreprocessed, pGeneratedCommandsInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(isPreprocessed);
        EncodeStructPtr(encoder, pGeneratedCommandsInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdExecuteGeneratedCommandsNVHandles, pGeneratedCommandsInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo_unwrapped = UnwrapStructPtrHandles(pGeneratedCommandsInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdExecuteGeneratedCommandsNV(commandBuffer_unwrapped, isPreprocessed, pGeneratedCommandsInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipelineShaderGroupNV(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineBindPoint, pipeline, groupIndex);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(groupIndex);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBindPipelineShaderGroupNVHandles, pipeline);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    GetDeviceTable(commandBuffer)->CmdBindPipelineShaderGroupNV(commandBuffer_unwrapped, pipelineBindPoint, pipeline_unwrapped, groupIndex);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNV(
    VkDevice                                    device,
    const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkIndirectCommandsLayoutNV*                 pIndirectCommandsLayout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateIndirectCommandsLayoutNV(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pIndirectCommandsLayout);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, IndirectCommandsLayoutNVWrapper>(device, NoParentWrapper::kHandleValue, pIndirectCommandsLayout, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pIndirectCommandsLayout, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, IndirectCommandsLayoutNVWrapper, VkIndirectCommandsLayoutCreateInfoNV>(result, device, pIndirectCommandsLayout, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNV(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNV                  indirectCommandsLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(VulkanCaptureManager::Get(), device, indirectCommandsLayout, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(indirectCommandsLayout);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<IndirectCommandsLayoutNVWrapper>(indirectCommandsLayout);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkIndirectCommandsLayoutNV indirectCommandsLayout_unwrapped = GetWrappedHandle<VkIndirectCommandsLayoutNV>(indirectCommandsLayout);

    GetDeviceTable(device)->DestroyIndirectCommandsLayoutNV(device_unwrapped, indirectCommandsLayout_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV>::Dispatch(VulkanCaptureManager::Get(), device, indirectCommandsLayout, pAllocator);

    DestroyWrappedHandle<IndirectCommandsLayoutNVWrapper>(indirectCommandsLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireDrmDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    int32_t                                     drmFd,
    VkDisplayKHR                                display)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, drmFd, display);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->AcquireDrmDisplayEXT(physicalDevice_unwrapped, drmFd, display_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeInt32Value(drmFd);
        encoder->EncodeHandleValue(display);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, drmFd, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDrmDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    VkDisplayKHR*                               display)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, drmFd, connectorId, display);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetDrmDisplayEXT(physicalDevice_unwrapped, drmFd, connectorId, display);

    if (result >= 0)
    {
        CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DisplayKHRWrapper>(physicalDevice, NoParentWrapper::kHandleValue, display, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetDrmDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeInt32Value(drmFd);
        encoder->EncodeUInt32Value(connectorId);
        encoder->EncodeHandlePtr(display, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkPhysicalDevice, DisplayKHRWrapper, void>(result, physicalDevice, display, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDrmDisplayEXT>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, drmFd, connectorId, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePrivateDataSlotEXT(
    VkDevice                                    device,
    const VkPrivateDataSlotCreateInfo*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPrivateDataSlot*                          pPrivateDataSlot)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pPrivateDataSlot);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreatePrivateDataSlotEXT(device_unwrapped, pCreateInfo, pAllocator, pPrivateDataSlot);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, PrivateDataSlotWrapper>(device, NoParentWrapper::kHandleValue, pPrivateDataSlot, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pPrivateDataSlot, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, PrivateDataSlotWrapper, VkPrivateDataSlotCreateInfo>(result, device, pPrivateDataSlot, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pPrivateDataSlot);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPrivateDataSlotEXT(
    VkDevice                                    device,
    VkPrivateDataSlot                           privateDataSlot,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(VulkanCaptureManager::Get(), device, privateDataSlot, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(privateDataSlot);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<PrivateDataSlotWrapper>(privateDataSlot);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPrivateDataSlot privateDataSlot_unwrapped = GetWrappedHandle<VkPrivateDataSlot>(privateDataSlot);

    GetDeviceTable(device)->DestroyPrivateDataSlotEXT(device_unwrapped, privateDataSlot_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT>::Dispatch(VulkanCaptureManager::Get(), device, privateDataSlot, pAllocator);

    DestroyWrappedHandle<PrivateDataSlotWrapper>(privateDataSlot);
}

VKAPI_ATTR VkResult VKAPI_CALL SetPrivateDataEXT(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t                                    data)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(VulkanCaptureManager::Get(), device, objectType, objectHandle, privateDataSlot, data);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    uint64_t objectHandle_unwrapped = GetWrappedHandle(objectHandle, objectType);
    VkPrivateDataSlot privateDataSlot_unwrapped = GetWrappedHandle<VkPrivateDataSlot>(privateDataSlot);

    VkResult result = GetDeviceTable(device)->SetPrivateDataEXT(device_unwrapped, objectType, objectHandle_unwrapped, privateDataSlot_unwrapped, data);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSetPrivateDataEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(GetWrappedId(objectHandle, objectType));
        encoder->EncodeHandleValue(privateDataSlot);
        encoder->EncodeUInt64Value(data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetPrivateDataEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, objectType, objectHandle, privateDataSlot, data);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPrivateDataEXT(
    VkDevice                                    device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    VkPrivateDataSlot                           privateDataSlot,
    uint64_t*                                   pData)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(VulkanCaptureManager::Get(), device, objectType, objectHandle, privateDataSlot, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    uint64_t objectHandle_unwrapped = GetWrappedHandle(objectHandle, objectType);
    VkPrivateDataSlot privateDataSlot_unwrapped = GetWrappedHandle<VkPrivateDataSlot>(privateDataSlot);

    GetDeviceTable(device)->GetPrivateDataEXT(device_unwrapped, objectType, objectHandle_unwrapped, privateDataSlot_unwrapped, pData);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPrivateDataEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(GetWrappedId(objectHandle, objectType));
        encoder->EncodeHandleValue(privateDataSlot);
        encoder->EncodeUInt64Ptr(pData);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPrivateDataEXT>::Dispatch(VulkanCaptureManager::Get(), device, objectType, objectHandle, privateDataSlot, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdSetFragmentShadingRateEnumNV(
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR    combinerOps[2])
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, shadingRate, combinerOps);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(shadingRate);
        encoder->EncodeEnumArray(combinerOps, 2);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetFragmentShadingRateEnumNV(commandBuffer_unwrapped, shadingRate, combinerOps);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, shadingRate, combinerOps);
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout2EXT(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource2EXT*               pSubresource,
    VkSubresourceLayout2EXT*                    pLayout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(VulkanCaptureManager::Get(), device, image, pSubresource, pLayout);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkImage image_unwrapped = GetWrappedHandle<VkImage>(image);

    GetDeviceTable(device)->GetImageSubresourceLayout2EXT(device_unwrapped, image_unwrapped, pSubresource, pLayout);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(image);
        EncodeStructPtr(encoder, pSubresource);
        EncodeStructPtr(encoder, pLayout);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT>::Dispatch(VulkanCaptureManager::Get(), device, image, pSubresource, pLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceFaultInfoEXT(
    VkDevice                                    device,
    VkDeviceFaultCountsEXT*                     pFaultCounts,
    VkDeviceFaultInfoEXT*                       pFaultInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(VulkanCaptureManager::Get(), device, pFaultCounts, pFaultInfo);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetDeviceFaultInfoEXT(device_unwrapped, pFaultCounts, pFaultInfo);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pFaultCounts, omit_output_data);
        EncodeStructPtr(encoder, pFaultInfo, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pFaultCounts, pFaultInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireWinrtDisplayNV(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, display);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDisplayKHR display_unwrapped = GetWrappedHandle<VkDisplayKHR>(display);

    VkResult result = GetInstanceTable(physicalDevice)->AcquireWinrtDisplayNV(physicalDevice_unwrapped, display_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeHandleValue(display);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetWinrtDisplayNV(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    VkDisplayKHR*                               pDisplay)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, deviceRelativeId, pDisplay);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetWinrtDisplayNV(physicalDevice_unwrapped, deviceRelativeId, pDisplay);

    if (result >= 0)
    {
        CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DisplayKHRWrapper>(physicalDevice, NoParentWrapper::kHandleValue, pDisplay, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkGetWinrtDisplayNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(deviceRelativeId);
        encoder->EncodeHandlePtr(pDisplay, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkPhysicalDevice, DisplayKHRWrapper, void>(result, physicalDevice, pDisplay, nullptr);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetWinrtDisplayNV>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, deviceRelativeId, pDisplay);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDirectFBSurfaceEXT(
    VkInstance                                  instance,
    const VkDirectFBSurfaceCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateDirectFBSurfaceEXT(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkDirectFBSurfaceCreateInfoEXT>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceDirectFBPresentationSupportEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    IDirectFB*                                  dfb)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, queueFamilyIndex, dfb);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice_unwrapped, queueFamilyIndex, dfb);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(dfb);
        encoder->EncodeVkBool32Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, queueFamilyIndex, dfb);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetVertexInputEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(vertexBindingDescriptionCount);
        EncodeStructArray(encoder, pVertexBindingDescriptions, vertexBindingDescriptionCount);
        encoder->EncodeUInt32Value(vertexAttributeDescriptionCount);
        EncodeStructArray(encoder, pVertexAttributeDescriptions, vertexAttributeDescriptionCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetVertexInputEXT(commandBuffer_unwrapped, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryZirconHandleFUCHSIA(
    VkDevice                                    device,
    const VkMemoryGetZirconHandleInfoFUCHSIA*   pGetZirconHandleInfo,
    zx_handle_t*                                pZirconHandle)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(VulkanCaptureManager::Get(), device, pGetZirconHandleInfo, pZirconHandle);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo_unwrapped = UnwrapStructPtrHandles(pGetZirconHandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetMemoryZirconHandleFUCHSIA(device_unwrapped, pGetZirconHandleInfo_unwrapped, pZirconHandle);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetZirconHandleInfo);
        encoder->EncodeUInt32Ptr(pZirconHandle, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA>::Dispatch(VulkanCaptureManager::Get(), result, device, pGetZirconHandleInfo, pZirconHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryZirconHandlePropertiesFUCHSIA(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    zx_handle_t                                 zirconHandle,
    VkMemoryZirconHandlePropertiesFUCHSIA*      pMemoryZirconHandleProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(VulkanCaptureManager::Get(), device, handleType, zirconHandle, pMemoryZirconHandleProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->GetMemoryZirconHandlePropertiesFUCHSIA(device_unwrapped, handleType, zirconHandle, pMemoryZirconHandleProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeUInt32Value(zirconHandle);
        EncodeStructPtr(encoder, pMemoryZirconHandleProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA>::Dispatch(VulkanCaptureManager::Get(), result, device, handleType, zirconHandle, pMemoryZirconHandleProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreZirconHandleFUCHSIA(
    VkDevice                                    device,
    const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(VulkanCaptureManager::Get(), device, pImportSemaphoreZirconHandleInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo_unwrapped = UnwrapStructPtrHandles(pImportSemaphoreZirconHandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->ImportSemaphoreZirconHandleFUCHSIA(device_unwrapped, pImportSemaphoreZirconHandleInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pImportSemaphoreZirconHandleInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA>::Dispatch(VulkanCaptureManager::Get(), result, device, pImportSemaphoreZirconHandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreZirconHandleFUCHSIA(
    VkDevice                                    device,
    const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo,
    zx_handle_t*                                pZirconHandle)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(VulkanCaptureManager::Get(), device, pGetZirconHandleInfo, pZirconHandle);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo_unwrapped = UnwrapStructPtrHandles(pGetZirconHandleInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetSemaphoreZirconHandleFUCHSIA(device_unwrapped, pGetZirconHandleInfo_unwrapped, pZirconHandle);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pGetZirconHandleInfo);
        encoder->EncodeUInt32Ptr(pZirconHandle, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA>::Dispatch(VulkanCaptureManager::Get(), result, device, pGetZirconHandleInfo, pZirconHandle);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindInvocationMaskHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, imageView, imageLayout);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(imageView);
        encoder->EncodeEnumValue(imageLayout);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBindInvocationMaskHUAWEIHandles, imageView);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkImageView imageView_unwrapped = GetWrappedHandle<VkImageView>(imageView);

    GetDeviceTable(commandBuffer)->CmdBindInvocationMaskHUAWEI(commandBuffer_unwrapped, imageView_unwrapped, imageLayout);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, imageView, imageLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryRemoteAddressNV(
    VkDevice                                    device,
    const VkMemoryGetRemoteAddressInfoNV*       pMemoryGetRemoteAddressInfo,
    VkRemoteAddressNV*                          pAddress)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(VulkanCaptureManager::Get(), device, pMemoryGetRemoteAddressInfo, pAddress);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo_unwrapped = UnwrapStructPtrHandles(pMemoryGetRemoteAddressInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetMemoryRemoteAddressNV(device_unwrapped, pMemoryGetRemoteAddressInfo_unwrapped, pAddress);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pMemoryGetRemoteAddressInfo);
        encoder->EncodeVoidPtrPtr(pAddress, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV>::Dispatch(VulkanCaptureManager::Get(), result, device, pMemoryGetRemoteAddressInfo, pAddress);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetPatchControlPointsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, patchControlPoints);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(patchControlPoints);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetPatchControlPointsEXT(commandBuffer_unwrapped, patchControlPoints);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, patchControlPoints);
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizerDiscardEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, rasterizerDiscardEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(rasterizerDiscardEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetRasterizerDiscardEnableEXT(commandBuffer_unwrapped, rasterizerDiscardEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, rasterizerDiscardEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBiasEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthBiasEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthBiasEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthBiasEnableEXT(commandBuffer_unwrapped, depthBiasEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthBiasEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEXT(
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, logicOp);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(logicOp);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetLogicOpEXT(commandBuffer_unwrapped, logicOp);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, logicOp);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPrimitiveRestartEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, primitiveRestartEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(primitiveRestartEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetPrimitiveRestartEnableEXT(commandBuffer_unwrapped, primitiveRestartEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, primitiveRestartEnable);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateScreenSurfaceQNX(
    VkInstance                                  instance,
    const VkScreenSurfaceCreateInfoQNX*         pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(VulkanCaptureManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkInstance instance_unwrapped = GetWrappedHandle<VkInstance>(instance);

    VkResult result = GetInstanceTable(instance)->CreateScreenSurfaceQNX(instance_unwrapped, pCreateInfo, pAllocator, pSurface);

    if (result >= 0)
    {
        CreateWrappedHandle<InstanceWrapper, NoParentWrapper, SurfaceKHRWrapper>(instance, NoParentWrapper::kHandleValue, pSurface, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX);
    if (encoder)
    {
        encoder->EncodeHandleValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSurface, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkInstance, SurfaceKHRWrapper, VkScreenSurfaceCreateInfoQNX>(result, instance, pSurface, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX>::Dispatch(VulkanCaptureManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceScreenPresentationSupportQNX(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct _screen_window*                      window)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, queueFamilyIndex, window);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkBool32 result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceScreenPresentationSupportQNX(physicalDevice_unwrapped, queueFamilyIndex, window);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(window);
        encoder->EncodeVkBool32Value(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, queueFamilyIndex, window);

    return result;
}

VKAPI_ATTR void                                    VKAPI_CALL CmdSetColorWriteEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, attachmentCount, pColorWriteEnables);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(attachmentCount);
        encoder->EncodeVkBool32Array(pColorWriteEnables, attachmentCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetColorWriteEnableEXT(commandBuffer_unwrapped, attachmentCount, pColorWriteEnables);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, attachmentCount, pColorWriteEnables);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMultiEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawMultiEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(drawCount);
        EncodeStructArray(encoder, pVertexInfo, drawCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstInstance);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawMultiEXT(commandBuffer_unwrapped, drawCount, pVertexInfo, instanceCount, firstInstance, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMultiIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(drawCount);
        EncodeStructArray(encoder, pIndexInfo, drawCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstInstance);
        encoder->EncodeUInt32Value(stride);
        encoder->EncodeInt32Ptr(pVertexOffset);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawMultiIndexedEXT(commandBuffer_unwrapped, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateMicromapEXT(
    VkDevice                                    device,
    const VkMicromapCreateInfoEXT*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkMicromapEXT*                              pMicromap)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pMicromap);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMicromapCreateInfoEXT* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CreateMicromapEXT(device_unwrapped, pCreateInfo_unwrapped, pAllocator, pMicromap);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, MicromapEXTWrapper>(device, NoParentWrapper::kHandleValue, pMicromap, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateMicromapEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pMicromap, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, MicromapEXTWrapper, VkMicromapCreateInfoEXT>(result, device, pMicromap, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pMicromap);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyMicromapEXT(
    VkDevice                                    device,
    VkMicromapEXT                               micromap,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), device, micromap, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyMicromapEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(micromap);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<MicromapEXTWrapper>(micromap);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkMicromapEXT micromap_unwrapped = GetWrappedHandle<VkMicromapEXT>(micromap);

    GetDeviceTable(device)->DestroyMicromapEXT(device_unwrapped, micromap_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), device, micromap, pAllocator);

    DestroyWrappedHandle<MicromapEXTWrapper>(micromap);
}

VKAPI_ATTR void VKAPI_CALL CmdBuildMicromapsEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, infoCount, pInfos);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(infoCount);
        EncodeStructArray(encoder, pInfos, infoCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBuildMicromapsEXTHandles, infoCount, pInfos);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkMicromapBuildInfoEXT* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBuildMicromapsEXT(commandBuffer_unwrapped, infoCount, pInfos_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, infoCount, pInfos);
}

VKAPI_ATTR VkResult VKAPI_CALL BuildMicromapsEXT(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(VulkanCaptureManager::Get(), device, deferredOperation, infoCount, pInfos);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR deferredOperation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(deferredOperation);
    const VkMicromapBuildInfoEXT* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->BuildMicromapsEXT(device_unwrapped, deferredOperation_unwrapped, infoCount, pInfos_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkBuildMicromapsEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(deferredOperation);
        encoder->EncodeUInt32Value(infoCount);
        EncodeStructArray(encoder, pInfos, infoCount);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBuildMicromapsEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, deferredOperation, infoCount, pInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyMicromapEXT(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMicromapInfoEXT*                pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), device, deferredOperation, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR deferredOperation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(deferredOperation);
    const VkCopyMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CopyMicromapEXT(device_unwrapped, deferredOperation_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkCopyMicromapEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(deferredOperation);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, deferredOperation, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyMicromapToMemoryEXT(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(VulkanCaptureManager::Get(), device, deferredOperation, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR deferredOperation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(deferredOperation);
    const VkCopyMicromapToMemoryInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CopyMicromapToMemoryEXT(device_unwrapped, deferredOperation_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(deferredOperation);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, deferredOperation, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToMicromapEXT(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), device, deferredOperation, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR deferredOperation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(deferredOperation);
    const VkCopyMemoryToMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CopyMemoryToMicromapEXT(device_unwrapped, deferredOperation_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(deferredOperation);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, deferredOperation, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WriteMicromapsPropertiesEXT(
    VkDevice                                    device,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    void*                                       pData,
    size_t                                      stride)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMicromapEXT* pMicromaps_unwrapped = UnwrapHandles<VkMicromapEXT>(pMicromaps, micromapCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->WriteMicromapsPropertiesEXT(device_unwrapped, micromapCount, pMicromaps_unwrapped, queryType, dataSize, pData, stride);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeUInt32Value(micromapCount);
        encoder->EncodeHandleArray(pMicromaps, micromapCount);
        encoder->EncodeEnumValue(queryType);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeSizeTValue(stride);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), result, device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyMicromapEXTHandles, pInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyMicromapEXT(commandBuffer_unwrapped, pInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyMicromapToMemoryEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyMicromapToMemoryEXTHandles, pInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyMicromapToMemoryInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyMicromapToMemoryEXT(commandBuffer_unwrapped, pInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToMicromapEXT(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyMemoryToMicromapEXTHandles, pInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyMemoryToMicromapInfoEXT* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyMemoryToMicromapEXT(commandBuffer_unwrapped, pInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteMicromapsPropertiesEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(micromapCount);
        encoder->EncodeHandleArray(pMicromaps, micromapCount);
        encoder->EncodeEnumValue(queryType);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWriteMicromapsPropertiesEXTHandles, micromapCount, pMicromaps, queryPool);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkMicromapEXT* pMicromaps_unwrapped = UnwrapHandles<VkMicromapEXT>(pMicromaps, micromapCount, handle_unwrap_memory);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdWriteMicromapsPropertiesEXT(commandBuffer_unwrapped, micromapCount, pMicromaps_unwrapped, queryType, queryPool_unwrapped, firstQuery);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMicromapCompatibilityEXT(
    VkDevice                                    device,
    const VkMicromapVersionInfoEXT*             pVersionInfo,
    VkAccelerationStructureCompatibilityKHR*    pCompatibility)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(VulkanCaptureManager::Get(), device, pVersionInfo, pCompatibility);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->GetDeviceMicromapCompatibilityEXT(device_unwrapped, pVersionInfo, pCompatibility);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pVersionInfo);
        encoder->EncodeEnumPtr(pCompatibility);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT>::Dispatch(VulkanCaptureManager::Get(), device, pVersionInfo, pCompatibility);
}

VKAPI_ATTR void VKAPI_CALL GetMicromapBuildSizesEXT(
    VkDevice                                    device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    const VkMicromapBuildInfoEXT*               pBuildInfo,
    VkMicromapBuildSizesInfoEXT*                pSizeInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(VulkanCaptureManager::Get(), device, buildType, pBuildInfo, pSizeInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkMicromapBuildInfoEXT* pBuildInfo_unwrapped = UnwrapStructPtrHandles(pBuildInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetMicromapBuildSizesEXT(device_unwrapped, buildType, pBuildInfo_unwrapped, pSizeInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(buildType);
        EncodeStructPtr(encoder, pBuildInfo);
        EncodeStructPtr(encoder, pSizeInfo);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT>::Dispatch(VulkanCaptureManager::Get(), device, buildType, pBuildInfo, pSizeInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawClusterHUAWEI(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawClusterHUAWEI(commandBuffer_unwrapped, groupCountX, groupCountY, groupCountZ);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawClusterIndirectHUAWEI(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawClusterIndirectHUAWEIHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdDrawClusterIndirectHUAWEI(commandBuffer_unwrapped, buffer_unwrapped, offset);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset);
}

VKAPI_ATTR void VKAPI_CALL SetDeviceMemoryPriorityEXT(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    float                                       priority)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(VulkanCaptureManager::Get(), device, memory, priority);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(memory);
        encoder->EncodeFloatValue(priority);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeviceMemory memory_unwrapped = GetWrappedHandle<VkDeviceMemory>(memory);

    GetDeviceTable(device)->SetDeviceMemoryPriorityEXT(device_unwrapped, memory_unwrapped, priority);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT>::Dispatch(VulkanCaptureManager::Get(), device, memory, priority);
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutHostMappingInfoVALVE(
    VkDevice                                    device,
    const VkDescriptorSetBindingReferenceVALVE* pBindingReference,
    VkDescriptorSetLayoutHostMappingInfoVALVE*  pHostMapping)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(VulkanCaptureManager::Get(), device, pBindingReference, pHostMapping);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkDescriptorSetBindingReferenceVALVE* pBindingReference_unwrapped = UnwrapStructPtrHandles(pBindingReference, handle_unwrap_memory);

    GetDeviceTable(device)->GetDescriptorSetLayoutHostMappingInfoVALVE(device_unwrapped, pBindingReference_unwrapped, pHostMapping);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pBindingReference);
        EncodeStructPtr(encoder, pHostMapping);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE>::Dispatch(VulkanCaptureManager::Get(), device, pBindingReference, pHostMapping);
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetHostMappingVALVE(
    VkDevice                                    device,
    VkDescriptorSet                             descriptorSet,
    void**                                      ppData)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(VulkanCaptureManager::Get(), device, descriptorSet, ppData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDescriptorSet descriptorSet_unwrapped = GetWrappedHandle<VkDescriptorSet>(descriptorSet);

    GetDeviceTable(device)->GetDescriptorSetHostMappingVALVE(device_unwrapped, descriptorSet_unwrapped, ppData);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(descriptorSet);
        encoder->EncodeVoidPtrPtr(ppData);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE>::Dispatch(VulkanCaptureManager::Get(), device, descriptorSet, ppData);
}

VKAPI_ATTR void VKAPI_CALL CmdSetTessellationDomainOriginEXT(
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, domainOrigin);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(domainOrigin);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetTessellationDomainOriginEXT(commandBuffer_unwrapped, domainOrigin);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, domainOrigin);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClampEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthClampEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthClampEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthClampEnableEXT(commandBuffer_unwrapped, depthClampEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthClampEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetPolygonModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, polygonMode);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(polygonMode);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetPolygonModeEXT(commandBuffer_unwrapped, polygonMode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, polygonMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationSamplesEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, rasterizationSamples);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(rasterizationSamples);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetRasterizationSamplesEXT(commandBuffer_unwrapped, rasterizationSamples);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, rasterizationSamples);
}

VKAPI_ATTR void VKAPI_CALL CmdSetSampleMaskEXT(
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, samples, pSampleMask);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(samples);
        encoder->EncodeVkSampleMaskArray(pSampleMask, (samples + 31) / 32);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetSampleMaskEXT(commandBuffer_unwrapped, samples, pSampleMask);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, samples, pSampleMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToCoverageEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, alphaToCoverageEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(alphaToCoverageEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetAlphaToCoverageEnableEXT(commandBuffer_unwrapped, alphaToCoverageEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, alphaToCoverageEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetAlphaToOneEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, alphaToOneEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(alphaToOneEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetAlphaToOneEnableEXT(commandBuffer_unwrapped, alphaToOneEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, alphaToOneEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLogicOpEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, logicOpEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(logicOpEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetLogicOpEnableEXT(commandBuffer_unwrapped, logicOpEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, logicOpEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEnableEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstAttachment);
        encoder->EncodeUInt32Value(attachmentCount);
        encoder->EncodeVkBool32Array(pColorBlendEnables, attachmentCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetColorBlendEnableEXT(commandBuffer_unwrapped, firstAttachment, attachmentCount, pColorBlendEnables);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendEquationEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstAttachment);
        encoder->EncodeUInt32Value(attachmentCount);
        EncodeStructArray(encoder, pColorBlendEquations, attachmentCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetColorBlendEquationEXT(commandBuffer_unwrapped, firstAttachment, attachmentCount, pColorBlendEquations);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorWriteMaskEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstAttachment);
        encoder->EncodeUInt32Value(attachmentCount);
        encoder->EncodeFlagsArray(pColorWriteMasks, attachmentCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetColorWriteMaskEXT(commandBuffer_unwrapped, firstAttachment, attachmentCount, pColorWriteMasks);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}

VKAPI_ATTR void VKAPI_CALL CmdSetRasterizationStreamEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, rasterizationStream);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(rasterizationStream);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetRasterizationStreamEXT(commandBuffer_unwrapped, rasterizationStream);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, rasterizationStream);
}

VKAPI_ATTR void VKAPI_CALL CmdSetConservativeRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, conservativeRasterizationMode);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(conservativeRasterizationMode);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetConservativeRasterizationModeEXT(commandBuffer_unwrapped, conservativeRasterizationMode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, conservativeRasterizationMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetExtraPrimitiveOverestimationSizeEXT(
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, extraPrimitiveOverestimationSize);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeFloatValue(extraPrimitiveOverestimationSize);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer_unwrapped, extraPrimitiveOverestimationSize);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, extraPrimitiveOverestimationSize);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthClipEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(depthClipEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthClipEnableEXT(commandBuffer_unwrapped, depthClipEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, depthClipEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, sampleLocationsEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(sampleLocationsEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetSampleLocationsEnableEXT(commandBuffer_unwrapped, sampleLocationsEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, sampleLocationsEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetColorBlendAdvancedEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstAttachment);
        encoder->EncodeUInt32Value(attachmentCount);
        EncodeStructArray(encoder, pColorBlendAdvanced, attachmentCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetColorBlendAdvancedEXT(commandBuffer_unwrapped, firstAttachment, attachmentCount, pColorBlendAdvanced);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}

VKAPI_ATTR void VKAPI_CALL CmdSetProvokingVertexModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, provokingVertexMode);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(provokingVertexMode);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetProvokingVertexModeEXT(commandBuffer_unwrapped, provokingVertexMode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, provokingVertexMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineRasterizationModeEXT(
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, lineRasterizationMode);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(lineRasterizationMode);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetLineRasterizationModeEXT(commandBuffer_unwrapped, lineRasterizationMode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, lineRasterizationMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineStippleEnableEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stippledLineEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(stippledLineEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetLineStippleEnableEXT(commandBuffer_unwrapped, stippledLineEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, stippledLineEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthClipNegativeOneToOneEXT(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, negativeOneToOne);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(negativeOneToOne);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetDepthClipNegativeOneToOneEXT(commandBuffer_unwrapped, negativeOneToOne);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, negativeOneToOne);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, viewportWScalingEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(viewportWScalingEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewportWScalingEnableNV(commandBuffer_unwrapped, viewportWScalingEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, viewportWScalingEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportSwizzleNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportSwizzles);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewportSwizzles, viewportCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetViewportSwizzleNV(commandBuffer_unwrapped, firstViewport, viewportCount, pViewportSwizzles);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageToColorEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(coverageToColorEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCoverageToColorEnableNV(commandBuffer_unwrapped, coverageToColorEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageToColorEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageToColorLocationNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageToColorLocation);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(coverageToColorLocation);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCoverageToColorLocationNV(commandBuffer_unwrapped, coverageToColorLocation);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageToColorLocation);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageModulationMode);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(coverageModulationMode);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCoverageModulationModeNV(commandBuffer_unwrapped, coverageModulationMode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageModulationMode);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageModulationTableEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(coverageModulationTableEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCoverageModulationTableEnableNV(commandBuffer_unwrapped, coverageModulationTableEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageModulationTableEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageModulationTableNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageModulationTableCount, pCoverageModulationTable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(coverageModulationTableCount);
        encoder->EncodeFloatArray(pCoverageModulationTable, coverageModulationTableCount);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCoverageModulationTableNV(commandBuffer_unwrapped, coverageModulationTableCount, pCoverageModulationTable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetShadingRateImageEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, shadingRateImageEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(shadingRateImageEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetShadingRateImageEnableNV(commandBuffer_unwrapped, shadingRateImageEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, shadingRateImageEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetRepresentativeFragmentTestEnableNV(
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, representativeFragmentTestEnable);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeVkBool32Value(representativeFragmentTestEnable);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetRepresentativeFragmentTestEnableNV(commandBuffer_unwrapped, representativeFragmentTestEnable);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, representativeFragmentTestEnable);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoverageReductionModeNV(
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageReductionMode);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeEnumValue(coverageReductionMode);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetCoverageReductionModeNV(commandBuffer_unwrapped, coverageReductionMode);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, coverageReductionMode);
}

VKAPI_ATTR void VKAPI_CALL GetShaderModuleIdentifierEXT(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    VkShaderModuleIdentifierEXT*                pIdentifier)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(VulkanCaptureManager::Get(), device, shaderModule, pIdentifier);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkShaderModule shaderModule_unwrapped = GetWrappedHandle<VkShaderModule>(shaderModule);

    GetDeviceTable(device)->GetShaderModuleIdentifierEXT(device_unwrapped, shaderModule_unwrapped, pIdentifier);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(shaderModule);
        EncodeStructPtr(encoder, pIdentifier);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT>::Dispatch(VulkanCaptureManager::Get(), device, shaderModule, pIdentifier);
}

VKAPI_ATTR void VKAPI_CALL GetShaderModuleCreateInfoIdentifierEXT(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    VkShaderModuleIdentifierEXT*                pIdentifier)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pIdentifier);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkShaderModuleCreateInfo* pCreateInfo_unwrapped = UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetShaderModuleCreateInfoIdentifierEXT(device_unwrapped, pCreateInfo_unwrapped, pIdentifier);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pIdentifier);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pIdentifier);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceOpticalFlowImageFormatsNV(
    VkPhysicalDevice                            physicalDevice,
    const VkOpticalFlowImageFormatInfoNV*       pOpticalFlowImageFormatInfo,
    uint32_t*                                   pFormatCount,
    VkOpticalFlowImageFormatPropertiesNV*       pImageFormatProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(VulkanCaptureManager::Get(), physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);

    VkPhysicalDevice physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);

    VkResult result = GetInstanceTable(physicalDevice)->GetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice_unwrapped, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(physicalDevice);
        EncodeStructPtr(encoder, pOpticalFlowImageFormatInfo);
        encoder->EncodeUInt32Ptr(pFormatCount, omit_output_data);
        EncodeStructArray(encoder, pImageFormatProperties, (pFormatCount != nullptr) ? (*pFormatCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>::Dispatch(VulkanCaptureManager::Get(), result, physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateOpticalFlowSessionNV(
    VkDevice                                    device,
    const VkOpticalFlowSessionCreateInfoNV*     pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkOpticalFlowSessionNV*                     pSession)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pSession);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    VkResult result = GetDeviceTable(device)->CreateOpticalFlowSessionNV(device_unwrapped, pCreateInfo, pAllocator, pSession);

    if (result >= 0)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, OpticalFlowSessionNVWrapper>(device, NoParentWrapper::kHandleValue, pSession, VulkanCaptureManager::GetUniqueId);
    }
    else
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pSession, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, OpticalFlowSessionNVWrapper, VkOpticalFlowSessionCreateInfoNV>(result, device, pSession, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pSession);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyOpticalFlowSessionNV(
    VkDevice                                    device,
    VkOpticalFlowSessionNV                      session,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(VulkanCaptureManager::Get(), device, session, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(session);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<OpticalFlowSessionNVWrapper>(session);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkOpticalFlowSessionNV session_unwrapped = GetWrappedHandle<VkOpticalFlowSessionNV>(session);

    GetDeviceTable(device)->DestroyOpticalFlowSessionNV(device_unwrapped, session_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV>::Dispatch(VulkanCaptureManager::Get(), device, session, pAllocator);

    DestroyWrappedHandle<OpticalFlowSessionNVWrapper>(session);
}

VKAPI_ATTR VkResult VKAPI_CALL BindOpticalFlowSessionImageNV(
    VkDevice                                    device,
    VkOpticalFlowSessionNV                      session,
    VkOpticalFlowSessionBindingPointNV          bindingPoint,
    VkImageView                                 view,
    VkImageLayout                               layout)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(VulkanCaptureManager::Get(), device, session, bindingPoint, view, layout);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkOpticalFlowSessionNV session_unwrapped = GetWrappedHandle<VkOpticalFlowSessionNV>(session);
    VkImageView view_unwrapped = GetWrappedHandle<VkImageView>(view);

    VkResult result = GetDeviceTable(device)->BindOpticalFlowSessionImageNV(device_unwrapped, session_unwrapped, bindingPoint, view_unwrapped, layout);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(session);
        encoder->EncodeEnumValue(bindingPoint);
        encoder->EncodeHandleValue(view);
        encoder->EncodeEnumValue(layout);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV>::Dispatch(VulkanCaptureManager::Get(), result, device, session, bindingPoint, view, layout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdOpticalFlowExecuteNV(
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, session, pExecuteInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(session);
        EncodeStructPtr(encoder, pExecuteInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdOpticalFlowExecuteNVHandles, session);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkOpticalFlowSessionNV session_unwrapped = GetWrappedHandle<VkOpticalFlowSessionNV>(session);

    GetDeviceTable(commandBuffer)->CmdOpticalFlowExecuteNV(commandBuffer_unwrapped, session_unwrapped, pExecuteInfo);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, session, pExecuteInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL GetFramebufferTilePropertiesQCOM(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    uint32_t*                                   pPropertiesCount,
    VkTilePropertiesQCOM*                       pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(VulkanCaptureManager::Get(), device, framebuffer, pPropertiesCount, pProperties);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkFramebuffer framebuffer_unwrapped = GetWrappedHandle<VkFramebuffer>(framebuffer);

    VkResult result = GetDeviceTable(device)->GetFramebufferTilePropertiesQCOM(device_unwrapped, framebuffer_unwrapped, pPropertiesCount, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(framebuffer);
        encoder->EncodeUInt32Ptr(pPropertiesCount, omit_output_data);
        EncodeStructArray(encoder, pProperties, (pPropertiesCount != nullptr) ? (*pPropertiesCount) : 0, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM>::Dispatch(VulkanCaptureManager::Get(), result, device, framebuffer, pPropertiesCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDynamicRenderingTilePropertiesQCOM(
    VkDevice                                    device,
    const VkRenderingInfo*                      pRenderingInfo,
    VkTilePropertiesQCOM*                       pProperties)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(VulkanCaptureManager::Get(), device, pRenderingInfo, pProperties);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkRenderingInfo* pRenderingInfo_unwrapped = UnwrapStructPtrHandles(pRenderingInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->GetDynamicRenderingTilePropertiesQCOM(device_unwrapped, pRenderingInfo_unwrapped, pProperties);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pRenderingInfo);
        EncodeStructPtr(encoder, pProperties, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM>::Dispatch(VulkanCaptureManager::Get(), result, device, pRenderingInfo, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureKHR(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureKHR*                 pAccelerationStructure)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(VulkanCaptureManager::Get(), device, pCreateInfo, pAllocator, pAccelerationStructure);

    VkResult result = VulkanCaptureManager::Get()->OverrideCreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandlePtr(pAccelerationStructure, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndCreateApiCallCapture<VkDevice, AccelerationStructureKHRWrapper, VkAccelerationStructureCreateInfoKHR>(result, device, pAccelerationStructure, pCreateInfo);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureKHR(
    VkDevice                                    device,
    VkAccelerationStructureKHR                  accelerationStructure,
    const VkAllocationCallbacks*                pAllocator)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(VulkanCaptureManager::Get(), device, accelerationStructure, pAllocator);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(accelerationStructure);
        EncodeStructPtr(encoder, pAllocator);
        VulkanCaptureManager::Get()->EndDestroyApiCallCapture<AccelerationStructureKHRWrapper>(accelerationStructure);
    }

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkAccelerationStructureKHR accelerationStructure_unwrapped = GetWrappedHandle<VkAccelerationStructureKHR>(accelerationStructure);

    GetDeviceTable(device)->DestroyAccelerationStructureKHR(device_unwrapped, accelerationStructure_unwrapped, pAllocator);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR>::Dispatch(VulkanCaptureManager::Get(), device, accelerationStructure, pAllocator);

    DestroyWrappedHandle<AccelerationStructureKHRWrapper>(accelerationStructure);
}

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, infoCount, pInfos, ppBuildRangeInfos);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(infoCount);
        EncodeStructArray(encoder, pInfos, infoCount);
        EncodeStructArray2D(encoder, ppBuildRangeInfos, ArraySize2D<VkCommandBuffer, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkAccelerationStructureBuildRangeInfoKHR* const*>(commandBuffer, infoCount, pInfos, ppBuildRangeInfos));
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBuildAccelerationStructuresKHRHandles, infoCount, pInfos);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBuildAccelerationStructuresKHR(commandBuffer_unwrapped, infoCount, pInfos_unwrapped, ppBuildRangeInfos);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructuresIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress*                      pIndirectDeviceAddresses,
    const uint32_t*                             pIndirectStrides,
    const uint32_t* const*                      ppMaxPrimitiveCounts)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(infoCount);
        EncodeStructArray(encoder, pInfos, infoCount);
        encoder->EncodeVkDeviceAddressArray(pIndirectDeviceAddresses, infoCount);
        encoder->EncodeUInt32Array(pIndirectStrides, infoCount);
        encoder->EncodeUInt32Array2D(ppMaxPrimitiveCounts, ArraySize2D<VkCommandBuffer, uint32_t, const VkAccelerationStructureBuildGeometryInfoKHR*, const VkDeviceAddress*, const uint32_t*, const uint32_t* const*>(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts));
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdBuildAccelerationStructuresIndirectKHRHandles, infoCount, pInfos);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos_unwrapped = UnwrapStructArrayHandles(pInfos, infoCount, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdBuildAccelerationStructuresIndirectKHR(commandBuffer_unwrapped, infoCount, pInfos_unwrapped, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}

VKAPI_ATTR VkResult VKAPI_CALL CopyAccelerationStructureToMemoryKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(VulkanCaptureManager::Get(), device, deferredOperation, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR deferredOperation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(deferredOperation);
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CopyAccelerationStructureToMemoryKHR(device_unwrapped, deferredOperation_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(deferredOperation);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, deferredOperation, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CopyMemoryToAccelerationStructureKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(VulkanCaptureManager::Get(), device, deferredOperation, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkDeferredOperationKHR deferredOperation_unwrapped = GetWrappedHandle<VkDeferredOperationKHR>(deferredOperation);
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->CopyMemoryToAccelerationStructureKHR(device_unwrapped, deferredOperation_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(deferredOperation);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, deferredOperation, pInfo);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAccelerationStructureKHR* pAccelerationStructures_unwrapped = UnwrapHandles<VkAccelerationStructureKHR>(pAccelerationStructures, accelerationStructureCount, handle_unwrap_memory);

    VkResult result = GetDeviceTable(device)->WriteAccelerationStructuresPropertiesKHR(device_unwrapped, accelerationStructureCount, pAccelerationStructures_unwrapped, queryType, dataSize, pData, stride);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR);
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
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyAccelerationStructureKHRHandles, pInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyAccelerationStructureKHR(commandBuffer_unwrapped, pInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureToMemoryKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyAccelerationStructureToMemoryKHRHandles, pInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyAccelerationStructureToMemoryKHR(commandBuffer_unwrapped, pInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyMemoryToAccelerationStructureKHR(
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdCopyMemoryToAccelerationStructureKHRHandles, pInfo);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    GetDeviceTable(commandBuffer)->CmdCopyMemoryToAccelerationStructureKHR(commandBuffer_unwrapped, pInfo_unwrapped);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pInfo);
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetAccelerationStructureDeviceAddressKHR(
    VkDevice                                    device,
    const VkAccelerationStructureDeviceAddressInfoKHR* pInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(VulkanCaptureManager::Get(), device, pInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAccelerationStructureDeviceAddressInfoKHR* pInfo_unwrapped = UnwrapStructPtrHandles(pInfo, handle_unwrap_memory);

    VkDeviceAddress result = GetDeviceTable(device)->GetAccelerationStructureDeviceAddressKHR(device_unwrapped, pInfo_unwrapped);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVkDeviceAddressValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pInfo);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(accelerationStructureCount);
        encoder->EncodeHandleArray(pAccelerationStructures, accelerationStructureCount);
        encoder->EncodeEnumValue(queryType);
        encoder->EncodeHandleValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdWriteAccelerationStructuresPropertiesKHRHandles, accelerationStructureCount, pAccelerationStructures, queryPool);
    }

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    const VkAccelerationStructureKHR* pAccelerationStructures_unwrapped = UnwrapHandles<VkAccelerationStructureKHR>(pAccelerationStructures, accelerationStructureCount, handle_unwrap_memory);
    VkQueryPool queryPool_unwrapped = GetWrappedHandle<VkQueryPool>(queryPool);

    GetDeviceTable(commandBuffer)->CmdWriteAccelerationStructuresPropertiesKHR(commandBuffer_unwrapped, accelerationStructureCount, pAccelerationStructures_unwrapped, queryType, queryPool_unwrapped, firstQuery);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceAccelerationStructureCompatibilityKHR(
    VkDevice                                    device,
    const VkAccelerationStructureVersionInfoKHR* pVersionInfo,
    VkAccelerationStructureCompatibilityKHR*    pCompatibility)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(VulkanCaptureManager::Get(), device, pVersionInfo, pCompatibility);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);

    GetDeviceTable(device)->GetDeviceAccelerationStructureCompatibilityKHR(device_unwrapped, pVersionInfo, pCompatibility);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        EncodeStructPtr(encoder, pVersionInfo);
        encoder->EncodeEnumPtr(pCompatibility);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR>::Dispatch(VulkanCaptureManager::Get(), device, pVersionInfo, pCompatibility);
}

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureBuildSizesKHR(
    VkDevice                                    device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo,
    const uint32_t*                             pMaxPrimitiveCounts,
    VkAccelerationStructureBuildSizesInfoKHR*   pSizeInfo)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(VulkanCaptureManager::Get(), device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);

    auto handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo_unwrapped = UnwrapStructPtrHandles(pBuildInfo, handle_unwrap_memory);

    GetDeviceTable(device)->GetAccelerationStructureBuildSizesKHR(device_unwrapped, buildType, pBuildInfo_unwrapped, pMaxPrimitiveCounts, pSizeInfo);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeEnumValue(buildType);
        EncodeStructPtr(encoder, pBuildInfo);
        encoder->EncodeUInt32Array(pMaxPrimitiveCounts, (pBuildInfo != nullptr) ? (pBuildInfo->geometryCount) : 0);
        EncodeStructPtr(encoder, pSizeInfo);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR>::Dispatch(VulkanCaptureManager::Get(), device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdTraceRaysKHR);
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
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdTraceRaysKHR(commandBuffer_unwrapped, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesKHR(
    VkDevice                                    device,
    VkDeferredOperationKHR                      deferredOperation,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkRayTracingPipelineCreateInfoKHR*    pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(VulkanCaptureManager::Get(), device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    VkResult result = VulkanCaptureManager::Get()->OverrideCreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(deferredOperation);
        encoder->EncodeHandleValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleArray(pPipelines, createInfoCount, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndGroupCreateApiCallCapture<VkDevice, VkDeferredOperationKHR, PipelineWrapper, VkRayTracingPipelineCreateInfoKHR>(result, device, deferredOperation, createInfoCount, pPipelines, pCreateInfos);
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

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
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    bool omit_output_data = false;

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(VulkanCaptureManager::Get(), device, pipeline, firstGroup, groupCount, dataSize, pData);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkResult result = GetDeviceTable(device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR(device_unwrapped, pipeline_unwrapped, firstGroup, groupCount, dataSize, pData);
    if (result < 0)
    {
        omit_output_data = true;
    }

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(firstGroup);
        encoder->EncodeUInt32Value(groupCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, omit_output_data);
        encoder->EncodeEnumValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysIndirectKHR(
    VkCommandBuffer                             commandBuffer,
    const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        EncodeStructPtr(encoder, pRaygenShaderBindingTable);
        EncodeStructPtr(encoder, pMissShaderBindingTable);
        EncodeStructPtr(encoder, pHitShaderBindingTable);
        EncodeStructPtr(encoder, pCallableShaderBindingTable);
        encoder->EncodeVkDeviceAddressValue(indirectDeviceAddress);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdTraceRaysIndirectKHR(commandBuffer_unwrapped, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}

VKAPI_ATTR VkDeviceSize VKAPI_CALL GetRayTracingShaderGroupStackSizeKHR(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(VulkanCaptureManager::Get(), device, pipeline, group, groupShader);

    VkDevice device_unwrapped = GetWrappedHandle<VkDevice>(device);
    VkPipeline pipeline_unwrapped = GetWrappedHandle<VkPipeline>(pipeline);

    VkDeviceSize result = GetDeviceTable(device)->GetRayTracingShaderGroupStackSizeKHR(device_unwrapped, pipeline_unwrapped, group, groupShader);

    auto encoder = VulkanCaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(device);
        encoder->EncodeHandleValue(pipeline);
        encoder->EncodeUInt32Value(group);
        encoder->EncodeEnumValue(groupShader);
        encoder->EncodeVkDeviceSizeValue(result);
        VulkanCaptureManager::Get()->EndApiCallCapture();
    }

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR>::Dispatch(VulkanCaptureManager::Get(), result, device, pipeline, group, groupShader);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetRayTracingPipelineStackSizeKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineStackSize);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(pipelineStackSize);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdSetRayTracingPipelineStackSizeKHR(commandBuffer_unwrapped, pipelineStackSize);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, pipelineStackSize);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawMeshTasksEXT(commandBuffer_unwrapped, groupCountX, groupCountY, groupCountZ);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawMeshTasksIndirectEXTHandles, buffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);

    GetDeviceTable(commandBuffer)->CmdDrawMeshTasksIndirectEXT(commandBuffer_unwrapped, buffer_unwrapped, offset, drawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountEXT(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    auto state_lock = VulkanCaptureManager::Get()->AcquireSharedStateLock();

    CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = VulkanCaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT);
    if (encoder)
    {
        encoder->EncodeHandleValue(commandBuffer);
        encoder->EncodeHandleValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        VulkanCaptureManager::Get()->EndCommandApiCallCapture(commandBuffer, TrackCmdDrawMeshTasksIndirectCountEXTHandles, buffer, countBuffer);
    }

    VkCommandBuffer commandBuffer_unwrapped = GetWrappedHandle<VkCommandBuffer>(commandBuffer);
    VkBuffer buffer_unwrapped = GetWrappedHandle<VkBuffer>(buffer);
    VkBuffer countBuffer_unwrapped = GetWrappedHandle<VkBuffer>(countBuffer);

    GetDeviceTable(commandBuffer)->CmdDrawMeshTasksIndirectCountEXT(commandBuffer_unwrapped, buffer_unwrapped, offset, countBuffer_unwrapped, countBufferOffset, maxDrawCount, stride);

    CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT>::Dispatch(VulkanCaptureManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
