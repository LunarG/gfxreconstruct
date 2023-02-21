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

#include "util/defines.h"
#include "generated/generated_vulkan_export_json_consumer.h"
#include "decode/custom_vulkan_struct_to_json.h"
#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanExportJsonConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    WriteApiCallToFile(call_info, "vkCreateInstance",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pInstance"], pInstance, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyInstance",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDevices",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pPhysicalDeviceCount"], pPhysicalDeviceCount, json_options_);
            FieldToJson(parameters["pPhysicalDevices"], pPhysicalDevices, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFeatures",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pFeatures"], pFeatures, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFormatProperties",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["format"], format, json_options_);
            FieldToJson(parameters["pFormatProperties"], pFormatProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceImageFormatProperties",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["format"], format, json_options_);
            FieldToJson(parameters["type"], type, json_options_);
            FieldToJson(parameters["tiling"], tiling, json_options_);
            FieldToJson(VkImageUsageFlags_t(), parameters["usage"], usage, json_options_);
            FieldToJson(VkImageCreateFlags_t(), parameters["flags"], flags, json_options_);
            FieldToJson(parameters["pImageFormatProperties"], pImageFormatProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceProperties",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyProperties",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount, json_options_);
            FieldToJson(parameters["pQueueFamilyProperties"], pQueueFamilyProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMemoryProperties",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pMemoryProperties"], pMemoryProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    WriteApiCallToFile(call_info, "vkCreateDevice",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pDevice"], pDevice, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDevice",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    WriteApiCallToFile(call_info, "vkGetDeviceQueue",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["queueFamilyIndex"], queueFamilyIndex, json_options_);
            FieldToJson(parameters["queueIndex"], queueIndex, json_options_);
            FieldToJson(parameters["pQueue"], pQueue, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkQueueSubmit(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
    format::HandleId                            fence)
{
    WriteApiCallToFile(call_info, "vkQueueSubmit",
        [&](auto& jdata)
        {
            FieldToJson(jdata["submit_index"], ++submit_index_, json_options_);
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            FieldToJson(parameters["submitCount"], submitCount, json_options_);
            FieldToJson(parameters["pSubmits"], pSubmits, json_options_);
            FieldToJson(parameters["fence"], to_hex(fence), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    WriteApiCallToFile(call_info, "vkQueueWaitIdle",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    WriteApiCallToFile(call_info, "vkDeviceWaitIdle",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    WriteApiCallToFile(call_info, "vkAllocateMemory",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pAllocateInfo"], pAllocateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pMemory"], pMemory, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkFreeMemory",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["memory"], to_hex(memory), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkMapMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    WriteApiCallToFile(call_info, "vkMapMemory",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["memory"], to_hex(memory), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["size"], size, json_options_);
            FieldToJson(VkMemoryMapFlags_t(), parameters["flags"], flags, json_options_);
            FieldToJson(parameters["ppData"], ppData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    WriteApiCallToFile(call_info, "vkUnmapMemory",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["memory"], to_hex(memory), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    WriteApiCallToFile(call_info, "vkFlushMappedMemoryRanges",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["memoryRangeCount"], memoryRangeCount, json_options_);
            FieldToJson(parameters["pMemoryRanges"], pMemoryRanges, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    WriteApiCallToFile(call_info, "vkInvalidateMappedMemoryRanges",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["memoryRangeCount"], memoryRangeCount, json_options_);
            FieldToJson(parameters["pMemoryRanges"], pMemoryRanges, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    WriteApiCallToFile(call_info, "vkGetDeviceMemoryCommitment",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["memory"], to_hex(memory), json_options_);
            FieldToJson(parameters["pCommittedMemoryInBytes"], pCommittedMemoryInBytes, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    WriteApiCallToFile(call_info, "vkBindBufferMemory",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["memory"], to_hex(memory), json_options_);
            FieldToJson(parameters["memoryOffset"], memoryOffset, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    WriteApiCallToFile(call_info, "vkBindImageMemory",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["image"], to_hex(image), json_options_);
            FieldToJson(parameters["memory"], to_hex(memory), json_options_);
            FieldToJson(parameters["memoryOffset"], memoryOffset, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetBufferMemoryRequirements",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetImageMemoryRequirements",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["image"], to_hex(image), json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetImageSparseMemoryRequirements",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["image"], to_hex(image), json_options_);
            FieldToJson(parameters["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options_);
            FieldToJson(parameters["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["format"], format, json_options_);
            FieldToJson(parameters["type"], type, json_options_);
            FieldToJson(parameters["samples"], samples, json_options_);
            FieldToJson(VkImageUsageFlags_t(), parameters["usage"], usage, json_options_);
            FieldToJson(parameters["tiling"], tiling, json_options_);
            FieldToJson(parameters["pPropertyCount"], pPropertyCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    WriteApiCallToFile(call_info, "vkQueueBindSparse",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            FieldToJson(parameters["bindInfoCount"], bindInfoCount, json_options_);
            FieldToJson(parameters["pBindInfo"], pBindInfo, json_options_);
            FieldToJson(parameters["fence"], to_hex(fence), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    WriteApiCallToFile(call_info, "vkCreateFence",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pFence"], pFence, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyFence",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["fence"], to_hex(fence), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    WriteApiCallToFile(call_info, "vkResetFences",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["fenceCount"], fenceCount, json_options_);
            FieldToJson(parameters["pFences"], pFences, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    WriteApiCallToFile(call_info, "vkGetFenceStatus",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["fence"], to_hex(fence), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkWaitForFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    WriteApiCallToFile(call_info, "vkWaitForFences",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["fenceCount"], fenceCount, json_options_);
            FieldToJson(parameters["pFences"], pFences, json_options_);
            FieldToJson(parameters["waitAll"], waitAll, json_options_);
            FieldToJson(parameters["timeout"], timeout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    WriteApiCallToFile(call_info, "vkCreateSemaphore",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSemaphore"], pSemaphore, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySemaphore",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["semaphore"], to_hex(semaphore), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    WriteApiCallToFile(call_info, "vkCreateEvent",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pEvent"], pEvent, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyEvent",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["event"], to_hex(event), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    WriteApiCallToFile(call_info, "vkGetEventStatus",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["event"], to_hex(event), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    WriteApiCallToFile(call_info, "vkSetEvent",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["event"], to_hex(event), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    WriteApiCallToFile(call_info, "vkResetEvent",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["event"], to_hex(event), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    WriteApiCallToFile(call_info, "vkCreateQueryPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pQueryPool"], pQueryPool, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyQueryPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetQueryPoolResults(
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
    WriteApiCallToFile(call_info, "vkGetQueryPoolResults",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["firstQuery"], firstQuery, json_options_);
            FieldToJson(parameters["queryCount"], queryCount, json_options_);
            FieldToJson(parameters["dataSize"], dataSize, json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            FieldToJson(VkQueryResultFlags_t(), parameters["flags"], flags, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    WriteApiCallToFile(call_info, "vkCreateBuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pBuffer"], pBuffer, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyBuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    WriteApiCallToFile(call_info, "vkCreateBufferView",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pView"], pView, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyBufferView",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["bufferView"], to_hex(bufferView), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    WriteApiCallToFile(call_info, "vkCreateImage",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pImage"], pImage, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyImage",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["image"], to_hex(image), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    WriteApiCallToFile(call_info, "vkGetImageSubresourceLayout",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["image"], to_hex(image), json_options_);
            FieldToJson(parameters["pSubresource"], pSubresource, json_options_);
            FieldToJson(parameters["pLayout"], pLayout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    WriteApiCallToFile(call_info, "vkCreateImageView",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pView"], pView, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyImageView",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["imageView"], to_hex(imageView), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyShaderModule",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["shaderModule"], to_hex(shaderModule), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyPipelineCache",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipelineCache"], to_hex(pipelineCache), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    WriteApiCallToFile(call_info, "vkMergePipelineCaches",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["dstCache"], to_hex(dstCache), json_options_);
            FieldToJson(parameters["srcCacheCount"], srcCacheCount, json_options_);
            FieldToJson(parameters["pSrcCaches"], pSrcCaches, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    WriteApiCallToFile(call_info, "vkCreateGraphicsPipelines",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipelineCache"], to_hex(pipelineCache), json_options_);
            FieldToJson(parameters["createInfoCount"], createInfoCount, json_options_);
            FieldToJson(parameters["pCreateInfos"], pCreateInfos, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pPipelines"], pPipelines, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    WriteApiCallToFile(call_info, "vkCreateComputePipelines",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipelineCache"], to_hex(pipelineCache), json_options_);
            FieldToJson(parameters["createInfoCount"], createInfoCount, json_options_);
            FieldToJson(parameters["pCreateInfos"], pCreateInfos, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pPipelines"], pPipelines, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyPipeline",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipeline"], to_hex(pipeline), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    WriteApiCallToFile(call_info, "vkCreatePipelineLayout",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pPipelineLayout"], pPipelineLayout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyPipelineLayout",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipelineLayout"], to_hex(pipelineLayout), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    WriteApiCallToFile(call_info, "vkCreateSampler",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSampler"], pSampler, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySampler",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["sampler"], to_hex(sampler), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    WriteApiCallToFile(call_info, "vkCreateDescriptorSetLayout",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSetLayout"], pSetLayout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDescriptorSetLayout",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["descriptorSetLayout"], to_hex(descriptorSetLayout), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    WriteApiCallToFile(call_info, "vkCreateDescriptorPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pDescriptorPool"], pDescriptorPool, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDescriptorPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["descriptorPool"], to_hex(descriptorPool), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    WriteApiCallToFile(call_info, "vkResetDescriptorPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["descriptorPool"], to_hex(descriptorPool), json_options_);
            FieldToJson(VkDescriptorPoolResetFlags_t(), parameters["flags"], flags, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    WriteApiCallToFile(call_info, "vkAllocateDescriptorSets",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pAllocateInfo"], pAllocateInfo, json_options_);
            FieldToJson(parameters["pDescriptorSets"], pDescriptorSets, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    WriteApiCallToFile(call_info, "vkFreeDescriptorSets",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["descriptorPool"], to_hex(descriptorPool), json_options_);
            FieldToJson(parameters["descriptorSetCount"], descriptorSetCount, json_options_);
            FieldToJson(parameters["pDescriptorSets"], pDescriptorSets, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies)
{
    WriteApiCallToFile(call_info, "vkUpdateDescriptorSets",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["descriptorWriteCount"], descriptorWriteCount, json_options_);
            FieldToJson(parameters["pDescriptorWrites"], pDescriptorWrites, json_options_);
            FieldToJson(parameters["descriptorCopyCount"], descriptorCopyCount, json_options_);
            FieldToJson(parameters["pDescriptorCopies"], pDescriptorCopies, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    WriteApiCallToFile(call_info, "vkCreateFramebuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pFramebuffer"], pFramebuffer, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyFramebuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["framebuffer"], to_hex(framebuffer), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    WriteApiCallToFile(call_info, "vkCreateRenderPass",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pRenderPass"], pRenderPass, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyRenderPass",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["renderPass"], to_hex(renderPass), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    WriteApiCallToFile(call_info, "vkGetRenderAreaGranularity",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["renderPass"], to_hex(renderPass), json_options_);
            FieldToJson(parameters["pGranularity"], pGranularity, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    WriteApiCallToFile(call_info, "vkCreateCommandPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pCommandPool"], pCommandPool, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyCommandPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["commandPool"], to_hex(commandPool), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    WriteApiCallToFile(call_info, "vkResetCommandPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["commandPool"], to_hex(commandPool), json_options_);
            FieldToJson(VkCommandPoolResetFlags_t(), parameters["flags"], flags, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    WriteApiCallToFile(call_info, "vkAllocateCommandBuffers",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pAllocateInfo"], pAllocateInfo, json_options_);
            FieldToJson(parameters["pCommandBuffers"], pCommandBuffers, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    WriteApiCallToFile(call_info, "vkFreeCommandBuffers",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["commandPool"], to_hex(commandPool), json_options_);
            FieldToJson(parameters["commandBufferCount"], commandBufferCount, json_options_);
            FieldToJson(parameters["pCommandBuffers"], pCommandBuffers, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    WriteApiCallToFile(call_info, "vkBeginCommandBuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pBeginInfo"], pBeginInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    WriteApiCallToFile(call_info, "vkEndCommandBuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    WriteApiCallToFile(call_info, "vkResetCommandBuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkCommandBufferResetFlags_t(), parameters["flags"], flags, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    WriteApiCallToFile(call_info, "vkCmdBindPipeline",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pipelineBindPoint"], pipelineBindPoint, json_options_);
            FieldToJson(parameters["pipeline"], to_hex(pipeline), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewport",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstViewport"], firstViewport, json_options_);
            FieldToJson(parameters["viewportCount"], viewportCount, json_options_);
            FieldToJson(parameters["pViewports"], pViewports, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    WriteApiCallToFile(call_info, "vkCmdSetScissor",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstScissor"], firstScissor, json_options_);
            FieldToJson(parameters["scissorCount"], scissorCount, json_options_);
            FieldToJson(parameters["pScissors"], pScissors, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    WriteApiCallToFile(call_info, "vkCmdSetLineWidth",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["lineWidth"], lineWidth, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthBias",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthBiasConstantFactor"], depthBiasConstantFactor, json_options_);
            FieldToJson(parameters["depthBiasClamp"], depthBiasClamp, json_options_);
            FieldToJson(parameters["depthBiasSlopeFactor"], depthBiasSlopeFactor, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    WriteApiCallToFile(call_info, "vkCmdSetBlendConstants",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["blendConstants"], blendConstants, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthBounds",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["minDepthBounds"], minDepthBounds, json_options_);
            FieldToJson(parameters["maxDepthBounds"], maxDepthBounds, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    WriteApiCallToFile(call_info, "vkCmdSetStencilCompareMask",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkStencilFaceFlags_t(), parameters["faceMask"], faceMask, json_options_);
            FieldToJson(parameters["compareMask"], compareMask, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    WriteApiCallToFile(call_info, "vkCmdSetStencilWriteMask",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkStencilFaceFlags_t(), parameters["faceMask"], faceMask, json_options_);
            FieldToJson(parameters["writeMask"], writeMask, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    WriteApiCallToFile(call_info, "vkCmdSetStencilReference",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkStencilFaceFlags_t(), parameters["faceMask"], faceMask, json_options_);
            FieldToJson(parameters["reference"], reference, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorSets(
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
    WriteApiCallToFile(call_info, "vkCmdBindDescriptorSets",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pipelineBindPoint"], pipelineBindPoint, json_options_);
            FieldToJson(parameters["layout"], to_hex(layout), json_options_);
            FieldToJson(parameters["firstSet"], firstSet, json_options_);
            FieldToJson(parameters["descriptorSetCount"], descriptorSetCount, json_options_);
            FieldToJson(parameters["pDescriptorSets"], pDescriptorSets, json_options_);
            FieldToJson(parameters["dynamicOffsetCount"], dynamicOffsetCount, json_options_);
            FieldToJson(parameters["pDynamicOffsets"], pDynamicOffsets, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    WriteApiCallToFile(call_info, "vkCmdBindIndexBuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["indexType"], indexType, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    WriteApiCallToFile(call_info, "vkCmdBindVertexBuffers",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstBinding"], firstBinding, json_options_);
            FieldToJson(parameters["bindingCount"], bindingCount, json_options_);
            FieldToJson(parameters["pBuffers"], pBuffers, json_options_);
            FieldToJson(parameters["pOffsets"], pOffsets, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    WriteApiCallToFile(call_info, "vkCmdDraw",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["vertexCount"], vertexCount, json_options_);
            FieldToJson(parameters["instanceCount"], instanceCount, json_options_);
            FieldToJson(parameters["firstVertex"], firstVertex, json_options_);
            FieldToJson(parameters["firstInstance"], firstInstance, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    WriteApiCallToFile(call_info, "vkCmdDrawIndexed",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["indexCount"], indexCount, json_options_);
            FieldToJson(parameters["instanceCount"], instanceCount, json_options_);
            FieldToJson(parameters["firstIndex"], firstIndex, json_options_);
            FieldToJson(parameters["vertexOffset"], vertexOffset, json_options_);
            FieldToJson(parameters["firstInstance"], firstInstance, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawIndirect",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["drawCount"], drawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirect",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["drawCount"], drawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    WriteApiCallToFile(call_info, "vkCmdDispatch",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["groupCountX"], groupCountX, json_options_);
            FieldToJson(parameters["groupCountY"], groupCountY, json_options_);
            FieldToJson(parameters["groupCountZ"], groupCountZ, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    WriteApiCallToFile(call_info, "vkCmdDispatchIndirect",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    WriteApiCallToFile(call_info, "vkCmdCopyBuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["srcBuffer"], to_hex(srcBuffer), json_options_);
            FieldToJson(parameters["dstBuffer"], to_hex(dstBuffer), json_options_);
            FieldToJson(parameters["regionCount"], regionCount, json_options_);
            FieldToJson(parameters["pRegions"], pRegions, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions)
{
    WriteApiCallToFile(call_info, "vkCmdCopyImage",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["srcImage"], to_hex(srcImage), json_options_);
            FieldToJson(parameters["srcImageLayout"], srcImageLayout, json_options_);
            FieldToJson(parameters["dstImage"], to_hex(dstImage), json_options_);
            FieldToJson(parameters["dstImageLayout"], dstImageLayout, json_options_);
            FieldToJson(parameters["regionCount"], regionCount, json_options_);
            FieldToJson(parameters["pRegions"], pRegions, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage(
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
    WriteApiCallToFile(call_info, "vkCmdBlitImage",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["srcImage"], to_hex(srcImage), json_options_);
            FieldToJson(parameters["srcImageLayout"], srcImageLayout, json_options_);
            FieldToJson(parameters["dstImage"], to_hex(dstImage), json_options_);
            FieldToJson(parameters["dstImageLayout"], dstImageLayout, json_options_);
            FieldToJson(parameters["regionCount"], regionCount, json_options_);
            FieldToJson(parameters["pRegions"], pRegions, json_options_);
            FieldToJson(parameters["filter"], filter, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    WriteApiCallToFile(call_info, "vkCmdCopyBufferToImage",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["srcBuffer"], to_hex(srcBuffer), json_options_);
            FieldToJson(parameters["dstImage"], to_hex(dstImage), json_options_);
            FieldToJson(parameters["dstImageLayout"], dstImageLayout, json_options_);
            FieldToJson(parameters["regionCount"], regionCount, json_options_);
            FieldToJson(parameters["pRegions"], pRegions, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    WriteApiCallToFile(call_info, "vkCmdCopyImageToBuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["srcImage"], to_hex(srcImage), json_options_);
            FieldToJson(parameters["srcImageLayout"], srcImageLayout, json_options_);
            FieldToJson(parameters["dstBuffer"], to_hex(dstBuffer), json_options_);
            FieldToJson(parameters["regionCount"], regionCount, json_options_);
            FieldToJson(parameters["pRegions"], pRegions, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    WriteApiCallToFile(call_info, "vkCmdUpdateBuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["dstBuffer"], to_hex(dstBuffer), json_options_);
            FieldToJson(parameters["dstOffset"], dstOffset, json_options_);
            FieldToJson(parameters["dataSize"], dataSize, json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    WriteApiCallToFile(call_info, "vkCmdFillBuffer",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["dstBuffer"], to_hex(dstBuffer), json_options_);
            FieldToJson(parameters["dstOffset"], dstOffset, json_options_);
            FieldToJson(parameters["size"], size, json_options_);
            FieldToJson(parameters["data"], data, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    WriteApiCallToFile(call_info, "vkCmdClearColorImage",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["image"], to_hex(image), json_options_);
            FieldToJson(parameters["imageLayout"], imageLayout, json_options_);
            FieldToJson(parameters["pColor"], pColor, json_options_);
            FieldToJson(parameters["rangeCount"], rangeCount, json_options_);
            FieldToJson(parameters["pRanges"], pRanges, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    WriteApiCallToFile(call_info, "vkCmdClearDepthStencilImage",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["image"], to_hex(image), json_options_);
            FieldToJson(parameters["imageLayout"], imageLayout, json_options_);
            FieldToJson(parameters["pDepthStencil"], pDepthStencil, json_options_);
            FieldToJson(parameters["rangeCount"], rangeCount, json_options_);
            FieldToJson(parameters["pRanges"], pRanges, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    WriteApiCallToFile(call_info, "vkCmdClearAttachments",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["attachmentCount"], attachmentCount, json_options_);
            FieldToJson(parameters["pAttachments"], pAttachments, json_options_);
            FieldToJson(parameters["rectCount"], rectCount, json_options_);
            FieldToJson(parameters["pRects"], pRects, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{
    WriteApiCallToFile(call_info, "vkCmdResolveImage",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["srcImage"], to_hex(srcImage), json_options_);
            FieldToJson(parameters["srcImageLayout"], srcImageLayout, json_options_);
            FieldToJson(parameters["dstImage"], to_hex(dstImage), json_options_);
            FieldToJson(parameters["dstImageLayout"], dstImageLayout, json_options_);
            FieldToJson(parameters["regionCount"], regionCount, json_options_);
            FieldToJson(parameters["pRegions"], pRegions, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    WriteApiCallToFile(call_info, "vkCmdSetEvent",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["event"], to_hex(event), json_options_);
            FieldToJson(VkPipelineStageFlags_t(), parameters["stageMask"], stageMask, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    WriteApiCallToFile(call_info, "vkCmdResetEvent",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["event"], to_hex(event), json_options_);
            FieldToJson(VkPipelineStageFlags_t(), parameters["stageMask"], stageMask, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWaitEvents(
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
    WriteApiCallToFile(call_info, "vkCmdWaitEvents",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["eventCount"], eventCount, json_options_);
            FieldToJson(parameters["pEvents"], pEvents, json_options_);
            FieldToJson(VkPipelineStageFlags_t(), parameters["srcStageMask"], srcStageMask, json_options_);
            FieldToJson(VkPipelineStageFlags_t(), parameters["dstStageMask"], dstStageMask, json_options_);
            FieldToJson(parameters["memoryBarrierCount"], memoryBarrierCount, json_options_);
            FieldToJson(parameters["pMemoryBarriers"], pMemoryBarriers, json_options_);
            FieldToJson(parameters["bufferMemoryBarrierCount"], bufferMemoryBarrierCount, json_options_);
            FieldToJson(parameters["pBufferMemoryBarriers"], pBufferMemoryBarriers, json_options_);
            FieldToJson(parameters["imageMemoryBarrierCount"], imageMemoryBarrierCount, json_options_);
            FieldToJson(parameters["pImageMemoryBarriers"], pImageMemoryBarriers, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier(
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
    WriteApiCallToFile(call_info, "vkCmdPipelineBarrier",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkPipelineStageFlags_t(), parameters["srcStageMask"], srcStageMask, json_options_);
            FieldToJson(VkPipelineStageFlags_t(), parameters["dstStageMask"], dstStageMask, json_options_);
            FieldToJson(VkDependencyFlags_t(), parameters["dependencyFlags"], dependencyFlags, json_options_);
            FieldToJson(parameters["memoryBarrierCount"], memoryBarrierCount, json_options_);
            FieldToJson(parameters["pMemoryBarriers"], pMemoryBarriers, json_options_);
            FieldToJson(parameters["bufferMemoryBarrierCount"], bufferMemoryBarrierCount, json_options_);
            FieldToJson(parameters["pBufferMemoryBarriers"], pBufferMemoryBarriers, json_options_);
            FieldToJson(parameters["imageMemoryBarrierCount"], imageMemoryBarrierCount, json_options_);
            FieldToJson(parameters["pImageMemoryBarriers"], pImageMemoryBarriers, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    WriteApiCallToFile(call_info, "vkCmdBeginQuery",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["query"], query, json_options_);
            FieldToJson(VkQueryControlFlags_t(), parameters["flags"], flags, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    WriteApiCallToFile(call_info, "vkCmdEndQuery",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["query"], query, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    WriteApiCallToFile(call_info, "vkCmdResetQueryPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["firstQuery"], firstQuery, json_options_);
            FieldToJson(parameters["queryCount"], queryCount, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    WriteApiCallToFile(call_info, "vkCmdWriteTimestamp",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pipelineStage"], pipelineStage, json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["query"], query, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyQueryPoolResults(
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
    WriteApiCallToFile(call_info, "vkCmdCopyQueryPoolResults",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["firstQuery"], firstQuery, json_options_);
            FieldToJson(parameters["queryCount"], queryCount, json_options_);
            FieldToJson(parameters["dstBuffer"], to_hex(dstBuffer), json_options_);
            FieldToJson(parameters["dstOffset"], dstOffset, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            FieldToJson(VkQueryResultFlags_t(), parameters["flags"], flags, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    WriteApiCallToFile(call_info, "vkCmdBeginRenderPass",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pRenderPassBegin"], pRenderPassBegin, json_options_);
            FieldToJson(parameters["contents"], contents, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    WriteApiCallToFile(call_info, "vkCmdNextSubpass",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["contents"], contents, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    WriteApiCallToFile(call_info, "vkCmdEndRenderPass",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    WriteApiCallToFile(call_info, "vkCmdExecuteCommands",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["commandBufferCount"], commandBufferCount, json_options_);
            FieldToJson(parameters["pCommandBuffers"], pCommandBuffers, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    WriteApiCallToFile(call_info, "vkBindBufferMemory2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["bindInfoCount"], bindInfoCount, json_options_);
            FieldToJson(parameters["pBindInfos"], pBindInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    WriteApiCallToFile(call_info, "vkBindImageMemory2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["bindInfoCount"], bindInfoCount, json_options_);
            FieldToJson(parameters["pBindInfos"], pBindInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    WriteApiCallToFile(call_info, "vkGetDeviceGroupPeerMemoryFeatures",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["heapIndex"], heapIndex, json_options_);
            FieldToJson(parameters["localDeviceIndex"], localDeviceIndex, json_options_);
            FieldToJson(parameters["remoteDeviceIndex"], remoteDeviceIndex, json_options_);
            FieldToJson(parameters["pPeerMemoryFeatures"], pPeerMemoryFeatures, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    WriteApiCallToFile(call_info, "vkCmdSetDeviceMask",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["deviceMask"], deviceMask, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    WriteApiCallToFile(call_info, "vkCmdDispatchBase",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["baseGroupX"], baseGroupX, json_options_);
            FieldToJson(parameters["baseGroupY"], baseGroupY, json_options_);
            FieldToJson(parameters["baseGroupZ"], baseGroupZ, json_options_);
            FieldToJson(parameters["groupCountX"], groupCountX, json_options_);
            FieldToJson(parameters["groupCountY"], groupCountY, json_options_);
            FieldToJson(parameters["groupCountZ"], groupCountZ, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDeviceGroups",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pPhysicalDeviceGroupCount"], pPhysicalDeviceGroupCount, json_options_);
            FieldToJson(parameters["pPhysicalDeviceGroupProperties"], pPhysicalDeviceGroupProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetImageMemoryRequirements2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetBufferMemoryRequirements2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetImageSparseMemoryRequirements2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options_);
            FieldToJson(parameters["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFeatures2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pFeatures"], pFeatures, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceProperties2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFormatProperties2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["format"], format, json_options_);
            FieldToJson(parameters["pFormatProperties"], pFormatProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceImageFormatProperties2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pImageFormatInfo"], pImageFormatInfo, json_options_);
            FieldToJson(parameters["pImageFormatProperties"], pImageFormatProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount, json_options_);
            FieldToJson(parameters["pQueueFamilyProperties"], pQueueFamilyProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMemoryProperties2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pMemoryProperties"], pMemoryProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pFormatInfo"], pFormatInfo, json_options_);
            FieldToJson(parameters["pPropertyCount"], pPropertyCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    WriteApiCallToFile(call_info, "vkTrimCommandPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["commandPool"], to_hex(commandPool), json_options_);
            FieldToJson(VkCommandPoolTrimFlags_t(), parameters["flags"], flags, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    WriteApiCallToFile(call_info, "vkGetDeviceQueue2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pQueueInfo"], pQueueInfo, json_options_);
            FieldToJson(parameters["pQueue"], pQueue, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    WriteApiCallToFile(call_info, "vkCreateSamplerYcbcrConversion",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pYcbcrConversion"], pYcbcrConversion, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySamplerYcbcrConversion",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["ycbcrConversion"], to_hex(ycbcrConversion), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    WriteApiCallToFile(call_info, "vkCreateDescriptorUpdateTemplate",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pDescriptorUpdateTemplate"], pDescriptorUpdateTemplate, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDescriptorUpdateTemplate",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["descriptorUpdateTemplate"], to_hex(descriptorUpdateTemplate), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalBufferProperties",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pExternalBufferInfo"], pExternalBufferInfo, json_options_);
            FieldToJson(parameters["pExternalBufferProperties"], pExternalBufferProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalFenceProperties",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pExternalFenceInfo"], pExternalFenceInfo, json_options_);
            FieldToJson(parameters["pExternalFenceProperties"], pExternalFenceProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalSemaphoreProperties",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pExternalSemaphoreInfo"], pExternalSemaphoreInfo, json_options_);
            FieldToJson(parameters["pExternalSemaphoreProperties"], pExternalSemaphoreProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    WriteApiCallToFile(call_info, "vkGetDescriptorSetLayoutSupport",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pSupport"], pSupport, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectCount",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["countBuffer"], to_hex(countBuffer), json_options_);
            FieldToJson(parameters["countBufferOffset"], countBufferOffset, json_options_);
            FieldToJson(parameters["maxDrawCount"], maxDrawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirectCount",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["countBuffer"], to_hex(countBuffer), json_options_);
            FieldToJson(parameters["countBufferOffset"], countBufferOffset, json_options_);
            FieldToJson(parameters["maxDrawCount"], maxDrawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    WriteApiCallToFile(call_info, "vkCreateRenderPass2",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pRenderPass"], pRenderPass, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBeginRenderPass2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pRenderPassBegin"], pRenderPassBegin, json_options_);
            FieldToJson(parameters["pSubpassBeginInfo"], pSubpassBeginInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    WriteApiCallToFile(call_info, "vkCmdNextSubpass2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pSubpassBeginInfo"], pSubpassBeginInfo, json_options_);
            FieldToJson(parameters["pSubpassEndInfo"], pSubpassEndInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    WriteApiCallToFile(call_info, "vkCmdEndRenderPass2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pSubpassEndInfo"], pSubpassEndInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    WriteApiCallToFile(call_info, "vkResetQueryPool",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["firstQuery"], firstQuery, json_options_);
            FieldToJson(parameters["queryCount"], queryCount, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreCounterValue(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    WriteApiCallToFile(call_info, "vkGetSemaphoreCounterValue",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["semaphore"], to_hex(semaphore), json_options_);
            FieldToJson(parameters["pValue"], pValue, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    WriteApiCallToFile(call_info, "vkWaitSemaphores",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pWaitInfo"], pWaitInfo, json_options_);
            FieldToJson(parameters["timeout"], timeout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    WriteApiCallToFile(call_info, "vkSignalSemaphore",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pSignalInfo"], pSignalInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetBufferDeviceAddress",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], to_hex(returnValue), json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetBufferOpaqueCaptureAddress",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetDeviceMemoryOpaqueCaptureAddress",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceToolProperties",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pToolCount"], pToolCount, json_options_);
            FieldToJson(parameters["pToolProperties"], pToolProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    WriteApiCallToFile(call_info, "vkCreatePrivateDataSlot",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pPrivateDataSlot"], pPrivateDataSlot, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyPrivateDataSlot",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["privateDataSlot"], to_hex(privateDataSlot), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSetPrivateData(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    WriteApiCallToFile(call_info, "vkSetPrivateData",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["objectType"], objectType, json_options_);
            FieldToJson(parameters["objectHandle"], objectHandle, json_options_);
            FieldToJson(parameters["privateDataSlot"], to_hex(privateDataSlot), json_options_);
            FieldToJson(parameters["data"], data, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    WriteApiCallToFile(call_info, "vkGetPrivateData",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["objectType"], objectType, json_options_);
            FieldToJson(parameters["objectHandle"], objectHandle, json_options_);
            FieldToJson(parameters["privateDataSlot"], to_hex(privateDataSlot), json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetEvent2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["event"], to_hex(event), json_options_);
            FieldToJson(parameters["pDependencyInfo"], pDependencyInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    WriteApiCallToFile(call_info, "vkCmdResetEvent2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["event"], to_hex(event), json_options_);
            FieldToJson(VkPipelineStageFlags2_t(), parameters["stageMask"], stageMask, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    WriteApiCallToFile(call_info, "vkCmdWaitEvents2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["eventCount"], eventCount, json_options_);
            FieldToJson(parameters["pEvents"], pEvents, json_options_);
            FieldToJson(parameters["pDependencyInfos"], pDependencyInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    WriteApiCallToFile(call_info, "vkCmdPipelineBarrier2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pDependencyInfo"], pDependencyInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    WriteApiCallToFile(call_info, "vkCmdWriteTimestamp2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkPipelineStageFlags2_t(), parameters["stage"], stage, json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["query"], query, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkQueueSubmit2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    WriteApiCallToFile(call_info, "vkQueueSubmit2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["submit_index"], ++submit_index_, json_options_);
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            FieldToJson(parameters["submitCount"], submitCount, json_options_);
            FieldToJson(parameters["pSubmits"], pSubmits, json_options_);
            FieldToJson(parameters["fence"], to_hex(fence), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyBuffer2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pCopyBufferInfo"], pCopyBufferInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyImage2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pCopyImageInfo"], pCopyImageInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyBufferToImage2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pCopyBufferToImageInfo"], pCopyBufferToImageInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyImageToBuffer2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pCopyImageToBufferInfo"], pCopyImageToBufferInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBlitImage2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pBlitImageInfo"], pBlitImageInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    WriteApiCallToFile(call_info, "vkCmdResolveImage2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pResolveImageInfo"], pResolveImageInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBeginRendering",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pRenderingInfo"], pRenderingInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    WriteApiCallToFile(call_info, "vkCmdEndRendering",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetCullMode",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkCullModeFlags_t(), parameters["cullMode"], cullMode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    WriteApiCallToFile(call_info, "vkCmdSetFrontFace",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["frontFace"], frontFace, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveTopology",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["primitiveTopology"], primitiveTopology, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewportWithCount",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["viewportCount"], viewportCount, json_options_);
            FieldToJson(parameters["pViewports"], pViewports, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    WriteApiCallToFile(call_info, "vkCmdSetScissorWithCount",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["scissorCount"], scissorCount, json_options_);
            FieldToJson(parameters["pScissors"], pScissors, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    WriteApiCallToFile(call_info, "vkCmdBindVertexBuffers2",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstBinding"], firstBinding, json_options_);
            FieldToJson(parameters["bindingCount"], bindingCount, json_options_);
            FieldToJson(parameters["pBuffers"], pBuffers, json_options_);
            FieldToJson(parameters["pOffsets"], pOffsets, json_options_);
            FieldToJson(parameters["pSizes"], pSizes, json_options_);
            FieldToJson(parameters["pStrides"], pStrides, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthTestEnable",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthTestEnable"], depthTestEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthWriteEnable",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthWriteEnable"], depthWriteEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthCompareOp",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthCompareOp"], depthCompareOp, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthBoundsTestEnable",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthBoundsTestEnable"], depthBoundsTestEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetStencilTestEnable",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["stencilTestEnable"], stencilTestEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    WriteApiCallToFile(call_info, "vkCmdSetStencilOp",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkStencilFaceFlags_t(), parameters["faceMask"], faceMask, json_options_);
            FieldToJson(parameters["failOp"], failOp, json_options_);
            FieldToJson(parameters["passOp"], passOp, json_options_);
            FieldToJson(parameters["depthFailOp"], depthFailOp, json_options_);
            FieldToJson(parameters["compareOp"], compareOp, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetRasterizerDiscardEnable",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["rasterizerDiscardEnable"], rasterizerDiscardEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthBiasEnable",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthBiasEnable"], depthBiasEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveRestartEnable",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["primitiveRestartEnable"], primitiveRestartEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetDeviceBufferMemoryRequirements",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetDeviceImageMemoryRequirements",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetDeviceImageSparseMemoryRequirements",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options_);
            FieldToJson(parameters["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySurfaceKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["surface"], to_hex(surface), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceSupportKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["queueFamilyIndex"], queueFamilyIndex, json_options_);
            FieldToJson(parameters["surface"], to_hex(surface), json_options_);
            FieldToJson(parameters["pSupported"], pSupported, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["surface"], to_hex(surface), json_options_);
            FieldToJson(parameters["pSurfaceCapabilities"], pSurfaceCapabilities, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceFormatsKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["surface"], to_hex(surface), json_options_);
            FieldToJson(parameters["pSurfaceFormatCount"], pSurfaceFormatCount, json_options_);
            FieldToJson(parameters["pSurfaceFormats"], pSurfaceFormats, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfacePresentModesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["surface"], to_hex(surface), json_options_);
            FieldToJson(parameters["pPresentModeCount"], pPresentModeCount, json_options_);
            FieldToJson(parameters["pPresentModes"], pPresentModes, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    WriteApiCallToFile(call_info, "vkCreateSwapchainKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSwapchain"], pSwapchain, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySwapchainKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchain"], to_hex(swapchain), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    WriteApiCallToFile(call_info, "vkGetSwapchainImagesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchain"], to_hex(swapchain), json_options_);
            FieldToJson(parameters["pSwapchainImageCount"], pSwapchainImageCount, json_options_);
            FieldToJson(parameters["pSwapchainImages"], pSwapchainImages, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAcquireNextImageKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    timeout,
    format::HandleId                            semaphore,
    format::HandleId                            fence,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    WriteApiCallToFile(call_info, "vkAcquireNextImageKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchain"], to_hex(swapchain), json_options_);
            FieldToJson(parameters["timeout"], timeout, json_options_);
            FieldToJson(parameters["semaphore"], to_hex(semaphore), json_options_);
            FieldToJson(parameters["fence"], to_hex(fence), json_options_);
            FieldToJson(parameters["pImageIndex"], pImageIndex, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    WriteApiCallToFile(call_info, "vkQueuePresentKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["submit_index"], ++submit_index_, json_options_);
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            FieldToJson(parameters["pPresentInfo"], pPresentInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetDeviceGroupPresentCapabilitiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pDeviceGroupPresentCapabilities"], pDeviceGroupPresentCapabilities, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    WriteApiCallToFile(call_info, "vkGetDeviceGroupSurfacePresentModesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["surface"], to_hex(surface), json_options_);
            FieldToJson(parameters["pModes"], pModes, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDevicePresentRectanglesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["surface"], to_hex(surface), json_options_);
            FieldToJson(parameters["pRectCount"], pRectCount, json_options_);
            FieldToJson(parameters["pRects"], pRects, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    WriteApiCallToFile(call_info, "vkAcquireNextImage2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pAcquireInfo"], pAcquireInfo, json_options_);
            FieldToJson(parameters["pImageIndex"], pImageIndex, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayPropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pPropertyCount"], pPropertyCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pPropertyCount"], pPropertyCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    planeIndex,
    PointerDecoder<uint32_t>*                   pDisplayCount,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplays)
{
    WriteApiCallToFile(call_info, "vkGetDisplayPlaneSupportedDisplaysKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["planeIndex"], planeIndex, json_options_);
            FieldToJson(parameters["pDisplayCount"], pDisplayCount, json_options_);
            FieldToJson(parameters["pDisplays"], pDisplays, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetDisplayModePropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["display"], to_hex(display), json_options_);
            FieldToJson(parameters["pPropertyCount"], pPropertyCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDisplayModeKHR>*     pMode)
{
    WriteApiCallToFile(call_info, "vkCreateDisplayModeKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["display"], to_hex(display), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pMode"], pMode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetDisplayPlaneCapabilitiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["mode"], to_hex(mode), json_options_);
            FieldToJson(parameters["planeIndex"], planeIndex, json_options_);
            FieldToJson(parameters["pCapabilities"], pCapabilities, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateDisplayPlaneSurfaceKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains)
{
    WriteApiCallToFile(call_info, "vkCreateSharedSwapchainsKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchainCount"], swapchainCount, json_options_);
            FieldToJson(parameters["pCreateInfos"], pCreateInfos, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSwapchains"], pSwapchains, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateXlibSurfaceKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceXlibPresentationSupportKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["queueFamilyIndex"], queueFamilyIndex, json_options_);
            FieldToJson(parameters["dpy"], dpy, json_options_);
            FieldToJson(parameters["visualID"], visualID, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateXcbSurfaceKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceXcbPresentationSupportKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["queueFamilyIndex"], queueFamilyIndex, json_options_);
            FieldToJson(parameters["connection"], connection, json_options_);
            FieldToJson(parameters["visual_id"], visual_id, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateWaylandSurfaceKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceWaylandPresentationSupportKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["queueFamilyIndex"], queueFamilyIndex, json_options_);
            FieldToJson(parameters["display"], display, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateAndroidSurfaceKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateWin32SurfaceKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceWin32PresentationSupportKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["queueFamilyIndex"], queueFamilyIndex, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile,
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceVideoCapabilitiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pVideoProfile"], pVideoProfile, json_options_);
            FieldToJson(parameters["pCapabilities"], pCapabilities, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo,
    PointerDecoder<uint32_t>*                   pVideoFormatPropertyCount,
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceVideoFormatPropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pVideoFormatInfo"], pVideoFormatInfo, json_options_);
            FieldToJson(parameters["pVideoFormatPropertyCount"], pVideoFormatPropertyCount, json_options_);
            FieldToJson(parameters["pVideoFormatProperties"], pVideoFormatProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionKHR>*    pVideoSession)
{
    WriteApiCallToFile(call_info, "vkCreateVideoSessionKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pVideoSession"], pVideoSession, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyVideoSessionKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["videoSession"], to_hex(videoSession), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetVideoSessionMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    PointerDecoder<uint32_t>*                   pMemoryRequirementsCount,
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetVideoSessionMemoryRequirementsKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["videoSession"], to_hex(videoSession), json_options_);
            FieldToJson(parameters["pMemoryRequirementsCount"], pMemoryRequirementsCount, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos)
{
    WriteApiCallToFile(call_info, "vkBindVideoSessionMemoryKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["videoSession"], to_hex(videoSession), json_options_);
            FieldToJson(parameters["bindSessionMemoryInfoCount"], bindSessionMemoryInfoCount, json_options_);
            FieldToJson(parameters["pBindSessionMemoryInfos"], pBindSessionMemoryInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters)
{
    WriteApiCallToFile(call_info, "vkCreateVideoSessionParametersKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pVideoSessionParameters"], pVideoSessionParameters, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkUpdateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo)
{
    WriteApiCallToFile(call_info, "vkUpdateVideoSessionParametersKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["videoSessionParameters"], to_hex(videoSessionParameters), json_options_);
            FieldToJson(parameters["pUpdateInfo"], pUpdateInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyVideoSessionParametersKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["videoSessionParameters"], to_hex(videoSessionParameters), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBeginVideoCodingKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pBeginInfo"], pBeginInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    WriteApiCallToFile(call_info, "vkCmdEndVideoCodingKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pEndCodingInfo"], pEndCodingInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    WriteApiCallToFile(call_info, "vkCmdControlVideoCodingKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pCodingControlInfo"], pCodingControlInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    WriteApiCallToFile(call_info, "vkCmdDecodeVideoKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pDecodeInfo"], pDecodeInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBeginRenderingKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pRenderingInfo"], pRenderingInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    WriteApiCallToFile(call_info, "vkCmdEndRenderingKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFeatures2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pFeatures"], pFeatures, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceProperties2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFormatProperties2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["format"], format, json_options_);
            FieldToJson(parameters["pFormatProperties"], pFormatProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceImageFormatProperties2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pImageFormatInfo"], pImageFormatInfo, json_options_);
            FieldToJson(parameters["pImageFormatProperties"], pImageFormatProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount, json_options_);
            FieldToJson(parameters["pQueueFamilyProperties"], pQueueFamilyProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMemoryProperties2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pMemoryProperties"], pMemoryProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pFormatInfo"], pFormatInfo, json_options_);
            FieldToJson(parameters["pPropertyCount"], pPropertyCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    WriteApiCallToFile(call_info, "vkGetDeviceGroupPeerMemoryFeaturesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["heapIndex"], heapIndex, json_options_);
            FieldToJson(parameters["localDeviceIndex"], localDeviceIndex, json_options_);
            FieldToJson(parameters["remoteDeviceIndex"], remoteDeviceIndex, json_options_);
            FieldToJson(parameters["pPeerMemoryFeatures"], pPeerMemoryFeatures, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    WriteApiCallToFile(call_info, "vkCmdSetDeviceMaskKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["deviceMask"], deviceMask, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    WriteApiCallToFile(call_info, "vkCmdDispatchBaseKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["baseGroupX"], baseGroupX, json_options_);
            FieldToJson(parameters["baseGroupY"], baseGroupY, json_options_);
            FieldToJson(parameters["baseGroupZ"], baseGroupZ, json_options_);
            FieldToJson(parameters["groupCountX"], groupCountX, json_options_);
            FieldToJson(parameters["groupCountY"], groupCountY, json_options_);
            FieldToJson(parameters["groupCountZ"], groupCountZ, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    WriteApiCallToFile(call_info, "vkTrimCommandPoolKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["commandPool"], to_hex(commandPool), json_options_);
            FieldToJson(VkCommandPoolTrimFlags_t(), parameters["flags"], flags, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDeviceGroupsKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pPhysicalDeviceGroupCount"], pPhysicalDeviceGroupCount, json_options_);
            FieldToJson(parameters["pPhysicalDeviceGroupProperties"], pPhysicalDeviceGroupProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalBufferPropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pExternalBufferInfo"], pExternalBufferInfo, json_options_);
            FieldToJson(parameters["pExternalBufferProperties"], pExternalBufferProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    WriteApiCallToFile(call_info, "vkGetMemoryWin32HandleKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pGetWin32HandleInfo"], pGetWin32HandleInfo, json_options_);
            FieldToJson(parameters["pHandle"], pHandle, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    handle,
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties)
{
    WriteApiCallToFile(call_info, "vkGetMemoryWin32HandlePropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["handleType"], handleType, json_options_);
            FieldToJson(parameters["handle"], handle, json_options_);
            FieldToJson(parameters["pMemoryWin32HandleProperties"], pMemoryWin32HandleProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    WriteApiCallToFile(call_info, "vkGetMemoryFdKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pGetFdInfo"], pGetFdInfo, json_options_);
            FieldToJson(parameters["pFd"], pFd, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    WriteApiCallToFile(call_info, "vkGetMemoryFdPropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["handleType"], handleType, json_options_);
            FieldToJson(parameters["fd"], fd, json_options_);
            FieldToJson(parameters["pMemoryFdProperties"], pMemoryFdProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pExternalSemaphoreInfo"], pExternalSemaphoreInfo, json_options_);
            FieldToJson(parameters["pExternalSemaphoreProperties"], pExternalSemaphoreProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    WriteApiCallToFile(call_info, "vkImportSemaphoreWin32HandleKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pImportSemaphoreWin32HandleInfo"], pImportSemaphoreWin32HandleInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    WriteApiCallToFile(call_info, "vkGetSemaphoreWin32HandleKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pGetWin32HandleInfo"], pGetWin32HandleInfo, json_options_);
            FieldToJson(parameters["pHandle"], pHandle, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    WriteApiCallToFile(call_info, "vkImportSemaphoreFdKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pImportSemaphoreFdInfo"], pImportSemaphoreFdInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    WriteApiCallToFile(call_info, "vkGetSemaphoreFdKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pGetFdInfo"], pGetFdInfo, json_options_);
            FieldToJson(parameters["pFd"], pFd, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    WriteApiCallToFile(call_info, "vkCmdPushDescriptorSetKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pipelineBindPoint"], pipelineBindPoint, json_options_);
            FieldToJson(parameters["layout"], to_hex(layout), json_options_);
            FieldToJson(parameters["set"], set, json_options_);
            FieldToJson(parameters["descriptorWriteCount"], descriptorWriteCount, json_options_);
            FieldToJson(parameters["pDescriptorWrites"], pDescriptorWrites, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    WriteApiCallToFile(call_info, "vkCreateDescriptorUpdateTemplateKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pDescriptorUpdateTemplate"], pDescriptorUpdateTemplate, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDescriptorUpdateTemplateKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["descriptorUpdateTemplate"], to_hex(descriptorUpdateTemplate), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    WriteApiCallToFile(call_info, "vkCreateRenderPass2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pRenderPass"], pRenderPass, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBeginRenderPass2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pRenderPassBegin"], pRenderPassBegin, json_options_);
            FieldToJson(parameters["pSubpassBeginInfo"], pSubpassBeginInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    WriteApiCallToFile(call_info, "vkCmdNextSubpass2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pSubpassBeginInfo"], pSubpassBeginInfo, json_options_);
            FieldToJson(parameters["pSubpassEndInfo"], pSubpassEndInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    WriteApiCallToFile(call_info, "vkCmdEndRenderPass2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pSubpassEndInfo"], pSubpassEndInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    WriteApiCallToFile(call_info, "vkGetSwapchainStatusKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchain"], to_hex(swapchain), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalFencePropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pExternalFenceInfo"], pExternalFenceInfo, json_options_);
            FieldToJson(parameters["pExternalFenceProperties"], pExternalFenceProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    WriteApiCallToFile(call_info, "vkImportFenceWin32HandleKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pImportFenceWin32HandleInfo"], pImportFenceWin32HandleInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    WriteApiCallToFile(call_info, "vkGetFenceWin32HandleKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pGetWin32HandleInfo"], pGetWin32HandleInfo, json_options_);
            FieldToJson(parameters["pHandle"], pHandle, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    WriteApiCallToFile(call_info, "vkImportFenceFdKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pImportFenceFdInfo"], pImportFenceFdInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    WriteApiCallToFile(call_info, "vkGetFenceFdKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pGetFdInfo"], pGetFdInfo, json_options_);
            FieldToJson(parameters["pFd"], pFd, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    PointerDecoder<uint32_t>*                   pCounterCount,
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters,
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions)
{
    WriteApiCallToFile(call_info, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["queueFamilyIndex"], queueFamilyIndex, json_options_);
            FieldToJson(parameters["pCounterCount"], pCounterCount, json_options_);
            FieldToJson(parameters["pCounters"], pCounters, json_options_);
            FieldToJson(parameters["pCounterDescriptions"], pCounterDescriptions, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pPerformanceQueryCreateInfo"], pPerformanceQueryCreateInfo, json_options_);
            FieldToJson(parameters["pNumPasses"], pNumPasses, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    WriteApiCallToFile(call_info, "vkAcquireProfilingLockKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    WriteApiCallToFile(call_info, "vkReleaseProfilingLockKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceCapabilities2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pSurfaceInfo"], pSurfaceInfo, json_options_);
            FieldToJson(parameters["pSurfaceCapabilities"], pSurfaceCapabilities, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceFormats2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pSurfaceInfo"], pSurfaceInfo, json_options_);
            FieldToJson(parameters["pSurfaceFormatCount"], pSurfaceFormatCount, json_options_);
            FieldToJson(parameters["pSurfaceFormats"], pSurfaceFormats, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayProperties2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pPropertyCount"], pPropertyCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pPropertyCount"], pPropertyCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDisplayModeProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetDisplayModeProperties2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["display"], to_hex(display), json_options_);
            FieldToJson(parameters["pPropertyCount"], pPropertyCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetDisplayPlaneCapabilities2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pDisplayPlaneInfo"], pDisplayPlaneInfo, json_options_);
            FieldToJson(parameters["pCapabilities"], pCapabilities, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetImageMemoryRequirements2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetBufferMemoryRequirements2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetImageSparseMemoryRequirements2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options_);
            FieldToJson(parameters["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    WriteApiCallToFile(call_info, "vkCreateSamplerYcbcrConversionKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pYcbcrConversion"], pYcbcrConversion, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroySamplerYcbcrConversionKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["ycbcrConversion"], to_hex(ycbcrConversion), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    WriteApiCallToFile(call_info, "vkBindBufferMemory2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["bindInfoCount"], bindInfoCount, json_options_);
            FieldToJson(parameters["pBindInfos"], pBindInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    WriteApiCallToFile(call_info, "vkBindImageMemory2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["bindInfoCount"], bindInfoCount, json_options_);
            FieldToJson(parameters["pBindInfos"], pBindInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    WriteApiCallToFile(call_info, "vkGetDescriptorSetLayoutSupportKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pSupport"], pSupport, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectCountKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["countBuffer"], to_hex(countBuffer), json_options_);
            FieldToJson(parameters["countBufferOffset"], countBufferOffset, json_options_);
            FieldToJson(parameters["maxDrawCount"], maxDrawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirectCountKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["countBuffer"], to_hex(countBuffer), json_options_);
            FieldToJson(parameters["countBufferOffset"], countBufferOffset, json_options_);
            FieldToJson(parameters["maxDrawCount"], maxDrawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreCounterValueKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    WriteApiCallToFile(call_info, "vkGetSemaphoreCounterValueKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["semaphore"], to_hex(semaphore), json_options_);
            FieldToJson(parameters["pValue"], pValue, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    WriteApiCallToFile(call_info, "vkWaitSemaphoresKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pWaitInfo"], pWaitInfo, json_options_);
            FieldToJson(parameters["timeout"], timeout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    WriteApiCallToFile(call_info, "vkSignalSemaphoreKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pSignalInfo"], pSignalInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceFragmentShadingRatesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pFragmentShadingRateCount"], pFragmentShadingRateCount, json_options_);
            FieldToJson(parameters["pFragmentShadingRates"], pFragmentShadingRates, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    WriteApiCallToFile(call_info, "vkCmdSetFragmentShadingRateKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pFragmentSize"], pFragmentSize, json_options_);
            FieldToJson(parameters["combinerOps"], combinerOps, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout)
{
    WriteApiCallToFile(call_info, "vkWaitForPresentKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchain"], to_hex(swapchain), json_options_);
            FieldToJson(parameters["presentId"], presentId, json_options_);
            FieldToJson(parameters["timeout"], timeout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetBufferDeviceAddressKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], to_hex(returnValue), json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetBufferOpaqueCaptureAddressKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetDeviceMemoryOpaqueCaptureAddressKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    WriteApiCallToFile(call_info, "vkCreateDeferredOperationKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pDeferredOperation"], pDeferredOperation, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDeferredOperationKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["operation"], to_hex(operation), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    WriteApiCallToFile(call_info, "vkGetDeferredOperationMaxConcurrencyKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["operation"], to_hex(operation), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    WriteApiCallToFile(call_info, "vkGetDeferredOperationResultKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["operation"], to_hex(operation), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    WriteApiCallToFile(call_info, "vkDeferredOperationJoinKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["operation"], to_hex(operation), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPipelineExecutablePropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pPipelineInfo"], pPipelineInfo, json_options_);
            FieldToJson(parameters["pExecutableCount"], pExecutableCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    WriteApiCallToFile(call_info, "vkGetPipelineExecutableStatisticsKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pExecutableInfo"], pExecutableInfo, json_options_);
            FieldToJson(parameters["pStatisticCount"], pStatisticCount, json_options_);
            FieldToJson(parameters["pStatistics"], pStatistics, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    WriteApiCallToFile(call_info, "vkGetPipelineExecutableInternalRepresentationsKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pExecutableInfo"], pExecutableInfo, json_options_);
            FieldToJson(parameters["pInternalRepresentationCount"], pInternalRepresentationCount, json_options_);
            FieldToJson(parameters["pInternalRepresentations"], pInternalRepresentations, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    WriteApiCallToFile(call_info, "vkCmdEncodeVideoKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pEncodeInfo"], pEncodeInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetEvent2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["event"], to_hex(event), json_options_);
            FieldToJson(parameters["pDependencyInfo"], pDependencyInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    WriteApiCallToFile(call_info, "vkCmdResetEvent2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["event"], to_hex(event), json_options_);
            FieldToJson(VkPipelineStageFlags2_t(), parameters["stageMask"], stageMask, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    WriteApiCallToFile(call_info, "vkCmdWaitEvents2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["eventCount"], eventCount, json_options_);
            FieldToJson(parameters["pEvents"], pEvents, json_options_);
            FieldToJson(parameters["pDependencyInfos"], pDependencyInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    WriteApiCallToFile(call_info, "vkCmdPipelineBarrier2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pDependencyInfo"], pDependencyInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    WriteApiCallToFile(call_info, "vkCmdWriteTimestamp2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkPipelineStageFlags2_t(), parameters["stage"], stage, json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["query"], query, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkQueueSubmit2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    WriteApiCallToFile(call_info, "vkQueueSubmit2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["submit_index"], ++submit_index_, json_options_);
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            FieldToJson(parameters["submitCount"], submitCount, json_options_);
            FieldToJson(parameters["pSubmits"], pSubmits, json_options_);
            FieldToJson(parameters["fence"], to_hex(fence), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    WriteApiCallToFile(call_info, "vkCmdWriteBufferMarker2AMD",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkPipelineStageFlags2_t(), parameters["stage"], stage, json_options_);
            FieldToJson(parameters["dstBuffer"], to_hex(dstBuffer), json_options_);
            FieldToJson(parameters["dstOffset"], dstOffset, json_options_);
            FieldToJson(parameters["marker"], marker, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    WriteApiCallToFile(call_info, "vkGetQueueCheckpointData2NV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            FieldToJson(parameters["pCheckpointDataCount"], pCheckpointDataCount, json_options_);
            FieldToJson(parameters["pCheckpointData"], pCheckpointData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyBuffer2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pCopyBufferInfo"], pCopyBufferInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyImage2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pCopyImageInfo"], pCopyImageInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyBufferToImage2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pCopyBufferToImageInfo"], pCopyBufferToImageInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyImageToBuffer2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pCopyImageToBufferInfo"], pCopyImageToBufferInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBlitImage2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pBlitImageInfo"], pBlitImageInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    WriteApiCallToFile(call_info, "vkCmdResolveImage2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pResolveImageInfo"], pResolveImageInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    WriteApiCallToFile(call_info, "vkCmdTraceRaysIndirect2KHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["indirectDeviceAddress"], to_hex(indirectDeviceAddress), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetDeviceBufferMemoryRequirementsKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetDeviceImageMemoryRequirementsKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetDeviceImageSparseMemoryRequirementsKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options_);
            FieldToJson(parameters["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    WriteApiCallToFile(call_info, "vkCreateDebugReportCallbackEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pCallback"], pCallback, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDebugReportCallbackEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["callback"], to_hex(callback), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDebugReportMessageEXT(
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
    WriteApiCallToFile(call_info, "vkDebugReportMessageEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(VkDebugReportFlagsEXT_t(), parameters["flags"], flags, json_options_);
            FieldToJson(parameters["objectType"], objectType, json_options_);
            FieldToJson(parameters["object"], object, json_options_);
            FieldToJson(parameters["location"], location, json_options_);
            FieldToJson(parameters["messageCode"], messageCode, json_options_);
            FieldToJson(parameters["pLayerPrefix"], pLayerPrefix, json_options_);
            FieldToJson(parameters["pMessage"], pMessage, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    WriteApiCallToFile(call_info, "vkDebugMarkerSetObjectTagEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pTagInfo"], pTagInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    WriteApiCallToFile(call_info, "vkDebugMarkerSetObjectNameEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pNameInfo"], pNameInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    WriteApiCallToFile(call_info, "vkCmdDebugMarkerBeginEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pMarkerInfo"], pMarkerInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    WriteApiCallToFile(call_info, "vkCmdDebugMarkerEndEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    WriteApiCallToFile(call_info, "vkCmdDebugMarkerInsertEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pMarkerInfo"], pMarkerInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes)
{
    WriteApiCallToFile(call_info, "vkCmdBindTransformFeedbackBuffersEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstBinding"], firstBinding, json_options_);
            FieldToJson(parameters["bindingCount"], bindingCount, json_options_);
            FieldToJson(parameters["pBuffers"], pBuffers, json_options_);
            FieldToJson(parameters["pOffsets"], pOffsets, json_options_);
            FieldToJson(parameters["pSizes"], pSizes, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    WriteApiCallToFile(call_info, "vkCmdBeginTransformFeedbackEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstCounterBuffer"], firstCounterBuffer, json_options_);
            FieldToJson(parameters["counterBufferCount"], counterBufferCount, json_options_);
            FieldToJson(parameters["pCounterBuffers"], pCounterBuffers, json_options_);
            FieldToJson(parameters["pCounterBufferOffsets"], pCounterBufferOffsets, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    WriteApiCallToFile(call_info, "vkCmdEndTransformFeedbackEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstCounterBuffer"], firstCounterBuffer, json_options_);
            FieldToJson(parameters["counterBufferCount"], counterBufferCount, json_options_);
            FieldToJson(parameters["pCounterBuffers"], pCounterBuffers, json_options_);
            FieldToJson(parameters["pCounterBufferOffsets"], pCounterBufferOffsets, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    WriteApiCallToFile(call_info, "vkCmdBeginQueryIndexedEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["query"], query, json_options_);
            FieldToJson(VkQueryControlFlags_t(), parameters["flags"], flags, json_options_);
            FieldToJson(parameters["index"], index, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    WriteApiCallToFile(call_info, "vkCmdEndQueryIndexedEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["query"], query, json_options_);
            FieldToJson(parameters["index"], index, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectByteCountEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["instanceCount"], instanceCount, json_options_);
            FieldToJson(parameters["firstInstance"], firstInstance, json_options_);
            FieldToJson(parameters["counterBuffer"], to_hex(counterBuffer), json_options_);
            FieldToJson(parameters["counterBufferOffset"], counterBufferOffset, json_options_);
            FieldToJson(parameters["counterOffset"], counterOffset, json_options_);
            FieldToJson(parameters["vertexStride"], vertexStride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetImageViewHandleNVX",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetImageViewAddressNVX",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["imageView"], to_hex(imageView), json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawIndirectCountAMD",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["countBuffer"], to_hex(countBuffer), json_options_);
            FieldToJson(parameters["countBufferOffset"], countBufferOffset, json_options_);
            FieldToJson(parameters["maxDrawCount"], maxDrawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawIndexedIndirectCountAMD",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["countBuffer"], to_hex(countBuffer), json_options_);
            FieldToJson(parameters["countBufferOffset"], countBufferOffset, json_options_);
            FieldToJson(parameters["maxDrawCount"], maxDrawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetShaderInfoAMD(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    PointerDecoder<size_t>*                     pInfoSize,
    PointerDecoder<uint8_t>*                    pInfo)
{
    WriteApiCallToFile(call_info, "vkGetShaderInfoAMD",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipeline"], to_hex(pipeline), json_options_);
            FieldToJson(parameters["shaderStage"], shaderStage, json_options_);
            FieldToJson(parameters["infoType"], infoType, json_options_);
            FieldToJson(parameters["pInfoSize"], pInfoSize, json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateStreamDescriptorSurfaceGGP",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
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
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["format"], format, json_options_);
            FieldToJson(parameters["type"], type, json_options_);
            FieldToJson(parameters["tiling"], tiling, json_options_);
            FieldToJson(VkImageUsageFlags_t(), parameters["usage"], usage, json_options_);
            FieldToJson(VkImageCreateFlags_t(), parameters["flags"], flags, json_options_);
            FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(), parameters["externalHandleType"], externalHandleType, json_options_);
            FieldToJson(parameters["pExternalImageFormatProperties"], pExternalImageFormatProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    WriteApiCallToFile(call_info, "vkGetMemoryWin32HandleNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["memory"], to_hex(memory), json_options_);
            FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(), parameters["handleType"], handleType, json_options_);
            FieldToJson(parameters["pHandle"], pHandle, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateViSurfaceNN",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    WriteApiCallToFile(call_info, "vkCmdBeginConditionalRenderingEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pConditionalRenderingBegin"], pConditionalRenderingBegin, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    WriteApiCallToFile(call_info, "vkCmdEndConditionalRenderingEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewportWScalingNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstViewport"], firstViewport, json_options_);
            FieldToJson(parameters["viewportCount"], viewportCount, json_options_);
            FieldToJson(parameters["pViewportWScalings"], pViewportWScalings, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    WriteApiCallToFile(call_info, "vkReleaseDisplayEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["display"], to_hex(display), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    WriteApiCallToFile(call_info, "vkAcquireXlibDisplayEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["dpy"], dpy, json_options_);
            FieldToJson(parameters["display"], to_hex(display), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    WriteApiCallToFile(call_info, "vkGetRandROutputDisplayEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["dpy"], dpy, json_options_);
            FieldToJson(parameters["rrOutput"], rrOutput, json_options_);
            FieldToJson(parameters["pDisplay"], pDisplay, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfaceCapabilities2EXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["surface"], to_hex(surface), json_options_);
            FieldToJson(parameters["pSurfaceCapabilities"], pSurfaceCapabilities, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    WriteApiCallToFile(call_info, "vkDisplayPowerControlEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["display"], to_hex(display), json_options_);
            FieldToJson(parameters["pDisplayPowerInfo"], pDisplayPowerInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    WriteApiCallToFile(call_info, "vkRegisterDeviceEventEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pDeviceEventInfo"], pDeviceEventInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pFence"], pFence, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    WriteApiCallToFile(call_info, "vkRegisterDisplayEventEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["display"], to_hex(display), json_options_);
            FieldToJson(parameters["pDisplayEventInfo"], pDisplayEventInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pFence"], pFence, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    WriteApiCallToFile(call_info, "vkGetSwapchainCounterEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchain"], to_hex(swapchain), json_options_);
            FieldToJson(parameters["counter"], counter, json_options_);
            FieldToJson(parameters["pCounterValue"], pCounterValue, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    WriteApiCallToFile(call_info, "vkGetRefreshCycleDurationGOOGLE",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchain"], to_hex(swapchain), json_options_);
            FieldToJson(parameters["pDisplayTimingProperties"], pDisplayTimingProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    WriteApiCallToFile(call_info, "vkGetPastPresentationTimingGOOGLE",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchain"], to_hex(swapchain), json_options_);
            FieldToJson(parameters["pPresentationTimingCount"], pPresentationTimingCount, json_options_);
            FieldToJson(parameters["pPresentationTimings"], pPresentationTimings, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    WriteApiCallToFile(call_info, "vkCmdSetDiscardRectangleEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstDiscardRectangle"], firstDiscardRectangle, json_options_);
            FieldToJson(parameters["discardRectangleCount"], discardRectangleCount, json_options_);
            FieldToJson(parameters["pDiscardRectangles"], pDiscardRectangles, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDiscardRectangleEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["discardRectangleEnable"], discardRectangleEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetDiscardRectangleModeEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["discardRectangleMode"], discardRectangleMode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    WriteApiCallToFile(call_info, "vkSetHdrMetadataEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchainCount"], swapchainCount, json_options_);
            FieldToJson(parameters["pSwapchains"], pSwapchains, json_options_);
            FieldToJson(parameters["pMetadata"], pMetadata, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateIOSSurfaceMVK",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateMacOSSurfaceMVK",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    WriteApiCallToFile(call_info, "vkSetDebugUtilsObjectNameEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pNameInfo"], pNameInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    WriteApiCallToFile(call_info, "vkSetDebugUtilsObjectTagEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pTagInfo"], pTagInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    WriteApiCallToFile(call_info, "vkQueueBeginDebugUtilsLabelEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            FieldToJson(parameters["pLabelInfo"], pLabelInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    WriteApiCallToFile(call_info, "vkQueueEndDebugUtilsLabelEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    WriteApiCallToFile(call_info, "vkQueueInsertDebugUtilsLabelEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            FieldToJson(parameters["pLabelInfo"], pLabelInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    WriteApiCallToFile(call_info, "vkCmdBeginDebugUtilsLabelEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pLabelInfo"], pLabelInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    WriteApiCallToFile(call_info, "vkCmdEndDebugUtilsLabelEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    WriteApiCallToFile(call_info, "vkCmdInsertDebugUtilsLabelEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pLabelInfo"], pLabelInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    WriteApiCallToFile(call_info, "vkCreateDebugUtilsMessengerEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pMessenger"], pMessenger, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyDebugUtilsMessengerEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["messenger"], to_hex(messenger), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    WriteApiCallToFile(call_info, "vkSubmitDebugUtilsMessageEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["messageSeverity"], messageSeverity, json_options_);
            FieldToJson(VkDebugUtilsMessageTypeFlagsEXT_t(), parameters["messageTypes"], messageTypes, json_options_);
            FieldToJson(parameters["pCallbackData"], pCallbackData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetAndroidHardwareBufferPropertiesANDROID",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["buffer"], buffer, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    WriteApiCallToFile(call_info, "vkGetMemoryAndroidHardwareBufferANDROID",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pBuffer"], pBuffer, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetSampleLocationsEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pSampleLocationsInfo"], pSampleLocationsInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceMultisamplePropertiesEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["samples"], samples, json_options_);
            FieldToJson(parameters["pMultisampleProperties"], pMultisampleProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetImageDrmFormatModifierPropertiesEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["image"], to_hex(image), json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    WriteApiCallToFile(call_info, "vkCreateValidationCacheEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pValidationCache"], pValidationCache, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyValidationCacheEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["validationCache"], to_hex(validationCache), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches)
{
    WriteApiCallToFile(call_info, "vkMergeValidationCachesEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["dstCache"], to_hex(dstCache), json_options_);
            FieldToJson(parameters["srcCacheCount"], srcCacheCount, json_options_);
            FieldToJson(parameters["pSrcCaches"], pSrcCaches, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    WriteApiCallToFile(call_info, "vkGetValidationCacheDataEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["validationCache"], to_hex(validationCache), json_options_);
            FieldToJson(parameters["pDataSize"], pDataSize, json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    WriteApiCallToFile(call_info, "vkCmdBindShadingRateImageNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["imageView"], to_hex(imageView), json_options_);
            FieldToJson(parameters["imageLayout"], imageLayout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewportShadingRatePaletteNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstViewport"], firstViewport, json_options_);
            FieldToJson(parameters["viewportCount"], viewportCount, json_options_);
            FieldToJson(parameters["pShadingRatePalettes"], pShadingRatePalettes, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoarseSampleOrderNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["sampleOrderType"], sampleOrderType, json_options_);
            FieldToJson(parameters["customSampleOrderCount"], customSampleOrderCount, json_options_);
            FieldToJson(parameters["pCustomSampleOrders"], pCustomSampleOrders, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    WriteApiCallToFile(call_info, "vkCreateAccelerationStructureNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pAccelerationStructure"], pAccelerationStructure, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyAccelerationStructureNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["accelerationStructure"], to_hex(accelerationStructure), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureMemoryRequirementsNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos)
{
    WriteApiCallToFile(call_info, "vkBindAccelerationStructureMemoryNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["bindInfoCount"], bindInfoCount, json_options_);
            FieldToJson(parameters["pBindInfos"], pBindInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBuildAccelerationStructureNV(
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
    WriteApiCallToFile(call_info, "vkCmdBuildAccelerationStructureNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["instanceData"], to_hex(instanceData), json_options_);
            FieldToJson(parameters["instanceOffset"], instanceOffset, json_options_);
            FieldToJson(parameters["update"], update, json_options_);
            FieldToJson(parameters["dst"], to_hex(dst), json_options_);
            FieldToJson(parameters["src"], to_hex(src), json_options_);
            FieldToJson(parameters["scratch"], to_hex(scratch), json_options_);
            FieldToJson(parameters["scratchOffset"], scratchOffset, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    WriteApiCallToFile(call_info, "vkCmdCopyAccelerationStructureNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["dst"], to_hex(dst), json_options_);
            FieldToJson(parameters["src"], to_hex(src), json_options_);
            FieldToJson(parameters["mode"], mode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysNV(
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
    WriteApiCallToFile(call_info, "vkCmdTraceRaysNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["raygenShaderBindingTableBuffer"], to_hex(raygenShaderBindingTableBuffer), json_options_);
            FieldToJson(parameters["raygenShaderBindingOffset"], raygenShaderBindingOffset, json_options_);
            FieldToJson(parameters["missShaderBindingTableBuffer"], to_hex(missShaderBindingTableBuffer), json_options_);
            FieldToJson(parameters["missShaderBindingOffset"], missShaderBindingOffset, json_options_);
            FieldToJson(parameters["missShaderBindingStride"], missShaderBindingStride, json_options_);
            FieldToJson(parameters["hitShaderBindingTableBuffer"], to_hex(hitShaderBindingTableBuffer), json_options_);
            FieldToJson(parameters["hitShaderBindingOffset"], hitShaderBindingOffset, json_options_);
            FieldToJson(parameters["hitShaderBindingStride"], hitShaderBindingStride, json_options_);
            FieldToJson(parameters["callableShaderBindingTableBuffer"], to_hex(callableShaderBindingTableBuffer), json_options_);
            FieldToJson(parameters["callableShaderBindingOffset"], callableShaderBindingOffset, json_options_);
            FieldToJson(parameters["callableShaderBindingStride"], callableShaderBindingStride, json_options_);
            FieldToJson(parameters["width"], width, json_options_);
            FieldToJson(parameters["height"], height, json_options_);
            FieldToJson(parameters["depth"], depth, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateRayTracingPipelinesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    WriteApiCallToFile(call_info, "vkCreateRayTracingPipelinesNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipelineCache"], to_hex(pipelineCache), json_options_);
            FieldToJson(parameters["createInfoCount"], createInfoCount, json_options_);
            FieldToJson(parameters["pCreateInfos"], pCreateInfos, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pPipelines"], pPipelines, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    WriteApiCallToFile(call_info, "vkGetRayTracingShaderGroupHandlesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipeline"], to_hex(pipeline), json_options_);
            FieldToJson(parameters["firstGroup"], firstGroup, json_options_);
            FieldToJson(parameters["groupCount"], groupCount, json_options_);
            FieldToJson(parameters["dataSize"], dataSize, json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    WriteApiCallToFile(call_info, "vkGetRayTracingShaderGroupHandlesNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipeline"], to_hex(pipeline), json_options_);
            FieldToJson(parameters["firstGroup"], firstGroup, json_options_);
            FieldToJson(parameters["groupCount"], groupCount, json_options_);
            FieldToJson(parameters["dataSize"], dataSize, json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureHandleNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["accelerationStructure"], to_hex(accelerationStructure), json_options_);
            FieldToJson(parameters["dataSize"], dataSize, json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    WriteApiCallToFile(call_info, "vkCmdWriteAccelerationStructuresPropertiesNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["accelerationStructureCount"], accelerationStructureCount, json_options_);
            FieldToJson(parameters["pAccelerationStructures"], pAccelerationStructures, json_options_);
            FieldToJson(parameters["queryType"], queryType, json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["firstQuery"], firstQuery, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCompileDeferredNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    WriteApiCallToFile(call_info, "vkCompileDeferredNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipeline"], to_hex(pipeline), json_options_);
            FieldToJson(parameters["shader"], shader, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    WriteApiCallToFile(call_info, "vkGetMemoryHostPointerPropertiesEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["handleType"], handleType, json_options_);
            FieldToJson(parameters["pHostPointer"], pHostPointer, json_options_);
            FieldToJson(parameters["pMemoryHostPointerProperties"], pMemoryHostPointerProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    WriteApiCallToFile(call_info, "vkCmdWriteBufferMarkerAMD",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pipelineStage"], pipelineStage, json_options_);
            FieldToJson(parameters["dstBuffer"], to_hex(dstBuffer), json_options_);
            FieldToJson(parameters["dstOffset"], dstOffset, json_options_);
            FieldToJson(parameters["marker"], marker, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pTimeDomainCount"], pTimeDomainCount, json_options_);
            FieldToJson(parameters["pTimeDomains"], pTimeDomains, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    WriteApiCallToFile(call_info, "vkGetCalibratedTimestampsEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["timestampCount"], timestampCount, json_options_);
            FieldToJson(parameters["pTimestampInfos"], pTimestampInfos, json_options_);
            FieldToJson(parameters["pTimestamps"], pTimestamps, json_options_);
            FieldToJson(parameters["pMaxDeviation"], pMaxDeviation, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["taskCount"], taskCount, json_options_);
            FieldToJson(parameters["firstTask"], firstTask, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksIndirectNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["drawCount"], drawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksIndirectCountNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["countBuffer"], to_hex(countBuffer), json_options_);
            FieldToJson(parameters["countBufferOffset"], countBufferOffset, json_options_);
            FieldToJson(parameters["maxDrawCount"], maxDrawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    PointerDecoder<VkBool32>*                   pExclusiveScissorEnables)
{
    WriteApiCallToFile(call_info, "vkCmdSetExclusiveScissorEnableNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstExclusiveScissor"], firstExclusiveScissor, json_options_);
            FieldToJson(parameters["exclusiveScissorCount"], exclusiveScissorCount, json_options_);
            FieldToJson(parameters["pExclusiveScissorEnables"], pExclusiveScissorEnables, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    WriteApiCallToFile(call_info, "vkCmdSetExclusiveScissorNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstExclusiveScissor"], firstExclusiveScissor, json_options_);
            FieldToJson(parameters["exclusiveScissorCount"], exclusiveScissorCount, json_options_);
            FieldToJson(parameters["pExclusiveScissors"], pExclusiveScissors, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    WriteApiCallToFile(call_info, "vkCmdSetCheckpointNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pCheckpointMarker"], pCheckpointMarker, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    WriteApiCallToFile(call_info, "vkGetQueueCheckpointDataNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            FieldToJson(parameters["pCheckpointDataCount"], pCheckpointDataCount, json_options_);
            FieldToJson(parameters["pCheckpointData"], pCheckpointData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    WriteApiCallToFile(call_info, "vkInitializePerformanceApiINTEL",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInitializeInfo"], pInitializeInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    WriteApiCallToFile(call_info, "vkUninitializePerformanceApiINTEL",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetPerformanceMarkerINTEL",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pMarkerInfo"], pMarkerInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetPerformanceStreamMarkerINTEL",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pMarkerInfo"], pMarkerInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    WriteApiCallToFile(call_info, "vkCmdSetPerformanceOverrideINTEL",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pOverrideInfo"], pOverrideInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    WriteApiCallToFile(call_info, "vkAcquirePerformanceConfigurationINTEL",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pAcquireInfo"], pAcquireInfo, json_options_);
            FieldToJson(parameters["pConfiguration"], pConfiguration, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    WriteApiCallToFile(call_info, "vkReleasePerformanceConfigurationINTEL",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["configuration"], to_hex(configuration), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    WriteApiCallToFile(call_info, "vkQueueSetPerformanceConfigurationINTEL",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["queue"], to_hex(queue), json_options_);
            FieldToJson(parameters["configuration"], to_hex(configuration), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    WriteApiCallToFile(call_info, "vkGetPerformanceParameterINTEL",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["parameter"], parameter, json_options_);
            FieldToJson(parameters["pValue"], pValue, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    WriteApiCallToFile(call_info, "vkSetLocalDimmingAMD",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapChain"], to_hex(swapChain), json_options_);
            FieldToJson(parameters["localDimmingEnable"], localDimmingEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateImagePipeSurfaceFUCHSIA",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateMetalSurfaceEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetBufferDeviceAddressEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], to_hex(returnValue), json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceToolPropertiesEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pToolCount"], pToolCount, json_options_);
            FieldToJson(parameters["pToolProperties"], pToolProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pPropertyCount"], pPropertyCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pCombinationCount"], pCombinationCount, json_options_);
            FieldToJson(parameters["pCombinations"], pCombinations, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceSurfacePresentModes2EXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pSurfaceInfo"], pSurfaceInfo, json_options_);
            FieldToJson(parameters["pPresentModeCount"], pPresentModeCount, json_options_);
            FieldToJson(parameters["pPresentModes"], pPresentModes, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    WriteApiCallToFile(call_info, "vkAcquireFullScreenExclusiveModeEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchain"], to_hex(swapchain), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    WriteApiCallToFile(call_info, "vkReleaseFullScreenExclusiveModeEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["swapchain"], to_hex(swapchain), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    WriteApiCallToFile(call_info, "vkGetDeviceGroupSurfacePresentModes2EXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pSurfaceInfo"], pSurfaceInfo, json_options_);
            FieldToJson(parameters["pModes"], pModes, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateHeadlessSurfaceEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    WriteApiCallToFile(call_info, "vkCmdSetLineStippleEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["lineStippleFactor"], lineStippleFactor, json_options_);
            FieldToJson(parameters["lineStipplePattern"], lineStipplePattern, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    WriteApiCallToFile(call_info, "vkResetQueryPoolEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["firstQuery"], firstQuery, json_options_);
            FieldToJson(parameters["queryCount"], queryCount, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetCullModeEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkCullModeFlags_t(), parameters["cullMode"], cullMode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    WriteApiCallToFile(call_info, "vkCmdSetFrontFaceEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["frontFace"], frontFace, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveTopologyEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["primitiveTopology"], primitiveTopology, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewportWithCountEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["viewportCount"], viewportCount, json_options_);
            FieldToJson(parameters["pViewports"], pViewports, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    WriteApiCallToFile(call_info, "vkCmdSetScissorWithCountEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["scissorCount"], scissorCount, json_options_);
            FieldToJson(parameters["pScissors"], pScissors, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    WriteApiCallToFile(call_info, "vkCmdBindVertexBuffers2EXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstBinding"], firstBinding, json_options_);
            FieldToJson(parameters["bindingCount"], bindingCount, json_options_);
            FieldToJson(parameters["pBuffers"], pBuffers, json_options_);
            FieldToJson(parameters["pOffsets"], pOffsets, json_options_);
            FieldToJson(parameters["pSizes"], pSizes, json_options_);
            FieldToJson(parameters["pStrides"], pStrides, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthTestEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthTestEnable"], depthTestEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthWriteEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthWriteEnable"], depthWriteEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthCompareOpEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthCompareOp"], depthCompareOp, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthBoundsTestEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthBoundsTestEnable"], depthBoundsTestEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetStencilTestEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["stencilTestEnable"], stencilTestEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    WriteApiCallToFile(call_info, "vkCmdSetStencilOpEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(VkStencilFaceFlags_t(), parameters["faceMask"], faceMask, json_options_);
            FieldToJson(parameters["failOp"], failOp, json_options_);
            FieldToJson(parameters["passOp"], passOp, json_options_);
            FieldToJson(parameters["depthFailOp"], depthFailOp, json_options_);
            FieldToJson(parameters["compareOp"], compareOp, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo)
{
    WriteApiCallToFile(call_info, "vkReleaseSwapchainImagesEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pReleaseInfo"], pReleaseInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    WriteApiCallToFile(call_info, "vkGetGeneratedCommandsMemoryRequirementsNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            FieldToJson(parameters["pMemoryRequirements"], pMemoryRequirements, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    WriteApiCallToFile(call_info, "vkCmdPreprocessGeneratedCommandsNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pGeneratedCommandsInfo"], pGeneratedCommandsInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    WriteApiCallToFile(call_info, "vkCmdExecuteGeneratedCommandsNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["isPreprocessed"], isPreprocessed, json_options_);
            FieldToJson(parameters["pGeneratedCommandsInfo"], pGeneratedCommandsInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    WriteApiCallToFile(call_info, "vkCmdBindPipelineShaderGroupNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pipelineBindPoint"], pipelineBindPoint, json_options_);
            FieldToJson(parameters["pipeline"], to_hex(pipeline), json_options_);
            FieldToJson(parameters["groupIndex"], groupIndex, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    WriteApiCallToFile(call_info, "vkCreateIndirectCommandsLayoutNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pIndirectCommandsLayout"], pIndirectCommandsLayout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyIndirectCommandsLayoutNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["indirectCommandsLayout"], to_hex(indirectCommandsLayout), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    format::HandleId                            display)
{
    WriteApiCallToFile(call_info, "vkAcquireDrmDisplayEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["drmFd"], drmFd, json_options_);
            FieldToJson(parameters["display"], to_hex(display), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    HandlePointerDecoder<VkDisplayKHR>*         display)
{
    WriteApiCallToFile(call_info, "vkGetDrmDisplayEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["drmFd"], drmFd, json_options_);
            FieldToJson(parameters["connectorId"], connectorId, json_options_);
            FieldToJson(parameters["display"], display, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    WriteApiCallToFile(call_info, "vkCreatePrivateDataSlotEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pPrivateDataSlot"], pPrivateDataSlot, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyPrivateDataSlotEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["privateDataSlot"], to_hex(privateDataSlot), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    WriteApiCallToFile(call_info, "vkSetPrivateDataEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["objectType"], objectType, json_options_);
            FieldToJson(parameters["objectHandle"], objectHandle, json_options_);
            FieldToJson(parameters["privateDataSlot"], to_hex(privateDataSlot), json_options_);
            FieldToJson(parameters["data"], data, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    WriteApiCallToFile(call_info, "vkGetPrivateDataEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["objectType"], objectType, json_options_);
            FieldToJson(parameters["objectHandle"], objectHandle, json_options_);
            FieldToJson(parameters["privateDataSlot"], to_hex(privateDataSlot), json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    WriteApiCallToFile(call_info, "vkCmdSetFragmentShadingRateEnumNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["shadingRate"], shadingRate, json_options_);
            FieldToJson(parameters["combinerOps"], combinerOps, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2EXT>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2EXT>* pLayout)
{
    WriteApiCallToFile(call_info, "vkGetImageSubresourceLayout2EXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["image"], to_hex(image), json_options_);
            FieldToJson(parameters["pSubresource"], pSubresource, json_options_);
            FieldToJson(parameters["pLayout"], pLayout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts,
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo)
{
    WriteApiCallToFile(call_info, "vkGetDeviceFaultInfoEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pFaultCounts"], pFaultCounts, json_options_);
            FieldToJson(parameters["pFaultInfo"], pFaultInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    WriteApiCallToFile(call_info, "vkAcquireWinrtDisplayNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["display"], to_hex(display), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    WriteApiCallToFile(call_info, "vkGetWinrtDisplayNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["deviceRelativeId"], deviceRelativeId, json_options_);
            FieldToJson(parameters["pDisplay"], pDisplay, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateDirectFBSurfaceEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["queueFamilyIndex"], queueFamilyIndex, json_options_);
            FieldToJson(parameters["dfb"], dfb, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    WriteApiCallToFile(call_info, "vkCmdSetVertexInputEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["vertexBindingDescriptionCount"], vertexBindingDescriptionCount, json_options_);
            FieldToJson(parameters["pVertexBindingDescriptions"], pVertexBindingDescriptions, json_options_);
            FieldToJson(parameters["vertexAttributeDescriptionCount"], vertexAttributeDescriptionCount, json_options_);
            FieldToJson(parameters["pVertexAttributeDescriptions"], pVertexAttributeDescriptions, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    WriteApiCallToFile(call_info, "vkGetMemoryZirconHandleFUCHSIA",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pGetZirconHandleInfo"], pGetZirconHandleInfo, json_options_);
            FieldToJson(parameters["pZirconHandle"], pZirconHandle, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint32_t                                    zirconHandle,
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties)
{
    WriteApiCallToFile(call_info, "vkGetMemoryZirconHandlePropertiesFUCHSIA",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["handleType"], handleType, json_options_);
            FieldToJson(parameters["zirconHandle"], zirconHandle, json_options_);
            FieldToJson(parameters["pMemoryZirconHandleProperties"], pMemoryZirconHandleProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    WriteApiCallToFile(call_info, "vkImportSemaphoreZirconHandleFUCHSIA",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pImportSemaphoreZirconHandleInfo"], pImportSemaphoreZirconHandleInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    WriteApiCallToFile(call_info, "vkGetSemaphoreZirconHandleFUCHSIA",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pGetZirconHandleInfo"], pGetZirconHandleInfo, json_options_);
            FieldToJson(parameters["pZirconHandle"], pZirconHandle, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    WriteApiCallToFile(call_info, "vkCmdBindInvocationMaskHUAWEI",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["imageView"], to_hex(imageView), json_options_);
            FieldToJson(parameters["imageLayout"], imageLayout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo,
    PointerDecoder<uint64_t, void*>*            pAddress)
{
    WriteApiCallToFile(call_info, "vkGetMemoryRemoteAddressNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pMemoryGetRemoteAddressInfo"], pMemoryGetRemoteAddressInfo, json_options_);
            FieldToJson(parameters["pAddress"], pAddress, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    WriteApiCallToFile(call_info, "vkCmdSetPatchControlPointsEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["patchControlPoints"], patchControlPoints, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetRasterizerDiscardEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["rasterizerDiscardEnable"], rasterizerDiscardEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthBiasEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthBiasEnable"], depthBiasEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    WriteApiCallToFile(call_info, "vkCmdSetLogicOpEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["logicOp"], logicOp, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetPrimitiveRestartEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["primitiveRestartEnable"], primitiveRestartEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    WriteApiCallToFile(call_info, "vkCreateScreenSurfaceQNX",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["instance"], to_hex(instance), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSurface"], pSurface, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    window)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceScreenPresentationSupportQNX",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["queueFamilyIndex"], queueFamilyIndex, json_options_);
            FieldToJson(parameters["window"], window, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    WriteApiCallToFile(call_info, "vkCmdSetColorWriteEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["attachmentCount"], attachmentCount, json_options_);
            FieldToJson(parameters["pColorWriteEnables"], pColorWriteEnables, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMultiEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["drawCount"], drawCount, json_options_);
            FieldToJson(parameters["pVertexInfo"], pVertexInfo, json_options_);
            FieldToJson(parameters["instanceCount"], instanceCount, json_options_);
            FieldToJson(parameters["firstInstance"], firstInstance, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    PointerDecoder<int32_t>*                    pVertexOffset)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMultiIndexedEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["drawCount"], drawCount, json_options_);
            FieldToJson(parameters["pIndexInfo"], pIndexInfo, json_options_);
            FieldToJson(parameters["instanceCount"], instanceCount, json_options_);
            FieldToJson(parameters["firstInstance"], firstInstance, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            FieldToJson(parameters["pVertexOffset"], pVertexOffset, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromap)
{
    WriteApiCallToFile(call_info, "vkCreateMicromapEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pMicromap"], pMicromap, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyMicromapEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["micromap"], to_hex(micromap), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    WriteApiCallToFile(call_info, "vkCmdBuildMicromapsEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["infoCount"], infoCount, json_options_);
            FieldToJson(parameters["pInfos"], pInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    WriteApiCallToFile(call_info, "vkBuildMicromapsEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["deferredOperation"], to_hex(deferredOperation), json_options_);
            FieldToJson(parameters["infoCount"], infoCount, json_options_);
            FieldToJson(parameters["pInfos"], pInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCopyMicromapEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["deferredOperation"], to_hex(deferredOperation), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCopyMicromapToMemoryEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["deferredOperation"], to_hex(deferredOperation), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCopyMemoryToMicromapEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["deferredOperation"], to_hex(deferredOperation), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkWriteMicromapsPropertiesEXT(
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
    WriteApiCallToFile(call_info, "vkWriteMicromapsPropertiesEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["micromapCount"], micromapCount, json_options_);
            FieldToJson(parameters["pMicromaps"], pMicromaps, json_options_);
            FieldToJson(parameters["queryType"], queryType, json_options_);
            FieldToJson(parameters["dataSize"], dataSize, json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyMicromapEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyMicromapToMemoryEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyMemoryToMicromapEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    WriteApiCallToFile(call_info, "vkCmdWriteMicromapsPropertiesEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["micromapCount"], micromapCount, json_options_);
            FieldToJson(parameters["pMicromaps"], pMicromaps, json_options_);
            FieldToJson(parameters["queryType"], queryType, json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["firstQuery"], firstQuery, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    WriteApiCallToFile(call_info, "vkGetDeviceMicromapCompatibilityEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pVersionInfo"], pVersionInfo, json_options_);
            FieldToJson(parameters["pCompatibility"], pCompatibility, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetMicromapBuildSizesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo,
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo)
{
    WriteApiCallToFile(call_info, "vkGetMicromapBuildSizesEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["buildType"], buildType, json_options_);
            FieldToJson(parameters["pBuildInfo"], pBuildInfo, json_options_);
            FieldToJson(parameters["pSizeInfo"], pSizeInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    WriteApiCallToFile(call_info, "vkCmdDrawClusterHUAWEI",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["groupCountX"], groupCountX, json_options_);
            FieldToJson(parameters["groupCountY"], groupCountY, json_options_);
            FieldToJson(parameters["groupCountZ"], groupCountZ, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    WriteApiCallToFile(call_info, "vkCmdDrawClusterIndirectHUAWEI",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    WriteApiCallToFile(call_info, "vkSetDeviceMemoryPriorityEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["memory"], to_hex(memory), json_options_);
            FieldToJson(parameters["priority"], priority, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping)
{
    WriteApiCallToFile(call_info, "vkGetDescriptorSetLayoutHostMappingInfoVALVE",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pBindingReference"], pBindingReference, json_options_);
            FieldToJson(parameters["pHostMapping"], pHostMapping, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    WriteApiCallToFile(call_info, "vkGetDescriptorSetHostMappingVALVE",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["descriptorSet"], to_hex(descriptorSet), json_options_);
            FieldToJson(parameters["ppData"], ppData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    WriteApiCallToFile(call_info, "vkCmdSetTessellationDomainOriginEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["domainOrigin"], domainOrigin, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthClampEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthClampEnable"], depthClampEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetPolygonModeEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["polygonMode"], polygonMode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    WriteApiCallToFile(call_info, "vkCmdSetRasterizationSamplesEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["rasterizationSamples"], rasterizationSamples, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    WriteApiCallToFile(call_info, "vkCmdSetSampleMaskEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["samples"], samples, json_options_);
            FieldToJson(parameters["pSampleMask"], pSampleMask, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetAlphaToCoverageEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["alphaToCoverageEnable"], alphaToCoverageEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetAlphaToOneEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["alphaToOneEnable"], alphaToOneEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetLogicOpEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["logicOpEnable"], logicOpEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorBlendEnables)
{
    WriteApiCallToFile(call_info, "vkCmdSetColorBlendEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstAttachment"], firstAttachment, json_options_);
            FieldToJson(parameters["attachmentCount"], attachmentCount, json_options_);
            FieldToJson(parameters["pColorBlendEnables"], pColorBlendEnables, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations)
{
    WriteApiCallToFile(call_info, "vkCmdSetColorBlendEquationEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstAttachment"], firstAttachment, json_options_);
            FieldToJson(parameters["attachmentCount"], attachmentCount, json_options_);
            FieldToJson(parameters["pColorBlendEquations"], pColorBlendEquations, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks)
{
    WriteApiCallToFile(call_info, "vkCmdSetColorWriteMaskEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstAttachment"], firstAttachment, json_options_);
            FieldToJson(parameters["attachmentCount"], attachmentCount, json_options_);
            FieldToJson(parameters["pColorWriteMasks"], pColorWriteMasks, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    WriteApiCallToFile(call_info, "vkCmdSetRasterizationStreamEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["rasterizationStream"], rasterizationStream, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetConservativeRasterizationModeEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["conservativeRasterizationMode"], conservativeRasterizationMode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    WriteApiCallToFile(call_info, "vkCmdSetExtraPrimitiveOverestimationSizeEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["extraPrimitiveOverestimationSize"], extraPrimitiveOverestimationSize, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthClipEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["depthClipEnable"], depthClipEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetSampleLocationsEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["sampleLocationsEnable"], sampleLocationsEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced)
{
    WriteApiCallToFile(call_info, "vkCmdSetColorBlendAdvancedEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstAttachment"], firstAttachment, json_options_);
            FieldToJson(parameters["attachmentCount"], attachmentCount, json_options_);
            FieldToJson(parameters["pColorBlendAdvanced"], pColorBlendAdvanced, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetProvokingVertexModeEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["provokingVertexMode"], provokingVertexMode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetLineRasterizationModeEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["lineRasterizationMode"], lineRasterizationMode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetLineStippleEnableEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["stippledLineEnable"], stippledLineEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    WriteApiCallToFile(call_info, "vkCmdSetDepthClipNegativeOneToOneEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["negativeOneToOne"], negativeOneToOne, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewportWScalingEnableNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["viewportWScalingEnable"], viewportWScalingEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles)
{
    WriteApiCallToFile(call_info, "vkCmdSetViewportSwizzleNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["firstViewport"], firstViewport, json_options_);
            FieldToJson(parameters["viewportCount"], viewportCount, json_options_);
            FieldToJson(parameters["pViewportSwizzles"], pViewportSwizzles, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageToColorEnableNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["coverageToColorEnable"], coverageToColorEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageToColorLocationNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["coverageToColorLocation"], coverageToColorLocation, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageModulationModeNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["coverageModulationMode"], coverageModulationMode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageModulationTableEnableNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["coverageModulationTableEnable"], coverageModulationTableEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageModulationTableNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["coverageModulationTableCount"], coverageModulationTableCount, json_options_);
            FieldToJson(parameters["pCoverageModulationTable"], pCoverageModulationTable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetShadingRateImageEnableNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["shadingRateImageEnable"], shadingRateImageEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    WriteApiCallToFile(call_info, "vkCmdSetRepresentativeFragmentTestEnableNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["representativeFragmentTestEnable"], representativeFragmentTestEnable, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    WriteApiCallToFile(call_info, "vkCmdSetCoverageReductionModeNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["coverageReductionMode"], coverageReductionMode, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    WriteApiCallToFile(call_info, "vkGetShaderModuleIdentifierEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["shaderModule"], to_hex(shaderModule), json_options_);
            FieldToJson(parameters["pIdentifier"], pIdentifier, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    WriteApiCallToFile(call_info, "vkGetShaderModuleCreateInfoIdentifierEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pIdentifier"], pIdentifier, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo,
    PointerDecoder<uint32_t>*                   pFormatCount,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties)
{
    WriteApiCallToFile(call_info, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["physicalDevice"], to_hex(physicalDevice), json_options_);
            FieldToJson(parameters["pOpticalFlowImageFormatInfo"], pOpticalFlowImageFormatInfo, json_options_);
            FieldToJson(parameters["pFormatCount"], pFormatCount, json_options_);
            FieldToJson(parameters["pImageFormatProperties"], pImageFormatProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession)
{
    WriteApiCallToFile(call_info, "vkCreateOpticalFlowSessionNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pSession"], pSession, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyOpticalFlowSessionNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["session"], to_hex(session), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            session,
    VkOpticalFlowSessionBindingPointNV          bindingPoint,
    format::HandleId                            view,
    VkImageLayout                               layout)
{
    WriteApiCallToFile(call_info, "vkBindOpticalFlowSessionImageNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["session"], to_hex(session), json_options_);
            FieldToJson(parameters["bindingPoint"], bindingPoint, json_options_);
            FieldToJson(parameters["view"], to_hex(view), json_options_);
            FieldToJson(parameters["layout"], layout, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    WriteApiCallToFile(call_info, "vkCmdOpticalFlowExecuteNV",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["session"], to_hex(session), json_options_);
            FieldToJson(parameters["pExecuteInfo"], pExecuteInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    PointerDecoder<uint32_t>*                   pPropertiesCount,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetFramebufferTilePropertiesQCOM",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["framebuffer"], to_hex(framebuffer), json_options_);
            FieldToJson(parameters["pPropertiesCount"], pPropertiesCount, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    WriteApiCallToFile(call_info, "vkGetDynamicRenderingTilePropertiesQCOM",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pRenderingInfo"], pRenderingInfo, json_options_);
            FieldToJson(parameters["pProperties"], pProperties, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    WriteApiCallToFile(call_info, "vkCreateAccelerationStructureKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pCreateInfo"], pCreateInfo, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pAccelerationStructure"], pAccelerationStructure, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    WriteApiCallToFile(call_info, "vkDestroyAccelerationStructureKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["accelerationStructure"], to_hex(accelerationStructure), json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos)
{
    WriteApiCallToFile(call_info, "vkCmdBuildAccelerationStructuresKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["infoCount"], infoCount, json_options_);
            FieldToJson(parameters["pInfos"], pInfos, json_options_);
            FieldToJson(parameters["ppBuildRangeInfos"], ppBuildRangeInfos, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCopyAccelerationStructureToMemoryKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["deferredOperation"], to_hex(deferredOperation), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCopyMemoryToAccelerationStructureKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["deferredOperation"], to_hex(deferredOperation), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
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
    WriteApiCallToFile(call_info, "vkWriteAccelerationStructuresPropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["accelerationStructureCount"], accelerationStructureCount, json_options_);
            FieldToJson(parameters["pAccelerationStructures"], pAccelerationStructures, json_options_);
            FieldToJson(parameters["queryType"], queryType, json_options_);
            FieldToJson(parameters["dataSize"], dataSize, json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyAccelerationStructureKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyAccelerationStructureToMemoryKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    WriteApiCallToFile(call_info, "vkCmdCopyMemoryToAccelerationStructureKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureDeviceAddressKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], to_hex(returnValue), json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pInfo"], pInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    WriteApiCallToFile(call_info, "vkCmdWriteAccelerationStructuresPropertiesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["accelerationStructureCount"], accelerationStructureCount, json_options_);
            FieldToJson(parameters["pAccelerationStructures"], pAccelerationStructures, json_options_);
            FieldToJson(parameters["queryType"], queryType, json_options_);
            FieldToJson(parameters["queryPool"], to_hex(queryPool), json_options_);
            FieldToJson(parameters["firstQuery"], firstQuery, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    WriteApiCallToFile(call_info, "vkGetDeviceAccelerationStructureCompatibilityKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pVersionInfo"], pVersionInfo, json_options_);
            FieldToJson(parameters["pCompatibility"], pCompatibility, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
    PointerDecoder<uint32_t>*                   pMaxPrimitiveCounts,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo)
{
    WriteApiCallToFile(call_info, "vkGetAccelerationStructureBuildSizesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["buildType"], buildType, json_options_);
            FieldToJson(parameters["pBuildInfo"], pBuildInfo, json_options_);
            FieldToJson(parameters["pMaxPrimitiveCounts"], pMaxPrimitiveCounts, json_options_);
            FieldToJson(parameters["pSizeInfo"], pSizeInfo, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysKHR(
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
    WriteApiCallToFile(call_info, "vkCmdTraceRaysKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pRaygenShaderBindingTable"], pRaygenShaderBindingTable, json_options_);
            FieldToJson(parameters["pMissShaderBindingTable"], pMissShaderBindingTable, json_options_);
            FieldToJson(parameters["pHitShaderBindingTable"], pHitShaderBindingTable, json_options_);
            FieldToJson(parameters["pCallableShaderBindingTable"], pCallableShaderBindingTable, json_options_);
            FieldToJson(parameters["width"], width, json_options_);
            FieldToJson(parameters["height"], height, json_options_);
            FieldToJson(parameters["depth"], depth, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCreateRayTracingPipelinesKHR(
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
    WriteApiCallToFile(call_info, "vkCreateRayTracingPipelinesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["deferredOperation"], to_hex(deferredOperation), json_options_);
            FieldToJson(parameters["pipelineCache"], to_hex(pipelineCache), json_options_);
            FieldToJson(parameters["createInfoCount"], createInfoCount, json_options_);
            FieldToJson(parameters["pCreateInfos"], pCreateInfos, json_options_);
            FieldToJson(parameters["pAllocator"], pAllocator, json_options_);
            FieldToJson(parameters["pPipelines"], pPipelines, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    WriteApiCallToFile(call_info, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipeline"], to_hex(pipeline), json_options_);
            FieldToJson(parameters["firstGroup"], firstGroup, json_options_);
            FieldToJson(parameters["groupCount"], groupCount, json_options_);
            FieldToJson(parameters["dataSize"], dataSize, json_options_);
            FieldToJson(parameters["pData"], pData, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    WriteApiCallToFile(call_info, "vkCmdTraceRaysIndirectKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pRaygenShaderBindingTable"], pRaygenShaderBindingTable, json_options_);
            FieldToJson(parameters["pMissShaderBindingTable"], pMissShaderBindingTable, json_options_);
            FieldToJson(parameters["pHitShaderBindingTable"], pHitShaderBindingTable, json_options_);
            FieldToJson(parameters["pCallableShaderBindingTable"], pCallableShaderBindingTable, json_options_);
            FieldToJson(parameters["indirectDeviceAddress"], to_hex(indirectDeviceAddress), json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceSize                                returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader)
{
    WriteApiCallToFile(call_info, "vkGetRayTracingShaderGroupStackSizeKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata[NameReturn()], returnValue, json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["device"], to_hex(device), json_options_);
            FieldToJson(parameters["pipeline"], to_hex(pipeline), json_options_);
            FieldToJson(parameters["group"], group, json_options_);
            FieldToJson(parameters["groupShader"], groupShader, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    WriteApiCallToFile(call_info, "vkCmdSetRayTracingPipelineStackSizeKHR",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["pipelineStackSize"], pipelineStackSize, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["groupCountX"], groupCountX, json_options_);
            FieldToJson(parameters["groupCountY"], groupCountY, json_options_);
            FieldToJson(parameters["groupCountZ"], groupCountZ, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksIndirectEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["drawCount"], drawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    WriteApiCallToFile(call_info, "vkCmdDrawMeshTasksIndirectCountEXT",
        [&](auto& jdata)
        {
            FieldToJson(jdata["rec_command_index"], GetCommandBufferRecordIndex(commandBuffer), json_options_);
            FieldToJson(jdata[NameReturn()], "void", json_options_);
            auto parameters = jdata[NameArgs()];
            FieldToJson(parameters["commandBuffer"], to_hex(commandBuffer), json_options_);
            FieldToJson(parameters["buffer"], to_hex(buffer), json_options_);
            FieldToJson(parameters["offset"], offset, json_options_);
            FieldToJson(parameters["countBuffer"], to_hex(countBuffer), json_options_);
            FieldToJson(parameters["countBufferOffset"], countBufferOffset, json_options_);
            FieldToJson(parameters["maxDrawCount"], maxDrawCount, json_options_);
            FieldToJson(parameters["stride"], stride, json_options_);
            jdata[NameArgs()] = parameters;
        }
    );
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
