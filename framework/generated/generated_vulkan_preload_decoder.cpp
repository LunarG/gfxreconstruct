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
#include "generated/generated_vulkan_struct_packet.h"
#include "generated/generated_vulkan_preload_decoder.h"
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

size_t VulkanPreloadDecoder::Decode_vkCreateInstance(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_VkInstanceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkInstance> pInstance;
    VkResult return_value;

    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInstance.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateInstance* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateInstance>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateInstance;
    packet->call_info = call_info;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pInstance = pInstance;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyInstance(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyInstance* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyInstance>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyInstance;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkEnumeratePhysicalDevices(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceCount;
    HandlePointerDecoder<VkPhysicalDevice> pPhysicalDevices;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPhysicalDevices.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkEnumeratePhysicalDevices* packet = PreloadDecodeAllocator::Allocate<Packet_vkEnumeratePhysicalDevices>();
    packet->packet_id = gfxrecon::format::PacketCall_vkEnumeratePhysicalDevices;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pPhysicalDeviceCount = pPhysicalDeviceCount;
    packet->pPhysicalDevices = pPhysicalDevices;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceFeatures(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceFeatures* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceFeatures>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceFeatures;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pFeatures = pFeatures;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceFormatProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceFormatProperties* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceFormatProperties>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceFormatProperties;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->format = format;
    packet->pFormatProperties = pFormatProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pImageFormatProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceImageFormatProperties* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceImageFormatProperties>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceImageFormatProperties;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->format = format;
    packet->type = type;
    packet->tiling = tiling;
    packet->usage = usage;
    packet->flags = flags;
    packet->pImageFormatProperties = pImageFormatProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceProperties* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceProperties>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceProperties;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pProperties = pProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceQueueFamilyProperties* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceQueueFamilyProperties>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceQueueFamilyProperties;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pQueueFamilyPropertyCount = pQueueFamilyPropertyCount;
    packet->pQueueFamilyProperties = pQueueFamilyProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceMemoryProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceMemoryProperties* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceMemoryProperties>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceMemoryProperties;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pMemoryProperties = pMemoryProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDevice(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDevice> pDevice;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDevice.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDevice* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDevice>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDevice;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pDevice = pDevice;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyDevice(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyDevice* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyDevice>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyDevice;
    packet->call_info = call_info;
    packet->device = device;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceQueue(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t queueFamilyIndex;
    uint32_t queueIndex;
    HandlePointerDecoder<VkQueue> pQueue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueIndex);
    bytes_read += pQueue.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceQueue* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceQueue>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceQueue;
    packet->call_info = call_info;
    packet->device = device;
    packet->queueFamilyIndex = queueFamilyIndex;
    packet->queueIndex = queueIndex;
    packet->pQueue = pQueue;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueueSubmit(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo> pSubmits;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &submitCount);
    bytes_read += pSubmits.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkQueueSubmit* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueueSubmit>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueueSubmit;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->submitCount = submitCount;
    packet->pSubmits = pSubmits;
    packet->fence = fence;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueueWaitIdle(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkQueueWaitIdle* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueueWaitIdle>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueueWaitIdle;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDeviceWaitIdle(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkDeviceWaitIdle* packet = PreloadDecodeAllocator::Allocate<Packet_vkDeviceWaitIdle>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDeviceWaitIdle;
    packet->call_info = call_info;
    packet->device = device;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAllocateMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo> pAllocateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDeviceMemory> pMemory;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemory.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkAllocateMemory* packet = PreloadDecodeAllocator::Allocate<Packet_vkAllocateMemory>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAllocateMemory;
    packet->call_info = call_info;
    packet->device = device;
    packet->pAllocateInfo = pAllocateInfo;
    packet->pAllocator = pAllocator;
    packet->pMemory = pMemory;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkFreeMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkFreeMemory* packet = PreloadDecodeAllocator::Allocate<Packet_vkFreeMemory>();
    packet->packet_id = gfxrecon::format::PacketCall_vkFreeMemory;
    packet->call_info = call_info;
    packet->device = device;
    packet->memory = memory;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkMapMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkMapMemory* packet = PreloadDecodeAllocator::Allocate<Packet_vkMapMemory>();
    packet->packet_id = gfxrecon::format::PacketCall_vkMapMemory;
    packet->call_info = call_info;
    packet->device = device;
    packet->memory = memory;
    packet->offset = offset;
    packet->size = size;
    packet->flags = flags;
    packet->ppData = ppData;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkUnmapMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);

    Packet_vkUnmapMemory* packet = PreloadDecodeAllocator::Allocate<Packet_vkUnmapMemory>();
    packet->packet_id = gfxrecon::format::PacketCall_vkUnmapMemory;
    packet->call_info = call_info;
    packet->device = device;
    packet->memory = memory;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkFlushMappedMemoryRanges(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryRangeCount);
    bytes_read += pMemoryRanges.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkFlushMappedMemoryRanges* packet = PreloadDecodeAllocator::Allocate<Packet_vkFlushMappedMemoryRanges>();
    packet->packet_id = gfxrecon::format::PacketCall_vkFlushMappedMemoryRanges;
    packet->call_info = call_info;
    packet->device = device;
    packet->memoryRangeCount = memoryRangeCount;
    packet->pMemoryRanges = pMemoryRanges;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkInvalidateMappedMemoryRanges(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryRangeCount);
    bytes_read += pMemoryRanges.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkInvalidateMappedMemoryRanges* packet = PreloadDecodeAllocator::Allocate<Packet_vkInvalidateMappedMemoryRanges>();
    packet->packet_id = gfxrecon::format::PacketCall_vkInvalidateMappedMemoryRanges;
    packet->call_info = call_info;
    packet->device = device;
    packet->memoryRangeCount = memoryRangeCount;
    packet->pMemoryRanges = pMemoryRanges;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceMemoryCommitment(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    PointerDecoder<VkDeviceSize> pCommittedMemoryInBytes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += pCommittedMemoryInBytes.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceMemoryCommitment* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceMemoryCommitment>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceMemoryCommitment;
    packet->call_info = call_info;
    packet->device = device;
    packet->memory = memory;
    packet->pCommittedMemoryInBytes = pCommittedMemoryInBytes;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBindBufferMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkBindBufferMemory* packet = PreloadDecodeAllocator::Allocate<Packet_vkBindBufferMemory>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBindBufferMemory;
    packet->call_info = call_info;
    packet->device = device;
    packet->buffer = buffer;
    packet->memory = memory;
    packet->memoryOffset = memoryOffset;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBindImageMemory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkBindImageMemory* packet = PreloadDecodeAllocator::Allocate<Packet_vkBindImageMemory>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBindImageMemory;
    packet->call_info = call_info;
    packet->device = device;
    packet->image = image;
    packet->memory = memory;
    packet->memoryOffset = memoryOffset;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetBufferMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetBufferMemoryRequirements* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetBufferMemoryRequirements>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetBufferMemoryRequirements;
    packet->call_info = call_info;
    packet->device = device;
    packet->buffer = buffer;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetImageMemoryRequirements* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageMemoryRequirements>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageMemoryRequirements;
    packet->call_info = call_info;
    packet->device = device;
    packet->image = image;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageSparseMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pSparseMemoryRequirementCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetImageSparseMemoryRequirements* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageSparseMemoryRequirements>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageSparseMemoryRequirements;
    packet->call_info = call_info;
    packet->device = device;
    packet->image = image;
    packet->pSparseMemoryRequirementCount = pSparseMemoryRequirementCount;
    packet->pSparseMemoryRequirements = pSparseMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceSparseImageFormatProperties* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSparseImageFormatProperties>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSparseImageFormatProperties;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->format = format;
    packet->type = type;
    packet->samples = samples;
    packet->usage = usage;
    packet->tiling = tiling;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueueBindSparse(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindSparseInfo> pBindInfo;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkQueueBindSparse* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueueBindSparse>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueueBindSparse;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->bindInfoCount = bindInfoCount;
    packet->pBindInfo = pBindInfo;
    packet->fence = fence;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateFence(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFence.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateFence* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateFence>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateFence;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pFence = pFence;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyFence(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId fence;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyFence* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyFence>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyFence;
    packet->call_info = call_info;
    packet->device = device;
    packet->fence = fence;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkResetFences(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t fenceCount;
    HandlePointerDecoder<VkFence> pFences;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fenceCount);
    bytes_read += pFences.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkResetFences* packet = PreloadDecodeAllocator::Allocate<Packet_vkResetFences>();
    packet->packet_id = gfxrecon::format::PacketCall_vkResetFences;
    packet->call_info = call_info;
    packet->device = device;
    packet->fenceCount = fenceCount;
    packet->pFences = pFences;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetFenceStatus(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetFenceStatus* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetFenceStatus>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetFenceStatus;
    packet->call_info = call_info;
    packet->device = device;
    packet->fence = fence;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkWaitForFences(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pFences.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &waitAll);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkWaitForFences* packet = PreloadDecodeAllocator::Allocate<Packet_vkWaitForFences>();
    packet->packet_id = gfxrecon::format::PacketCall_vkWaitForFences;
    packet->call_info = call_info;
    packet->device = device;
    packet->fenceCount = fenceCount;
    packet->pFences = pFences;
    packet->waitAll = waitAll;
    packet->timeout = timeout;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateSemaphore(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSemaphore> pSemaphore;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSemaphore.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateSemaphore* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateSemaphore>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateSemaphore;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSemaphore = pSemaphore;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroySemaphore(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId semaphore;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroySemaphore* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroySemaphore>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroySemaphore;
    packet->call_info = call_info;
    packet->device = device;
    packet->semaphore = semaphore;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkEventCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkEvent> pEvent;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pEvent.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateEvent* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateEvent>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateEvent;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pEvent = pEvent;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyEvent* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyEvent>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyEvent;
    packet->call_info = call_info;
    packet->device = device;
    packet->event = event;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetEventStatus(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetEventStatus* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetEventStatus>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetEventStatus;
    packet->call_info = call_info;
    packet->device = device;
    packet->event = event;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkSetEvent* packet = PreloadDecodeAllocator::Allocate<Packet_vkSetEvent>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSetEvent;
    packet->call_info = call_info;
    packet->device = device;
    packet->event = event;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkResetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkResetEvent* packet = PreloadDecodeAllocator::Allocate<Packet_vkResetEvent>();
    packet->packet_id = gfxrecon::format::PacketCall_vkResetEvent;
    packet->call_info = call_info;
    packet->device = device;
    packet->event = event;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkQueryPool> pQueryPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueryPool.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateQueryPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateQueryPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateQueryPool;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pQueryPool = pQueryPool;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId queryPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyQueryPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyQueryPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyQueryPool;
    packet->call_info = call_info;
    packet->device = device;
    packet->queryPool = queryPool;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetQueryPoolResults(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetQueryPoolResults* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetQueryPoolResults>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetQueryPoolResults;
    packet->call_info = call_info;
    packet->device = device;
    packet->queryPool = queryPool;
    packet->firstQuery = firstQuery;
    packet->queryCount = queryCount;
    packet->dataSize = dataSize;
    packet->pData = pData;
    packet->stride = stride;
    packet->flags = flags;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkBuffer> pBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pBuffer.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateBuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateBuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateBuffer;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pBuffer = pBuffer;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyBuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyBuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyBuffer;
    packet->call_info = call_info;
    packet->device = device;
    packet->buffer = buffer;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateBufferView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkBufferView> pView;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pView.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateBufferView* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateBufferView>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateBufferView;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pView = pView;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyBufferView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId bufferView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferView);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyBufferView* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyBufferView>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyBufferView;
    packet->call_info = call_info;
    packet->device = device;
    packet->bufferView = bufferView;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkImage> pImage;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImage.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateImage* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateImage>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateImage;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pImage = pImage;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyImage* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyImage>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyImage;
    packet->call_info = call_info;
    packet->device = device;
    packet->image = image;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageSubresourceLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout> pLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pSubresource.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pLayout.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetImageSubresourceLayout* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageSubresourceLayout>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageSubresourceLayout;
    packet->call_info = call_info;
    packet->device = device;
    packet->image = image;
    packet->pSubresource = pSubresource;
    packet->pLayout = pLayout;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateImageView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkImageView> pView;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pView.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateImageView* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateImageView>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateImageView;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pView = pView;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyImageView(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId imageView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageView);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyImageView* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyImageView>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyImageView;
    packet->call_info = call_info;
    packet->device = device;
    packet->imageView = imageView;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateShaderModule(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkShaderModule> pShaderModule;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pShaderModule.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateShaderModule* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateShaderModule>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateShaderModule;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pShaderModule = pShaderModule;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyShaderModule(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId shaderModule;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shaderModule);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyShaderModule* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyShaderModule>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyShaderModule;
    packet->call_info = call_info;
    packet->device = device;
    packet->shaderModule = shaderModule;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreatePipelineCache(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipelineCache> pPipelineCache;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelineCache.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreatePipelineCache* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreatePipelineCache>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreatePipelineCache;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pPipelineCache = pPipelineCache;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyPipelineCache(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyPipelineCache* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyPipelineCache>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyPipelineCache;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipelineCache = pipelineCache;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPipelineCacheData(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += pDataSize.PreloadDecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPipelineCacheData* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPipelineCacheData>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPipelineCacheData;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipelineCache = pipelineCache;
    packet->pDataSize = pDataSize;
    packet->pData = pData;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkMergePipelineCaches(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pSrcCaches.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkMergePipelineCaches* packet = PreloadDecodeAllocator::Allocate<Packet_vkMergePipelineCaches>();
    packet->packet_id = gfxrecon::format::PacketCall_vkMergePipelineCaches;
    packet->call_info = call_info;
    packet->device = device;
    packet->dstCache = dstCache;
    packet->srcCacheCount = srcCacheCount;
    packet->pSrcCaches = pSrcCaches;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateGraphicsPipelines(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCreateInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelines.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateGraphicsPipelines* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateGraphicsPipelines>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateGraphicsPipelines;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipelineCache = pipelineCache;
    packet->createInfoCount = createInfoCount;
    packet->pCreateInfos = pCreateInfos;
    packet->pAllocator = pAllocator;
    packet->pPipelines = pPipelines;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateComputePipelines(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCreateInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelines.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateComputePipelines* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateComputePipelines>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateComputePipelines;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipelineCache = pipelineCache;
    packet->createInfoCount = createInfoCount;
    packet->pCreateInfos = pCreateInfos;
    packet->pAllocator = pAllocator;
    packet->pPipelines = pPipelines;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyPipeline(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyPipeline* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyPipeline>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyPipeline;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipeline = pipeline;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreatePipelineLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPipelineLayout> pPipelineLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelineLayout.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreatePipelineLayout* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreatePipelineLayout>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreatePipelineLayout;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pPipelineLayout = pPipelineLayout;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyPipelineLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineLayout);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyPipelineLayout* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyPipelineLayout>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyPipelineLayout;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipelineLayout = pipelineLayout;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateSampler(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSampler> pSampler;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSampler.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateSampler* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateSampler>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateSampler;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSampler = pSampler;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroySampler(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId sampler;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sampler);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroySampler* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroySampler>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroySampler;
    packet->call_info = call_info;
    packet->device = device;
    packet->sampler = sampler;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDescriptorSetLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSetLayout.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDescriptorSetLayout* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDescriptorSetLayout>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDescriptorSetLayout;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSetLayout = pSetLayout;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyDescriptorSetLayout(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorSetLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSetLayout);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyDescriptorSetLayout* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyDescriptorSetLayout>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyDescriptorSetLayout;
    packet->call_info = call_info;
    packet->device = device;
    packet->descriptorSetLayout = descriptorSetLayout;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDescriptorPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorPool> pDescriptorPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorPool.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDescriptorPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDescriptorPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDescriptorPool;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pDescriptorPool = pDescriptorPool;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyDescriptorPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorPool);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyDescriptorPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyDescriptorPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyDescriptorPool;
    packet->call_info = call_info;
    packet->device = device;
    packet->descriptorPool = descriptorPool;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkResetDescriptorPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkResetDescriptorPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkResetDescriptorPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkResetDescriptorPool;
    packet->call_info = call_info;
    packet->device = device;
    packet->descriptorPool = descriptorPool;
    packet->flags = flags;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAllocateDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo> pAllocateInfo;
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorSets.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkAllocateDescriptorSets* packet = PreloadDecodeAllocator::Allocate<Packet_vkAllocateDescriptorSets>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAllocateDescriptorSets;
    packet->call_info = call_info;
    packet->device = device;
    packet->pAllocateInfo = pAllocateInfo;
    packet->pDescriptorSets = pDescriptorSets;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkFreeDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pDescriptorSets.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkFreeDescriptorSets* packet = PreloadDecodeAllocator::Allocate<Packet_vkFreeDescriptorSets>();
    packet->packet_id = gfxrecon::format::PacketCall_vkFreeDescriptorSets;
    packet->call_info = call_info;
    packet->device = device;
    packet->descriptorPool = descriptorPool;
    packet->descriptorSetCount = descriptorSetCount;
    packet->pDescriptorSets = pDescriptorSets;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkUpdateDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;
    uint32_t descriptorCopyCount;
    StructPointerDecoder<Decoded_VkCopyDescriptorSet> pDescriptorCopies;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorWriteCount);
    bytes_read += pDescriptorWrites.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorCopyCount);
    bytes_read += pDescriptorCopies.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkUpdateDescriptorSets* packet = PreloadDecodeAllocator::Allocate<Packet_vkUpdateDescriptorSets>();
    packet->packet_id = gfxrecon::format::PacketCall_vkUpdateDescriptorSets;
    packet->call_info = call_info;
    packet->device = device;
    packet->descriptorWriteCount = descriptorWriteCount;
    packet->pDescriptorWrites = pDescriptorWrites;
    packet->descriptorCopyCount = descriptorCopyCount;
    packet->pDescriptorCopies = pDescriptorCopies;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateFramebuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFramebuffer> pFramebuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFramebuffer.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateFramebuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateFramebuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateFramebuffer;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pFramebuffer = pFramebuffer;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyFramebuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId framebuffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &framebuffer);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyFramebuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyFramebuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyFramebuffer;
    packet->call_info = call_info;
    packet->device = device;
    packet->framebuffer = framebuffer;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRenderPass.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateRenderPass* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateRenderPass>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateRenderPass;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pRenderPass = pRenderPass;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &renderPass);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyRenderPass* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyRenderPass>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyRenderPass;
    packet->call_info = call_info;
    packet->device = device;
    packet->renderPass = renderPass;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetRenderAreaGranularity(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &renderPass);
    bytes_read += pGranularity.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetRenderAreaGranularity* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetRenderAreaGranularity>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetRenderAreaGranularity;
    packet->call_info = call_info;
    packet->device = device;
    packet->renderPass = renderPass;
    packet->pGranularity = pGranularity;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkCommandPool> pCommandPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCommandPool.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateCommandPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateCommandPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateCommandPool;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pCommandPool = pCommandPool;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyCommandPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyCommandPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyCommandPool;
    packet->call_info = call_info;
    packet->device = device;
    packet->commandPool = commandPool;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkResetCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkResetCommandPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkResetCommandPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkResetCommandPool;
    packet->call_info = call_info;
    packet->device = device;
    packet->commandPool = commandPool;
    packet->flags = flags;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAllocateCommandBuffers(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo> pAllocateInfo;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCommandBuffers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkAllocateCommandBuffers* packet = PreloadDecodeAllocator::Allocate<Packet_vkAllocateCommandBuffers>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAllocateCommandBuffers;
    packet->call_info = call_info;
    packet->device = device;
    packet->pAllocateInfo = pAllocateInfo;
    packet->pCommandBuffers = pCommandBuffers;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkFreeCommandBuffers(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    uint32_t commandBufferCount;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBufferCount);
    bytes_read += pCommandBuffers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkFreeCommandBuffers* packet = PreloadDecodeAllocator::Allocate<Packet_vkFreeCommandBuffers>();
    packet->packet_id = gfxrecon::format::PacketCall_vkFreeCommandBuffers;
    packet->call_info = call_info;
    packet->device = device;
    packet->commandPool = commandPool;
    packet->commandBufferCount = commandBufferCount;
    packet->pCommandBuffers = pCommandBuffers;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBeginCommandBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo> pBeginInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBeginInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkBeginCommandBuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkBeginCommandBuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBeginCommandBuffer;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pBeginInfo = pBeginInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkEndCommandBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkEndCommandBuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkEndCommandBuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkEndCommandBuffer;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkResetCommandBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCommandBufferResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkResetCommandBuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkResetCommandBuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkResetCommandBuffer;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->flags = flags;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindPipeline(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);

    Packet_vkCmdBindPipeline* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindPipeline>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindPipeline;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pipelineBindPoint = pipelineBindPoint;
    packet->pipeline = pipeline;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetViewport(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewports.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetViewport* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetViewport>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetViewport;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstViewport = firstViewport;
    packet->viewportCount = viewportCount;
    packet->pViewports = pViewports;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetScissor(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstScissor;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scissorCount);
    bytes_read += pScissors.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetScissor* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetScissor>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetScissor;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstScissor = firstScissor;
    packet->scissorCount = scissorCount;
    packet->pScissors = pScissors;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetLineWidth(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float lineWidth;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineWidth);

    Packet_vkCmdSetLineWidth* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetLineWidth>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetLineWidth;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->lineWidth = lineWidth;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthBias(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdSetDepthBias* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthBias>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthBias;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthBiasConstantFactor = depthBiasConstantFactor;
    packet->depthBiasClamp = depthBiasClamp;
    packet->depthBiasSlopeFactor = depthBiasSlopeFactor;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetBlendConstants(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    PointerDecoder<float> blendConstants;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += blendConstants.PreloadDecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetBlendConstants* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetBlendConstants>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetBlendConstants;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->blendConstants = blendConstants;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthBounds(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float minDepthBounds;
    float maxDepthBounds;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &minDepthBounds);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDepthBounds);

    Packet_vkCmdSetDepthBounds* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthBounds>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthBounds;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->minDepthBounds = minDepthBounds;
    packet->maxDepthBounds = maxDepthBounds;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetStencilCompareMask(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t compareMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &compareMask);

    Packet_vkCmdSetStencilCompareMask* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetStencilCompareMask>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetStencilCompareMask;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->faceMask = faceMask;
    packet->compareMask = compareMask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetStencilWriteMask(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t writeMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &writeMask);

    Packet_vkCmdSetStencilWriteMask* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetStencilWriteMask>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetStencilWriteMask;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->faceMask = faceMask;
    packet->writeMask = writeMask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetStencilReference(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t reference;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &reference);

    Packet_vkCmdSetStencilReference* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetStencilReference>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetStencilReference;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->faceMask = faceMask;
    packet->reference = reference;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindDescriptorSets(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pDescriptorSets.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dynamicOffsetCount);
    bytes_read += pDynamicOffsets.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBindDescriptorSets* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindDescriptorSets>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindDescriptorSets;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pipelineBindPoint = pipelineBindPoint;
    packet->layout = layout;
    packet->firstSet = firstSet;
    packet->descriptorSetCount = descriptorSetCount;
    packet->pDescriptorSets = pDescriptorSets;
    packet->dynamicOffsetCount = dynamicOffsetCount;
    packet->pDynamicOffsets = pDynamicOffsets;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindIndexBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdBindIndexBuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindIndexBuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindIndexBuffer;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->indexType = indexType;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindVertexBuffers(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pBuffers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pOffsets.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBindVertexBuffers* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindVertexBuffers>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindVertexBuffers;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstBinding = firstBinding;
    packet->bindingCount = bindingCount;
    packet->pBuffers = pBuffers;
    packet->pOffsets = pOffsets;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDraw(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDraw* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDraw>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDraw;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->vertexCount = vertexCount;
    packet->instanceCount = instanceCount;
    packet->firstVertex = firstVertex;
    packet->firstInstance = firstInstance;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawIndexed(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawIndexed* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawIndexed>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawIndexed;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->indexCount = indexCount;
    packet->instanceCount = instanceCount;
    packet->firstIndex = firstIndex;
    packet->vertexOffset = vertexOffset;
    packet->firstInstance = firstInstance;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawIndirect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawIndirect* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawIndirect>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawIndirect;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->drawCount = drawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawIndexedIndirect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawIndexedIndirect* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawIndexedIndirect>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawIndexedIndirect;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->drawCount = drawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDispatch(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDispatch* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDispatch>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDispatch;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->groupCountX = groupCountX;
    packet->groupCountY = groupCountY;
    packet->groupCountZ = groupCountZ;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDispatchIndirect(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);

    Packet_vkCmdDispatchIndirect* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDispatchIndirect>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDispatchIndirect;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pRegions.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyBuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyBuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyBuffer;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->srcBuffer = srcBuffer;
    packet->dstBuffer = dstBuffer;
    packet->regionCount = regionCount;
    packet->pRegions = pRegions;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pRegions.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyImage* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyImage>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyImage;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->srcImage = srcImage;
    packet->srcImageLayout = srcImageLayout;
    packet->dstImage = dstImage;
    packet->dstImageLayout = dstImageLayout;
    packet->regionCount = regionCount;
    packet->pRegions = pRegions;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBlitImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pRegions.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &filter);

    Packet_vkCmdBlitImage* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBlitImage>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBlitImage;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->srcImage = srcImage;
    packet->srcImageLayout = srcImageLayout;
    packet->dstImage = dstImage;
    packet->dstImageLayout = dstImageLayout;
    packet->regionCount = regionCount;
    packet->pRegions = pRegions;
    packet->filter = filter;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyBufferToImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pRegions.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyBufferToImage* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyBufferToImage>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyBufferToImage;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->srcBuffer = srcBuffer;
    packet->dstImage = dstImage;
    packet->dstImageLayout = dstImageLayout;
    packet->regionCount = regionCount;
    packet->pRegions = pRegions;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyImageToBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pRegions.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyImageToBuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyImageToBuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyImageToBuffer;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->srcImage = srcImage;
    packet->srcImageLayout = srcImageLayout;
    packet->dstBuffer = dstBuffer;
    packet->regionCount = regionCount;
    packet->pRegions = pRegions;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdUpdateBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdUpdateBuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdUpdateBuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdUpdateBuffer;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->dstBuffer = dstBuffer;
    packet->dstOffset = dstOffset;
    packet->dataSize = dataSize;
    packet->pData = pData;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdFillBuffer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdFillBuffer* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdFillBuffer>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdFillBuffer;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->dstBuffer = dstBuffer;
    packet->dstOffset = dstOffset;
    packet->size = size;
    packet->data = data;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdClearColorImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pColor.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rangeCount);
    bytes_read += pRanges.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdClearColorImage* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdClearColorImage>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdClearColorImage;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->image = image;
    packet->imageLayout = imageLayout;
    packet->pColor = pColor;
    packet->rangeCount = rangeCount;
    packet->pRanges = pRanges;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdClearDepthStencilImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pDepthStencil.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rangeCount);
    bytes_read += pRanges.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdClearDepthStencilImage* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdClearDepthStencilImage>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdClearDepthStencilImage;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->image = image;
    packet->imageLayout = imageLayout;
    packet->pDepthStencil = pDepthStencil;
    packet->rangeCount = rangeCount;
    packet->pRanges = pRanges;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdClearAttachments(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkClearAttachment> pAttachments;
    uint32_t rectCount;
    StructPointerDecoder<Decoded_VkClearRect> pRects;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pAttachments.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rectCount);
    bytes_read += pRects.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdClearAttachments* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdClearAttachments>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdClearAttachments;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->attachmentCount = attachmentCount;
    packet->pAttachments = pAttachments;
    packet->rectCount = rectCount;
    packet->pRects = pRects;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdResolveImage(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pRegions.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdResolveImage* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdResolveImage>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdResolveImage;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->srcImage = srcImage;
    packet->srcImageLayout = srcImageLayout;
    packet->dstImage = dstImage;
    packet->dstImageLayout = dstImageLayout;
    packet->regionCount = regionCount;
    packet->pRegions = pRegions;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageMask);

    Packet_vkCmdSetEvent* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetEvent>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetEvent;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->event = event;
    packet->stageMask = stageMask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdResetEvent(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageMask);

    Packet_vkCmdResetEvent* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdResetEvent>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdResetEvent;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->event = event;
    packet->stageMask = stageMask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWaitEvents(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pEvents.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstStageMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryBarrierCount);
    bytes_read += pMemoryBarriers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferMemoryBarrierCount);
    bytes_read += pBufferMemoryBarriers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageMemoryBarrierCount);
    bytes_read += pImageMemoryBarriers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdWaitEvents* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWaitEvents>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWaitEvents;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->eventCount = eventCount;
    packet->pEvents = pEvents;
    packet->srcStageMask = srcStageMask;
    packet->dstStageMask = dstStageMask;
    packet->memoryBarrierCount = memoryBarrierCount;
    packet->pMemoryBarriers = pMemoryBarriers;
    packet->bufferMemoryBarrierCount = bufferMemoryBarrierCount;
    packet->pBufferMemoryBarriers = pBufferMemoryBarriers;
    packet->imageMemoryBarrierCount = imageMemoryBarrierCount;
    packet->pImageMemoryBarriers = pImageMemoryBarriers;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdPipelineBarrier(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pMemoryBarriers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferMemoryBarrierCount);
    bytes_read += pBufferMemoryBarriers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageMemoryBarrierCount);
    bytes_read += pImageMemoryBarriers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdPipelineBarrier* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdPipelineBarrier>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdPipelineBarrier;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->srcStageMask = srcStageMask;
    packet->dstStageMask = dstStageMask;
    packet->dependencyFlags = dependencyFlags;
    packet->memoryBarrierCount = memoryBarrierCount;
    packet->pMemoryBarriers = pMemoryBarriers;
    packet->bufferMemoryBarrierCount = bufferMemoryBarrierCount;
    packet->pBufferMemoryBarriers = pBufferMemoryBarriers;
    packet->imageMemoryBarrierCount = imageMemoryBarrierCount;
    packet->pImageMemoryBarriers = pImageMemoryBarriers;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginQuery(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdBeginQuery* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginQuery>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginQuery;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->queryPool = queryPool;
    packet->query = query;
    packet->flags = flags;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndQuery(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);

    Packet_vkCmdEndQuery* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndQuery>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndQuery;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->queryPool = queryPool;
    packet->query = query;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdResetQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdResetQueryPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdResetQueryPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdResetQueryPool;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->queryPool = queryPool;
    packet->firstQuery = firstQuery;
    packet->queryCount = queryCount;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWriteTimestamp(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdWriteTimestamp* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWriteTimestamp>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWriteTimestamp;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pipelineStage = pipelineStage;
    packet->queryPool = queryPool;
    packet->query = query;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyQueryPoolResults(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdCopyQueryPoolResults* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyQueryPoolResults>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyQueryPoolResults;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->queryPool = queryPool;
    packet->firstQuery = firstQuery;
    packet->queryCount = queryCount;
    packet->dstBuffer = dstBuffer;
    packet->dstOffset = dstOffset;
    packet->stride = stride;
    packet->flags = flags;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdPushConstants(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pValues.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdPushConstants* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdPushConstants>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdPushConstants;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->layout = layout;
    packet->stageFlags = stageFlags;
    packet->offset = offset;
    packet->size = size;
    packet->pValues = pValues;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &contents);

    Packet_vkCmdBeginRenderPass* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginRenderPass>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginRenderPass;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pRenderPassBegin = pRenderPassBegin;
    packet->contents = contents;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdNextSubpass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &contents);

    Packet_vkCmdNextSubpass* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdNextSubpass>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdNextSubpass;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->contents = contents;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndRenderPass(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    Packet_vkCmdEndRenderPass* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndRenderPass>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndRenderPass;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdExecuteCommands(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t commandBufferCount;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBufferCount);
    bytes_read += pCommandBuffers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdExecuteCommands* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdExecuteCommands>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdExecuteCommands;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->commandBufferCount = commandBufferCount;
    packet->pCommandBuffers = pCommandBuffers;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBindBufferMemory2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkBindBufferMemory2* packet = PreloadDecodeAllocator::Allocate<Packet_vkBindBufferMemory2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBindBufferMemory2;
    packet->call_info = call_info;
    packet->device = device;
    packet->bindInfoCount = bindInfoCount;
    packet->pBindInfos = pBindInfos;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBindImageMemory2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkBindImageMemory2* packet = PreloadDecodeAllocator::Allocate<Packet_vkBindImageMemory2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBindImageMemory2;
    packet->call_info = call_info;
    packet->device = device;
    packet->bindInfoCount = bindInfoCount;
    packet->pBindInfos = pBindInfos;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceGroupPeerMemoryFeatures(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pPeerMemoryFeatures.PreloadDecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceGroupPeerMemoryFeatures* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceGroupPeerMemoryFeatures>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceGroupPeerMemoryFeatures;
    packet->call_info = call_info;
    packet->device = device;
    packet->heapIndex = heapIndex;
    packet->localDeviceIndex = localDeviceIndex;
    packet->remoteDeviceIndex = remoteDeviceIndex;
    packet->pPeerMemoryFeatures = pPeerMemoryFeatures;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDeviceMask(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceMask);

    Packet_vkCmdSetDeviceMask* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDeviceMask>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDeviceMask;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->deviceMask = deviceMask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDispatchBase(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDispatchBase* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDispatchBase>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDispatchBase;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->baseGroupX = baseGroupX;
    packet->baseGroupY = baseGroupY;
    packet->baseGroupZ = baseGroupZ;
    packet->groupCountX = groupCountX;
    packet->groupCountY = groupCountY;
    packet->groupCountZ = groupCountZ;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkEnumeratePhysicalDeviceGroups(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceGroupCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkEnumeratePhysicalDeviceGroups* packet = PreloadDecodeAllocator::Allocate<Packet_vkEnumeratePhysicalDeviceGroups>();
    packet->packet_id = gfxrecon::format::PacketCall_vkEnumeratePhysicalDeviceGroups;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pPhysicalDeviceGroupCount = pPhysicalDeviceGroupCount;
    packet->pPhysicalDeviceGroupProperties = pPhysicalDeviceGroupProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageMemoryRequirements2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetImageMemoryRequirements2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageMemoryRequirements2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageMemoryRequirements2;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetBufferMemoryRequirements2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetBufferMemoryRequirements2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetBufferMemoryRequirements2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetBufferMemoryRequirements2;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageSparseMemoryRequirements2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetImageSparseMemoryRequirements2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageSparseMemoryRequirements2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageSparseMemoryRequirements2;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pSparseMemoryRequirementCount = pSparseMemoryRequirementCount;
    packet->pSparseMemoryRequirements = pSparseMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceFeatures2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceFeatures2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceFeatures2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceFeatures2;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pFeatures = pFeatures;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceProperties2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceProperties2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceProperties2;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pProperties = pProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceFormatProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceFormatProperties2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceFormatProperties2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceFormatProperties2;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->format = format;
    packet->pFormatProperties = pFormatProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pImageFormatInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceImageFormatProperties2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceImageFormatProperties2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceImageFormatProperties2;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pImageFormatInfo = pImageFormatInfo;
    packet->pImageFormatProperties = pImageFormatProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceQueueFamilyProperties2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceQueueFamilyProperties2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceQueueFamilyProperties2;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pQueueFamilyPropertyCount = pQueueFamilyPropertyCount;
    packet->pQueueFamilyProperties = pQueueFamilyProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceMemoryProperties2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceMemoryProperties2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceMemoryProperties2;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pMemoryProperties = pMemoryProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFormatInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceSparseImageFormatProperties2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSparseImageFormatProperties2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSparseImageFormatProperties2;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pFormatInfo = pFormatInfo;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkTrimCommandPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    Packet_vkTrimCommandPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkTrimCommandPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkTrimCommandPool;
    packet->call_info = call_info;
    packet->device = device;
    packet->commandPool = commandPool;
    packet->flags = flags;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceQueue2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2> pQueueInfo;
    HandlePointerDecoder<VkQueue> pQueue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pQueueInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueue.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceQueue2* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceQueue2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceQueue2;
    packet->call_info = call_info;
    packet->device = device;
    packet->pQueueInfo = pQueueInfo;
    packet->pQueue = pQueue;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateSamplerYcbcrConversion(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pYcbcrConversion.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateSamplerYcbcrConversion* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateSamplerYcbcrConversion>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateSamplerYcbcrConversion;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pYcbcrConversion = pYcbcrConversion;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroySamplerYcbcrConversion(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ycbcrConversion);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroySamplerYcbcrConversion* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroySamplerYcbcrConversion>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroySamplerYcbcrConversion;
    packet->call_info = call_info;
    packet->device = device;
    packet->ycbcrConversion = ycbcrConversion;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDescriptorUpdateTemplate(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorUpdateTemplate.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDescriptorUpdateTemplate* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDescriptorUpdateTemplate>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDescriptorUpdateTemplate;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pDescriptorUpdateTemplate = pDescriptorUpdateTemplate;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyDescriptorUpdateTemplate(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyDescriptorUpdateTemplate* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyDescriptorUpdateTemplate>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyDescriptorUpdateTemplate;
    packet->call_info = call_info;
    packet->device = device;
    packet->descriptorUpdateTemplate = descriptorUpdateTemplate;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceExternalBufferProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalBufferInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalBufferProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceExternalBufferProperties* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceExternalBufferProperties>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceExternalBufferProperties;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pExternalBufferInfo = pExternalBufferInfo;
    packet->pExternalBufferProperties = pExternalBufferProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceExternalFenceProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalFenceInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalFenceProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceExternalFenceProperties* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceExternalFenceProperties>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceExternalFenceProperties;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pExternalFenceInfo = pExternalFenceInfo;
    packet->pExternalFenceProperties = pExternalFenceProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalSemaphoreInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalSemaphoreProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceExternalSemaphoreProperties* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceExternalSemaphoreProperties>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceExternalSemaphoreProperties;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pExternalSemaphoreInfo = pExternalSemaphoreInfo;
    packet->pExternalSemaphoreProperties = pExternalSemaphoreProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDescriptorSetLayoutSupport(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSupport.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDescriptorSetLayoutSupport* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDescriptorSetLayoutSupport>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDescriptorSetLayoutSupport;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pSupport = pSupport;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawIndirectCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawIndirectCount* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawIndirectCount>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawIndirectCount;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->countBuffer = countBuffer;
    packet->countBufferOffset = countBufferOffset;
    packet->maxDrawCount = maxDrawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawIndexedIndirectCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawIndexedIndirectCount* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawIndexedIndirectCount>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawIndexedIndirectCount;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->countBuffer = countBuffer;
    packet->countBufferOffset = countBufferOffset;
    packet->maxDrawCount = maxDrawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateRenderPass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRenderPass.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateRenderPass2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateRenderPass2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateRenderPass2;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pRenderPass = pRenderPass;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginRenderPass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSubpassBeginInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBeginRenderPass2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginRenderPass2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginRenderPass2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pRenderPassBegin = pRenderPassBegin;
    packet->pSubpassBeginInfo = pSubpassBeginInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdNextSubpass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassBeginInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSubpassEndInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdNextSubpass2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdNextSubpass2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdNextSubpass2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pSubpassBeginInfo = pSubpassBeginInfo;
    packet->pSubpassEndInfo = pSubpassEndInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndRenderPass2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassEndInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdEndRenderPass2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndRenderPass2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndRenderPass2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pSubpassEndInfo = pSubpassEndInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkResetQueryPool(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkResetQueryPool* packet = PreloadDecodeAllocator::Allocate<Packet_vkResetQueryPool>();
    packet->packet_id = gfxrecon::format::PacketCall_vkResetQueryPool;
    packet->call_info = call_info;
    packet->device = device;
    packet->queryPool = queryPool;
    packet->firstQuery = firstQuery;
    packet->queryCount = queryCount;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetSemaphoreCounterValue(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId semaphore;
    PointerDecoder<uint64_t> pValue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += pValue.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetSemaphoreCounterValue* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetSemaphoreCounterValue>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetSemaphoreCounterValue;
    packet->call_info = call_info;
    packet->device = device;
    packet->semaphore = semaphore;
    packet->pValue = pValue;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkWaitSemaphores(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo> pWaitInfo;
    uint64_t timeout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pWaitInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkWaitSemaphores* packet = PreloadDecodeAllocator::Allocate<Packet_vkWaitSemaphores>();
    packet->packet_id = gfxrecon::format::PacketCall_vkWaitSemaphores;
    packet->call_info = call_info;
    packet->device = device;
    packet->pWaitInfo = pWaitInfo;
    packet->timeout = timeout;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSignalSemaphore(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo> pSignalInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pSignalInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkSignalSemaphore* packet = PreloadDecodeAllocator::Allocate<Packet_vkSignalSemaphore>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSignalSemaphore;
    packet->call_info = call_info;
    packet->device = device;
    packet->pSignalInfo = pSignalInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetBufferDeviceAddress(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetBufferDeviceAddress* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetBufferDeviceAddress>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetBufferDeviceAddress;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetBufferOpaqueCaptureAddress(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    uint64_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetBufferOpaqueCaptureAddress* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetBufferOpaqueCaptureAddress>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetBufferOpaqueCaptureAddress;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceMemoryOpaqueCaptureAddress(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo> pInfo;
    uint64_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDeviceMemoryOpaqueCaptureAddress* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceMemoryOpaqueCaptureAddress>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceMemoryOpaqueCaptureAddress;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceToolProperties(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties> pToolProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pToolCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pToolProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceToolProperties* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceToolProperties>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceToolProperties;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pToolCount = pToolCount;
    packet->pToolProperties = pToolProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreatePrivateDataSlot(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlot> pPrivateDataSlot;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPrivateDataSlot.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreatePrivateDataSlot* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreatePrivateDataSlot>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreatePrivateDataSlot;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pPrivateDataSlot = pPrivateDataSlot;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyPrivateDataSlot(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId privateDataSlot;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &privateDataSlot);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyPrivateDataSlot* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyPrivateDataSlot>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyPrivateDataSlot;
    packet->call_info = call_info;
    packet->device = device;
    packet->privateDataSlot = privateDataSlot;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSetPrivateData(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkSetPrivateData* packet = PreloadDecodeAllocator::Allocate<Packet_vkSetPrivateData>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSetPrivateData;
    packet->call_info = call_info;
    packet->device = device;
    packet->objectType = objectType;
    packet->objectHandle = objectHandle;
    packet->privateDataSlot = privateDataSlot;
    packet->data = data;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPrivateData(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pData.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPrivateData* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPrivateData>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPrivateData;
    packet->call_info = call_info;
    packet->device = device;
    packet->objectType = objectType;
    packet->objectHandle = objectHandle;
    packet->privateDataSlot = privateDataSlot;
    packet->pData = pData;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetEvent2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += pDependencyInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetEvent2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetEvent2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetEvent2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->event = event;
    packet->pDependencyInfo = pDependencyInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdResetEvent2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags2 stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlags64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageMask);

    Packet_vkCmdResetEvent2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdResetEvent2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdResetEvent2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->event = event;
    packet->stageMask = stageMask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWaitEvents2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t eventCount;
    HandlePointerDecoder<VkEvent> pEvents;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfos;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &eventCount);
    bytes_read += pEvents.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDependencyInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdWaitEvents2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWaitEvents2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWaitEvents2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->eventCount = eventCount;
    packet->pEvents = pEvents;
    packet->pDependencyInfos = pDependencyInfos;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdPipelineBarrier2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pDependencyInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdPipelineBarrier2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdPipelineBarrier2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdPipelineBarrier2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pDependencyInfo = pDependencyInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWriteTimestamp2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdWriteTimestamp2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWriteTimestamp2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWriteTimestamp2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->stage = stage;
    packet->queryPool = queryPool;
    packet->query = query;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueueSubmit2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo2> pSubmits;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &submitCount);
    bytes_read += pSubmits.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkQueueSubmit2* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueueSubmit2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueueSubmit2;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->submitCount = submitCount;
    packet->pSubmits = pSubmits;
    packet->fence = fence;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyBuffer2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferInfo2> pCopyBufferInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyBufferInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyBuffer2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyBuffer2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyBuffer2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pCopyBufferInfo = pCopyBufferInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageInfo2> pCopyImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyImageInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyImage2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyImage2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyImage2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pCopyImageInfo = pCopyImageInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyBufferToImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2> pCopyBufferToImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyBufferToImageInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyBufferToImage2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyBufferToImage2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyBufferToImage2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pCopyBufferToImageInfo = pCopyBufferToImageInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyImageToBuffer2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2> pCopyImageToBufferInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyImageToBufferInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyImageToBuffer2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyImageToBuffer2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyImageToBuffer2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pCopyImageToBufferInfo = pCopyImageToBufferInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBlitImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBlitImageInfo2> pBlitImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBlitImageInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBlitImage2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBlitImage2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBlitImage2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pBlitImageInfo = pBlitImageInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdResolveImage2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkResolveImageInfo2> pResolveImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pResolveImageInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdResolveImage2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdResolveImage2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdResolveImage2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pResolveImageInfo = pResolveImageInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginRendering(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderingInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBeginRendering* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginRendering>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginRendering;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pRenderingInfo = pRenderingInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndRendering(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    Packet_vkCmdEndRendering* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndRendering>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndRendering;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetCullMode(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCullModeFlags cullMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &cullMode);

    Packet_vkCmdSetCullMode* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetCullMode>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetCullMode;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->cullMode = cullMode;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetFrontFace(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkFrontFace frontFace;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &frontFace);

    Packet_vkCmdSetFrontFace* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetFrontFace>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetFrontFace;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->frontFace = frontFace;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetPrimitiveTopology(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPrimitiveTopology primitiveTopology;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &primitiveTopology);

    Packet_vkCmdSetPrimitiveTopology* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetPrimitiveTopology>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetPrimitiveTopology;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->primitiveTopology = primitiveTopology;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetViewportWithCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewports.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetViewportWithCount* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetViewportWithCount>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetViewportWithCount;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->viewportCount = viewportCount;
    packet->pViewports = pViewports;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetScissorWithCount(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scissorCount);
    bytes_read += pScissors.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetScissorWithCount* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetScissorWithCount>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetScissorWithCount;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->scissorCount = scissorCount;
    packet->pScissors = pScissors;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindVertexBuffers2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pBuffers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pOffsets.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizes.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pStrides.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBindVertexBuffers2* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindVertexBuffers2>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindVertexBuffers2;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstBinding = firstBinding;
    packet->bindingCount = bindingCount;
    packet->pBuffers = pBuffers;
    packet->pOffsets = pOffsets;
    packet->pSizes = pSizes;
    packet->pStrides = pStrides;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthTestEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthTestEnable);

    Packet_vkCmdSetDepthTestEnable* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthTestEnable>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthTestEnable;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthTestEnable = depthTestEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthWriteEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthWriteEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthWriteEnable);

    Packet_vkCmdSetDepthWriteEnable* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthWriteEnable>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthWriteEnable;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthWriteEnable = depthWriteEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthCompareOp(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCompareOp depthCompareOp;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthCompareOp);

    Packet_vkCmdSetDepthCompareOp* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthCompareOp>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthCompareOp;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthCompareOp = depthCompareOp;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthBoundsTestEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthBoundsTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBoundsTestEnable);

    Packet_vkCmdSetDepthBoundsTestEnable* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthBoundsTestEnable>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthBoundsTestEnable;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthBoundsTestEnable = depthBoundsTestEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetStencilTestEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 stencilTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stencilTestEnable);

    Packet_vkCmdSetStencilTestEnable* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetStencilTestEnable>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetStencilTestEnable;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->stencilTestEnable = stencilTestEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetStencilOp(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdSetStencilOp* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetStencilOp>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetStencilOp;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->faceMask = faceMask;
    packet->failOp = failOp;
    packet->passOp = passOp;
    packet->depthFailOp = depthFailOp;
    packet->compareOp = compareOp;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetRasterizerDiscardEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 rasterizerDiscardEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rasterizerDiscardEnable);

    Packet_vkCmdSetRasterizerDiscardEnable* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetRasterizerDiscardEnable>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetRasterizerDiscardEnable;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->rasterizerDiscardEnable = rasterizerDiscardEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthBiasEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthBiasEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBiasEnable);

    Packet_vkCmdSetDepthBiasEnable* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthBiasEnable>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthBiasEnable;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthBiasEnable = depthBiasEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetPrimitiveRestartEnable(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 primitiveRestartEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &primitiveRestartEnable);

    Packet_vkCmdSetPrimitiveRestartEnable* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetPrimitiveRestartEnable>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetPrimitiveRestartEnable;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->primitiveRestartEnable = primitiveRestartEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceBufferMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceBufferMemoryRequirements* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceBufferMemoryRequirements>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceBufferMemoryRequirements;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceImageMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceImageMemoryRequirements* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceImageMemoryRequirements>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceImageMemoryRequirements;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceImageSparseMemoryRequirements(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceImageSparseMemoryRequirements* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceImageSparseMemoryRequirements>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceImageSparseMemoryRequirements;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pSparseMemoryRequirementCount = pSparseMemoryRequirementCount;
    packet->pSparseMemoryRequirements = pSparseMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroySurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroySurfaceKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroySurfaceKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroySurfaceKHR;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->surface = surface;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSurfaceSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pSupported.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceSurfaceSupportKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSurfaceSupportKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSurfaceSupportKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->queueFamilyIndex = queueFamilyIndex;
    packet->surface = surface;
    packet->pSupported = pSupported;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceCapabilities.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->surface = surface;
    packet->pSurfaceCapabilities = pSurfaceCapabilities;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR> pSurfaceFormats;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceFormatCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceSurfaceFormatsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSurfaceFormatsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSurfaceFormatsKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->surface = surface;
    packet->pSurfaceFormatCount = pSurfaceFormatCount;
    packet->pSurfaceFormats = pSurfaceFormats;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pPresentModeCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPresentModes.PreloadDecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceSurfacePresentModesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSurfacePresentModesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSurfacePresentModesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->surface = surface;
    packet->pPresentModeCount = pPresentModeCount;
    packet->pPresentModes = pPresentModes;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateSwapchainKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSwapchain.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateSwapchainKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateSwapchainKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateSwapchainKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSwapchain = pSwapchain;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroySwapchainKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroySwapchainKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroySwapchainKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroySwapchainKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetSwapchainImagesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pSwapchainImageCount;
    HandlePointerDecoder<VkImage> pSwapchainImages;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pSwapchainImageCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSwapchainImages.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetSwapchainImagesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetSwapchainImagesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetSwapchainImagesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->pSwapchainImageCount = pSwapchainImageCount;
    packet->pSwapchainImages = pSwapchainImages;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAcquireNextImageKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pImageIndex.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkAcquireNextImageKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkAcquireNextImageKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAcquireNextImageKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->timeout = timeout;
    packet->semaphore = semaphore;
    packet->fence = fence;
    packet->pImageIndex = pImageIndex;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueuePresentKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkPresentInfoKHR> pPresentInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pPresentInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkQueuePresentKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueuePresentKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueuePresentKHR;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->pPresentInfo = pPresentInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceGroupPresentCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR> pDeviceGroupPresentCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pDeviceGroupPresentCapabilities.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDeviceGroupPresentCapabilitiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceGroupPresentCapabilitiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceGroupPresentCapabilitiesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pDeviceGroupPresentCapabilities = pDeviceGroupPresentCapabilities;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceGroupSurfacePresentModesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId surface;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pModes.PreloadDecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDeviceGroupSurfacePresentModesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceGroupSurfacePresentModesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceGroupSurfacePresentModesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->surface = surface;
    packet->pModes = pModes;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDevicePresentRectanglesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pRectCount;
    StructPointerDecoder<Decoded_VkRect2D> pRects;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pRectCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRects.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDevicePresentRectanglesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDevicePresentRectanglesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDevicePresentRectanglesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->surface = surface;
    packet->pRectCount = pRectCount;
    packet->pRects = pRects;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAcquireNextImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR> pAcquireInfo;
    PointerDecoder<uint32_t> pImageIndex;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAcquireInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageIndex.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkAcquireNextImage2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkAcquireNextImage2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAcquireNextImage2KHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pAcquireInfo = pAcquireInfo;
    packet->pImageIndex = pImageIndex;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceDisplayPropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceDisplayPropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceDisplayPropertiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceDisplayPlanePropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDisplayPlaneSupportedDisplaysKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t planeIndex;
    PointerDecoder<uint32_t> pDisplayCount;
    HandlePointerDecoder<VkDisplayKHR> pDisplays;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeIndex);
    bytes_read += pDisplayCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDisplays.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDisplayPlaneSupportedDisplaysKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDisplayPlaneSupportedDisplaysKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDisplayPlaneSupportedDisplaysKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->planeIndex = planeIndex;
    packet->pDisplayCount = pDisplayCount;
    packet->pDisplays = pDisplays;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDisplayModePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDisplayModePropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDisplayModePropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDisplayModePropertiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->display = display;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDisplayModeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMode.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDisplayModeKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDisplayModeKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDisplayModeKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->display = display;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pMode = pMode;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDisplayPlaneCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCapabilities.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDisplayPlaneCapabilitiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDisplayPlaneCapabilitiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDisplayPlaneCapabilitiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->mode = mode;
    packet->planeIndex = planeIndex;
    packet->pCapabilities = pCapabilities;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDisplayPlaneSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDisplayPlaneSurfaceKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDisplayPlaneSurfaceKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDisplayPlaneSurfaceKHR;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateSharedSwapchainsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCreateInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSwapchains.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateSharedSwapchainsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateSharedSwapchainsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateSharedSwapchainsKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchainCount = swapchainCount;
    packet->pCreateInfos = pCreateInfos;
    packet->pAllocator = pAllocator;
    packet->pSwapchains = pSwapchains;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateXlibSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateXlibSurfaceKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateXlibSurfaceKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateXlibSurfaceKHR;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkGetPhysicalDeviceXlibPresentationSupportKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceXlibPresentationSupportKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceXlibPresentationSupportKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->queueFamilyIndex = queueFamilyIndex;
    packet->dpy = dpy;
    packet->visualID = visualID;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateXcbSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateXcbSurfaceKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateXcbSurfaceKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateXcbSurfaceKHR;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkGetPhysicalDeviceXcbPresentationSupportKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceXcbPresentationSupportKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceXcbPresentationSupportKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->queueFamilyIndex = queueFamilyIndex;
    packet->connection = connection;
    packet->visual_id = visual_id;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateWaylandSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateWaylandSurfaceKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateWaylandSurfaceKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateWaylandSurfaceKHR;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkGetPhysicalDeviceWaylandPresentationSupportKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceWaylandPresentationSupportKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->queueFamilyIndex = queueFamilyIndex;
    packet->display = display;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateAndroidSurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateAndroidSurfaceKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateAndroidSurfaceKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateAndroidSurfaceKHR;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateWin32SurfaceKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateWin32SurfaceKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateWin32SurfaceKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateWin32SurfaceKHR;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceWin32PresentationSupportKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceWin32PresentationSupportKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceWin32PresentationSupportKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->queueFamilyIndex = queueFamilyIndex;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceVideoCapabilitiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR> pVideoProfile;
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR> pCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pVideoProfile.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCapabilities.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceVideoCapabilitiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceVideoCapabilitiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceVideoCapabilitiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pVideoProfile = pVideoProfile;
    packet->pCapabilities = pCapabilities;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceVideoFormatPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR> pVideoFormatInfo;
    PointerDecoder<uint32_t> pVideoFormatPropertyCount;
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR> pVideoFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pVideoFormatInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pVideoFormatPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pVideoFormatProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceVideoFormatPropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceVideoFormatPropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pVideoFormatInfo = pVideoFormatInfo;
    packet->pVideoFormatPropertyCount = pVideoFormatPropertyCount;
    packet->pVideoFormatProperties = pVideoFormatProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateVideoSessionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkVideoSessionKHR> pVideoSession;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pVideoSession.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateVideoSessionKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateVideoSessionKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateVideoSessionKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pVideoSession = pVideoSession;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyVideoSessionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId videoSession;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &videoSession);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyVideoSessionKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyVideoSessionKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyVideoSessionKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->videoSession = videoSession;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetVideoSessionMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId videoSession;
    PointerDecoder<uint32_t> pMemoryRequirementsCount;
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR> pMemoryRequirements;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &videoSession);
    bytes_read += pMemoryRequirementsCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetVideoSessionMemoryRequirementsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetVideoSessionMemoryRequirementsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetVideoSessionMemoryRequirementsKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->videoSession = videoSession;
    packet->pMemoryRequirementsCount = pMemoryRequirementsCount;
    packet->pMemoryRequirements = pMemoryRequirements;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBindVideoSessionMemoryKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pBindSessionMemoryInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkBindVideoSessionMemoryKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkBindVideoSessionMemoryKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBindVideoSessionMemoryKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->videoSession = videoSession;
    packet->bindSessionMemoryInfoCount = bindSessionMemoryInfoCount;
    packet->pBindSessionMemoryInfos = pBindSessionMemoryInfos;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkVideoSessionParametersKHR> pVideoSessionParameters;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pVideoSessionParameters.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateVideoSessionParametersKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateVideoSessionParametersKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateVideoSessionParametersKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pVideoSessionParameters = pVideoSessionParameters;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkUpdateVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId videoSessionParameters;
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR> pUpdateInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &videoSessionParameters);
    bytes_read += pUpdateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkUpdateVideoSessionParametersKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkUpdateVideoSessionParametersKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkUpdateVideoSessionParametersKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->videoSessionParameters = videoSessionParameters;
    packet->pUpdateInfo = pUpdateInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId videoSessionParameters;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &videoSessionParameters);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyVideoSessionParametersKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyVideoSessionParametersKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyVideoSessionParametersKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->videoSessionParameters = videoSessionParameters;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginVideoCodingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR> pBeginInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBeginInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBeginVideoCodingKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginVideoCodingKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginVideoCodingKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pBeginInfo = pBeginInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndVideoCodingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR> pEndCodingInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pEndCodingInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdEndVideoCodingKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndVideoCodingKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndVideoCodingKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pEndCodingInfo = pEndCodingInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdControlVideoCodingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR> pCodingControlInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCodingControlInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdControlVideoCodingKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdControlVideoCodingKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdControlVideoCodingKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pCodingControlInfo = pCodingControlInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDecodeVideoKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR> pDecodeInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pDecodeInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdDecodeVideoKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDecodeVideoKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDecodeVideoKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pDecodeInfo = pDecodeInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginRenderingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderingInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBeginRenderingKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginRenderingKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginRenderingKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pRenderingInfo = pRenderingInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndRenderingKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    Packet_vkCmdEndRenderingKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndRenderingKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndRenderingKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceFeatures2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceFeatures2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceFeatures2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceFeatures2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pFeatures = pFeatures;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceProperties2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceProperties2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceProperties2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pProperties = pProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceFormatProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceFormatProperties2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceFormatProperties2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceFormatProperties2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->format = format;
    packet->pFormatProperties = pFormatProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pImageFormatInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceImageFormatProperties2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceImageFormatProperties2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceImageFormatProperties2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pImageFormatInfo = pImageFormatInfo;
    packet->pImageFormatProperties = pImageFormatProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceQueueFamilyProperties2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceQueueFamilyProperties2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pQueueFamilyPropertyCount = pQueueFamilyPropertyCount;
    packet->pQueueFamilyProperties = pQueueFamilyProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceMemoryProperties2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceMemoryProperties2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceMemoryProperties2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pMemoryProperties = pMemoryProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFormatInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceSparseImageFormatProperties2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pFormatInfo = pFormatInfo;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pPeerMemoryFeatures.PreloadDecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceGroupPeerMemoryFeaturesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceGroupPeerMemoryFeaturesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceGroupPeerMemoryFeaturesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->heapIndex = heapIndex;
    packet->localDeviceIndex = localDeviceIndex;
    packet->remoteDeviceIndex = remoteDeviceIndex;
    packet->pPeerMemoryFeatures = pPeerMemoryFeatures;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDeviceMaskKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceMask);

    Packet_vkCmdSetDeviceMaskKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDeviceMaskKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDeviceMaskKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->deviceMask = deviceMask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDispatchBaseKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDispatchBaseKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDispatchBaseKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDispatchBaseKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->baseGroupX = baseGroupX;
    packet->baseGroupY = baseGroupY;
    packet->baseGroupZ = baseGroupZ;
    packet->groupCountX = groupCountX;
    packet->groupCountY = groupCountY;
    packet->groupCountZ = groupCountZ;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkTrimCommandPoolKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    Packet_vkTrimCommandPoolKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkTrimCommandPoolKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkTrimCommandPoolKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->commandPool = commandPool;
    packet->flags = flags;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkEnumeratePhysicalDeviceGroupsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceGroupCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkEnumeratePhysicalDeviceGroupsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkEnumeratePhysicalDeviceGroupsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkEnumeratePhysicalDeviceGroupsKHR;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pPhysicalDeviceGroupCount = pPhysicalDeviceGroupCount;
    packet->pPhysicalDeviceGroupProperties = pPhysicalDeviceGroupProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalBufferInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalBufferProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceExternalBufferPropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceExternalBufferPropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pExternalBufferInfo = pExternalBufferInfo;
    packet->pExternalBufferProperties = pExternalBufferProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMemoryWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetMemoryWin32HandleKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMemoryWin32HandleKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMemoryWin32HandleKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pGetWin32HandleInfo = pGetWin32HandleInfo;
    packet->pHandle = pHandle;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMemoryWin32HandlePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pMemoryWin32HandleProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetMemoryWin32HandlePropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMemoryWin32HandlePropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMemoryWin32HandlePropertiesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->handleType = handleType;
    packet->handle = handle;
    packet->pMemoryWin32HandleProperties = pMemoryWin32HandleProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMemoryFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFd.PreloadDecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetMemoryFdKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMemoryFdKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMemoryFdKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pGetFdInfo = pGetFdInfo;
    packet->pFd = pFd;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMemoryFdPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pMemoryFdProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetMemoryFdPropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMemoryFdPropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMemoryFdPropertiesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->handleType = handleType;
    packet->fd = fd;
    packet->pMemoryFdProperties = pMemoryFdProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalSemaphoreInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalSemaphoreProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pExternalSemaphoreInfo = pExternalSemaphoreInfo;
    packet->pExternalSemaphoreProperties = pExternalSemaphoreProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkImportSemaphoreWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR> pImportSemaphoreWin32HandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreWin32HandleInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkImportSemaphoreWin32HandleKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkImportSemaphoreWin32HandleKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkImportSemaphoreWin32HandleKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pImportSemaphoreWin32HandleInfo = pImportSemaphoreWin32HandleInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetSemaphoreWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetSemaphoreWin32HandleKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetSemaphoreWin32HandleKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetSemaphoreWin32HandleKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pGetWin32HandleInfo = pGetWin32HandleInfo;
    packet->pHandle = pHandle;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkImportSemaphoreFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR> pImportSemaphoreFdInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreFdInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkImportSemaphoreFdKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkImportSemaphoreFdKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkImportSemaphoreFdKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pImportSemaphoreFdInfo = pImportSemaphoreFdInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetSemaphoreFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFd.PreloadDecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetSemaphoreFdKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetSemaphoreFdKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetSemaphoreFdKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pGetFdInfo = pGetFdInfo;
    packet->pFd = pFd;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdPushDescriptorSetKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pDescriptorWrites.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdPushDescriptorSetKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdPushDescriptorSetKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdPushDescriptorSetKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pipelineBindPoint = pipelineBindPoint;
    packet->layout = layout;
    packet->set = set;
    packet->descriptorWriteCount = descriptorWriteCount;
    packet->pDescriptorWrites = pDescriptorWrites;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDescriptorUpdateTemplateKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorUpdateTemplate.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDescriptorUpdateTemplateKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDescriptorUpdateTemplateKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDescriptorUpdateTemplateKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pDescriptorUpdateTemplate = pDescriptorUpdateTemplate;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyDescriptorUpdateTemplateKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyDescriptorUpdateTemplateKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyDescriptorUpdateTemplateKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyDescriptorUpdateTemplateKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->descriptorUpdateTemplate = descriptorUpdateTemplate;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateRenderPass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkRenderPass> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRenderPass.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateRenderPass2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateRenderPass2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateRenderPass2KHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pRenderPass = pRenderPass;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginRenderPass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSubpassBeginInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBeginRenderPass2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginRenderPass2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginRenderPass2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pRenderPassBegin = pRenderPassBegin;
    packet->pSubpassBeginInfo = pSubpassBeginInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdNextSubpass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfo> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassBeginInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSubpassEndInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdNextSubpass2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdNextSubpass2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdNextSubpass2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pSubpassBeginInfo = pSubpassBeginInfo;
    packet->pSubpassEndInfo = pSubpassEndInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndRenderPass2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassEndInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdEndRenderPass2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndRenderPass2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndRenderPass2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pSubpassEndInfo = pSubpassEndInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetSwapchainStatusKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetSwapchainStatusKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetSwapchainStatusKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetSwapchainStatusKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalFenceInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalFenceProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceExternalFencePropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceExternalFencePropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceExternalFencePropertiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pExternalFenceInfo = pExternalFenceInfo;
    packet->pExternalFenceProperties = pExternalFenceProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkImportFenceWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR> pImportFenceWin32HandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportFenceWin32HandleInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkImportFenceWin32HandleKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkImportFenceWin32HandleKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkImportFenceWin32HandleKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pImportFenceWin32HandleInfo = pImportFenceWin32HandleInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetFenceWin32HandleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t, void*> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetFenceWin32HandleKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetFenceWin32HandleKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetFenceWin32HandleKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pGetWin32HandleInfo = pGetWin32HandleInfo;
    packet->pHandle = pHandle;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkImportFenceFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR> pImportFenceFdInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportFenceFdInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkImportFenceFdKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkImportFenceFdKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkImportFenceFdKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pImportFenceFdInfo = pImportFenceFdInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetFenceFdKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFd.PreloadDecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetFenceFdKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetFenceFdKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetFenceFdKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pGetFdInfo = pGetFdInfo;
    packet->pFd = pFd;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCounterCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCounters.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCounterDescriptions.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->queueFamilyIndex = queueFamilyIndex;
    packet->pCounterCount = pCounterCount;
    packet->pCounters = pCounters;
    packet->pCounterDescriptions = pCounterDescriptions;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR> pPerformanceQueryCreateInfo;
    PointerDecoder<uint32_t> pNumPasses;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPerformanceQueryCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pNumPasses.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pPerformanceQueryCreateInfo = pPerformanceQueryCreateInfo;
    packet->pNumPasses = pNumPasses;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAcquireProfilingLockKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkAcquireProfilingLockKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkAcquireProfilingLockKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAcquireProfilingLockKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkReleaseProfilingLockKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);

    Packet_vkReleaseProfilingLockKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkReleaseProfilingLockKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkReleaseProfilingLockKHR;
    packet->call_info = call_info;
    packet->device = device;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceCapabilities.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceSurfaceCapabilities2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSurfaceCapabilities2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pSurfaceInfo = pSurfaceInfo;
    packet->pSurfaceCapabilities = pSurfaceCapabilities;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR> pSurfaceFormats;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceFormatCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceSurfaceFormats2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSurfaceFormats2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSurfaceFormats2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pSurfaceInfo = pSurfaceInfo;
    packet->pSurfaceFormatCount = pSurfaceFormatCount;
    packet->pSurfaceFormats = pSurfaceFormats;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceDisplayProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceDisplayProperties2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceDisplayProperties2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceDisplayProperties2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceDisplayPlaneProperties2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDisplayModeProperties2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDisplayModeProperties2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDisplayModeProperties2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDisplayModeProperties2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->display = display;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDisplayPlaneCapabilities2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR> pDisplayPlaneInfo;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR> pCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pDisplayPlaneInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCapabilities.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDisplayPlaneCapabilities2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDisplayPlaneCapabilities2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDisplayPlaneCapabilities2KHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pDisplayPlaneInfo = pDisplayPlaneInfo;
    packet->pCapabilities = pCapabilities;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageMemoryRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetImageMemoryRequirements2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageMemoryRequirements2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageMemoryRequirements2KHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetBufferMemoryRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetBufferMemoryRequirements2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetBufferMemoryRequirements2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetBufferMemoryRequirements2KHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageSparseMemoryRequirements2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetImageSparseMemoryRequirements2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageSparseMemoryRequirements2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageSparseMemoryRequirements2KHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pSparseMemoryRequirementCount = pSparseMemoryRequirementCount;
    packet->pSparseMemoryRequirements = pSparseMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateSamplerYcbcrConversionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pYcbcrConversion.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateSamplerYcbcrConversionKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateSamplerYcbcrConversionKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateSamplerYcbcrConversionKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pYcbcrConversion = pYcbcrConversion;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroySamplerYcbcrConversionKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ycbcrConversion);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroySamplerYcbcrConversionKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroySamplerYcbcrConversionKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroySamplerYcbcrConversionKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->ycbcrConversion = ycbcrConversion;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBindBufferMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkBindBufferMemory2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkBindBufferMemory2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBindBufferMemory2KHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->bindInfoCount = bindInfoCount;
    packet->pBindInfos = pBindInfos;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBindImageMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkBindImageMemory2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkBindImageMemory2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBindImageMemory2KHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->bindInfoCount = bindInfoCount;
    packet->pBindInfos = pBindInfos;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDescriptorSetLayoutSupportKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSupport.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDescriptorSetLayoutSupportKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDescriptorSetLayoutSupportKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDescriptorSetLayoutSupportKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pSupport = pSupport;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawIndirectCountKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawIndirectCountKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawIndirectCountKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawIndirectCountKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->countBuffer = countBuffer;
    packet->countBufferOffset = countBufferOffset;
    packet->maxDrawCount = maxDrawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawIndexedIndirectCountKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawIndexedIndirectCountKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawIndexedIndirectCountKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawIndexedIndirectCountKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->countBuffer = countBuffer;
    packet->countBufferOffset = countBufferOffset;
    packet->maxDrawCount = maxDrawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetSemaphoreCounterValueKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId semaphore;
    PointerDecoder<uint64_t> pValue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += pValue.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetSemaphoreCounterValueKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetSemaphoreCounterValueKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetSemaphoreCounterValueKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->semaphore = semaphore;
    packet->pValue = pValue;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkWaitSemaphoresKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo> pWaitInfo;
    uint64_t timeout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pWaitInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkWaitSemaphoresKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkWaitSemaphoresKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkWaitSemaphoresKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pWaitInfo = pWaitInfo;
    packet->timeout = timeout;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSignalSemaphoreKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo> pSignalInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pSignalInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkSignalSemaphoreKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkSignalSemaphoreKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSignalSemaphoreKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pSignalInfo = pSignalInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceFragmentShadingRatesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pFragmentShadingRateCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR> pFragmentShadingRates;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFragmentShadingRateCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFragmentShadingRates.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceFragmentShadingRatesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceFragmentShadingRatesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceFragmentShadingRatesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pFragmentShadingRateCount = pFragmentShadingRateCount;
    packet->pFragmentShadingRates = pFragmentShadingRates;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetFragmentShadingRateKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkExtent2D> pFragmentSize;
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pFragmentSize.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += combinerOps.PreloadDecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetFragmentShadingRateKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetFragmentShadingRateKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetFragmentShadingRateKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pFragmentSize = pFragmentSize;
    packet->combinerOps = combinerOps;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetRenderingAttachmentLocationsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfoKHR> pLocationInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLocationInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetRenderingAttachmentLocationsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetRenderingAttachmentLocationsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetRenderingAttachmentLocationsKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pLocationInfo = pLocationInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetRenderingInputAttachmentIndicesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfoKHR> pInputAttachmentIndexInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInputAttachmentIndexInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetRenderingInputAttachmentIndicesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetRenderingInputAttachmentIndicesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetRenderingInputAttachmentIndicesKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pInputAttachmentIndexInfo = pInputAttachmentIndexInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkWaitForPresentKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkWaitForPresentKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkWaitForPresentKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkWaitForPresentKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->presentId = presentId;
    packet->timeout = timeout;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetBufferDeviceAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetBufferDeviceAddressKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetBufferDeviceAddressKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetBufferDeviceAddressKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetBufferOpaqueCaptureAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    uint64_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetBufferOpaqueCaptureAddressKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetBufferOpaqueCaptureAddressKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetBufferOpaqueCaptureAddressKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceMemoryOpaqueCaptureAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo> pInfo;
    uint64_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDeviceMemoryOpaqueCaptureAddressKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceMemoryOpaqueCaptureAddressKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDeferredOperationKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDeferredOperationKHR> pDeferredOperation;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDeferredOperation.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDeferredOperationKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDeferredOperationKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDeferredOperationKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pAllocator = pAllocator;
    packet->pDeferredOperation = pDeferredOperation;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyDeferredOperationKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId operation;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &operation);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyDeferredOperationKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyDeferredOperationKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyDeferredOperationKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->operation = operation;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeferredOperationMaxConcurrencyKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId operation;
    uint32_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &operation);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDeferredOperationMaxConcurrencyKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeferredOperationMaxConcurrencyKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeferredOperationMaxConcurrencyKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->operation = operation;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeferredOperationResultKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId operation;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &operation);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDeferredOperationResultKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeferredOperationResultKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeferredOperationResultKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->operation = operation;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPipelineExecutablePropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineInfoKHR> pPipelineInfo;
    PointerDecoder<uint32_t> pExecutableCount;
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pPipelineInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExecutableCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPipelineExecutablePropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPipelineExecutablePropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPipelineExecutablePropertiesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pPipelineInfo = pPipelineInfo;
    packet->pExecutableCount = pExecutableCount;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPipelineExecutableStatisticsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR> pExecutableInfo;
    PointerDecoder<uint32_t> pStatisticCount;
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR> pStatistics;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pExecutableInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pStatisticCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pStatistics.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPipelineExecutableStatisticsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPipelineExecutableStatisticsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPipelineExecutableStatisticsKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pExecutableInfo = pExecutableInfo;
    packet->pStatisticCount = pStatisticCount;
    packet->pStatistics = pStatistics;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPipelineExecutableInternalRepresentationsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR> pExecutableInfo;
    PointerDecoder<uint32_t> pInternalRepresentationCount;
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR> pInternalRepresentations;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pExecutableInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInternalRepresentationCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInternalRepresentations.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPipelineExecutableInternalRepresentationsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPipelineExecutableInternalRepresentationsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPipelineExecutableInternalRepresentationsKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pExecutableInfo = pExecutableInfo;
    packet->pInternalRepresentationCount = pInternalRepresentationCount;
    packet->pInternalRepresentations = pInternalRepresentations;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkMapMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryMapInfoKHR> pMemoryMapInfo;
    PointerDecoder<uint64_t, void*> ppData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pMemoryMapInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppData.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkMapMemory2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkMapMemory2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkMapMemory2KHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pMemoryMapInfo = pMemoryMapInfo;
    packet->ppData = ppData;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkUnmapMemory2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryUnmapInfoKHR> pMemoryUnmapInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pMemoryUnmapInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkUnmapMemory2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkUnmapMemory2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkUnmapMemory2KHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pMemoryUnmapInfo = pMemoryUnmapInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR> pQualityLevelInfo;
    StructPointerDecoder<Decoded_VkVideoEncodeQualityLevelPropertiesKHR> pQualityLevelProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQualityLevelInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQualityLevelProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pQualityLevelInfo = pQualityLevelInfo;
    packet->pQualityLevelProperties = pQualityLevelProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetEncodedVideoSessionParametersKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersGetInfoKHR> pVideoSessionParametersInfo;
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR> pFeedbackInfo;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pVideoSessionParametersInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFeedbackInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDataSize.PreloadDecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetEncodedVideoSessionParametersKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetEncodedVideoSessionParametersKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetEncodedVideoSessionParametersKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pVideoSessionParametersInfo = pVideoSessionParametersInfo;
    packet->pFeedbackInfo = pFeedbackInfo;
    packet->pDataSize = pDataSize;
    packet->pData = pData;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEncodeVideoKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR> pEncodeInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pEncodeInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdEncodeVideoKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEncodeVideoKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEncodeVideoKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pEncodeInfo = pEncodeInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetEvent2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += pDependencyInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetEvent2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetEvent2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetEvent2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->event = event;
    packet->pDependencyInfo = pDependencyInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdResetEvent2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags2 stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlags64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageMask);

    Packet_vkCmdResetEvent2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdResetEvent2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdResetEvent2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->event = event;
    packet->stageMask = stageMask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWaitEvents2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t eventCount;
    HandlePointerDecoder<VkEvent> pEvents;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfos;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &eventCount);
    bytes_read += pEvents.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDependencyInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdWaitEvents2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWaitEvents2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWaitEvents2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->eventCount = eventCount;
    packet->pEvents = pEvents;
    packet->pDependencyInfos = pDependencyInfos;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdPipelineBarrier2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDependencyInfo> pDependencyInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pDependencyInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdPipelineBarrier2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdPipelineBarrier2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdPipelineBarrier2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pDependencyInfo = pDependencyInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWriteTimestamp2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdWriteTimestamp2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWriteTimestamp2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWriteTimestamp2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->stage = stage;
    packet->queryPool = queryPool;
    packet->query = query;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueueSubmit2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo2> pSubmits;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &submitCount);
    bytes_read += pSubmits.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkQueueSubmit2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueueSubmit2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueueSubmit2KHR;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->submitCount = submitCount;
    packet->pSubmits = pSubmits;
    packet->fence = fence;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWriteBufferMarker2AMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdWriteBufferMarker2AMD* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWriteBufferMarker2AMD>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWriteBufferMarker2AMD;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->stage = stage;
    packet->dstBuffer = dstBuffer;
    packet->dstOffset = dstOffset;
    packet->marker = marker;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetQueueCheckpointData2NV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    PointerDecoder<uint32_t> pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointData2NV> pCheckpointData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pCheckpointDataCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCheckpointData.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetQueueCheckpointData2NV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetQueueCheckpointData2NV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetQueueCheckpointData2NV;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->pCheckpointDataCount = pCheckpointDataCount;
    packet->pCheckpointData = pCheckpointData;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyBuffer2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferInfo2> pCopyBufferInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyBufferInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyBuffer2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyBuffer2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyBuffer2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pCopyBufferInfo = pCopyBufferInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageInfo2> pCopyImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyImageInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyImage2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyImage2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyImage2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pCopyImageInfo = pCopyImageInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyBufferToImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2> pCopyBufferToImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyBufferToImageInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyBufferToImage2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyBufferToImage2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyBufferToImage2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pCopyBufferToImageInfo = pCopyBufferToImageInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyImageToBuffer2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2> pCopyImageToBufferInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pCopyImageToBufferInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyImageToBuffer2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyImageToBuffer2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyImageToBuffer2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pCopyImageToBufferInfo = pCopyImageToBufferInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBlitImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBlitImageInfo2> pBlitImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBlitImageInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBlitImage2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBlitImage2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBlitImage2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pBlitImageInfo = pBlitImageInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdResolveImage2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkResolveImageInfo2> pResolveImageInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pResolveImageInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdResolveImage2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdResolveImage2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdResolveImage2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pResolveImageInfo = pResolveImageInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdTraceRaysIndirect2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkDeviceAddress indirectDeviceAddress;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indirectDeviceAddress);

    Packet_vkCmdTraceRaysIndirect2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdTraceRaysIndirect2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdTraceRaysIndirect2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->indirectDeviceAddress = indirectDeviceAddress;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceBufferMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceBufferMemoryRequirementsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceBufferMemoryRequirementsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceBufferMemoryRequirementsKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceImageMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceImageMemoryRequirementsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceImageMemoryRequirementsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceImageMemoryRequirementsKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceImageSparseMemoryRequirementsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceImageSparseMemoryRequirementsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceImageSparseMemoryRequirementsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceImageSparseMemoryRequirementsKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pSparseMemoryRequirementCount = pSparseMemoryRequirementCount;
    packet->pSparseMemoryRequirements = pSparseMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindIndexBuffer2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdBindIndexBuffer2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindIndexBuffer2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindIndexBuffer2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->size = size;
    packet->indexType = indexType;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetRenderingAreaGranularityKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderingAreaInfoKHR> pRenderingAreaInfo;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pRenderingAreaInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pGranularity.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetRenderingAreaGranularityKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetRenderingAreaGranularityKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetRenderingAreaGranularityKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pRenderingAreaInfo = pRenderingAreaInfo;
    packet->pGranularity = pGranularity;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceImageSubresourceLayoutKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfoKHR> pInfo;
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR> pLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pLayout.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceImageSubresourceLayoutKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceImageSubresourceLayoutKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceImageSubresourceLayoutKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pLayout = pLayout;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageSubresourceLayout2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource2KHR> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR> pLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pSubresource.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pLayout.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetImageSubresourceLayout2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageSubresourceLayout2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageSubresourceLayout2KHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->image = image;
    packet->pSubresource = pSubresource;
    packet->pLayout = pLayout;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetLineStippleKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineStippleFactor);
    bytes_read += ValueDecoder::DecodeUInt16Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineStipplePattern);

    Packet_vkCmdSetLineStippleKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetLineStippleKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetLineStippleKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->lineStippleFactor = lineStippleFactor;
    packet->lineStipplePattern = lineStipplePattern;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pTimeDomainCount;
    PointerDecoder<VkTimeDomainKHR> pTimeDomains;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pTimeDomainCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTimeDomains.PreloadDecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pTimeDomainCount = pTimeDomainCount;
    packet->pTimeDomains = pTimeDomains;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetCalibratedTimestampsKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pTimestampInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTimestamps.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMaxDeviation.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetCalibratedTimestampsKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetCalibratedTimestampsKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetCalibratedTimestampsKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->timestampCount = timestampCount;
    packet->pTimestampInfos = pTimestampInfos;
    packet->pTimestamps = pTimestamps;
    packet->pMaxDeviation = pMaxDeviation;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindDescriptorSets2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfoKHR> pBindDescriptorSetsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBindDescriptorSetsInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBindDescriptorSets2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindDescriptorSets2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindDescriptorSets2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pBindDescriptorSetsInfo = pBindDescriptorSetsInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdPushConstants2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushConstantsInfoKHR> pPushConstantsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pPushConstantsInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdPushConstants2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdPushConstants2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdPushConstants2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pPushConstantsInfo = pPushConstantsInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdPushDescriptorSet2KHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfoKHR> pPushDescriptorSetInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pPushDescriptorSetInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdPushDescriptorSet2KHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdPushDescriptorSet2KHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdPushDescriptorSet2KHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pPushDescriptorSetInfo = pPushDescriptorSetInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDescriptorBufferOffsets2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT> pSetDescriptorBufferOffsetsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSetDescriptorBufferOffsetsInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetDescriptorBufferOffsets2EXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDescriptorBufferOffsets2EXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDescriptorBufferOffsets2EXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pSetDescriptorBufferOffsetsInfo = pSetDescriptorBufferOffsetsInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT> pBindDescriptorBufferEmbeddedSamplersInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBindDescriptorBufferEmbeddedSamplersInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pBindDescriptorBufferEmbeddedSamplersInfo = pBindDescriptorBufferEmbeddedSamplersInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkFrameBoundaryANDROID(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId semaphore;
    format::HandleId image;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);

    Packet_vkFrameBoundaryANDROID* packet = PreloadDecodeAllocator::Allocate<Packet_vkFrameBoundaryANDROID>();
    packet->packet_id = gfxrecon::format::PacketCall_vkFrameBoundaryANDROID;
    packet->call_info = call_info;
    packet->device = device;
    packet->semaphore = semaphore;
    packet->image = image;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDebugReportCallbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDebugReportCallbackEXT> pCallback;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCallback.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDebugReportCallbackEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDebugReportCallbackEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDebugReportCallbackEXT;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pCallback = pCallback;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyDebugReportCallbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId callback;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callback);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyDebugReportCallbackEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyDebugReportCallbackEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyDebugReportCallbackEXT;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->callback = callback;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDebugReportMessageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pLayerPrefix.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMessage.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDebugReportMessageEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkDebugReportMessageEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDebugReportMessageEXT;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->flags = flags;
    packet->objectType = objectType;
    packet->object = object;
    packet->location = location;
    packet->messageCode = messageCode;
    packet->pLayerPrefix = pLayerPrefix;
    packet->pMessage = pMessage;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDebugMarkerSetObjectTagEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT> pTagInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pTagInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkDebugMarkerSetObjectTagEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkDebugMarkerSetObjectTagEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDebugMarkerSetObjectTagEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pTagInfo = pTagInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDebugMarkerSetObjectNameEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT> pNameInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pNameInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkDebugMarkerSetObjectNameEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkDebugMarkerSetObjectNameEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDebugMarkerSetObjectNameEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pNameInfo = pNameInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDebugMarkerBeginEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdDebugMarkerBeginEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDebugMarkerBeginEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDebugMarkerBeginEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pMarkerInfo = pMarkerInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDebugMarkerEndEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    Packet_vkCmdDebugMarkerEndEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDebugMarkerEndEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDebugMarkerEndEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDebugMarkerInsertEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdDebugMarkerInsertEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDebugMarkerInsertEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDebugMarkerInsertEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pMarkerInfo = pMarkerInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindTransformFeedbackBuffersEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pBuffers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pOffsets.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizes.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBindTransformFeedbackBuffersEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindTransformFeedbackBuffersEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindTransformFeedbackBuffersEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstBinding = firstBinding;
    packet->bindingCount = bindingCount;
    packet->pBuffers = pBuffers;
    packet->pOffsets = pOffsets;
    packet->pSizes = pSizes;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginTransformFeedbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCounterBuffers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCounterBufferOffsets.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBeginTransformFeedbackEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginTransformFeedbackEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginTransformFeedbackEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstCounterBuffer = firstCounterBuffer;
    packet->counterBufferCount = counterBufferCount;
    packet->pCounterBuffers = pCounterBuffers;
    packet->pCounterBufferOffsets = pCounterBufferOffsets;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndTransformFeedbackEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCounterBuffers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCounterBufferOffsets.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdEndTransformFeedbackEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndTransformFeedbackEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndTransformFeedbackEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstCounterBuffer = firstCounterBuffer;
    packet->counterBufferCount = counterBufferCount;
    packet->pCounterBuffers = pCounterBuffers;
    packet->pCounterBufferOffsets = pCounterBufferOffsets;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginQueryIndexedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdBeginQueryIndexedEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginQueryIndexedEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginQueryIndexedEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->queryPool = queryPool;
    packet->query = query;
    packet->flags = flags;
    packet->index = index;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndQueryIndexedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdEndQueryIndexedEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndQueryIndexedEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndQueryIndexedEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->queryPool = queryPool;
    packet->query = query;
    packet->index = index;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawIndirectByteCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawIndirectByteCountEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawIndirectByteCountEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawIndirectByteCountEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->instanceCount = instanceCount;
    packet->firstInstance = firstInstance;
    packet->counterBuffer = counterBuffer;
    packet->counterBufferOffset = counterBufferOffset;
    packet->counterOffset = counterOffset;
    packet->vertexStride = vertexStride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageViewHandleNVX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX> pInfo;
    uint32_t return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetImageViewHandleNVX* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageViewHandleNVX>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageViewHandleNVX;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageViewAddressNVX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId imageView;
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageView);
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetImageViewAddressNVX* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageViewAddressNVX>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageViewAddressNVX;
    packet->call_info = call_info;
    packet->device = device;
    packet->imageView = imageView;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawIndirectCountAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawIndirectCountAMD* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawIndirectCountAMD>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawIndirectCountAMD;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->countBuffer = countBuffer;
    packet->countBufferOffset = countBufferOffset;
    packet->maxDrawCount = maxDrawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawIndexedIndirectCountAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawIndexedIndirectCountAMD* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawIndexedIndirectCountAMD>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawIndexedIndirectCountAMD;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->countBuffer = countBuffer;
    packet->countBufferOffset = countBufferOffset;
    packet->maxDrawCount = maxDrawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetShaderInfoAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pInfoSize.PreloadDecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInfo.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetShaderInfoAMD* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetShaderInfoAMD>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetShaderInfoAMD;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipeline = pipeline;
    packet->shaderStage = shaderStage;
    packet->infoType = infoType;
    packet->pInfoSize = pInfoSize;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateStreamDescriptorSurfaceGGP(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateStreamDescriptorSurfaceGGP* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateStreamDescriptorSurfaceGGP>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateStreamDescriptorSurfaceGGP;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pExternalImageFormatProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceExternalImageFormatPropertiesNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->format = format;
    packet->type = type;
    packet->tiling = tiling;
    packet->usage = usage;
    packet->flags = flags;
    packet->externalHandleType = externalHandleType;
    packet->pExternalImageFormatProperties = pExternalImageFormatProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMemoryWin32HandleNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkGetMemoryWin32HandleNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMemoryWin32HandleNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMemoryWin32HandleNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->memory = memory;
    packet->handleType = handleType;
    packet->pHandle = pHandle;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateViSurfaceNN(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateViSurfaceNN* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateViSurfaceNN>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateViSurfaceNN;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginConditionalRenderingEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT> pConditionalRenderingBegin;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pConditionalRenderingBegin.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBeginConditionalRenderingEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginConditionalRenderingEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginConditionalRenderingEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pConditionalRenderingBegin = pConditionalRenderingBegin;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndConditionalRenderingEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    Packet_vkCmdEndConditionalRenderingEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndConditionalRenderingEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndConditionalRenderingEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetViewportWScalingNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportWScalingNV> pViewportWScalings;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewportWScalings.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetViewportWScalingNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetViewportWScalingNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetViewportWScalingNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstViewport = firstViewport;
    packet->viewportCount = viewportCount;
    packet->pViewportWScalings = pViewportWScalings;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkReleaseDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkReleaseDisplayEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkReleaseDisplayEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkReleaseDisplayEXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->display = display;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAcquireXlibDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkAcquireXlibDisplayEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkAcquireXlibDisplayEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAcquireXlibDisplayEXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->dpy = dpy;
    packet->display = display;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetRandROutputDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pDisplay.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetRandROutputDisplayEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetRandROutputDisplayEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetRandROutputDisplayEXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->dpy = dpy;
    packet->rrOutput = rrOutput;
    packet->pDisplay = pDisplay;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceCapabilities.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceSurfaceCapabilities2EXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSurfaceCapabilities2EXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->surface = surface;
    packet->pSurfaceCapabilities = pSurfaceCapabilities;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDisplayPowerControlEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT> pDisplayPowerInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pDisplayPowerInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkDisplayPowerControlEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkDisplayPowerControlEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDisplayPowerControlEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->display = display;
    packet->pDisplayPowerInfo = pDisplayPowerInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkRegisterDeviceEventEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT> pDeviceEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkFence> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pDeviceEventInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFence.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkRegisterDeviceEventEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkRegisterDeviceEventEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkRegisterDeviceEventEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pDeviceEventInfo = pDeviceEventInfo;
    packet->pAllocator = pAllocator;
    packet->pFence = pFence;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkRegisterDisplayEventEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pDisplayEventInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFence.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkRegisterDisplayEventEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkRegisterDisplayEventEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkRegisterDisplayEventEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->display = display;
    packet->pDisplayEventInfo = pDisplayEventInfo;
    packet->pAllocator = pAllocator;
    packet->pFence = pFence;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetSwapchainCounterEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCounterValue.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetSwapchainCounterEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetSwapchainCounterEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetSwapchainCounterEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->counter = counter;
    packet->pCounterValue = pCounterValue;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetRefreshCycleDurationGOOGLE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE> pDisplayTimingProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pDisplayTimingProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetRefreshCycleDurationGOOGLE* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetRefreshCycleDurationGOOGLE>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetRefreshCycleDurationGOOGLE;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->pDisplayTimingProperties = pDisplayTimingProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPastPresentationTimingGOOGLE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pPresentationTimingCount;
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE> pPresentationTimings;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pPresentationTimingCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPresentationTimings.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPastPresentationTimingGOOGLE* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPastPresentationTimingGOOGLE>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPastPresentationTimingGOOGLE;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->pPresentationTimingCount = pPresentationTimingCount;
    packet->pPresentationTimings = pPresentationTimings;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDiscardRectangleEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstDiscardRectangle;
    uint32_t discardRectangleCount;
    StructPointerDecoder<Decoded_VkRect2D> pDiscardRectangles;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstDiscardRectangle);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &discardRectangleCount);
    bytes_read += pDiscardRectangles.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetDiscardRectangleEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDiscardRectangleEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDiscardRectangleEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstDiscardRectangle = firstDiscardRectangle;
    packet->discardRectangleCount = discardRectangleCount;
    packet->pDiscardRectangles = pDiscardRectangles;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDiscardRectangleEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 discardRectangleEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &discardRectangleEnable);

    Packet_vkCmdSetDiscardRectangleEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDiscardRectangleEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDiscardRectangleEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->discardRectangleEnable = discardRectangleEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDiscardRectangleModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkDiscardRectangleModeEXT discardRectangleMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &discardRectangleMode);

    Packet_vkCmdSetDiscardRectangleModeEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDiscardRectangleModeEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDiscardRectangleModeEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->discardRectangleMode = discardRectangleMode;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSetHdrMetadataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t swapchainCount;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchains;
    StructPointerDecoder<Decoded_VkHdrMetadataEXT> pMetadata;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchainCount);
    bytes_read += pSwapchains.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMetadata.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkSetHdrMetadataEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkSetHdrMetadataEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSetHdrMetadataEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchainCount = swapchainCount;
    packet->pSwapchains = pSwapchains;
    packet->pMetadata = pMetadata;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateIOSSurfaceMVK(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateIOSSurfaceMVK* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateIOSSurfaceMVK>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateIOSSurfaceMVK;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateMacOSSurfaceMVK(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateMacOSSurfaceMVK* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateMacOSSurfaceMVK>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateMacOSSurfaceMVK;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSetDebugUtilsObjectNameEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT> pNameInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pNameInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkSetDebugUtilsObjectNameEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkSetDebugUtilsObjectNameEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSetDebugUtilsObjectNameEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pNameInfo = pNameInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSetDebugUtilsObjectTagEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT> pTagInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pTagInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkSetDebugUtilsObjectTagEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkSetDebugUtilsObjectTagEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSetDebugUtilsObjectTagEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pTagInfo = pTagInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueueBeginDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkQueueBeginDebugUtilsLabelEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueueBeginDebugUtilsLabelEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueueBeginDebugUtilsLabelEXT;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->pLabelInfo = pLabelInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueueEndDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);

    Packet_vkQueueEndDebugUtilsLabelEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueueEndDebugUtilsLabelEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueueEndDebugUtilsLabelEXT;
    packet->call_info = call_info;
    packet->queue = queue;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueueInsertDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkQueueInsertDebugUtilsLabelEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueueInsertDebugUtilsLabelEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueueInsertDebugUtilsLabelEXT;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->pLabelInfo = pLabelInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBeginDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBeginDebugUtilsLabelEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBeginDebugUtilsLabelEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBeginDebugUtilsLabelEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pLabelInfo = pLabelInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdEndDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    Packet_vkCmdEndDebugUtilsLabelEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdEndDebugUtilsLabelEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdEndDebugUtilsLabelEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdInsertDebugUtilsLabelEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdInsertDebugUtilsLabelEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdInsertDebugUtilsLabelEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdInsertDebugUtilsLabelEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pLabelInfo = pLabelInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDebugUtilsMessengerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkDebugUtilsMessengerEXT> pMessenger;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMessenger.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDebugUtilsMessengerEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDebugUtilsMessengerEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDebugUtilsMessengerEXT;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pMessenger = pMessenger;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyDebugUtilsMessengerEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId messenger;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messenger);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyDebugUtilsMessengerEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyDebugUtilsMessengerEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyDebugUtilsMessengerEXT;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->messenger = messenger;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSubmitDebugUtilsMessageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity;
    VkDebugUtilsMessageTypeFlagsEXT messageTypes;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT> pCallbackData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messageSeverity);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messageTypes);
    bytes_read += pCallbackData.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkSubmitDebugUtilsMessageEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkSubmitDebugUtilsMessageEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSubmitDebugUtilsMessageEXT;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->messageSeverity = messageSeverity;
    packet->messageTypes = messageTypes;
    packet->pCallbackData = pCallbackData;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetAndroidHardwareBufferPropertiesANDROID(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint64_t buffer;
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetAndroidHardwareBufferPropertiesANDROID* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetAndroidHardwareBufferPropertiesANDROID>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetAndroidHardwareBufferPropertiesANDROID;
    packet->call_info = call_info;
    packet->device = device;
    packet->buffer = buffer;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMemoryAndroidHardwareBufferANDROID(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID> pInfo;
    PointerDecoder<uint64_t, void*> pBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pBuffer.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetMemoryAndroidHardwareBufferANDROID* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMemoryAndroidHardwareBufferANDROID>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMemoryAndroidHardwareBufferANDROID;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pBuffer = pBuffer;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetSampleLocationsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT> pSampleLocationsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSampleLocationsInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetSampleLocationsEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetSampleLocationsEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetSampleLocationsEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pSampleLocationsInfo = pSampleLocationsInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkSampleCountFlagBits samples;
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT> pMultisampleProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &samples);
    bytes_read += pMultisampleProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPhysicalDeviceMultisamplePropertiesEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceMultisamplePropertiesEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceMultisamplePropertiesEXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->samples = samples;
    packet->pMultisampleProperties = pMultisampleProperties;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageDrmFormatModifierPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetImageDrmFormatModifierPropertiesEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageDrmFormatModifierPropertiesEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageDrmFormatModifierPropertiesEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->image = image;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateValidationCacheEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkValidationCacheEXT> pValidationCache;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pValidationCache.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateValidationCacheEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateValidationCacheEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateValidationCacheEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pValidationCache = pValidationCache;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyValidationCacheEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId validationCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &validationCache);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyValidationCacheEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyValidationCacheEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyValidationCacheEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->validationCache = validationCache;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkMergeValidationCachesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pSrcCaches.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkMergeValidationCachesEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkMergeValidationCachesEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkMergeValidationCachesEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->dstCache = dstCache;
    packet->srcCacheCount = srcCacheCount;
    packet->pSrcCaches = pSrcCaches;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetValidationCacheDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId validationCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &validationCache);
    bytes_read += pDataSize.PreloadDecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetValidationCacheDataEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetValidationCacheDataEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetValidationCacheDataEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->validationCache = validationCache;
    packet->pDataSize = pDataSize;
    packet->pData = pData;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindShadingRateImageNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId imageView;
    VkImageLayout imageLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageView);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageLayout);

    Packet_vkCmdBindShadingRateImageNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindShadingRateImageNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindShadingRateImageNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->imageView = imageView;
    packet->imageLayout = imageLayout;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetViewportShadingRatePaletteNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV> pShadingRatePalettes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pShadingRatePalettes.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetViewportShadingRatePaletteNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetViewportShadingRatePaletteNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetViewportShadingRatePaletteNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstViewport = firstViewport;
    packet->viewportCount = viewportCount;
    packet->pShadingRatePalettes = pShadingRatePalettes;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetCoarseSampleOrderNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCoarseSampleOrderTypeNV sampleOrderType;
    uint32_t customSampleOrderCount;
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV> pCustomSampleOrders;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sampleOrderType);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &customSampleOrderCount);
    bytes_read += pCustomSampleOrders.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetCoarseSampleOrderNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetCoarseSampleOrderNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetCoarseSampleOrderNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->sampleOrderType = sampleOrderType;
    packet->customSampleOrderCount = customSampleOrderCount;
    packet->pCustomSampleOrders = pCustomSampleOrders;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructure;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAccelerationStructure.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateAccelerationStructureNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateAccelerationStructureNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateAccelerationStructureNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pAccelerationStructure = pAccelerationStructure;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &accelerationStructure);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyAccelerationStructureNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyAccelerationStructureNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyAccelerationStructureNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->accelerationStructure = accelerationStructure;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetAccelerationStructureMemoryRequirementsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetAccelerationStructureMemoryRequirementsNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetAccelerationStructureMemoryRequirementsNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetAccelerationStructureMemoryRequirementsNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBindAccelerationStructureMemoryNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkBindAccelerationStructureMemoryNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkBindAccelerationStructureMemoryNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBindAccelerationStructureMemoryNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->bindInfoCount = bindInfoCount;
    packet->pBindInfos = pBindInfos;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBuildAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceData);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &update);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dst);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &src);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scratch);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scratchOffset);

    Packet_vkCmdBuildAccelerationStructureNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBuildAccelerationStructureNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBuildAccelerationStructureNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pInfo = pInfo;
    packet->instanceData = instanceData;
    packet->instanceOffset = instanceOffset;
    packet->update = update;
    packet->dst = dst;
    packet->src = src;
    packet->scratch = scratch;
    packet->scratchOffset = scratchOffset;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyAccelerationStructureNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdCopyAccelerationStructureNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyAccelerationStructureNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyAccelerationStructureNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->dst = dst;
    packet->src = src;
    packet->mode = mode;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdTraceRaysNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdTraceRaysNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdTraceRaysNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdTraceRaysNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->raygenShaderBindingTableBuffer = raygenShaderBindingTableBuffer;
    packet->raygenShaderBindingOffset = raygenShaderBindingOffset;
    packet->missShaderBindingTableBuffer = missShaderBindingTableBuffer;
    packet->missShaderBindingOffset = missShaderBindingOffset;
    packet->missShaderBindingStride = missShaderBindingStride;
    packet->hitShaderBindingTableBuffer = hitShaderBindingTableBuffer;
    packet->hitShaderBindingOffset = hitShaderBindingOffset;
    packet->hitShaderBindingStride = hitShaderBindingStride;
    packet->callableShaderBindingTableBuffer = callableShaderBindingTableBuffer;
    packet->callableShaderBindingOffset = callableShaderBindingOffset;
    packet->callableShaderBindingStride = callableShaderBindingStride;
    packet->width = width;
    packet->height = height;
    packet->depth = depth;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateRayTracingPipelinesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCreateInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelines.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateRayTracingPipelinesNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateRayTracingPipelinesNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateRayTracingPipelinesNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipelineCache = pipelineCache;
    packet->createInfoCount = createInfoCount;
    packet->pCreateInfos = pCreateInfos;
    packet->pAllocator = pAllocator;
    packet->pPipelines = pPipelines;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetRayTracingShaderGroupHandlesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetRayTracingShaderGroupHandlesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetRayTracingShaderGroupHandlesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetRayTracingShaderGroupHandlesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipeline = pipeline;
    packet->firstGroup = firstGroup;
    packet->groupCount = groupCount;
    packet->dataSize = dataSize;
    packet->pData = pData;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetRayTracingShaderGroupHandlesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetRayTracingShaderGroupHandlesNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetRayTracingShaderGroupHandlesNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetRayTracingShaderGroupHandlesNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipeline = pipeline;
    packet->firstGroup = firstGroup;
    packet->groupCount = groupCount;
    packet->dataSize = dataSize;
    packet->pData = pData;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetAccelerationStructureHandleNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetAccelerationStructureHandleNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetAccelerationStructureHandleNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetAccelerationStructureHandleNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->accelerationStructure = accelerationStructure;
    packet->dataSize = dataSize;
    packet->pData = pData;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWriteAccelerationStructuresPropertiesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pAccelerationStructures.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);

    Packet_vkCmdWriteAccelerationStructuresPropertiesNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWriteAccelerationStructuresPropertiesNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWriteAccelerationStructuresPropertiesNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->accelerationStructureCount = accelerationStructureCount;
    packet->pAccelerationStructures = pAccelerationStructures;
    packet->queryType = queryType;
    packet->queryPool = queryPool;
    packet->firstQuery = firstQuery;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCompileDeferredNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCompileDeferredNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCompileDeferredNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCompileDeferredNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipeline = pipeline;
    packet->shader = shader;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMemoryHostPointerPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pMemoryHostPointerProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetMemoryHostPointerPropertiesEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMemoryHostPointerPropertiesEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMemoryHostPointerPropertiesEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->handleType = handleType;
    packet->pHostPointer = pHostPointer;
    packet->pMemoryHostPointerProperties = pMemoryHostPointerProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWriteBufferMarkerAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdWriteBufferMarkerAMD* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWriteBufferMarkerAMD>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWriteBufferMarkerAMD;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pipelineStage = pipelineStage;
    packet->dstBuffer = dstBuffer;
    packet->dstOffset = dstOffset;
    packet->marker = marker;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pTimeDomainCount;
    PointerDecoder<VkTimeDomainKHR> pTimeDomains;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pTimeDomainCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTimeDomains.PreloadDecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pTimeDomainCount = pTimeDomainCount;
    packet->pTimeDomains = pTimeDomains;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetCalibratedTimestampsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pTimestampInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTimestamps.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMaxDeviation.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetCalibratedTimestampsEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetCalibratedTimestampsEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetCalibratedTimestampsEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->timestampCount = timestampCount;
    packet->pTimestampInfos = pTimestampInfos;
    packet->pTimestamps = pTimestamps;
    packet->pMaxDeviation = pMaxDeviation;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawMeshTasksNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t taskCount;
    uint32_t firstTask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &taskCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstTask);

    Packet_vkCmdDrawMeshTasksNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawMeshTasksNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawMeshTasksNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->taskCount = taskCount;
    packet->firstTask = firstTask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawMeshTasksIndirectNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawMeshTasksIndirectNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawMeshTasksIndirectNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawMeshTasksIndirectNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->drawCount = drawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawMeshTasksIndirectCountNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawMeshTasksIndirectCountNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawMeshTasksIndirectCountNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawMeshTasksIndirectCountNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->countBuffer = countBuffer;
    packet->countBufferOffset = countBufferOffset;
    packet->maxDrawCount = maxDrawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetExclusiveScissorEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    PointerDecoder<VkBool32> pExclusiveScissorEnables;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstExclusiveScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &exclusiveScissorCount);
    bytes_read += pExclusiveScissorEnables.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetExclusiveScissorEnableNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetExclusiveScissorEnableNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetExclusiveScissorEnableNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstExclusiveScissor = firstExclusiveScissor;
    packet->exclusiveScissorCount = exclusiveScissorCount;
    packet->pExclusiveScissorEnables = pExclusiveScissorEnables;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetExclusiveScissorNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pExclusiveScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstExclusiveScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &exclusiveScissorCount);
    bytes_read += pExclusiveScissors.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetExclusiveScissorNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetExclusiveScissorNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetExclusiveScissorNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstExclusiveScissor = firstExclusiveScissor;
    packet->exclusiveScissorCount = exclusiveScissorCount;
    packet->pExclusiveScissors = pExclusiveScissors;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetCheckpointNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint64_t pCheckpointMarker;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCheckpointMarker);

    Packet_vkCmdSetCheckpointNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetCheckpointNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetCheckpointNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pCheckpointMarker = pCheckpointMarker;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetQueueCheckpointDataNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    PointerDecoder<uint32_t> pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointDataNV> pCheckpointData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pCheckpointDataCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCheckpointData.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetQueueCheckpointDataNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetQueueCheckpointDataNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetQueueCheckpointDataNV;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->pCheckpointDataCount = pCheckpointDataCount;
    packet->pCheckpointData = pCheckpointData;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkInitializePerformanceApiINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL> pInitializeInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInitializeInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkInitializePerformanceApiINTEL* packet = PreloadDecodeAllocator::Allocate<Packet_vkInitializePerformanceApiINTEL>();
    packet->packet_id = gfxrecon::format::PacketCall_vkInitializePerformanceApiINTEL;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInitializeInfo = pInitializeInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkUninitializePerformanceApiINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);

    Packet_vkUninitializePerformanceApiINTEL* packet = PreloadDecodeAllocator::Allocate<Packet_vkUninitializePerformanceApiINTEL>();
    packet->packet_id = gfxrecon::format::PacketCall_vkUninitializePerformanceApiINTEL;
    packet->call_info = call_info;
    packet->device = device;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetPerformanceMarkerINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL> pMarkerInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCmdSetPerformanceMarkerINTEL* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetPerformanceMarkerINTEL>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetPerformanceMarkerINTEL;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pMarkerInfo = pMarkerInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetPerformanceStreamMarkerINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL> pMarkerInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCmdSetPerformanceStreamMarkerINTEL* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetPerformanceStreamMarkerINTEL>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetPerformanceStreamMarkerINTEL;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pMarkerInfo = pMarkerInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetPerformanceOverrideINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL> pOverrideInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pOverrideInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCmdSetPerformanceOverrideINTEL* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetPerformanceOverrideINTEL>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetPerformanceOverrideINTEL;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pOverrideInfo = pOverrideInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAcquirePerformanceConfigurationINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL> pAcquireInfo;
    HandlePointerDecoder<VkPerformanceConfigurationINTEL> pConfiguration;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAcquireInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pConfiguration.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkAcquirePerformanceConfigurationINTEL* packet = PreloadDecodeAllocator::Allocate<Packet_vkAcquirePerformanceConfigurationINTEL>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAcquirePerformanceConfigurationINTEL;
    packet->call_info = call_info;
    packet->device = device;
    packet->pAcquireInfo = pAcquireInfo;
    packet->pConfiguration = pConfiguration;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkReleasePerformanceConfigurationINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId configuration;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &configuration);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkReleasePerformanceConfigurationINTEL* packet = PreloadDecodeAllocator::Allocate<Packet_vkReleasePerformanceConfigurationINTEL>();
    packet->packet_id = gfxrecon::format::PacketCall_vkReleasePerformanceConfigurationINTEL;
    packet->call_info = call_info;
    packet->device = device;
    packet->configuration = configuration;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueueSetPerformanceConfigurationINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    format::HandleId configuration;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &configuration);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkQueueSetPerformanceConfigurationINTEL* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueueSetPerformanceConfigurationINTEL>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueueSetPerformanceConfigurationINTEL;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->configuration = configuration;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPerformanceParameterINTEL(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkPerformanceParameterTypeINTEL parameter;
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL> pValue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &parameter);
    bytes_read += pValue.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPerformanceParameterINTEL* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPerformanceParameterINTEL>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPerformanceParameterINTEL;
    packet->call_info = call_info;
    packet->device = device;
    packet->parameter = parameter;
    packet->pValue = pValue;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSetLocalDimmingAMD(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapChain;
    VkBool32 localDimmingEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapChain);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &localDimmingEnable);

    Packet_vkSetLocalDimmingAMD* packet = PreloadDecodeAllocator::Allocate<Packet_vkSetLocalDimmingAMD>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSetLocalDimmingAMD;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapChain = swapChain;
    packet->localDimmingEnable = localDimmingEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateImagePipeSurfaceFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateImagePipeSurfaceFUCHSIA* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateImagePipeSurfaceFUCHSIA>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateImagePipeSurfaceFUCHSIA;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateMetalSurfaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateMetalSurfaceEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateMetalSurfaceEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateMetalSurfaceEXT;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetBufferDeviceAddressEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetBufferDeviceAddressEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetBufferDeviceAddressEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetBufferDeviceAddressEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceToolPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties> pToolProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pToolCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pToolProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceToolPropertiesEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceToolPropertiesEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceToolPropertiesEXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pToolCount = pToolCount;
    packet->pToolProperties = pToolProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pPropertyCount = pPropertyCount;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pCombinationCount;
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV> pCombinations;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pCombinationCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCombinations.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pCombinationCount = pCombinationCount;
    packet->pCombinations = pCombinations;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceSurfacePresentModes2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPresentModeCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPresentModes.PreloadDecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceSurfacePresentModes2EXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceSurfacePresentModes2EXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceSurfacePresentModes2EXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pSurfaceInfo = pSurfaceInfo;
    packet->pPresentModeCount = pPresentModeCount;
    packet->pPresentModes = pPresentModes;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAcquireFullScreenExclusiveModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkAcquireFullScreenExclusiveModeEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkAcquireFullScreenExclusiveModeEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAcquireFullScreenExclusiveModeEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkReleaseFullScreenExclusiveModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkReleaseFullScreenExclusiveModeEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkReleaseFullScreenExclusiveModeEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkReleaseFullScreenExclusiveModeEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceGroupSurfacePresentModes2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pSurfaceInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pModes.PreloadDecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDeviceGroupSurfacePresentModes2EXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceGroupSurfacePresentModes2EXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceGroupSurfacePresentModes2EXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pSurfaceInfo = pSurfaceInfo;
    packet->pModes = pModes;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateHeadlessSurfaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateHeadlessSurfaceEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateHeadlessSurfaceEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateHeadlessSurfaceEXT;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetLineStippleEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t lineStippleFactor;
    uint16_t lineStipplePattern;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineStippleFactor);
    bytes_read += ValueDecoder::DecodeUInt16Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineStipplePattern);

    Packet_vkCmdSetLineStippleEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetLineStippleEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetLineStippleEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->lineStippleFactor = lineStippleFactor;
    packet->lineStipplePattern = lineStipplePattern;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkResetQueryPoolEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkResetQueryPoolEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkResetQueryPoolEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkResetQueryPoolEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->queryPool = queryPool;
    packet->firstQuery = firstQuery;
    packet->queryCount = queryCount;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetCullModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCullModeFlags cullMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &cullMode);

    Packet_vkCmdSetCullModeEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetCullModeEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetCullModeEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->cullMode = cullMode;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetFrontFaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkFrontFace frontFace;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &frontFace);

    Packet_vkCmdSetFrontFaceEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetFrontFaceEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetFrontFaceEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->frontFace = frontFace;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetPrimitiveTopologyEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPrimitiveTopology primitiveTopology;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &primitiveTopology);

    Packet_vkCmdSetPrimitiveTopologyEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetPrimitiveTopologyEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetPrimitiveTopologyEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->primitiveTopology = primitiveTopology;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetViewportWithCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewports.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetViewportWithCountEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetViewportWithCountEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetViewportWithCountEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->viewportCount = viewportCount;
    packet->pViewports = pViewports;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetScissorWithCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scissorCount);
    bytes_read += pScissors.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetScissorWithCountEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetScissorWithCountEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetScissorWithCountEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->scissorCount = scissorCount;
    packet->pScissors = pScissors;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindVertexBuffers2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pBuffers.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pOffsets.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizes.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pStrides.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBindVertexBuffers2EXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindVertexBuffers2EXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindVertexBuffers2EXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstBinding = firstBinding;
    packet->bindingCount = bindingCount;
    packet->pBuffers = pBuffers;
    packet->pOffsets = pOffsets;
    packet->pSizes = pSizes;
    packet->pStrides = pStrides;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthTestEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthTestEnable);

    Packet_vkCmdSetDepthTestEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthTestEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthTestEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthTestEnable = depthTestEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthWriteEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthWriteEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthWriteEnable);

    Packet_vkCmdSetDepthWriteEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthWriteEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthWriteEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthWriteEnable = depthWriteEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthCompareOpEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCompareOp depthCompareOp;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthCompareOp);

    Packet_vkCmdSetDepthCompareOpEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthCompareOpEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthCompareOpEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthCompareOp = depthCompareOp;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthBoundsTestEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthBoundsTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBoundsTestEnable);

    Packet_vkCmdSetDepthBoundsTestEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthBoundsTestEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthBoundsTestEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthBoundsTestEnable = depthBoundsTestEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetStencilTestEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 stencilTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stencilTestEnable);

    Packet_vkCmdSetStencilTestEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetStencilTestEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetStencilTestEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->stencilTestEnable = stencilTestEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetStencilOpEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdSetStencilOpEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetStencilOpEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetStencilOpEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->faceMask = faceMask;
    packet->failOp = failOp;
    packet->passOp = passOp;
    packet->depthFailOp = depthFailOp;
    packet->compareOp = compareOp;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCopyMemoryToImageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfoEXT> pCopyMemoryToImageInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCopyMemoryToImageInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCopyMemoryToImageEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCopyMemoryToImageEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCopyMemoryToImageEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCopyMemoryToImageInfo = pCopyMemoryToImageInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCopyImageToMemoryEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfoEXT> pCopyImageToMemoryInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCopyImageToMemoryInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCopyImageToMemoryEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCopyImageToMemoryEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCopyImageToMemoryEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCopyImageToMemoryInfo = pCopyImageToMemoryInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCopyImageToImageEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyImageToImageInfoEXT> pCopyImageToImageInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCopyImageToImageInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCopyImageToImageEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCopyImageToImageEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCopyImageToImageEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCopyImageToImageInfo = pCopyImageToImageInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkTransitionImageLayoutEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t transitionCount;
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfoEXT> pTransitions;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &transitionCount);
    bytes_read += pTransitions.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkTransitionImageLayoutEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkTransitionImageLayoutEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkTransitionImageLayoutEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->transitionCount = transitionCount;
    packet->pTransitions = pTransitions;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetImageSubresourceLayout2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource2KHR> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR> pLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pSubresource.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pLayout.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetImageSubresourceLayout2EXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetImageSubresourceLayout2EXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetImageSubresourceLayout2EXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->image = image;
    packet->pSubresource = pSubresource;
    packet->pLayout = pLayout;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkReleaseSwapchainImagesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT> pReleaseInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pReleaseInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkReleaseSwapchainImagesEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkReleaseSwapchainImagesEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkReleaseSwapchainImagesEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pReleaseInfo = pReleaseInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetGeneratedCommandsMemoryRequirementsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetGeneratedCommandsMemoryRequirementsNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetGeneratedCommandsMemoryRequirementsNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetGeneratedCommandsMemoryRequirementsNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdPreprocessGeneratedCommandsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pGeneratedCommandsInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdPreprocessGeneratedCommandsNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdPreprocessGeneratedCommandsNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdPreprocessGeneratedCommandsNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pGeneratedCommandsInfo = pGeneratedCommandsInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdExecuteGeneratedCommandsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 isPreprocessed;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &isPreprocessed);
    bytes_read += pGeneratedCommandsInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdExecuteGeneratedCommandsNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdExecuteGeneratedCommandsNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdExecuteGeneratedCommandsNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->isPreprocessed = isPreprocessed;
    packet->pGeneratedCommandsInfo = pGeneratedCommandsInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindPipelineShaderGroupNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdBindPipelineShaderGroupNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindPipelineShaderGroupNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindPipelineShaderGroupNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pipelineBindPoint = pipelineBindPoint;
    packet->pipeline = pipeline;
    packet->groupIndex = groupIndex;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateIndirectCommandsLayoutNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkIndirectCommandsLayoutNV> pIndirectCommandsLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pIndirectCommandsLayout.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateIndirectCommandsLayoutNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateIndirectCommandsLayoutNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateIndirectCommandsLayoutNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pIndirectCommandsLayout = pIndirectCommandsLayout;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyIndirectCommandsLayoutNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indirectCommandsLayout);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyIndirectCommandsLayoutNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyIndirectCommandsLayoutNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyIndirectCommandsLayoutNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->indirectCommandsLayout = indirectCommandsLayout;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthBias2EXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT> pDepthBiasInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pDepthBiasInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetDepthBias2EXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthBias2EXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthBias2EXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pDepthBiasInfo = pDepthBiasInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAcquireDrmDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkAcquireDrmDisplayEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkAcquireDrmDisplayEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAcquireDrmDisplayEXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->drmFd = drmFd;
    packet->display = display;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDrmDisplayEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += display.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDrmDisplayEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDrmDisplayEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDrmDisplayEXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->drmFd = drmFd;
    packet->connectorId = connectorId;
    packet->display = display;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreatePrivateDataSlotEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlot> pPrivateDataSlot;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPrivateDataSlot.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreatePrivateDataSlotEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreatePrivateDataSlotEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreatePrivateDataSlotEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pPrivateDataSlot = pPrivateDataSlot;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyPrivateDataSlotEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId privateDataSlot;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &privateDataSlot);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyPrivateDataSlotEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyPrivateDataSlotEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyPrivateDataSlotEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->privateDataSlot = privateDataSlot;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSetPrivateDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkSetPrivateDataEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkSetPrivateDataEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSetPrivateDataEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->objectType = objectType;
    packet->objectHandle = objectHandle;
    packet->privateDataSlot = privateDataSlot;
    packet->data = data;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPrivateDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pData.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPrivateDataEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPrivateDataEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPrivateDataEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->objectType = objectType;
    packet->objectHandle = objectHandle;
    packet->privateDataSlot = privateDataSlot;
    packet->pData = pData;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetFragmentShadingRateEnumNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkFragmentShadingRateNV shadingRate;
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shadingRate);
    bytes_read += combinerOps.PreloadDecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetFragmentShadingRateEnumNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetFragmentShadingRateEnumNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetFragmentShadingRateEnumNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->shadingRate = shadingRate;
    packet->combinerOps = combinerOps;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceFaultInfoEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT> pFaultCounts;
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT> pFaultInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pFaultCounts.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFaultInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDeviceFaultInfoEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceFaultInfoEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceFaultInfoEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pFaultCounts = pFaultCounts;
    packet->pFaultInfo = pFaultInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkAcquireWinrtDisplayNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkAcquireWinrtDisplayNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkAcquireWinrtDisplayNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkAcquireWinrtDisplayNV;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->display = display;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetWinrtDisplayNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t deviceRelativeId;
    HandlePointerDecoder<VkDisplayKHR> pDisplay;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceRelativeId);
    bytes_read += pDisplay.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetWinrtDisplayNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetWinrtDisplayNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetWinrtDisplayNV;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->deviceRelativeId = deviceRelativeId;
    packet->pDisplay = pDisplay;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateDirectFBSurfaceEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateDirectFBSurfaceEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateDirectFBSurfaceEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateDirectFBSurfaceEXT;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkGetPhysicalDeviceDirectFBPresentationSupportEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceDirectFBPresentationSupportEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->queueFamilyIndex = queueFamilyIndex;
    packet->dfb = dfb;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetVertexInputEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t vertexBindingDescriptionCount;
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT> pVertexBindingDescriptions;
    uint32_t vertexAttributeDescriptionCount;
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT> pVertexAttributeDescriptions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexBindingDescriptionCount);
    bytes_read += pVertexBindingDescriptions.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexAttributeDescriptionCount);
    bytes_read += pVertexAttributeDescriptions.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetVertexInputEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetVertexInputEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetVertexInputEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->vertexBindingDescriptionCount = vertexBindingDescriptionCount;
    packet->pVertexBindingDescriptions = pVertexBindingDescriptions;
    packet->vertexAttributeDescriptionCount = vertexAttributeDescriptionCount;
    packet->pVertexAttributeDescriptions = pVertexAttributeDescriptions;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMemoryZirconHandleFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA> pGetZirconHandleInfo;
    PointerDecoder<uint32_t> pZirconHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetZirconHandleInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pZirconHandle.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetMemoryZirconHandleFUCHSIA* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMemoryZirconHandleFUCHSIA>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMemoryZirconHandleFUCHSIA;
    packet->call_info = call_info;
    packet->device = device;
    packet->pGetZirconHandleInfo = pGetZirconHandleInfo;
    packet->pZirconHandle = pZirconHandle;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMemoryZirconHandlePropertiesFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pMemoryZirconHandleProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetMemoryZirconHandlePropertiesFUCHSIA* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMemoryZirconHandlePropertiesFUCHSIA>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMemoryZirconHandlePropertiesFUCHSIA;
    packet->call_info = call_info;
    packet->device = device;
    packet->handleType = handleType;
    packet->zirconHandle = zirconHandle;
    packet->pMemoryZirconHandleProperties = pMemoryZirconHandleProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkImportSemaphoreZirconHandleFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA> pImportSemaphoreZirconHandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreZirconHandleInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkImportSemaphoreZirconHandleFUCHSIA* packet = PreloadDecodeAllocator::Allocate<Packet_vkImportSemaphoreZirconHandleFUCHSIA>();
    packet->packet_id = gfxrecon::format::PacketCall_vkImportSemaphoreZirconHandleFUCHSIA;
    packet->call_info = call_info;
    packet->device = device;
    packet->pImportSemaphoreZirconHandleInfo = pImportSemaphoreZirconHandleInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetSemaphoreZirconHandleFUCHSIA(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA> pGetZirconHandleInfo;
    PointerDecoder<uint32_t> pZirconHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetZirconHandleInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pZirconHandle.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetSemaphoreZirconHandleFUCHSIA* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetSemaphoreZirconHandleFUCHSIA>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetSemaphoreZirconHandleFUCHSIA;
    packet->call_info = call_info;
    packet->device = device;
    packet->pGetZirconHandleInfo = pGetZirconHandleInfo;
    packet->pZirconHandle = pZirconHandle;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindInvocationMaskHUAWEI(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId imageView;
    VkImageLayout imageLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageView);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageLayout);

    Packet_vkCmdBindInvocationMaskHUAWEI* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindInvocationMaskHUAWEI>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindInvocationMaskHUAWEI;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->imageView = imageView;
    packet->imageLayout = imageLayout;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMemoryRemoteAddressNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV> pMemoryGetRemoteAddressInfo;
    PointerDecoder<uint64_t, void*> pAddress;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pMemoryGetRemoteAddressInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAddress.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetMemoryRemoteAddressNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMemoryRemoteAddressNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMemoryRemoteAddressNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pMemoryGetRemoteAddressInfo = pMemoryGetRemoteAddressInfo;
    packet->pAddress = pAddress;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetPatchControlPointsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t patchControlPoints;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &patchControlPoints);

    Packet_vkCmdSetPatchControlPointsEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetPatchControlPointsEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetPatchControlPointsEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->patchControlPoints = patchControlPoints;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetRasterizerDiscardEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 rasterizerDiscardEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rasterizerDiscardEnable);

    Packet_vkCmdSetRasterizerDiscardEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetRasterizerDiscardEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetRasterizerDiscardEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->rasterizerDiscardEnable = rasterizerDiscardEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthBiasEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthBiasEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBiasEnable);

    Packet_vkCmdSetDepthBiasEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthBiasEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthBiasEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthBiasEnable = depthBiasEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetLogicOpEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkLogicOp logicOp;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &logicOp);

    Packet_vkCmdSetLogicOpEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetLogicOpEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetLogicOpEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->logicOp = logicOp;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetPrimitiveRestartEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 primitiveRestartEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &primitiveRestartEnable);

    Packet_vkCmdSetPrimitiveRestartEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetPrimitiveRestartEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetPrimitiveRestartEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->primitiveRestartEnable = primitiveRestartEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateScreenSurfaceQNX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateScreenSurfaceQNX* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateScreenSurfaceQNX>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateScreenSurfaceQNX;
    packet->call_info = call_info;
    packet->instance = instance;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSurface = pSurface;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceScreenPresentationSupportQNX(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkGetPhysicalDeviceScreenPresentationSupportQNX* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceScreenPresentationSupportQNX>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceScreenPresentationSupportQNX;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->queueFamilyIndex = queueFamilyIndex;
    packet->window = window;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetColorWriteEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t attachmentCount;
    PointerDecoder<VkBool32> pColorWriteEnables;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pColorWriteEnables.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetColorWriteEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetColorWriteEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetColorWriteEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->attachmentCount = attachmentCount;
    packet->pColorWriteEnables = pColorWriteEnables;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawMultiEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pVertexInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstInstance);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    Packet_vkCmdDrawMultiEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawMultiEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawMultiEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->drawCount = drawCount;
    packet->pVertexInfo = pVertexInfo;
    packet->instanceCount = instanceCount;
    packet->firstInstance = firstInstance;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawMultiIndexedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pIndexInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstInstance);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += pVertexOffset.PreloadDecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdDrawMultiIndexedEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawMultiIndexedEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawMultiIndexedEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->drawCount = drawCount;
    packet->pIndexInfo = pIndexInfo;
    packet->instanceCount = instanceCount;
    packet->firstInstance = firstInstance;
    packet->stride = stride;
    packet->pVertexOffset = pVertexOffset;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkMicromapEXT> pMicromap;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMicromap.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateMicromapEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateMicromapEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateMicromapEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pMicromap = pMicromap;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId micromap;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &micromap);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyMicromapEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyMicromapEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyMicromapEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->micromap = micromap;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBuildMicromapsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pInfos;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &infoCount);
    bytes_read += pInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBuildMicromapsEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBuildMicromapsEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBuildMicromapsEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->infoCount = infoCount;
    packet->pInfos = pInfos;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBuildMicromapsEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkBuildMicromapsEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkBuildMicromapsEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBuildMicromapsEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->deferredOperation = deferredOperation;
    packet->infoCount = infoCount;
    packet->pInfos = pInfos;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCopyMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCopyMicromapEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCopyMicromapEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCopyMicromapEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->deferredOperation = deferredOperation;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCopyMicromapToMemoryEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCopyMicromapToMemoryEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCopyMicromapToMemoryEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCopyMicromapToMemoryEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->deferredOperation = deferredOperation;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCopyMemoryToMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCopyMemoryToMicromapEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCopyMemoryToMicromapEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCopyMemoryToMicromapEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->deferredOperation = deferredOperation;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkWriteMicromapsPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pMicromaps.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkWriteMicromapsPropertiesEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkWriteMicromapsPropertiesEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkWriteMicromapsPropertiesEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->micromapCount = micromapCount;
    packet->pMicromaps = pMicromaps;
    packet->queryType = queryType;
    packet->dataSize = dataSize;
    packet->pData = pData;
    packet->stride = stride;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyMicromapEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyMicromapEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyMicromapEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pInfo = pInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyMicromapToMemoryEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyMicromapToMemoryEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyMicromapToMemoryEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyMicromapToMemoryEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pInfo = pInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyMemoryToMicromapEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyMemoryToMicromapEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyMemoryToMicromapEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyMemoryToMicromapEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pInfo = pInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWriteMicromapsPropertiesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pMicromaps.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);

    Packet_vkCmdWriteMicromapsPropertiesEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWriteMicromapsPropertiesEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWriteMicromapsPropertiesEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->micromapCount = micromapCount;
    packet->pMicromaps = pMicromaps;
    packet->queryType = queryType;
    packet->queryPool = queryPool;
    packet->firstQuery = firstQuery;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceMicromapCompatibilityEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT> pVersionInfo;
    PointerDecoder<VkAccelerationStructureCompatibilityKHR> pCompatibility;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pVersionInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCompatibility.PreloadDecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceMicromapCompatibilityEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceMicromapCompatibilityEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceMicromapCompatibilityEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pVersionInfo = pVersionInfo;
    packet->pCompatibility = pCompatibility;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetMicromapBuildSizesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkAccelerationStructureBuildTypeKHR buildType;
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT> pBuildInfo;
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT> pSizeInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buildType);
    bytes_read += pBuildInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizeInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetMicromapBuildSizesEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetMicromapBuildSizesEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetMicromapBuildSizesEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->buildType = buildType;
    packet->pBuildInfo = pBuildInfo;
    packet->pSizeInfo = pSizeInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawClusterHUAWEI(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawClusterHUAWEI* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawClusterHUAWEI>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawClusterHUAWEI;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->groupCountX = groupCountX;
    packet->groupCountY = groupCountY;
    packet->groupCountZ = groupCountZ;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawClusterIndirectHUAWEI(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);

    Packet_vkCmdDrawClusterIndirectHUAWEI* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawClusterIndirectHUAWEI>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawClusterIndirectHUAWEI;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSetDeviceMemoryPriorityEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    float priority;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &priority);

    Packet_vkSetDeviceMemoryPriorityEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkSetDeviceMemoryPriorityEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSetDeviceMemoryPriorityEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->memory = memory;
    packet->priority = priority;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDescriptorSetLayoutHostMappingInfoVALVE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE> pBindingReference;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE> pHostMapping;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pBindingReference.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHostMapping.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDescriptorSetLayoutHostMappingInfoVALVE* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDescriptorSetLayoutHostMappingInfoVALVE>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE;
    packet->call_info = call_info;
    packet->device = device;
    packet->pBindingReference = pBindingReference;
    packet->pHostMapping = pHostMapping;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDescriptorSetHostMappingVALVE(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorSet;
    PointerDecoder<uint64_t, void*> ppData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSet);
    bytes_read += ppData.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDescriptorSetHostMappingVALVE* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDescriptorSetHostMappingVALVE>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDescriptorSetHostMappingVALVE;
    packet->call_info = call_info;
    packet->device = device;
    packet->descriptorSet = descriptorSet;
    packet->ppData = ppData;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPipelineIndirectMemoryRequirementsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetPipelineIndirectMemoryRequirementsNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPipelineIndirectMemoryRequirementsNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPipelineIndirectMemoryRequirementsNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pMemoryRequirements = pMemoryRequirements;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdUpdatePipelineIndirectBufferNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);

    Packet_vkCmdUpdatePipelineIndirectBufferNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdUpdatePipelineIndirectBufferNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdUpdatePipelineIndirectBufferNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pipelineBindPoint = pipelineBindPoint;
    packet->pipeline = pipeline;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPipelineIndirectDeviceAddressNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPipelineIndirectDeviceAddressNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPipelineIndirectDeviceAddressNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPipelineIndirectDeviceAddressNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthClampEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthClampEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthClampEnable);

    Packet_vkCmdSetDepthClampEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthClampEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthClampEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthClampEnable = depthClampEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetPolygonModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPolygonMode polygonMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &polygonMode);

    Packet_vkCmdSetPolygonModeEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetPolygonModeEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetPolygonModeEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->polygonMode = polygonMode;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetRasterizationSamplesEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkSampleCountFlagBits rasterizationSamples;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rasterizationSamples);

    Packet_vkCmdSetRasterizationSamplesEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetRasterizationSamplesEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetRasterizationSamplesEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->rasterizationSamples = rasterizationSamples;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetSampleMaskEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkSampleCountFlagBits samples;
    PointerDecoder<VkSampleMask> pSampleMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &samples);
    bytes_read += pSampleMask.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetSampleMaskEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetSampleMaskEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetSampleMaskEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->samples = samples;
    packet->pSampleMask = pSampleMask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetAlphaToCoverageEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 alphaToCoverageEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &alphaToCoverageEnable);

    Packet_vkCmdSetAlphaToCoverageEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetAlphaToCoverageEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetAlphaToCoverageEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->alphaToCoverageEnable = alphaToCoverageEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetAlphaToOneEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 alphaToOneEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &alphaToOneEnable);

    Packet_vkCmdSetAlphaToOneEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetAlphaToOneEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetAlphaToOneEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->alphaToOneEnable = alphaToOneEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetLogicOpEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 logicOpEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &logicOpEnable);

    Packet_vkCmdSetLogicOpEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetLogicOpEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetLogicOpEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->logicOpEnable = logicOpEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetColorBlendEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    PointerDecoder<VkBool32> pColorBlendEnables;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstAttachment);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pColorBlendEnables.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetColorBlendEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetColorBlendEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetColorBlendEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstAttachment = firstAttachment;
    packet->attachmentCount = attachmentCount;
    packet->pColorBlendEnables = pColorBlendEnables;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetColorBlendEquationEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT> pColorBlendEquations;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstAttachment);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pColorBlendEquations.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetColorBlendEquationEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetColorBlendEquationEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetColorBlendEquationEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstAttachment = firstAttachment;
    packet->attachmentCount = attachmentCount;
    packet->pColorBlendEquations = pColorBlendEquations;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetColorWriteMaskEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    PointerDecoder<VkColorComponentFlags> pColorWriteMasks;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstAttachment);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pColorWriteMasks.PreloadDecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetColorWriteMaskEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetColorWriteMaskEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetColorWriteMaskEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstAttachment = firstAttachment;
    packet->attachmentCount = attachmentCount;
    packet->pColorWriteMasks = pColorWriteMasks;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetTessellationDomainOriginEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkTessellationDomainOrigin domainOrigin;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &domainOrigin);

    Packet_vkCmdSetTessellationDomainOriginEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetTessellationDomainOriginEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetTessellationDomainOriginEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->domainOrigin = domainOrigin;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetRasterizationStreamEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t rasterizationStream;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rasterizationStream);

    Packet_vkCmdSetRasterizationStreamEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetRasterizationStreamEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetRasterizationStreamEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->rasterizationStream = rasterizationStream;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetConservativeRasterizationModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkConservativeRasterizationModeEXT conservativeRasterizationMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &conservativeRasterizationMode);

    Packet_vkCmdSetConservativeRasterizationModeEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetConservativeRasterizationModeEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetConservativeRasterizationModeEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->conservativeRasterizationMode = conservativeRasterizationMode;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetExtraPrimitiveOverestimationSizeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float extraPrimitiveOverestimationSize;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &extraPrimitiveOverestimationSize);

    Packet_vkCmdSetExtraPrimitiveOverestimationSizeEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetExtraPrimitiveOverestimationSizeEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->extraPrimitiveOverestimationSize = extraPrimitiveOverestimationSize;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthClipEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthClipEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthClipEnable);

    Packet_vkCmdSetDepthClipEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthClipEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthClipEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->depthClipEnable = depthClipEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetSampleLocationsEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 sampleLocationsEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sampleLocationsEnable);

    Packet_vkCmdSetSampleLocationsEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetSampleLocationsEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetSampleLocationsEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->sampleLocationsEnable = sampleLocationsEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetColorBlendAdvancedEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstAttachment;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT> pColorBlendAdvanced;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstAttachment);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pColorBlendAdvanced.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetColorBlendAdvancedEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetColorBlendAdvancedEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetColorBlendAdvancedEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstAttachment = firstAttachment;
    packet->attachmentCount = attachmentCount;
    packet->pColorBlendAdvanced = pColorBlendAdvanced;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetProvokingVertexModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkProvokingVertexModeEXT provokingVertexMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &provokingVertexMode);

    Packet_vkCmdSetProvokingVertexModeEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetProvokingVertexModeEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetProvokingVertexModeEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->provokingVertexMode = provokingVertexMode;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetLineRasterizationModeEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkLineRasterizationModeEXT lineRasterizationMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineRasterizationMode);

    Packet_vkCmdSetLineRasterizationModeEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetLineRasterizationModeEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetLineRasterizationModeEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->lineRasterizationMode = lineRasterizationMode;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetLineStippleEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 stippledLineEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stippledLineEnable);

    Packet_vkCmdSetLineStippleEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetLineStippleEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetLineStippleEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->stippledLineEnable = stippledLineEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetDepthClipNegativeOneToOneEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 negativeOneToOne;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &negativeOneToOne);

    Packet_vkCmdSetDepthClipNegativeOneToOneEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetDepthClipNegativeOneToOneEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetDepthClipNegativeOneToOneEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->negativeOneToOne = negativeOneToOne;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetViewportWScalingEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 viewportWScalingEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportWScalingEnable);

    Packet_vkCmdSetViewportWScalingEnableNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetViewportWScalingEnableNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetViewportWScalingEnableNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->viewportWScalingEnable = viewportWScalingEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetViewportSwizzleNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportSwizzleNV> pViewportSwizzles;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewportSwizzles.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetViewportSwizzleNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetViewportSwizzleNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetViewportSwizzleNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->firstViewport = firstViewport;
    packet->viewportCount = viewportCount;
    packet->pViewportSwizzles = pViewportSwizzles;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetCoverageToColorEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 coverageToColorEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageToColorEnable);

    Packet_vkCmdSetCoverageToColorEnableNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetCoverageToColorEnableNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetCoverageToColorEnableNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->coverageToColorEnable = coverageToColorEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetCoverageToColorLocationNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t coverageToColorLocation;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageToColorLocation);

    Packet_vkCmdSetCoverageToColorLocationNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetCoverageToColorLocationNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetCoverageToColorLocationNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->coverageToColorLocation = coverageToColorLocation;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetCoverageModulationModeNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCoverageModulationModeNV coverageModulationMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageModulationMode);

    Packet_vkCmdSetCoverageModulationModeNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetCoverageModulationModeNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetCoverageModulationModeNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->coverageModulationMode = coverageModulationMode;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetCoverageModulationTableEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 coverageModulationTableEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageModulationTableEnable);

    Packet_vkCmdSetCoverageModulationTableEnableNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetCoverageModulationTableEnableNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetCoverageModulationTableEnableNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->coverageModulationTableEnable = coverageModulationTableEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetCoverageModulationTableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t coverageModulationTableCount;
    PointerDecoder<float> pCoverageModulationTable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageModulationTableCount);
    bytes_read += pCoverageModulationTable.PreloadDecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdSetCoverageModulationTableNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetCoverageModulationTableNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetCoverageModulationTableNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->coverageModulationTableCount = coverageModulationTableCount;
    packet->pCoverageModulationTable = pCoverageModulationTable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetShadingRateImageEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 shadingRateImageEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shadingRateImageEnable);

    Packet_vkCmdSetShadingRateImageEnableNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetShadingRateImageEnableNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetShadingRateImageEnableNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->shadingRateImageEnable = shadingRateImageEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetRepresentativeFragmentTestEnableNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 representativeFragmentTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &representativeFragmentTestEnable);

    Packet_vkCmdSetRepresentativeFragmentTestEnableNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetRepresentativeFragmentTestEnableNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetRepresentativeFragmentTestEnableNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->representativeFragmentTestEnable = representativeFragmentTestEnable;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetCoverageReductionModeNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCoverageReductionModeNV coverageReductionMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &coverageReductionMode);

    Packet_vkCmdSetCoverageReductionModeNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetCoverageReductionModeNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetCoverageReductionModeNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->coverageReductionMode = coverageReductionMode;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetShaderModuleIdentifierEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId shaderModule;
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT> pIdentifier;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shaderModule);
    bytes_read += pIdentifier.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetShaderModuleIdentifierEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetShaderModuleIdentifierEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetShaderModuleIdentifierEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->shaderModule = shaderModule;
    packet->pIdentifier = pIdentifier;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetShaderModuleCreateInfoIdentifierEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT> pIdentifier;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pIdentifier.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetShaderModuleCreateInfoIdentifierEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetShaderModuleCreateInfoIdentifierEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetShaderModuleCreateInfoIdentifierEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pIdentifier = pIdentifier;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV> pOpticalFlowImageFormatInfo;
    PointerDecoder<uint32_t> pFormatCount;
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pOpticalFlowImageFormatInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFormatCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetPhysicalDeviceOpticalFlowImageFormatsNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetPhysicalDeviceOpticalFlowImageFormatsNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV;
    packet->call_info = call_info;
    packet->physicalDevice = physicalDevice;
    packet->pOpticalFlowImageFormatInfo = pOpticalFlowImageFormatInfo;
    packet->pFormatCount = pFormatCount;
    packet->pImageFormatProperties = pImageFormatProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateOpticalFlowSessionNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkOpticalFlowSessionNV> pSession;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSession.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateOpticalFlowSessionNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateOpticalFlowSessionNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateOpticalFlowSessionNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pSession = pSession;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyOpticalFlowSessionNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyOpticalFlowSessionNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyOpticalFlowSessionNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyOpticalFlowSessionNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->session = session;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkBindOpticalFlowSessionImageNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkBindOpticalFlowSessionImageNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkBindOpticalFlowSessionImageNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkBindOpticalFlowSessionImageNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->session = session;
    packet->bindingPoint = bindingPoint;
    packet->view = view;
    packet->layout = layout;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdOpticalFlowExecuteNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId session;
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV> pExecuteInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &session);
    bytes_read += pExecuteInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdOpticalFlowExecuteNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdOpticalFlowExecuteNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdOpticalFlowExecuteNV;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->session = session;
    packet->pExecuteInfo = pExecuteInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateShadersEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCreateInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pShaders.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateShadersEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateShadersEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateShadersEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->createInfoCount = createInfoCount;
    packet->pCreateInfos = pCreateInfos;
    packet->pAllocator = pAllocator;
    packet->pShaders = pShaders;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyShaderEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId shader;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shader);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyShaderEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyShaderEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyShaderEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->shader = shader;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetShaderBinaryDataEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId shader;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shader);
    bytes_read += pDataSize.PreloadDecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetShaderBinaryDataEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetShaderBinaryDataEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetShaderBinaryDataEXT;
    packet->call_info = call_info;
    packet->device = device;
    packet->shader = shader;
    packet->pDataSize = pDataSize;
    packet->pData = pData;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBindShadersEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t stageCount;
    PointerDecoder<VkShaderStageFlagBits> pStages;
    HandlePointerDecoder<VkShaderEXT> pShaders;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageCount);
    bytes_read += pStages.PreloadDecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pShaders.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBindShadersEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBindShadersEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBindShadersEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->stageCount = stageCount;
    packet->pStages = pStages;
    packet->pShaders = pShaders;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetFramebufferTilePropertiesQCOM(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId framebuffer;
    PointerDecoder<uint32_t> pPropertiesCount;
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &framebuffer);
    bytes_read += pPropertiesCount.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetFramebufferTilePropertiesQCOM* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetFramebufferTilePropertiesQCOM>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetFramebufferTilePropertiesQCOM;
    packet->call_info = call_info;
    packet->device = device;
    packet->framebuffer = framebuffer;
    packet->pPropertiesCount = pPropertiesCount;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDynamicRenderingTilePropertiesQCOM(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderingInfo> pRenderingInfo;
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pRenderingInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetDynamicRenderingTilePropertiesQCOM* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDynamicRenderingTilePropertiesQCOM>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDynamicRenderingTilePropertiesQCOM;
    packet->call_info = call_info;
    packet->device = device;
    packet->pRenderingInfo = pRenderingInfo;
    packet->pProperties = pProperties;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSetLatencySleepModeNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkLatencySleepModeInfoNV> pSleepModeInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pSleepModeInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkSetLatencySleepModeNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkSetLatencySleepModeNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSetLatencySleepModeNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->pSleepModeInfo = pSleepModeInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkLatencySleepNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkLatencySleepInfoNV> pSleepInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pSleepInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkLatencySleepNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkLatencySleepNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkLatencySleepNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->pSleepInfo = pSleepInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkSetLatencyMarkerNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkSetLatencyMarkerInfoNV> pLatencyMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pLatencyMarkerInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkSetLatencyMarkerNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkSetLatencyMarkerNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkSetLatencyMarkerNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->pLatencyMarkerInfo = pLatencyMarkerInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetLatencyTimingsNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkGetLatencyMarkerInfoNV> pLatencyMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pLatencyMarkerInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetLatencyTimingsNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetLatencyTimingsNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetLatencyTimingsNV;
    packet->call_info = call_info;
    packet->device = device;
    packet->swapchain = swapchain;
    packet->pLatencyMarkerInfo = pLatencyMarkerInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkQueueNotifyOutOfBandNV(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkOutOfBandQueueTypeInfoNV> pQueueTypeInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pQueueTypeInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkQueueNotifyOutOfBandNV* packet = PreloadDecodeAllocator::Allocate<Packet_vkQueueNotifyOutOfBandNV>();
    packet->packet_id = gfxrecon::format::PacketCall_vkQueueNotifyOutOfBandNV;
    packet->call_info = call_info;
    packet->queue = queue;
    packet->pQueueTypeInfo = pQueueTypeInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetAttachmentFeedbackLoopEnableEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkImageAspectFlags aspectMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &aspectMask);

    Packet_vkCmdSetAttachmentFeedbackLoopEnableEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetAttachmentFeedbackLoopEnableEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetAttachmentFeedbackLoopEnableEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->aspectMask = aspectMask;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCreateAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructure;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAccelerationStructure.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCreateAccelerationStructureKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCreateAccelerationStructureKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCreateAccelerationStructureKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pCreateInfo = pCreateInfo;
    packet->pAllocator = pAllocator;
    packet->pAccelerationStructure = pAccelerationStructure;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkDestroyAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &accelerationStructure);
    bytes_read += pAllocator.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkDestroyAccelerationStructureKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkDestroyAccelerationStructureKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkDestroyAccelerationStructureKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->accelerationStructure = accelerationStructure;
    packet->pAllocator = pAllocator;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBuildAccelerationStructuresKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t infoCount;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfos;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*> ppBuildRangeInfos;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &infoCount);
    bytes_read += pInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppBuildRangeInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBuildAccelerationStructuresKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBuildAccelerationStructuresKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBuildAccelerationStructuresKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->infoCount = infoCount;
    packet->pInfos = pInfos;
    packet->ppBuildRangeInfos = ppBuildRangeInfos;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdBuildAccelerationStructuresIndirectKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pInfos.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pIndirectDeviceAddresses.PreloadDecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pIndirectStrides.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppMaxPrimitiveCounts.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdBuildAccelerationStructuresIndirectKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdBuildAccelerationStructuresIndirectKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdBuildAccelerationStructuresIndirectKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->infoCount = infoCount;
    packet->pInfos = pInfos;
    packet->pIndirectDeviceAddresses = pIndirectDeviceAddresses;
    packet->pIndirectStrides = pIndirectStrides;
    packet->ppMaxPrimitiveCounts = ppMaxPrimitiveCounts;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCopyAccelerationStructureToMemoryKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCopyAccelerationStructureToMemoryKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCopyAccelerationStructureToMemoryKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCopyAccelerationStructureToMemoryKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->deferredOperation = deferredOperation;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCopyMemoryToAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId deferredOperation;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deferredOperation);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkCopyMemoryToAccelerationStructureKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCopyMemoryToAccelerationStructureKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCopyMemoryToAccelerationStructureKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->deferredOperation = deferredOperation;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkWriteAccelerationStructuresPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pAccelerationStructures.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkWriteAccelerationStructuresPropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkWriteAccelerationStructuresPropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkWriteAccelerationStructuresPropertiesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->accelerationStructureCount = accelerationStructureCount;
    packet->pAccelerationStructures = pAccelerationStructures;
    packet->queryType = queryType;
    packet->dataSize = dataSize;
    packet->pData = pData;
    packet->stride = stride;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyAccelerationStructureKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyAccelerationStructureKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyAccelerationStructureKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pInfo = pInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyAccelerationStructureToMemoryKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyAccelerationStructureToMemoryKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyAccelerationStructureToMemoryKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyAccelerationStructureToMemoryKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pInfo = pInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdCopyMemoryToAccelerationStructureKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkCmdCopyMemoryToAccelerationStructureKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdCopyMemoryToAccelerationStructureKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdCopyMemoryToAccelerationStructureKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pInfo = pInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetAccelerationStructureDeviceAddressKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetAccelerationStructureDeviceAddressKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetAccelerationStructureDeviceAddressKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetAccelerationStructureDeviceAddressKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pInfo = pInfo;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdWriteAccelerationStructuresPropertiesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pAccelerationStructures.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);

    Packet_vkCmdWriteAccelerationStructuresPropertiesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdWriteAccelerationStructuresPropertiesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdWriteAccelerationStructuresPropertiesKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->accelerationStructureCount = accelerationStructureCount;
    packet->pAccelerationStructures = pAccelerationStructures;
    packet->queryType = queryType;
    packet->queryPool = queryPool;
    packet->firstQuery = firstQuery;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetDeviceAccelerationStructureCompatibilityKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR> pVersionInfo;
    PointerDecoder<VkAccelerationStructureCompatibilityKHR> pCompatibility;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pVersionInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCompatibility.PreloadDecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetDeviceAccelerationStructureCompatibilityKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetDeviceAccelerationStructureCompatibilityKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetDeviceAccelerationStructureCompatibilityKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pVersionInfo = pVersionInfo;
    packet->pCompatibility = pCompatibility;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetAccelerationStructureBuildSizesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkAccelerationStructureBuildTypeKHR buildType;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pBuildInfo;
    PointerDecoder<uint32_t> pMaxPrimitiveCounts;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR> pSizeInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buildType);
    bytes_read += pBuildInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMaxPrimitiveCounts.PreloadDecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizeInfo.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    Packet_vkGetAccelerationStructureBuildSizesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetAccelerationStructureBuildSizesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetAccelerationStructureBuildSizesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->buildType = buildType;
    packet->pBuildInfo = pBuildInfo;
    packet->pMaxPrimitiveCounts = pMaxPrimitiveCounts;
    packet->pSizeInfo = pSizeInfo;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdTraceRaysKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pRaygenShaderBindingTable.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMissShaderBindingTable.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHitShaderBindingTable.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCallableShaderBindingTable.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &width);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &height);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depth);

    Packet_vkCmdTraceRaysKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdTraceRaysKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdTraceRaysKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pRaygenShaderBindingTable = pRaygenShaderBindingTable;
    packet->pMissShaderBindingTable = pMissShaderBindingTable;
    packet->pHitShaderBindingTable = pHitShaderBindingTable;
    packet->pCallableShaderBindingTable = pCallableShaderBindingTable;
    packet->width = width;
    packet->height = height;
    packet->depth = depth;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pData.PreloadDecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    Packet_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipeline = pipeline;
    packet->firstGroup = firstGroup;
    packet->groupCount = groupCount;
    packet->dataSize = dataSize;
    packet->pData = pData;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdTraceRaysIndirectKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pRaygenShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pMissShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pHitShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR> pCallableShaderBindingTable;
    VkDeviceAddress indirectDeviceAddress;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRaygenShaderBindingTable.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMissShaderBindingTable.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHitShaderBindingTable.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCallableShaderBindingTable.PreloadDecode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indirectDeviceAddress);

    Packet_vkCmdTraceRaysIndirectKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdTraceRaysIndirectKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdTraceRaysIndirectKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pRaygenShaderBindingTable = pRaygenShaderBindingTable;
    packet->pMissShaderBindingTable = pMissShaderBindingTable;
    packet->pHitShaderBindingTable = pHitShaderBindingTable;
    packet->pCallableShaderBindingTable = pCallableShaderBindingTable;
    packet->indirectDeviceAddress = indirectDeviceAddress;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkGetRayTracingShaderGroupStackSizeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkGetRayTracingShaderGroupStackSizeKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkGetRayTracingShaderGroupStackSizeKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkGetRayTracingShaderGroupStackSizeKHR;
    packet->call_info = call_info;
    packet->device = device;
    packet->pipeline = pipeline;
    packet->group = group;
    packet->groupShader = groupShader;
    packet->return_value = return_value;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdSetRayTracingPipelineStackSizeKHR(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t pipelineStackSize;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineStackSize);

    Packet_vkCmdSetRayTracingPipelineStackSizeKHR* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdSetRayTracingPipelineStackSizeKHR>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdSetRayTracingPipelineStackSizeKHR;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->pipelineStackSize = pipelineStackSize;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawMeshTasksEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawMeshTasksEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawMeshTasksEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawMeshTasksEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->groupCountX = groupCountX;
    packet->groupCountY = groupCountY;
    packet->groupCountZ = groupCountZ;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawMeshTasksIndirectEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawMeshTasksIndirectEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawMeshTasksIndirectEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawMeshTasksIndirectEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->drawCount = drawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

size_t VulkanPreloadDecoder::Decode_vkCmdDrawMeshTasksIndirectCountEXT(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
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

    Packet_vkCmdDrawMeshTasksIndirectCountEXT* packet = PreloadDecodeAllocator::Allocate<Packet_vkCmdDrawMeshTasksIndirectCountEXT>();
    packet->packet_id = gfxrecon::format::PacketCall_vkCmdDrawMeshTasksIndirectCountEXT;
    packet->call_info = call_info;
    packet->commandBuffer = commandBuffer;
    packet->buffer = buffer;
    packet->offset = offset;
    packet->countBuffer = countBuffer;
    packet->countBufferOffset = countBufferOffset;
    packet->maxDrawCount = maxDrawCount;
    packet->stride = stride;

    AddPacket(reinterpret_cast<void*>(packet));

    return bytes_read;
}

void VulkanPreloadDecoder::DecodeFunctionCall(format::ApiCallId             call_id,
                                       const ApiCallInfo&            call_info,
                                       const uint8_t*                parameter_buffer,
                                       size_t                        buffer_size)
{
    switch(call_id)
    {
    default:
        VulkanPreloadDecoderBase::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);
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
