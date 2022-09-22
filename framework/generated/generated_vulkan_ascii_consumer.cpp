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

#include "generated/generated_vulkan_ascii_consumer.h"
#include "decode/custom_vulkan_ascii_consumer.h"
#include "util/custom_vulkan_to_string.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_to_string.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanAsciiConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCreateInstance", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pInstance", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pInstance));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyInstance", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDevices", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "[out]pPhysicalDeviceCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPhysicalDeviceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPhysicalDevices", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(pPhysicalDeviceCount, pPhysicalDevices, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFeatures", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFormatProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceImageFormatProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, '"' + ToString(type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, '"' + ToString(tiling, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pQueueFamilyPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueFamilyPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueueFamilyProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pQueueFamilyProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMemoryProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pMemoryProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateDevice", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDevice", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDevice));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyDevice", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceQueue", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkQueueSubmit", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "submitCount", toStringFlags, tabCount, tabSize, ToString(submitCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubmits", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSubmits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkQueueWaitIdle", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDeviceWaitIdle", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkAllocateMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAllocateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemory", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pMemory));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkFreeMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkMapMemory(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkMapMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]ppData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(ppData));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkUnmapMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
        }
    );
}

void VulkanAsciiConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkFlushMappedMemoryRanges", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memoryRangeCount", toStringFlags, tabCount, tabSize, ToString(memoryRangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRanges", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pMemoryRanges, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkInvalidateMappedMemoryRanges", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memoryRangeCount", toStringFlags, tabCount, tabSize, ToString(memoryRangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRanges", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pMemoryRanges, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceMemoryCommitment", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "[out]pCommittedMemoryInBytes", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCommittedMemoryInBytes, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkBindBufferMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(memoryOffset, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkBindImageMemory", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(memoryOffset, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetBufferMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageSparseMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, '"' + ToString(type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, '"' + ToString(samples, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, '"' + ToString(tiling, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkQueueBindSparse", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfo", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateFence", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFence", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFence));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyFence", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkResetFences", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fenceCount", toStringFlags, tabCount, tabSize, ToString(fenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFences", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(fenceCount, pFences, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetFenceStatus", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkWaitForFences(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkWaitForFences", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fenceCount", toStringFlags, tabCount, tabSize, ToString(fenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFences", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(fenceCount, pFences, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "waitAll", toStringFlags, tabCount, tabSize, ToString(waitAll, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateSemaphore", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSemaphore", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSemaphore));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroySemaphore", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pEvent", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pEvent));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetEventStatus", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkSetEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkResetEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateQueryPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueryPool", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pQueryPool));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyQueryPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetQueryPoolResults(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetQueryPoolResults", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "firstQuery", toStringFlags, tabCount, tabSize, ToString(firstQuery, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryCount", toStringFlags, tabCount, tabSize, ToString(queryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pBuffer", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pBuffer));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateBufferView", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pView", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pView));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyBufferView", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bufferView", toStringFlags, tabCount, tabSize, HandleIdToString(bufferView));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pImage", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pImage));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageSubresourceLayout", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateImageView", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pView", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pView));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyImageView", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateShaderModule(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateShaderModule", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pShaderModule", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pShaderModule));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyShaderModule", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "shaderModule", toStringFlags, tabCount, tabSize, HandleIdToString(shaderModule));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreatePipelineCache(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreatePipelineCache", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelineCache", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPipelineCache));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyPipelineCache", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPipelineCacheData(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPipelineCacheData", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "[out]pDataSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkMergePipelineCaches", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "dstCache", toStringFlags, tabCount, tabSize, HandleIdToString(dstCache));
            FieldToString(strStrm, false, "srcCacheCount", toStringFlags, tabCount, tabSize, ToString(srcCacheCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSrcCaches", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(srcCacheCount, pSrcCaches, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateGraphicsPipelines", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateComputePipelines", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyPipeline", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreatePipelineLayout", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelineLayout", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPipelineLayout));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyPipelineLayout", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineLayout", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineLayout));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateSampler", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSampler", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSampler));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroySampler", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "sampler", toStringFlags, tabCount, tabSize, HandleIdToString(sampler));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateDescriptorSetLayout", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSetLayout", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSetLayout));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyDescriptorSetLayout", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorSetLayout", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorSetLayout));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateDescriptorPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDescriptorPool", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDescriptorPool));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyDescriptorPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorPool", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorPool));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkResetDescriptorPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorPool", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorPool));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkFreeDescriptorSets", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorPool", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorPool));
            FieldToString(strStrm, false, "descriptorSetCount", toStringFlags, tabCount, tabSize, ToString(descriptorSetCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorSets", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(descriptorSetCount, pDescriptorSets, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkUpdateDescriptorSets", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorWriteCount", toStringFlags, tabCount, tabSize, ToString(descriptorWriteCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorWrites", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pDescriptorWrites, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorCopyCount", toStringFlags, tabCount, tabSize, ToString(descriptorCopyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorCopies", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pDescriptorCopies, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateFramebuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFramebuffer", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFramebuffer));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyFramebuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "framebuffer", toStringFlags, tabCount, tabSize, HandleIdToString(framebuffer));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateRenderPass", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pRenderPass", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pRenderPass));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyRenderPass", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, HandleIdToString(renderPass));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetRenderAreaGranularity", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, HandleIdToString(renderPass));
            FieldToString(strStrm, false, "[out]pGranularity", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGranularity, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateCommandPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCommandPool", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pCommandPool));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyCommandPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, HandleIdToString(commandPool));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkResetCommandPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, HandleIdToString(commandPool));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkFreeCommandBuffers", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkBeginCommandBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBeginInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkEndCommandBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkResetCommandBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBindPipeline", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, '"' + ToString(pipelineBindPoint, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetViewport", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstViewport", toStringFlags, tabCount, tabSize, ToString(firstViewport, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewports", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pViewports, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetScissor", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstScissor", toStringFlags, tabCount, tabSize, ToString(firstScissor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "scissorCount", toStringFlags, tabCount, tabSize, ToString(scissorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pScissors", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pScissors, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetLineWidth", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "lineWidth", toStringFlags, tabCount, tabSize, ToString(lineWidth, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthBias", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetBlendConstants", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "blendConstants", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(4, blendConstants, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthBounds", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "minDepthBounds", toStringFlags, tabCount, tabSize, ToString(minDepthBounds, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "maxDepthBounds", toStringFlags, tabCount, tabSize, ToString(maxDepthBounds, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetStencilCompareMask", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "faceMask", toStringFlags, tabCount, tabSize, ToString(faceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "compareMask", toStringFlags, tabCount, tabSize, ToString(compareMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetStencilWriteMask", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "faceMask", toStringFlags, tabCount, tabSize, ToString(faceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "writeMask", toStringFlags, tabCount, tabSize, ToString(writeMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetStencilReference", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "faceMask", toStringFlags, tabCount, tabSize, ToString(faceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "reference", toStringFlags, tabCount, tabSize, ToString(reference, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdBindDescriptorSets", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBindIndexBuffer", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdBindVertexBuffers", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDraw", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndexed", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndirect", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirect", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdDispatch", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdDispatchIndirect", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdCopyBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(srcBuffer));
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(dstBuffer));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdCopyImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(srcImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(dstImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdBlitImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(srcImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(dstImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRegions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filter", toStringFlags, tabCount, tabSize, '"' + ToString(filter, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdCopyBufferToImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(srcBuffer));
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(dstImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdCopyImageToBuffer", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(srcImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dstBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(dstBuffer));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdUpdateBuffer", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdFillBuffer", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdClearColorImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(imageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pColor", toStringFlags, tabCount, tabSize, PointerDecoderToString(pColor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rangeCount", toStringFlags, tabCount, tabSize, ToString(rangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRanges", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdClearDepthStencilImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(imageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pDepthStencil", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDepthStencil, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rangeCount", toStringFlags, tabCount, tabSize, ToString(rangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRanges", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRanges, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdClearAttachments", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAttachments", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pAttachments, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "rectCount", toStringFlags, tabCount, tabSize, ToString(rectCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRects", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRects, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdResolveImage", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(srcImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(dstImageLayout, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRegions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, ToString(stageMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdResetEvent", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, ToString(stageMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdWaitEvents", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "eventCount", toStringFlags, tabCount, tabSize, ToString(eventCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pEvents", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(eventCount, pEvents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "srcStageMask", toStringFlags, tabCount, tabSize, ToString(srcStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstStageMask", toStringFlags, tabCount, tabSize, ToString(dstStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(memoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pMemoryBarriers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferMemoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(bufferMemoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBufferMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBufferMemoryBarriers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageMemoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(imageMemoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pImageMemoryBarriers, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdPipelineBarrier", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcStageMask", toStringFlags, tabCount, tabSize, ToString(srcStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dstStageMask", toStringFlags, tabCount, tabSize, ToString(dstStageMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dependencyFlags", toStringFlags, tabCount, tabSize, ToString(dependencyFlags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "memoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(memoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pMemoryBarriers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "bufferMemoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(bufferMemoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBufferMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBufferMemoryBarriers, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "imageMemoryBarrierCount", toStringFlags, tabCount, tabSize, ToString(imageMemoryBarrierCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageMemoryBarriers", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pImageMemoryBarriers, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBeginQuery", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdEndQuery", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "query", toStringFlags, tabCount, tabSize, ToString(query, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdResetQueryPool", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdWriteTimestamp", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdCopyQueryPoolResults", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdPushConstants", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBeginRenderPass", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderPassBegin", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderPassBegin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "contents", toStringFlags, tabCount, tabSize, '"' + ToString(contents, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdNextSubpass", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "contents", toStringFlags, tabCount, tabSize, '"' + ToString(contents, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdEndRenderPass", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdExecuteCommands", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "commandBufferCount", toStringFlags, tabCount, tabSize, ToString(commandBufferCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCommandBuffers", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(commandBufferCount, pCommandBuffers, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkBindBufferMemory2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfos, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkBindImageMemory2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfos, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetDeviceGroupPeerMemoryFeatures", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDeviceMask", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "deviceMask", toStringFlags, tabCount, tabSize, ToString(deviceMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDispatchBase", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDeviceGroups", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "[out]pPhysicalDeviceGroupCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPhysicalDeviceGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPhysicalDeviceGroupProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pPhysicalDeviceGroupProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageMemoryRequirements2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetBufferMemoryRequirements2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageSparseMemoryRequirements2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFeatures2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFormatProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceImageFormatProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pImageFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pQueueFamilyPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueFamilyPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueueFamilyProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pQueueFamilyProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMemoryProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pMemoryProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkTrimCommandPool", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, HandleIdToString(commandPool));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceQueue2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pQueueInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueue", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pQueue));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateSamplerYcbcrConversion", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pYcbcrConversion", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pYcbcrConversion));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroySamplerYcbcrConversion", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "ycbcrConversion", toStringFlags, tabCount, tabSize, HandleIdToString(ycbcrConversion));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateDescriptorUpdateTemplate", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDescriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDescriptorUpdateTemplate));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyDescriptorUpdateTemplate", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorUpdateTemplate));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalBufferProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalBufferProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalFenceProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalFenceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalFenceProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalSemaphoreProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalSemaphoreInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalSemaphoreProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDescriptorSetLayoutSupport", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSupport", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSupport, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectCount", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirectCount", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateRenderPass2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pRenderPass", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pRenderPass));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBeginRenderPass2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderPassBegin", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderPassBegin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpassBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassBeginInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdNextSubpass2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pSubpassBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassBeginInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpassEndInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassEndInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdEndRenderPass2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pSubpassEndInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassEndInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkResetQueryPool", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetSemaphoreCounterValue", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "[out]pValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pValue, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkWaitSemaphores", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pWaitInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pWaitInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkSignalSemaphore", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pSignalInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSignalInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetBufferDeviceAddress", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetBufferOpaqueCaptureAddress", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceMemoryOpaqueCaptureAddress", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceToolProperties", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pToolCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pToolCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pToolProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pToolProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreatePrivateDataSlot", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPrivateDataSlot", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPrivateDataSlot));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyPrivateDataSlot", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetPrivateData(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkSetPrivateData", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, '"' + ToString(objectType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(data, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPrivateData", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetEvent2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "pDependencyInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDependencyInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdResetEvent2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, ToString(stageMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdWaitEvents2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "eventCount", toStringFlags, tabCount, tabSize, ToString(eventCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pEvents", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(eventCount, pEvents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDependencyInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pDependencyInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdPipelineBarrier2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pDependencyInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDependencyInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdWriteTimestamp2", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkQueueSubmit2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "submitCount", toStringFlags, tabCount, tabSize, ToString(submitCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubmits", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSubmits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyBuffer2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyBufferInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyImage2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyBufferToImage2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyBufferToImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyBufferToImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyImageToBuffer2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyImageToBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyImageToBufferInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBlitImage2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pBlitImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBlitImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdResolveImage2", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pResolveImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pResolveImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBeginRendering", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderingInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderingInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdEndRendering", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetCullMode", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "cullMode", toStringFlags, tabCount, tabSize, ToString(cullMode, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetFrontFace", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "frontFace", toStringFlags, tabCount, tabSize, '"' + ToString(frontFace, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveTopology", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "primitiveTopology", toStringFlags, tabCount, tabSize, '"' + ToString(primitiveTopology, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetViewportWithCount", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewports", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pViewports, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetScissorWithCount", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "scissorCount", toStringFlags, tabCount, tabSize, ToString(scissorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pScissors", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pScissors, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdBindVertexBuffers2", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthTestEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthTestEnable", toStringFlags, tabCount, tabSize, ToString(depthTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthWriteEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthWriteEnable", toStringFlags, tabCount, tabSize, ToString(depthWriteEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthCompareOp", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthCompareOp", toStringFlags, tabCount, tabSize, '"' + ToString(depthCompareOp, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthBoundsTestEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthBoundsTestEnable", toStringFlags, tabCount, tabSize, ToString(depthBoundsTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetStencilTestEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stencilTestEnable", toStringFlags, tabCount, tabSize, ToString(stencilTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdSetStencilOp", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetRasterizerDiscardEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "rasterizerDiscardEnable", toStringFlags, tabCount, tabSize, ToString(rasterizerDiscardEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthBiasEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthBiasEnable", toStringFlags, tabCount, tabSize, ToString(depthBiasEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveRestartEnable", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "primitiveRestartEnable", toStringFlags, tabCount, tabSize, ToString(primitiveRestartEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceBufferMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceImageMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceImageSparseMemoryRequirements", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroySurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pSupported", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSupported, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pSurfaceCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceCapabilities, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceFormatsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pSurfaceFormatCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceFormatCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurfaceFormats", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSurfaceFormats, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfacePresentModesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pPresentModeCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentModeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPresentModes", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(pPresentModeCount, pPresentModes, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateSwapchainKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSwapchain", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSwapchain));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroySwapchainKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetSwapchainImagesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "[out]pSwapchainImageCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSwapchainImageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSwapchainImages", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(pSwapchainImageCount, pSwapchainImages, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkAcquireNextImageKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkAcquireNextImageKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
            FieldToString(strStrm, false, "[out]pImageIndex", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageIndex, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkQueuePresentKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "pPresentInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceGroupPresentCapabilitiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "[out]pDeviceGroupPresentCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDeviceGroupPresentCapabilities, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceGroupSurfacePresentModesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pModes", toStringFlags, tabCount, tabSize, PointerDecoderToString(pModes, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDevicePresentRectanglesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pRectCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRectCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pRects", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRects, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkAcquireNextImage2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAcquireInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAcquireInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pImageIndex", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageIndex, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayPropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetDisplayPlaneSupportedDisplaysKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "planeIndex", toStringFlags, tabCount, tabSize, ToString(planeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDisplayCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDisplays", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(pDisplayCount, pDisplays, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetDisplayModePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateDisplayModeKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMode", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pMode));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetDisplayPlaneCapabilitiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, HandleIdToString(mode));
            FieldToString(strStrm, false, "planeIndex", toStringFlags, tabCount, tabSize, ToString(planeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCapabilities, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateDisplayPlaneSurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateSharedSwapchainsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSwapchains", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(swapchainCount, pSwapchains, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateXlibSurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceXlibPresentationSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dpy", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dpy));
            FieldToString(strStrm, false, "visualID", toStringFlags, tabCount, tabSize, ToString(visualID, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateXcbSurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceXcbPresentationSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "connection", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(connection));
            FieldToString(strStrm, false, "visual_id", toStringFlags, tabCount, tabSize, ToString(visual_id, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateWaylandSurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceWaylandPresentationSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(display));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateAndroidSurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateWin32SurfaceKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceWin32PresentationSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBeginRenderingKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderingInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderingInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdEndRenderingKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFeatures2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFormatProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceImageFormatProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pImageFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pQueueFamilyPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueFamilyPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pQueueFamilyProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pQueueFamilyProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMemoryProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pMemoryProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetDeviceGroupPeerMemoryFeaturesKHR", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDeviceMaskKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "deviceMask", toStringFlags, tabCount, tabSize, ToString(deviceMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDispatchBaseKHR", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkTrimCommandPoolKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, HandleIdToString(commandPool));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDeviceGroupsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "[out]pPhysicalDeviceGroupCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPhysicalDeviceGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPhysicalDeviceGroupProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pPhysicalDeviceGroupProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalBufferPropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalBufferProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetMemoryWin32HandleKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetWin32HandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetMemoryWin32HandlePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, '"' + ToString(handleType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "handle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(handle));
            FieldToString(strStrm, false, "[out]pMemoryWin32HandleProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryWin32HandleProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetMemoryFdKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetFdInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFd", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFd, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetMemoryFdPropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, '"' + ToString(handleType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "fd", toStringFlags, tabCount, tabSize, ToString(fd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryFdProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryFdProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalSemaphoreInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalSemaphoreProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkImportSemaphoreWin32HandleKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportSemaphoreWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportSemaphoreWin32HandleInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetSemaphoreWin32HandleKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetWin32HandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkImportSemaphoreFdKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportSemaphoreFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportSemaphoreFdInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetSemaphoreFdKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetFdInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFd", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFd, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdPushDescriptorSetKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, '"' + ToString(pipelineBindPoint, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, HandleIdToString(layout));
            FieldToString(strStrm, false, "set", toStringFlags, tabCount, tabSize, ToString(set, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "descriptorWriteCount", toStringFlags, tabCount, tabSize, ToString(descriptorWriteCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorWrites", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pDescriptorWrites, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateDescriptorUpdateTemplateKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDescriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDescriptorUpdateTemplate));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyDescriptorUpdateTemplateKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorUpdateTemplate));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateRenderPass2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pRenderPass", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pRenderPass));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBeginRenderPass2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderPassBegin", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderPassBegin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpassBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassBeginInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdNextSubpass2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pSubpassBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassBeginInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubpassEndInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassEndInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdEndRenderPass2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pSubpassEndInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubpassEndInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetSwapchainStatusKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalFencePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalFenceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalFenceProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkImportFenceWin32HandleKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportFenceWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportFenceWin32HandleInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetFenceWin32HandleKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetWin32HandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkImportFenceFdKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportFenceFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportFenceFdInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetFenceFdKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetFdInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFd", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFd, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCounterCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCounterCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCounters", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCounters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCounterDescriptions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCounterDescriptions, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pPerformanceQueryCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPerformanceQueryCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pNumPasses", toStringFlags, tabCount, tabSize, PointerDecoderToString(pNumPasses, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkAcquireProfilingLockKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkReleaseProfilingLockKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceCapabilities2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurfaceCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceCapabilities, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceFormats2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurfaceFormatCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceFormatCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurfaceFormats", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSurfaceFormats, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayModeProperties2KHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetDisplayModeProperties2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDisplayPlaneCapabilities2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pDisplayPlaneInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayPlaneInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCapabilities, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageMemoryRequirements2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetBufferMemoryRequirements2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageSparseMemoryRequirements2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateSamplerYcbcrConversionKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pYcbcrConversion", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pYcbcrConversion));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroySamplerYcbcrConversionKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "ycbcrConversion", toStringFlags, tabCount, tabSize, HandleIdToString(ycbcrConversion));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkBindBufferMemory2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfos, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkBindImageMemory2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfos, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDescriptorSetLayoutSupportKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSupport", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSupport, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectCountKHR", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirectCountKHR", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetSemaphoreCounterValueKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "[out]pValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pValue, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkWaitSemaphoresKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pWaitInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pWaitInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkSignalSemaphoreKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pSignalInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSignalInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFragmentShadingRatesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pFragmentShadingRateCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFragmentShadingRateCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFragmentShadingRates", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pFragmentShadingRates, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetFragmentShadingRateKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pFragmentSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFragmentSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "combinerOps", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(2, combinerOps, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkWaitForPresentKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "presentId", toStringFlags, tabCount, tabSize, ToString(presentId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetBufferDeviceAddressKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetBufferOpaqueCaptureAddressKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceMemoryOpaqueCaptureAddressKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCreateDeferredOperationKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDeferredOperation", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDeferredOperation));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyDeferredOperationKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeferredOperationMaxConcurrencyKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeferredOperationResultKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDeferredOperationJoinKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPipelineExecutablePropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pPipelineInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPipelineInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExecutableCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExecutableCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPipelineExecutableStatisticsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pExecutableInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExecutableInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pStatisticCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pStatisticCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pStatistics", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pStatistics, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPipelineExecutableInternalRepresentationsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pExecutableInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExecutableInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pInternalRepresentationCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInternalRepresentationCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pInternalRepresentations", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pInternalRepresentations, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetEvent2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "pDependencyInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDependencyInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdResetEvent2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, ToString(stageMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdWaitEvents2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "eventCount", toStringFlags, tabCount, tabSize, ToString(eventCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pEvents", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(eventCount, pEvents, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDependencyInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pDependencyInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdPipelineBarrier2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pDependencyInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDependencyInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdWriteTimestamp2KHR", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkQueueSubmit2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "submitCount", toStringFlags, tabCount, tabSize, ToString(submitCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubmits", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSubmits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdWriteBufferMarker2AMD", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetQueueCheckpointData2NV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "[out]pCheckpointDataCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCheckpointDataCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCheckpointData", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCheckpointData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyBuffer2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyBufferInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyImage2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyBufferToImage2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyBufferToImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyBufferToImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyImageToBuffer2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCopyImageToBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCopyImageToBufferInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBlitImage2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pBlitImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBlitImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdResolveImage2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pResolveImageInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pResolveImageInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdTraceRaysIndirect2KHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "indirectDeviceAddress", toStringFlags, tabCount, tabSize, ToString(indirectDeviceAddress, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceBufferMemoryRequirementsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceImageMemoryRequirementsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceImageSparseMemoryRequirementsKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateDebugReportCallbackEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCallback", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pCallback));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyDebugReportCallbackEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "callback", toStringFlags, tabCount, tabSize, HandleIdToString(callback));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDebugReportMessageEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkDebugReportMessageEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDebugMarkerSetObjectTagEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pTagInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pTagInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDebugMarkerSetObjectNameEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pNameInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pNameInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdDebugMarkerBeginEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pMarkerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMarkerInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdDebugMarkerEndEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdDebugMarkerInsertEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pMarkerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMarkerInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdBindTransformFeedbackBuffersEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdBeginTransformFeedbackEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdEndTransformFeedbackEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdBeginQueryIndexedEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdEndQueryIndexedEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectByteCountEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageViewHandleNVX", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageViewAddressNVX", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectCountAMD", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirectCountAMD", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetShaderInfoAMD", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "shaderStage", toStringFlags, tabCount, tabSize, '"' + ToString(shaderStage, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "infoType", toStringFlags, tabCount, tabSize, '"' + ToString(infoType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pInfoSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfoSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pInfo", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pInfo));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateStreamDescriptorSurfaceGGP", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, '"' + ToString(format, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, '"' + ToString(type, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, '"' + ToString(tiling, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "externalHandleType", toStringFlags, tabCount, tabSize, ToString(externalHandleType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pExternalImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalImageFormatProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetMemoryWin32HandleNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, ToString(handleType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateViSurfaceNN", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBeginConditionalRenderingEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pConditionalRenderingBegin", toStringFlags, tabCount, tabSize, PointerDecoderToString(pConditionalRenderingBegin, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdEndConditionalRenderingEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetViewportWScalingNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstViewport", toStringFlags, tabCount, tabSize, ToString(firstViewport, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewportWScalings", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pViewportWScalings, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkReleaseDisplayEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkAcquireXlibDisplayEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "dpy", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dpy));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetRandROutputDisplayEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "dpy", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dpy));
            FieldToString(strStrm, false, "rrOutput", toStringFlags, tabCount, tabSize, ToString(rrOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDisplay", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDisplay));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceCapabilities2EXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "[out]pSurfaceCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceCapabilities, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDisplayPowerControlEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pDisplayPowerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayPowerInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkRegisterDeviceEventEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pDeviceEventInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDeviceEventInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFence", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFence));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkRegisterDisplayEventEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pDisplayEventInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayEventInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pFence", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFence));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetSwapchainCounterEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "counter", toStringFlags, tabCount, tabSize, '"' + ToString(counter, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pCounterValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCounterValue, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetRefreshCycleDurationGOOGLE", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "[out]pDisplayTimingProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayTimingProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPastPresentationTimingGOOGLE", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "[out]pPresentationTimingCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentationTimingCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPresentationTimings", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pPresentationTimings, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDiscardRectangleEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstDiscardRectangle", toStringFlags, tabCount, tabSize, ToString(firstDiscardRectangle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "discardRectangleCount", toStringFlags, tabCount, tabSize, ToString(discardRectangleCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDiscardRectangles", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pDiscardRectangles, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkSetHdrMetadataEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSwapchains", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(swapchainCount, pSwapchains, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMetadata", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pMetadata, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateIOSSurfaceMVK", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateMacOSSurfaceMVK", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkSetDebugUtilsObjectNameEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pNameInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pNameInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkSetDebugUtilsObjectTagEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pTagInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pTagInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkQueueBeginDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "pLabelInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLabelInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkQueueEndDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
        }
    );
}

void VulkanAsciiConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkQueueInsertDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "pLabelInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLabelInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBeginDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pLabelInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLabelInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdEndDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdInsertDebugUtilsLabelEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pLabelInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLabelInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateDebugUtilsMessengerEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMessenger", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pMessenger));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyDebugUtilsMessengerEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "messenger", toStringFlags, tabCount, tabSize, HandleIdToString(messenger));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkSubmitDebugUtilsMessageEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetAndroidHardwareBufferPropertiesANDROID", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(buffer));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetMemoryAndroidHardwareBufferANDROID", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pBuffer", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pBuffer));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetSampleLocationsEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pSampleLocationsInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSampleLocationsInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMultisamplePropertiesEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, '"' + ToString(samples, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pMultisampleProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMultisampleProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageDrmFormatModifierPropertiesEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateValidationCacheEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pValidationCache", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pValidationCache));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyValidationCacheEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "validationCache", toStringFlags, tabCount, tabSize, HandleIdToString(validationCache));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkMergeValidationCachesEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "dstCache", toStringFlags, tabCount, tabSize, HandleIdToString(dstCache));
            FieldToString(strStrm, false, "srcCacheCount", toStringFlags, tabCount, tabSize, ToString(srcCacheCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSrcCaches", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(srcCacheCount, pSrcCaches, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetValidationCacheDataEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "validationCache", toStringFlags, tabCount, tabSize, HandleIdToString(validationCache));
            FieldToString(strStrm, false, "[out]pDataSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBindShadingRateImageNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(imageLayout, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetViewportShadingRatePaletteNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstViewport", toStringFlags, tabCount, tabSize, ToString(firstViewport, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pShadingRatePalettes", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pShadingRatePalettes, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetCoarseSampleOrderNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "sampleOrderType", toStringFlags, tabCount, tabSize, '"' + ToString(sampleOrderType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "customSampleOrderCount", toStringFlags, tabCount, tabSize, ToString(customSampleOrderCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCustomSampleOrders", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCustomSampleOrders, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateAccelerationStructureNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pAccelerationStructure", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pAccelerationStructure));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyAccelerationStructureNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, HandleIdToString(accelerationStructure));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureMemoryRequirementsNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkBindAccelerationStructureMemoryNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfos, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdBuildAccelerationStructureNV", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyAccelerationStructureNV", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdTraceRaysNV", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateRayTracingPipelinesNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetRayTracingShaderGroupHandlesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "firstGroup", toStringFlags, tabCount, tabSize, ToString(firstGroup, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetRayTracingShaderGroupHandlesNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "firstGroup", toStringFlags, tabCount, tabSize, ToString(firstGroup, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureHandleNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, HandleIdToString(accelerationStructure));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdWriteAccelerationStructuresPropertiesNV", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCompileDeferredNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "shader", toStringFlags, tabCount, tabSize, ToString(shader, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetMemoryHostPointerPropertiesEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, '"' + ToString(handleType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "pHostPointer", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHostPointer));
            FieldToString(strStrm, false, "[out]pMemoryHostPointerProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryHostPointerProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdWriteBufferMarkerAMD", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pTimeDomainCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pTimeDomainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pTimeDomains", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(pTimeDomainCount, pTimeDomains, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetCalibratedTimestampsEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "timestampCount", toStringFlags, tabCount, tabSize, ToString(timestampCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTimestampInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pTimestampInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pTimestamps", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(timestampCount, pTimestamps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMaxDeviation", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMaxDeviation, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "taskCount", toStringFlags, tabCount, tabSize, ToString(taskCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstTask", toStringFlags, tabCount, tabSize, ToString(firstTask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksIndirectNV", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksIndirectCountNV", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetExclusiveScissorNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstExclusiveScissor", toStringFlags, tabCount, tabSize, ToString(firstExclusiveScissor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "exclusiveScissorCount", toStringFlags, tabCount, tabSize, ToString(exclusiveScissorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExclusiveScissors", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pExclusiveScissors, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetCheckpointNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCheckpointMarker", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pCheckpointMarker));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetQueueCheckpointDataNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "[out]pCheckpointDataCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCheckpointDataCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCheckpointData", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCheckpointData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkInitializePerformanceApiINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInitializeInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInitializeInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkUninitializePerformanceApiINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetPerformanceMarkerINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pMarkerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMarkerInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetPerformanceStreamMarkerINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pMarkerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMarkerInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetPerformanceOverrideINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pOverrideInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pOverrideInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkAcquirePerformanceConfigurationINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAcquireInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAcquireInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pConfiguration", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pConfiguration));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkReleasePerformanceConfigurationINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "configuration", toStringFlags, tabCount, tabSize, HandleIdToString(configuration));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkQueueSetPerformanceConfigurationINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "configuration", toStringFlags, tabCount, tabSize, HandleIdToString(configuration));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPerformanceParameterINTEL", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "parameter", toStringFlags, tabCount, tabSize, '"' + ToString(parameter, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "[out]pValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pValue, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkSetLocalDimmingAMD", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapChain", toStringFlags, tabCount, tabSize, HandleIdToString(swapChain));
            FieldToString(strStrm, false, "localDimmingEnable", toStringFlags, tabCount, tabSize, ToString(localDimmingEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateImagePipeSurfaceFUCHSIA", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateMetalSurfaceEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetBufferDeviceAddressEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceToolPropertiesEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pToolCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pToolCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pToolProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pToolProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "[out]pCombinationCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCombinationCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCombinations", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCombinations, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfacePresentModes2EXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPresentModeCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentModeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPresentModes", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(pPresentModeCount, pPresentModes, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkAcquireFullScreenExclusiveModeEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkReleaseFullScreenExclusiveModeEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceGroupSurfacePresentModes2EXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pModes", toStringFlags, tabCount, tabSize, PointerDecoderToString(pModes, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateHeadlessSurfaceEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetLineStippleEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "lineStippleFactor", toStringFlags, tabCount, tabSize, ToString(lineStippleFactor, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "lineStipplePattern", toStringFlags, tabCount, tabSize, ToString(lineStipplePattern, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkResetQueryPoolEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetCullModeEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "cullMode", toStringFlags, tabCount, tabSize, ToString(cullMode, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetFrontFaceEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "frontFace", toStringFlags, tabCount, tabSize, '"' + ToString(frontFace, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveTopologyEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "primitiveTopology", toStringFlags, tabCount, tabSize, '"' + ToString(primitiveTopology, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetViewportWithCountEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewports", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pViewports, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetScissorWithCountEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "scissorCount", toStringFlags, tabCount, tabSize, ToString(scissorCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pScissors", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pScissors, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdBindVertexBuffers2EXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthTestEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthTestEnable", toStringFlags, tabCount, tabSize, ToString(depthTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthWriteEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthWriteEnable", toStringFlags, tabCount, tabSize, ToString(depthWriteEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthCompareOpEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthCompareOp", toStringFlags, tabCount, tabSize, '"' + ToString(depthCompareOp, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthBoundsTestEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthBoundsTestEnable", toStringFlags, tabCount, tabSize, ToString(depthBoundsTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetStencilTestEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stencilTestEnable", toStringFlags, tabCount, tabSize, ToString(stencilTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdSetStencilOpEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetGeneratedCommandsMemoryRequirementsNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdPreprocessGeneratedCommandsNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pGeneratedCommandsInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGeneratedCommandsInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdExecuteGeneratedCommandsNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "isPreprocessed", toStringFlags, tabCount, tabSize, ToString(isPreprocessed, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pGeneratedCommandsInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGeneratedCommandsInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBindPipelineShaderGroupNV", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateIndirectCommandsLayoutNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pIndirectCommandsLayout", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pIndirectCommandsLayout));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyIndirectCommandsLayoutNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "indirectCommandsLayout", toStringFlags, tabCount, tabSize, HandleIdToString(indirectCommandsLayout));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    format::HandleId                            display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkAcquireDrmDisplayEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "drmFd", toStringFlags, tabCount, tabSize, ToString(drmFd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetDrmDisplayEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "drmFd", toStringFlags, tabCount, tabSize, ToString(drmFd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "connectorId", toStringFlags, tabCount, tabSize, ToString(connectorId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]display", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(display));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreatePrivateDataSlotEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPrivateDataSlot", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPrivateDataSlot));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyPrivateDataSlotEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkSetPrivateDataEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, '"' + ToString(objectType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(data, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetPrivateDataEXT", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetFragmentShadingRateEnumNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "shadingRate", toStringFlags, tabCount, tabSize, '"' + ToString(shadingRate, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "combinerOps", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(2, combinerOps, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2EXT>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2EXT>* pLayout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetImageSubresourceLayout2EXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "pSubresource", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pLayout", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLayout, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkAcquireWinrtDisplayNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetWinrtDisplayNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "deviceRelativeId", toStringFlags, tabCount, tabSize, ToString(deviceRelativeId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pDisplay", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDisplay));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateDirectFBSurfaceEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dfb", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dfb));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdSetVertexInputEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "vertexBindingDescriptionCount", toStringFlags, tabCount, tabSize, ToString(vertexBindingDescriptionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexBindingDescriptions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pVertexBindingDescriptions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "vertexAttributeDescriptionCount", toStringFlags, tabCount, tabSize, ToString(vertexAttributeDescriptionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexAttributeDescriptions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pVertexAttributeDescriptions, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetMemoryZirconHandleFUCHSIA", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetZirconHandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetZirconHandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pZirconHandle", toStringFlags, tabCount, tabSize, PointerDecoderToString(pZirconHandle, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetMemoryZirconHandlePropertiesFUCHSIA", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, '"' + ToString(handleType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "zirconHandle", toStringFlags, tabCount, tabSize, ToString(zirconHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pMemoryZirconHandleProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryZirconHandleProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkImportSemaphoreZirconHandleFUCHSIA", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportSemaphoreZirconHandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportSemaphoreZirconHandleInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetSemaphoreZirconHandleFUCHSIA", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetZirconHandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetZirconHandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pZirconHandle", toStringFlags, tabCount, tabSize, PointerDecoderToString(pZirconHandle, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdBindInvocationMaskHUAWEI", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, '"' + ToString(imageLayout, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo,
    PointerDecoder<uint64_t, void*>*            pAddress)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetMemoryRemoteAddressNV", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pMemoryGetRemoteAddressInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryGetRemoteAddressInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pAddress", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pAddress));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetPatchControlPointsEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "patchControlPoints", toStringFlags, tabCount, tabSize, ToString(patchControlPoints, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetRasterizerDiscardEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "rasterizerDiscardEnable", toStringFlags, tabCount, tabSize, ToString(rasterizerDiscardEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetDepthBiasEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthBiasEnable", toStringFlags, tabCount, tabSize, ToString(depthBiasEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetLogicOpEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "logicOp", toStringFlags, tabCount, tabSize, '"' + ToString(logicOp, toStringFlags, tabCount, tabSize) + '"');
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveRestartEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "primitiveRestartEnable", toStringFlags, tabCount, tabSize, ToString(primitiveRestartEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateScreenSurfaceQNX", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    window)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceScreenPresentationSupportQNX", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "window", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(window));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetColorWriteEnableEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorWriteEnables", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(attachmentCount, pColorWriteEnables, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawMultiEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "drawCount", toStringFlags, tabCount, tabSize, ToString(drawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexInfo", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pVertexInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCount", toStringFlags, tabCount, tabSize, ToString(instanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstInstance", toStringFlags, tabCount, tabSize, ToString(firstInstance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdDrawMultiIndexedEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "drawCount", toStringFlags, tabCount, tabSize, ToString(drawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIndexInfo", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pIndexInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "instanceCount", toStringFlags, tabCount, tabSize, ToString(instanceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "firstInstance", toStringFlags, tabCount, tabSize, ToString(firstInstance, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVertexOffset", toStringFlags, tabCount, tabSize, PointerDecoderToString(pVertexOffset, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkSetDeviceMemoryPriorityEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "priority", toStringFlags, tabCount, tabSize, ToString(priority, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDescriptorSetLayoutHostMappingInfoVALVE", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pBindingReference", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBindingReference, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pHostMapping", toStringFlags, tabCount, tabSize, PointerDecoderToString(pHostMapping, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDescriptorSetHostMappingVALVE", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorSet", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorSet));
            FieldToString(strStrm, false, "[out]ppData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(ppData));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetShaderModuleIdentifierEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "shaderModule", toStringFlags, tabCount, tabSize, HandleIdToString(shaderModule));
            FieldToString(strStrm, false, "[out]pIdentifier", toStringFlags, tabCount, tabSize, PointerDecoderToString(pIdentifier, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetShaderModuleCreateInfoIdentifierEXT", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pIdentifier", toStringFlags, tabCount, tabSize, PointerDecoderToString(pIdentifier, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    PointerDecoder<uint32_t>*                   pPropertiesCount,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetFramebufferTilePropertiesQCOM", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "framebuffer", toStringFlags, tabCount, tabSize, HandleIdToString(framebuffer));
            FieldToString(strStrm, false, "[out]pPropertiesCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertiesCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDynamicRenderingTilePropertiesQCOM", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pRenderingInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderingInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateAccelerationStructureKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pAccelerationStructure", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pAccelerationStructure));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkDestroyAccelerationStructureKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, HandleIdToString(accelerationStructure));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCopyAccelerationStructureToMemoryKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCopyMemoryToAccelerationStructureKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkWriteAccelerationStructuresPropertiesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "accelerationStructureCount", toStringFlags, tabCount, tabSize, ToString(accelerationStructureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructures", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(accelerationStructureCount, pAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryType", toStringFlags, tabCount, tabSize, '"' + ToString(queryType, toStringFlags, tabCount, tabSize) + '"');
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyAccelerationStructureKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyAccelerationStructureToMemoryKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdCopyMemoryToAccelerationStructureKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureDeviceAddressKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdWriteAccelerationStructuresPropertiesKHR", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkGetDeviceAccelerationStructureCompatibilityKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pVersionInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pVersionInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pCompatibility", toStringFlags, tabCount, tabSize, EnumPointerDecoderToString(pCompatibility));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdTraceRaysKHR", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCreateRayTracingPipelinesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "firstGroup", toStringFlags, tabCount, tabSize, ToString(firstGroup, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "[out]pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkCmdTraceRaysIndirectKHR", toStringFlags, tabCount, tabSize,
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
    const ApiCallInfo&                          call_info,
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
    WriteApiCallToFile(call_info, "vkGetRayTracingShaderGroupStackSizeKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "group", toStringFlags, tabCount, tabSize, ToString(group, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupShader", toStringFlags, tabCount, tabSize, '"' + ToString(groupShader, toStringFlags, tabCount, tabSize) + '"');
        }, ('"' + ToString(returnValue, toStringFlags, tabCount, tabSize) + '"').c_str()
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    using namespace gfxrecon::util;
    ToStringFlags toStringFlags = kToString_Default;
    uint32_t tabCount = 0;
    uint32_t tabSize = 4;
    WriteApiCallToFile(call_info, "vkCmdSetRayTracingPipelineStackSizeKHR", toStringFlags, tabCount, tabSize,
        [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineStackSize", toStringFlags, tabCount, tabSize, ToString(pipelineStackSize, toStringFlags, tabCount, tabSize));
        }
    );
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
