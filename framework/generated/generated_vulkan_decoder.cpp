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

#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/value_decoder.h"
#include "decode/vulkan_pnext_node.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <cstddef>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t VulkanDecoder::Decode_vkCreateInstance(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_VkInstanceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkInstance> pInstance;
    VkResult return_value;

    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInstance.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateInstance(call_info, return_value, &pCreateInfo, &pAllocator, &pInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyInstance(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyInstance(call_info, instance, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDevices(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceCount;
    HandlePointerDecoder<VkPhysicalDevice> pPhysicalDevices;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPhysicalDevices.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEnumeratePhysicalDevices(call_info, return_value, instance, &pPhysicalDeviceCount, &pPhysicalDevices);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures(call_info, physicalDevice, &pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFormatProperties(call_info, physicalDevice, format, &pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    StructPointerDecoder<Decoded_VkImageFormatProperties> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &tiling);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += pImageFormatProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties(call_info, return_value, physicalDevice, format, type, tiling, usage, flags, &pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties(call_info, physicalDevice, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties(call_info, physicalDevice, &pQueueFamilyPropertyCount, &pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties(call_info, physicalDevice, &pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDevice(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDevice> pDevice;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDevice.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDevice(call_info, return_value, physicalDevice, &pCreateInfo, &pAllocator, &pDevice);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDevice(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDevice(call_info, device, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceQueue(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t queueFamilyIndex;
    uint32_t queueIndex;
    HandlePointerDecoder<VkQueue> pQueue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueIndex);
    bytes_read += pQueue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceQueue(call_info, device, queueFamilyIndex, queueIndex, &pQueue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueSubmit(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo> pSubmits;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &submitCount);
    bytes_read += pSubmits.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueSubmit(call_info, return_value, queue, submitCount, &pSubmits, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueWaitIdle(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueWaitIdle(call_info, return_value, queue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDeviceWaitIdle(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDeviceWaitIdle(call_info, return_value, device);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo> pAllocateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDeviceMemory> pMemory;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemory.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAllocateMemory(call_info, return_value, device, &pAllocateInfo, &pAllocator, &pMemory);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFreeMemory(call_info, device, memory, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMapMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkMemoryMapFlags flags;
    PointerDecoder<uint64_t, void*> ppData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ppData.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMapMemory(call_info, return_value, device, memory, offset, size, flags, &ppData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUnmapMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUnmapMemory(call_info, device, memory);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFlushMappedMemoryRanges(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryRangeCount);
    bytes_read += pMemoryRanges.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFlushMappedMemoryRanges(call_info, return_value, device, memoryRangeCount, &pMemoryRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkInvalidateMappedMemoryRanges(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryRangeCount);
    bytes_read += pMemoryRanges.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkInvalidateMappedMemoryRanges(call_info, return_value, device, memoryRangeCount, &pMemoryRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceMemoryCommitment(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    PointerDecoder<VkDeviceSize> pCommittedMemoryInBytes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += pCommittedMemoryInBytes.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceMemoryCommitment(call_info, device, memory, &pCommittedMemoryInBytes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    format::HandleId memory;
    VkDeviceSize memoryOffset;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryOffset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindBufferMemory(call_info, return_value, device, buffer, memory, memoryOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    format::HandleId memory;
    VkDeviceSize memoryOffset;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryOffset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindImageMemory(call_info, return_value, device, image, memory, memoryOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferMemoryRequirements(call_info, device, buffer, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageMemoryRequirements(call_info, device, image, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSparseMemoryRequirements(call_info, device, image, &pSparseMemoryRequirementCount, &pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkSampleCountFlagBits samples;
    VkImageUsageFlags usage;
    VkImageTiling tiling;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &samples);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &tiling);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties(call_info, physicalDevice, format, type, samples, usage, tiling, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueBindSparse(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindSparseInfo> pBindInfo;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueBindSparse(call_info, return_value, queue, bindInfoCount, &pBindInfo, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateFence(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFence.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateFence(call_info, return_value, device, &pCreateInfo, &pAllocator, &pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyFence(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId fence;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyFence(call_info, device, fence, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetFences(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t fenceCount;
    HandlePointerDecoder<VkFence> pFences;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fenceCount);
    bytes_read += pFences.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetFences(call_info, return_value, device, fenceCount, &pFences);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceStatus(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetFenceStatus(call_info, return_value, device, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWaitForFences(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t fenceCount;
    HandlePointerDecoder<VkFence> pFences;
    VkBool32 waitAll;
    uint64_t timeout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fenceCount);
    bytes_read += pFences.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &waitAll);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkWaitForFences(call_info, return_value, device, fenceCount, &pFences, waitAll, timeout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSemaphore(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSemaphore> pSemaphore;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSemaphore.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSemaphore(call_info, return_value, device, &pCreateInfo, &pAllocator, &pSemaphore);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySemaphore(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId semaphore;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySemaphore(call_info, device, semaphore, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkEventCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkEvent> pEvent;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pEvent.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateEvent(call_info, return_value, device, &pCreateInfo, &pAllocator, &pEvent);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyEvent(call_info, device, event, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetEventStatus(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetEventStatus(call_info, return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetEvent(call_info, return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetEvent(call_info, return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkQueryPool> pQueryPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueryPool.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateQueryPool(call_info, return_value, device, &pCreateInfo, &pAllocator, &pQueryPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId queryPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyQueryPool(call_info, device, queryPool, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetQueryPoolResults(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkDeviceSize stride;
    VkQueryResultFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryCount);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetQueryPoolResults(call_info, return_value, device, queryPool, firstQuery, queryCount, dataSize, &pData, stride, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkBuffer> pBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pBuffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateBuffer(call_info, return_value, device, &pCreateInfo, &pAllocator, &pBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyBuffer(call_info, device, buffer, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateBufferView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkBufferView> pView;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pView.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateBufferView(call_info, return_value, device, &pCreateInfo, &pAllocator, &pView);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyBufferView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId bufferView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferView);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyBufferView(call_info, device, bufferView, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkImage> pImage;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImage.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateImage(call_info, return_value, device, &pCreateInfo, &pAllocator, &pImage);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyImage(call_info, device, image, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSubresourceLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout> pLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pSubresource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pLayout.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSubresourceLayout(call_info, device, image, &pSubresource, &pLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImageView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkImageView> pView;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pView.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateImageView(call_info, return_value, device, &pCreateInfo, &pAllocator, &pView);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyImageView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId imageView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageView);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyImageView(call_info, device, imageView, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateShaderModule(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkShaderModule> pShaderModule;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pShaderModule.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateShaderModule(call_info, return_value, device, &pCreateInfo, &pAllocator, &pShaderModule);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyShaderModule(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId shaderModule;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shaderModule);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyShaderModule(call_info, device, shaderModule, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePipelineCache(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipelineCache> pPipelineCache;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelineCache.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreatePipelineCache(call_info, return_value, device, &pCreateInfo, &pAllocator, &pPipelineCache);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipelineCache(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPipelineCache(call_info, device, pipelineCache, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineCacheData(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += pDataSize.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPipelineCacheData(call_info, return_value, device, pipelineCache, &pDataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMergePipelineCaches(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId dstCache;
    uint32_t srcCacheCount;
    HandlePointerDecoder<VkPipelineCache> pSrcCaches;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcCacheCount);
    bytes_read += pSrcCaches.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMergePipelineCaches(call_info, return_value, device, dstCache, srcCacheCount, &pSrcCaches);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateGraphicsPipelines(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipeline> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelines.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateGraphicsPipelines(call_info, return_value, device, pipelineCache, createInfoCount, &pCreateInfos, &pAllocator, &pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateComputePipelines(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipeline> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelines.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateComputePipelines(call_info, return_value, device, pipelineCache, createInfoCount, &pCreateInfos, &pAllocator, &pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipeline(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPipeline(call_info, device, pipeline, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePipelineLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipelineLayout> pPipelineLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelineLayout.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreatePipelineLayout(call_info, return_value, device, &pCreateInfo, &pAllocator, &pPipelineLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipelineLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineLayout);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPipelineLayout(call_info, device, pipelineLayout, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSampler(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSampler> pSampler;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSampler.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSampler(call_info, return_value, device, &pCreateInfo, &pAllocator, &pSampler);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySampler(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId sampler;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sampler);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySampler(call_info, device, sampler, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorSetLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSetLayout.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorSetLayout(call_info, return_value, device, &pCreateInfo, &pAllocator, &pSetLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorSetLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorSetLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSetLayout);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorSetLayout(call_info, device, descriptorSetLayout, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorPool> pDescriptorPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorPool.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorPool(call_info, return_value, device, &pCreateInfo, &pAllocator, &pDescriptorPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorPool);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorPool(call_info, device, descriptorPool, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetDescriptorPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorPool;
    VkDescriptorPoolResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetDescriptorPool(call_info, return_value, device, descriptorPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo> pAllocateInfo;
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorSets.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAllocateDescriptorSets(call_info, return_value, device, &pAllocateInfo, &pDescriptorSets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorPool;
    uint32_t descriptorSetCount;
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSetCount);
    bytes_read += pDescriptorSets.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFreeDescriptorSets(call_info, return_value, device, descriptorPool, descriptorSetCount, &pDescriptorSets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUpdateDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;
    uint32_t descriptorCopyCount;
    StructPointerDecoder<Decoded_VkCopyDescriptorSet> pDescriptorCopies;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorWriteCount);
    bytes_read += pDescriptorWrites.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorCopyCount);
    bytes_read += pDescriptorCopies.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUpdateDescriptorSets(call_info, device, descriptorWriteCount, &pDescriptorWrites, descriptorCopyCount, &pDescriptorCopies);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateFramebuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFramebuffer> pFramebuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFramebuffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateFramebuffer(call_info, return_value, device, &pCreateInfo, &pAllocator, &pFramebuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyFramebuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId framebuffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &framebuffer);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyFramebuffer(call_info, device, framebuffer, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRenderPass.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRenderPass(call_info, return_value, device, &pCreateInfo, &pAllocator, &pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &renderPass);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyRenderPass(call_info, device, renderPass, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRenderAreaGranularity(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &renderPass);
    bytes_read += pGranularity.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRenderAreaGranularity(call_info, device, renderPass, &pGranularity);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkCommandPool> pCommandPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCommandPool.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateCommandPool(call_info, return_value, device, &pCreateInfo, &pAllocator, &pCommandPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyCommandPool(call_info, device, commandPool, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetCommandPool(call_info, return_value, device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateCommandBuffers(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo> pAllocateInfo;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCommandBuffers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAllocateCommandBuffers(call_info, return_value, device, &pAllocateInfo, &pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeCommandBuffers(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    uint32_t commandBufferCount;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBufferCount);
    bytes_read += pCommandBuffers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFreeCommandBuffers(call_info, device, commandPool, commandBufferCount, &pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBeginCommandBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo> pBeginInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBeginInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBeginCommandBuffer(call_info, return_value, commandBuffer, &pBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEndCommandBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEndCommandBuffer(call_info, return_value, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetCommandBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCommandBufferResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetCommandBuffer(call_info, return_value, commandBuffer, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindPipeline(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindPipeline(call_info, commandBuffer, pipelineBindPoint, pipeline);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewport(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewports.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewport(call_info, commandBuffer, firstViewport, viewportCount, &pViewports);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetScissor(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstScissor;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scissorCount);
    bytes_read += pScissors.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetScissor(call_info, commandBuffer, firstScissor, scissorCount, &pScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLineWidth(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float lineWidth;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineWidth);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetLineWidth(call_info, commandBuffer, lineWidth);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBias(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float depthBiasConstantFactor;
    float depthBiasClamp;
    float depthBiasSlopeFactor;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBiasConstantFactor);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBiasClamp);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBiasSlopeFactor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBias(call_info, commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetBlendConstants(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    PointerDecoder<float> blendConstants;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += blendConstants.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetBlendConstants(call_info, commandBuffer, &blendConstants);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBounds(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float minDepthBounds;
    float maxDepthBounds;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &minDepthBounds);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDepthBounds);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBounds(call_info, commandBuffer, minDepthBounds, maxDepthBounds);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilCompareMask(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t compareMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &compareMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilCompareMask(call_info, commandBuffer, faceMask, compareMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilWriteMask(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t writeMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &writeMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilWriteMask(call_info, commandBuffer, faceMask, writeMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilReference(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t reference;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &reference);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilReference(call_info, commandBuffer, faceMask, reference);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t firstSet;
    uint32_t descriptorSetCount;
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;
    uint32_t dynamicOffsetCount;
    PointerDecoder<uint32_t> pDynamicOffsets;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstSet);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSetCount);
    bytes_read += pDescriptorSets.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dynamicOffsetCount);
    bytes_read += pDynamicOffsets.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindDescriptorSets(call_info, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, &pDescriptorSets, dynamicOffsetCount, &pDynamicOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindIndexBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkIndexType indexType;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indexType);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindIndexBuffer(call_info, commandBuffer, buffer, offset, indexType);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindVertexBuffers(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstBinding);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindingCount);
    bytes_read += pBuffers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pOffsets.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindVertexBuffers(call_info, commandBuffer, firstBinding, bindingCount, &pBuffers, &pOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDraw(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstVertex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstInstance);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDraw(call_info, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexed(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t firstIndex;
    int32_t vertexOffset;
    uint32_t firstInstance;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indexCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstIndex);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstInstance);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexed(call_info, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirect(call_info, commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirect(call_info, commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatch(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatch(call_info, commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchIndirect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatchIndirect(call_info, commandBuffer, buffer, offset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcBuffer;
    format::HandleId dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyBuffer(call_info, commandBuffer, srcBuffer, dstBuffer, regionCount, &pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyImage(call_info, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, &pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBlitImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageBlit> pRegions;
    VkFilter filter;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &filter);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBlitImage(call_info, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, &pRegions, filter);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBufferToImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcBuffer;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyBufferToImage(call_info, commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, &pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImageToBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyImageToBuffer(call_info, commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, &pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdUpdateBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize dataSize;
    PointerDecoder<uint8_t> pData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdUpdateBuffer(call_info, commandBuffer, dstBuffer, dstOffset, dataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdFillBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize size;
    uint32_t data;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &data);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdFillBuffer(call_info, commandBuffer, dstBuffer, dstOffset, size, data);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearColorImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId image;
    VkImageLayout imageLayout;
    StructPointerDecoder<Decoded_VkClearColorValue> pColor;
    uint32_t rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageLayout);
    bytes_read += pColor.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rangeCount);
    bytes_read += pRanges.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdClearColorImage(call_info, commandBuffer, image, imageLayout, &pColor, rangeCount, &pRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearDepthStencilImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId image;
    VkImageLayout imageLayout;
    StructPointerDecoder<Decoded_VkClearDepthStencilValue> pDepthStencil;
    uint32_t rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageLayout);
    bytes_read += pDepthStencil.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rangeCount);
    bytes_read += pRanges.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdClearDepthStencilImage(call_info, commandBuffer, image, imageLayout, &pDepthStencil, rangeCount, &pRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearAttachments(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkClearAttachment> pAttachments;
    uint32_t rectCount;
    StructPointerDecoder<Decoded_VkClearRect> pRects;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pAttachments.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rectCount);
    bytes_read += pRects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdClearAttachments(call_info, commandBuffer, attachmentCount, &pAttachments, rectCount, &pRects);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResolveImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageResolve> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResolveImage(call_info, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, &pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetEvent(call_info, commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResetEvent(call_info, commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWaitEvents(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t eventCount;
    HandlePointerDecoder<VkEvent> pEvents;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    uint32_t memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &eventCount);
    bytes_read += pEvents.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstStageMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryBarrierCount);
    bytes_read += pMemoryBarriers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferMemoryBarrierCount);
    bytes_read += pBufferMemoryBarriers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageMemoryBarrierCount);
    bytes_read += pImageMemoryBarriers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWaitEvents(call_info, commandBuffer, eventCount, &pEvents, srcStageMask, dstStageMask, memoryBarrierCount, &pMemoryBarriers, bufferMemoryBarrierCount, &pBufferMemoryBarriers, imageMemoryBarrierCount, &pImageMemoryBarriers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPipelineBarrier(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    VkDependencyFlags dependencyFlags;
    uint32_t memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dependencyFlags);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryBarrierCount);
    bytes_read += pMemoryBarriers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferMemoryBarrierCount);
    bytes_read += pBufferMemoryBarriers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageMemoryBarrierCount);
    bytes_read += pImageMemoryBarriers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPipelineBarrier(call_info, commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, &pMemoryBarriers, bufferMemoryBarrierCount, &pBufferMemoryBarriers, imageMemoryBarrierCount, &pImageMemoryBarriers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginQuery(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    VkQueryControlFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginQuery(call_info, commandBuffer, queryPool, query, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndQuery(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndQuery(call_info, commandBuffer, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryCount);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResetQueryPool(call_info, commandBuffer, queryPool, firstQuery, queryCount);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteTimestamp(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineStage);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteTimestamp(call_info, commandBuffer, pipelineStage, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyQueryPoolResults(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize stride;
    VkQueryResultFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryCount);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyQueryPoolResults(call_info, commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushConstants(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId layout;
    VkShaderStageFlags stageFlags;
    uint32_t offset;
    uint32_t size;
    PointerDecoder<uint8_t> pValues;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageFlags);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &size);
    bytes_read += pValues.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPushConstants(call_info, commandBuffer, layout, stageFlags, offset, size, &pValues);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &contents);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginRenderPass(call_info, commandBuffer, &pRenderPassBegin, contents);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &contents);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdNextSubpass(call_info, commandBuffer, contents);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderPass(call_info, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdExecuteCommands(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t commandBufferCount;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBufferCount);
    bytes_read += pCommandBuffers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdExecuteCommands(call_info, commandBuffer, commandBufferCount, &pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindBufferMemory2(call_info, return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindImageMemory2(call_info, return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPeerMemoryFeatures(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &heapIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &localDeviceIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &remoteDeviceIndex);
    bytes_read += pPeerMemoryFeatures.DecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupPeerMemoryFeatures(call_info, device, heapIndex, localDeviceIndex, remoteDeviceIndex, &pPeerMemoryFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDeviceMask(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDeviceMask(call_info, commandBuffer, deviceMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchBase(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupZ);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatchBase(call_info, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceGroups(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceGroupCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEnumeratePhysicalDeviceGroups(call_info, return_value, instance, &pPhysicalDeviceGroupCount, &pPhysicalDeviceGroupProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageMemoryRequirements2(call_info, device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferMemoryRequirements2(call_info, device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSparseMemoryRequirements2(call_info, device, &pInfo, &pSparseMemoryRequirementCount, &pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures2(call_info, physicalDevice, &pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties2(call_info, physicalDevice, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFormatProperties2(call_info, physicalDevice, format, &pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pImageFormatInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties2(call_info, return_value, physicalDevice, &pImageFormatInfo, &pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties2(call_info, physicalDevice, &pQueueFamilyPropertyCount, &pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties2(call_info, physicalDevice, &pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFormatInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties2(call_info, physicalDevice, &pFormatInfo, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTrimCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkTrimCommandPool(call_info, device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceQueue2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2> pQueueInfo;
    HandlePointerDecoder<VkQueue> pQueue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pQueueInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceQueue2(call_info, device, &pQueueInfo, &pQueue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSamplerYcbcrConversion(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pYcbcrConversion.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSamplerYcbcrConversion(call_info, return_value, device, &pCreateInfo, &pAllocator, &pYcbcrConversion);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySamplerYcbcrConversion(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ycbcrConversion);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySamplerYcbcrConversion(call_info, device, ycbcrConversion, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorUpdateTemplate(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorUpdateTemplate.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorUpdateTemplate(call_info, return_value, device, &pCreateInfo, &pAllocator, &pDescriptorUpdateTemplate);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorUpdateTemplate(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorUpdateTemplate(call_info, device, descriptorUpdateTemplate, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalBufferProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalBufferInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalBufferProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalBufferProperties(call_info, physicalDevice, &pExternalBufferInfo, &pExternalBufferProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalFenceProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalFenceInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalFenceProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalFenceProperties(call_info, physicalDevice, &pExternalFenceInfo, &pExternalFenceProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalSemaphoreInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalSemaphoreProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalSemaphoreProperties(call_info, physicalDevice, &pExternalSemaphoreInfo, &pExternalSemaphoreProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutSupport(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSupport.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDescriptorSetLayoutSupport(call_info, device, &pCreateInfo, &pSupport);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectCount(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirectCount(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRenderPass.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRenderPass2(call_info, return_value, device, &pCreateInfo, &pAllocator, &pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSubpassBeginInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginRenderPass2(call_info, commandBuffer, &pRenderPassBegin, &pSubpassBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassBeginInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSubpassEndInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdNextSubpass2(call_info, commandBuffer, &pSubpassBeginInfo, &pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassEndInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderPass2(call_info, commandBuffer, &pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryCount);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetQueryPool(call_info, device, queryPool, firstQuery, queryCount);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreCounterValue(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId semaphore;
    PointerDecoder<uint64_t> pValue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += pValue.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSemaphoreCounterValue(call_info, return_value, device, semaphore, &pValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWaitSemaphores(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo> pWaitInfo;
    uint64_t timeout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pWaitInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkWaitSemaphores(call_info, return_value, device, &pWaitInfo, timeout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSignalSemaphore(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo> pSignalInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pSignalInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSignalSemaphore(call_info, return_value, device, &pSignalInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferDeviceAddress(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferDeviceAddress(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferOpaqueCaptureAddress(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    uint64_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferOpaqueCaptureAddress(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceMemoryOpaqueCaptureAddress(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo> pInfo;
    uint64_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceMemoryOpaqueCaptureAddress(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceToolProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties> pToolProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pToolCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pToolProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceToolProperties(call_info, return_value, physicalDevice, &pToolCount, &pToolProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePrivateDataSlot(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlot> pPrivateDataSlot;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPrivateDataSlot.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreatePrivateDataSlot(call_info, return_value, device, &pCreateInfo, &pAllocator, &pPrivateDataSlot);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPrivateDataSlot(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId privateDataSlot;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &privateDataSlot);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPrivateDataSlot(call_info, device, privateDataSlot, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetPrivateData(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkObjectType objectType;
    uint64_t objectHandle;
    format::HandleId privateDataSlot;
    uint64_t data;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectType);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectHandle);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &privateDataSlot);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &data);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetPrivateData(call_info, return_value, device, objectType, objectHandle, privateDataSlot, data);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPrivateData(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkObjectType objectType;
    uint64_t objectHandle;
    format::HandleId privateDataSlot;
    PointerDecoder<uint64_t> pData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectType);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectHandle);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &privateDataSlot);
    bytes_read += pData.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPrivateData(call_info, device, objectType, objectHandle, privateDataSlot, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetEvent2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += pDependencyInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetEvent2(call_info, commandBuffer, event, &pDependencyInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetEvent2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags2 stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlags64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResetEvent2(call_info, commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWaitEvents2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t eventCount;
    HandlePointerDecoder<VkEvent> pEvents;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfos;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &eventCount);
    bytes_read += pEvents.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDependencyInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWaitEvents2(call_info, commandBuffer, eventCount, &pEvents, &pDependencyInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPipelineBarrier2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pDependencyInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPipelineBarrier2(call_info, commandBuffer, &pDependencyInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteTimestamp2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlags2 stage;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlags64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stage);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteTimestamp2(call_info, commandBuffer, stage, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueSubmit2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo2> pSubmits;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &submitCount);
    bytes_read += pSubmits.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueSubmit2(call_info, return_value, queue, submitCount, &pSubmits, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBuffer2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferInfo2> pCopyBufferInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyBufferInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyBuffer2(call_info, commandBuffer, &pCopyBufferInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageInfo2> pCopyImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyImageInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyImage2(call_info, commandBuffer, &pCopyImageInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBufferToImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2> pCopyBufferToImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyBufferToImageInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyBufferToImage2(call_info, commandBuffer, &pCopyBufferToImageInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImageToBuffer2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2> pCopyImageToBufferInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyImageToBufferInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyImageToBuffer2(call_info, commandBuffer, &pCopyImageToBufferInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBlitImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBlitImageInfo2> pBlitImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBlitImageInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBlitImage2(call_info, commandBuffer, &pBlitImageInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResolveImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkResolveImageInfo2> pResolveImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pResolveImageInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResolveImage2(call_info, commandBuffer, &pResolveImageInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRendering(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderingInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginRendering(call_info, commandBuffer, &pRenderingInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRendering(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRendering(call_info, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCullMode(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCullModeFlags cullMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &cullMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCullMode(call_info, commandBuffer, cullMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetFrontFace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkFrontFace frontFace;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &frontFace);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetFrontFace(call_info, commandBuffer, frontFace);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPrimitiveTopology(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPrimitiveTopology primitiveTopology;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &primitiveTopology);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetPrimitiveTopology(call_info, commandBuffer, primitiveTopology);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportWithCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewports.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewportWithCount(call_info, commandBuffer, viewportCount, &pViewports);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetScissorWithCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scissorCount);
    bytes_read += pScissors.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetScissorWithCount(call_info, commandBuffer, scissorCount, &pScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindVertexBuffers2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;
    PointerDecoder<VkDeviceSize> pSizes;
    PointerDecoder<VkDeviceSize> pStrides;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstBinding);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindingCount);
    bytes_read += pBuffers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pOffsets.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizes.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pStrides.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindVertexBuffers2(call_info, commandBuffer, firstBinding, bindingCount, &pBuffers, &pOffsets, &pSizes, &pStrides);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthTestEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthTestEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthTestEnable(call_info, commandBuffer, depthTestEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthWriteEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthWriteEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthWriteEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthWriteEnable(call_info, commandBuffer, depthWriteEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthCompareOp(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCompareOp depthCompareOp;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthCompareOp);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthCompareOp(call_info, commandBuffer, depthCompareOp);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBoundsTestEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthBoundsTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBoundsTestEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBoundsTestEnable(call_info, commandBuffer, depthBoundsTestEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilTestEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 stencilTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stencilTestEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilTestEnable(call_info, commandBuffer, stencilTestEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilOp(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    VkStencilOp failOp;
    VkStencilOp passOp;
    VkStencilOp depthFailOp;
    VkCompareOp compareOp;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &failOp);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &passOp);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthFailOp);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &compareOp);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilOp(call_info, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetRasterizerDiscardEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 rasterizerDiscardEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rasterizerDiscardEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetRasterizerDiscardEnable(call_info, commandBuffer, rasterizerDiscardEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBiasEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthBiasEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBiasEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBiasEnable(call_info, commandBuffer, depthBiasEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPrimitiveRestartEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 primitiveRestartEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &primitiveRestartEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetPrimitiveRestartEnable(call_info, commandBuffer, primitiveRestartEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceBufferMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceBufferMemoryRequirements(call_info, device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceImageMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceImageMemoryRequirements(call_info, device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceImageSparseMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceImageSparseMemoryRequirements(call_info, device, &pInfo, &pSparseMemoryRequirementCount, &pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySurfaceKHR(call_info, instance, surface, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    format::HandleId surface;
    PointerDecoder<VkBool32> pSupported;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSupported.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceSupportKHR(call_info, return_value, physicalDevice, queueFamilyIndex, surface, &pSupported);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceCapabilities.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(call_info, return_value, physicalDevice, surface, &pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR> pSurfaceFormats;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceFormatCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceFormatsKHR(call_info, return_value, physicalDevice, surface, &pSurfaceFormatCount, &pSurfaceFormats);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pPresentModeCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPresentModes.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfacePresentModesKHR(call_info, return_value, physicalDevice, surface, &pPresentModeCount, &pPresentModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSwapchainKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSwapchain.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSwapchainKHR(call_info, return_value, device, &pCreateInfo, &pAllocator, &pSwapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySwapchainKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySwapchainKHR(call_info, device, swapchain, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainImagesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pSwapchainImageCount;
    HandlePointerDecoder<VkImage> pSwapchainImages;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pSwapchainImageCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSwapchainImages.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSwapchainImagesKHR(call_info, return_value, device, swapchain, &pSwapchainImageCount, &pSwapchainImages);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireNextImageKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    uint64_t timeout;
    format::HandleId semaphore;
    format::HandleId fence;
    PointerDecoder<uint32_t> pImageIndex;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += pImageIndex.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireNextImageKHR(call_info, return_value, device, swapchain, timeout, semaphore, fence, &pImageIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueuePresentKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkPresentInfoKHR> pPresentInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pPresentInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueuePresentKHR(call_info, return_value, queue, &pPresentInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPresentCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR> pDeviceGroupPresentCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pDeviceGroupPresentCapabilities.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupPresentCapabilitiesKHR(call_info, return_value, device, &pDeviceGroupPresentCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupSurfacePresentModesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId surface;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pModes.DecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupSurfacePresentModesKHR(call_info, return_value, device, surface, &pModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDevicePresentRectanglesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pRectCount;
    StructPointerDecoder<Decoded_VkRect2D> pRects;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pRectCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDevicePresentRectanglesKHR(call_info, return_value, physicalDevice, surface, &pRectCount, &pRects);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireNextImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR> pAcquireInfo;
    PointerDecoder<uint32_t> pImageIndex;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAcquireInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageIndex.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireNextImage2KHR(call_info, return_value, device, &pAcquireInfo, &pImageIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayPropertiesKHR(call_info, return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(call_info, return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneSupportedDisplaysKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t planeIndex;
    PointerDecoder<uint32_t> pDisplayCount;
    HandlePointerDecoder<VkDisplayKHR> pDisplays;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeIndex);
    bytes_read += pDisplayCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDisplays.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayPlaneSupportedDisplaysKHR(call_info, return_value, physicalDevice, planeIndex, &pDisplayCount, &pDisplays);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayModePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayModePropertiesKHR(call_info, return_value, physicalDevice, display, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDisplayModeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDisplayModeKHR> pMode;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMode.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDisplayModeKHR(call_info, return_value, physicalDevice, display, &pCreateInfo, &pAllocator, &pMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId mode;
    uint32_t planeIndex;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR> pCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &mode);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeIndex);
    bytes_read += pCapabilities.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayPlaneCapabilitiesKHR(call_info, return_value, physicalDevice, mode, planeIndex, &pCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDisplayPlaneSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDisplayPlaneSurfaceKHR(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSharedSwapchainsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t swapchainCount;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchains;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchainCount);
    bytes_read += pCreateInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSwapchains.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSharedSwapchainsKHR(call_info, return_value, device, swapchainCount, &pCreateInfos, &pAllocator, &pSwapchains);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateXlibSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateXlibSurfaceKHR(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t dpy;
    size_t visualID;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dpy);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &visualID);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(call_info, return_value, physicalDevice, queueFamilyIndex, dpy, visualID);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateXcbSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateXcbSurfaceKHR(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t connection;
    uint32_t visual_id;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &connection);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &visual_id);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(call_info, return_value, physicalDevice, queueFamilyIndex, connection, visual_id);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateWaylandSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateWaylandSurfaceKHR(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t display;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(call_info, return_value, physicalDevice, queueFamilyIndex, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateAndroidSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateAndroidSurfaceKHR(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateWin32SurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateWin32SurfaceKHR(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(call_info, return_value, physicalDevice, queueFamilyIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceVideoCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR> pVideoProfile;
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR> pCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pVideoProfile.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCapabilities.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(call_info, return_value, physicalDevice, &pVideoProfile, &pCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceVideoFormatPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR> pVideoFormatInfo;
    PointerDecoder<uint32_t> pVideoFormatPropertyCount;
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR> pVideoFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pVideoFormatInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pVideoFormatPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pVideoFormatProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(call_info, return_value, physicalDevice, &pVideoFormatInfo, &pVideoFormatPropertyCount, &pVideoFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateVideoSessionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkVideoSessionKHR> pVideoSession;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pVideoSession.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateVideoSessionKHR(call_info, return_value, device, &pCreateInfo, &pAllocator, &pVideoSession);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyVideoSessionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId videoSession;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &videoSession);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyVideoSessionKHR(call_info, device, videoSession, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetVideoSessionMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId videoSession;
    PointerDecoder<uint32_t> pMemoryRequirementsCount;
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR> pMemoryRequirements;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &videoSession);
    bytes_read += pMemoryRequirementsCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetVideoSessionMemoryRequirementsKHR(call_info, return_value, device, videoSession, &pMemoryRequirementsCount, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindVideoSessionMemoryKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId videoSession;
    uint32_t bindSessionMemoryInfoCount;
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR> pBindSessionMemoryInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &videoSession);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindSessionMemoryInfoCount);
    bytes_read += pBindSessionMemoryInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindVideoSessionMemoryKHR(call_info, return_value, device, videoSession, bindSessionMemoryInfoCount, &pBindSessionMemoryInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkVideoSessionParametersKHR> pVideoSessionParameters;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pVideoSessionParameters.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateVideoSessionParametersKHR(call_info, return_value, device, &pCreateInfo, &pAllocator, &pVideoSessionParameters);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUpdateVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId videoSessionParameters;
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR> pUpdateInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &videoSessionParameters);
    bytes_read += pUpdateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUpdateVideoSessionParametersKHR(call_info, return_value, device, videoSessionParameters, &pUpdateInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId videoSessionParameters;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &videoSessionParameters);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyVideoSessionParametersKHR(call_info, device, videoSessionParameters, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginVideoCodingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR> pBeginInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBeginInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginVideoCodingKHR(call_info, commandBuffer, &pBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndVideoCodingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR> pEndCodingInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pEndCodingInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndVideoCodingKHR(call_info, commandBuffer, &pEndCodingInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdControlVideoCodingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR> pCodingControlInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCodingControlInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdControlVideoCodingKHR(call_info, commandBuffer, &pCodingControlInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDecodeVideoKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR> pDecodeInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pDecodeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDecodeVideoKHR(call_info, commandBuffer, &pDecodeInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderingInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginRenderingKHR(call_info, commandBuffer, &pRenderingInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderingKHR(call_info, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures2KHR(call_info, physicalDevice, &pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties2KHR(call_info, physicalDevice, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFormatProperties2KHR(call_info, physicalDevice, format, &pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pImageFormatInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties2KHR(call_info, return_value, physicalDevice, &pImageFormatInfo, &pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(call_info, physicalDevice, &pQueueFamilyPropertyCount, &pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties2KHR(call_info, physicalDevice, &pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFormatInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(call_info, physicalDevice, &pFormatInfo, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &heapIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &localDeviceIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &remoteDeviceIndex);
    bytes_read += pPeerMemoryFeatures.DecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(call_info, device, heapIndex, localDeviceIndex, remoteDeviceIndex, &pPeerMemoryFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDeviceMaskKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDeviceMaskKHR(call_info, commandBuffer, deviceMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchBaseKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupZ);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatchBaseKHR(call_info, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTrimCommandPoolKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkTrimCommandPoolKHR(call_info, device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceGroupsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceGroupCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEnumeratePhysicalDeviceGroupsKHR(call_info, return_value, instance, &pPhysicalDeviceGroupCount, &pPhysicalDeviceGroupProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalBufferInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalBufferProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(call_info, physicalDevice, &pExternalBufferInfo, &pExternalBufferProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryWin32HandleKHR(call_info, return_value, device, &pGetWin32HandleInfo, &pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandlePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t handle;
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR> pMemoryWin32HandleProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handle);
    bytes_read += pMemoryWin32HandleProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryWin32HandlePropertiesKHR(call_info, return_value, device, handleType, handle, &pMemoryWin32HandleProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryFdKHR(call_info, return_value, device, &pGetFdInfo, &pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryFdPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    int fd;
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR> pMemoryFdProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fd);
    bytes_read += pMemoryFdProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryFdPropertiesKHR(call_info, return_value, device, handleType, fd, &pMemoryFdProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalSemaphoreInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalSemaphoreProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(call_info, physicalDevice, &pExternalSemaphoreInfo, &pExternalSemaphoreProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportSemaphoreWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR> pImportSemaphoreWin32HandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreWin32HandleInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportSemaphoreWin32HandleKHR(call_info, return_value, device, &pImportSemaphoreWin32HandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSemaphoreWin32HandleKHR(call_info, return_value, device, &pGetWin32HandleInfo, &pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportSemaphoreFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR> pImportSemaphoreFdInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreFdInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportSemaphoreFdKHR(call_info, return_value, device, &pImportSemaphoreFdInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSemaphoreFdKHR(call_info, return_value, device, &pGetFdInfo, &pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushDescriptorSetKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t set;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &set);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorWriteCount);
    bytes_read += pDescriptorWrites.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPushDescriptorSetKHR(call_info, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, &pDescriptorWrites);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorUpdateTemplateKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorUpdateTemplate.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorUpdateTemplateKHR(call_info, return_value, device, &pCreateInfo, &pAllocator, &pDescriptorUpdateTemplate);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorUpdateTemplateKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorUpdateTemplateKHR(call_info, device, descriptorUpdateTemplate, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRenderPass.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRenderPass2KHR(call_info, return_value, device, &pCreateInfo, &pAllocator, &pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSubpassBeginInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginRenderPass2KHR(call_info, commandBuffer, &pRenderPassBegin, &pSubpassBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassBeginInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSubpassEndInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdNextSubpass2KHR(call_info, commandBuffer, &pSubpassBeginInfo, &pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassEndInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderPass2KHR(call_info, commandBuffer, &pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainStatusKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSwapchainStatusKHR(call_info, return_value, device, swapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalFenceInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalFenceProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(call_info, physicalDevice, &pExternalFenceInfo, &pExternalFenceProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportFenceWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR> pImportFenceWin32HandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportFenceWin32HandleInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportFenceWin32HandleKHR(call_info, return_value, device, &pImportFenceWin32HandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetFenceWin32HandleKHR(call_info, return_value, device, &pGetWin32HandleInfo, &pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportFenceFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR> pImportFenceFdInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportFenceFdInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportFenceFdKHR(call_info, return_value, device, &pImportFenceFdInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetFenceFdKHR(call_info, return_value, device, &pGetFdInfo, &pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    PointerDecoder<uint32_t> pCounterCount;
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR> pCounters;
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR> pCounterDescriptions;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += pCounterCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCounters.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCounterDescriptions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(call_info, return_value, physicalDevice, queueFamilyIndex, &pCounterCount, &pCounters, &pCounterDescriptions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR> pPerformanceQueryCreateInfo;
    PointerDecoder<uint32_t> pNumPasses;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPerformanceQueryCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pNumPasses.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(call_info, physicalDevice, &pPerformanceQueryCreateInfo, &pNumPasses);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireProfilingLockKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireProfilingLockKHR(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleaseProfilingLockKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkReleaseProfilingLockKHR(call_info, device);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceCapabilities.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(call_info, return_value, physicalDevice, &pSurfaceInfo, &pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR> pSurfaceFormats;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceFormatCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceFormats2KHR(call_info, return_value, physicalDevice, &pSurfaceInfo, &pSurfaceFormatCount, &pSurfaceFormats);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayProperties2KHR(call_info, return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(call_info, return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayModeProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayModeProperties2KHR(call_info, return_value, physicalDevice, display, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneCapabilities2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR> pDisplayPlaneInfo;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR> pCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pDisplayPlaneInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCapabilities.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayPlaneCapabilities2KHR(call_info, return_value, physicalDevice, &pDisplayPlaneInfo, &pCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageMemoryRequirements2KHR(call_info, device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferMemoryRequirements2KHR(call_info, device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSparseMemoryRequirements2KHR(call_info, device, &pInfo, &pSparseMemoryRequirementCount, &pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSamplerYcbcrConversionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pYcbcrConversion.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSamplerYcbcrConversionKHR(call_info, return_value, device, &pCreateInfo, &pAllocator, &pYcbcrConversion);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySamplerYcbcrConversionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ycbcrConversion);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySamplerYcbcrConversionKHR(call_info, device, ycbcrConversion, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindBufferMemory2KHR(call_info, return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindImageMemory2KHR(call_info, return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSupport.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDescriptorSetLayoutSupportKHR(call_info, device, &pCreateInfo, &pSupport);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCountKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectCountKHR(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCountKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirectCountKHR(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreCounterValueKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId semaphore;
    PointerDecoder<uint64_t> pValue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += pValue.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSemaphoreCounterValueKHR(call_info, return_value, device, semaphore, &pValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWaitSemaphoresKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo> pWaitInfo;
    uint64_t timeout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pWaitInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkWaitSemaphoresKHR(call_info, return_value, device, &pWaitInfo, timeout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSignalSemaphoreKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo> pSignalInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pSignalInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSignalSemaphoreKHR(call_info, return_value, device, &pSignalInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFragmentShadingRatesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pFragmentShadingRateCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR> pFragmentShadingRates;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFragmentShadingRateCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFragmentShadingRates.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(call_info, return_value, physicalDevice, &pFragmentShadingRateCount, &pFragmentShadingRates);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetFragmentShadingRateKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkExtent2D> pFragmentSize;
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pFragmentSize.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += combinerOps.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetFragmentShadingRateKHR(call_info, commandBuffer, &pFragmentSize, &combinerOps);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetRenderingAttachmentLocationsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfoKHR> pLocationInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLocationInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetRenderingAttachmentLocationsKHR(call_info, commandBuffer, &pLocationInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetRenderingInputAttachmentIndicesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfoKHR> pLocationInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLocationInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetRenderingInputAttachmentIndicesKHR(call_info, commandBuffer, &pLocationInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWaitForPresentKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    uint64_t presentId;
    uint64_t timeout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &presentId);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkWaitForPresentKHR(call_info, return_value, device, swapchain, presentId, timeout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferDeviceAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferDeviceAddressKHR(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferOpaqueCaptureAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    uint64_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferOpaqueCaptureAddressKHR(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceMemoryOpaqueCaptureAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo> pInfo;
    uint64_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDeferredOperationKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDeferredOperationKHR> pDeferredOperation;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDeferredOperation.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDeferredOperationKHR(call_info, return_value, device, &pAllocator, &pDeferredOperation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDeferredOperationKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId operation;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &operation);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDeferredOperationKHR(call_info, device, operation, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeferredOperationMaxConcurrencyKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId operation;
    uint32_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &operation);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeferredOperationMaxConcurrencyKHR(call_info, return_value, device, operation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeferredOperationResultKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId operation;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &operation);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeferredOperationResultKHR(call_info, return_value, device, operation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineExecutablePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineInfoKHR> pPipelineInfo;
    PointerDecoder<uint32_t> pExecutableCount;
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pPipelineInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExecutableCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPipelineExecutablePropertiesKHR(call_info, return_value, device, &pPipelineInfo, &pExecutableCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineExecutableStatisticsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR> pExecutableInfo;
    PointerDecoder<uint32_t> pStatisticCount;
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR> pStatistics;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pExecutableInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pStatisticCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pStatistics.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPipelineExecutableStatisticsKHR(call_info, return_value, device, &pExecutableInfo, &pStatisticCount, &pStatistics);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineExecutableInternalRepresentationsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR> pExecutableInfo;
    PointerDecoder<uint32_t> pInternalRepresentationCount;
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR> pInternalRepresentations;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pExecutableInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInternalRepresentationCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInternalRepresentations.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPipelineExecutableInternalRepresentationsKHR(call_info, return_value, device, &pExecutableInfo, &pInternalRepresentationCount, &pInternalRepresentations);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMapMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryMapInfoKHR> pMemoryMapInfo;
    PointerDecoder<uint64_t, void*> ppData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pMemoryMapInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppData.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMapMemory2KHR(call_info, return_value, device, &pMemoryMapInfo, &ppData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUnmapMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryUnmapInfoKHR> pMemoryUnmapInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pMemoryUnmapInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUnmapMemory2KHR(call_info, return_value, device, &pMemoryUnmapInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR> pQualityLevelInfo;
    StructPointerDecoder<Decoded_VkVideoEncodeQualityLevelPropertiesKHR> pQualityLevelProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQualityLevelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQualityLevelProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(call_info, return_value, physicalDevice, &pQualityLevelInfo, &pQualityLevelProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetEncodedVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersGetInfoKHR> pVideoSessionParametersInfo;
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR> pFeedbackInfo;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pVideoSessionParametersInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFeedbackInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDataSize.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetEncodedVideoSessionParametersKHR(call_info, return_value, device, &pVideoSessionParametersInfo, &pFeedbackInfo, &pDataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEncodeVideoKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR> pEncodeInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pEncodeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEncodeVideoKHR(call_info, commandBuffer, &pEncodeInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetEvent2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += pDependencyInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetEvent2KHR(call_info, commandBuffer, event, &pDependencyInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetEvent2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags2 stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlags64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResetEvent2KHR(call_info, commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWaitEvents2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t eventCount;
    HandlePointerDecoder<VkEvent> pEvents;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfos;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &eventCount);
    bytes_read += pEvents.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDependencyInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWaitEvents2KHR(call_info, commandBuffer, eventCount, &pEvents, &pDependencyInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPipelineBarrier2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pDependencyInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPipelineBarrier2KHR(call_info, commandBuffer, &pDependencyInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteTimestamp2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlags2 stage;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlags64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stage);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteTimestamp2KHR(call_info, commandBuffer, stage, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueSubmit2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo2> pSubmits;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &submitCount);
    bytes_read += pSubmits.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueSubmit2KHR(call_info, return_value, queue, submitCount, &pSubmits, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteBufferMarker2AMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlags2 stage;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlags64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stage);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &marker);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteBufferMarker2AMD(call_info, commandBuffer, stage, dstBuffer, dstOffset, marker);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetQueueCheckpointData2NV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    PointerDecoder<uint32_t> pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointData2NV> pCheckpointData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pCheckpointDataCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCheckpointData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetQueueCheckpointData2NV(call_info, queue, &pCheckpointDataCount, &pCheckpointData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBuffer2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferInfo2> pCopyBufferInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyBufferInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyBuffer2KHR(call_info, commandBuffer, &pCopyBufferInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageInfo2> pCopyImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyImageInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyImage2KHR(call_info, commandBuffer, &pCopyImageInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBufferToImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2> pCopyBufferToImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyBufferToImageInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyBufferToImage2KHR(call_info, commandBuffer, &pCopyBufferToImageInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImageToBuffer2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2> pCopyImageToBufferInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyImageToBufferInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyImageToBuffer2KHR(call_info, commandBuffer, &pCopyImageToBufferInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBlitImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBlitImageInfo2> pBlitImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBlitImageInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBlitImage2KHR(call_info, commandBuffer, &pBlitImageInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResolveImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkResolveImageInfo2> pResolveImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pResolveImageInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResolveImage2KHR(call_info, commandBuffer, &pResolveImageInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdTraceRaysIndirect2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkDeviceAddress indirectDeviceAddress;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indirectDeviceAddress);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdTraceRaysIndirect2KHR(call_info, commandBuffer, indirectDeviceAddress);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceBufferMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceBufferMemoryRequirementsKHR(call_info, device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceImageMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceImageMemoryRequirementsKHR(call_info, device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceImageSparseMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceImageSparseMemoryRequirementsKHR(call_info, device, &pInfo, &pSparseMemoryRequirementCount, &pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindIndexBuffer2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkIndexType indexType;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indexType);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindIndexBuffer2KHR(call_info, commandBuffer, buffer, offset, size, indexType);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRenderingAreaGranularityKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderingAreaInfoKHR> pRenderingAreaInfo;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pRenderingAreaInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pGranularity.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRenderingAreaGranularityKHR(call_info, device, &pRenderingAreaInfo, &pGranularity);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceImageSubresourceLayoutKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfoKHR> pInfo;
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR> pLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pLayout.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceImageSubresourceLayoutKHR(call_info, device, &pInfo, &pLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSubresourceLayout2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource2KHR> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR> pLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pSubresource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pLayout.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSubresourceLayout2KHR(call_info, device, image, &pSubresource, &pLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(call_info, return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLineStippleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineStippleFactor);
    bytes_read += ValueDecoder::DecodeUInt16Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineStipplePattern);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetLineStippleKHR(call_info, commandBuffer, lineStippleFactor, lineStipplePattern);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pTimeDomainCount;
    PointerDecoder<VkTimeDomainKHR> pTimeDomains;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pTimeDomainCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTimeDomains.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(call_info, return_value, physicalDevice, &pTimeDomainCount, &pTimeDomains);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetCalibratedTimestampsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t timestampCount;
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR> pTimestampInfos;
    PointerDecoder<uint64_t> pTimestamps;
    PointerDecoder<uint64_t> pMaxDeviation;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timestampCount);
    bytes_read += pTimestampInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTimestamps.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMaxDeviation.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetCalibratedTimestampsKHR(call_info, return_value, device, timestampCount, &pTimestampInfos, &pTimestamps, &pMaxDeviation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindDescriptorSets2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfoKHR> pBindDescriptorSetsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBindDescriptorSetsInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindDescriptorSets2KHR(call_info, commandBuffer, &pBindDescriptorSetsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushConstants2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushConstantsInfoKHR> pPushConstantsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pPushConstantsInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPushConstants2KHR(call_info, commandBuffer, &pPushConstantsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushDescriptorSet2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfoKHR> pPushDescriptorSetInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pPushDescriptorSetInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPushDescriptorSet2KHR(call_info, commandBuffer, &pPushDescriptorSetInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushDescriptorSetWithTemplate2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetWithTemplateInfoKHR> pPushDescriptorSetWithTemplateInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pPushDescriptorSetWithTemplateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPushDescriptorSetWithTemplate2KHR(call_info, commandBuffer, &pPushDescriptorSetWithTemplateInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDescriptorBufferOffsets2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT> pSetDescriptorBufferOffsetsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSetDescriptorBufferOffsetsInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDescriptorBufferOffsets2EXT(call_info, commandBuffer, &pSetDescriptorBufferOffsetsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT> pBindDescriptorBufferEmbeddedSamplersInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBindDescriptorBufferEmbeddedSamplersInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(call_info, commandBuffer, &pBindDescriptorBufferEmbeddedSamplersInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFrameBoundaryANDROID(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId semaphore;
    format::HandleId image;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFrameBoundaryANDROID(call_info, device, semaphore, image);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDebugReportCallbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDebugReportCallbackEXT> pCallback;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCallback.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDebugReportCallbackEXT(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pCallback);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDebugReportCallbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId callback;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callback);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDebugReportCallbackEXT(call_info, instance, callback, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugReportMessageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    VkDebugReportFlagsEXT flags;
    VkDebugReportObjectTypeEXT objectType;
    uint64_t object;
    size_t location;
    int32_t messageCode;
    StringDecoder pLayerPrefix;
    StringDecoder pMessage;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectType);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &object);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &location);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messageCode);
    bytes_read += pLayerPrefix.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMessage.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDebugReportMessageEXT(call_info, instance, flags, objectType, object, location, messageCode, &pLayerPrefix, &pMessage);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugMarkerSetObjectTagEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT> pTagInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pTagInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDebugMarkerSetObjectTagEXT(call_info, return_value, device, &pTagInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugMarkerSetObjectNameEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT> pNameInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pNameInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDebugMarkerSetObjectNameEXT(call_info, return_value, device, &pNameInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerBeginEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerBeginEXT(call_info, commandBuffer, &pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerEndEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerEndEXT(call_info, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerInsertEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerInsertEXT(call_info, commandBuffer, &pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindTransformFeedbackBuffersEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;
    PointerDecoder<VkDeviceSize> pSizes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstBinding);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindingCount);
    bytes_read += pBuffers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pOffsets.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizes.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindTransformFeedbackBuffersEXT(call_info, commandBuffer, firstBinding, bindingCount, &pBuffers, &pOffsets, &pSizes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginTransformFeedbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstCounterBuffer;
    uint32_t counterBufferCount;
    HandlePointerDecoder<VkBuffer> pCounterBuffers;
    PointerDecoder<VkDeviceSize> pCounterBufferOffsets;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstCounterBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counterBufferCount);
    bytes_read += pCounterBuffers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCounterBufferOffsets.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginTransformFeedbackEXT(call_info, commandBuffer, firstCounterBuffer, counterBufferCount, &pCounterBuffers, &pCounterBufferOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndTransformFeedbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstCounterBuffer;
    uint32_t counterBufferCount;
    HandlePointerDecoder<VkBuffer> pCounterBuffers;
    PointerDecoder<VkDeviceSize> pCounterBufferOffsets;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstCounterBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counterBufferCount);
    bytes_read += pCounterBuffers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCounterBufferOffsets.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndTransformFeedbackEXT(call_info, commandBuffer, firstCounterBuffer, counterBufferCount, &pCounterBuffers, &pCounterBufferOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginQueryIndexedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    VkQueryControlFlags flags;
    uint32_t index;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &index);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginQueryIndexedEXT(call_info, commandBuffer, queryPool, query, flags, index);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndQueryIndexedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    uint32_t index;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &index);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndQueryIndexedEXT(call_info, commandBuffer, queryPool, query, index);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectByteCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t instanceCount;
    uint32_t firstInstance;
    format::HandleId counterBuffer;
    VkDeviceSize counterBufferOffset;
    uint32_t counterOffset;
    uint32_t vertexStride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstInstance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counterBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counterBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counterOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexStride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectByteCountEXT(call_info, commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageViewHandleNVX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX> pInfo;
    uint32_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageViewHandleNVX(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageViewAddressNVX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId imageView;
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageView);
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageViewAddressNVX(call_info, return_value, device, imageView, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCountAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectCountAMD(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCountAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirectCountAMD(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetShaderInfoAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    VkShaderStageFlagBits shaderStage;
    VkShaderInfoTypeAMD infoType;
    PointerDecoder<size_t> pInfoSize;
    PointerDecoder<uint8_t> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shaderStage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &infoType);
    bytes_read += pInfoSize.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInfo.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetShaderInfoAMD(call_info, return_value, device, pipeline, shaderStage, infoType, &pInfoSize, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateStreamDescriptorSurfaceGGP(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateStreamDescriptorSurfaceGGP(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    VkExternalMemoryHandleTypeFlagsNV externalHandleType;
    StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV> pExternalImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &tiling);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &externalHandleType);
    bytes_read += pExternalImageFormatProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(call_info, return_value, physicalDevice, format, type, tiling, usage, flags, externalHandleType, &pExternalImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandleNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    VkExternalMemoryHandleTypeFlagsNV handleType;
    PointerDecoder<uint64_t, void*> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handleType);
    bytes_read += pHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryWin32HandleNV(call_info, return_value, device, memory, handleType, &pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateViSurfaceNN(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateViSurfaceNN(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginConditionalRenderingEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT> pConditionalRenderingBegin;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pConditionalRenderingBegin.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginConditionalRenderingEXT(call_info, commandBuffer, &pConditionalRenderingBegin);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndConditionalRenderingEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndConditionalRenderingEXT(call_info, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportWScalingNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportWScalingNV> pViewportWScalings;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewportWScalings.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewportWScalingNV(call_info, commandBuffer, firstViewport, viewportCount, &pViewportWScalings);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleaseDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkReleaseDisplayEXT(call_info, return_value, physicalDevice, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireXlibDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint64_t dpy;
    format::HandleId display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dpy);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireXlibDisplayEXT(call_info, return_value, physicalDevice, dpy, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRandROutputDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint64_t dpy;
    size_t rrOutput;
    HandlePointerDecoder<VkDisplayKHR> pDisplay;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dpy);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rrOutput);
    bytes_read += pDisplay.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRandROutputDisplayEXT(call_info, return_value, physicalDevice, dpy, rrOutput, &pDisplay);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceCapabilities.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(call_info, return_value, physicalDevice, surface, &pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDisplayPowerControlEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT> pDisplayPowerInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pDisplayPowerInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDisplayPowerControlEXT(call_info, return_value, device, display, &pDisplayPowerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterDeviceEventEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT> pDeviceEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pDeviceEventInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFence.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkRegisterDeviceEventEXT(call_info, return_value, device, &pDeviceEventInfo, &pAllocator, &pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterDisplayEventEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT> pDisplayEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pDisplayEventInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFence.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkRegisterDisplayEventEXT(call_info, return_value, device, display, &pDisplayEventInfo, &pAllocator, &pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainCounterEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkSurfaceCounterFlagBitsEXT counter;
    PointerDecoder<uint64_t> pCounterValue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counter);
    bytes_read += pCounterValue.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSwapchainCounterEXT(call_info, return_value, device, swapchain, counter, &pCounterValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRefreshCycleDurationGOOGLE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE> pDisplayTimingProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pDisplayTimingProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRefreshCycleDurationGOOGLE(call_info, return_value, device, swapchain, &pDisplayTimingProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPastPresentationTimingGOOGLE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pPresentationTimingCount;
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE> pPresentationTimings;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pPresentationTimingCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPresentationTimings.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPastPresentationTimingGOOGLE(call_info, return_value, device, swapchain, &pPresentationTimingCount, &pPresentationTimings);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDiscardRectangleEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstDiscardRectangle;
    uint32_t discardRectangleCount;
    StructPointerDecoder<Decoded_VkRect2D> pDiscardRectangles;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstDiscardRectangle);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &discardRectangleCount);
    bytes_read += pDiscardRectangles.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDiscardRectangleEXT(call_info, commandBuffer, firstDiscardRectangle, discardRectangleCount, &pDiscardRectangles);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDiscardRectangleEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 discardRectangleEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &discardRectangleEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDiscardRectangleEnableEXT(call_info, commandBuffer, discardRectangleEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDiscardRectangleModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkDiscardRectangleModeEXT discardRectangleMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &discardRectangleMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDiscardRectangleModeEXT(call_info, commandBuffer, discardRectangleMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetHdrMetadataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t swapchainCount;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchains;
    StructPointerDecoder<Decoded_VkHdrMetadataEXT> pMetadata;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchainCount);
    bytes_read += pSwapchains.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMetadata.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetHdrMetadataEXT(call_info, device, swapchainCount, &pSwapchains, &pMetadata);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateIOSSurfaceMVK(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateIOSSurfaceMVK(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateMacOSSurfaceMVK(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateMacOSSurfaceMVK(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetDebugUtilsObjectNameEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT> pNameInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pNameInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetDebugUtilsObjectNameEXT(call_info, return_value, device, &pNameInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetDebugUtilsObjectTagEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT> pTagInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pTagInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetDebugUtilsObjectTagEXT(call_info, return_value, device, &pTagInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueBeginDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueBeginDebugUtilsLabelEXT(call_info, queue, &pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueEndDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueEndDebugUtilsLabelEXT(call_info, queue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueInsertDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueInsertDebugUtilsLabelEXT(call_info, queue, &pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginDebugUtilsLabelEXT(call_info, commandBuffer, &pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndDebugUtilsLabelEXT(call_info, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdInsertDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdInsertDebugUtilsLabelEXT(call_info, commandBuffer, &pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDebugUtilsMessengerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDebugUtilsMessengerEXT> pMessenger;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMessenger.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDebugUtilsMessengerEXT(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pMessenger);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDebugUtilsMessengerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId messenger;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messenger);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDebugUtilsMessengerEXT(call_info, instance, messenger, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSubmitDebugUtilsMessageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity;
    VkDebugUtilsMessageTypeFlagsEXT messageTypes;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT> pCallbackData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messageSeverity);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messageTypes);
    bytes_read += pCallbackData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSubmitDebugUtilsMessageEXT(call_info, instance, messageSeverity, messageTypes, &pCallbackData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAndroidHardwareBufferPropertiesANDROID(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint64_t buffer;
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAndroidHardwareBufferPropertiesANDROID(call_info, return_value, device, buffer, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryAndroidHardwareBufferANDROID(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID> pInfo;
    PointerDecoder<uint64_t, void*> pBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pBuffer.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryAndroidHardwareBufferANDROID(call_info, return_value, device, &pInfo, &pBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetSampleLocationsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT> pSampleLocationsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSampleLocationsInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetSampleLocationsEXT(call_info, commandBuffer, &pSampleLocationsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkSampleCountFlagBits samples;
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT> pMultisampleProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &samples);
    bytes_read += pMultisampleProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(call_info, physicalDevice, samples, &pMultisampleProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageDrmFormatModifierPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageDrmFormatModifierPropertiesEXT(call_info, return_value, device, image, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateValidationCacheEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkValidationCacheEXT> pValidationCache;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pValidationCache.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateValidationCacheEXT(call_info, return_value, device, &pCreateInfo, &pAllocator, &pValidationCache);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyValidationCacheEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId validationCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &validationCache);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyValidationCacheEXT(call_info, device, validationCache, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMergeValidationCachesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId dstCache;
    uint32_t srcCacheCount;
    HandlePointerDecoder<VkValidationCacheEXT> pSrcCaches;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcCacheCount);
    bytes_read += pSrcCaches.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMergeValidationCachesEXT(call_info, return_value, device, dstCache, srcCacheCount, &pSrcCaches);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetValidationCacheDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId validationCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &validationCache);
    bytes_read += pDataSize.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetValidationCacheDataEXT(call_info, return_value, device, validationCache, &pDataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindShadingRateImageNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId imageView;
    VkImageLayout imageLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageView);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageLayout);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindShadingRateImageNV(call_info, commandBuffer, imageView, imageLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportShadingRatePaletteNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV> pShadingRatePalettes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pShadingRatePalettes.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewportShadingRatePaletteNV(call_info, commandBuffer, firstViewport, viewportCount, &pShadingRatePalettes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCoarseSampleOrderNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCoarseSampleOrderTypeNV sampleOrderType;
    uint32_t customSampleOrderCount;
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV> pCustomSampleOrders;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sampleOrderType);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &customSampleOrderCount);
    bytes_read += pCustomSampleOrders.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCoarseSampleOrderNV(call_info, commandBuffer, sampleOrderType, customSampleOrderCount, &pCustomSampleOrders);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructure;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAccelerationStructure.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateAccelerationStructureNV(call_info, return_value, device, &pCreateInfo, &pAllocator, &pAccelerationStructure);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &accelerationStructure);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyAccelerationStructureNV(call_info, device, accelerationStructure, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureMemoryRequirementsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureMemoryRequirementsNV(call_info, device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindAccelerationStructureMemoryNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindAccelerationStructureMemoryNV(call_info, return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBuildAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV> pInfo;
    format::HandleId instanceData;
    VkDeviceSize instanceOffset;
    VkBool32 update;
    format::HandleId dst;
    format::HandleId src;
    format::HandleId scratch;
    VkDeviceSize scratchOffset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceData);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &update);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dst);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &src);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scratch);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scratchOffset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBuildAccelerationStructureNV(call_info, commandBuffer, &pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dst;
    format::HandleId src;
    VkCopyAccelerationStructureModeKHR mode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dst);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &src);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &mode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyAccelerationStructureNV(call_info, commandBuffer, dst, src, mode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdTraceRaysNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId raygenShaderBindingTableBuffer;
    VkDeviceSize raygenShaderBindingOffset;
    format::HandleId missShaderBindingTableBuffer;
    VkDeviceSize missShaderBindingOffset;
    VkDeviceSize missShaderBindingStride;
    format::HandleId hitShaderBindingTableBuffer;
    VkDeviceSize hitShaderBindingOffset;
    VkDeviceSize hitShaderBindingStride;
    format::HandleId callableShaderBindingTableBuffer;
    VkDeviceSize callableShaderBindingOffset;
    VkDeviceSize callableShaderBindingStride;
    uint32_t width;
    uint32_t height;
    uint32_t depth;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &raygenShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &raygenShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &missShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &missShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &missShaderBindingStride);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hitShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hitShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hitShaderBindingStride);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callableShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callableShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callableShaderBindingStride);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &width);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &height);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depth);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdTraceRaysNV(call_info, commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRayTracingPipelinesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipeline> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelines.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRayTracingPipelinesNV(call_info, return_value, device, pipelineCache, createInfoCount, &pCreateInfos, &pAllocator, &pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRayTracingShaderGroupHandlesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    uint32_t firstGroup;
    uint32_t groupCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstGroup);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCount);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRayTracingShaderGroupHandlesKHR(call_info, return_value, device, pipeline, firstGroup, groupCount, dataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRayTracingShaderGroupHandlesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    uint32_t firstGroup;
    uint32_t groupCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstGroup);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCount);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRayTracingShaderGroupHandlesNV(call_info, return_value, device, pipeline, firstGroup, groupCount, dataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureHandleNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId accelerationStructure;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &accelerationStructure);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureHandleNV(call_info, return_value, device, accelerationStructure, dataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteAccelerationStructuresPropertiesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t accelerationStructureCount;
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructures;
    VkQueryType queryType;
    format::HandleId queryPool;
    uint32_t firstQuery;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &accelerationStructureCount);
    bytes_read += pAccelerationStructures.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteAccelerationStructuresPropertiesNV(call_info, commandBuffer, accelerationStructureCount, &pAccelerationStructures, queryType, queryPool, firstQuery);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCompileDeferredNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    uint32_t shader;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shader);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCompileDeferredNV(call_info, return_value, device, pipeline, shader);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryHostPointerPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t pHostPointer;
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT> pMemoryHostPointerProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pHostPointer);
    bytes_read += pMemoryHostPointerProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryHostPointerPropertiesEXT(call_info, return_value, device, handleType, pHostPointer, &pMemoryHostPointerProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteBufferMarkerAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineStage);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &marker);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteBufferMarkerAMD(call_info, commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pTimeDomainCount;
    PointerDecoder<VkTimeDomainKHR> pTimeDomains;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pTimeDomainCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTimeDomains.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(call_info, return_value, physicalDevice, &pTimeDomainCount, &pTimeDomains);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetCalibratedTimestampsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t timestampCount;
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR> pTimestampInfos;
    PointerDecoder<uint64_t> pTimestamps;
    PointerDecoder<uint64_t> pMaxDeviation;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timestampCount);
    bytes_read += pTimestampInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTimestamps.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMaxDeviation.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetCalibratedTimestampsEXT(call_info, return_value, device, timestampCount, &pTimestampInfos, &pTimestamps, &pMaxDeviation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t taskCount;
    uint32_t firstTask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &taskCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstTask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksNV(call_info, commandBuffer, taskCount, firstTask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksIndirectNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksIndirectNV(call_info, commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksIndirectCountNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksIndirectCountNV(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetExclusiveScissorEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    PointerDecoder<VkBool32> pExclusiveScissorEnables;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstExclusiveScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &exclusiveScissorCount);
    bytes_read += pExclusiveScissorEnables.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetExclusiveScissorEnableNV(call_info, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, &pExclusiveScissorEnables);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetExclusiveScissorNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pExclusiveScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstExclusiveScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &exclusiveScissorCount);
    bytes_read += pExclusiveScissors.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetExclusiveScissorNV(call_info, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, &pExclusiveScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCheckpointNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint64_t pCheckpointMarker;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCheckpointMarker);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCheckpointNV(call_info, commandBuffer, pCheckpointMarker);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetQueueCheckpointDataNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    PointerDecoder<uint32_t> pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointDataNV> pCheckpointData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pCheckpointDataCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCheckpointData.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetQueueCheckpointDataNV(call_info, queue, &pCheckpointDataCount, &pCheckpointData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkInitializePerformanceApiINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL> pInitializeInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInitializeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkInitializePerformanceApiINTEL(call_info, return_value, device, &pInitializeInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUninitializePerformanceApiINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUninitializePerformanceApiINTEL(call_info, device);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPerformanceMarkerINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL> pMarkerInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetPerformanceMarkerINTEL(call_info, return_value, commandBuffer, &pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPerformanceStreamMarkerINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL> pMarkerInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetPerformanceStreamMarkerINTEL(call_info, return_value, commandBuffer, &pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPerformanceOverrideINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL> pOverrideInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pOverrideInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetPerformanceOverrideINTEL(call_info, return_value, commandBuffer, &pOverrideInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquirePerformanceConfigurationINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL> pAcquireInfo;
    HandlePointerDecoder<VkPerformanceConfigurationINTEL> pConfiguration;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAcquireInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pConfiguration.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquirePerformanceConfigurationINTEL(call_info, return_value, device, &pAcquireInfo, &pConfiguration);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleasePerformanceConfigurationINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId configuration;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &configuration);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkReleasePerformanceConfigurationINTEL(call_info, return_value, device, configuration);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueSetPerformanceConfigurationINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    format::HandleId configuration;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &configuration);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueSetPerformanceConfigurationINTEL(call_info, return_value, queue, configuration);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPerformanceParameterINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkPerformanceParameterTypeINTEL parameter;
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL> pValue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &parameter);
    bytes_read += pValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPerformanceParameterINTEL(call_info, return_value, device, parameter, &pValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetLocalDimmingAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapChain;
    VkBool32 localDimmingEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapChain);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &localDimmingEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetLocalDimmingAMD(call_info, device, swapChain, localDimmingEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImagePipeSurfaceFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateImagePipeSurfaceFUCHSIA(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateMetalSurfaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateMetalSurfaceEXT(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferDeviceAddressEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferDeviceAddressEXT(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceToolPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties> pToolProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pToolCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pToolProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceToolPropertiesEXT(call_info, return_value, physicalDevice, &pToolCount, &pToolProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(call_info, return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pCombinationCount;
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV> pCombinations;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pCombinationCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCombinations.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(call_info, return_value, physicalDevice, &pCombinationCount, &pCombinations);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfacePresentModes2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPresentModeCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPresentModes.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(call_info, return_value, physicalDevice, &pSurfaceInfo, &pPresentModeCount, &pPresentModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireFullScreenExclusiveModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireFullScreenExclusiveModeEXT(call_info, return_value, device, swapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleaseFullScreenExclusiveModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkReleaseFullScreenExclusiveModeEXT(call_info, return_value, device, swapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupSurfacePresentModes2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pSurfaceInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pModes.DecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupSurfacePresentModes2EXT(call_info, return_value, device, &pSurfaceInfo, &pModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateHeadlessSurfaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateHeadlessSurfaceEXT(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLineStippleEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineStippleFactor);
    bytes_read += ValueDecoder::DecodeUInt16Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineStipplePattern);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetLineStippleEXT(call_info, commandBuffer, lineStippleFactor, lineStipplePattern);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetQueryPoolEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryCount);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetQueryPoolEXT(call_info, device, queryPool, firstQuery, queryCount);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCullModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCullModeFlags cullMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &cullMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCullModeEXT(call_info, commandBuffer, cullMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetFrontFaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkFrontFace frontFace;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &frontFace);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetFrontFaceEXT(call_info, commandBuffer, frontFace);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPrimitiveTopologyEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPrimitiveTopology primitiveTopology;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &primitiveTopology);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetPrimitiveTopologyEXT(call_info, commandBuffer, primitiveTopology);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportWithCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewports.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewportWithCountEXT(call_info, commandBuffer, viewportCount, &pViewports);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetScissorWithCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scissorCount);
    bytes_read += pScissors.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetScissorWithCountEXT(call_info, commandBuffer, scissorCount, &pScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindVertexBuffers2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;
    PointerDecoder<VkDeviceSize> pSizes;
    PointerDecoder<VkDeviceSize> pStrides;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstBinding);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindingCount);
    bytes_read += pBuffers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pOffsets.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizes.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pStrides.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindVertexBuffers2EXT(call_info, commandBuffer, firstBinding, bindingCount, &pBuffers, &pOffsets, &pSizes, &pStrides);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthTestEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthTestEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthTestEnableEXT(call_info, commandBuffer, depthTestEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthWriteEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthWriteEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthWriteEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthWriteEnableEXT(call_info, commandBuffer, depthWriteEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthCompareOpEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCompareOp depthCompareOp;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthCompareOp);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthCompareOpEXT(call_info, commandBuffer, depthCompareOp);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBoundsTestEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthBoundsTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBoundsTestEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBoundsTestEnableEXT(call_info, commandBuffer, depthBoundsTestEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilTestEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 stencilTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stencilTestEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilTestEnableEXT(call_info, commandBuffer, stencilTestEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilOpEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    VkStencilOp failOp;
    VkStencilOp passOp;
    VkStencilOp depthFailOp;
    VkCompareOp compareOp;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &failOp);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &passOp);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthFailOp);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &compareOp);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilOpEXT(call_info, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyMemoryToImageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfoEXT> pCopyMemoryToImageInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCopyMemoryToImageInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyMemoryToImageEXT(call_info, return_value, device, &pCopyMemoryToImageInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyImageToMemoryEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfoEXT> pCopyImageToMemoryInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCopyImageToMemoryInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyImageToMemoryEXT(call_info, return_value, device, &pCopyImageToMemoryInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyImageToImageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToImageInfoEXT> pCopyImageToImageInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCopyImageToImageInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyImageToImageEXT(call_info, return_value, device, &pCopyImageToImageInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTransitionImageLayoutEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t transitionCount;
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfoEXT> pTransitions;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &transitionCount);
    bytes_read += pTransitions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkTransitionImageLayoutEXT(call_info, return_value, device, transitionCount, &pTransitions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSubresourceLayout2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource2KHR> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR> pLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pSubresource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pLayout.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSubresourceLayout2EXT(call_info, device, image, &pSubresource, &pLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleaseSwapchainImagesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT> pReleaseInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pReleaseInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkReleaseSwapchainImagesEXT(call_info, return_value, device, &pReleaseInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetGeneratedCommandsMemoryRequirementsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetGeneratedCommandsMemoryRequirementsNV(call_info, device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPreprocessGeneratedCommandsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pGeneratedCommandsInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPreprocessGeneratedCommandsNV(call_info, commandBuffer, &pGeneratedCommandsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdExecuteGeneratedCommandsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 isPreprocessed;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &isPreprocessed);
    bytes_read += pGeneratedCommandsInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdExecuteGeneratedCommandsNV(call_info, commandBuffer, isPreprocessed, &pGeneratedCommandsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindPipelineShaderGroupNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;
    uint32_t groupIndex;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupIndex);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindPipelineShaderGroupNV(call_info, commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateIndirectCommandsLayoutNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkIndirectCommandsLayoutNV> pIndirectCommandsLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pIndirectCommandsLayout.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateIndirectCommandsLayoutNV(call_info, return_value, device, &pCreateInfo, &pAllocator, &pIndirectCommandsLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyIndirectCommandsLayoutNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indirectCommandsLayout);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyIndirectCommandsLayoutNV(call_info, device, indirectCommandsLayout, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBias2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT> pDepthBiasInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pDepthBiasInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBias2EXT(call_info, commandBuffer, &pDepthBiasInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireDrmDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    int32_t drmFd;
    format::HandleId display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drmFd);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireDrmDisplayEXT(call_info, return_value, physicalDevice, drmFd, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDrmDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    int32_t drmFd;
    uint32_t connectorId;
    HandlePointerDecoder<VkDisplayKHR> display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drmFd);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &connectorId);
    bytes_read += display.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDrmDisplayEXT(call_info, return_value, physicalDevice, drmFd, connectorId, &display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePrivateDataSlotEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlot> pPrivateDataSlot;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPrivateDataSlot.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreatePrivateDataSlotEXT(call_info, return_value, device, &pCreateInfo, &pAllocator, &pPrivateDataSlot);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPrivateDataSlotEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId privateDataSlot;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &privateDataSlot);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPrivateDataSlotEXT(call_info, device, privateDataSlot, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetPrivateDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkObjectType objectType;
    uint64_t objectHandle;
    format::HandleId privateDataSlot;
    uint64_t data;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectType);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectHandle);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &privateDataSlot);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &data);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetPrivateDataEXT(call_info, return_value, device, objectType, objectHandle, privateDataSlot, data);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPrivateDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkObjectType objectType;
    uint64_t objectHandle;
    format::HandleId privateDataSlot;
    PointerDecoder<uint64_t> pData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectType);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectHandle);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &privateDataSlot);
    bytes_read += pData.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPrivateDataEXT(call_info, device, objectType, objectHandle, privateDataSlot, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetFragmentShadingRateEnumNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkFragmentShadingRateNV shadingRate;
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shadingRate);
    bytes_read += combinerOps.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetFragmentShadingRateEnumNV(call_info, commandBuffer, shadingRate, &combinerOps);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceFaultInfoEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT> pFaultCounts;
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT> pFaultInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pFaultCounts.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFaultInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceFaultInfoEXT(call_info, return_value, device, &pFaultCounts, &pFaultInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireWinrtDisplayNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireWinrtDisplayNV(call_info, return_value, physicalDevice, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetWinrtDisplayNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t deviceRelativeId;
    HandlePointerDecoder<VkDisplayKHR> pDisplay;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceRelativeId);
    bytes_read += pDisplay.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetWinrtDisplayNV(call_info, return_value, physicalDevice, deviceRelativeId, &pDisplay);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDirectFBSurfaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDirectFBSurfaceEXT(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t dfb;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dfb);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(call_info, return_value, physicalDevice, queueFamilyIndex, dfb);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetVertexInputEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t vertexBindingDescriptionCount;
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT> pVertexBindingDescriptions;
    uint32_t vertexAttributeDescriptionCount;
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT> pVertexAttributeDescriptions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexBindingDescriptionCount);
    bytes_read += pVertexBindingDescriptions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexAttributeDescriptionCount);
    bytes_read += pVertexAttributeDescriptions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetVertexInputEXT(call_info, commandBuffer, vertexBindingDescriptionCount, &pVertexBindingDescriptions, vertexAttributeDescriptionCount, &pVertexAttributeDescriptions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryZirconHandleFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA> pGetZirconHandleInfo;
    PointerDecoder<uint32_t> pZirconHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetZirconHandleInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pZirconHandle.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryZirconHandleFUCHSIA(call_info, return_value, device, &pGetZirconHandleInfo, &pZirconHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryZirconHandlePropertiesFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint32_t zirconHandle;
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA> pMemoryZirconHandleProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &zirconHandle);
    bytes_read += pMemoryZirconHandleProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(call_info, return_value, device, handleType, zirconHandle, &pMemoryZirconHandleProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportSemaphoreZirconHandleFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA> pImportSemaphoreZirconHandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreZirconHandleInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportSemaphoreZirconHandleFUCHSIA(call_info, return_value, device, &pImportSemaphoreZirconHandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreZirconHandleFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA> pGetZirconHandleInfo;
    PointerDecoder<uint32_t> pZirconHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetZirconHandleInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pZirconHandle.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSemaphoreZirconHandleFUCHSIA(call_info, return_value, device, &pGetZirconHandleInfo, &pZirconHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindInvocationMaskHUAWEI(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId imageView;
    VkImageLayout imageLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageView);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageLayout);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindInvocationMaskHUAWEI(call_info, commandBuffer, imageView, imageLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryRemoteAddressNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV> pMemoryGetRemoteAddressInfo;
    PointerDecoder<uint64_t, void*> pAddress;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pMemoryGetRemoteAddressInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAddress.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryRemoteAddressNV(call_info, return_value, device, &pMemoryGetRemoteAddressInfo, &pAddress);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPatchControlPointsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t patchControlPoints;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &patchControlPoints);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetPatchControlPointsEXT(call_info, commandBuffer, patchControlPoints);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetRasterizerDiscardEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 rasterizerDiscardEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rasterizerDiscardEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetRasterizerDiscardEnableEXT(call_info, commandBuffer, rasterizerDiscardEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBiasEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthBiasEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBiasEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBiasEnableEXT(call_info, commandBuffer, depthBiasEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLogicOpEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkLogicOp logicOp;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &logicOp);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetLogicOpEXT(call_info, commandBuffer, logicOp);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPrimitiveRestartEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 primitiveRestartEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &primitiveRestartEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetPrimitiveRestartEnableEXT(call_info, commandBuffer, primitiveRestartEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateScreenSurfaceQNX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateScreenSurfaceQNX(call_info, return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceScreenPresentationSupportQNX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t window;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &window);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(call_info, return_value, physicalDevice, queueFamilyIndex, window);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetColorWriteEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t attachmentCount;
    PointerDecoder<VkBool32> pColorWriteEnables;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pColorWriteEnables.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetColorWriteEnableEXT(call_info, commandBuffer, attachmentCount, &pColorWriteEnables);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMultiEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t drawCount;
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT> pVertexInfo;
    uint32_t instanceCount;
    uint32_t firstInstance;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += pVertexInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstInstance);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMultiEXT(call_info, commandBuffer, drawCount, &pVertexInfo, instanceCount, firstInstance, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMultiIndexedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t drawCount;
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT> pIndexInfo;
    uint32_t instanceCount;
    uint32_t firstInstance;
    uint32_t stride;
    PointerDecoder<int32_t> pVertexOffset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += pIndexInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstInstance);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += pVertexOffset.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMultiIndexedEXT(call_info, commandBuffer, drawCount, &pIndexInfo, instanceCount, firstInstance, stride, &pVertexOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkMicromapEXT> pMicromap;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMicromap.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateMicromapEXT(call_info, return_value, device, &pCreateInfo, &pAllocator, &pMicromap);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId micromap;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &micromap);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyMicromapEXT(call_info, device, micromap, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBuildMicromapsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pInfos;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &infoCount);
    bytes_read += pInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBuildMicromapsEXT(call_info, commandBuffer, infoCount, &pInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBuildMicromapsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &infoCount);
    bytes_read += pInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBuildMicromapsEXT(call_info, return_value, device, deferredOperation, infoCount, &pInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyMicromapEXT(call_info, return_value, device, deferredOperation, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyMicromapToMemoryEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyMicromapToMemoryEXT(call_info, return_value, device, deferredOperation, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyMemoryToMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyMemoryToMicromapEXT(call_info, return_value, device, deferredOperation, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWriteMicromapsPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t micromapCount;
    HandlePointerDecoder<VkMicromapEXT> pMicromaps;
    VkQueryType queryType;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    size_t stride;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &micromapCount);
    bytes_read += pMicromaps.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkWriteMicromapsPropertiesEXT(call_info, return_value, device, micromapCount, &pMicromaps, queryType, dataSize, &pData, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyMicromapEXT(call_info, commandBuffer, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyMicromapToMemoryEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyMicromapToMemoryEXT(call_info, commandBuffer, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyMemoryToMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyMemoryToMicromapEXT(call_info, commandBuffer, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteMicromapsPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t micromapCount;
    HandlePointerDecoder<VkMicromapEXT> pMicromaps;
    VkQueryType queryType;
    format::HandleId queryPool;
    uint32_t firstQuery;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &micromapCount);
    bytes_read += pMicromaps.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteMicromapsPropertiesEXT(call_info, commandBuffer, micromapCount, &pMicromaps, queryType, queryPool, firstQuery);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceMicromapCompatibilityEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT> pVersionInfo;
    PointerDecoder<VkAccelerationStructureCompatibilityKHR> pCompatibility;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pVersionInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCompatibility.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceMicromapCompatibilityEXT(call_info, device, &pVersionInfo, &pCompatibility);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMicromapBuildSizesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkAccelerationStructureBuildTypeKHR buildType;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pBuildInfo;
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT> pSizeInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buildType);
    bytes_read += pBuildInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMicromapBuildSizesEXT(call_info, device, buildType, &pBuildInfo, &pSizeInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawClusterHUAWEI(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawClusterHUAWEI(call_info, commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawClusterIndirectHUAWEI(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawClusterIndirectHUAWEI(call_info, commandBuffer, buffer, offset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetDeviceMemoryPriorityEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    float priority;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &priority);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetDeviceMemoryPriorityEXT(call_info, device, memory, priority);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutHostMappingInfoVALVE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE> pBindingReference;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE> pHostMapping;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pBindingReference.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHostMapping.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(call_info, device, &pBindingReference, &pHostMapping);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetHostMappingVALVE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorSet;
    PointerDecoder<uint64_t, void*> ppData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSet);
    bytes_read += ppData.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDescriptorSetHostMappingVALVE(call_info, device, descriptorSet, &ppData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineIndirectMemoryRequirementsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPipelineIndirectMemoryRequirementsNV(call_info, device, &pCreateInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdUpdatePipelineIndirectBufferNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdUpdatePipelineIndirectBufferNV(call_info, commandBuffer, pipelineBindPoint, pipeline);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineIndirectDeviceAddressNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPipelineIndirectDeviceAddressNV(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthClampEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthClampEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthClampEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthClampEnableEXT(call_info, commandBuffer, depthClampEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPolygonModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPolygonMode polygonMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &polygonMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetPolygonModeEXT(call_info, commandBuffer, polygonMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetRasterizationSamplesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkSampleCountFlagBits rasterizationSamples;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rasterizationSamples);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetRasterizationSamplesEXT(call_info, commandBuffer, rasterizationSamples);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetSampleMaskEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkSampleCountFlagBits samples;
    PointerDecoder<VkSampleMask> pSampleMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &samples);
    bytes_read += pSampleMask.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetSampleMaskEXT(call_info, commandBuffer, samples, &pSampleMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetAlphaToCoverageEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 alphaToCoverageEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &alphaToCoverageEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetAlphaToCoverageEnableEXT(call_info, commandBuffer, alphaToCoverageEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetAlphaToOneEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 alphaToOneEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &alphaToOneEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetAlphaToOneEnableEXT(call_info, commandBuffer, alphaToOneEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLogicOpEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 logicOpEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &logicOpEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetLogicOpEnableEXT(call_info, commandBuffer, logicOpEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetColorBlendEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    PointerDecoder<VkBool32> pColorBlendEnables;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstAttachment);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pColorBlendEnables.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetColorBlendEnableEXT(call_info, commandBuffer, firstAttachment, attachmentCount, &pColorBlendEnables);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetColorBlendEquationEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT> pColorBlendEquations;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstAttachment);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pColorBlendEquations.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetColorBlendEquationEXT(call_info, commandBuffer, firstAttachment, attachmentCount, &pColorBlendEquations);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetColorWriteMaskEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    PointerDecoder<VkColorComponentFlags> pColorWriteMasks;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstAttachment);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pColorWriteMasks.DecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetColorWriteMaskEXT(call_info, commandBuffer, firstAttachment, attachmentCount, &pColorWriteMasks);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetTessellationDomainOriginEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkTessellationDomainOrigin domainOrigin;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &domainOrigin);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetTessellationDomainOriginEXT(call_info, commandBuffer, domainOrigin);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetRasterizationStreamEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t rasterizationStream;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rasterizationStream);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetRasterizationStreamEXT(call_info, commandBuffer, rasterizationStream);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetConservativeRasterizationModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkConservativeRasterizationModeEXT conservativeRasterizationMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &conservativeRasterizationMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetConservativeRasterizationModeEXT(call_info, commandBuffer, conservativeRasterizationMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetExtraPrimitiveOverestimationSizeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float extraPrimitiveOverestimationSize;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &extraPrimitiveOverestimationSize);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(call_info, commandBuffer, extraPrimitiveOverestimationSize);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthClipEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthClipEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthClipEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthClipEnableEXT(call_info, commandBuffer, depthClipEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetSampleLocationsEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 sampleLocationsEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sampleLocationsEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetSampleLocationsEnableEXT(call_info, commandBuffer, sampleLocationsEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetColorBlendAdvancedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT> pColorBlendAdvanced;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstAttachment);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pColorBlendAdvanced.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetColorBlendAdvancedEXT(call_info, commandBuffer, firstAttachment, attachmentCount, &pColorBlendAdvanced);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetProvokingVertexModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkProvokingVertexModeEXT provokingVertexMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &provokingVertexMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetProvokingVertexModeEXT(call_info, commandBuffer, provokingVertexMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLineRasterizationModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkLineRasterizationModeEXT lineRasterizationMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineRasterizationMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetLineRasterizationModeEXT(call_info, commandBuffer, lineRasterizationMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLineStippleEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 stippledLineEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stippledLineEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetLineStippleEnableEXT(call_info, commandBuffer, stippledLineEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthClipNegativeOneToOneEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 negativeOneToOne;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &negativeOneToOne);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthClipNegativeOneToOneEXT(call_info, commandBuffer, negativeOneToOne);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportWScalingEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 viewportWScalingEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportWScalingEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewportWScalingEnableNV(call_info, commandBuffer, viewportWScalingEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportSwizzleNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportSwizzleNV> pViewportSwizzles;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewportSwizzles.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewportSwizzleNV(call_info, commandBuffer, firstViewport, viewportCount, &pViewportSwizzles);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCoverageToColorEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 coverageToColorEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageToColorEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCoverageToColorEnableNV(call_info, commandBuffer, coverageToColorEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCoverageToColorLocationNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t coverageToColorLocation;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageToColorLocation);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCoverageToColorLocationNV(call_info, commandBuffer, coverageToColorLocation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCoverageModulationModeNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCoverageModulationModeNV coverageModulationMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageModulationMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCoverageModulationModeNV(call_info, commandBuffer, coverageModulationMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCoverageModulationTableEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 coverageModulationTableEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageModulationTableEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCoverageModulationTableEnableNV(call_info, commandBuffer, coverageModulationTableEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCoverageModulationTableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t coverageModulationTableCount;
    PointerDecoder<float> pCoverageModulationTable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageModulationTableCount);
    bytes_read += pCoverageModulationTable.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCoverageModulationTableNV(call_info, commandBuffer, coverageModulationTableCount, &pCoverageModulationTable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetShadingRateImageEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 shadingRateImageEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shadingRateImageEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetShadingRateImageEnableNV(call_info, commandBuffer, shadingRateImageEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetRepresentativeFragmentTestEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 representativeFragmentTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &representativeFragmentTestEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetRepresentativeFragmentTestEnableNV(call_info, commandBuffer, representativeFragmentTestEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCoverageReductionModeNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCoverageReductionModeNV coverageReductionMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageReductionMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCoverageReductionModeNV(call_info, commandBuffer, coverageReductionMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetShaderModuleIdentifierEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId shaderModule;
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT> pIdentifier;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shaderModule);
    bytes_read += pIdentifier.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetShaderModuleIdentifierEXT(call_info, device, shaderModule, &pIdentifier);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetShaderModuleCreateInfoIdentifierEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT> pIdentifier;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pIdentifier.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetShaderModuleCreateInfoIdentifierEXT(call_info, device, &pCreateInfo, &pIdentifier);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV> pOpticalFlowImageFormatInfo;
    PointerDecoder<uint32_t> pFormatCount;
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pOpticalFlowImageFormatInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFormatCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(call_info, return_value, physicalDevice, &pOpticalFlowImageFormatInfo, &pFormatCount, &pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateOpticalFlowSessionNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkOpticalFlowSessionNV> pSession;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSession.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateOpticalFlowSessionNV(call_info, return_value, device, &pCreateInfo, &pAllocator, &pSession);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyOpticalFlowSessionNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyOpticalFlowSessionNV(call_info, device, session, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindOpticalFlowSessionImageNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId session;
    VkOpticalFlowSessionBindingPointNV bindingPoint;
    format::HandleId view;
    VkImageLayout layout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindingPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &view);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindOpticalFlowSessionImageNV(call_info, return_value, device, session, bindingPoint, view, layout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdOpticalFlowExecuteNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV> pExecuteInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += pExecuteInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdOpticalFlowExecuteNV(call_info, commandBuffer, session, &pExecuteInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateShadersEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkShaderCreateInfoEXT> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkShaderEXT> pShaders;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pShaders.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateShadersEXT(call_info, return_value, device, createInfoCount, &pCreateInfos, &pAllocator, &pShaders);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyShaderEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId shader;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shader);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyShaderEXT(call_info, device, shader, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetShaderBinaryDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId shader;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shader);
    bytes_read += pDataSize.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetShaderBinaryDataEXT(call_info, return_value, device, shader, &pDataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindShadersEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t stageCount;
    PointerDecoder<VkShaderStageFlagBits> pStages;
    HandlePointerDecoder<VkShaderEXT> pShaders;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageCount);
    bytes_read += pStages.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pShaders.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindShadersEXT(call_info, commandBuffer, stageCount, &pStages, &pShaders);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFramebufferTilePropertiesQCOM(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId framebuffer;
    PointerDecoder<uint32_t> pPropertiesCount;
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &framebuffer);
    bytes_read += pPropertiesCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetFramebufferTilePropertiesQCOM(call_info, return_value, device, framebuffer, &pPropertiesCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDynamicRenderingTilePropertiesQCOM(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pRenderingInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDynamicRenderingTilePropertiesQCOM(call_info, return_value, device, &pRenderingInfo, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetLatencySleepModeNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkLatencySleepModeInfoNV> pSleepModeInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pSleepModeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetLatencySleepModeNV(call_info, return_value, device, swapchain, &pSleepModeInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkLatencySleepNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkLatencySleepInfoNV> pSleepInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pSleepInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkLatencySleepNV(call_info, return_value, device, swapchain, &pSleepInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetLatencyMarkerNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkSetLatencyMarkerInfoNV> pLatencyMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pLatencyMarkerInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetLatencyMarkerNV(call_info, device, swapchain, &pLatencyMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetLatencyTimingsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkGetLatencyMarkerInfoNV> pLatencyMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pLatencyMarkerInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetLatencyTimingsNV(call_info, device, swapchain, &pLatencyMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueNotifyOutOfBandNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkOutOfBandQueueTypeInfoNV> pQueueTypeInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pQueueTypeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueNotifyOutOfBandNV(call_info, queue, &pQueueTypeInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetAttachmentFeedbackLoopEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkImageAspectFlags aspectMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &aspectMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(call_info, commandBuffer, aspectMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructure;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAccelerationStructure.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateAccelerationStructureKHR(call_info, return_value, device, &pCreateInfo, &pAllocator, &pAccelerationStructure);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &accelerationStructure);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyAccelerationStructureKHR(call_info, device, accelerationStructure, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBuildAccelerationStructuresKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*> ppBuildRangeInfos;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &infoCount);
    bytes_read += pInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppBuildRangeInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBuildAccelerationStructuresKHR(call_info, commandBuffer, infoCount, &pInfos, &ppBuildRangeInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBuildAccelerationStructuresIndirectKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    PointerDecoder<VkDeviceAddress> pIndirectDeviceAddresses;
    PointerDecoder<uint32_t> pIndirectStrides;
    PointerDecoder<uint32_t*> ppMaxPrimitiveCounts;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &infoCount);
    bytes_read += pInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pIndirectDeviceAddresses.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pIndirectStrides.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppMaxPrimitiveCounts.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBuildAccelerationStructuresIndirectKHR(call_info, commandBuffer, infoCount, &pInfos, &pIndirectDeviceAddresses, &pIndirectStrides, &ppMaxPrimitiveCounts);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyAccelerationStructureToMemoryKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyAccelerationStructureToMemoryKHR(call_info, return_value, device, deferredOperation, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyMemoryToAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyMemoryToAccelerationStructureKHR(call_info, return_value, device, deferredOperation, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWriteAccelerationStructuresPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t accelerationStructureCount;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructures;
    VkQueryType queryType;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    size_t stride;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &accelerationStructureCount);
    bytes_read += pAccelerationStructures.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkWriteAccelerationStructuresPropertiesKHR(call_info, return_value, device, accelerationStructureCount, &pAccelerationStructures, queryType, dataSize, &pData, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyAccelerationStructureKHR(call_info, commandBuffer, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyAccelerationStructureToMemoryKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyAccelerationStructureToMemoryKHR(call_info, commandBuffer, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyMemoryToAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyMemoryToAccelerationStructureKHR(call_info, commandBuffer, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureDeviceAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureDeviceAddressKHR(call_info, return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteAccelerationStructuresPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t accelerationStructureCount;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructures;
    VkQueryType queryType;
    format::HandleId queryPool;
    uint32_t firstQuery;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &accelerationStructureCount);
    bytes_read += pAccelerationStructures.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteAccelerationStructuresPropertiesKHR(call_info, commandBuffer, accelerationStructureCount, &pAccelerationStructures, queryType, queryPool, firstQuery);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceAccelerationStructureCompatibilityKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR> pVersionInfo;
    PointerDecoder<VkAccelerationStructureCompatibilityKHR> pCompatibility;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pVersionInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCompatibility.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceAccelerationStructureCompatibilityKHR(call_info, device, &pVersionInfo, &pCompatibility);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureBuildSizesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkAccelerationStructureBuildTypeKHR buildType;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pBuildInfo;
    PointerDecoder<uint32_t> pMaxPrimitiveCounts;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR> pSizeInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buildType);
    bytes_read += pBuildInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMaxPrimitiveCounts.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureBuildSizesKHR(call_info, device, buildType, &pBuildInfo, &pMaxPrimitiveCounts, &pSizeInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdTraceRaysKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pRaygenShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pMissShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pHitShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pCallableShaderBindingTable;
    uint32_t width;
    uint32_t height;
    uint32_t depth;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRaygenShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMissShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHitShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCallableShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &width);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &height);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depth);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdTraceRaysKHR(call_info, commandBuffer, &pRaygenShaderBindingTable, &pMissShaderBindingTable, &pHitShaderBindingTable, &pCallableShaderBindingTable, width, height, depth);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    uint32_t firstGroup;
    uint32_t groupCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstGroup);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCount);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(call_info, return_value, device, pipeline, firstGroup, groupCount, dataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdTraceRaysIndirectKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pRaygenShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pMissShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pHitShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pCallableShaderBindingTable;
    VkDeviceAddress indirectDeviceAddress;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRaygenShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMissShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHitShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCallableShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indirectDeviceAddress);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdTraceRaysIndirectKHR(call_info, commandBuffer, &pRaygenShaderBindingTable, &pMissShaderBindingTable, &pHitShaderBindingTable, &pCallableShaderBindingTable, indirectDeviceAddress);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRayTracingShaderGroupStackSizeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    uint32_t group;
    VkShaderGroupShaderKHR groupShader;
    VkDeviceSize return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &group);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupShader);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRayTracingShaderGroupStackSizeKHR(call_info, return_value, device, pipeline, group, groupShader);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetRayTracingPipelineStackSizeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t pipelineStackSize;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineStackSize);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetRayTracingPipelineStackSizeKHR(call_info, commandBuffer, pipelineStackSize);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksEXT(call_info, commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksIndirectEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksIndirectEXT(call_info, commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksIndirectCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksIndirectCountEXT(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

void VulkanDecoder::DecodeFunctionCall(format::ApiCallId             call_id,
                                       const ApiCallInfo&            call_info,
                                       const uint8_t*                parameter_buffer,
                                       size_t                        buffer_size)
{
    switch(call_id)
    {
    default:
        VulkanDecoderBase::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);
        break;

    case format::ApiCallId::ApiCall_vkCreateInstance:
        Decode_vkCreateInstance(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyInstance:
        Decode_vkDestroyInstance(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices:
        Decode_vkEnumeratePhysicalDevices(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures:
        Decode_vkGetPhysicalDeviceFeatures(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties:
        Decode_vkGetPhysicalDeviceFormatProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties:
        Decode_vkGetPhysicalDeviceImageFormatProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties:
        Decode_vkGetPhysicalDeviceProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties:
        Decode_vkGetPhysicalDeviceMemoryProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDevice:
        Decode_vkCreateDevice(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDevice:
        Decode_vkDestroyDevice(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceQueue:
        Decode_vkGetDeviceQueue(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueSubmit:
        Decode_vkQueueSubmit(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueWaitIdle:
        Decode_vkQueueWaitIdle(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDeviceWaitIdle:
        Decode_vkDeviceWaitIdle(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateMemory:
        Decode_vkAllocateMemory(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeMemory:
        Decode_vkFreeMemory(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMapMemory:
        Decode_vkMapMemory(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUnmapMemory:
        Decode_vkUnmapMemory(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges:
        Decode_vkFlushMappedMemoryRanges(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges:
        Decode_vkInvalidateMappedMemoryRanges(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment:
        Decode_vkGetDeviceMemoryCommitment(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory:
        Decode_vkBindBufferMemory(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory:
        Decode_vkBindImageMemory(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements:
        Decode_vkGetBufferMemoryRequirements(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements:
        Decode_vkGetImageMemoryRequirements(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements:
        Decode_vkGetImageSparseMemoryRequirements(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueBindSparse:
        Decode_vkQueueBindSparse(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateFence:
        Decode_vkCreateFence(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyFence:
        Decode_vkDestroyFence(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetFences:
        Decode_vkResetFences(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceStatus:
        Decode_vkGetFenceStatus(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWaitForFences:
        Decode_vkWaitForFences(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSemaphore:
        Decode_vkCreateSemaphore(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySemaphore:
        Decode_vkDestroySemaphore(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateEvent:
        Decode_vkCreateEvent(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyEvent:
        Decode_vkDestroyEvent(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetEventStatus:
        Decode_vkGetEventStatus(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetEvent:
        Decode_vkSetEvent(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetEvent:
        Decode_vkResetEvent(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateQueryPool:
        Decode_vkCreateQueryPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyQueryPool:
        Decode_vkDestroyQueryPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetQueryPoolResults:
        Decode_vkGetQueryPoolResults(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateBuffer:
        Decode_vkCreateBuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyBuffer:
        Decode_vkDestroyBuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateBufferView:
        Decode_vkCreateBufferView(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyBufferView:
        Decode_vkDestroyBufferView(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImage:
        Decode_vkCreateImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyImage:
        Decode_vkDestroyImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSubresourceLayout:
        Decode_vkGetImageSubresourceLayout(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImageView:
        Decode_vkCreateImageView(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyImageView:
        Decode_vkDestroyImageView(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateShaderModule:
        Decode_vkCreateShaderModule(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyShaderModule:
        Decode_vkDestroyShaderModule(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePipelineCache:
        Decode_vkCreatePipelineCache(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipelineCache:
        Decode_vkDestroyPipelineCache(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineCacheData:
        Decode_vkGetPipelineCacheData(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMergePipelineCaches:
        Decode_vkMergePipelineCaches(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateGraphicsPipelines:
        Decode_vkCreateGraphicsPipelines(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateComputePipelines:
        Decode_vkCreateComputePipelines(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipeline:
        Decode_vkDestroyPipeline(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePipelineLayout:
        Decode_vkCreatePipelineLayout(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipelineLayout:
        Decode_vkDestroyPipelineLayout(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSampler:
        Decode_vkCreateSampler(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySampler:
        Decode_vkDestroySampler(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout:
        Decode_vkCreateDescriptorSetLayout(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout:
        Decode_vkDestroyDescriptorSetLayout(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorPool:
        Decode_vkCreateDescriptorPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorPool:
        Decode_vkDestroyDescriptorPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetDescriptorPool:
        Decode_vkResetDescriptorPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateDescriptorSets:
        Decode_vkAllocateDescriptorSets(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeDescriptorSets:
        Decode_vkFreeDescriptorSets(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUpdateDescriptorSets:
        Decode_vkUpdateDescriptorSets(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateFramebuffer:
        Decode_vkCreateFramebuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyFramebuffer:
        Decode_vkDestroyFramebuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRenderPass:
        Decode_vkCreateRenderPass(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyRenderPass:
        Decode_vkDestroyRenderPass(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRenderAreaGranularity:
        Decode_vkGetRenderAreaGranularity(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateCommandPool:
        Decode_vkCreateCommandPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyCommandPool:
        Decode_vkDestroyCommandPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetCommandPool:
        Decode_vkResetCommandPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateCommandBuffers:
        Decode_vkAllocateCommandBuffers(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeCommandBuffers:
        Decode_vkFreeCommandBuffers(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBeginCommandBuffer:
        Decode_vkBeginCommandBuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEndCommandBuffer:
        Decode_vkEndCommandBuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetCommandBuffer:
        Decode_vkResetCommandBuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindPipeline:
        Decode_vkCmdBindPipeline(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewport:
        Decode_vkCmdSetViewport(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetScissor:
        Decode_vkCmdSetScissor(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLineWidth:
        Decode_vkCmdSetLineWidth(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBias:
        Decode_vkCmdSetDepthBias(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetBlendConstants:
        Decode_vkCmdSetBlendConstants(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBounds:
        Decode_vkCmdSetDepthBounds(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask:
        Decode_vkCmdSetStencilCompareMask(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask:
        Decode_vkCmdSetStencilWriteMask(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilReference:
        Decode_vkCmdSetStencilReference(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindDescriptorSets:
        Decode_vkCmdBindDescriptorSets(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindIndexBuffer:
        Decode_vkCmdBindIndexBuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindVertexBuffers:
        Decode_vkCmdBindVertexBuffers(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDraw:
        Decode_vkCmdDraw(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexed:
        Decode_vkCmdDrawIndexed(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirect:
        Decode_vkCmdDrawIndirect(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect:
        Decode_vkCmdDrawIndexedIndirect(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatch:
        Decode_vkCmdDispatch(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchIndirect:
        Decode_vkCmdDispatchIndirect(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBuffer:
        Decode_vkCmdCopyBuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImage:
        Decode_vkCmdCopyImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBlitImage:
        Decode_vkCmdBlitImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBufferToImage:
        Decode_vkCmdCopyBufferToImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer:
        Decode_vkCmdCopyImageToBuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdUpdateBuffer:
        Decode_vkCmdUpdateBuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdFillBuffer:
        Decode_vkCmdFillBuffer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearColorImage:
        Decode_vkCmdClearColorImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage:
        Decode_vkCmdClearDepthStencilImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearAttachments:
        Decode_vkCmdClearAttachments(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResolveImage:
        Decode_vkCmdResolveImage(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetEvent:
        Decode_vkCmdSetEvent(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResetEvent:
        Decode_vkCmdResetEvent(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWaitEvents:
        Decode_vkCmdWaitEvents(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPipelineBarrier:
        Decode_vkCmdPipelineBarrier(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginQuery:
        Decode_vkCmdBeginQuery(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndQuery:
        Decode_vkCmdEndQuery(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResetQueryPool:
        Decode_vkCmdResetQueryPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteTimestamp:
        Decode_vkCmdWriteTimestamp(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults:
        Decode_vkCmdCopyQueryPoolResults(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushConstants:
        Decode_vkCmdPushConstants(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderPass:
        Decode_vkCmdBeginRenderPass(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdNextSubpass:
        Decode_vkCmdNextSubpass(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderPass:
        Decode_vkCmdEndRenderPass(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdExecuteCommands:
        Decode_vkCmdExecuteCommands(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory2:
        Decode_vkBindBufferMemory2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory2:
        Decode_vkBindImageMemory2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures:
        Decode_vkGetDeviceGroupPeerMemoryFeatures(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDeviceMask:
        Decode_vkCmdSetDeviceMask(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchBase:
        Decode_vkCmdDispatchBase(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups:
        Decode_vkEnumeratePhysicalDeviceGroups(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2:
        Decode_vkGetImageMemoryRequirements2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2:
        Decode_vkGetBufferMemoryRequirements2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2:
        Decode_vkGetImageSparseMemoryRequirements2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2:
        Decode_vkGetPhysicalDeviceFeatures2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2:
        Decode_vkGetPhysicalDeviceProperties2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2:
        Decode_vkGetPhysicalDeviceFormatProperties2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2:
        Decode_vkGetPhysicalDeviceImageFormatProperties2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2:
        Decode_vkGetPhysicalDeviceMemoryProperties2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkTrimCommandPool:
        Decode_vkTrimCommandPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceQueue2:
        Decode_vkGetDeviceQueue2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion:
        Decode_vkCreateSamplerYcbcrConversion(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion:
        Decode_vkDestroySamplerYcbcrConversion(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate:
        Decode_vkCreateDescriptorUpdateTemplate(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate:
        Decode_vkDestroyDescriptorUpdateTemplate(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties:
        Decode_vkGetPhysicalDeviceExternalBufferProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties:
        Decode_vkGetPhysicalDeviceExternalFenceProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties:
        Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport:
        Decode_vkGetDescriptorSetLayoutSupport(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectCount:
        Decode_vkCmdDrawIndirectCount(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount:
        Decode_vkCmdDrawIndexedIndirectCount(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRenderPass2:
        Decode_vkCreateRenderPass2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderPass2:
        Decode_vkCmdBeginRenderPass2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdNextSubpass2:
        Decode_vkCmdNextSubpass2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderPass2:
        Decode_vkCmdEndRenderPass2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetQueryPool:
        Decode_vkResetQueryPool(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue:
        Decode_vkGetSemaphoreCounterValue(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWaitSemaphores:
        Decode_vkWaitSemaphores(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSignalSemaphore:
        Decode_vkSignalSemaphore(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferDeviceAddress:
        Decode_vkGetBufferDeviceAddress(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress:
        Decode_vkGetBufferOpaqueCaptureAddress(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress:
        Decode_vkGetDeviceMemoryOpaqueCaptureAddress(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties:
        Decode_vkGetPhysicalDeviceToolProperties(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePrivateDataSlot:
        Decode_vkCreatePrivateDataSlot(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot:
        Decode_vkDestroyPrivateDataSlot(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetPrivateData:
        Decode_vkSetPrivateData(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPrivateData:
        Decode_vkGetPrivateData(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetEvent2:
        Decode_vkCmdSetEvent2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResetEvent2:
        Decode_vkCmdResetEvent2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWaitEvents2:
        Decode_vkCmdWaitEvents2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPipelineBarrier2:
        Decode_vkCmdPipelineBarrier2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteTimestamp2:
        Decode_vkCmdWriteTimestamp2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueSubmit2:
        Decode_vkQueueSubmit2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBuffer2:
        Decode_vkCmdCopyBuffer2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImage2:
        Decode_vkCmdCopyImage2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2:
        Decode_vkCmdCopyBufferToImage2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2:
        Decode_vkCmdCopyImageToBuffer2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBlitImage2:
        Decode_vkCmdBlitImage2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResolveImage2:
        Decode_vkCmdResolveImage2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRendering:
        Decode_vkCmdBeginRendering(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRendering:
        Decode_vkCmdEndRendering(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCullMode:
        Decode_vkCmdSetCullMode(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetFrontFace:
        Decode_vkCmdSetFrontFace(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology:
        Decode_vkCmdSetPrimitiveTopology(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportWithCount:
        Decode_vkCmdSetViewportWithCount(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetScissorWithCount:
        Decode_vkCmdSetScissorWithCount(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2:
        Decode_vkCmdBindVertexBuffers2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable:
        Decode_vkCmdSetDepthTestEnable(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable:
        Decode_vkCmdSetDepthWriteEnable(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp:
        Decode_vkCmdSetDepthCompareOp(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable:
        Decode_vkCmdSetDepthBoundsTestEnable(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable:
        Decode_vkCmdSetStencilTestEnable(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilOp:
        Decode_vkCmdSetStencilOp(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable:
        Decode_vkCmdSetRasterizerDiscardEnable(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable:
        Decode_vkCmdSetDepthBiasEnable(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable:
        Decode_vkCmdSetPrimitiveRestartEnable(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements:
        Decode_vkGetDeviceBufferMemoryRequirements(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements:
        Decode_vkGetDeviceImageMemoryRequirements(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements:
        Decode_vkGetDeviceImageSparseMemoryRequirements(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySurfaceKHR:
        Decode_vkDestroySurfaceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR:
        Decode_vkGetPhysicalDeviceSurfaceSupportKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR:
        Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR:
        Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR:
        Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSwapchainKHR:
        Decode_vkCreateSwapchainKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySwapchainKHR:
        Decode_vkDestroySwapchainKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR:
        Decode_vkGetSwapchainImagesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireNextImageKHR:
        Decode_vkAcquireNextImageKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueuePresentKHR:
        Decode_vkQueuePresentKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR:
        Decode_vkGetDeviceGroupPresentCapabilitiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR:
        Decode_vkGetDeviceGroupSurfacePresentModesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR:
        Decode_vkGetPhysicalDevicePresentRectanglesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireNextImage2KHR:
        Decode_vkAcquireNextImage2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR:
        Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR:
        Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR:
        Decode_vkGetDisplayPlaneSupportedDisplaysKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR:
        Decode_vkGetDisplayModePropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDisplayModeKHR:
        Decode_vkCreateDisplayModeKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR:
        Decode_vkGetDisplayPlaneCapabilitiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR:
        Decode_vkCreateDisplayPlaneSurfaceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR:
        Decode_vkCreateSharedSwapchainsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR:
        Decode_vkCreateXlibSurfaceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR:
        Decode_vkCreateXcbSurfaceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR:
        Decode_vkCreateWaylandSurfaceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR:
        Decode_vkCreateAndroidSurfaceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR:
        Decode_vkCreateWin32SurfaceKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR:
        Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR:
        Decode_vkGetPhysicalDeviceVideoCapabilitiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR:
        Decode_vkGetPhysicalDeviceVideoFormatPropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateVideoSessionKHR:
        Decode_vkCreateVideoSessionKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR:
        Decode_vkDestroyVideoSessionKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR:
        Decode_vkGetVideoSessionMemoryRequirementsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR:
        Decode_vkBindVideoSessionMemoryKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR:
        Decode_vkCreateVideoSessionParametersKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR:
        Decode_vkUpdateVideoSessionParametersKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR:
        Decode_vkDestroyVideoSessionParametersKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR:
        Decode_vkCmdBeginVideoCodingKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR:
        Decode_vkCmdEndVideoCodingKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR:
        Decode_vkCmdControlVideoCodingKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR:
        Decode_vkCmdDecodeVideoKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR:
        Decode_vkCmdBeginRenderingKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderingKHR:
        Decode_vkCmdEndRenderingKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR:
        Decode_vkGetPhysicalDeviceFeatures2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR:
        Decode_vkGetPhysicalDeviceProperties2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceFormatProperties2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR:
        Decode_vkGetPhysicalDeviceMemoryProperties2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR:
        Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR:
        Decode_vkCmdSetDeviceMaskKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR:
        Decode_vkCmdDispatchBaseKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkTrimCommandPoolKHR:
        Decode_vkTrimCommandPoolKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR:
        Decode_vkEnumeratePhysicalDeviceGroupsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR:
        Decode_vkGetMemoryWin32HandleKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR:
        Decode_vkGetMemoryWin32HandlePropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryFdKHR:
        Decode_vkGetMemoryFdKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR:
        Decode_vkGetMemoryFdPropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR:
        Decode_vkImportSemaphoreWin32HandleKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR:
        Decode_vkGetSemaphoreWin32HandleKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR:
        Decode_vkImportSemaphoreFdKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR:
        Decode_vkGetSemaphoreFdKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR:
        Decode_vkCmdPushDescriptorSetKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR:
        Decode_vkCreateDescriptorUpdateTemplateKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR:
        Decode_vkDestroyDescriptorUpdateTemplateKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRenderPass2KHR:
        Decode_vkCreateRenderPass2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR:
        Decode_vkCmdBeginRenderPass2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR:
        Decode_vkCmdNextSubpass2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR:
        Decode_vkCmdEndRenderPass2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR:
        Decode_vkGetSwapchainStatusKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR:
        Decode_vkImportFenceWin32HandleKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR:
        Decode_vkGetFenceWin32HandleKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportFenceFdKHR:
        Decode_vkImportFenceFdKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceFdKHR:
        Decode_vkGetFenceFdKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR:
        Decode_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR:
        Decode_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR:
        Decode_vkAcquireProfilingLockKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR:
        Decode_vkReleaseProfilingLockKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR:
        Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR:
        Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR:
        Decode_vkGetPhysicalDeviceDisplayProperties2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR:
        Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR:
        Decode_vkGetDisplayModeProperties2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR:
        Decode_vkGetDisplayPlaneCapabilities2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR:
        Decode_vkGetImageMemoryRequirements2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR:
        Decode_vkGetBufferMemoryRequirements2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR:
        Decode_vkGetImageSparseMemoryRequirements2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR:
        Decode_vkCreateSamplerYcbcrConversionKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR:
        Decode_vkDestroySamplerYcbcrConversionKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory2KHR:
        Decode_vkBindBufferMemory2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory2KHR:
        Decode_vkBindImageMemory2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR:
        Decode_vkGetDescriptorSetLayoutSupportKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR:
        Decode_vkCmdDrawIndirectCountKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR:
        Decode_vkCmdDrawIndexedIndirectCountKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR:
        Decode_vkGetSemaphoreCounterValueKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWaitSemaphoresKHR:
        Decode_vkWaitSemaphoresKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSignalSemaphoreKHR:
        Decode_vkSignalSemaphoreKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR:
        Decode_vkGetPhysicalDeviceFragmentShadingRatesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR:
        Decode_vkCmdSetFragmentShadingRateKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetRenderingAttachmentLocationsKHR:
        Decode_vkCmdSetRenderingAttachmentLocationsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetRenderingInputAttachmentIndicesKHR:
        Decode_vkCmdSetRenderingInputAttachmentIndicesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWaitForPresentKHR:
        Decode_vkWaitForPresentKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR:
        Decode_vkGetBufferDeviceAddressKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR:
        Decode_vkGetBufferOpaqueCaptureAddressKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR:
        Decode_vkGetDeviceMemoryOpaqueCaptureAddressKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR:
        Decode_vkCreateDeferredOperationKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR:
        Decode_vkDestroyDeferredOperationKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR:
        Decode_vkGetDeferredOperationMaxConcurrencyKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR:
        Decode_vkGetDeferredOperationResultKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR:
        Decode_vkGetPipelineExecutablePropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR:
        Decode_vkGetPipelineExecutableStatisticsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR:
        Decode_vkGetPipelineExecutableInternalRepresentationsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMapMemory2KHR:
        Decode_vkMapMemory2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUnmapMemory2KHR:
        Decode_vkUnmapMemory2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR:
        Decode_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetEncodedVideoSessionParametersKHR:
        Decode_vkGetEncodedVideoSessionParametersKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR:
        Decode_vkCmdEncodeVideoKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetEvent2KHR:
        Decode_vkCmdSetEvent2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResetEvent2KHR:
        Decode_vkCmdResetEvent2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR:
        Decode_vkCmdWaitEvents2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR:
        Decode_vkCmdPipelineBarrier2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR:
        Decode_vkCmdWriteTimestamp2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueSubmit2KHR:
        Decode_vkQueueSubmit2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD:
        Decode_vkCmdWriteBufferMarker2AMD(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV:
        Decode_vkGetQueueCheckpointData2NV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR:
        Decode_vkCmdCopyBuffer2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImage2KHR:
        Decode_vkCmdCopyImage2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR:
        Decode_vkCmdCopyBufferToImage2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR:
        Decode_vkCmdCopyImageToBuffer2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBlitImage2KHR:
        Decode_vkCmdBlitImage2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResolveImage2KHR:
        Decode_vkCmdResolveImage2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR:
        Decode_vkCmdTraceRaysIndirect2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR:
        Decode_vkGetDeviceBufferMemoryRequirementsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR:
        Decode_vkGetDeviceImageMemoryRequirementsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR:
        Decode_vkGetDeviceImageSparseMemoryRequirementsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindIndexBuffer2KHR:
        Decode_vkCmdBindIndexBuffer2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRenderingAreaGranularityKHR:
        Decode_vkGetRenderingAreaGranularityKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceImageSubresourceLayoutKHR:
        Decode_vkGetDeviceImageSubresourceLayoutKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2KHR:
        Decode_vkGetImageSubresourceLayout2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR:
        Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLineStippleKHR:
        Decode_vkCmdSetLineStippleKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR:
        Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetCalibratedTimestampsKHR:
        Decode_vkGetCalibratedTimestampsKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindDescriptorSets2KHR:
        Decode_vkCmdBindDescriptorSets2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushConstants2KHR:
        Decode_vkCmdPushConstants2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushDescriptorSet2KHR:
        Decode_vkCmdPushDescriptorSet2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplate2KHR:
        Decode_vkCmdPushDescriptorSetWithTemplate2KHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDescriptorBufferOffsets2EXT:
        Decode_vkCmdSetDescriptorBufferOffsets2EXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT:
        Decode_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFrameBoundaryANDROID:
        Decode_vkFrameBoundaryANDROID(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT:
        Decode_vkCreateDebugReportCallbackEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT:
        Decode_vkDestroyDebugReportCallbackEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugReportMessageEXT:
        Decode_vkDebugReportMessageEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT:
        Decode_vkDebugMarkerSetObjectTagEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT:
        Decode_vkDebugMarkerSetObjectNameEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT:
        Decode_vkCmdDebugMarkerBeginEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT:
        Decode_vkCmdDebugMarkerEndEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT:
        Decode_vkCmdDebugMarkerInsertEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT:
        Decode_vkCmdBindTransformFeedbackBuffersEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT:
        Decode_vkCmdBeginTransformFeedbackEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT:
        Decode_vkCmdEndTransformFeedbackEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT:
        Decode_vkCmdBeginQueryIndexedEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT:
        Decode_vkCmdEndQueryIndexedEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT:
        Decode_vkCmdDrawIndirectByteCountEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageViewHandleNVX:
        Decode_vkGetImageViewHandleNVX(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageViewAddressNVX:
        Decode_vkGetImageViewAddressNVX(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD:
        Decode_vkCmdDrawIndirectCountAMD(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD:
        Decode_vkCmdDrawIndexedIndirectCountAMD(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetShaderInfoAMD:
        Decode_vkGetShaderInfoAMD(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP:
        Decode_vkCreateStreamDescriptorSurfaceGGP(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV:
        Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV:
        Decode_vkGetMemoryWin32HandleNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateViSurfaceNN:
        Decode_vkCreateViSurfaceNN(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT:
        Decode_vkCmdBeginConditionalRenderingEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT:
        Decode_vkCmdEndConditionalRenderingEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV:
        Decode_vkCmdSetViewportWScalingNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleaseDisplayEXT:
        Decode_vkReleaseDisplayEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT:
        Decode_vkAcquireXlibDisplayEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT:
        Decode_vkGetRandROutputDisplayEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT:
        Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDisplayPowerControlEXT:
        Decode_vkDisplayPowerControlEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT:
        Decode_vkRegisterDeviceEventEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT:
        Decode_vkRegisterDisplayEventEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT:
        Decode_vkGetSwapchainCounterEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE:
        Decode_vkGetRefreshCycleDurationGOOGLE(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE:
        Decode_vkGetPastPresentationTimingGOOGLE(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT:
        Decode_vkCmdSetDiscardRectangleEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT:
        Decode_vkCmdSetDiscardRectangleEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT:
        Decode_vkCmdSetDiscardRectangleModeEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetHdrMetadataEXT:
        Decode_vkSetHdrMetadataEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK:
        Decode_vkCreateIOSSurfaceMVK(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK:
        Decode_vkCreateMacOSSurfaceMVK(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT:
        Decode_vkSetDebugUtilsObjectNameEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT:
        Decode_vkSetDebugUtilsObjectTagEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT:
        Decode_vkQueueBeginDebugUtilsLabelEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT:
        Decode_vkQueueEndDebugUtilsLabelEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT:
        Decode_vkQueueInsertDebugUtilsLabelEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT:
        Decode_vkCmdBeginDebugUtilsLabelEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT:
        Decode_vkCmdEndDebugUtilsLabelEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT:
        Decode_vkCmdInsertDebugUtilsLabelEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT:
        Decode_vkCreateDebugUtilsMessengerEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT:
        Decode_vkDestroyDebugUtilsMessengerEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT:
        Decode_vkSubmitDebugUtilsMessageEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID:
        Decode_vkGetAndroidHardwareBufferPropertiesANDROID(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID:
        Decode_vkGetMemoryAndroidHardwareBufferANDROID(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT:
        Decode_vkCmdSetSampleLocationsEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT:
        Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT:
        Decode_vkGetImageDrmFormatModifierPropertiesEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateValidationCacheEXT:
        Decode_vkCreateValidationCacheEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT:
        Decode_vkDestroyValidationCacheEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMergeValidationCachesEXT:
        Decode_vkMergeValidationCachesEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT:
        Decode_vkGetValidationCacheDataEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV:
        Decode_vkCmdBindShadingRateImageNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV:
        Decode_vkCmdSetViewportShadingRatePaletteNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV:
        Decode_vkCmdSetCoarseSampleOrderNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV:
        Decode_vkCreateAccelerationStructureNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV:
        Decode_vkDestroyAccelerationStructureNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV:
        Decode_vkGetAccelerationStructureMemoryRequirementsNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV:
        Decode_vkBindAccelerationStructureMemoryNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV:
        Decode_vkCmdBuildAccelerationStructureNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV:
        Decode_vkCmdCopyAccelerationStructureNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdTraceRaysNV:
        Decode_vkCmdTraceRaysNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV:
        Decode_vkCreateRayTracingPipelinesNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR:
        Decode_vkGetRayTracingShaderGroupHandlesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV:
        Decode_vkGetRayTracingShaderGroupHandlesNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV:
        Decode_vkGetAccelerationStructureHandleNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV:
        Decode_vkCmdWriteAccelerationStructuresPropertiesNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCompileDeferredNV:
        Decode_vkCompileDeferredNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT:
        Decode_vkGetMemoryHostPointerPropertiesEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD:
        Decode_vkCmdWriteBufferMarkerAMD(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT:
        Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT:
        Decode_vkGetCalibratedTimestampsEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV:
        Decode_vkCmdDrawMeshTasksNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV:
        Decode_vkCmdDrawMeshTasksIndirectNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV:
        Decode_vkCmdDrawMeshTasksIndirectCountNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV:
        Decode_vkCmdSetExclusiveScissorEnableNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV:
        Decode_vkCmdSetExclusiveScissorNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCheckpointNV:
        Decode_vkCmdSetCheckpointNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV:
        Decode_vkGetQueueCheckpointDataNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL:
        Decode_vkInitializePerformanceApiINTEL(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL:
        Decode_vkUninitializePerformanceApiINTEL(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL:
        Decode_vkCmdSetPerformanceMarkerINTEL(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL:
        Decode_vkCmdSetPerformanceStreamMarkerINTEL(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL:
        Decode_vkCmdSetPerformanceOverrideINTEL(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL:
        Decode_vkAcquirePerformanceConfigurationINTEL(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL:
        Decode_vkReleasePerformanceConfigurationINTEL(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL:
        Decode_vkQueueSetPerformanceConfigurationINTEL(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL:
        Decode_vkGetPerformanceParameterINTEL(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetLocalDimmingAMD:
        Decode_vkSetLocalDimmingAMD(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA:
        Decode_vkCreateImagePipeSurfaceFUCHSIA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT:
        Decode_vkCreateMetalSurfaceEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT:
        Decode_vkGetBufferDeviceAddressEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT:
        Decode_vkGetPhysicalDeviceToolPropertiesEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV:
        Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV:
        Decode_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT:
        Decode_vkGetPhysicalDeviceSurfacePresentModes2EXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT:
        Decode_vkAcquireFullScreenExclusiveModeEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT:
        Decode_vkReleaseFullScreenExclusiveModeEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT:
        Decode_vkGetDeviceGroupSurfacePresentModes2EXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT:
        Decode_vkCreateHeadlessSurfaceEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT:
        Decode_vkCmdSetLineStippleEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetQueryPoolEXT:
        Decode_vkResetQueryPoolEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCullModeEXT:
        Decode_vkCmdSetCullModeEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT:
        Decode_vkCmdSetFrontFaceEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT:
        Decode_vkCmdSetPrimitiveTopologyEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT:
        Decode_vkCmdSetViewportWithCountEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT:
        Decode_vkCmdSetScissorWithCountEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT:
        Decode_vkCmdBindVertexBuffers2EXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT:
        Decode_vkCmdSetDepthTestEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT:
        Decode_vkCmdSetDepthWriteEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT:
        Decode_vkCmdSetDepthCompareOpEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT:
        Decode_vkCmdSetDepthBoundsTestEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT:
        Decode_vkCmdSetStencilTestEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT:
        Decode_vkCmdSetStencilOpEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyMemoryToImageEXT:
        Decode_vkCopyMemoryToImageEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyImageToMemoryEXT:
        Decode_vkCopyImageToMemoryEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyImageToImageEXT:
        Decode_vkCopyImageToImageEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkTransitionImageLayoutEXT:
        Decode_vkTransitionImageLayoutEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT:
        Decode_vkGetImageSubresourceLayout2EXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT:
        Decode_vkReleaseSwapchainImagesEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV:
        Decode_vkGetGeneratedCommandsMemoryRequirementsNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV:
        Decode_vkCmdPreprocessGeneratedCommandsNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV:
        Decode_vkCmdExecuteGeneratedCommandsNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV:
        Decode_vkCmdBindPipelineShaderGroupNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV:
        Decode_vkCreateIndirectCommandsLayoutNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV:
        Decode_vkDestroyIndirectCommandsLayoutNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBias2EXT:
        Decode_vkCmdSetDepthBias2EXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT:
        Decode_vkAcquireDrmDisplayEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDrmDisplayEXT:
        Decode_vkGetDrmDisplayEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT:
        Decode_vkCreatePrivateDataSlotEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT:
        Decode_vkDestroyPrivateDataSlotEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetPrivateDataEXT:
        Decode_vkSetPrivateDataEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPrivateDataEXT:
        Decode_vkGetPrivateDataEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV:
        Decode_vkCmdSetFragmentShadingRateEnumNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT:
        Decode_vkGetDeviceFaultInfoEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV:
        Decode_vkAcquireWinrtDisplayNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetWinrtDisplayNV:
        Decode_vkGetWinrtDisplayNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT:
        Decode_vkCreateDirectFBSurfaceEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT:
        Decode_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT:
        Decode_vkCmdSetVertexInputEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA:
        Decode_vkGetMemoryZirconHandleFUCHSIA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA:
        Decode_vkGetMemoryZirconHandlePropertiesFUCHSIA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA:
        Decode_vkImportSemaphoreZirconHandleFUCHSIA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA:
        Decode_vkGetSemaphoreZirconHandleFUCHSIA(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI:
        Decode_vkCmdBindInvocationMaskHUAWEI(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV:
        Decode_vkGetMemoryRemoteAddressNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT:
        Decode_vkCmdSetPatchControlPointsEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT:
        Decode_vkCmdSetRasterizerDiscardEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT:
        Decode_vkCmdSetDepthBiasEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT:
        Decode_vkCmdSetLogicOpEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT:
        Decode_vkCmdSetPrimitiveRestartEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX:
        Decode_vkCreateScreenSurfaceQNX(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX:
        Decode_vkGetPhysicalDeviceScreenPresentationSupportQNX(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT:
        Decode_vkCmdSetColorWriteEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMultiEXT:
        Decode_vkCmdDrawMultiEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT:
        Decode_vkCmdDrawMultiIndexedEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateMicromapEXT:
        Decode_vkCreateMicromapEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyMicromapEXT:
        Decode_vkDestroyMicromapEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT:
        Decode_vkCmdBuildMicromapsEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBuildMicromapsEXT:
        Decode_vkBuildMicromapsEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyMicromapEXT:
        Decode_vkCopyMicromapEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT:
        Decode_vkCopyMicromapToMemoryEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT:
        Decode_vkCopyMemoryToMicromapEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT:
        Decode_vkWriteMicromapsPropertiesEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT:
        Decode_vkCmdCopyMicromapEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT:
        Decode_vkCmdCopyMicromapToMemoryEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT:
        Decode_vkCmdCopyMemoryToMicromapEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT:
        Decode_vkCmdWriteMicromapsPropertiesEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT:
        Decode_vkGetDeviceMicromapCompatibilityEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT:
        Decode_vkGetMicromapBuildSizesEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI:
        Decode_vkCmdDrawClusterHUAWEI(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI:
        Decode_vkCmdDrawClusterIndirectHUAWEI(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT:
        Decode_vkSetDeviceMemoryPriorityEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE:
        Decode_vkGetDescriptorSetLayoutHostMappingInfoVALVE(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE:
        Decode_vkGetDescriptorSetHostMappingVALVE(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineIndirectMemoryRequirementsNV:
        Decode_vkGetPipelineIndirectMemoryRequirementsNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdUpdatePipelineIndirectBufferNV:
        Decode_vkCmdUpdatePipelineIndirectBufferNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineIndirectDeviceAddressNV:
        Decode_vkGetPipelineIndirectDeviceAddressNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT:
        Decode_vkCmdSetDepthClampEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT:
        Decode_vkCmdSetPolygonModeEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT:
        Decode_vkCmdSetRasterizationSamplesEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT:
        Decode_vkCmdSetSampleMaskEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT:
        Decode_vkCmdSetAlphaToCoverageEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT:
        Decode_vkCmdSetAlphaToOneEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT:
        Decode_vkCmdSetLogicOpEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT:
        Decode_vkCmdSetColorBlendEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT:
        Decode_vkCmdSetColorBlendEquationEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT:
        Decode_vkCmdSetColorWriteMaskEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT:
        Decode_vkCmdSetTessellationDomainOriginEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT:
        Decode_vkCmdSetRasterizationStreamEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT:
        Decode_vkCmdSetConservativeRasterizationModeEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT:
        Decode_vkCmdSetExtraPrimitiveOverestimationSizeEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT:
        Decode_vkCmdSetDepthClipEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT:
        Decode_vkCmdSetSampleLocationsEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT:
        Decode_vkCmdSetColorBlendAdvancedEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT:
        Decode_vkCmdSetProvokingVertexModeEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT:
        Decode_vkCmdSetLineRasterizationModeEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT:
        Decode_vkCmdSetLineStippleEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT:
        Decode_vkCmdSetDepthClipNegativeOneToOneEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV:
        Decode_vkCmdSetViewportWScalingEnableNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV:
        Decode_vkCmdSetViewportSwizzleNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV:
        Decode_vkCmdSetCoverageToColorEnableNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV:
        Decode_vkCmdSetCoverageToColorLocationNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV:
        Decode_vkCmdSetCoverageModulationModeNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV:
        Decode_vkCmdSetCoverageModulationTableEnableNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV:
        Decode_vkCmdSetCoverageModulationTableNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV:
        Decode_vkCmdSetShadingRateImageEnableNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV:
        Decode_vkCmdSetRepresentativeFragmentTestEnableNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV:
        Decode_vkCmdSetCoverageReductionModeNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT:
        Decode_vkGetShaderModuleIdentifierEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT:
        Decode_vkGetShaderModuleCreateInfoIdentifierEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV:
        Decode_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV:
        Decode_vkCreateOpticalFlowSessionNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV:
        Decode_vkDestroyOpticalFlowSessionNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV:
        Decode_vkBindOpticalFlowSessionImageNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV:
        Decode_vkCmdOpticalFlowExecuteNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateShadersEXT:
        Decode_vkCreateShadersEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyShaderEXT:
        Decode_vkDestroyShaderEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetShaderBinaryDataEXT:
        Decode_vkGetShaderBinaryDataEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindShadersEXT:
        Decode_vkCmdBindShadersEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM:
        Decode_vkGetFramebufferTilePropertiesQCOM(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM:
        Decode_vkGetDynamicRenderingTilePropertiesQCOM(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetLatencySleepModeNV:
        Decode_vkSetLatencySleepModeNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkLatencySleepNV:
        Decode_vkLatencySleepNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetLatencyMarkerNV:
        Decode_vkSetLatencyMarkerNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetLatencyTimingsNV:
        Decode_vkGetLatencyTimingsNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueNotifyOutOfBandNV:
        Decode_vkQueueNotifyOutOfBandNV(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetAttachmentFeedbackLoopEnableEXT:
        Decode_vkCmdSetAttachmentFeedbackLoopEnableEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR:
        Decode_vkCreateAccelerationStructureKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR:
        Decode_vkDestroyAccelerationStructureKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR:
        Decode_vkCmdBuildAccelerationStructuresKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR:
        Decode_vkCmdBuildAccelerationStructuresIndirectKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR:
        Decode_vkCopyAccelerationStructureToMemoryKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR:
        Decode_vkCopyMemoryToAccelerationStructureKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR:
        Decode_vkWriteAccelerationStructuresPropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR:
        Decode_vkCmdCopyAccelerationStructureKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR:
        Decode_vkCmdCopyAccelerationStructureToMemoryKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR:
        Decode_vkCmdCopyMemoryToAccelerationStructureKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR:
        Decode_vkGetAccelerationStructureDeviceAddressKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR:
        Decode_vkCmdWriteAccelerationStructuresPropertiesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR:
        Decode_vkGetDeviceAccelerationStructureCompatibilityKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR:
        Decode_vkGetAccelerationStructureBuildSizesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdTraceRaysKHR:
        Decode_vkCmdTraceRaysKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR:
        Decode_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR:
        Decode_vkCmdTraceRaysIndirectKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR:
        Decode_vkGetRayTracingShaderGroupStackSizeKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR:
        Decode_vkCmdSetRayTracingPipelineStackSizeKHR(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT:
        Decode_vkCmdDrawMeshTasksEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT:
        Decode_vkCmdDrawMeshTasksIndirectEXT(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT:
        Decode_vkCmdDrawMeshTasksIndirectCountEXT(call_info, parameter_buffer, buffer_size);
        break;
    }
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
