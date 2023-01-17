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

namespace {
    using namespace gfxrecon::util;
    const ToStringFlags toStringFlags = kToString_Default;
    const uint32_t tabCount = 0;
    const uint32_t tabSize = 4;
}

void VulkanAsciiConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    WriteApiCallToFile(call_info, "vkCreateInstance", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInstance", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pInstance));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyInstance", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDevices", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pPhysicalDeviceCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPhysicalDeviceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPhysicalDevices", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(pPhysicalDeviceCount, pPhysicalDevices, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFeatures", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFormatProperties", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatProperties, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceImageFormatProperties", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, Quote(ToString(tiling, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceProperties", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyProperties", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pQueueFamilyPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueFamilyPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueueFamilyProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pQueueFamilyProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMemoryProperties", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pMemoryProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryProperties, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkCreateDevice", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDevice", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDevice));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDevice", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetDeviceQueue", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queueIndex", toStringFlags, tabCount, tabSize, ToString(queueIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueue", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pQueue));
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
    WriteApiCallToFile(call_info, "vkQueueSubmit", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "submitCount", toStringFlags, tabCount, tabSize, ToString(submitCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubmits", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSubmits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    WriteApiCallToFile(call_info, "vkQueueWaitIdle", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    WriteApiCallToFile(call_info, "vkDeviceWaitIdle", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkAllocateMemory", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAllocateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemory", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pMemory));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkFreeMemory", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkMapMemory", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "size", toStringFlags, tabCount, tabSize, ToString(size, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "ppData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(ppData));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    WriteApiCallToFile(call_info, "vkUnmapMemory", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkFlushMappedMemoryRanges", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memoryRangeCount", toStringFlags, tabCount, tabSize, ToString(memoryRangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRanges", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pMemoryRanges, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    WriteApiCallToFile(call_info, "vkInvalidateMappedMemoryRanges", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memoryRangeCount", toStringFlags, tabCount, tabSize, ToString(memoryRangeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRanges", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pMemoryRanges, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    WriteApiCallToFile(call_info, "vkGetDeviceMemoryCommitment", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "pCommittedMemoryInBytes", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCommittedMemoryInBytes, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkBindBufferMemory", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(memoryOffset, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkBindImageMemory", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "memoryOffset", toStringFlags, tabCount, tabSize, ToString(memoryOffset, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetBufferMemoryRequirements", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetImageMemoryRequirements", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetImageSparseMemoryRequirements", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, Quote(ToString(samples, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, Quote(ToString(tiling, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkQueueBindSparse", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfo", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateFence", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFence", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFence));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyFence", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkResetFences", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fenceCount", toStringFlags, tabCount, tabSize, ToString(fenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFences", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(fenceCount, pFences, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    WriteApiCallToFile(call_info, "vkGetFenceStatus", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkWaitForFences", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "fenceCount", toStringFlags, tabCount, tabSize, ToString(fenceCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFences", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(fenceCount, pFences, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "waitAll", toStringFlags, tabCount, tabSize, ToString(waitAll, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateSemaphore", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSemaphore", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSemaphore));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySemaphore", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateEvent", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pEvent", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pEvent));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyEvent", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetEventStatus", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    WriteApiCallToFile(call_info, "vkSetEvent", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    WriteApiCallToFile(call_info, "vkResetEvent", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateQueryPool", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueryPool", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pQueryPool));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyQueryPool", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetQueryPoolResults", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "firstQuery", toStringFlags, tabCount, tabSize, ToString(firstQuery, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryCount", toStringFlags, tabCount, tabSize, ToString(queryCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateBuffer", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBuffer", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pBuffer));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyBuffer", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateBufferView", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pView", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pView));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyBufferView", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateImage", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImage", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pImage));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyImage", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetImageSubresourceLayout", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "pSubresource", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pLayout", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLayout, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkCreateImageView", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pView", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pView));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyImageView", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateShaderModule", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pShaderModule", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pShaderModule));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyShaderModule", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreatePipelineCache", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPipelineCache", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPipelineCache));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyPipelineCache", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetPipelineCacheData", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "pDataSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkMergePipelineCaches", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "dstCache", toStringFlags, tabCount, tabSize, HandleIdToString(dstCache));
            FieldToString(strStrm, false, "srcCacheCount", toStringFlags, tabCount, tabSize, ToString(srcCacheCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSrcCaches", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(srcCacheCount, pSrcCaches, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateGraphicsPipelines", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateComputePipelines", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyPipeline", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreatePipelineLayout", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPipelineLayout", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPipelineLayout));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyPipelineLayout", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateSampler", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSampler", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSampler));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySampler", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateDescriptorSetLayout", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSetLayout", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSetLayout));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDescriptorSetLayout", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateDescriptorPool", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorPool", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDescriptorPool));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDescriptorPool", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkResetDescriptorPool", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorPool", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorPool));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkFreeDescriptorSets", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorPool", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorPool));
            FieldToString(strStrm, false, "descriptorSetCount", toStringFlags, tabCount, tabSize, ToString(descriptorSetCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorSets", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(descriptorSetCount, pDescriptorSets, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkUpdateDescriptorSets", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateFramebuffer", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFramebuffer", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFramebuffer));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyFramebuffer", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateRenderPass", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRenderPass", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pRenderPass));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyRenderPass", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetRenderAreaGranularity", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "renderPass", toStringFlags, tabCount, tabSize, HandleIdToString(renderPass));
            FieldToString(strStrm, false, "pGranularity", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGranularity, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkCreateCommandPool", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCommandPool", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pCommandPool));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyCommandPool", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkResetCommandPool", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "commandPool", toStringFlags, tabCount, tabSize, HandleIdToString(commandPool));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    WriteApiCallToFile(call_info, "vkFreeCommandBuffers", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkBeginCommandBuffer", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBeginInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    WriteApiCallToFile(call_info, "vkEndCommandBuffer", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    WriteApiCallToFile(call_info, "vkResetCommandBuffer", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    WriteApiCallToFile(call_info, "vkCmdBindPipeline", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, Quote(ToString(pipelineBindPoint, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdSetViewport", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetScissor", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetLineWidth", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetDepthBias", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetBlendConstants", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetDepthBounds", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetStencilCompareMask", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetStencilWriteMask", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetStencilReference", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBindDescriptorSets", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, Quote(ToString(pipelineBindPoint, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdBindIndexBuffer", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "indexType", toStringFlags, tabCount, tabSize, Quote(ToString(indexType, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdBindVertexBuffers", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDraw", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndexed", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndirect", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirect", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDispatch", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDispatchIndirect", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyBuffer", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyImage", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(srcImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(dstImageLayout, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdBlitImage", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(srcImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(dstImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "regionCount", toStringFlags, tabCount, tabSize, ToString(regionCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRegions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRegions, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "filter", toStringFlags, tabCount, tabSize, Quote(ToString(filter, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdCopyBufferToImage", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(srcBuffer));
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(dstImageLayout, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdCopyImageToBuffer", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(srcImageLayout, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdUpdateBuffer", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdFillBuffer", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdClearColorImage", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(imageLayout, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdClearDepthStencilImage", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(imageLayout, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdClearAttachments", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdResolveImage", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "srcImage", toStringFlags, tabCount, tabSize, HandleIdToString(srcImage));
            FieldToString(strStrm, false, "srcImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(srcImageLayout, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dstImage", toStringFlags, tabCount, tabSize, HandleIdToString(dstImage));
            FieldToString(strStrm, false, "dstImageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(dstImageLayout, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdSetEvent", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdResetEvent", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdWaitEvents", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdPipelineBarrier", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBeginQuery", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdEndQuery", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdResetQueryPool", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdWriteTimestamp", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineStage", toStringFlags, tabCount, tabSize, Quote(ToString(pipelineStage, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdCopyQueryPoolResults", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdPushConstants", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBeginRenderPass", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pRenderPassBegin", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderPassBegin, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "contents", toStringFlags, tabCount, tabSize, Quote(ToString(contents, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    WriteApiCallToFile(call_info, "vkCmdNextSubpass", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "contents", toStringFlags, tabCount, tabSize, Quote(ToString(contents, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    WriteApiCallToFile(call_info, "vkCmdEndRenderPass", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdExecuteCommands", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkBindBufferMemory2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfos, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    WriteApiCallToFile(call_info, "vkBindImageMemory2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfos, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetDeviceGroupPeerMemoryFeatures", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "heapIndex", toStringFlags, tabCount, tabSize, ToString(heapIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "localDeviceIndex", toStringFlags, tabCount, tabSize, ToString(localDeviceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "remoteDeviceIndex", toStringFlags, tabCount, tabSize, ToString(remoteDeviceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPeerMemoryFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPeerMemoryFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    WriteApiCallToFile(call_info, "vkCmdSetDeviceMask", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDispatchBase", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDeviceGroups", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pPhysicalDeviceGroupCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPhysicalDeviceGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPhysicalDeviceGroupProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pPhysicalDeviceGroupProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetImageMemoryRequirements2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetBufferMemoryRequirements2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetImageSparseMemoryRequirements2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFeatures2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceProperties2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFormatProperties2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatProperties, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceImageFormatProperties2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pImageFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pQueueFamilyPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueFamilyPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueueFamilyProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pQueueFamilyProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMemoryProperties2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pMemoryProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryProperties, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    WriteApiCallToFile(call_info, "vkTrimCommandPool", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetDeviceQueue2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pQueueInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueue", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pQueue));
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
    WriteApiCallToFile(call_info, "vkCreateSamplerYcbcrConversion", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pYcbcrConversion", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pYcbcrConversion));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySamplerYcbcrConversion", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateDescriptorUpdateTemplate", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDescriptorUpdateTemplate));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDescriptorUpdateTemplate", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalBufferProperties", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExternalBufferProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalFenceProperties", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalFenceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExternalFenceProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalSemaphoreProperties", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalSemaphoreInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExternalSemaphoreProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    WriteApiCallToFile(call_info, "vkGetDescriptorSetLayoutSupport", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSupport", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSupport, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectCount", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirectCount", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateRenderPass2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRenderPass", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pRenderPass));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBeginRenderPass2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdNextSubpass2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdEndRenderPass2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkResetQueryPool", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetSemaphoreCounterValue", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "pValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pValue, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    WriteApiCallToFile(call_info, "vkWaitSemaphores", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pWaitInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pWaitInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    WriteApiCallToFile(call_info, "vkSignalSemaphore", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pSignalInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSignalInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetBufferDeviceAddress", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, PtrToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetBufferOpaqueCaptureAddress", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, PtrToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetDeviceMemoryOpaqueCaptureAddress", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, PtrToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceToolProperties", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pToolCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pToolCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pToolProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pToolProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreatePrivateDataSlot", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPrivateDataSlot", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPrivateDataSlot));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyPrivateDataSlot", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkSetPrivateData", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, Quote(ToString(objectType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(data, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPrivateData", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, Quote(ToString(objectType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, PointerDecoderToString(pData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetEvent2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdResetEvent2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(stageMask)));
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
    WriteApiCallToFile(call_info, "vkCmdWaitEvents2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdPipelineBarrier2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdWriteTimestamp2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stage", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(stage)));
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
    WriteApiCallToFile(call_info, "vkQueueSubmit2", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "submitCount", toStringFlags, tabCount, tabSize, ToString(submitCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubmits", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSubmits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyBuffer2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyImage2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyBufferToImage2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyImageToBuffer2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBlitImage2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdResolveImage2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBeginRendering", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdEndRendering", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetCullMode", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetFrontFace", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "frontFace", toStringFlags, tabCount, tabSize, Quote(ToString(frontFace, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveTopology", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "primitiveTopology", toStringFlags, tabCount, tabSize, Quote(ToString(primitiveTopology, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewportWithCount", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetScissorWithCount", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBindVertexBuffers2", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetDepthTestEnable", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetDepthWriteEnable", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetDepthCompareOp", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthCompareOp", toStringFlags, tabCount, tabSize, Quote(ToString(depthCompareOp, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthBoundsTestEnable", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetStencilTestEnable", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetStencilOp", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "faceMask", toStringFlags, tabCount, tabSize, ToString(faceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "failOp", toStringFlags, tabCount, tabSize, Quote(ToString(failOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "passOp", toStringFlags, tabCount, tabSize, Quote(ToString(passOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "depthFailOp", toStringFlags, tabCount, tabSize, Quote(ToString(depthFailOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "compareOp", toStringFlags, tabCount, tabSize, Quote(ToString(compareOp, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetRasterizerDiscardEnable", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetDepthBiasEnable", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveRestartEnable", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetDeviceBufferMemoryRequirements", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetDeviceImageMemoryRequirements", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetDeviceImageSparseMemoryRequirements", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySurfaceKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceSupportKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "pSupported", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSupported, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "pSurfaceCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceCapabilities, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceFormatsKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "pSurfaceFormatCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceFormatCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurfaceFormats", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSurfaceFormats, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfacePresentModesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "pPresentModeCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentModeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPresentModes", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(pPresentModeCount, pPresentModes, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateSwapchainKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSwapchain", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSwapchain));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySwapchainKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetSwapchainImagesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "pSwapchainImageCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSwapchainImageCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSwapchainImages", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(pSwapchainImageCount, pSwapchainImages, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkAcquireNextImageKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
            FieldToString(strStrm, false, "pImageIndex", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageIndex, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    WriteApiCallToFile(call_info, "vkQueuePresentKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "pPresentInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetDeviceGroupPresentCapabilitiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pDeviceGroupPresentCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDeviceGroupPresentCapabilities, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    WriteApiCallToFile(call_info, "vkGetDeviceGroupSurfacePresentModesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "pModes", toStringFlags, tabCount, tabSize, PointerDecoderToString(pModes, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDevicePresentRectanglesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "pRectCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRectCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRects", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pRects, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    WriteApiCallToFile(call_info, "vkAcquireNextImage2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAcquireInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAcquireInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageIndex", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageIndex, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayPropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetDisplayPlaneSupportedDisplaysKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "planeIndex", toStringFlags, tabCount, tabSize, ToString(planeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDisplayCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDisplays", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(pDisplayCount, pDisplays, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetDisplayModePropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateDisplayModeKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMode", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pMode));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetDisplayPlaneCapabilitiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, HandleIdToString(mode));
            FieldToString(strStrm, false, "planeIndex", toStringFlags, tabCount, tabSize, ToString(planeIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCapabilities, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateDisplayPlaneSurfaceKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateSharedSwapchainsKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchainCount", toStringFlags, tabCount, tabSize, ToString(swapchainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSwapchains", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(swapchainCount, pSwapchains, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateXlibSurfaceKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceXlibPresentationSupportKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dpy", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dpy));
            FieldToString(strStrm, false, "visualID", toStringFlags, tabCount, tabSize, ToString(visualID, toStringFlags, tabCount, tabSize));
        }, Bool32ToString(returnValue), false
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
    WriteApiCallToFile(call_info, "vkCreateXcbSurfaceKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceXcbPresentationSupportKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "connection", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(connection));
            FieldToString(strStrm, false, "visual_id", toStringFlags, tabCount, tabSize, ToString(visual_id, toStringFlags, tabCount, tabSize));
        }, Bool32ToString(returnValue), false
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
    WriteApiCallToFile(call_info, "vkCreateWaylandSurfaceKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceWaylandPresentationSupportKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(display));
        }, Bool32ToString(returnValue), false
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
    WriteApiCallToFile(call_info, "vkCreateAndroidSurfaceKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateWin32SurfaceKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceWin32PresentationSupportKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
        }, Bool32ToString(returnValue), false
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile,
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceVideoCapabilitiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pVideoProfile", toStringFlags, tabCount, tabSize, PointerDecoderToString(pVideoProfile, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCapabilities, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo,
    PointerDecoder<uint32_t>*                   pVideoFormatPropertyCount,
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceVideoFormatPropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pVideoFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pVideoFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVideoFormatPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pVideoFormatPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVideoFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pVideoFormatProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionKHR>*    pVideoSession)
{
    WriteApiCallToFile(call_info, "vkCreateVideoSessionKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVideoSession", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pVideoSession));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyVideoSessionKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "videoSession", toStringFlags, tabCount, tabSize, HandleIdToString(videoSession));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetVideoSessionMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    PointerDecoder<uint32_t>*                   pMemoryRequirementsCount,
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetVideoSessionMemoryRequirementsKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "videoSession", toStringFlags, tabCount, tabSize, HandleIdToString(videoSession));
            FieldToString(strStrm, false, "pMemoryRequirementsCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirementsCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos)
{
    WriteApiCallToFile(call_info, "vkBindVideoSessionMemoryKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "videoSession", toStringFlags, tabCount, tabSize, HandleIdToString(videoSession));
            FieldToString(strStrm, false, "bindSessionMemoryInfoCount", toStringFlags, tabCount, tabSize, ToString(bindSessionMemoryInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindSessionMemoryInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindSessionMemoryInfos, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters)
{
    WriteApiCallToFile(call_info, "vkCreateVideoSessionParametersKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pVideoSessionParameters", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pVideoSessionParameters));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkUpdateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo)
{
    WriteApiCallToFile(call_info, "vkUpdateVideoSessionParametersKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "videoSessionParameters", toStringFlags, tabCount, tabSize, HandleIdToString(videoSessionParameters));
            FieldToString(strStrm, false, "pUpdateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pUpdateInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyVideoSessionParametersKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "videoSessionParameters", toStringFlags, tabCount, tabSize, HandleIdToString(videoSessionParameters));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBeginVideoCodingKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pBeginInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBeginInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    WriteApiCallToFile(call_info, "vkCmdEndVideoCodingKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pEndCodingInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pEndCodingInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    WriteApiCallToFile(call_info, "vkCmdControlVideoCodingKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pCodingControlInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCodingControlInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    WriteApiCallToFile(call_info, "vkCmdDecodeVideoKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pDecodeInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDecodeInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBeginRenderingKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdEndRenderingKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFeatures2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceProperties2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFormatProperties2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatProperties, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceImageFormatProperties2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pImageFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImageFormatProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pQueueFamilyPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pQueueFamilyPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pQueueFamilyProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pQueueFamilyProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMemoryProperties2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pMemoryProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryProperties, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetDeviceGroupPeerMemoryFeaturesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "heapIndex", toStringFlags, tabCount, tabSize, ToString(heapIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "localDeviceIndex", toStringFlags, tabCount, tabSize, ToString(localDeviceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "remoteDeviceIndex", toStringFlags, tabCount, tabSize, ToString(remoteDeviceIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPeerMemoryFeatures", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPeerMemoryFeatures, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    WriteApiCallToFile(call_info, "vkCmdSetDeviceMaskKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDispatchBaseKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkTrimCommandPoolKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDeviceGroupsKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pPhysicalDeviceGroupCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPhysicalDeviceGroupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPhysicalDeviceGroupProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pPhysicalDeviceGroupProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalBufferPropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalBufferInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExternalBufferProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalBufferProperties, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetMemoryWin32HandleKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetWin32HandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetMemoryWin32HandlePropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "handle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(handle));
            FieldToString(strStrm, false, "pMemoryWin32HandleProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryWin32HandleProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    WriteApiCallToFile(call_info, "vkGetMemoryFdKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetFdInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFd", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFd, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetMemoryFdPropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "fd", toStringFlags, tabCount, tabSize, ToString(fd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryFdProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryFdProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalSemaphoreInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExternalSemaphoreProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalSemaphoreProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    WriteApiCallToFile(call_info, "vkImportSemaphoreWin32HandleKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportSemaphoreWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportSemaphoreWin32HandleInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    WriteApiCallToFile(call_info, "vkGetSemaphoreWin32HandleKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetWin32HandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    WriteApiCallToFile(call_info, "vkImportSemaphoreFdKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportSemaphoreFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportSemaphoreFdInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    WriteApiCallToFile(call_info, "vkGetSemaphoreFdKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetFdInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFd", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFd, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCmdPushDescriptorSetKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, Quote(ToString(pipelineBindPoint, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCreateDescriptorUpdateTemplateKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDescriptorUpdateTemplate", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDescriptorUpdateTemplate));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDescriptorUpdateTemplateKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateRenderPass2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pRenderPass", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pRenderPass));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBeginRenderPass2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdNextSubpass2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdEndRenderPass2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetSwapchainStatusKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalFencePropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pExternalFenceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExternalFenceProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalFenceProperties, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    WriteApiCallToFile(call_info, "vkImportFenceWin32HandleKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportFenceWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportFenceWin32HandleInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    WriteApiCallToFile(call_info, "vkGetFenceWin32HandleKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetWin32HandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetWin32HandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    WriteApiCallToFile(call_info, "vkImportFenceFdKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportFenceFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportFenceFdInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    WriteApiCallToFile(call_info, "vkGetFenceFdKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetFdInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetFdInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFd", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFd, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCounterCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCounterCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCounters", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCounters, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCounterDescriptions", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCounterDescriptions, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pPerformanceQueryCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPerformanceQueryCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pNumPasses", toStringFlags, tabCount, tabSize, PointerDecoderToString(pNumPasses, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    WriteApiCallToFile(call_info, "vkAcquireProfilingLockKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    WriteApiCallToFile(call_info, "vkReleaseProfilingLockKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceCapabilities2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurfaceCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceCapabilities, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceFormats2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurfaceFormatCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceFormatCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurfaceFormats", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSurfaceFormats, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayProperties2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetDisplayModeProperties2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetDisplayPlaneCapabilities2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pDisplayPlaneInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayPlaneInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCapabilities, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetImageMemoryRequirements2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetBufferMemoryRequirements2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetImageSparseMemoryRequirements2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkCreateSamplerYcbcrConversionKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pYcbcrConversion", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pYcbcrConversion));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySamplerYcbcrConversionKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkBindBufferMemory2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfos, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    WriteApiCallToFile(call_info, "vkBindImageMemory2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfos, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    WriteApiCallToFile(call_info, "vkGetDescriptorSetLayoutSupportKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSupport", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSupport, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectCountKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirectCountKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetSemaphoreCounterValueKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "semaphore", toStringFlags, tabCount, tabSize, HandleIdToString(semaphore));
            FieldToString(strStrm, false, "pValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pValue, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    WriteApiCallToFile(call_info, "vkWaitSemaphoresKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pWaitInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pWaitInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    WriteApiCallToFile(call_info, "vkSignalSemaphoreKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pSignalInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSignalInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFragmentShadingRatesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pFragmentShadingRateCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFragmentShadingRateCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFragmentShadingRates", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pFragmentShadingRates, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    WriteApiCallToFile(call_info, "vkCmdSetFragmentShadingRateKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkWaitForPresentKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "presentId", toStringFlags, tabCount, tabSize, ToString(presentId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "timeout", toStringFlags, tabCount, tabSize, ToString(timeout, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetBufferDeviceAddressKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, PtrToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetBufferOpaqueCaptureAddressKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, PtrToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetDeviceMemoryOpaqueCaptureAddressKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, PtrToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    WriteApiCallToFile(call_info, "vkCreateDeferredOperationKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDeferredOperation", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDeferredOperation));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDeferredOperationKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetDeferredOperationMaxConcurrencyKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
        }, ToString(returnValue), false
    );
}

void VulkanAsciiConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    WriteApiCallToFile(call_info, "vkGetDeferredOperationResultKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    WriteApiCallToFile(call_info, "vkDeferredOperationJoinKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "operation", toStringFlags, tabCount, tabSize, HandleIdToString(operation));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPipelineExecutablePropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pPipelineInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPipelineInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExecutableCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExecutableCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPipelineExecutableStatisticsKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pExecutableInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExecutableInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStatisticCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pStatisticCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pStatistics", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pStatistics, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPipelineExecutableInternalRepresentationsKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pExecutableInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExecutableInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInternalRepresentationCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInternalRepresentationCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInternalRepresentations", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pInternalRepresentations, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    WriteApiCallToFile(call_info, "vkCmdEncodeVideoKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pEncodeInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pEncodeInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetEvent2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdResetEvent2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "event", toStringFlags, tabCount, tabSize, HandleIdToString(event));
            FieldToString(strStrm, false, "stageMask", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(stageMask)));
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
    WriteApiCallToFile(call_info, "vkCmdWaitEvents2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdPipelineBarrier2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdWriteTimestamp2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stage", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(stage)));
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
    WriteApiCallToFile(call_info, "vkQueueSubmit2KHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "submitCount", toStringFlags, tabCount, tabSize, ToString(submitCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSubmits", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSubmits, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "fence", toStringFlags, tabCount, tabSize, HandleIdToString(fence));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCmdWriteBufferMarker2AMD", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stage", toStringFlags, tabCount, tabSize, Quote(VkPipelineStageFlags2ToString(stage)));
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
    WriteApiCallToFile(call_info, "vkGetQueueCheckpointData2NV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "pCheckpointDataCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCheckpointDataCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCheckpointData", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCheckpointData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyBuffer2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyImage2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyBufferToImage2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyImageToBuffer2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBlitImage2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdResolveImage2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdTraceRaysIndirect2KHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetDeviceBufferMemoryRequirementsKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetDeviceImageMemoryRequirementsKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetDeviceImageSparseMemoryRequirementsKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSparseMemoryRequirementCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSparseMemoryRequirementCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSparseMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pSparseMemoryRequirements, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkCreateDebugReportCallbackEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCallback", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pCallback));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDebugReportCallbackEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkDebugReportMessageEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, Quote(ToString(objectType, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkDebugMarkerSetObjectTagEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pTagInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pTagInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    WriteApiCallToFile(call_info, "vkDebugMarkerSetObjectNameEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pNameInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pNameInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    WriteApiCallToFile(call_info, "vkCmdDebugMarkerBeginEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDebugMarkerEndEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDebugMarkerInsertEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBindTransformFeedbackBuffersEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBeginTransformFeedbackEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdEndTransformFeedbackEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBeginQueryIndexedEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdEndQueryIndexedEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectByteCountEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetImageViewHandleNVX", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue), false
    );
}

void VulkanAsciiConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetImageViewAddressNVX", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectCountAMD", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirectCountAMD", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetShaderInfoAMD", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "shaderStage", toStringFlags, tabCount, tabSize, Quote(ToString(shaderStage, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "infoType", toStringFlags, tabCount, tabSize, Quote(ToString(infoType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pInfoSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfoSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pInfo));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateStreamDescriptorSurfaceGGP", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "format", toStringFlags, tabCount, tabSize, Quote(ToString(format, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "type", toStringFlags, tabCount, tabSize, Quote(ToString(type, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "tiling", toStringFlags, tabCount, tabSize, Quote(ToString(tiling, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "usage", toStringFlags, tabCount, tabSize, ToString(usage, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "flags", toStringFlags, tabCount, tabSize, ToString(flags, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "externalHandleType", toStringFlags, tabCount, tabSize, ToString(externalHandleType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pExternalImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExternalImageFormatProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetMemoryWin32HandleNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "memory", toStringFlags, tabCount, tabSize, HandleIdToString(memory));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, ToString(handleType, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pHandle", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHandle));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateViSurfaceNN", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    WriteApiCallToFile(call_info, "vkCmdBeginConditionalRenderingEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdEndConditionalRenderingEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetViewportWScalingNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkReleaseDisplayEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    WriteApiCallToFile(call_info, "vkAcquireXlibDisplayEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "dpy", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dpy));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetRandROutputDisplayEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "dpy", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dpy));
            FieldToString(strStrm, false, "rrOutput", toStringFlags, tabCount, tabSize, ToString(rrOutput, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDisplay", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDisplay));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceCapabilities2EXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "surface", toStringFlags, tabCount, tabSize, HandleIdToString(surface));
            FieldToString(strStrm, false, "pSurfaceCapabilities", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceCapabilities, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    WriteApiCallToFile(call_info, "vkDisplayPowerControlEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pDisplayPowerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayPowerInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkRegisterDeviceEventEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pDeviceEventInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDeviceEventInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFence", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFence));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkRegisterDisplayEventEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
            FieldToString(strStrm, false, "pDisplayEventInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayEventInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFence", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pFence));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetSwapchainCounterEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "counter", toStringFlags, tabCount, tabSize, Quote(ToString(counter, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pCounterValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCounterValue, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    WriteApiCallToFile(call_info, "vkGetRefreshCycleDurationGOOGLE", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "pDisplayTimingProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDisplayTimingProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPastPresentationTimingGOOGLE", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
            FieldToString(strStrm, false, "pPresentationTimingCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentationTimingCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPresentationTimings", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pPresentationTimings, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    WriteApiCallToFile(call_info, "vkCmdSetDiscardRectangleEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkSetHdrMetadataEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateIOSSurfaceMVK", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateMacOSSurfaceMVK", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    WriteApiCallToFile(call_info, "vkSetDebugUtilsObjectNameEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pNameInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pNameInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    WriteApiCallToFile(call_info, "vkSetDebugUtilsObjectTagEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pTagInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pTagInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    WriteApiCallToFile(call_info, "vkQueueBeginDebugUtilsLabelEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkQueueEndDebugUtilsLabelEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkQueueInsertDebugUtilsLabelEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBeginDebugUtilsLabelEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdEndDebugUtilsLabelEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdInsertDebugUtilsLabelEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateDebugUtilsMessengerEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMessenger", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pMessenger));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDebugUtilsMessengerEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkSubmitDebugUtilsMessageEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "messageSeverity", toStringFlags, tabCount, tabSize, Quote(ToString(messageSeverity, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkGetAndroidHardwareBufferPropertiesANDROID", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(buffer));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    WriteApiCallToFile(call_info, "vkGetMemoryAndroidHardwareBufferANDROID", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBuffer", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pBuffer));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetSampleLocationsEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMultisamplePropertiesEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, Quote(ToString(samples, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pMultisampleProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMultisampleProperties, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetImageDrmFormatModifierPropertiesEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateValidationCacheEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pValidationCache", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pValidationCache));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyValidationCacheEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkMergeValidationCachesEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "dstCache", toStringFlags, tabCount, tabSize, HandleIdToString(dstCache));
            FieldToString(strStrm, false, "srcCacheCount", toStringFlags, tabCount, tabSize, ToString(srcCacheCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSrcCaches", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(srcCacheCount, pSrcCaches, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetValidationCacheDataEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "validationCache", toStringFlags, tabCount, tabSize, HandleIdToString(validationCache));
            FieldToString(strStrm, false, "pDataSize", toStringFlags, tabCount, tabSize, PointerDecoderToString(pDataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    WriteApiCallToFile(call_info, "vkCmdBindShadingRateImageNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(imageLayout, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdSetViewportShadingRatePaletteNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetCoarseSampleOrderNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "sampleOrderType", toStringFlags, tabCount, tabSize, Quote(ToString(sampleOrderType, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCreateAccelerationStructureNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructure", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pAccelerationStructure));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyAccelerationStructureNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureMemoryRequirementsNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkBindAccelerationStructureMemoryNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "bindInfoCount", toStringFlags, tabCount, tabSize, ToString(bindInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pBindInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pBindInfos, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCmdBuildAccelerationStructureNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyAccelerationStructureNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "dst", toStringFlags, tabCount, tabSize, HandleIdToString(dst));
            FieldToString(strStrm, false, "src", toStringFlags, tabCount, tabSize, HandleIdToString(src));
            FieldToString(strStrm, false, "mode", toStringFlags, tabCount, tabSize, Quote(ToString(mode, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCmdTraceRaysNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateRayTracingPipelinesNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetRayTracingShaderGroupHandlesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "firstGroup", toStringFlags, tabCount, tabSize, ToString(firstGroup, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetRayTracingShaderGroupHandlesNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "firstGroup", toStringFlags, tabCount, tabSize, ToString(firstGroup, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureHandleNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "accelerationStructure", toStringFlags, tabCount, tabSize, HandleIdToString(accelerationStructure));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCmdWriteAccelerationStructuresPropertiesNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "accelerationStructureCount", toStringFlags, tabCount, tabSize, ToString(accelerationStructureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructures", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(accelerationStructureCount, pAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryType", toStringFlags, tabCount, tabSize, Quote(ToString(queryType, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCompileDeferredNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "shader", toStringFlags, tabCount, tabSize, ToString(shader, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetMemoryHostPointerPropertiesEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pHostPointer", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pHostPointer));
            FieldToString(strStrm, false, "pMemoryHostPointerProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryHostPointerProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCmdWriteBufferMarkerAMD", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineStage", toStringFlags, tabCount, tabSize, Quote(ToString(pipelineStage, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pTimeDomainCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pTimeDomainCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTimeDomains", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(pTimeDomainCount, pTimeDomains, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetCalibratedTimestampsEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "timestampCount", toStringFlags, tabCount, tabSize, ToString(timestampCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTimestampInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pTimestampInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pTimestamps", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(timestampCount, pTimestamps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMaxDeviation", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMaxDeviation, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksIndirectNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksIndirectCountNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetExclusiveScissorNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetCheckpointNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetQueueCheckpointDataNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "pCheckpointDataCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCheckpointDataCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCheckpointData", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCheckpointData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    WriteApiCallToFile(call_info, "vkInitializePerformanceApiINTEL", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInitializeInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInitializeInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    WriteApiCallToFile(call_info, "vkUninitializePerformanceApiINTEL", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetPerformanceMarkerINTEL", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pMarkerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMarkerInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetPerformanceStreamMarkerINTEL", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pMarkerInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMarkerInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetPerformanceOverrideINTEL", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pOverrideInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pOverrideInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    WriteApiCallToFile(call_info, "vkAcquirePerformanceConfigurationINTEL", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pAcquireInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAcquireInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pConfiguration", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pConfiguration));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    WriteApiCallToFile(call_info, "vkReleasePerformanceConfigurationINTEL", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "configuration", toStringFlags, tabCount, tabSize, HandleIdToString(configuration));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    WriteApiCallToFile(call_info, "vkQueueSetPerformanceConfigurationINTEL", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "queue", toStringFlags, tabCount, tabSize, HandleIdToString(queue));
            FieldToString(strStrm, false, "configuration", toStringFlags, tabCount, tabSize, HandleIdToString(configuration));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    WriteApiCallToFile(call_info, "vkGetPerformanceParameterINTEL", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "parameter", toStringFlags, tabCount, tabSize, Quote(ToString(parameter, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pValue", toStringFlags, tabCount, tabSize, PointerDecoderToString(pValue, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    WriteApiCallToFile(call_info, "vkSetLocalDimmingAMD", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateImagePipeSurfaceFUCHSIA", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateMetalSurfaceEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetBufferDeviceAddressEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, PtrToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceToolPropertiesEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pToolCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pToolCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pToolProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pToolProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pPropertyCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertyCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pCombinationCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCombinationCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCombinations", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCombinations, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfacePresentModes2EXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPresentModeCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPresentModeCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPresentModes", toStringFlags, tabCount, tabSize, EnumPointerDecoderArrayToString(pPresentModeCount, pPresentModes, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    WriteApiCallToFile(call_info, "vkAcquireFullScreenExclusiveModeEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    WriteApiCallToFile(call_info, "vkReleaseFullScreenExclusiveModeEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "swapchain", toStringFlags, tabCount, tabSize, HandleIdToString(swapchain));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    WriteApiCallToFile(call_info, "vkGetDeviceGroupSurfacePresentModes2EXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pSurfaceInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSurfaceInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pModes", toStringFlags, tabCount, tabSize, PointerDecoderToString(pModes, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateHeadlessSurfaceEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    WriteApiCallToFile(call_info, "vkCmdSetLineStippleEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkResetQueryPoolEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetCullModeEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetFrontFaceEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "frontFace", toStringFlags, tabCount, tabSize, Quote(ToString(frontFace, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveTopologyEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "primitiveTopology", toStringFlags, tabCount, tabSize, Quote(ToString(primitiveTopology, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewportWithCountEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetScissorWithCountEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBindVertexBuffers2EXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetDepthTestEnableEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetDepthWriteEnableEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetDepthCompareOpEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthCompareOp", toStringFlags, tabCount, tabSize, Quote(ToString(depthCompareOp, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthBoundsTestEnableEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetStencilTestEnableEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetStencilOpEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "faceMask", toStringFlags, tabCount, tabSize, ToString(faceMask, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "failOp", toStringFlags, tabCount, tabSize, Quote(ToString(failOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "passOp", toStringFlags, tabCount, tabSize, Quote(ToString(passOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "depthFailOp", toStringFlags, tabCount, tabSize, Quote(ToString(depthFailOp, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "compareOp", toStringFlags, tabCount, tabSize, Quote(ToString(compareOp, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo)
{
    WriteApiCallToFile(call_info, "vkReleaseSwapchainImagesEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pReleaseInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pReleaseInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetGeneratedCommandsMemoryRequirementsNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryRequirements", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryRequirements, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    WriteApiCallToFile(call_info, "vkCmdPreprocessGeneratedCommandsNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdExecuteGeneratedCommandsNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdBindPipelineShaderGroupNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineBindPoint", toStringFlags, tabCount, tabSize, Quote(ToString(pipelineBindPoint, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkCreateIndirectCommandsLayoutNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIndirectCommandsLayout", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pIndirectCommandsLayout));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyIndirectCommandsLayoutNV", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkAcquireDrmDisplayEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "drmFd", toStringFlags, tabCount, tabSize, ToString(drmFd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetDrmDisplayEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "drmFd", toStringFlags, tabCount, tabSize, ToString(drmFd, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "connectorId", toStringFlags, tabCount, tabSize, ToString(connectorId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(display));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreatePrivateDataSlotEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPrivateDataSlot", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pPrivateDataSlot));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyPrivateDataSlotEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkSetPrivateDataEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, Quote(ToString(objectType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "data", toStringFlags, tabCount, tabSize, ToString(data, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetPrivateDataEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "objectType", toStringFlags, tabCount, tabSize, Quote(ToString(objectType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "objectHandle", toStringFlags, tabCount, tabSize, ToString(objectHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "privateDataSlot", toStringFlags, tabCount, tabSize, HandleIdToString(privateDataSlot));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, PointerDecoderToString(pData, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    WriteApiCallToFile(call_info, "vkCmdSetFragmentShadingRateEnumNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "shadingRate", toStringFlags, tabCount, tabSize, Quote(ToString(shadingRate, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkGetImageSubresourceLayout2EXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "image", toStringFlags, tabCount, tabSize, HandleIdToString(image));
            FieldToString(strStrm, false, "pSubresource", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSubresource, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pLayout", toStringFlags, tabCount, tabSize, PointerDecoderToString(pLayout, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts,
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo)
{
    WriteApiCallToFile(call_info, "vkGetDeviceFaultInfoEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pFaultCounts", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFaultCounts, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFaultInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFaultInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    WriteApiCallToFile(call_info, "vkAcquireWinrtDisplayNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "display", toStringFlags, tabCount, tabSize, HandleIdToString(display));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    WriteApiCallToFile(call_info, "vkGetWinrtDisplayNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "deviceRelativeId", toStringFlags, tabCount, tabSize, ToString(deviceRelativeId, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pDisplay", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pDisplay));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateDirectFBSurfaceEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dfb", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(dfb));
        }, Bool32ToString(returnValue), false
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
    WriteApiCallToFile(call_info, "vkCmdSetVertexInputEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetMemoryZirconHandleFUCHSIA", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetZirconHandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetZirconHandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pZirconHandle", toStringFlags, tabCount, tabSize, PointerDecoderToString(pZirconHandle, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetMemoryZirconHandlePropertiesFUCHSIA", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "handleType", toStringFlags, tabCount, tabSize, Quote(ToString(handleType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "zirconHandle", toStringFlags, tabCount, tabSize, ToString(zirconHandle, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMemoryZirconHandleProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryZirconHandleProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    WriteApiCallToFile(call_info, "vkImportSemaphoreZirconHandleFUCHSIA", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pImportSemaphoreZirconHandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pImportSemaphoreZirconHandleInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    WriteApiCallToFile(call_info, "vkGetSemaphoreZirconHandleFUCHSIA", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pGetZirconHandleInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pGetZirconHandleInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pZirconHandle", toStringFlags, tabCount, tabSize, PointerDecoderToString(pZirconHandle, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    WriteApiCallToFile(call_info, "vkCmdBindInvocationMaskHUAWEI", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "imageView", toStringFlags, tabCount, tabSize, HandleIdToString(imageView));
            FieldToString(strStrm, false, "imageLayout", toStringFlags, tabCount, tabSize, Quote(ToString(imageLayout, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkGetMemoryRemoteAddressNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pMemoryGetRemoteAddressInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pMemoryGetRemoteAddressInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAddress", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pAddress));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    WriteApiCallToFile(call_info, "vkCmdSetPatchControlPointsEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetRasterizerDiscardEnableEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetDepthBiasEnableEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdSetLogicOpEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "logicOp", toStringFlags, tabCount, tabSize, Quote(ToString(logicOp, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveRestartEnableEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateScreenSurfaceQNX", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "instance", toStringFlags, tabCount, tabSize, HandleIdToString(instance));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSurface", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSurface));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    window)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceScreenPresentationSupportQNX", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "queueFamilyIndex", toStringFlags, tabCount, tabSize, ToString(queueFamilyIndex, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "window", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(window));
        }, Bool32ToString(returnValue), false
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    WriteApiCallToFile(call_info, "vkCmdSetColorWriteEnableEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawMultiEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdDrawMultiIndexedEXT", [&](std::stringstream& strStrm)
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

void VulkanAsciiConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromap)
{
    WriteApiCallToFile(call_info, "vkCreateMicromapEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMicromap", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pMicromap));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyMicromapEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "micromap", toStringFlags, tabCount, tabSize, HandleIdToString(micromap));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    WriteApiCallToFile(call_info, "vkCmdBuildMicromapsEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "infoCount", toStringFlags, tabCount, tabSize, ToString(infoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pInfos, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    WriteApiCallToFile(call_info, "vkBuildMicromapsEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "infoCount", toStringFlags, tabCount, tabSize, ToString(infoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pInfos, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCopyMicromapEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCopyMicromapToMemoryEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCopyMemoryToMicromapEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    WriteApiCallToFile(call_info, "vkWriteMicromapsPropertiesEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "micromapCount", toStringFlags, tabCount, tabSize, ToString(micromapCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMicromaps", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(micromapCount, pMicromaps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryType", toStringFlags, tabCount, tabSize, Quote(ToString(queryType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyMicromapEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyMicromapToMemoryEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyMemoryToMicromapEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    WriteApiCallToFile(call_info, "vkCmdWriteMicromapsPropertiesEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "micromapCount", toStringFlags, tabCount, tabSize, ToString(micromapCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pMicromaps", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(micromapCount, pMicromaps, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryType", toStringFlags, tabCount, tabSize, Quote(ToString(queryType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "queryPool", toStringFlags, tabCount, tabSize, HandleIdToString(queryPool));
            FieldToString(strStrm, false, "firstQuery", toStringFlags, tabCount, tabSize, ToString(firstQuery, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    WriteApiCallToFile(call_info, "vkGetDeviceMicromapCompatibilityEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pVersionInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pVersionInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCompatibility", toStringFlags, tabCount, tabSize, EnumPointerDecoderToString(pCompatibility));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetMicromapBuildSizesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo,
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo)
{
    WriteApiCallToFile(call_info, "vkGetMicromapBuildSizesEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "buildType", toStringFlags, tabCount, tabSize, Quote(ToString(buildType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pBuildInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBuildInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSizeInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pSizeInfo, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    WriteApiCallToFile(call_info, "vkCmdDrawClusterHUAWEI", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "groupCountX", toStringFlags, tabCount, tabSize, ToString(groupCountX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountY", toStringFlags, tabCount, tabSize, ToString(groupCountY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountZ", toStringFlags, tabCount, tabSize, ToString(groupCountZ, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    WriteApiCallToFile(call_info, "vkCmdDrawClusterIndirectHUAWEI", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    WriteApiCallToFile(call_info, "vkSetDeviceMemoryPriorityEXT", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetDescriptorSetLayoutHostMappingInfoVALVE", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pBindingReference", toStringFlags, tabCount, tabSize, PointerDecoderToString(pBindingReference, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pHostMapping", toStringFlags, tabCount, tabSize, PointerDecoderToString(pHostMapping, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    WriteApiCallToFile(call_info, "vkGetDescriptorSetHostMappingVALVE", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "descriptorSet", toStringFlags, tabCount, tabSize, HandleIdToString(descriptorSet));
            FieldToString(strStrm, false, "ppData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(ppData));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    WriteApiCallToFile(call_info, "vkCmdSetTessellationDomainOriginEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "domainOrigin", toStringFlags, tabCount, tabSize, Quote(ToString(domainOrigin, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthClampEnableEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthClampEnable", toStringFlags, tabCount, tabSize, ToString(depthClampEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetPolygonModeEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "polygonMode", toStringFlags, tabCount, tabSize, Quote(ToString(polygonMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    WriteApiCallToFile(call_info, "vkCmdSetRasterizationSamplesEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "rasterizationSamples", toStringFlags, tabCount, tabSize, Quote(ToString(rasterizationSamples, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    WriteApiCallToFile(call_info, "vkCmdSetSampleMaskEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "samples", toStringFlags, tabCount, tabSize, Quote(ToString(samples, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "pSampleMask", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString((samples + 31) / 32, pSampleMask, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetAlphaToCoverageEnableEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "alphaToCoverageEnable", toStringFlags, tabCount, tabSize, ToString(alphaToCoverageEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetAlphaToOneEnableEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "alphaToOneEnable", toStringFlags, tabCount, tabSize, ToString(alphaToOneEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetLogicOpEnableEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "logicOpEnable", toStringFlags, tabCount, tabSize, ToString(logicOpEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorBlendEnables)
{
    WriteApiCallToFile(call_info, "vkCmdSetColorBlendEnableEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstAttachment", toStringFlags, tabCount, tabSize, ToString(firstAttachment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorBlendEnables", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(attachmentCount, pColorBlendEnables, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations)
{
    WriteApiCallToFile(call_info, "vkCmdSetColorBlendEquationEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstAttachment", toStringFlags, tabCount, tabSize, ToString(firstAttachment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorBlendEquations", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pColorBlendEquations, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks)
{
    WriteApiCallToFile(call_info, "vkCmdSetColorWriteMaskEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstAttachment", toStringFlags, tabCount, tabSize, ToString(firstAttachment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorWriteMasks", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(attachmentCount, pColorWriteMasks, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    WriteApiCallToFile(call_info, "vkCmdSetRasterizationStreamEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "rasterizationStream", toStringFlags, tabCount, tabSize, ToString(rasterizationStream, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetConservativeRasterizationModeEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "conservativeRasterizationMode", toStringFlags, tabCount, tabSize, Quote(ToString(conservativeRasterizationMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    WriteApiCallToFile(call_info, "vkCmdSetExtraPrimitiveOverestimationSizeEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "extraPrimitiveOverestimationSize", toStringFlags, tabCount, tabSize, ToString(extraPrimitiveOverestimationSize, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthClipEnableEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "depthClipEnable", toStringFlags, tabCount, tabSize, ToString(depthClipEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetSampleLocationsEnableEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "sampleLocationsEnable", toStringFlags, tabCount, tabSize, ToString(sampleLocationsEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced)
{
    WriteApiCallToFile(call_info, "vkCmdSetColorBlendAdvancedEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstAttachment", toStringFlags, tabCount, tabSize, ToString(firstAttachment, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "attachmentCount", toStringFlags, tabCount, tabSize, ToString(attachmentCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pColorBlendAdvanced", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pColorBlendAdvanced, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetProvokingVertexModeEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "provokingVertexMode", toStringFlags, tabCount, tabSize, Quote(ToString(provokingVertexMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetLineRasterizationModeEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "lineRasterizationMode", toStringFlags, tabCount, tabSize, Quote(ToString(lineRasterizationMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetLineStippleEnableEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "stippledLineEnable", toStringFlags, tabCount, tabSize, ToString(stippledLineEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthClipNegativeOneToOneEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "negativeOneToOne", toStringFlags, tabCount, tabSize, ToString(negativeOneToOne, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewportWScalingEnableNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "viewportWScalingEnable", toStringFlags, tabCount, tabSize, ToString(viewportWScalingEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewportSwizzleNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "firstViewport", toStringFlags, tabCount, tabSize, ToString(firstViewport, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "viewportCount", toStringFlags, tabCount, tabSize, ToString(viewportCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pViewportSwizzles", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pViewportSwizzles, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageToColorEnableNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "coverageToColorEnable", toStringFlags, tabCount, tabSize, ToString(coverageToColorEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageToColorLocationNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "coverageToColorLocation", toStringFlags, tabCount, tabSize, ToString(coverageToColorLocation, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageModulationModeNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "coverageModulationMode", toStringFlags, tabCount, tabSize, Quote(ToString(coverageModulationMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageModulationTableEnableNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "coverageModulationTableEnable", toStringFlags, tabCount, tabSize, ToString(coverageModulationTableEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageModulationTableNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "coverageModulationTableCount", toStringFlags, tabCount, tabSize, ToString(coverageModulationTableCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCoverageModulationTable", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(coverageModulationTableCount, pCoverageModulationTable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetShadingRateImageEnableNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "shadingRateImageEnable", toStringFlags, tabCount, tabSize, ToString(shadingRateImageEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetRepresentativeFragmentTestEnableNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "representativeFragmentTestEnable", toStringFlags, tabCount, tabSize, ToString(representativeFragmentTestEnable, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageReductionModeNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "coverageReductionMode", toStringFlags, tabCount, tabSize, Quote(ToString(coverageReductionMode, toStringFlags, tabCount, tabSize)));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    WriteApiCallToFile(call_info, "vkGetShaderModuleIdentifierEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "shaderModule", toStringFlags, tabCount, tabSize, HandleIdToString(shaderModule));
            FieldToString(strStrm, false, "pIdentifier", toStringFlags, tabCount, tabSize, PointerDecoderToString(pIdentifier, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    WriteApiCallToFile(call_info, "vkGetShaderModuleCreateInfoIdentifierEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pIdentifier", toStringFlags, tabCount, tabSize, PointerDecoderToString(pIdentifier, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo,
    PointerDecoder<uint32_t>*                   pFormatCount,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "physicalDevice", toStringFlags, tabCount, tabSize, HandleIdToString(physicalDevice));
            FieldToString(strStrm, false, "pOpticalFlowImageFormatInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pOpticalFlowImageFormatInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pFormatCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pFormatCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pImageFormatProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pImageFormatProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession)
{
    WriteApiCallToFile(call_info, "vkCreateOpticalFlowSessionNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pSession", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pSession));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyOpticalFlowSessionNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "session", toStringFlags, tabCount, tabSize, HandleIdToString(session));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            session,
    VkOpticalFlowSessionBindingPointNV          bindingPoint,
    format::HandleId                            view,
    VkImageLayout                               layout)
{
    WriteApiCallToFile(call_info, "vkBindOpticalFlowSessionImageNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "session", toStringFlags, tabCount, tabSize, HandleIdToString(session));
            FieldToString(strStrm, false, "bindingPoint", toStringFlags, tabCount, tabSize, Quote(ToString(bindingPoint, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "view", toStringFlags, tabCount, tabSize, HandleIdToString(view));
            FieldToString(strStrm, false, "layout", toStringFlags, tabCount, tabSize, Quote(ToString(layout, toStringFlags, tabCount, tabSize)));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    WriteApiCallToFile(call_info, "vkCmdOpticalFlowExecuteNV", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "session", toStringFlags, tabCount, tabSize, HandleIdToString(session));
            FieldToString(strStrm, false, "pExecuteInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pExecuteInfo, toStringFlags, tabCount, tabSize));
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
    WriteApiCallToFile(call_info, "vkGetFramebufferTilePropertiesQCOM", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "framebuffer", toStringFlags, tabCount, tabSize, HandleIdToString(framebuffer));
            FieldToString(strStrm, false, "pPropertiesCount", toStringFlags, tabCount, tabSize, PointerDecoderToString(pPropertiesCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetDynamicRenderingTilePropertiesQCOM", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pRenderingInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pRenderingInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pProperties", toStringFlags, tabCount, tabSize, PointerDecoderToString(pProperties, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCreateAccelerationStructureKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pCreateInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pCreateInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructure", toStringFlags, tabCount, tabSize, HandlePointerDecoderToString(pAccelerationStructure));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyAccelerationStructureKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCopyAccelerationStructureToMemoryKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCopyMemoryToAccelerationStructureKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkWriteAccelerationStructuresPropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "accelerationStructureCount", toStringFlags, tabCount, tabSize, ToString(accelerationStructureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructures", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(accelerationStructureCount, pAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryType", toStringFlags, tabCount, tabSize, Quote(ToString(queryType, toStringFlags, tabCount, tabSize)));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
    );
}

void VulkanAsciiConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyAccelerationStructureKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyAccelerationStructureToMemoryKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCmdCopyMemoryToAccelerationStructureKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureDeviceAddressKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pInfo, toStringFlags, tabCount, tabSize));
        }, PtrToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCmdWriteAccelerationStructuresPropertiesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "accelerationStructureCount", toStringFlags, tabCount, tabSize, ToString(accelerationStructureCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAccelerationStructures", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(accelerationStructureCount, pAccelerationStructures, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "queryType", toStringFlags, tabCount, tabSize, Quote(ToString(queryType, toStringFlags, tabCount, tabSize)));
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
    WriteApiCallToFile(call_info, "vkGetDeviceAccelerationStructureCompatibilityKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pVersionInfo", toStringFlags, tabCount, tabSize, PointerDecoderToString(pVersionInfo, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCompatibility", toStringFlags, tabCount, tabSize, EnumPointerDecoderToString(pCompatibility));
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
    WriteApiCallToFile(call_info, "vkCmdTraceRaysKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkCreateRayTracingPipelinesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "deferredOperation", toStringFlags, tabCount, tabSize, HandleIdToString(deferredOperation));
            FieldToString(strStrm, false, "pipelineCache", toStringFlags, tabCount, tabSize, HandleIdToString(pipelineCache));
            FieldToString(strStrm, false, "createInfoCount", toStringFlags, tabCount, tabSize, ToString(createInfoCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pCreateInfos", toStringFlags, tabCount, tabSize, PointerDecoderArrayToString(*pCreateInfos, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pAllocator", toStringFlags, tabCount, tabSize, PointerDecoderToString(pAllocator, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pPipelines", toStringFlags, tabCount, tabSize, HandlePointerDecoderArrayToString(createInfoCount, pPipelines, toStringFlags, tabCount, tabSize));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "firstGroup", toStringFlags, tabCount, tabSize, ToString(firstGroup, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCount", toStringFlags, tabCount, tabSize, ToString(groupCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "dataSize", toStringFlags, tabCount, tabSize, ToString(dataSize, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "pData", toStringFlags, tabCount, tabSize, DataPointerDecoderToString(pData));
        }, ToString(returnValue)
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
    WriteApiCallToFile(call_info, "vkCmdTraceRaysIndirectKHR", [&](std::stringstream& strStrm)
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
    WriteApiCallToFile(call_info, "vkGetRayTracingShaderGroupStackSizeKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "device", toStringFlags, tabCount, tabSize, HandleIdToString(device));
            FieldToString(strStrm, false, "pipeline", toStringFlags, tabCount, tabSize, HandleIdToString(pipeline));
            FieldToString(strStrm, false, "group", toStringFlags, tabCount, tabSize, ToString(group, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupShader", toStringFlags, tabCount, tabSize, Quote(ToString(groupShader, toStringFlags, tabCount, tabSize)));
        }, ToString(returnValue), false
    );
}

void VulkanAsciiConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    WriteApiCallToFile(call_info, "vkCmdSetRayTracingPipelineStackSizeKHR", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "pipelineStackSize", toStringFlags, tabCount, tabSize, ToString(pipelineStackSize, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "groupCountX", toStringFlags, tabCount, tabSize, ToString(groupCountX, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountY", toStringFlags, tabCount, tabSize, ToString(groupCountY, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "groupCountZ", toStringFlags, tabCount, tabSize, ToString(groupCountZ, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksIndirectEXT", [&](std::stringstream& strStrm)
        {
            FieldToString(strStrm, true, "commandBuffer", toStringFlags, tabCount, tabSize, HandleIdToString(commandBuffer));
            FieldToString(strStrm, false, "buffer", toStringFlags, tabCount, tabSize, HandleIdToString(buffer));
            FieldToString(strStrm, false, "offset", toStringFlags, tabCount, tabSize, ToString(offset, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "drawCount", toStringFlags, tabCount, tabSize, ToString(drawCount, toStringFlags, tabCount, tabSize));
            FieldToString(strStrm, false, "stride", toStringFlags, tabCount, tabSize, ToString(stride, toStringFlags, tabCount, tabSize));
        }
    );
}

void VulkanAsciiConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksIndirectCountEXT", [&](std::stringstream& strStrm)
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
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
