/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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

#include "generated/generated_vulkan_ascii_consumer.h"
#include "decode/custom_vulkan_ascii_consumer.h"
#include "decode/custom_vulkan_to_string.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_to_string.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanAsciiConsumer::Process_vkCreateInstance(
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateInstance", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pInstance", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pInstance));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyInstance(
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyInstance", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDevices(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkEnumeratePhysicalDevices", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "[out]pPhysicalDeviceCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPhysicalDeviceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPhysicalDevices", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(pPhysicalDeviceCount, pPhysicalDevices, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceFeatures", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceFormatProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceImageFormatProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, '"' + ToString(type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, '"' + ToString(tiling, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceQueueFamilyProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pQueueFamilyPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueFamilyPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueueFamilyProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pQueueFamilyPropertyCount, pQueueFamilyProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceMemoryProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pMemoryProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDevice(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDevice", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDevice", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDevice));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDevice(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyDevice", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceQueue(
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceQueue", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueIndex", toStringFlags, tabCount, tabSize, ToString(queueIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueue", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pQueue));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueSubmit(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
    format::HandleId                            fence)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkQueueSubmit", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "submitCount", toStringFlags, tabCount, tabSize, ToString(submitCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubmits", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(submitCount, pSubmits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueWaitIdle(
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkQueueWaitIdle", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDeviceWaitIdle(
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDeviceWaitIdle", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAllocateMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkAllocateMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAllocateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemory", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pMemory));
        }
    );
}

void VulkanAsciiConsumer::Process_vkFreeMemory(
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkFreeMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkMapMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkMapMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]ppData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(ppData));
        }
    );
}

void VulkanAsciiConsumer::Process_vkUnmapMemory(
    format::HandleId                            device,
    format::HandleId                            memory)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkUnmapMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
        }
    );
}

