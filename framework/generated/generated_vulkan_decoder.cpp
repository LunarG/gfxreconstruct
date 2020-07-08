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

#include "decode/handle_pointer_decoder.h"
#include "decode/pnext_node.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/value_decoder.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstddef>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t VulkanDecoder::Decode_vkCreateInstance(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateInstance(return_value, &pCreateInfo, &pAllocator, &pInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyInstance(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyInstance(instance, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDevices(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkEnumeratePhysicalDevices(return_value, instance, &pPhysicalDeviceCount, &pPhysicalDevices);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures(physicalDevice, &pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceFormatProperties(physicalDevice, format, &pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties(return_value, physicalDevice, format, type, tiling, usage, flags, &pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties(physicalDevice, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &pQueueFamilyPropertyCount, &pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties(physicalDevice, &pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDevice(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDevice(return_value, physicalDevice, &pCreateInfo, &pAllocator, &pDevice);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDevice(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDevice(device, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceQueue(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, &pQueue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueSubmit(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkQueueSubmit(return_value, queue, submitCount, &pSubmits, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueWaitIdle(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueWaitIdle(return_value, queue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDeviceWaitIdle(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDeviceWaitIdle(return_value, device);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateMemory(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkAllocateMemory(return_value, device, &pAllocateInfo, &pAllocator, &pMemory);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeMemory(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkFreeMemory(device, memory, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMapMemory(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ppData.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMapMemory(return_value, device, memory, offset, size, flags, &ppData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUnmapMemory(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUnmapMemory(device, memory);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFlushMappedMemoryRanges(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkFlushMappedMemoryRanges(return_value, device, memoryRangeCount, &pMemoryRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkInvalidateMappedMemoryRanges(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkInvalidateMappedMemoryRanges(return_value, device, memoryRangeCount, &pMemoryRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceMemoryCommitment(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    PointerDecoder<VkDeviceSize> pCommittedMemoryInBytes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += pCommittedMemoryInBytes.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceMemoryCommitment(device, memory, &pCommittedMemoryInBytes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryOffset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindBufferMemory(return_value, device, buffer, memory, memoryOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryOffset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindImageMemory(return_value, device, image, memory, memoryOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetBufferMemoryRequirements(device, buffer, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetImageMemoryRequirements(device, image, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetImageSparseMemoryRequirements(device, image, &pSparseMemoryRequirementCount, &pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueBindSparse(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkQueueBindSparse(return_value, queue, bindInfoCount, &pBindInfo, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateFence(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateFence(return_value, device, &pCreateInfo, &pAllocator, &pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyFence(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyFence(device, fence, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetFences(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkResetFences(return_value, device, fenceCount, &pFences);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceStatus(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetFenceStatus(return_value, device, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWaitForFences(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &waitAll);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkWaitForFences(return_value, device, fenceCount, &pFences, waitAll, timeout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSemaphore(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateSemaphore(return_value, device, &pCreateInfo, &pAllocator, &pSemaphore);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySemaphore(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroySemaphore(device, semaphore, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateEvent(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateEvent(return_value, device, &pCreateInfo, &pAllocator, &pEvent);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyEvent(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyEvent(device, event, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetEventStatus(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetEventStatus(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetEvent(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkSetEvent(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetEvent(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkResetEvent(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateQueryPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateQueryPool(return_value, device, &pCreateInfo, &pAllocator, &pQueryPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyQueryPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyQueryPool(device, queryPool, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetQueryPoolResults(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetQueryPoolResults(return_value, device, queryPool, firstQuery, queryCount, dataSize, &pData, stride, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateBuffer(return_value, device, &pCreateInfo, &pAllocator, &pBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyBuffer(device, buffer, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateBufferView(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateBufferView(return_value, device, &pCreateInfo, &pAllocator, &pView);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyBufferView(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyBufferView(device, bufferView, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImage(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateImage(return_value, device, &pCreateInfo, &pAllocator, &pImage);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyImage(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyImage(device, image, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSubresourceLayout(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetImageSubresourceLayout(device, image, &pSubresource, &pLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImageView(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateImageView(return_value, device, &pCreateInfo, &pAllocator, &pView);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyImageView(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyImageView(device, imageView, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateShaderModule(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateShaderModule(return_value, device, &pCreateInfo, &pAllocator, &pShaderModule);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyShaderModule(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyShaderModule(device, shaderModule, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePipelineCache(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreatePipelineCache(return_value, device, &pCreateInfo, &pAllocator, &pPipelineCache);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipelineCache(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyPipelineCache(device, pipelineCache, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineCacheData(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPipelineCacheData(return_value, device, pipelineCache, &pDataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMergePipelineCaches(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkMergePipelineCaches(return_value, device, dstCache, srcCacheCount, &pSrcCaches);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateGraphicsPipelines(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateGraphicsPipelines(return_value, device, pipelineCache, createInfoCount, &pCreateInfos, &pAllocator, &pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateComputePipelines(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateComputePipelines(return_value, device, pipelineCache, createInfoCount, &pCreateInfos, &pAllocator, &pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipeline(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyPipeline(device, pipeline, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePipelineLayout(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreatePipelineLayout(return_value, device, &pCreateInfo, &pAllocator, &pPipelineLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipelineLayout(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyPipelineLayout(device, pipelineLayout, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSampler(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateSampler(return_value, device, &pCreateInfo, &pAllocator, &pSampler);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySampler(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroySampler(device, sampler, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorSetLayout(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDescriptorSetLayout(return_value, device, &pCreateInfo, &pAllocator, &pSetLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorSetLayout(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyDescriptorSetLayout(device, descriptorSetLayout, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDescriptorPool(return_value, device, &pCreateInfo, &pAllocator, &pDescriptorPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyDescriptorPool(device, descriptorPool, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetDescriptorPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkResetDescriptorPool(return_value, device, descriptorPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkAllocateDescriptorSets(return_value, device, &pAllocateInfo, &pDescriptorSets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkFreeDescriptorSets(return_value, device, descriptorPool, descriptorSetCount, &pDescriptorSets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUpdateDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkUpdateDescriptorSets(device, descriptorWriteCount, &pDescriptorWrites, descriptorCopyCount, &pDescriptorCopies);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateFramebuffer(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateFramebuffer(return_value, device, &pCreateInfo, &pAllocator, &pFramebuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyFramebuffer(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyFramebuffer(device, framebuffer, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateRenderPass(return_value, device, &pCreateInfo, &pAllocator, &pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyRenderPass(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyRenderPass(device, renderPass, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRenderAreaGranularity(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetRenderAreaGranularity(device, renderPass, &pGranularity);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateCommandPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateCommandPool(return_value, device, &pCreateInfo, &pAllocator, &pCommandPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyCommandPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyCommandPool(device, commandPool, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetCommandPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkResetCommandPool(return_value, device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateCommandBuffers(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkAllocateCommandBuffers(return_value, device, &pAllocateInfo, &pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeCommandBuffers(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkFreeCommandBuffers(device, commandPool, commandBufferCount, &pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBeginCommandBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkBeginCommandBuffer(return_value, commandBuffer, &pBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEndCommandBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEndCommandBuffer(return_value, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetCommandBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkResetCommandBuffer(return_value, commandBuffer, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindPipeline(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewport(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, &pViewports);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetScissor(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, &pScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLineWidth(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float lineWidth;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineWidth);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetLineWidth(commandBuffer, lineWidth);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBias(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetBlendConstants(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    PointerDecoder<float> blendConstants;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += blendConstants.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetBlendConstants(commandBuffer, &blendConstants);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBounds(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilCompareMask(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilWriteMask(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilReference(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetStencilReference(commandBuffer, faceMask, reference);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, &pDescriptorSets, dynamicOffsetCount, &pDynamicOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindIndexBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkIndexType indexType;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indexType);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindVertexBuffers(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pOffsets.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, &pBuffers, &pOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDraw(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexed(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirect(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirect(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatch(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchIndirect(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatchIndirect(commandBuffer, buffer, offset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, &pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImage(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, &pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBlitImage(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, &pRegions, filter);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBufferToImage(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, &pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImageToBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, &pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdUpdateBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize dataSize;
    PointerDecoder<uint8_t> pData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdFillBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize size;
    uint32_t data;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &data);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearColorImage(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdClearColorImage(commandBuffer, image, imageLayout, &pColor, rangeCount, &pRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearDepthStencilImage(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, &pDepthStencil, rangeCount, &pRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearAttachments(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdClearAttachments(commandBuffer, attachmentCount, &pAttachments, rectCount, &pRects);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResolveImage(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, &pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetEvent(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetEvent(commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetEvent(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdResetEvent(commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWaitEvents(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdWaitEvents(commandBuffer, eventCount, &pEvents, srcStageMask, dstStageMask, memoryBarrierCount, &pMemoryBarriers, bufferMemoryBarrierCount, &pBufferMemoryBarriers, imageMemoryBarrierCount, &pImageMemoryBarriers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPipelineBarrier(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, &pMemoryBarriers, bufferMemoryBarrierCount, &pBufferMemoryBarriers, imageMemoryBarrierCount, &pImageMemoryBarriers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginQuery(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndQuery(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdEndQuery(commandBuffer, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetQueryPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteTimestamp(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyQueryPoolResults(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushConstants(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, &pValues);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdBeginRenderPass(commandBuffer, &pRenderPassBegin, contents);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &contents);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdNextSubpass(commandBuffer, contents);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderPass(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdExecuteCommands(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdExecuteCommands(commandBuffer, commandBufferCount, &pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkBindBufferMemory2(return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkBindImageMemory2(return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPeerMemoryFeatures(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, &pPeerMemoryFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDeviceMask(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDeviceMask(commandBuffer, deviceMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchBase(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceGroups(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkEnumeratePhysicalDeviceGroups(return_value, instance, &pPhysicalDeviceGroupCount, &pPhysicalDeviceGroupProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetImageMemoryRequirements2(device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetBufferMemoryRequirements2(device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetImageSparseMemoryRequirements2(device, &pInfo, &pSparseMemoryRequirementCount, &pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures2(physicalDevice, &pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties2(physicalDevice, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, &pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties2(return_value, physicalDevice, &pImageFormatInfo, &pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, &pQueueFamilyPropertyCount, &pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties2(physicalDevice, &pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, &pFormatInfo, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTrimCommandPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkTrimCommandPool(device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceQueue2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeviceQueue2(device, &pQueueInfo, &pQueue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSamplerYcbcrConversion(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateSamplerYcbcrConversion(return_value, device, &pCreateInfo, &pAllocator, &pYcbcrConversion);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySamplerYcbcrConversion(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroySamplerYcbcrConversion(device, ycbcrConversion, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorUpdateTemplate(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDescriptorUpdateTemplate(return_value, device, &pCreateInfo, &pAllocator, &pDescriptorUpdateTemplate);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorUpdateTemplate(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalBufferProperties(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, &pExternalBufferInfo, &pExternalBufferProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalFenceProperties(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, &pExternalFenceInfo, &pExternalFenceProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, &pExternalSemaphoreInfo, &pExternalSemaphoreProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutSupport(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDescriptorSetLayoutSupport(device, &pCreateInfo, &pSupport);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCount(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCount(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateRenderPass2(return_value, device, &pCreateInfo, &pAllocator, &pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdBeginRenderPass2(commandBuffer, &pRenderPassBegin, &pSubpassBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass2(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdNextSubpass2(commandBuffer, &pSubpassBeginInfo, &pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassEndInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderPass2(commandBuffer, &pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetQueryPool(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkResetQueryPool(device, queryPool, firstQuery, queryCount);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreCounterValue(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetSemaphoreCounterValue(return_value, device, semaphore, &pValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWaitSemaphores(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkWaitSemaphores(return_value, device, &pWaitInfo, timeout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSignalSemaphore(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkSignalSemaphore(return_value, device, &pSignalInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferDeviceAddress(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkDeviceAddressValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferDeviceAddress(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferOpaqueCaptureAddress(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetBufferOpaqueCaptureAddress(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceMemoryOpaqueCaptureAddress(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeviceMemoryOpaqueCaptureAddress(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroySurfaceKHR(instance, surface, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pSupported.DecodeVkBool32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceSupportKHR(return_value, physicalDevice, queueFamilyIndex, surface, &pSupported);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(return_value, physicalDevice, surface, &pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSurfaceFormatsKHR(return_value, physicalDevice, surface, &pSurfaceFormatCount, &pSurfaceFormats);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSurfacePresentModesKHR(return_value, physicalDevice, surface, &pPresentModeCount, &pPresentModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSwapchainKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateSwapchainKHR(return_value, device, &pCreateInfo, &pAllocator, &pSwapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySwapchainKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroySwapchainKHR(device, swapchain, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainImagesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetSwapchainImagesKHR(return_value, device, swapchain, &pSwapchainImageCount, &pSwapchainImages);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireNextImageKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkAcquireNextImageKHR(return_value, device, swapchain, timeout, semaphore, fence, &pImageIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueuePresentKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkQueuePresentKHR(return_value, queue, &pPresentInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPresentCapabilitiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeviceGroupPresentCapabilitiesKHR(return_value, device, &pDeviceGroupPresentCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupSurfacePresentModesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeviceGroupSurfacePresentModesKHR(return_value, device, surface, &pModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDevicePresentRectanglesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDevicePresentRectanglesKHR(return_value, physicalDevice, surface, &pRectCount, &pRects);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireNextImage2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkAcquireNextImage2KHR(return_value, device, &pAcquireInfo, &pImageIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceDisplayPropertiesKHR(return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneSupportedDisplaysKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDisplayPlaneSupportedDisplaysKHR(return_value, physicalDevice, planeIndex, &pDisplayCount, &pDisplays);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayModePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDisplayModePropertiesKHR(return_value, physicalDevice, display, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDisplayModeKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDisplayModeKHR(return_value, physicalDevice, display, &pCreateInfo, &pAllocator, &pMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneCapabilitiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDisplayPlaneCapabilitiesKHR(return_value, physicalDevice, mode, planeIndex, &pCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDisplayPlaneSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDisplayPlaneSurfaceKHR(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSharedSwapchainsKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateSharedSwapchainsKHR(return_value, device, swapchainCount, &pCreateInfos, &pAllocator, &pSwapchains);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateXlibSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateXlibSurfaceKHR(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, dpy, visualID);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateXcbSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateXcbSurfaceKHR(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, connection, visual_id);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateWaylandSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateWaylandSurfaceKHR(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t display;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateAndroidSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateAndroidSurfaceKHR(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateWin32SurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateWin32SurfaceKHR(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures2KHR(physicalDevice, &pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties2KHR(physicalDevice, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, &pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties2KHR(return_value, physicalDevice, &pImageFormatInfo, &pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, &pQueueFamilyPropertyCount, &pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice, &pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, &pFormatInfo, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, &pPeerMemoryFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDeviceMaskKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchBaseKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTrimCommandPoolKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkTrimCommandPoolKHR(device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceGroupsKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkEnumeratePhysicalDeviceGroupsKHR(return_value, instance, &pPhysicalDeviceGroupCount, &pPhysicalDeviceGroupProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, &pExternalBufferInfo, &pExternalBufferProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetMemoryWin32HandleKHR(return_value, device, &pGetWin32HandleInfo, &pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandlePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetMemoryWin32HandlePropertiesKHR(return_value, device, handleType, handle, &pMemoryWin32HandleProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryFdKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetMemoryFdKHR(return_value, device, &pGetFdInfo, &pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryFdPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetMemoryFdPropertiesKHR(return_value, device, handleType, fd, &pMemoryFdProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, &pExternalSemaphoreInfo, &pExternalSemaphoreProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportSemaphoreWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkImportSemaphoreWin32HandleKHR(return_value, device, &pImportSemaphoreWin32HandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetSemaphoreWin32HandleKHR(return_value, device, &pGetWin32HandleInfo, &pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportSemaphoreFdKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkImportSemaphoreFdKHR(return_value, device, &pImportSemaphoreFdInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreFdKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetSemaphoreFdKHR(return_value, device, &pGetFdInfo, &pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushDescriptorSetKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, &pDescriptorWrites);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorUpdateTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDescriptorUpdateTemplateKHR(return_value, device, &pCreateInfo, &pAllocator, &pDescriptorUpdateTemplate);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorUpdateTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateRenderPass2KHR(return_value, device, &pCreateInfo, &pAllocator, &pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdBeginRenderPass2KHR(commandBuffer, &pRenderPassBegin, &pSubpassBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdNextSubpass2KHR(commandBuffer, &pSubpassBeginInfo, &pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfo> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassEndInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderPass2KHR(commandBuffer, &pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainStatusKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetSwapchainStatusKHR(return_value, device, swapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, &pExternalFenceInfo, &pExternalFenceProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportFenceWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkImportFenceWin32HandleKHR(return_value, device, &pImportFenceWin32HandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetFenceWin32HandleKHR(return_value, device, &pGetWin32HandleInfo, &pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportFenceFdKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkImportFenceFdKHR(return_value, device, &pImportFenceFdInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceFdKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetFenceFdKHR(return_value, device, &pGetFdInfo, &pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(return_value, physicalDevice, queueFamilyIndex, &pCounterCount, &pCounters, &pCounterDescriptions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, &pPerformanceQueryCreateInfo, &pNumPasses);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireProfilingLockKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkAcquireProfilingLockKHR(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleaseProfilingLockKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkReleaseProfilingLockKHR(device);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(return_value, physicalDevice, &pSurfaceInfo, &pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSurfaceFormats2KHR(return_value, physicalDevice, &pSurfaceInfo, &pSurfaceFormatCount, &pSurfaceFormats);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceDisplayProperties2KHR(return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayModeProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDisplayModeProperties2KHR(return_value, physicalDevice, display, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneCapabilities2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDisplayPlaneCapabilities2KHR(return_value, physicalDevice, &pDisplayPlaneInfo, &pCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetImageMemoryRequirements2KHR(device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetBufferMemoryRequirements2KHR(device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetImageSparseMemoryRequirements2KHR(device, &pInfo, &pSparseMemoryRequirementCount, &pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSamplerYcbcrConversionKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateSamplerYcbcrConversionKHR(return_value, device, &pCreateInfo, &pAllocator, &pYcbcrConversion);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySamplerYcbcrConversionKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkBindBufferMemory2KHR(return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkBindImageMemory2KHR(return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDescriptorSetLayoutSupportKHR(device, &pCreateInfo, &pSupport);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCountKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCountKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreCounterValueKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetSemaphoreCounterValueKHR(return_value, device, semaphore, &pValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWaitSemaphoresKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkWaitSemaphoresKHR(return_value, device, &pWaitInfo, timeout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSignalSemaphoreKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkSignalSemaphoreKHR(return_value, device, &pSignalInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferDeviceAddressKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkDeviceAddressValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferDeviceAddressKHR(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferOpaqueCaptureAddressKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetBufferOpaqueCaptureAddressKHR(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceMemoryOpaqueCaptureAddressKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDeferredOperationKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDeferredOperationKHR(return_value, device, &pAllocator, &pDeferredOperation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDeferredOperationKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyDeferredOperationKHR(device, operation, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeferredOperationMaxConcurrencyKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeferredOperationMaxConcurrencyKHR(return_value, device, operation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeferredOperationResultKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeferredOperationResultKHR(return_value, device, operation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDeferredOperationJoinKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDeferredOperationJoinKHR(return_value, device, operation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineExecutablePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPipelineExecutablePropertiesKHR(return_value, device, &pPipelineInfo, &pExecutableCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineExecutableStatisticsKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPipelineExecutableStatisticsKHR(return_value, device, &pExecutableInfo, &pStatisticCount, &pStatistics);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineExecutableInternalRepresentationsKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPipelineExecutableInternalRepresentationsKHR(return_value, device, &pExecutableInfo, &pInternalRepresentationCount, &pInternalRepresentations);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDebugReportCallbackEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDebugReportCallbackEXT(return_value, instance, &pCreateInfo, &pAllocator, &pCallback);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDebugReportCallbackEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyDebugReportCallbackEXT(instance, callback, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugReportMessageEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, &pLayerPrefix, &pMessage);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugMarkerSetObjectTagEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDebugMarkerSetObjectTagEXT(return_value, device, &pTagInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugMarkerSetObjectNameEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDebugMarkerSetObjectNameEXT(return_value, device, &pNameInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerBeginEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerBeginEXT(commandBuffer, &pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerEndEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerEndEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerInsertEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerInsertEXT(commandBuffer, &pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindTransformFeedbackBuffersEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pOffsets.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizes.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, &pBuffers, &pOffsets, &pSizes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginTransformFeedbackEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCounterBufferOffsets.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, &pCounterBuffers, &pCounterBufferOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndTransformFeedbackEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pCounterBufferOffsets.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, &pCounterBuffers, &pCounterBufferOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginQueryIndexedEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndQueryIndexedEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectByteCountEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counterBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counterOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexStride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageViewHandleNVX(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetImageViewHandleNVX(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageViewAddressNVX(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetImageViewAddressNVX(return_value, device, imageView, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCountAMD(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCountAMD(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetShaderInfoAMD(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetShaderInfoAMD(return_value, device, pipeline, shaderStage, infoType, &pInfoSize, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateStreamDescriptorSurfaceGGP(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateStreamDescriptorSurfaceGGP(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(return_value, physicalDevice, format, type, tiling, usage, flags, externalHandleType, &pExternalImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandleNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetMemoryWin32HandleNV(return_value, device, memory, handleType, &pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateViSurfaceNN(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateViSurfaceNN(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginConditionalRenderingEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT> pConditionalRenderingBegin;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pConditionalRenderingBegin.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginConditionalRenderingEXT(commandBuffer, &pConditionalRenderingBegin);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndConditionalRenderingEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndConditionalRenderingEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportWScalingNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, &pViewportWScalings);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleaseDisplayEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkReleaseDisplayEXT(return_value, physicalDevice, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireXlibDisplayEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkAcquireXlibDisplayEXT(return_value, physicalDevice, dpy, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRandROutputDisplayEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetRandROutputDisplayEXT(return_value, physicalDevice, dpy, rrOutput, &pDisplay);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(return_value, physicalDevice, surface, &pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDisplayPowerControlEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDisplayPowerControlEXT(return_value, device, display, &pDisplayPowerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterDeviceEventEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkRegisterDeviceEventEXT(return_value, device, &pDeviceEventInfo, &pAllocator, &pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterDisplayEventEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkRegisterDisplayEventEXT(return_value, device, display, &pDisplayEventInfo, &pAllocator, &pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainCounterEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetSwapchainCounterEXT(return_value, device, swapchain, counter, &pCounterValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRefreshCycleDurationGOOGLE(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetRefreshCycleDurationGOOGLE(return_value, device, swapchain, &pDisplayTimingProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPastPresentationTimingGOOGLE(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPastPresentationTimingGOOGLE(return_value, device, swapchain, &pPresentationTimingCount, &pPresentationTimings);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDiscardRectangleEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, &pDiscardRectangles);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetHdrMetadataEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkSetHdrMetadataEXT(device, swapchainCount, &pSwapchains, &pMetadata);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateIOSSurfaceMVK(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateIOSSurfaceMVK(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateMacOSSurfaceMVK(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateMacOSSurfaceMVK(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetDebugUtilsObjectNameEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkSetDebugUtilsObjectNameEXT(return_value, device, &pNameInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetDebugUtilsObjectTagEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkSetDebugUtilsObjectTagEXT(return_value, device, &pTagInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueBeginDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueBeginDebugUtilsLabelEXT(queue, &pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueEndDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueEndDebugUtilsLabelEXT(queue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueInsertDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueInsertDebugUtilsLabelEXT(queue, &pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginDebugUtilsLabelEXT(commandBuffer, &pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndDebugUtilsLabelEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdInsertDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdInsertDebugUtilsLabelEXT(commandBuffer, &pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDebugUtilsMessengerEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDebugUtilsMessengerEXT(return_value, instance, &pCreateInfo, &pAllocator, &pMessenger);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDebugUtilsMessengerEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyDebugUtilsMessengerEXT(instance, messenger, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSubmitDebugUtilsMessageEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, &pCallbackData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAndroidHardwareBufferPropertiesANDROID(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetAndroidHardwareBufferPropertiesANDROID(return_value, device, buffer, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryAndroidHardwareBufferANDROID(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetMemoryAndroidHardwareBufferANDROID(return_value, device, &pInfo, &pBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetSampleLocationsEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT> pSampleLocationsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSampleLocationsInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetSampleLocationsEXT(commandBuffer, &pSampleLocationsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, &pMultisampleProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageDrmFormatModifierPropertiesEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetImageDrmFormatModifierPropertiesEXT(return_value, device, image, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateValidationCacheEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateValidationCacheEXT(return_value, device, &pCreateInfo, &pAllocator, &pValidationCache);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyValidationCacheEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyValidationCacheEXT(device, validationCache, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMergeValidationCachesEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkMergeValidationCachesEXT(return_value, device, dstCache, srcCacheCount, &pSrcCaches);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetValidationCacheDataEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetValidationCacheDataEXT(return_value, device, validationCache, &pDataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindShadingRateImageNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportShadingRatePaletteNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, &pShadingRatePalettes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCoarseSampleOrderNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, &pCustomSampleOrders);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateAccelerationStructureNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateAccelerationStructureNV(return_value, device, &pCreateInfo, &pAllocator, &pAccelerationStructure);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyAccelerationStructureKHR(device, accelerationStructure, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyAccelerationStructureNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyAccelerationStructureNV(device, accelerationStructure, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureMemoryRequirementsNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetAccelerationStructureMemoryRequirementsNV(device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindAccelerationStructureMemoryKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoKHR> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindAccelerationStructureMemoryKHR(return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindAccelerationStructureMemoryNV(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoKHR> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindAccelerationStructureMemoryNV(return_value, device, bindInfoCount, &pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBuildAccelerationStructureNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceOffset);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &update);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dst);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &src);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scratch);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scratchOffset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBuildAccelerationStructureNV(commandBuffer, &pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyAccelerationStructureNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdTraceRaysNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &raygenShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &missShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &missShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &missShaderBindingStride);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hitShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hitShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hitShaderBindingStride);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callableShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callableShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callableShaderBindingStride);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &width);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &height);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depth);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRayTracingPipelinesNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateRayTracingPipelinesNV(return_value, device, pipelineCache, createInfoCount, &pCreateInfos, &pAllocator, &pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRayTracingShaderGroupHandlesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetRayTracingShaderGroupHandlesKHR(return_value, device, pipeline, firstGroup, groupCount, dataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRayTracingShaderGroupHandlesNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetRayTracingShaderGroupHandlesNV(return_value, device, pipeline, firstGroup, groupCount, dataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureHandleNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetAccelerationStructureHandleNV(return_value, device, accelerationStructure, dataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteAccelerationStructuresPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, &pAccelerationStructures, queryType, queryPool, firstQuery);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteAccelerationStructuresPropertiesNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, &pAccelerationStructures, queryType, queryPool, firstQuery);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCompileDeferredNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCompileDeferredNV(return_value, device, pipeline, shader);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryHostPointerPropertiesEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetMemoryHostPointerPropertiesEXT(return_value, device, handleType, pHostPointer, &pMemoryHostPointerProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteBufferMarkerAMD(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &marker);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pTimeDomainCount;
    PointerDecoder<VkTimeDomainEXT> pTimeDomains;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pTimeDomainCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTimeDomains.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(return_value, physicalDevice, &pTimeDomainCount, &pTimeDomains);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetCalibratedTimestampsEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t timestampCount;
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT> pTimestampInfos;
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
        consumer->Process_vkGetCalibratedTimestampsEXT(return_value, device, timestampCount, &pTimestampInfos, &pTimestamps, &pMaxDeviation);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksIndirectNV(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksIndirectCountNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetExclusiveScissorNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, &pExclusiveScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCheckpointNV(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint64_t pCheckpointMarker;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCheckpointMarker);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetQueueCheckpointDataNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetQueueCheckpointDataNV(queue, &pCheckpointDataCount, &pCheckpointData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkInitializePerformanceApiINTEL(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkInitializePerformanceApiINTEL(return_value, device, &pInitializeInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUninitializePerformanceApiINTEL(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUninitializePerformanceApiINTEL(device);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPerformanceMarkerINTEL(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetPerformanceMarkerINTEL(return_value, commandBuffer, &pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPerformanceStreamMarkerINTEL(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetPerformanceStreamMarkerINTEL(return_value, commandBuffer, &pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPerformanceOverrideINTEL(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetPerformanceOverrideINTEL(return_value, commandBuffer, &pOverrideInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquirePerformanceConfigurationINTEL(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkAcquirePerformanceConfigurationINTEL(return_value, device, &pAcquireInfo, &pConfiguration);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleasePerformanceConfigurationINTEL(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkReleasePerformanceConfigurationINTEL(return_value, device, configuration);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueSetPerformanceConfigurationINTEL(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkQueueSetPerformanceConfigurationINTEL(return_value, queue, configuration);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPerformanceParameterINTEL(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPerformanceParameterINTEL(return_value, device, parameter, &pValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetLocalDimmingAMD(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapChain;
    VkBool32 localDimmingEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapChain);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &localDimmingEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImagePipeSurfaceFUCHSIA(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateImagePipeSurfaceFUCHSIA(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateMetalSurfaceEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateMetalSurfaceEXT(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferDeviceAddressEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkDeviceAddressValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferDeviceAddressEXT(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceToolPropertiesEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pToolCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolPropertiesEXT> pToolProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pToolCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pToolProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceToolPropertiesEXT(return_value, physicalDevice, &pToolCount, &pToolProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(return_value, physicalDevice, &pPropertyCount, &pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(return_value, physicalDevice, &pCombinationCount, &pCombinations);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfacePresentModes2EXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(return_value, physicalDevice, &pSurfaceInfo, &pPresentModeCount, &pPresentModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireFullScreenExclusiveModeEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkAcquireFullScreenExclusiveModeEXT(return_value, device, swapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleaseFullScreenExclusiveModeEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkReleaseFullScreenExclusiveModeEXT(return_value, device, swapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupSurfacePresentModes2EXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetDeviceGroupSurfacePresentModes2EXT(return_value, device, &pSurfaceInfo, &pModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateHeadlessSurfaceEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateHeadlessSurfaceEXT(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLineStippleEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetQueryPoolEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkResetQueryPoolEXT(device, queryPool, firstQuery, queryCount);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCullModeEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCullModeFlags cullMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &cullMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCullModeEXT(commandBuffer, cullMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetFrontFaceEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkFrontFace frontFace;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &frontFace);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetFrontFaceEXT(commandBuffer, frontFace);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetPrimitiveTopologyEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPrimitiveTopology primitiveTopology;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &primitiveTopology);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportWithCountEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetViewportWithCountEXT(commandBuffer, viewportCount, &pViewports);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetScissorWithCountEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetScissorWithCountEXT(commandBuffer, scissorCount, &pScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindVertexBuffers2EXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
    bytes_read += pOffsets.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSizes.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pStrides.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, &pBuffers, &pOffsets, &pSizes, &pStrides);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthTestEnableEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthTestEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthWriteEnableEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthWriteEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthWriteEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthCompareOpEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCompareOp depthCompareOp;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthCompareOp);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBoundsTestEnableEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 depthBoundsTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBoundsTestEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilTestEnableEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 stencilTestEnable;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stencilTestEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilOpEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetGeneratedCommandsMemoryRequirementsNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetGeneratedCommandsMemoryRequirementsNV(device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPreprocessGeneratedCommandsNV(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pGeneratedCommandsInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPreprocessGeneratedCommandsNV(commandBuffer, &pGeneratedCommandsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdExecuteGeneratedCommandsNV(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkBool32 isPreprocessed;
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV> pGeneratedCommandsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &isPreprocessed);
    bytes_read += pGeneratedCommandsInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, &pGeneratedCommandsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindPipelineShaderGroupNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateIndirectCommandsLayoutNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateIndirectCommandsLayoutNV(return_value, device, &pCreateInfo, &pAllocator, &pIndirectCommandsLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyIndirectCommandsLayoutNV(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePrivateDataSlotEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    HandlePointerDecoder<VkPrivateDataSlotEXT> pPrivateDataSlot;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPrivateDataSlot.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreatePrivateDataSlotEXT(return_value, device, &pCreateInfo, &pAllocator, &pPrivateDataSlot);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPrivateDataSlotEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkDestroyPrivateDataSlotEXT(device, privateDataSlot, &pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetPrivateDataEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkSetPrivateDataEXT(return_value, device, objectType, objectHandle, privateDataSlot, data);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPrivateDataEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDirectFBSurfaceEXT(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateDirectFBSurfaceEXT(return_value, instance, &pCreateInfo, &pAllocator, &pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t dfb;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dfb);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(return_value, physicalDevice, queueFamilyIndex, dfb);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkCreateAccelerationStructureKHR(return_value, device, &pCreateInfo, &pAllocator, &pAccelerationStructure);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureMemoryRequirementsKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoKHR> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureMemoryRequirementsKHR(device, &pInfo, &pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBuildAccelerationStructureIndirectKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR> pInfo;
    format::HandleId indirectBuffer;
    VkDeviceSize indirectOffset;
    uint32_t indirectStride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indirectBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indirectOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indirectStride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBuildAccelerationStructureIndirectKHR(commandBuffer, &pInfo, indirectBuffer, indirectOffset, indirectStride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyAccelerationStructureKHR(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyAccelerationStructureToMemoryKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyAccelerationStructureToMemoryKHR(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCopyMemoryToAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCopyMemoryToAccelerationStructureKHR(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWriteAccelerationStructuresPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkWriteAccelerationStructuresPropertiesKHR(return_value, device, accelerationStructureCount, &pAccelerationStructures, queryType, dataSize, &pData, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyAccelerationStructureKHR(commandBuffer, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyAccelerationStructureToMemoryKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyMemoryToAccelerationStructureKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR> pInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdTraceRaysKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR> pRaygenShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR> pMissShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR> pHitShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR> pCallableShaderBindingTable;
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
        consumer->Process_vkCmdTraceRaysKHR(commandBuffer, &pRaygenShaderBindingTable, &pMissShaderBindingTable, &pHitShaderBindingTable, &pCallableShaderBindingTable, width, height, depth);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRayTracingPipelinesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR> pCreateInfos;
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
        consumer->Process_vkCreateRayTracingPipelinesKHR(return_value, device, pipelineCache, createInfoCount, &pCreateInfos, &pAllocator, &pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureDeviceAddressKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR> pInfo;
    VkDeviceAddress return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkDeviceAddressValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureDeviceAddressKHR(return_value, device, &pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
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
        consumer->Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(return_value, device, pipeline, firstGroup, groupCount, dataSize, &pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdTraceRaysIndirectKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR> pRaygenShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR> pMissShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR> pHitShaderBindingTable;
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR> pCallableShaderBindingTable;
    format::HandleId buffer;
    VkDeviceSize offset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRaygenShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMissShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHitShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCallableShaderBindingTable.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdTraceRaysIndirectKHR(commandBuffer, &pRaygenShaderBindingTable, &pMissShaderBindingTable, &pHitShaderBindingTable, &pCallableShaderBindingTable, buffer, offset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceAccelerationStructureCompatibilityKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionKHR> version;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += version.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceAccelerationStructureCompatibilityKHR(return_value, device, &version);
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
        Decode_vkCreateInstance(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyInstance:
        Decode_vkDestroyInstance(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices:
        Decode_vkEnumeratePhysicalDevices(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures:
        Decode_vkGetPhysicalDeviceFeatures(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties:
        Decode_vkGetPhysicalDeviceFormatProperties(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties:
        Decode_vkGetPhysicalDeviceImageFormatProperties(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties:
        Decode_vkGetPhysicalDeviceProperties(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties:
        Decode_vkGetPhysicalDeviceMemoryProperties(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDevice:
        Decode_vkCreateDevice(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDevice:
        Decode_vkDestroyDevice(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceQueue:
        Decode_vkGetDeviceQueue(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueSubmit:
        Decode_vkQueueSubmit(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueWaitIdle:
        Decode_vkQueueWaitIdle(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDeviceWaitIdle:
        Decode_vkDeviceWaitIdle(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateMemory:
        Decode_vkAllocateMemory(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeMemory:
        Decode_vkFreeMemory(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMapMemory:
        Decode_vkMapMemory(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUnmapMemory:
        Decode_vkUnmapMemory(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges:
        Decode_vkFlushMappedMemoryRanges(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges:
        Decode_vkInvalidateMappedMemoryRanges(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment:
        Decode_vkGetDeviceMemoryCommitment(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory:
        Decode_vkBindBufferMemory(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory:
        Decode_vkBindImageMemory(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements:
        Decode_vkGetBufferMemoryRequirements(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements:
        Decode_vkGetImageMemoryRequirements(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements:
        Decode_vkGetImageSparseMemoryRequirements(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueBindSparse:
        Decode_vkQueueBindSparse(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateFence:
        Decode_vkCreateFence(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyFence:
        Decode_vkDestroyFence(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetFences:
        Decode_vkResetFences(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceStatus:
        Decode_vkGetFenceStatus(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWaitForFences:
        Decode_vkWaitForFences(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSemaphore:
        Decode_vkCreateSemaphore(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySemaphore:
        Decode_vkDestroySemaphore(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateEvent:
        Decode_vkCreateEvent(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyEvent:
        Decode_vkDestroyEvent(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetEventStatus:
        Decode_vkGetEventStatus(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetEvent:
        Decode_vkSetEvent(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetEvent:
        Decode_vkResetEvent(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateQueryPool:
        Decode_vkCreateQueryPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyQueryPool:
        Decode_vkDestroyQueryPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetQueryPoolResults:
        Decode_vkGetQueryPoolResults(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateBuffer:
        Decode_vkCreateBuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyBuffer:
        Decode_vkDestroyBuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateBufferView:
        Decode_vkCreateBufferView(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyBufferView:
        Decode_vkDestroyBufferView(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImage:
        Decode_vkCreateImage(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyImage:
        Decode_vkDestroyImage(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSubresourceLayout:
        Decode_vkGetImageSubresourceLayout(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImageView:
        Decode_vkCreateImageView(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyImageView:
        Decode_vkDestroyImageView(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateShaderModule:
        Decode_vkCreateShaderModule(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyShaderModule:
        Decode_vkDestroyShaderModule(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePipelineCache:
        Decode_vkCreatePipelineCache(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipelineCache:
        Decode_vkDestroyPipelineCache(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineCacheData:
        Decode_vkGetPipelineCacheData(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMergePipelineCaches:
        Decode_vkMergePipelineCaches(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateGraphicsPipelines:
        Decode_vkCreateGraphicsPipelines(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateComputePipelines:
        Decode_vkCreateComputePipelines(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipeline:
        Decode_vkDestroyPipeline(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePipelineLayout:
        Decode_vkCreatePipelineLayout(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipelineLayout:
        Decode_vkDestroyPipelineLayout(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSampler:
        Decode_vkCreateSampler(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySampler:
        Decode_vkDestroySampler(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout:
        Decode_vkCreateDescriptorSetLayout(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout:
        Decode_vkDestroyDescriptorSetLayout(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorPool:
        Decode_vkCreateDescriptorPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorPool:
        Decode_vkDestroyDescriptorPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetDescriptorPool:
        Decode_vkResetDescriptorPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateDescriptorSets:
        Decode_vkAllocateDescriptorSets(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeDescriptorSets:
        Decode_vkFreeDescriptorSets(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUpdateDescriptorSets:
        Decode_vkUpdateDescriptorSets(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateFramebuffer:
        Decode_vkCreateFramebuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyFramebuffer:
        Decode_vkDestroyFramebuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRenderPass:
        Decode_vkCreateRenderPass(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyRenderPass:
        Decode_vkDestroyRenderPass(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRenderAreaGranularity:
        Decode_vkGetRenderAreaGranularity(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateCommandPool:
        Decode_vkCreateCommandPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyCommandPool:
        Decode_vkDestroyCommandPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetCommandPool:
        Decode_vkResetCommandPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateCommandBuffers:
        Decode_vkAllocateCommandBuffers(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeCommandBuffers:
        Decode_vkFreeCommandBuffers(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBeginCommandBuffer:
        Decode_vkBeginCommandBuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEndCommandBuffer:
        Decode_vkEndCommandBuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetCommandBuffer:
        Decode_vkResetCommandBuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindPipeline:
        Decode_vkCmdBindPipeline(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewport:
        Decode_vkCmdSetViewport(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetScissor:
        Decode_vkCmdSetScissor(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLineWidth:
        Decode_vkCmdSetLineWidth(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBias:
        Decode_vkCmdSetDepthBias(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetBlendConstants:
        Decode_vkCmdSetBlendConstants(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBounds:
        Decode_vkCmdSetDepthBounds(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask:
        Decode_vkCmdSetStencilCompareMask(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask:
        Decode_vkCmdSetStencilWriteMask(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilReference:
        Decode_vkCmdSetStencilReference(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindDescriptorSets:
        Decode_vkCmdBindDescriptorSets(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindIndexBuffer:
        Decode_vkCmdBindIndexBuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindVertexBuffers:
        Decode_vkCmdBindVertexBuffers(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDraw:
        Decode_vkCmdDraw(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexed:
        Decode_vkCmdDrawIndexed(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirect:
        Decode_vkCmdDrawIndirect(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect:
        Decode_vkCmdDrawIndexedIndirect(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatch:
        Decode_vkCmdDispatch(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchIndirect:
        Decode_vkCmdDispatchIndirect(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBuffer:
        Decode_vkCmdCopyBuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImage:
        Decode_vkCmdCopyImage(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBlitImage:
        Decode_vkCmdBlitImage(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBufferToImage:
        Decode_vkCmdCopyBufferToImage(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer:
        Decode_vkCmdCopyImageToBuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdUpdateBuffer:
        Decode_vkCmdUpdateBuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdFillBuffer:
        Decode_vkCmdFillBuffer(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearColorImage:
        Decode_vkCmdClearColorImage(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage:
        Decode_vkCmdClearDepthStencilImage(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearAttachments:
        Decode_vkCmdClearAttachments(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResolveImage:
        Decode_vkCmdResolveImage(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetEvent:
        Decode_vkCmdSetEvent(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResetEvent:
        Decode_vkCmdResetEvent(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWaitEvents:
        Decode_vkCmdWaitEvents(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPipelineBarrier:
        Decode_vkCmdPipelineBarrier(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginQuery:
        Decode_vkCmdBeginQuery(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndQuery:
        Decode_vkCmdEndQuery(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResetQueryPool:
        Decode_vkCmdResetQueryPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteTimestamp:
        Decode_vkCmdWriteTimestamp(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults:
        Decode_vkCmdCopyQueryPoolResults(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushConstants:
        Decode_vkCmdPushConstants(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderPass:
        Decode_vkCmdBeginRenderPass(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdNextSubpass:
        Decode_vkCmdNextSubpass(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderPass:
        Decode_vkCmdEndRenderPass(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdExecuteCommands:
        Decode_vkCmdExecuteCommands(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory2:
        Decode_vkBindBufferMemory2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory2:
        Decode_vkBindImageMemory2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures:
        Decode_vkGetDeviceGroupPeerMemoryFeatures(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDeviceMask:
        Decode_vkCmdSetDeviceMask(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchBase:
        Decode_vkCmdDispatchBase(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups:
        Decode_vkEnumeratePhysicalDeviceGroups(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2:
        Decode_vkGetImageMemoryRequirements2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2:
        Decode_vkGetBufferMemoryRequirements2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2:
        Decode_vkGetImageSparseMemoryRequirements2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2:
        Decode_vkGetPhysicalDeviceFeatures2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2:
        Decode_vkGetPhysicalDeviceProperties2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2:
        Decode_vkGetPhysicalDeviceFormatProperties2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2:
        Decode_vkGetPhysicalDeviceImageFormatProperties2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2:
        Decode_vkGetPhysicalDeviceMemoryProperties2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkTrimCommandPool:
        Decode_vkTrimCommandPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceQueue2:
        Decode_vkGetDeviceQueue2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion:
        Decode_vkCreateSamplerYcbcrConversion(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion:
        Decode_vkDestroySamplerYcbcrConversion(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate:
        Decode_vkCreateDescriptorUpdateTemplate(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate:
        Decode_vkDestroyDescriptorUpdateTemplate(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties:
        Decode_vkGetPhysicalDeviceExternalBufferProperties(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties:
        Decode_vkGetPhysicalDeviceExternalFenceProperties(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties:
        Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport:
        Decode_vkGetDescriptorSetLayoutSupport(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectCount:
        Decode_vkCmdDrawIndirectCount(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount:
        Decode_vkCmdDrawIndexedIndirectCount(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRenderPass2:
        Decode_vkCreateRenderPass2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderPass2:
        Decode_vkCmdBeginRenderPass2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdNextSubpass2:
        Decode_vkCmdNextSubpass2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderPass2:
        Decode_vkCmdEndRenderPass2(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetQueryPool:
        Decode_vkResetQueryPool(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue:
        Decode_vkGetSemaphoreCounterValue(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWaitSemaphores:
        Decode_vkWaitSemaphores(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSignalSemaphore:
        Decode_vkSignalSemaphore(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferDeviceAddress:
        Decode_vkGetBufferDeviceAddress(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress:
        Decode_vkGetBufferOpaqueCaptureAddress(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress:
        Decode_vkGetDeviceMemoryOpaqueCaptureAddress(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySurfaceKHR:
        Decode_vkDestroySurfaceKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR:
        Decode_vkGetPhysicalDeviceSurfaceSupportKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR:
        Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR:
        Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR:
        Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSwapchainKHR:
        Decode_vkCreateSwapchainKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySwapchainKHR:
        Decode_vkDestroySwapchainKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR:
        Decode_vkGetSwapchainImagesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireNextImageKHR:
        Decode_vkAcquireNextImageKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueuePresentKHR:
        Decode_vkQueuePresentKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR:
        Decode_vkGetDeviceGroupPresentCapabilitiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR:
        Decode_vkGetDeviceGroupSurfacePresentModesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR:
        Decode_vkGetPhysicalDevicePresentRectanglesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireNextImage2KHR:
        Decode_vkAcquireNextImage2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR:
        Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR:
        Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR:
        Decode_vkGetDisplayPlaneSupportedDisplaysKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR:
        Decode_vkGetDisplayModePropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDisplayModeKHR:
        Decode_vkCreateDisplayModeKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR:
        Decode_vkGetDisplayPlaneCapabilitiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR:
        Decode_vkCreateDisplayPlaneSurfaceKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR:
        Decode_vkCreateSharedSwapchainsKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR:
        Decode_vkCreateXlibSurfaceKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR:
        Decode_vkCreateXcbSurfaceKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR:
        Decode_vkCreateWaylandSurfaceKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR:
        Decode_vkCreateAndroidSurfaceKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR:
        Decode_vkCreateWin32SurfaceKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR:
        Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR:
        Decode_vkGetPhysicalDeviceFeatures2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR:
        Decode_vkGetPhysicalDeviceProperties2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceFormatProperties2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR:
        Decode_vkGetPhysicalDeviceMemoryProperties2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR:
        Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR:
        Decode_vkCmdSetDeviceMaskKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR:
        Decode_vkCmdDispatchBaseKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkTrimCommandPoolKHR:
        Decode_vkTrimCommandPoolKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR:
        Decode_vkEnumeratePhysicalDeviceGroupsKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR:
        Decode_vkGetMemoryWin32HandleKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR:
        Decode_vkGetMemoryWin32HandlePropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryFdKHR:
        Decode_vkGetMemoryFdKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR:
        Decode_vkGetMemoryFdPropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR:
        Decode_vkImportSemaphoreWin32HandleKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR:
        Decode_vkGetSemaphoreWin32HandleKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR:
        Decode_vkImportSemaphoreFdKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR:
        Decode_vkGetSemaphoreFdKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR:
        Decode_vkCmdPushDescriptorSetKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR:
        Decode_vkCreateDescriptorUpdateTemplateKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR:
        Decode_vkDestroyDescriptorUpdateTemplateKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRenderPass2KHR:
        Decode_vkCreateRenderPass2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR:
        Decode_vkCmdBeginRenderPass2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR:
        Decode_vkCmdNextSubpass2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR:
        Decode_vkCmdEndRenderPass2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR:
        Decode_vkGetSwapchainStatusKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR:
        Decode_vkImportFenceWin32HandleKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR:
        Decode_vkGetFenceWin32HandleKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportFenceFdKHR:
        Decode_vkImportFenceFdKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceFdKHR:
        Decode_vkGetFenceFdKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR:
        Decode_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR:
        Decode_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR:
        Decode_vkAcquireProfilingLockKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR:
        Decode_vkReleaseProfilingLockKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR:
        Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR:
        Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR:
        Decode_vkGetPhysicalDeviceDisplayProperties2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR:
        Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR:
        Decode_vkGetDisplayModeProperties2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR:
        Decode_vkGetDisplayPlaneCapabilities2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR:
        Decode_vkGetImageMemoryRequirements2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR:
        Decode_vkGetBufferMemoryRequirements2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR:
        Decode_vkGetImageSparseMemoryRequirements2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR:
        Decode_vkCreateSamplerYcbcrConversionKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR:
        Decode_vkDestroySamplerYcbcrConversionKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory2KHR:
        Decode_vkBindBufferMemory2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory2KHR:
        Decode_vkBindImageMemory2KHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR:
        Decode_vkGetDescriptorSetLayoutSupportKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR:
        Decode_vkCmdDrawIndirectCountKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR:
        Decode_vkCmdDrawIndexedIndirectCountKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR:
        Decode_vkGetSemaphoreCounterValueKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWaitSemaphoresKHR:
        Decode_vkWaitSemaphoresKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSignalSemaphoreKHR:
        Decode_vkSignalSemaphoreKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR:
        Decode_vkGetBufferDeviceAddressKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR:
        Decode_vkGetBufferOpaqueCaptureAddressKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR:
        Decode_vkGetDeviceMemoryOpaqueCaptureAddressKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR:
        Decode_vkCreateDeferredOperationKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR:
        Decode_vkDestroyDeferredOperationKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR:
        Decode_vkGetDeferredOperationMaxConcurrencyKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR:
        Decode_vkGetDeferredOperationResultKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR:
        Decode_vkDeferredOperationJoinKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR:
        Decode_vkGetPipelineExecutablePropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR:
        Decode_vkGetPipelineExecutableStatisticsKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR:
        Decode_vkGetPipelineExecutableInternalRepresentationsKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT:
        Decode_vkCreateDebugReportCallbackEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT:
        Decode_vkDestroyDebugReportCallbackEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugReportMessageEXT:
        Decode_vkDebugReportMessageEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT:
        Decode_vkDebugMarkerSetObjectTagEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT:
        Decode_vkDebugMarkerSetObjectNameEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT:
        Decode_vkCmdDebugMarkerBeginEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT:
        Decode_vkCmdDebugMarkerEndEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT:
        Decode_vkCmdDebugMarkerInsertEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT:
        Decode_vkCmdBindTransformFeedbackBuffersEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT:
        Decode_vkCmdBeginTransformFeedbackEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT:
        Decode_vkCmdEndTransformFeedbackEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT:
        Decode_vkCmdBeginQueryIndexedEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT:
        Decode_vkCmdEndQueryIndexedEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT:
        Decode_vkCmdDrawIndirectByteCountEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageViewHandleNVX:
        Decode_vkGetImageViewHandleNVX(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageViewAddressNVX:
        Decode_vkGetImageViewAddressNVX(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD:
        Decode_vkCmdDrawIndirectCountAMD(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD:
        Decode_vkCmdDrawIndexedIndirectCountAMD(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetShaderInfoAMD:
        Decode_vkGetShaderInfoAMD(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP:
        Decode_vkCreateStreamDescriptorSurfaceGGP(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV:
        Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV:
        Decode_vkGetMemoryWin32HandleNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateViSurfaceNN:
        Decode_vkCreateViSurfaceNN(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT:
        Decode_vkCmdBeginConditionalRenderingEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT:
        Decode_vkCmdEndConditionalRenderingEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV:
        Decode_vkCmdSetViewportWScalingNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleaseDisplayEXT:
        Decode_vkReleaseDisplayEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT:
        Decode_vkAcquireXlibDisplayEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT:
        Decode_vkGetRandROutputDisplayEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT:
        Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDisplayPowerControlEXT:
        Decode_vkDisplayPowerControlEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT:
        Decode_vkRegisterDeviceEventEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT:
        Decode_vkRegisterDisplayEventEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT:
        Decode_vkGetSwapchainCounterEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE:
        Decode_vkGetRefreshCycleDurationGOOGLE(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE:
        Decode_vkGetPastPresentationTimingGOOGLE(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT:
        Decode_vkCmdSetDiscardRectangleEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetHdrMetadataEXT:
        Decode_vkSetHdrMetadataEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK:
        Decode_vkCreateIOSSurfaceMVK(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK:
        Decode_vkCreateMacOSSurfaceMVK(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT:
        Decode_vkSetDebugUtilsObjectNameEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT:
        Decode_vkSetDebugUtilsObjectTagEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT:
        Decode_vkQueueBeginDebugUtilsLabelEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT:
        Decode_vkQueueEndDebugUtilsLabelEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT:
        Decode_vkQueueInsertDebugUtilsLabelEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT:
        Decode_vkCmdBeginDebugUtilsLabelEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT:
        Decode_vkCmdEndDebugUtilsLabelEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT:
        Decode_vkCmdInsertDebugUtilsLabelEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT:
        Decode_vkCreateDebugUtilsMessengerEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT:
        Decode_vkDestroyDebugUtilsMessengerEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT:
        Decode_vkSubmitDebugUtilsMessageEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID:
        Decode_vkGetAndroidHardwareBufferPropertiesANDROID(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID:
        Decode_vkGetMemoryAndroidHardwareBufferANDROID(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT:
        Decode_vkCmdSetSampleLocationsEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT:
        Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT:
        Decode_vkGetImageDrmFormatModifierPropertiesEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateValidationCacheEXT:
        Decode_vkCreateValidationCacheEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT:
        Decode_vkDestroyValidationCacheEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMergeValidationCachesEXT:
        Decode_vkMergeValidationCachesEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT:
        Decode_vkGetValidationCacheDataEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV:
        Decode_vkCmdBindShadingRateImageNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV:
        Decode_vkCmdSetViewportShadingRatePaletteNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV:
        Decode_vkCmdSetCoarseSampleOrderNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV:
        Decode_vkCreateAccelerationStructureNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR:
        Decode_vkDestroyAccelerationStructureKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV:
        Decode_vkDestroyAccelerationStructureNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV:
        Decode_vkGetAccelerationStructureMemoryRequirementsNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryKHR:
        Decode_vkBindAccelerationStructureMemoryKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV:
        Decode_vkBindAccelerationStructureMemoryNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV:
        Decode_vkCmdBuildAccelerationStructureNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV:
        Decode_vkCmdCopyAccelerationStructureNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdTraceRaysNV:
        Decode_vkCmdTraceRaysNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV:
        Decode_vkCreateRayTracingPipelinesNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR:
        Decode_vkGetRayTracingShaderGroupHandlesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV:
        Decode_vkGetRayTracingShaderGroupHandlesNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV:
        Decode_vkGetAccelerationStructureHandleNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR:
        Decode_vkCmdWriteAccelerationStructuresPropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV:
        Decode_vkCmdWriteAccelerationStructuresPropertiesNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCompileDeferredNV:
        Decode_vkCompileDeferredNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT:
        Decode_vkGetMemoryHostPointerPropertiesEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD:
        Decode_vkCmdWriteBufferMarkerAMD(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT:
        Decode_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT:
        Decode_vkGetCalibratedTimestampsEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV:
        Decode_vkCmdDrawMeshTasksNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV:
        Decode_vkCmdDrawMeshTasksIndirectNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV:
        Decode_vkCmdDrawMeshTasksIndirectCountNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV:
        Decode_vkCmdSetExclusiveScissorNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCheckpointNV:
        Decode_vkCmdSetCheckpointNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV:
        Decode_vkGetQueueCheckpointDataNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL:
        Decode_vkInitializePerformanceApiINTEL(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL:
        Decode_vkUninitializePerformanceApiINTEL(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL:
        Decode_vkCmdSetPerformanceMarkerINTEL(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL:
        Decode_vkCmdSetPerformanceStreamMarkerINTEL(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL:
        Decode_vkCmdSetPerformanceOverrideINTEL(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL:
        Decode_vkAcquirePerformanceConfigurationINTEL(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL:
        Decode_vkReleasePerformanceConfigurationINTEL(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL:
        Decode_vkQueueSetPerformanceConfigurationINTEL(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL:
        Decode_vkGetPerformanceParameterINTEL(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetLocalDimmingAMD:
        Decode_vkSetLocalDimmingAMD(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA:
        Decode_vkCreateImagePipeSurfaceFUCHSIA(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT:
        Decode_vkCreateMetalSurfaceEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT:
        Decode_vkGetBufferDeviceAddressEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT:
        Decode_vkGetPhysicalDeviceToolPropertiesEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV:
        Decode_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV:
        Decode_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT:
        Decode_vkGetPhysicalDeviceSurfacePresentModes2EXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT:
        Decode_vkAcquireFullScreenExclusiveModeEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT:
        Decode_vkReleaseFullScreenExclusiveModeEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT:
        Decode_vkGetDeviceGroupSurfacePresentModes2EXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT:
        Decode_vkCreateHeadlessSurfaceEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT:
        Decode_vkCmdSetLineStippleEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetQueryPoolEXT:
        Decode_vkResetQueryPoolEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCullModeEXT:
        Decode_vkCmdSetCullModeEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT:
        Decode_vkCmdSetFrontFaceEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT:
        Decode_vkCmdSetPrimitiveTopologyEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT:
        Decode_vkCmdSetViewportWithCountEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT:
        Decode_vkCmdSetScissorWithCountEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT:
        Decode_vkCmdBindVertexBuffers2EXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT:
        Decode_vkCmdSetDepthTestEnableEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT:
        Decode_vkCmdSetDepthWriteEnableEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT:
        Decode_vkCmdSetDepthCompareOpEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT:
        Decode_vkCmdSetDepthBoundsTestEnableEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT:
        Decode_vkCmdSetStencilTestEnableEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT:
        Decode_vkCmdSetStencilOpEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV:
        Decode_vkGetGeneratedCommandsMemoryRequirementsNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV:
        Decode_vkCmdPreprocessGeneratedCommandsNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV:
        Decode_vkCmdExecuteGeneratedCommandsNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV:
        Decode_vkCmdBindPipelineShaderGroupNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV:
        Decode_vkCreateIndirectCommandsLayoutNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV:
        Decode_vkDestroyIndirectCommandsLayoutNV(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT:
        Decode_vkCreatePrivateDataSlotEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT:
        Decode_vkDestroyPrivateDataSlotEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetPrivateDataEXT:
        Decode_vkSetPrivateDataEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPrivateDataEXT:
        Decode_vkGetPrivateDataEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT:
        Decode_vkCreateDirectFBSurfaceEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT:
        Decode_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR:
        Decode_vkCreateAccelerationStructureKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsKHR:
        Decode_vkGetAccelerationStructureMemoryRequirementsKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureIndirectKHR:
        Decode_vkCmdBuildAccelerationStructureIndirectKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyAccelerationStructureKHR:
        Decode_vkCopyAccelerationStructureKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR:
        Decode_vkCopyAccelerationStructureToMemoryKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR:
        Decode_vkCopyMemoryToAccelerationStructureKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR:
        Decode_vkWriteAccelerationStructuresPropertiesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR:
        Decode_vkCmdCopyAccelerationStructureKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR:
        Decode_vkCmdCopyAccelerationStructureToMemoryKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR:
        Decode_vkCmdCopyMemoryToAccelerationStructureKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdTraceRaysKHR:
        Decode_vkCmdTraceRaysKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR:
        Decode_vkCreateRayTracingPipelinesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR:
        Decode_vkGetAccelerationStructureDeviceAddressKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR:
        Decode_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR:
        Decode_vkCmdTraceRaysIndirectKHR(parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR:
        Decode_vkGetDeviceAccelerationStructureCompatibilityKHR(parameter_buffer, buffer_size);
        break;
    }
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
