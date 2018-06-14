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
#include "format/pnext_node.h"
#include "format/pointer_decoder.h"
#include "format/string_array_decoder.h"
#include "format/string_decoder.h"
#include "format/struct_pointer_decoder.h"
#include "format/value_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

size_t VulkanDecoder::Decode_vkCreateInstance(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_VkInstanceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkInstance> pInstance;
    VkResult return_value;

    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInstance.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateInstance(return_value, pCreateInfo, pAllocator, pInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyInstance(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyInstance(instance, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDevices(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    PointerDecoder<uint32_t> pPhysicalDeviceCount;
    PointerDecoder<VkPhysicalDevice> pPhysicalDevices;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPhysicalDevices.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkEnumeratePhysicalDevices(return_value, instance, pPhysicalDeviceCount, pPhysicalDevices);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    StructPointerDecoder<Decoded_VkImageFormatProperties> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &tiling);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += pImageFormatProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceImageFormatProperties(return_value, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties> pProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDevice(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkDevice> pDevice;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDevice.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateDevice(return_value, physicalDevice, pCreateInfo, pAllocator, pDevice);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDevice(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyDevice(device, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceQueue(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t queueFamilyIndex;
    uint32_t queueIndex;
    PointerDecoder<VkQueue> pQueue;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueIndex);
    bytes_read += pQueue.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueSubmit(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkQueue queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo> pSubmits;
    VkFence fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &submitCount);
    bytes_read += pSubmits.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkQueueSubmit(return_value, queue, submitCount, pSubmits, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueWaitIdle(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkQueue queue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkQueueWaitIdle(return_value, queue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDeviceWaitIdle(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDeviceWaitIdle(return_value, device);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateMemory(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo> pAllocateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkDeviceMemory> pMemory;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemory.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkAllocateMemory(return_value, device, pAllocateInfo, pAllocator, pMemory);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeMemory(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDeviceMemory memory;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkFreeMemory(device, memory, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMapMemory(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDeviceMemory memory;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkMemoryMapFlags flags;
    PointerDecoder<uint64_t> ppData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ppData.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkMapMemory(return_value, device, memory, offset, size, flags, ppData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUnmapMemory(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDeviceMemory memory;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkUnmapMemory(device, memory);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFlushMappedMemoryRanges(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryRangeCount);
    bytes_read += pMemoryRanges.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkFlushMappedMemoryRanges(return_value, device, memoryRangeCount, pMemoryRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkInvalidateMappedMemoryRanges(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryRangeCount);
    bytes_read += pMemoryRanges.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkInvalidateMappedMemoryRanges(return_value, device, memoryRangeCount, pMemoryRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceMemoryCommitment(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDeviceMemory memory;
    PointerDecoder<VkDeviceSize> pCommittedMemoryInBytes;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += pCommittedMemoryInBytes.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkBuffer buffer;
    VkDeviceMemory memory;
    VkDeviceSize memoryOffset;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryOffset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkBindBufferMemory(return_value, device, buffer, memory, memoryOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkImage image;
    VkDeviceMemory memory;
    VkDeviceSize memoryOffset;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryOffset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkBindImageMemory(return_value, device, image, memory, memoryOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkBuffer buffer;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += pMemoryRequirements.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkImage image;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pMemoryRequirements.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkImage image;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkFormat format;
    VkImageType type;
    VkSampleCountFlagBits samples;
    VkImageUsageFlags usage;
    VkImageTiling tiling;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties> pProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &samples);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &tiling);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueBindSparse(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkQueue queue;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindSparseInfo> pBindInfo;
    VkFence fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkQueueBindSparse(return_value, queue, bindInfoCount, pBindInfo, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateFence(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkFenceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkFence> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFence.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateFence(return_value, device, pCreateInfo, pAllocator, pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyFence(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkFence fence;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyFence(device, fence, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetFences(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t fenceCount;
    PointerDecoder<VkFence> pFences;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fenceCount);
    bytes_read += pFences.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkResetFences(return_value, device, fenceCount, pFences);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceStatus(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkFence fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetFenceStatus(return_value, device, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWaitForFences(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t fenceCount;
    PointerDecoder<VkFence> pFences;
    VkBool32 waitAll;
    uint64_t timeout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fenceCount);
    bytes_read += pFences.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &waitAll);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkWaitForFences(return_value, device, fenceCount, pFences, waitAll, timeout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSemaphore(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSemaphore> pSemaphore;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSemaphore.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateSemaphore(return_value, device, pCreateInfo, pAllocator, pSemaphore);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySemaphore(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSemaphore semaphore;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroySemaphore(device, semaphore, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateEvent(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkEventCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkEvent> pEvent;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pEvent.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateEvent(return_value, device, pCreateInfo, pAllocator, pEvent);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyEvent(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkEvent event;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyEvent(device, event, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetEventStatus(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkEvent event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetEventStatus(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetEvent(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkEvent event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkSetEvent(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetEvent(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkEvent event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkResetEvent(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateQueryPool(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkQueryPool> pQueryPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueryPool.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateQueryPool(return_value, device, pCreateInfo, pAllocator, pQueryPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyQueryPool(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkQueryPool queryPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyQueryPool(device, queryPool, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetQueryPoolResults(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkQueryPool queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkDeviceSize stride;
    VkQueryResultFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryCount);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetQueryPoolResults(return_value, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkBufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkBuffer> pBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pBuffer.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateBuffer(return_value, device, pCreateInfo, pAllocator, pBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkBuffer buffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyBuffer(device, buffer, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateBufferView(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkBufferView> pView;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pView.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateBufferView(return_value, device, pCreateInfo, pAllocator, pView);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyBufferView(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkBufferView bufferView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferView);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyBufferView(device, bufferView, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImage(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkImageCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkImage> pImage;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImage.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateImage(return_value, device, pCreateInfo, pAllocator, pImage);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyImage(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkImage image;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyImage(device, image, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSubresourceLayout(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkImage image;
    StructPointerDecoder<Decoded_VkImageSubresource> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout> pLayout;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += pSubresource.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pLayout.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImageView(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkImageViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkImageView> pView;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pView.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateImageView(return_value, device, pCreateInfo, pAllocator, pView);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyImageView(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkImageView imageView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageView);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyImageView(device, imageView, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateShaderModule(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkShaderModule> pShaderModule;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pShaderModule.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateShaderModule(return_value, device, pCreateInfo, pAllocator, pShaderModule);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyShaderModule(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkShaderModule shaderModule;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shaderModule);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyShaderModule(device, shaderModule, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePipelineCache(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkPipelineCache> pPipelineCache;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelineCache.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreatePipelineCache(return_value, device, pCreateInfo, pAllocator, pPipelineCache);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipelineCache(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkPipelineCache pipelineCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyPipelineCache(device, pipelineCache, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineCacheData(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkPipelineCache pipelineCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += pDataSize.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPipelineCacheData(return_value, device, pipelineCache, pDataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMergePipelineCaches(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkPipelineCache dstCache;
    uint32_t srcCacheCount;
    PointerDecoder<VkPipelineCache> pSrcCaches;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcCacheCount);
    bytes_read += pSrcCaches.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkMergePipelineCaches(return_value, device, dstCache, srcCacheCount, pSrcCaches);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateGraphicsPipelines(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkPipelineCache pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkPipeline> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelines.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateGraphicsPipelines(return_value, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateComputePipelines(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkPipelineCache pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkPipeline> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelines.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateComputePipelines(return_value, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipeline(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkPipeline pipeline;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyPipeline(device, pipeline, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePipelineLayout(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkPipelineLayout> pPipelineLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPipelineLayout.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreatePipelineLayout(return_value, device, pCreateInfo, pAllocator, pPipelineLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipelineLayout(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkPipelineLayout pipelineLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineLayout);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSampler(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkSamplerCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSampler> pSampler;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSampler.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateSampler(return_value, device, pCreateInfo, pAllocator, pSampler);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySampler(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSampler sampler;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &sampler);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroySampler(device, sampler, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorSetLayout(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkDescriptorSetLayout> pSetLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSetLayout.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateDescriptorSetLayout(return_value, device, pCreateInfo, pAllocator, pSetLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorSetLayout(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDescriptorSetLayout descriptorSetLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSetLayout);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorPool(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkDescriptorPool> pDescriptorPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorPool.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateDescriptorPool(return_value, device, pCreateInfo, pAllocator, pDescriptorPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorPool(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDescriptorPool descriptorPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorPool);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetDescriptorPool(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDescriptorPool descriptorPool;
    VkDescriptorPoolResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkResetDescriptorPool(return_value, device, descriptorPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo> pAllocateInfo;
    PointerDecoder<VkDescriptorSet> pDescriptorSets;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorSets.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkAllocateDescriptorSets(return_value, device, pAllocateInfo, pDescriptorSets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDescriptorPool descriptorPool;
    uint32_t descriptorSetCount;
    PointerDecoder<VkDescriptorSet> pDescriptorSets;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSetCount);
    bytes_read += pDescriptorSets.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkFreeDescriptorSets(return_value, device, descriptorPool, descriptorSetCount, pDescriptorSets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUpdateDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;
    uint32_t descriptorCopyCount;
    StructPointerDecoder<Decoded_VkCopyDescriptorSet> pDescriptorCopies;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorWriteCount);
    bytes_read += pDescriptorWrites.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorCopyCount);
    bytes_read += pDescriptorCopies.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateFramebuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkFramebuffer> pFramebuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFramebuffer.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateFramebuffer(return_value, device, pCreateInfo, pAllocator, pFramebuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyFramebuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkFramebuffer framebuffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &framebuffer);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyFramebuffer(device, framebuffer, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkRenderPass> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRenderPass.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateRenderPass(return_value, device, pCreateInfo, pAllocator, pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyRenderPass(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkRenderPass renderPass;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &renderPass);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyRenderPass(device, renderPass, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRenderAreaGranularity(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkRenderPass renderPass;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &renderPass);
    bytes_read += pGranularity.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetRenderAreaGranularity(device, renderPass, pGranularity);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateCommandPool(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkCommandPool> pCommandPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCommandPool.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateCommandPool(return_value, device, pCreateInfo, pAllocator, pCommandPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyCommandPool(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkCommandPool commandPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyCommandPool(device, commandPool, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetCommandPool(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkCommandPool commandPool;
    VkCommandPoolResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkResetCommandPool(return_value, device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateCommandBuffers(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo> pAllocateInfo;
    PointerDecoder<VkCommandBuffer> pCommandBuffers;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCommandBuffers.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkAllocateCommandBuffers(return_value, device, pAllocateInfo, pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeCommandBuffers(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkCommandPool commandPool;
    uint32_t commandBufferCount;
    PointerDecoder<VkCommandBuffer> pCommandBuffers;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBufferCount);
    bytes_read += pCommandBuffers.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBeginCommandBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo> pBeginInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBeginInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkBeginCommandBuffer(return_value, commandBuffer, pBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEndCommandBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkEndCommandBuffer(return_value, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetCommandBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkCommandBufferResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkResetCommandBuffer(return_value, commandBuffer, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindPipeline(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipeline pipeline;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewport(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewports.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetScissor(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t firstScissor;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &scissorCount);
    bytes_read += pScissors.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLineWidth(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    float lineWidth;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &lineWidth);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetLineWidth(commandBuffer, lineWidth);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBias(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    float depthBiasConstantFactor;
    float depthBiasClamp;
    float depthBiasSlopeFactor;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBiasConstantFactor);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBiasClamp);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &depthBiasSlopeFactor);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetBlendConstants(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    PointerDecoder<float> blendConstants;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += blendConstants.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetBlendConstants(commandBuffer, blendConstants);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBounds(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    float minDepthBounds;
    float maxDepthBounds;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &minDepthBounds);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDepthBounds);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilCompareMask(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t compareMask;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &compareMask);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilWriteMask(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t writeMask;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &writeMask);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilReference(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t reference;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &reference);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetStencilReference(commandBuffer, faceMask, reference);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindDescriptorSets(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipelineLayout layout;
    uint32_t firstSet;
    uint32_t descriptorSetCount;
    PointerDecoder<VkDescriptorSet> pDescriptorSets;
    uint32_t dynamicOffsetCount;
    PointerDecoder<uint32_t> pDynamicOffsets;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstSet);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSetCount);
    bytes_read += pDescriptorSets.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dynamicOffsetCount);
    bytes_read += pDynamicOffsets.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindIndexBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkIndexType indexType;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indexType);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindVertexBuffers(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    PointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstBinding);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindingCount);
    bytes_read += pBuffers.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pOffsets.DecodeVkDeviceSize((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDraw(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstVertex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstInstance);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexed(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t firstIndex;
    int32_t vertexOffset;
    uint32_t firstInstance;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indexCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstIndex);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &vertexOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstInstance);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirect(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirect(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatch(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchIndirect(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDispatchIndirect(commandBuffer, buffer, offset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkBuffer srcBuffer;
    VkBuffer dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImage(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBlitImage(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageBlit> pRegions;
    VkFilter filter;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &filter);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBufferToImage(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkBuffer srcBuffer;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImageToBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkBuffer dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdUpdateBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize dataSize;
    PointerDecoder<uint8_t> pData;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdFillBuffer(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize size;
    uint32_t data;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &data);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearColorImage(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkImage image;
    VkImageLayout imageLayout;
    StructPointerDecoder<Decoded_VkClearColorValue> pColor;
    uint32_t rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageLayout);
    bytes_read += pColor.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rangeCount);
    bytes_read += pRanges.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearDepthStencilImage(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkImage image;
    VkImageLayout imageLayout;
    StructPointerDecoder<Decoded_VkClearDepthStencilValue> pDepthStencil;
    uint32_t rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageLayout);
    bytes_read += pDepthStencil.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rangeCount);
    bytes_read += pRanges.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearAttachments(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkClearAttachment> pAttachments;
    uint32_t rectCount;
    StructPointerDecoder<Decoded_VkClearRect> pRects;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &attachmentCount);
    bytes_read += pAttachments.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rectCount);
    bytes_read += pRects.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResolveImage(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkImage srcImage;
    VkImageLayout srcImageLayout;
    VkImage dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageResolve> pRegions;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetEvent(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkEvent event;
    VkPipelineStageFlags stageMask;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageMask);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetEvent(commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetEvent(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkEvent event;
    VkPipelineStageFlags stageMask;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageMask);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdResetEvent(commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWaitEvents(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t eventCount;
    PointerDecoder<VkEvent> pEvents;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    uint32_t memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &eventCount);
    bytes_read += pEvents.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstStageMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryBarrierCount);
    bytes_read += pMemoryBarriers.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferMemoryBarrierCount);
    bytes_read += pBufferMemoryBarriers.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageMemoryBarrierCount);
    bytes_read += pImageMemoryBarriers.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPipelineBarrier(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    VkDependencyFlags dependencyFlags;
    uint32_t memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dependencyFlags);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memoryBarrierCount);
    bytes_read += pMemoryBarriers.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bufferMemoryBarrierCount);
    bytes_read += pBufferMemoryBarriers.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &imageMemoryBarrierCount);
    bytes_read += pImageMemoryBarriers.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginQuery(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t query;
    VkQueryControlFlags flags;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndQuery(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdEndQuery(commandBuffer, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetQueryPool(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryCount);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteTimestamp(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    VkQueryPool queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineStage);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &query);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyQueryPoolResults(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkQueryPool queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize stride;
    VkQueryResultFlags flags;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queryCount);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushConstants(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkPipelineLayout layout;
    VkShaderStageFlags stageFlags;
    uint32_t offset;
    uint32_t size;
    PointerDecoder<uint8_t> pValues;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stageFlags);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &size);
    bytes_read += pValues.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &contents);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &contents);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdNextSubpass(commandBuffer, contents);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdEndRenderPass(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdExecuteCommands(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t commandBufferCount;
    PointerDecoder<VkCommandBuffer> pCommandBuffers;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBufferCount);
    bytes_read += pCommandBuffers.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkBindBufferMemory2(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkBindImageMemory2(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPeerMemoryFeatures(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &heapIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &localDeviceIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &remoteDeviceIndex);
    bytes_read += pPeerMemoryFeatures.DecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDeviceMask(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceMask);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetDeviceMask(commandBuffer, deviceMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchBase(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupZ);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceGroups(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceGroupCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkEnumeratePhysicalDeviceGroups(return_value, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pImageFormatInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceImageFormatProperties2(return_value, physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFormatInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTrimCommandPool(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkCommandPool commandPool;
    VkCommandPoolTrimFlags flags;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkTrimCommandPool(device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceQueue2(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2> pQueueInfo;
    PointerDecoder<VkQueue> pQueue;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pQueueInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueue.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDeviceQueue2(device, pQueueInfo, pQueue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSamplerYcbcrConversion(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pYcbcrConversion.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateSamplerYcbcrConversion(return_value, device, pCreateInfo, pAllocator, pYcbcrConversion);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySamplerYcbcrConversion(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSamplerYcbcrConversion ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ycbcrConversion);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorUpdateTemplate(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorUpdateTemplate.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateDescriptorUpdateTemplate(return_value, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorUpdateTemplate(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDescriptorUpdateTemplate descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUpdateDescriptorSetWithTemplate(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDescriptorSet descriptorSet;
    VkDescriptorUpdateTemplate descriptorUpdateTemplate;
    uint64_t pData;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pData);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalBufferProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalBufferInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalBufferProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalFenceProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalFenceInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalFenceProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalSemaphoreInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalSemaphoreProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutSupport(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSupport.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    VkSurfaceKHR surface;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroySurfaceKHR(instance, surface, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    uint32_t queueFamilyIndex;
    VkSurfaceKHR surface;
    PointerDecoder<VkBool32> pSupported;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSupported.DecodeVkBool32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceSurfaceSupportKHR(return_value, physicalDevice, queueFamilyIndex, surface, pSupported);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkSurfaceKHR surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceCapabilities.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(return_value, physicalDevice, surface, pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkSurfaceKHR surface;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR> pSurfaceFormats;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceFormatCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceSurfaceFormatsKHR(return_value, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkSurfaceKHR surface;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pPresentModeCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPresentModes.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceSurfacePresentModesKHR(return_value, physicalDevice, surface, pPresentModeCount, pPresentModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSwapchainKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSwapchainKHR> pSwapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSwapchain.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateSwapchainKHR(return_value, device, pCreateInfo, pAllocator, pSwapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySwapchainKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSwapchainKHR swapchain;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroySwapchainKHR(device, swapchain, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainImagesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSwapchainKHR swapchain;
    PointerDecoder<uint32_t> pSwapchainImageCount;
    PointerDecoder<VkImage> pSwapchainImages;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pSwapchainImageCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSwapchainImages.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetSwapchainImagesKHR(return_value, device, swapchain, pSwapchainImageCount, pSwapchainImages);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireNextImageKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSwapchainKHR swapchain;
    uint64_t timeout;
    VkSemaphore semaphore;
    VkFence fence;
    PointerDecoder<uint32_t> pImageIndex;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &semaphore);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fence);
    bytes_read += pImageIndex.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkAcquireNextImageKHR(return_value, device, swapchain, timeout, semaphore, fence, pImageIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueuePresentKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkQueue queue;
    StructPointerDecoder<Decoded_VkPresentInfoKHR> pPresentInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pPresentInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkQueuePresentKHR(return_value, queue, pPresentInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPresentCapabilitiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR> pDeviceGroupPresentCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pDeviceGroupPresentCapabilities.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDeviceGroupPresentCapabilitiesKHR(return_value, device, pDeviceGroupPresentCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupSurfacePresentModesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSurfaceKHR surface;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pModes.DecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDeviceGroupSurfacePresentModesKHR(return_value, device, surface, pModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDevicePresentRectanglesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkSurfaceKHR surface;
    PointerDecoder<uint32_t> pRectCount;
    StructPointerDecoder<Decoded_VkRect2D> pRects;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pRectCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRects.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDevicePresentRectanglesKHR(return_value, physicalDevice, surface, pRectCount, pRects);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireNextImage2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR> pAcquireInfo;
    PointerDecoder<uint32_t> pImageIndex;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pAcquireInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageIndex.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkAcquireNextImage2KHR(return_value, device, pAcquireInfo, pImageIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceDisplayPropertiesKHR(return_value, physicalDevice, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(return_value, physicalDevice, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneSupportedDisplaysKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    uint32_t planeIndex;
    PointerDecoder<uint32_t> pDisplayCount;
    PointerDecoder<VkDisplayKHR> pDisplays;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeIndex);
    bytes_read += pDisplayCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDisplays.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDisplayPlaneSupportedDisplaysKHR(return_value, physicalDevice, planeIndex, pDisplayCount, pDisplays);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayModePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkDisplayKHR display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDisplayModePropertiesKHR(return_value, physicalDevice, display, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDisplayModeKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkDisplayKHR display;
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkDisplayModeKHR> pMode;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMode.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateDisplayModeKHR(return_value, physicalDevice, display, pCreateInfo, pAllocator, pMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneCapabilitiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkDisplayModeKHR mode;
    uint32_t planeIndex;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR> pCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &mode);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &planeIndex);
    bytes_read += pCapabilities.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDisplayPlaneCapabilitiesKHR(return_value, physicalDevice, mode, planeIndex, pCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDisplayPlaneSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateDisplayPlaneSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSharedSwapchainsKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t swapchainCount;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSwapchainKHR> pSwapchains;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchainCount);
    bytes_read += pCreateInfos.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSwapchains.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateSharedSwapchainsKHR(return_value, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    }

    return bytes_read;
}

#ifdef VK_USE_PLATFORM_XLIB_KHR
size_t VulkanDecoder::Decode_vkCreateXlibSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateXlibSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    uint32_t queueFamilyIndex;
    PointerDecoder<Display> dpy;
    VisualID visualID;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += dpy.DecodeDisplay((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVisualIDValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &visualID);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, dpy, visualID);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
size_t VulkanDecoder::Decode_vkCreateXcbSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateXcbSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    uint32_t queueFamilyIndex;
    PointerDecoder<xcb_connection_t> connection;
    xcb_visualid_t visual_id;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += connection.DecodeXcb_Connection((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeXcb_VisualidValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &visual_id);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, connection, visual_id);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
size_t VulkanDecoder::Decode_vkCreateWaylandSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateWaylandSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    uint32_t queueFamilyIndex;
    PointerDecoder<wl_display> display;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += display.DecodeWl_Display((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, display);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
size_t VulkanDecoder::Decode_vkCreateMirSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkMirSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateMirSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMirPresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    uint32_t queueFamilyIndex;
    PointerDecoder<MirConnection> connection;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += connection.DecodeMirConnection((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceMirPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, connection);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
size_t VulkanDecoder::Decode_vkCreateAndroidSurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateAndroidSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t VulkanDecoder::Decode_vkCreateWin32SurfaceKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateWin32SurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    uint32_t queueFamilyIndex;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeVkBool32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pImageFormatInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceImageFormatProperties2KHR(return_value, physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFormatInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPropertyCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &heapIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &localDeviceIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &remoteDeviceIndex);
    bytes_read += pPeerMemoryFeatures.DecodeFlags((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDeviceMaskKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &deviceMask);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchBaseKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseGroupZ);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTrimCommandPoolKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkCommandPool commandPool;
    VkCommandPoolTrimFlags flags;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkTrimCommandPoolKHR(device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceGroupsKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceGroupCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkEnumeratePhysicalDeviceGroupsKHR(return_value, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalBufferInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalBufferProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    }

    return bytes_read;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t VulkanDecoder::Decode_vkGetMemoryWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<HANDLE> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeHANDLE((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetMemoryWin32HandleKHR(return_value, device, pGetWin32HandleInfo, pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandlePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    HANDLE handle;
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR> pMemoryWin32HandleProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeHANDLEValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handle);
    bytes_read += pMemoryWin32HandleProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetMemoryWin32HandlePropertiesKHR(return_value, device, handleType, handle, pMemoryWin32HandleProperties);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t VulkanDecoder::Decode_vkGetMemoryFdKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetMemoryFdKHR(return_value, device, pGetFdInfo, pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryFdPropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    int fd;
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR> pMemoryFdProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &fd);
    bytes_read += pMemoryFdProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetMemoryFdPropertiesKHR(return_value, device, handleType, fd, pMemoryFdProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalSemaphoreInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalSemaphoreProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    }

    return bytes_read;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t VulkanDecoder::Decode_vkImportSemaphoreWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR> pImportSemaphoreWin32HandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreWin32HandleInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkImportSemaphoreWin32HandleKHR(return_value, device, pImportSemaphoreWin32HandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<HANDLE> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeHANDLE((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetSemaphoreWin32HandleKHR(return_value, device, pGetWin32HandleInfo, pHandle);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t VulkanDecoder::Decode_vkImportSemaphoreFdKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR> pImportSemaphoreFdInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreFdInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkImportSemaphoreFdKHR(return_value, device, pImportSemaphoreFdInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreFdKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetSemaphoreFdKHR(return_value, device, pGetFdInfo, pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushDescriptorSetKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    VkPipelineLayout layout;
    uint32_t set;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &set);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorWriteCount);
    bytes_read += pDescriptorWrites.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushDescriptorSetWithTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkDescriptorUpdateTemplate descriptorUpdateTemplate;
    VkPipelineLayout layout;
    uint32_t set;
    uint64_t pData;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &set);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pData);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorUpdateTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkDescriptorUpdateTemplate> pDescriptorUpdateTemplate;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescriptorUpdateTemplate.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateDescriptorUpdateTemplateKHR(return_value, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorUpdateTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDescriptorUpdateTemplate descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUpdateDescriptorSetWithTemplateKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDescriptorSet descriptorSet;
    VkDescriptorUpdateTemplate descriptorUpdateTemplate;
    uint64_t pData;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pData);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainStatusKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSwapchainKHR swapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetSwapchainStatusKHR(return_value, device, swapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalFenceInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pExternalFenceProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    }

    return bytes_read;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t VulkanDecoder::Decode_vkImportFenceWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR> pImportFenceWin32HandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportFenceWin32HandleInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkImportFenceWin32HandleKHR(return_value, device, pImportFenceWin32HandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceWin32HandleKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<HANDLE> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeHANDLE((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetFenceWin32HandleKHR(return_value, device, pGetWin32HandleInfo, pHandle);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

size_t VulkanDecoder::Decode_vkImportFenceFdKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR> pImportFenceFdInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pImportFenceFdInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkImportFenceFdKHR(return_value, device, pImportFenceFdInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceFdKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetFenceFdKHR(return_value, device, pGetFdInfo, pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceCapabilities.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(return_value, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR> pSurfaceFormats;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceFormatCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceSurfaceFormats2KHR(return_value, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSamplerYcbcrConversionKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSamplerYcbcrConversion> pYcbcrConversion;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pYcbcrConversion.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateSamplerYcbcrConversionKHR(return_value, device, pCreateInfo, pAllocator, pYcbcrConversion);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySamplerYcbcrConversionKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSamplerYcbcrConversion ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ycbcrConversion);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkBindBufferMemory2KHR(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory2KHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkBindImageMemory2KHR(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutSupportKHR(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSupport.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDebugReportCallbackEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkDebugReportCallbackEXT> pCallback;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCallback.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateDebugReportCallbackEXT(return_value, instance, pCreateInfo, pAllocator, pCallback);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDebugReportCallbackEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    VkDebugReportCallbackEXT callback;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callback);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugReportMessageEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    VkDebugReportFlagsEXT flags;
    VkDebugReportObjectTypeEXT objectType;
    uint64_t object;
    size_t location;
    int32_t messageCode;
    StringDecoder pLayerPrefix;
    StringDecoder pMessage;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectType);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &object);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &location);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messageCode);
    bytes_read += pLayerPrefix.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMessage.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugMarkerSetObjectTagEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT> pTagInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pTagInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDebugMarkerSetObjectTagEXT(return_value, device, pTagInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugMarkerSetObjectNameEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT> pNameInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pNameInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDebugMarkerSetObjectNameEXT(return_value, device, pNameInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerBeginEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerEndEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDebugMarkerEndEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerInsertEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCountAMD(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkBuffer countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCountAMD(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkBuffer buffer;
    VkDeviceSize offset;
    VkBuffer countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &stride);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetShaderInfoAMD(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkPipeline pipeline;
    VkShaderStageFlagBits shaderStage;
    VkShaderInfoTypeAMD infoType;
    PointerDecoder<size_t> pInfoSize;
    PointerDecoder<uint8_t> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shaderStage);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &infoType);
    bytes_read += pInfoSize.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInfo.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetShaderInfoAMD(return_value, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    VkExternalMemoryHandleTypeFlagsNV externalHandleType;
    StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV> pExternalImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &tiling);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &externalHandleType);
    bytes_read += pExternalImageFormatProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(return_value, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    }

    return bytes_read;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
size_t VulkanDecoder::Decode_vkGetMemoryWin32HandleNV(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDeviceMemory memory;
    VkExternalMemoryHandleTypeFlagsNV handleType;
    PointerDecoder<HANDLE> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handleType);
    bytes_read += pHandle.DecodeHANDLE((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetMemoryWin32HandleNV(return_value, device, memory, handleType, pHandle);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_VI_NN
size_t VulkanDecoder::Decode_vkCreateViSurfaceNN(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateViSurfaceNN(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_VI_NN */

size_t VulkanDecoder::Decode_vkCmdProcessCommandsNVX(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    StructPointerDecoder<Decoded_VkCmdProcessCommandsInfoNVX> pProcessCommandsInfo;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pProcessCommandsInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdProcessCommandsNVX(commandBuffer, pProcessCommandsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdReserveSpaceForCommandsNVX(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    StructPointerDecoder<Decoded_VkCmdReserveSpaceForCommandsInfoNVX> pReserveSpaceInfo;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pReserveSpaceInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdReserveSpaceForCommandsNVX(commandBuffer, pReserveSpaceInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateIndirectCommandsLayoutNVX(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNVX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkIndirectCommandsLayoutNVX> pIndirectCommandsLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pIndirectCommandsLayout.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateIndirectCommandsLayoutNVX(return_value, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyIndirectCommandsLayoutNVX(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkIndirectCommandsLayoutNVX indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &indirectCommandsLayout);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateObjectTableNVX(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkObjectTableCreateInfoNVX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkObjectTableNVX> pObjectTable;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pObjectTable.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateObjectTableNVX(return_value, device, pCreateInfo, pAllocator, pObjectTable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyObjectTableNVX(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkObjectTableNVX objectTable;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectTable);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyObjectTableNVX(device, objectTable, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterObjectsNVX(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkObjectTableNVX objectTable;
    uint32_t objectCount;
    StructPointerDecoder<Decoded_VkObjectTableEntryNVX> ppObjectTableEntries;
    PointerDecoder<uint32_t> pObjectIndices;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectTable);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectCount);
    bytes_read += ppObjectTableEntries.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pObjectIndices.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkRegisterObjectsNVX(return_value, device, objectTable, objectCount, ppObjectTableEntries, pObjectIndices);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUnregisterObjectsNVX(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkObjectTableNVX objectTable;
    uint32_t objectCount;
    PointerDecoder<VkObjectEntryTypeNVX> pObjectEntryTypes;
    PointerDecoder<uint32_t> pObjectIndices;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectTable);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &objectCount);
    bytes_read += pObjectEntryTypes.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pObjectIndices.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkUnregisterObjectsNVX(return_value, device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsFeaturesNVX> pFeatures;
    StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsLimitsNVX> pLimits;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pLimits.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, pFeatures, pLimits);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportWScalingNV(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportWScalingNV> pViewportWScalings;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewportWScalings.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleaseDisplayEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkDisplayKHR display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkReleaseDisplayEXT(return_value, physicalDevice, display);
    }

    return bytes_read;
}

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
size_t VulkanDecoder::Decode_vkAcquireXlibDisplayEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    PointerDecoder<Display> dpy;
    VkDisplayKHR display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += dpy.DecodeDisplay((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkAcquireXlibDisplayEXT(return_value, physicalDevice, dpy, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRandROutputDisplayEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    PointerDecoder<Display> dpy;
    RROutput rrOutput;
    PointerDecoder<VkDisplayKHR> pDisplay;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += dpy.DecodeDisplay((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeRROutputValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rrOutput);
    bytes_read += pDisplay.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetRandROutputDisplayEXT(return_value, physicalDevice, dpy, rrOutput, pDisplay);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkSurfaceKHR surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceCapabilities.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(return_value, physicalDevice, surface, pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDisplayPowerControlEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDisplayKHR display;
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT> pDisplayPowerInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pDisplayPowerInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDisplayPowerControlEXT(return_value, device, display, pDisplayPowerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterDeviceEventEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT> pDeviceEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkFence> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pDeviceEventInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFence.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkRegisterDeviceEventEXT(return_value, device, pDeviceEventInfo, pAllocator, pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterDisplayEventEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkDisplayKHR display;
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT> pDisplayEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkFence> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &display);
    bytes_read += pDisplayEventInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFence.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkRegisterDisplayEventEXT(return_value, device, display, pDisplayEventInfo, pAllocator, pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainCounterEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSwapchainKHR swapchain;
    VkSurfaceCounterFlagBitsEXT counter;
    PointerDecoder<uint64_t> pCounterValue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &counter);
    bytes_read += pCounterValue.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetSwapchainCounterEXT(return_value, device, swapchain, counter, pCounterValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRefreshCycleDurationGOOGLE(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSwapchainKHR swapchain;
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE> pDisplayTimingProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pDisplayTimingProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetRefreshCycleDurationGOOGLE(return_value, device, swapchain, pDisplayTimingProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPastPresentationTimingGOOGLE(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkSwapchainKHR swapchain;
    PointerDecoder<uint32_t> pPresentationTimingCount;
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE> pPresentationTimings;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchain);
    bytes_read += pPresentationTimingCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPresentationTimings.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPastPresentationTimingGOOGLE(return_value, device, swapchain, pPresentationTimingCount, pPresentationTimings);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDiscardRectangleEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    uint32_t firstDiscardRectangle;
    uint32_t discardRectangleCount;
    StructPointerDecoder<Decoded_VkRect2D> pDiscardRectangles;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &firstDiscardRectangle);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &discardRectangleCount);
    bytes_read += pDiscardRectangles.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetHdrMetadataEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    uint32_t swapchainCount;
    PointerDecoder<VkSwapchainKHR> pSwapchains;
    StructPointerDecoder<Decoded_VkHdrMetadataEXT> pMetadata;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &swapchainCount);
    bytes_read += pSwapchains.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMetadata.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    }

    return bytes_read;
}

#ifdef VK_USE_PLATFORM_IOS_MVK
size_t VulkanDecoder::Decode_vkCreateIOSSurfaceMVK(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateIOSSurfaceMVK(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
size_t VulkanDecoder::Decode_vkCreateMacOSSurfaceMVK(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkSurfaceKHR> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateMacOSSurfaceMVK(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_MACOS_MVK */

size_t VulkanDecoder::Decode_vkSetDebugUtilsObjectNameEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT> pNameInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pNameInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkSetDebugUtilsObjectNameEXT(return_value, device, pNameInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetDebugUtilsObjectTagEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT> pTagInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pTagInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkSetDebugUtilsObjectTagEXT(return_value, device, pTagInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueBeginDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkQueue queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueEndDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkQueue queue;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkQueueEndDebugUtilsLabelEXT(queue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueInsertDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkQueue queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdEndDebugUtilsLabelEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdInsertDebugUtilsLabelEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDebugUtilsMessengerEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkDebugUtilsMessengerEXT> pMessenger;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMessenger.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateDebugUtilsMessengerEXT(return_value, instance, pCreateInfo, pAllocator, pMessenger);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDebugUtilsMessengerEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    VkDebugUtilsMessengerEXT messenger;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messenger);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSubmitDebugUtilsMessageEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkInstance instance;
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity;
    VkDebugUtilsMessageTypeFlagsEXT messageTypes;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT> pCallbackData;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messageSeverity);
    bytes_read += ValueDecoder::DecodeFlagsValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &messageTypes);
    bytes_read += pCallbackData.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    }

    return bytes_read;
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
size_t VulkanDecoder::Decode_vkGetAndroidHardwareBufferPropertiesANDROID(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    PointerDecoder<AHardwareBuffer> buffer;
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &buffer);
    bytes_read += pProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetAndroidHardwareBufferPropertiesANDROID(return_value, device, buffer, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryAndroidHardwareBufferANDROID(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID> pInfo;
    PointerDecoder<AHardwareBuffer> pBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pBuffer.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetMemoryAndroidHardwareBufferANDROID(return_value, device, pInfo, pBuffer);
    }

    return bytes_read;
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

size_t VulkanDecoder::Decode_vkCmdSetSampleLocationsEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT> pSampleLocationsInfo;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSampleLocationsInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkPhysicalDevice physicalDevice;
    VkSampleCountFlagBits samples;
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT> pMultisampleProperties;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &samples);
    bytes_read += pMultisampleProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateValidationCacheEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<VkValidationCacheEXT> pValidationCache;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pValidationCache.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCreateValidationCacheEXT(return_value, device, pCreateInfo, pAllocator, pValidationCache);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyValidationCacheEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkValidationCacheEXT validationCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &validationCache);
    bytes_read += pAllocator.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMergeValidationCachesEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkValidationCacheEXT dstCache;
    uint32_t srcCacheCount;
    PointerDecoder<VkValidationCacheEXT> pSrcCaches;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &srcCacheCount);
    bytes_read += pSrcCaches.DecodeHandle((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkMergeValidationCachesEXT(return_value, device, dstCache, srcCacheCount, pSrcCaches);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetValidationCacheDataEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkValidationCacheEXT validationCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &validationCache);
    bytes_read += pDataSize.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetValidationCacheDataEXT(return_value, device, validationCache, pDataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryHostPointerPropertiesEXT(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkDevice device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t pHostPointer;
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT> pMemoryHostPointerProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pHostPointer);
    bytes_read += pMemoryHostPointerProperties.Decode<decode_struct>((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkGetMemoryHostPointerPropertiesEXT(return_value, device, handleType, pHostPointer, pMemoryHostPointerProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteBufferMarkerAMD(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    VkCommandBuffer commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    VkBuffer dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;

    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pipelineStage);
    bytes_read += ValueDecoder::DecodeHandleValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &marker);

    for (auto consumer : consumers_)
    {
        //consumer->Process_vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    }

    return bytes_read;
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