void VulkanAsciiConsumer::Process_vkFlushMappedMemoryRanges(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkFlushMappedMemoryRanges", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memoryRangeCount", toStringFlags, tabCount, tabSize, ToString(memoryRangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRanges", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(memoryRangeCount, pMemoryRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkInvalidateMappedMemoryRanges(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkInvalidateMappedMemoryRanges", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memoryRangeCount", toStringFlags, tabCount, tabSize, ToString(memoryRangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRanges", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(memoryRangeCount, pMemoryRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryCommitment(
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceMemoryCommitment", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "[out]pCommittedMemoryInBytes", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCommittedMemoryInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkBindBufferMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(memoryOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindImageMemory(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkBindImageMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(memoryOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetBufferMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetImageMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements(
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetImageSparseMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pSparseMemoryRequirementCount, pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSparseImageFormatProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, '"' + ToString(type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, '"' + ToString(samples, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, '"' + ToString(tiling, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPropertyCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueBindSparse(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkQueueBindSparse", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfo", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindInfoCount, pBindInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateFence(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateFence", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFence", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFence));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyFence(
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyFence", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetFences(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkResetFences", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fenceCount", toStringFlags, tabCount, tabSize, ToString(fenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFences", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(fenceCount, pFences, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetFenceStatus(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetFenceStatus", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }
    );
}

void VulkanAsciiConsumer::Process_vkWaitForFences(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkWaitForFences", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fenceCount", toStringFlags, tabCount, tabSize, ToString(fenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFences", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(fenceCount, pFences, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "waitAll", toStringFlags, tabCount, tabSize, ToString(waitAll, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateSemaphore(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateSemaphore", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSemaphore", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSemaphore));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroySemaphore(
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroySemaphore", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pEvent", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pEvent));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyEvent(
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetEventStatus(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetEventStatus", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSetEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetEvent(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkResetEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateQueryPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateQueryPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueryPool", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pQueryPool));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyQueryPool(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyQueryPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetQueryPoolResults(
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
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetQueryPoolResults", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "firstQuery", toStringFlags, tabCount, tabSize, ToString(firstQuery, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryCount", toStringFlags, tabCount, tabSize, ToString(queryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateBuffer(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pBuffer", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyBuffer(
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateBufferView(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateBufferView", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pView", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pView));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyBufferView(
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyBufferView", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bufferView", toStringFlags, tabCount, tabSize, HandleIdToString(bufferView));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateImage(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pImage", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pImage));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyImage(
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageSubresourceLayout(
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetImageSubresourceLayout", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "pSubresource", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pLayout", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLayout, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateImageView(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateImageView", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pView", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pView));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyImageView(
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyImageView", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateShaderModule(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderModule>*       pShaderModule)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateShaderModule", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pShaderModule", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pShaderModule));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyShaderModule(
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyShaderModule", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "shaderModule", toStringFlags, tabCount, tabSize, HandleIdToString(shaderModule));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreatePipelineCache(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineCache>*      pPipelineCache)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreatePipelineCache", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelineCache", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPipelineCache));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPipelineCache(
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyPipelineCache", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPipelineCacheData(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPipelineCacheData", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "[out]pDataSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }
    );
}

void VulkanAsciiConsumer::Process_vkMergePipelineCaches(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkMergePipelineCaches", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "dstCache", toStringFlags, tabCount, tabSize, HandleIdToString(dstCache));
            FieldToString(strStrm, false, "srcCacheCount", toStringFlags, tabCount, tabSize, ToString(srcCacheCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSrcCaches", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(srcCacheCount, pSrcCaches, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateGraphicsPipelines(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateGraphicsPipelines", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(createInfoCount, pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateComputePipelines(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateComputePipelines", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(createInfoCount, pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPipeline(
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyPipeline", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreatePipelineLayout(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreatePipelineLayout", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelineLayout", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPipelineLayout));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPipelineLayout(
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyPipelineLayout", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineLayout", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineLayout));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateSampler(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateSampler", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSampler", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSampler));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroySampler(
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroySampler", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "sampler", toStringFlags, tabCount, tabSize, HandleIdToString(sampler));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorSetLayout(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDescriptorSetLayout", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSetLayout", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSetLayout));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorSetLayout(
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyDescriptorSetLayout", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorSetLayout", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorSetLayout));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDescriptorPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDescriptorPool", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDescriptorPool));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorPool(
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyDescriptorPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorPool", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorPool));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetDescriptorPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkResetDescriptorPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorPool", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorPool));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkFreeDescriptorSets(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkFreeDescriptorSets", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorPool", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorPool));
            FieldToString(strStrm, false, "descriptorSetCount", toStringFlags, tabCount, tabSize, ToString(descriptorSetCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorSets", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(descriptorSetCount, pDescriptorSets, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkUpdateDescriptorSets(
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkUpdateDescriptorSets", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorWriteCount", toStringFlags, tabCount, tabSize, ToString(descriptorWriteCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorWrites", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(descriptorWriteCount, pDescriptorWrites, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorCopyCount", toStringFlags, tabCount, tabSize, ToString(descriptorCopyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorCopies", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(descriptorCopyCount, pDescriptorCopies, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateFramebuffer(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateFramebuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFramebuffer", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFramebuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyFramebuffer(
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyFramebuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "framebuffer", toStringFlags, tabCount, tabSize, HandleIdToString(framebuffer));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateRenderPass(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateRenderPass", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pRenderPass", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pRenderPass));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyRenderPass(
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyRenderPass", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, HandleIdToString(renderPass));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetRenderAreaGranularity(
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetRenderAreaGranularity", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, HandleIdToString(renderPass));
            FieldToString(strStrm, false, "[out]pGranularity", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGranularity, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateCommandPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateCommandPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCommandPool", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pCommandPool));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyCommandPool(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyCommandPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, HandleIdToString(commandPool));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetCommandPool(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkResetCommandPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, HandleIdToString(commandPool));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkFreeCommandBuffers(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkFreeCommandBuffers", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, HandleIdToString(commandPool));
            FieldToString(strStrm, false, "commandBufferCount", toStringFlags, tabCount, tabSize, ToString(commandBufferCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCommandBuffers", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(commandBufferCount, pCommandBuffers, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBeginCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkBeginCommandBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBeginInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkEndCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkEndCommandBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetCommandBuffer(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkResetCommandBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindPipeline(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBindPipeline", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, '"' + ToString(pipelineBindPoint, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewport(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetViewport", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstViewport", toStringFlags, tabCount, tabSize, ToString(firstViewport, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewports", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(viewportCount, pViewports, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetScissor(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetScissor", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstScissor", toStringFlags, tabCount, tabSize, ToString(firstScissor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "scissorCount", toStringFlags, tabCount, tabSize, ToString(scissorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pScissors", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(scissorCount, pScissors, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetLineWidth(
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetLineWidth", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "lineWidth", toStringFlags, tabCount, tabSize, ToString(lineWidth, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBias(
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthBias", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthBiasConstantFactor", toStringFlags, tabCount, tabSize, ToString(depthBiasConstantFactor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthBiasClamp", toStringFlags, tabCount, tabSize, ToString(depthBiasClamp, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depthBiasSlopeFactor", toStringFlags, tabCount, tabSize, ToString(depthBiasSlopeFactor, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetBlendConstants(
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetBlendConstants", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "blendConstants", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(4, blendConstants, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBounds(
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthBounds", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "minDepthBounds", toStringFlags, tabCount, tabSize, ToString(minDepthBounds, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDepthBounds", toStringFlags, tabCount, tabSize, ToString(maxDepthBounds, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilCompareMask(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetStencilCompareMask", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "faceMask", toStringFlags, tabCount, tabSize, ToString(faceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compareMask", toStringFlags, tabCount, tabSize, ToString(compareMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilWriteMask(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetStencilWriteMask", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "faceMask", toStringFlags, tabCount, tabSize, ToString(faceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "writeMask", toStringFlags, tabCount, tabSize, ToString(writeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilReference(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetStencilReference", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "faceMask", toStringFlags, tabCount, tabSize, ToString(faceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "reference", toStringFlags, tabCount, tabSize, ToString(reference, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindDescriptorSets(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    PointerDecoder<uint32_t>*                   pDynamicOffsets)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBindDescriptorSets", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, '"' + ToString(pipelineBindPoint, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, HandleIdToString(layout));
            FieldToString(strStrm, false, "firstSet", toStringFlags, tabCount, tabSize, ToString(firstSet, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorSetCount", toStringFlags, tabCount, tabSize, ToString(descriptorSetCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorSets", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(descriptorSetCount, pDescriptorSets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dynamicOffsetCount", toStringFlags, tabCount, tabSize, ToString(dynamicOffsetCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDynamicOffsets", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(dynamicOffsetCount, pDynamicOffsets, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindIndexBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBindIndexBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexType", toStringFlags, tabCount, tabSize, '"' + ToString(indexType, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindVertexBuffers(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBindVertexBuffers", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstBinding", toStringFlags, tabCount, tabSize, ToString(firstBinding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bindingCount", toStringFlags, tabCount, tabSize, ToString(bindingCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBuffers", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(bindingCount, pBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pOffsets", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindingCount, pOffsets, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDraw(
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDraw", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "vertexCount", toStringFlags, tabCount, tabSize, ToString(vertexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCount", toStringFlags, tabCount, tabSize, ToString(instanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstVertex", toStringFlags, tabCount, tabSize, ToString(firstVertex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstInstance", toStringFlags, tabCount, tabSize, ToString(firstInstance, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexed(
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawIndexed", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "indexCount", toStringFlags, tabCount, tabSize, ToString(indexCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCount", toStringFlags, tabCount, tabSize, ToString(instanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstIndex", toStringFlags, tabCount, tabSize, ToString(firstIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexOffset", toStringFlags, tabCount, tabSize, ToString(vertexOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstInstance", toStringFlags, tabCount, tabSize, ToString(firstInstance, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawIndirect", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drawCount", toStringFlags, tabCount, tabSize, ToString(drawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawIndexedIndirect", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drawCount", toStringFlags, tabCount, tabSize, ToString(drawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDispatch(
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDispatch", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "groupCountX", toStringFlags, tabCount, tabSize, ToString(groupCountX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountY", toStringFlags, tabCount, tabSize, ToString(groupCountY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountZ", toStringFlags, tabCount, tabSize, ToString(groupCountZ, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDispatchIndirect(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDispatchIndirect", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(srcBuffer));
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(dstBuffer));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(regionCount, pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(srcImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(dstImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(regionCount, pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBlitImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
    VkFilter                                    filter)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBlitImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(srcImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(dstImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(regionCount, pRegions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filter", toStringFlags, tabCount, tabSize, '"' + ToString(filter, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBufferToImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyBufferToImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(srcBuffer));
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(dstImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(regionCount, pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImageToBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyImageToBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(srcImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(dstBuffer));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(regionCount, pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdUpdateBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdUpdateBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(dstBuffer));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdFillBuffer(
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdFillBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(dstBuffer));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(data, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdClearColorImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdClearColorImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(imageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pColor", toStringFlags, tabCount, tabSize, PointerDecoderToString(pColor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rangeCount", toStringFlags, tabCount, tabSize, ToString(rangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRanges", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(rangeCount, pRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdClearDepthStencilImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdClearDepthStencilImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(imageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pDepthStencil", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDepthStencil, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rangeCount", toStringFlags, tabCount, tabSize, ToString(rangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRanges", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(rangeCount, pRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdClearAttachments(
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdClearAttachments", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttachments", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(attachmentCount, pAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rectCount", toStringFlags, tabCount, tabSize, ToString(rectCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRects", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(rectCount, pRects, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResolveImage(
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdResolveImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(srcImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(dstImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(regionCount, pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetEvent(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, ToString(stageMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResetEvent(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdResetEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, ToString(stageMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWaitEvents(
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
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdWaitEvents", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "eventCount", toStringFlags, tabCount, tabSize, ToString(eventCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pEvents", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(eventCount, pEvents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcStageMask", toStringFlags, tabCount, tabSize, ToString(srcStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstStageMask", toStringFlags, tabCount, tabSize, ToString(dstStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(memoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(memoryBarrierCount, pMemoryBarriers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferMemoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(bufferMemoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBufferMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bufferMemoryBarrierCount, pBufferMemoryBarriers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageMemoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(imageMemoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(imageMemoryBarrierCount, pImageMemoryBarriers, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPipelineBarrier(
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
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdPipelineBarrier", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcStageMask", toStringFlags, tabCount, tabSize, ToString(srcStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstStageMask", toStringFlags, tabCount, tabSize, ToString(dstStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dependencyFlags", toStringFlags, tabCount, tabSize, ToString(dependencyFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(memoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(memoryBarrierCount, pMemoryBarriers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferMemoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(bufferMemoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBufferMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bufferMemoryBarrierCount, pBufferMemoryBarriers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageMemoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(imageMemoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(imageMemoryBarrierCount, pImageMemoryBarriers, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginQuery(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBeginQuery", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "query", toStringFlags, tabCount, tabSize, ToString(query, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndQuery(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdEndQuery", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "query", toStringFlags, tabCount, tabSize, ToString(query, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResetQueryPool(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdResetQueryPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "firstQuery", toStringFlags, tabCount, tabSize, ToString(firstQuery, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryCount", toStringFlags, tabCount, tabSize, ToString(queryCount, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteTimestamp(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdWriteTimestamp", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineStage", toStringFlags, tabCount, tabSize, '"' + ToString(pipelineStage, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "query", toStringFlags, tabCount, tabSize, ToString(query, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyQueryPoolResults(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyQueryPoolResults", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "firstQuery", toStringFlags, tabCount, tabSize, ToString(firstQuery, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryCount", toStringFlags, tabCount, tabSize, ToString(queryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(dstBuffer));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPushConstants(
    format::HandleId                            commandBuffer,
    format::HandleId                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    PointerDecoder<uint8_t>*                    pValues)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdPushConstants", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, HandleIdToString(layout));
            FieldToString(strStrm, false, "stageFlags", toStringFlags, tabCount, tabSize, ToString(stageFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pValues", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pValues));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBeginRenderPass", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderPassBegin", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderPassBegin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "contents", toStringFlags, tabCount, tabSize, '"' + ToString(contents, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass(
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdNextSubpass", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "contents", toStringFlags, tabCount, tabSize, '"' + ToString(contents, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass(
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdEndRenderPass", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdExecuteCommands(
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdExecuteCommands", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "commandBufferCount", toStringFlags, tabCount, tabSize, ToString(commandBufferCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCommandBuffers", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(commandBufferCount, pCommandBuffers, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkBindBufferMemory2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindInfoCount, pBindInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindImageMemory2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkBindImageMemory2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindInfoCount, pBindInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceGroupPeerMemoryFeatures", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "heapIndex", toStringFlags, tabCount, tabSize, ToString(heapIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "localDeviceIndex", toStringFlags, tabCount, tabSize, ToString(localDeviceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "remoteDeviceIndex", toStringFlags, tabCount, tabSize, ToString(remoteDeviceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPeerMemoryFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPeerMemoryFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDeviceMask(
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDeviceMask", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "deviceMask", toStringFlags, tabCount, tabSize, ToString(deviceMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDispatchBase(
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDispatchBase", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "baseGroupX", toStringFlags, tabCount, tabSize, ToString(baseGroupX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseGroupY", toStringFlags, tabCount, tabSize, ToString(baseGroupY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseGroupZ", toStringFlags, tabCount, tabSize, ToString(baseGroupZ, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountX", toStringFlags, tabCount, tabSize, ToString(groupCountX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountY", toStringFlags, tabCount, tabSize, ToString(groupCountY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountZ", toStringFlags, tabCount, tabSize, ToString(groupCountZ, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkEnumeratePhysicalDeviceGroups", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "[out]pPhysicalDeviceGroupCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPhysicalDeviceGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPhysicalDeviceGroupProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetImageMemoryRequirements2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetBufferMemoryRequirements2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetImageSparseMemoryRequirements2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pSparseMemoryRequirementCount, pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceFeatures2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceFormatProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceImageFormatProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pImageFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceQueueFamilyProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pQueueFamilyPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueFamilyPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueueFamilyProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pQueueFamilyPropertyCount, pQueueFamilyProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceMemoryProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pMemoryProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSparseImageFormatProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPropertyCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkTrimCommandPool(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkTrimCommandPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, HandleIdToString(commandPool));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceQueue2(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceQueue2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pQueueInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueue", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pQueue));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateSamplerYcbcrConversion(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateSamplerYcbcrConversion", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pYcbcrConversion", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pYcbcrConversion));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroySamplerYcbcrConversion(
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroySamplerYcbcrConversion", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "ycbcrConversion", toStringFlags, tabCount, tabSize, HandleIdToString(ycbcrConversion));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorUpdateTemplate(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDescriptorUpdateTemplate", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDescriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDescriptorUpdateTemplate));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyDescriptorUpdateTemplate", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorUpdateTemplate));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceExternalBufferProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalBufferProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceExternalFenceProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalFenceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalFenceProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceExternalSemaphoreProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalSemaphoreInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalSemaphoreProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutSupport(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDescriptorSetLayoutSupport", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSupport", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSupport, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCount(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawIndirectCount", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "countBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(countBuffer));
            FieldToString(strStrm, false, "countBufferOffset", toStringFlags, tabCount, tabSize, ToString(countBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDrawCount", toStringFlags, tabCount, tabSize, ToString(maxDrawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirectCount(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawIndexedIndirectCount", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "countBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(countBuffer));
            FieldToString(strStrm, false, "countBufferOffset", toStringFlags, tabCount, tabSize, ToString(countBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDrawCount", toStringFlags, tabCount, tabSize, ToString(maxDrawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateRenderPass2(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateRenderPass2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pRenderPass", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pRenderPass));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBeginRenderPass2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderPassBegin", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderPassBegin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpassBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassBeginInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdNextSubpass2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pSubpassBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassBeginInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpassEndInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassEndInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdEndRenderPass2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pSubpassEndInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassEndInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetQueryPool(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkResetQueryPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "firstQuery", toStringFlags, tabCount, tabSize, ToString(firstQuery, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryCount", toStringFlags, tabCount, tabSize, ToString(queryCount, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreCounterValue(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetSemaphoreCounterValue", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "[out]pValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pValue, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkWaitSemaphores(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkWaitSemaphores", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pWaitInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pWaitInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSignalSemaphore(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSignalSemaphore", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pSignalInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSignalInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddress(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetBufferDeviceAddress", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetBufferOpaqueCaptureAddress", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceMemoryOpaqueCaptureAddress", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceToolProperties(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceToolProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pToolCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pToolCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pToolProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pToolCount, pToolProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreatePrivateDataSlot(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreatePrivateDataSlot", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPrivateDataSlot", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPrivateDataSlot));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPrivateDataSlot(
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyPrivateDataSlot", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetPrivateData(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSetPrivateData", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, '"' + ToString(objectType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(data, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPrivateData(
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPrivateData", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, '"' + ToString(objectType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, PointerDecoderToString(pData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetEvent2(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetEvent2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "pDependencyInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDependencyInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResetEvent2(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdResetEvent2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, ToString(stageMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWaitEvents2(
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdWaitEvents2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "eventCount", toStringFlags, tabCount, tabSize, ToString(eventCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pEvents", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(eventCount, pEvents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDependencyInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(eventCount, pDependencyInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPipelineBarrier2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdPipelineBarrier2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pDependencyInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDependencyInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteTimestamp2(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdWriteTimestamp2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stage", toStringFlags, tabCount, tabSize, ToString(stage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "query", toStringFlags, tabCount, tabSize, ToString(query, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueSubmit2(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkQueueSubmit2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "submitCount", toStringFlags, tabCount, tabSize, ToString(submitCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubmits", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(submitCount, pSubmits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBuffer2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyBuffer2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyBufferInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImage2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyImage2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBufferToImage2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyBufferToImage2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyBufferToImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyBufferToImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImageToBuffer2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyImageToBuffer2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyImageToBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyImageToBufferInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBlitImage2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBlitImage2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pBlitImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBlitImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResolveImage2(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdResolveImage2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pResolveImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pResolveImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRendering(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBeginRendering", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderingInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderingInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRendering(
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdEndRendering", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCullMode(
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetCullMode", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "cullMode", toStringFlags, tabCount, tabSize, ToString(cullMode, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetFrontFace(
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetFrontFace", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "frontFace", toStringFlags, tabCount, tabSize, '"' + ToString(frontFace, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveTopology(
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetPrimitiveTopology", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "primitiveTopology", toStringFlags, tabCount, tabSize, '"' + ToString(primitiveTopology, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWithCount(
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetViewportWithCount", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewports", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(viewportCount, pViewports, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetScissorWithCount(
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetScissorWithCount", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "scissorCount", toStringFlags, tabCount, tabSize, ToString(scissorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pScissors", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(scissorCount, pScissors, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindVertexBuffers2(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBindVertexBuffers2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstBinding", toStringFlags, tabCount, tabSize, ToString(firstBinding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bindingCount", toStringFlags, tabCount, tabSize, ToString(bindingCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBuffers", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(bindingCount, pBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pOffsets", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindingCount, pOffsets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSizes", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindingCount, pSizes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStrides", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindingCount, pStrides, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthTestEnable(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthTestEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthTestEnable", toStringFlags, tabCount, tabSize, ToString(depthTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthWriteEnable(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthWriteEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthWriteEnable", toStringFlags, tabCount, tabSize, ToString(depthWriteEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthCompareOp(
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthCompareOp", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthCompareOp", toStringFlags, tabCount, tabSize, '"' + ToString(depthCompareOp, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthBoundsTestEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthBoundsTestEnable", toStringFlags, tabCount, tabSize, ToString(depthBoundsTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilTestEnable(
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetStencilTestEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stencilTestEnable", toStringFlags, tabCount, tabSize, ToString(stencilTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilOp(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetStencilOp", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "faceMask", toStringFlags, tabCount, tabSize, ToString(faceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "failOp", toStringFlags, tabCount, tabSize, '"' + ToString(failOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "passOp", toStringFlags, tabCount, tabSize, '"' + ToString(passOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "depthFailOp", toStringFlags, tabCount, tabSize, '"' + ToString(depthFailOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "compareOp", toStringFlags, tabCount, tabSize, '"' + ToString(compareOp, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetRasterizerDiscardEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "rasterizerDiscardEnable", toStringFlags, tabCount, tabSize, ToString(rasterizerDiscardEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBiasEnable(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthBiasEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthBiasEnable", toStringFlags, tabCount, tabSize, ToString(depthBiasEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetPrimitiveRestartEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "primitiveRestartEnable", toStringFlags, tabCount, tabSize, ToString(primitiveRestartEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceBufferMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceImageMemoryRequirements(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceImageMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceImageSparseMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pSparseMemoryRequirementCount, pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroySurfaceKHR(
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroySurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSurfaceSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pSupported", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSupported, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSurfaceCapabilitiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pSurfaceCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceCapabilities, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSurfaceFormatsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pSurfaceFormatCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceFormatCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurfaceFormats", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pSurfaceFormatCount, pSurfaceFormats, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSurfacePresentModesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pPresentModeCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentModeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPresentModes", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(pPresentModeCount, pPresentModes, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateSwapchainKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateSwapchainKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSwapchain", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSwapchain));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroySwapchainKHR(
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroySwapchainKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetSwapchainImagesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetSwapchainImagesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "[out]pSwapchainImageCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSwapchainImageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSwapchainImages", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(pSwapchainImageCount, pSwapchainImages, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireNextImageKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    timeout,
    format::HandleId                            semaphore,
    format::HandleId                            fence,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkAcquireNextImageKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
            FieldToString(strStrm, false, "[out]pImageIndex", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueuePresentKHR(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkQueuePresentKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "pPresentInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceGroupPresentCapabilitiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "[out]pDeviceGroupPresentCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDeviceGroupPresentCapabilities, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceGroupSurfacePresentModesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pModes", toStringFlags, tabCount, tabSize, PointerDecoderToString(pModes, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDevicePresentRectanglesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pRectCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRectCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pRects", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pRectCount, pRects, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireNextImage2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkAcquireNextImage2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAcquireInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAcquireInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pImageIndex", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceDisplayPropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPropertyCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPropertyCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    planeIndex,
    PointerDecoder<uint32_t>*                   pDisplayCount,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplays)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDisplayPlaneSupportedDisplaysKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "planeIndex", toStringFlags, tabCount, tabSize, ToString(planeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDisplayCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDisplays", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(pDisplayCount, pDisplays, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayModePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDisplayModePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPropertyCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDisplayModeKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDisplayModeKHR>*     pMode)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDisplayModeKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMode", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pMode));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDisplayPlaneCapabilitiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, HandleIdToString(mode));
            FieldToString(strStrm, false, "planeIndex", toStringFlags, tabCount, tabSize, ToString(planeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCapabilities, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDisplayPlaneSurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateSharedSwapchainsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateSharedSwapchainsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(swapchainCount, pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSwapchains", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(swapchainCount, pSwapchains, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateXlibSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateXlibSurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceXlibPresentationSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dpy", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dpy));
            FieldToString(strStrm, false, "visualID", toStringFlags, tabCount, tabSize, ToString(visualID, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateXcbSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateXcbSurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceXcbPresentationSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "connection", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(connection));
            FieldToString(strStrm, false, "visual_id", toStringFlags, tabCount, tabSize, ToString(visual_id, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateWaylandSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateWaylandSurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceWaylandPresentationSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(display));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateAndroidSurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateAndroidSurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateWin32SurfaceKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateWin32SurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceWin32PresentationSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderingKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBeginRenderingKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderingInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderingInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderingKHR(
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdEndRenderingKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceFeatures2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceFormatProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceImageFormatProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pImageFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceQueueFamilyProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pQueueFamilyPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueFamilyPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueueFamilyProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pQueueFamilyPropertyCount, pQueueFamilyProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceMemoryProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pMemoryProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSparseImageFormatProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPropertyCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceGroupPeerMemoryFeaturesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "heapIndex", toStringFlags, tabCount, tabSize, ToString(heapIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "localDeviceIndex", toStringFlags, tabCount, tabSize, ToString(localDeviceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "remoteDeviceIndex", toStringFlags, tabCount, tabSize, ToString(remoteDeviceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPeerMemoryFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPeerMemoryFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDeviceMaskKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDeviceMaskKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "deviceMask", toStringFlags, tabCount, tabSize, ToString(deviceMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDispatchBaseKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDispatchBaseKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "baseGroupX", toStringFlags, tabCount, tabSize, ToString(baseGroupX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseGroupY", toStringFlags, tabCount, tabSize, ToString(baseGroupY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "baseGroupZ", toStringFlags, tabCount, tabSize, ToString(baseGroupZ, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountX", toStringFlags, tabCount, tabSize, ToString(groupCountX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountY", toStringFlags, tabCount, tabSize, ToString(groupCountY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountZ", toStringFlags, tabCount, tabSize, ToString(groupCountZ, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkTrimCommandPoolKHR(
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkTrimCommandPoolKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, HandleIdToString(commandPool));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkEnumeratePhysicalDeviceGroupsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "[out]pPhysicalDeviceGroupCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPhysicalDeviceGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPhysicalDeviceGroupProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceExternalBufferPropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalBufferProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetMemoryWin32HandleKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetWin32HandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    handle,
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetMemoryWin32HandlePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, '"' + ToString(handleType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "handle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(handle));
            FieldToString(strStrm, false, "[out]pMemoryWin32HandleProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryWin32HandleProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetMemoryFdKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetFdInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFd", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFd, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryFdPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetMemoryFdPropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, '"' + ToString(handleType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "fd", toStringFlags, tabCount, tabSize, ToString(fd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryFdProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryFdProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceExternalSemaphorePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalSemaphoreInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalSemaphoreProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkImportSemaphoreWin32HandleKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportSemaphoreWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportSemaphoreWin32HandleInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetSemaphoreWin32HandleKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetWin32HandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }
    );
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkImportSemaphoreFdKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportSemaphoreFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportSemaphoreFdInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetSemaphoreFdKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetFdInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFd", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFd, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPushDescriptorSetKHR(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdPushDescriptorSetKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, '"' + ToString(pipelineBindPoint, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, HandleIdToString(layout));
            FieldToString(strStrm, false, "set", toStringFlags, tabCount, tabSize, ToString(set, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorWriteCount", toStringFlags, tabCount, tabSize, ToString(descriptorWriteCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorWrites", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(descriptorWriteCount, pDescriptorWrites, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDescriptorUpdateTemplateKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDescriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDescriptorUpdateTemplate));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyDescriptorUpdateTemplateKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorUpdateTemplate));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateRenderPass2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateRenderPass2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pRenderPass", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pRenderPass));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBeginRenderPass2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderPassBegin", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderPassBegin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpassBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassBeginInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdNextSubpass2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pSubpassBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassBeginInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpassEndInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassEndInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdEndRenderPass2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pSubpassEndInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassEndInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetSwapchainStatusKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetSwapchainStatusKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceExternalFencePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalFenceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalFenceProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkImportFenceWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkImportFenceWin32HandleKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportFenceWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportFenceWin32HandleInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetFenceWin32HandleKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetFenceWin32HandleKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetWin32HandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }
    );
}

void VulkanAsciiConsumer::Process_vkImportFenceFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkImportFenceFdKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportFenceFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportFenceFdInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetFenceFdKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetFenceFdKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetFdInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFd", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFd, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    PointerDecoder<uint32_t>*                   pCounterCount,
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters,
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCounterCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCounterCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCounters", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pCounterCount, pCounters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCounterDescriptions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pCounterCount, pCounterDescriptions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pPerformanceQueryCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPerformanceQueryCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pNumPasses", toStringFlags, tabCount, tabSize, PointerDecoderToString(pNumPasses, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireProfilingLockKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkAcquireProfilingLockKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkReleaseProfilingLockKHR(
    format::HandleId                            device)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkReleaseProfilingLockKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSurfaceCapabilities2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurfaceCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceCapabilities, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSurfaceFormats2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurfaceFormatCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceFormatCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurfaceFormats", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pSurfaceFormatCount, pSurfaceFormats, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceDisplayProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPropertyCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPropertyCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayModeProperties2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDisplayModeProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPropertyCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDisplayPlaneCapabilities2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pDisplayPlaneInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayPlaneInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCapabilities, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements2KHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetImageMemoryRequirements2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetBufferMemoryRequirements2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetImageSparseMemoryRequirements2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pSparseMemoryRequirementCount, pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateSamplerYcbcrConversionKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pYcbcrConversion", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pYcbcrConversion));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroySamplerYcbcrConversionKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "ycbcrConversion", toStringFlags, tabCount, tabSize, HandleIdToString(ycbcrConversion));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkBindBufferMemory2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindInfoCount, pBindInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindImageMemory2KHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkBindImageMemory2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindInfoCount, pBindInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDescriptorSetLayoutSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSupport", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSupport, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCountKHR(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawIndirectCountKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "countBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(countBuffer));
            FieldToString(strStrm, false, "countBufferOffset", toStringFlags, tabCount, tabSize, ToString(countBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDrawCount", toStringFlags, tabCount, tabSize, ToString(maxDrawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawIndexedIndirectCountKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "countBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(countBuffer));
            FieldToString(strStrm, false, "countBufferOffset", toStringFlags, tabCount, tabSize, ToString(countBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDrawCount", toStringFlags, tabCount, tabSize, ToString(maxDrawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreCounterValueKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetSemaphoreCounterValueKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "[out]pValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pValue, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkWaitSemaphoresKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkWaitSemaphoresKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pWaitInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pWaitInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSignalSemaphoreKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSignalSemaphoreKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pSignalInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSignalInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceFragmentShadingRatesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pFragmentShadingRateCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFragmentShadingRateCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFragmentShadingRates", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pFragmentShadingRateCount, pFragmentShadingRates, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetFragmentShadingRateKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pFragmentSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFragmentSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "combinerOps", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(2, combinerOps, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkWaitForPresentKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkWaitForPresentKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "presentId", toStringFlags, tabCount, tabSize, ToString(presentId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddressKHR(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetBufferDeviceAddressKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetBufferOpaqueCaptureAddressKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceMemoryOpaqueCaptureAddressKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDeferredOperationKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDeferredOperationKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDeferredOperation", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDeferredOperation));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDeferredOperationKHR(
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyDeferredOperationKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeferredOperationMaxConcurrencyKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeferredOperationResultKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeferredOperationResultKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDeferredOperationJoinKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDeferredOperationJoinKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPipelineExecutablePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pPipelineInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPipelineInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExecutableCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExecutableCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pExecutableCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPipelineExecutableStatisticsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pExecutableInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExecutableInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pStatisticCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pStatisticCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pStatistics", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pStatisticCount, pStatistics, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPipelineExecutableInternalRepresentationsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pExecutableInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExecutableInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pInternalRepresentationCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInternalRepresentationCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pInternalRepresentations", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pInternalRepresentationCount, pInternalRepresentations, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetEvent2KHR(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetEvent2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "pDependencyInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDependencyInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResetEvent2KHR(
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdResetEvent2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, ToString(stageMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWaitEvents2KHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdWaitEvents2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "eventCount", toStringFlags, tabCount, tabSize, ToString(eventCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pEvents", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(eventCount, pEvents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDependencyInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(eventCount, pDependencyInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPipelineBarrier2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdPipelineBarrier2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pDependencyInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDependencyInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteTimestamp2KHR(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdWriteTimestamp2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stage", toStringFlags, tabCount, tabSize, ToString(stage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "query", toStringFlags, tabCount, tabSize, ToString(query, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueSubmit2KHR(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkQueueSubmit2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "submitCount", toStringFlags, tabCount, tabSize, ToString(submitCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubmits", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(submitCount, pSubmits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteBufferMarker2AMD(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdWriteBufferMarker2AMD", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stage", toStringFlags, tabCount, tabSize, ToString(stage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(dstBuffer));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "marker", toStringFlags, tabCount, tabSize, ToString(marker, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetQueueCheckpointData2NV(
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetQueueCheckpointData2NV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "[out]pCheckpointDataCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCheckpointDataCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCheckpointData", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pCheckpointDataCount, pCheckpointData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBuffer2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyBuffer2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyBufferInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImage2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyImage2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBufferToImage2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyBufferToImage2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyBufferToImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyBufferToImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyImageToBuffer2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyImageToBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyImageToBufferInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBlitImage2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBlitImage2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pBlitImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBlitImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResolveImage2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdResolveImage2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pResolveImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pResolveImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceBufferMemoryRequirementsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceImageMemoryRequirementsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceImageSparseMemoryRequirementsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pSparseMemoryRequirementCount, pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDebugReportCallbackEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDebugReportCallbackEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCallback", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pCallback));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDebugReportCallbackEXT(
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyDebugReportCallbackEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "callback", toStringFlags, tabCount, tabSize, HandleIdToString(callback));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDebugReportMessageEXT(
    format::HandleId                            instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    StringDecoder*                              pLayerPrefix,
    StringDecoder*                              pMessage)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDebugReportMessageEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, '"' + ToString(objectType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "object", toStringFlags, tabCount, tabSize, ToString(object, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "location", toStringFlags, tabCount, tabSize, ToString(location, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "messageCode", toStringFlags, tabCount, tabSize, ToString(messageCode, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pLayerPrefix", toStringFlags, tabCount, tabSize, StringDecoderToString(pLayerPrefix));
            FieldToString(strStrm, false, "pMessage", toStringFlags, tabCount, tabSize, StringDecoderToString(pMessage));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDebugMarkerSetObjectTagEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pTagInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pTagInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDebugMarkerSetObjectNameEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pNameInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pNameInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerBeginEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDebugMarkerBeginEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pMarkerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMarkerInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerEndEXT(
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDebugMarkerEndEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerInsertEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDebugMarkerInsertEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pMarkerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMarkerInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBindTransformFeedbackBuffersEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstBinding", toStringFlags, tabCount, tabSize, ToString(firstBinding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bindingCount", toStringFlags, tabCount, tabSize, ToString(bindingCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBuffers", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(bindingCount, pBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pOffsets", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindingCount, pOffsets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSizes", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindingCount, pSizes, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBeginTransformFeedbackEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstCounterBuffer", toStringFlags, tabCount, tabSize, ToString(firstCounterBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "counterBufferCount", toStringFlags, tabCount, tabSize, ToString(counterBufferCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCounterBuffers", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(counterBufferCount, pCounterBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCounterBufferOffsets", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(counterBufferCount, pCounterBufferOffsets, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndTransformFeedbackEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdEndTransformFeedbackEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstCounterBuffer", toStringFlags, tabCount, tabSize, ToString(firstCounterBuffer, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "counterBufferCount", toStringFlags, tabCount, tabSize, ToString(counterBufferCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCounterBuffers", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(counterBufferCount, pCounterBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCounterBufferOffsets", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(counterBufferCount, pCounterBufferOffsets, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginQueryIndexedEXT(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBeginQueryIndexedEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "query", toStringFlags, tabCount, tabSize, ToString(query, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "index", toStringFlags, tabCount, tabSize, ToString(index, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndQueryIndexedEXT(
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdEndQueryIndexedEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "query", toStringFlags, tabCount, tabSize, ToString(query, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "index", toStringFlags, tabCount, tabSize, ToString(index, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawIndirectByteCountEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "instanceCount", toStringFlags, tabCount, tabSize, ToString(instanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstInstance", toStringFlags, tabCount, tabSize, ToString(firstInstance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "counterBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(counterBuffer));
            FieldToString(strStrm, false, "counterBufferOffset", toStringFlags, tabCount, tabSize, ToString(counterBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "counterOffset", toStringFlags, tabCount, tabSize, ToString(counterOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexStride", toStringFlags, tabCount, tabSize, ToString(vertexStride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageViewHandleNVX(
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetImageViewHandleNVX", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageViewAddressNVX(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetImageViewAddressNVX", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCountAMD(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawIndirectCountAMD", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "countBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(countBuffer));
            FieldToString(strStrm, false, "countBufferOffset", toStringFlags, tabCount, tabSize, ToString(countBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDrawCount", toStringFlags, tabCount, tabSize, ToString(maxDrawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawIndexedIndirectCountAMD", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "countBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(countBuffer));
            FieldToString(strStrm, false, "countBufferOffset", toStringFlags, tabCount, tabSize, ToString(countBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDrawCount", toStringFlags, tabCount, tabSize, ToString(maxDrawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetShaderInfoAMD(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    PointerDecoder<size_t>*                     pInfoSize,
    PointerDecoder<uint8_t>*                    pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetShaderInfoAMD", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "shaderStage", toStringFlags, tabCount, tabSize, '"' + ToString(shaderStage, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "infoType", toStringFlags, tabCount, tabSize, '"' + ToString(infoType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pInfoSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfoSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pInfo", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pInfo));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateStreamDescriptorSurfaceGGP", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
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
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceExternalImageFormatPropertiesNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, '"' + ToString(type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, '"' + ToString(tiling, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "externalHandleType", toStringFlags, tabCount, tabSize, ToString(externalHandleType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalImageFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandleNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetMemoryWin32HandleNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, ToString(handleType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateViSurfaceNN(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateViSurfaceNN", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBeginConditionalRenderingEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pConditionalRenderingBegin", toStringFlags, tabCount, tabSize, PointerDecoderToString(pConditionalRenderingBegin, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndConditionalRenderingEXT(
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdEndConditionalRenderingEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWScalingNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetViewportWScalingNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstViewport", toStringFlags, tabCount, tabSize, ToString(firstViewport, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewportWScalings", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(viewportCount, pViewportWScalings, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkReleaseDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkReleaseDisplayEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireXlibDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkAcquireXlibDisplayEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "dpy", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dpy));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetRandROutputDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetRandROutputDisplayEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "dpy", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dpy));
            FieldToString(strStrm, false, "rrOutput", toStringFlags, tabCount, tabSize, ToString(rrOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDisplay", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDisplay));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSurfaceCapabilities2EXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pSurfaceCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceCapabilities, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDisplayPowerControlEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDisplayPowerControlEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pDisplayPowerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayPowerInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkRegisterDeviceEventEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkRegisterDeviceEventEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pDeviceEventInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDeviceEventInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFence", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFence));
        }
    );
}

void VulkanAsciiConsumer::Process_vkRegisterDisplayEventEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkRegisterDisplayEventEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pDisplayEventInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayEventInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFence", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFence));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetSwapchainCounterEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetSwapchainCounterEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "counter", toStringFlags, tabCount, tabSize, '"' + ToString(counter, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pCounterValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCounterValue, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetRefreshCycleDurationGOOGLE", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "[out]pDisplayTimingProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayTimingProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPastPresentationTimingGOOGLE", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "[out]pPresentationTimingCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentationTimingCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPresentationTimings", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPresentationTimingCount, pPresentationTimings, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDiscardRectangleEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDiscardRectangleEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstDiscardRectangle", toStringFlags, tabCount, tabSize, ToString(firstDiscardRectangle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "discardRectangleCount", toStringFlags, tabCount, tabSize, ToString(discardRectangleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDiscardRectangles", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(discardRectangleCount, pDiscardRectangles, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetHdrMetadataEXT(
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSetHdrMetadataEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSwapchains", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(swapchainCount, pSwapchains, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMetadata", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(swapchainCount, pMetadata, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateIOSSurfaceMVK(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateIOSSurfaceMVK", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateMacOSSurfaceMVK(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateMacOSSurfaceMVK", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSetDebugUtilsObjectNameEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pNameInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pNameInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSetDebugUtilsObjectTagEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pTagInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pTagInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkQueueBeginDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "pLabelInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLabelInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    format::HandleId                            queue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkQueueEndDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkQueueInsertDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "pLabelInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLabelInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBeginDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pLabelInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLabelInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdEndDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdInsertDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pLabelInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLabelInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDebugUtilsMessengerEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMessenger", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pMessenger));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyDebugUtilsMessengerEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "messenger", toStringFlags, tabCount, tabSize, HandleIdToString(messenger));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSubmitDebugUtilsMessageEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "messageSeverity", toStringFlags, tabCount, tabSize, '"' + ToString(messageSeverity, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "messageTypes", toStringFlags, tabCount, tabSize, ToString(messageTypes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCallbackData", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCallbackData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetAndroidHardwareBufferPropertiesANDROID", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(buffer));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetMemoryAndroidHardwareBufferANDROID", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pBuffer", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetSampleLocationsEXT(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetSampleLocationsEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pSampleLocationsInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSampleLocationsInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceMultisamplePropertiesEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, '"' + ToString(samples, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pMultisampleProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMultisampleProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetImageDrmFormatModifierPropertiesEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateValidationCacheEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateValidationCacheEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pValidationCache", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pValidationCache));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyValidationCacheEXT(
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyValidationCacheEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "validationCache", toStringFlags, tabCount, tabSize, HandleIdToString(validationCache));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkMergeValidationCachesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkMergeValidationCachesEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "dstCache", toStringFlags, tabCount, tabSize, HandleIdToString(dstCache));
            FieldToString(strStrm, false, "srcCacheCount", toStringFlags, tabCount, tabSize, ToString(srcCacheCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSrcCaches", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(srcCacheCount, pSrcCaches, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetValidationCacheDataEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetValidationCacheDataEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "validationCache", toStringFlags, tabCount, tabSize, HandleIdToString(validationCache));
            FieldToString(strStrm, false, "[out]pDataSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindShadingRateImageNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBindShadingRateImageNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(imageLayout, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetViewportShadingRatePaletteNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstViewport", toStringFlags, tabCount, tabSize, ToString(firstViewport, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pShadingRatePalettes", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(viewportCount, pShadingRatePalettes, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetCoarseSampleOrderNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "sampleOrderType", toStringFlags, tabCount, tabSize, '"' + ToString(sampleOrderType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "customSampleOrderCount", toStringFlags, tabCount, tabSize, ToString(customSampleOrderCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCustomSampleOrders", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(customSampleOrderCount, pCustomSampleOrders, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateAccelerationStructureNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateAccelerationStructureNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pAccelerationStructure", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pAccelerationStructure));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyAccelerationStructureNV(
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyAccelerationStructureNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, HandleIdToString(accelerationStructure));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetAccelerationStructureMemoryRequirementsNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindAccelerationStructureMemoryNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkBindAccelerationStructureMemoryNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindInfoCount, pBindInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBuildAccelerationStructureNV(
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
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBuildAccelerationStructureNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceData", toStringFlags, tabCount, tabSize, HandleIdToString(instanceData));
            FieldToString(strStrm, false, "instanceOffset", toStringFlags, tabCount, tabSize, ToString(instanceOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "update", toStringFlags, tabCount, tabSize, ToString(update, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dst", toStringFlags, tabCount, tabSize, HandleIdToString(dst));
            FieldToString(strStrm, false, "src", toStringFlags, tabCount, tabSize, HandleIdToString(src));
            FieldToString(strStrm, false, "scratch", toStringFlags, tabCount, tabSize, HandleIdToString(scratch));
            FieldToString(strStrm, false, "scratchOffset", toStringFlags, tabCount, tabSize, ToString(scratchOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyAccelerationStructureNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyAccelerationStructureNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "dst", toStringFlags, tabCount, tabSize, HandleIdToString(dst));
            FieldToString(strStrm, false, "src", toStringFlags, tabCount, tabSize, HandleIdToString(src));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, '"' + ToString(mode, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdTraceRaysNV(
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
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdTraceRaysNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "raygenShaderBindingTableBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(raygenShaderBindingTableBuffer));
            FieldToString(strStrm, false, "raygenShaderBindingOffset", toStringFlags, tabCount, tabSize, ToString(raygenShaderBindingOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "missShaderBindingTableBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(missShaderBindingTableBuffer));
            FieldToString(strStrm, false, "missShaderBindingOffset", toStringFlags, tabCount, tabSize, ToString(missShaderBindingOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "missShaderBindingStride", toStringFlags, tabCount, tabSize, ToString(missShaderBindingStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hitShaderBindingTableBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(hitShaderBindingTableBuffer));
            FieldToString(strStrm, false, "hitShaderBindingOffset", toStringFlags, tabCount, tabSize, ToString(hitShaderBindingOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "hitShaderBindingStride", toStringFlags, tabCount, tabSize, ToString(hitShaderBindingStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "callableShaderBindingTableBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(callableShaderBindingTableBuffer));
            FieldToString(strStrm, false, "callableShaderBindingOffset", toStringFlags, tabCount, tabSize, ToString(callableShaderBindingOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "callableShaderBindingStride", toStringFlags, tabCount, tabSize, ToString(callableShaderBindingStride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "width", toStringFlags, tabCount, tabSize, ToString(width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depth", toStringFlags, tabCount, tabSize, ToString(depth, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateRayTracingPipelinesNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateRayTracingPipelinesNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(createInfoCount, pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetRayTracingShaderGroupHandlesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "firstGroup", toStringFlags, tabCount, tabSize, ToString(firstGroup, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetRayTracingShaderGroupHandlesNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "firstGroup", toStringFlags, tabCount, tabSize, ToString(firstGroup, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureHandleNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetAccelerationStructureHandleNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, HandleIdToString(accelerationStructure));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdWriteAccelerationStructuresPropertiesNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "accelerationStructureCount", toStringFlags, tabCount, tabSize, ToString(accelerationStructureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructures", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(accelerationStructureCount, pAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryType", toStringFlags, tabCount, tabSize, '"' + ToString(queryType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "firstQuery", toStringFlags, tabCount, tabSize, ToString(firstQuery, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCompileDeferredNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCompileDeferredNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "shader", toStringFlags, tabCount, tabSize, ToString(shader, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetMemoryHostPointerPropertiesEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, '"' + ToString(handleType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pHostPointer", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHostPointer));
            FieldToString(strStrm, false, "[out]pMemoryHostPointerProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryHostPointerProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteBufferMarkerAMD(
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdWriteBufferMarkerAMD", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineStage", toStringFlags, tabCount, tabSize, '"' + ToString(pipelineStage, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(dstBuffer));
            FieldToString(strStrm, false, "dstOffset", toStringFlags, tabCount, tabSize, ToString(dstOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "marker", toStringFlags, tabCount, tabSize, ToString(marker, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pTimeDomainCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pTimeDomainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pTimeDomains", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(pTimeDomainCount, pTimeDomains, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetCalibratedTimestampsEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetCalibratedTimestampsEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "timestampCount", toStringFlags, tabCount, tabSize, ToString(timestampCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTimestampInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(timestampCount, pTimestampInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pTimestamps", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(timestampCount, pTimestamps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMaxDeviation", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMaxDeviation, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawMeshTasksNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "taskCount", toStringFlags, tabCount, tabSize, ToString(taskCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstTask", toStringFlags, tabCount, tabSize, ToString(firstTask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawMeshTasksIndirectNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drawCount", toStringFlags, tabCount, tabSize, ToString(drawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawMeshTasksIndirectCountNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "countBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(countBuffer));
            FieldToString(strStrm, false, "countBufferOffset", toStringFlags, tabCount, tabSize, ToString(countBufferOffset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDrawCount", toStringFlags, tabCount, tabSize, ToString(maxDrawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetExclusiveScissorNV(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetExclusiveScissorNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstExclusiveScissor", toStringFlags, tabCount, tabSize, ToString(firstExclusiveScissor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "exclusiveScissorCount", toStringFlags, tabCount, tabSize, ToString(exclusiveScissorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExclusiveScissors", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(exclusiveScissorCount, pExclusiveScissors, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCheckpointNV(
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetCheckpointNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCheckpointMarker", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pCheckpointMarker));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetQueueCheckpointDataNV(
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetQueueCheckpointDataNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "[out]pCheckpointDataCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCheckpointDataCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCheckpointData", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pCheckpointDataCount, pCheckpointData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkInitializePerformanceApiINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkInitializePerformanceApiINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInitializeInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInitializeInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkUninitializePerformanceApiINTEL(
    format::HandleId                            device)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkUninitializePerformanceApiINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetPerformanceMarkerINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pMarkerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMarkerInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetPerformanceStreamMarkerINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pMarkerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMarkerInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetPerformanceOverrideINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pOverrideInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pOverrideInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkAcquirePerformanceConfigurationINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAcquireInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAcquireInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pConfiguration", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pConfiguration));
        }
    );
}

void VulkanAsciiConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkReleasePerformanceConfigurationINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "configuration", toStringFlags, tabCount, tabSize, HandleIdToString(configuration));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkQueueSetPerformanceConfigurationINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "configuration", toStringFlags, tabCount, tabSize, HandleIdToString(configuration));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPerformanceParameterINTEL(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPerformanceParameterINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "parameter", toStringFlags, tabCount, tabSize, '"' + ToString(parameter, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pValue, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetLocalDimmingAMD(
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSetLocalDimmingAMD", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapChain", toStringFlags, tabCount, tabSize, HandleIdToString(swapChain));
            FieldToString(strStrm, false, "localDimmingEnable", toStringFlags, tabCount, tabSize, ToString(localDimmingEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateImagePipeSurfaceFUCHSIA", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateMetalSurfaceEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateMetalSurfaceEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddressEXT(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetBufferDeviceAddressEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceToolPropertiesEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pToolCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pToolCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pToolProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pToolCount, pToolProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pPropertyCount, pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pCombinationCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCombinationCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCombinations", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(pCombinationCount, pCombinations, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceSurfacePresentModes2EXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPresentModeCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentModeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPresentModes", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(pPresentModeCount, pPresentModes, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkAcquireFullScreenExclusiveModeEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
        }
    );
}

void VulkanAsciiConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkReleaseFullScreenExclusiveModeEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceGroupSurfacePresentModes2EXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pModes", toStringFlags, tabCount, tabSize, PointerDecoderToString(pModes, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateHeadlessSurfaceEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateHeadlessSurfaceEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetLineStippleEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetLineStippleEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "lineStippleFactor", toStringFlags, tabCount, tabSize, ToString(lineStippleFactor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lineStipplePattern", toStringFlags, tabCount, tabSize, ToString(lineStipplePattern, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetQueryPoolEXT(
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkResetQueryPoolEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "firstQuery", toStringFlags, tabCount, tabSize, ToString(firstQuery, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryCount", toStringFlags, tabCount, tabSize, ToString(queryCount, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCullModeEXT(
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetCullModeEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "cullMode", toStringFlags, tabCount, tabSize, ToString(cullMode, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetFrontFaceEXT(
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetFrontFaceEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "frontFace", toStringFlags, tabCount, tabSize, '"' + ToString(frontFace, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetPrimitiveTopologyEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "primitiveTopology", toStringFlags, tabCount, tabSize, '"' + ToString(primitiveTopology, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWithCountEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetViewportWithCountEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewports", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(viewportCount, pViewports, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetScissorWithCountEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetScissorWithCountEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "scissorCount", toStringFlags, tabCount, tabSize, ToString(scissorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pScissors", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(scissorCount, pScissors, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindVertexBuffers2EXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBindVertexBuffers2EXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstBinding", toStringFlags, tabCount, tabSize, ToString(firstBinding, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bindingCount", toStringFlags, tabCount, tabSize, ToString(bindingCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBuffers", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(bindingCount, pBuffers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pOffsets", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindingCount, pOffsets, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSizes", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindingCount, pSizes, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStrides", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(bindingCount, pStrides, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthTestEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthTestEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthTestEnable", toStringFlags, tabCount, tabSize, ToString(depthTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthWriteEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthWriteEnable", toStringFlags, tabCount, tabSize, ToString(depthWriteEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthCompareOpEXT(
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthCompareOpEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthCompareOp", toStringFlags, tabCount, tabSize, '"' + ToString(depthCompareOp, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthBoundsTestEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthBoundsTestEnable", toStringFlags, tabCount, tabSize, ToString(depthBoundsTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilTestEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetStencilTestEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stencilTestEnable", toStringFlags, tabCount, tabSize, ToString(stencilTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilOpEXT(
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetStencilOpEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "faceMask", toStringFlags, tabCount, tabSize, ToString(faceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "failOp", toStringFlags, tabCount, tabSize, '"' + ToString(failOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "passOp", toStringFlags, tabCount, tabSize, '"' + ToString(passOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "depthFailOp", toStringFlags, tabCount, tabSize, '"' + ToString(depthFailOp, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "compareOp", toStringFlags, tabCount, tabSize, '"' + ToString(compareOp, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetGeneratedCommandsMemoryRequirementsNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdPreprocessGeneratedCommandsNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pGeneratedCommandsInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGeneratedCommandsInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdExecuteGeneratedCommandsNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "isPreprocessed", toStringFlags, tabCount, tabSize, ToString(isPreprocessed, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pGeneratedCommandsInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGeneratedCommandsInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBindPipelineShaderGroupNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, '"' + ToString(pipelineBindPoint, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "groupIndex", toStringFlags, tabCount, tabSize, ToString(groupIndex, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateIndirectCommandsLayoutNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pIndirectCommandsLayout", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pIndirectCommandsLayout));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyIndirectCommandsLayoutNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "indirectCommandsLayout", toStringFlags, tabCount, tabSize, HandleIdToString(indirectCommandsLayout));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireDrmDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    format::HandleId                            display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkAcquireDrmDisplayEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "drmFd", toStringFlags, tabCount, tabSize, ToString(drmFd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDrmDisplayEXT(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    HandlePointerDecoder<VkDisplayKHR>*         display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDrmDisplayEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "drmFd", toStringFlags, tabCount, tabSize, ToString(drmFd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "connectorId", toStringFlags, tabCount, tabSize, ToString(connectorId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]display", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(display));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreatePrivateDataSlotEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreatePrivateDataSlotEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPrivateDataSlot", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPrivateDataSlot));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPrivateDataSlotEXT(
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyPrivateDataSlotEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetPrivateDataEXT(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSetPrivateDataEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, '"' + ToString(objectType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(data, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPrivateDataEXT(
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPrivateDataEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, '"' + ToString(objectType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, PointerDecoderToString(pData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetFragmentShadingRateEnumNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "shadingRate", toStringFlags, tabCount, tabSize, '"' + ToString(shadingRate, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "combinerOps", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(2, combinerOps, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireWinrtDisplayNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkAcquireWinrtDisplayNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetWinrtDisplayNV(
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetWinrtDisplayNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "deviceRelativeId", toStringFlags, tabCount, tabSize, ToString(deviceRelativeId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDisplay", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDisplay));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDirectFBSurfaceEXT(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateDirectFBSurfaceEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceDirectFBPresentationSupportEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dfb", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dfb));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetVertexInputEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetVertexInputEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "vertexBindingDescriptionCount", toStringFlags, tabCount, tabSize, ToString(vertexBindingDescriptionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexBindingDescriptions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(vertexBindingDescriptionCount, pVertexBindingDescriptions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexAttributeDescriptionCount", toStringFlags, tabCount, tabSize, ToString(vertexAttributeDescriptionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexAttributeDescriptions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(vertexAttributeDescriptionCount, pVertexAttributeDescriptions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetMemoryZirconHandleFUCHSIA", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetZirconHandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetZirconHandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pZirconHandle", toStringFlags, tabCount, tabSize, PointerDecoderToString(pZirconHandle, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint32_t                                    zirconHandle,
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetMemoryZirconHandlePropertiesFUCHSIA", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, '"' + ToString(handleType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "zirconHandle", toStringFlags, tabCount, tabSize, ToString(zirconHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryZirconHandleProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryZirconHandleProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkImportSemaphoreZirconHandleFUCHSIA", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportSemaphoreZirconHandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportSemaphoreZirconHandleInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetSemaphoreZirconHandleFUCHSIA", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetZirconHandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetZirconHandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pZirconHandle", toStringFlags, tabCount, tabSize, PointerDecoderToString(pZirconHandle, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdBindInvocationMaskHUAWEI", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(imageLayout, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryRemoteAddressNV(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo,
    PointerDecoder<uint64_t, void*>*            pAddress)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetMemoryRemoteAddressNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pMemoryGetRemoteAddressInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryGetRemoteAddressInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pAddress", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pAddress));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPatchControlPointsEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetPatchControlPointsEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "patchControlPoints", toStringFlags, tabCount, tabSize, ToString(patchControlPoints, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetRasterizerDiscardEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "rasterizerDiscardEnable", toStringFlags, tabCount, tabSize, ToString(rasterizerDiscardEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetDepthBiasEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthBiasEnable", toStringFlags, tabCount, tabSize, ToString(depthBiasEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetLogicOpEXT(
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetLogicOpEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "logicOp", toStringFlags, tabCount, tabSize, '"' + ToString(logicOp, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetPrimitiveRestartEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "primitiveRestartEnable", toStringFlags, tabCount, tabSize, ToString(primitiveRestartEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateScreenSurfaceQNX(
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateScreenSurfaceQNX", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    window)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetPhysicalDeviceScreenPresentationSupportQNX", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "window", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(window));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetColorWriteEnableEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetColorWriteEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorWriteEnables", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(attachmentCount, pColorWriteEnables, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMultiEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawMultiEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "drawCount", toStringFlags, tabCount, tabSize, ToString(drawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexInfo", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(drawCount, pVertexInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCount", toStringFlags, tabCount, tabSize, ToString(instanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstInstance", toStringFlags, tabCount, tabSize, ToString(firstInstance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMultiIndexedEXT(
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    PointerDecoder<int32_t>*                    pVertexOffset)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdDrawMultiIndexedEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "drawCount", toStringFlags, tabCount, tabSize, ToString(drawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIndexInfo", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(drawCount, pIndexInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCount", toStringFlags, tabCount, tabSize, ToString(instanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstInstance", toStringFlags, tabCount, tabSize, ToString(firstInstance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexOffset", toStringFlags, tabCount, tabSize, PointerDecoderToString(pVertexOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkSetDeviceMemoryPriorityEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "priority", toStringFlags, tabCount, tabSize, ToString(priority, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateAccelerationStructureKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateAccelerationStructureKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pAccelerationStructure", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pAccelerationStructure));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroyAccelerationStructureKHR(
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkDestroyAccelerationStructureKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, HandleIdToString(accelerationStructure));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCopyAccelerationStructureToMemoryKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCopyMemoryToAccelerationStructureKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkWriteAccelerationStructuresPropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "accelerationStructureCount", toStringFlags, tabCount, tabSize, ToString(accelerationStructureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructures", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(accelerationStructureCount, pAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryType", toStringFlags, tabCount, tabSize, '"' + ToString(queryType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyAccelerationStructureKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyAccelerationStructureToMemoryKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdCopyMemoryToAccelerationStructureKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetAccelerationStructureDeviceAddressKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdWriteAccelerationStructuresPropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "accelerationStructureCount", toStringFlags, tabCount, tabSize, ToString(accelerationStructureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructures", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(accelerationStructureCount, pAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryType", toStringFlags, tabCount, tabSize, '"' + ToString(queryType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "firstQuery", toStringFlags, tabCount, tabSize, ToString(firstQuery, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetDeviceAccelerationStructureCompatibilityKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pVersionInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pVersionInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCompatibility", toStringFlags, tabCount, tabSize, EnumPointerDecoderToString(pCompatibility));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdTraceRaysKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdTraceRaysKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRaygenShaderBindingTable", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRaygenShaderBindingTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMissShaderBindingTable", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMissShaderBindingTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pHitShaderBindingTable", toStringFlags, tabCount, tabSize, PointerDecoderToString(pHitShaderBindingTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCallableShaderBindingTable", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCallableShaderBindingTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "width", toStringFlags, tabCount, tabSize, ToString(width, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "height", toStringFlags, tabCount, tabSize, ToString(height, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "depth", toStringFlags, tabCount, tabSize, ToString(depth, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateRayTracingPipelinesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCreateRayTracingPipelinesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(createInfoCount, pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "firstGroup", toStringFlags, tabCount, tabSize, ToString(firstGroup, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdTraceRaysIndirectKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdTraceRaysIndirectKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRaygenShaderBindingTable", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRaygenShaderBindingTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMissShaderBindingTable", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMissShaderBindingTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pHitShaderBindingTable", toStringFlags, tabCount, tabSize, PointerDecoderToString(pHitShaderBindingTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCallableShaderBindingTable", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCallableShaderBindingTable, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indirectDeviceAddress", toStringFlags, tabCount, tabSize, ToString(indirectDeviceAddress, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    VkDeviceSize                                returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkGetRayTracingShaderGroupStackSizeKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "return", toStringFlags, tabCount, tabSize, '"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "group", toStringFlags, tabCount, tabSize, ToString(group, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupShader", toStringFlags, tabCount, tabSize, '"' + ToString(groupShader, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile("vkCmdSetRayTracingPipelineStackSizeKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineStackSize", toStringFlags, tabCount, tabSize, ToString(pipelineStackSize, toStringFlags, tabCount, tabSize));
        }
    );
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
