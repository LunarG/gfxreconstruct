/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
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

#include "util/defines.h"
#include "generated/generated_vulkan_json_consumer.h"
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

using util::FieldToJson;
using util::HandleToJson;
using util::Bool32ToJson;

void VulkanExportJsonConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateInstance");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pInstance"], pInstance);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyInstance");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEnumeratePhysicalDevices");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pPhysicalDeviceCount"], pPhysicalDeviceCount);
        HandleToJson(args["pPhysicalDevices"], pPhysicalDevices);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pFeatures"], pFeatures);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFormatProperties");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["format"] = format;
        FieldToJson(args["pFormatProperties"], pFormatProperties);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceImageFormatProperties");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["format"] = format;
        args["type"] = type;
        args["tiling"] = tiling;
        args["usage"] = VkImageUsageFlags_t{usage};
        args["flags"] = VkImageCreateFlags_t{flags};
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyProperties");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount);
        FieldToJson(args["pQueueFamilyProperties"], pQueueFamilyProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pMemoryProperties"], pMemoryProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDevice");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pDevice"], pDevice);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDevice");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceQueue");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["queueFamilyIndex"] = queueFamilyIndex;
        args["queueIndex"] = queueIndex;
        HandleToJson(args["pQueue"], pQueue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSubmit(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
    format::HandleId                            fence)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSubmit");
    jdata[NameSubmitIndex()] = ++submit_index_;
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        args["submitCount"] = submitCount;
        FieldToJson(args["pSubmits"], pSubmits);
        HandleToJson(args["fence"], fence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueWaitIdle");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDeviceWaitIdle");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAllocateMemory");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pAllocateInfo"], pAllocateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pMemory"], pMemory);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFreeMemory");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["memory"], memory);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMapMemory");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["memory"], memory);
        args["offset"] = offset;
        args["size"] = size;
        args["flags"] = VkMemoryMapFlags_t{flags};
        FieldToJsonAsHex(args["ppData"], ppData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUnmapMemory");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["memory"], memory);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFlushMappedMemoryRanges");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["memoryRangeCount"] = memoryRangeCount;
        FieldToJson(args["pMemoryRanges"], pMemoryRanges);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkInvalidateMappedMemoryRanges");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["memoryRangeCount"] = memoryRangeCount;
        FieldToJson(args["pMemoryRanges"], pMemoryRanges);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryCommitment");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["memory"], memory);
        FieldToJson(args["pCommittedMemoryInBytes"], pCommittedMemoryInBytes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindBufferMemory");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["buffer"], buffer);
        HandleToJson(args["memory"], memory);
        args["memoryOffset"] = memoryOffset;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindImageMemory");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["image"], image);
        HandleToJson(args["memory"], memory);
        args["memoryOffset"] = memoryOffset;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferMemoryRequirements");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["buffer"], buffer);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageMemoryRequirements");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["image"], image);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSparseMemoryRequirements");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["image"], image);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["format"] = format;
        args["type"] = type;
        args["samples"] = samples;
        args["usage"] = VkImageUsageFlags_t{usage};
        args["tiling"] = tiling;
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueBindSparse");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        args["bindInfoCount"] = bindInfoCount;
        FieldToJson(args["pBindInfo"], pBindInfo);
        HandleToJson(args["fence"], fence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateFence");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pFence"], pFence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyFence");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["fence"], fence);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetFences");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["fenceCount"] = fenceCount;
        HandleToJson(args["pFences"], pFences);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetFenceStatus");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["fence"], fence);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWaitForFences");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["fenceCount"] = fenceCount;
        HandleToJson(args["pFences"], pFences);
        Bool32ToJson(args["waitAll"], waitAll);
        args["timeout"] = timeout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSemaphore");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSemaphore"], pSemaphore);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySemaphore");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["semaphore"], semaphore);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateQueryPool");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pQueryPool"], pQueryPool);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyQueryPool");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["queryPool"], queryPool);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetQueryPoolResults");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["queryPool"], queryPool);
        args["firstQuery"] = firstQuery;
        args["queryCount"] = queryCount;
        args["dataSize"] = dataSize;
        FieldToJson(args["pData"], pData);
        args["stride"] = stride;
        args["flags"] = VkQueryResultFlags_t{flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateBuffer");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pBuffer"], pBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyBuffer");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["buffer"], buffer);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateImage");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pImage"], pImage);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyImage");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["image"], image);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSubresourceLayout");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["image"], image);
        FieldToJson(args["pSubresource"], pSubresource);
        FieldToJson(args["pLayout"], pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateImageView");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pView"], pView);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyImageView");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["imageView"], imageView);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateCommandPool");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pCommandPool"], pCommandPool);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyCommandPool");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["commandPool"], commandPool);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetCommandPool");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["commandPool"], commandPool);
        args["flags"] = VkCommandPoolResetFlags_t{flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAllocateCommandBuffers");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pAllocateInfo"], pAllocateInfo);
        HandleToJson(args["pCommandBuffers"], pCommandBuffers);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFreeCommandBuffers");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["commandPool"], commandPool);
        args["commandBufferCount"] = commandBufferCount;
        HandleToJson(args["pCommandBuffers"], pCommandBuffers);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBeginCommandBuffer");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pBeginInfo"], pBeginInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEndCommandBuffer");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetCommandBuffer");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["flags"] = VkCommandBufferResetFlags_t{flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBuffer");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["srcBuffer"], srcBuffer);
        HandleToJson(args["dstBuffer"], dstBuffer);
        args["regionCount"] = regionCount;
        FieldToJson(args["pRegions"], pRegions);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImage");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["srcImage"], srcImage);
        args["srcImageLayout"] = srcImageLayout;
        HandleToJson(args["dstImage"], dstImage);
        args["dstImageLayout"] = dstImageLayout;
        args["regionCount"] = regionCount;
        FieldToJson(args["pRegions"], pRegions);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBufferToImage");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["srcBuffer"], srcBuffer);
        HandleToJson(args["dstImage"], dstImage);
        args["dstImageLayout"] = dstImageLayout;
        args["regionCount"] = regionCount;
        FieldToJson(args["pRegions"], pRegions);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToBuffer");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["srcImage"], srcImage);
        args["srcImageLayout"] = srcImageLayout;
        HandleToJson(args["dstBuffer"], dstBuffer);
        args["regionCount"] = regionCount;
        FieldToJson(args["pRegions"], pRegions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdUpdateBuffer");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["dstBuffer"], dstBuffer);
        args["dstOffset"] = dstOffset;
        args["dataSize"] = dataSize;
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdFillBuffer");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["dstBuffer"], dstBuffer);
        args["dstOffset"] = dstOffset;
        args["size"] = size;
        args["data"] = data;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPipelineBarrier");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["srcStageMask"] = VkPipelineStageFlags_t{srcStageMask};
        args["dstStageMask"] = VkPipelineStageFlags_t{dstStageMask};
        args["dependencyFlags"] = VkDependencyFlags_t{dependencyFlags};
        args["memoryBarrierCount"] = memoryBarrierCount;
        FieldToJson(args["pMemoryBarriers"], pMemoryBarriers);
        args["bufferMemoryBarrierCount"] = bufferMemoryBarrierCount;
        FieldToJson(args["pBufferMemoryBarriers"], pBufferMemoryBarriers);
        args["imageMemoryBarrierCount"] = imageMemoryBarrierCount;
        FieldToJson(args["pImageMemoryBarriers"], pImageMemoryBarriers);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginQuery");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["queryPool"], queryPool);
        args["query"] = query;
        args["flags"] = VkQueryControlFlags_t{flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndQuery");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["queryPool"], queryPool);
        args["query"] = query;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetQueryPool");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["queryPool"], queryPool);
        args["firstQuery"] = firstQuery;
        args["queryCount"] = queryCount;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteTimestamp");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineStage"] = pipelineStage;
        HandleToJson(args["queryPool"], queryPool);
        args["query"] = query;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyQueryPoolResults");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["queryPool"], queryPool);
        args["firstQuery"] = firstQuery;
        args["queryCount"] = queryCount;
        HandleToJson(args["dstBuffer"], dstBuffer);
        args["dstOffset"] = dstOffset;
        args["stride"] = stride;
        args["flags"] = VkQueryResultFlags_t{flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdExecuteCommands");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["commandBufferCount"] = commandBufferCount;
        HandleToJson(args["pCommandBuffers"], pCommandBuffers);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateEvent");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pEvent"], pEvent);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyEvent");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["event"], event);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetEventStatus");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["event"], event);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetEvent");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["event"], event);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetEvent");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["event"], event);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateBufferView");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pView"], pView);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyBufferView");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["bufferView"], bufferView);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyShaderModule");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["shaderModule"], shaderModule);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipelineCache");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipelineCache"], pipelineCache);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMergePipelineCaches");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["dstCache"], dstCache);
        args["srcCacheCount"] = srcCacheCount;
        HandleToJson(args["pSrcCaches"], pSrcCaches);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateComputePipelines");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipelineCache"], pipelineCache);
        args["createInfoCount"] = createInfoCount;
        FieldToJson(args["pCreateInfos"], pCreateInfos);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pPipelines"], pPipelines);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipeline");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipeline"], pipeline);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreatePipelineLayout");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pPipelineLayout"], pPipelineLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipelineLayout");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipelineLayout"], pipelineLayout);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSampler");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSampler"], pSampler);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySampler");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["sampler"], sampler);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDescriptorSetLayout");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSetLayout"], pSetLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorSetLayout");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["descriptorSetLayout"], descriptorSetLayout);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDescriptorPool");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pDescriptorPool"], pDescriptorPool);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorPool");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["descriptorPool"], descriptorPool);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetDescriptorPool");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["descriptorPool"], descriptorPool);
        args["flags"] = VkDescriptorPoolResetFlags_t{flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAllocateDescriptorSets");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pAllocateInfo"], pAllocateInfo);
        HandleToJson(args["pDescriptorSets"], pDescriptorSets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFreeDescriptorSets");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["descriptorPool"], descriptorPool);
        args["descriptorSetCount"] = descriptorSetCount;
        HandleToJson(args["pDescriptorSets"], pDescriptorSets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUpdateDescriptorSets");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["descriptorWriteCount"] = descriptorWriteCount;
        FieldToJson(args["pDescriptorWrites"], pDescriptorWrites);
        args["descriptorCopyCount"] = descriptorCopyCount;
        FieldToJson(args["pDescriptorCopies"], pDescriptorCopies);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindPipeline");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineBindPoint"] = pipelineBindPoint;
        HandleToJson(args["pipeline"], pipeline);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorSets");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineBindPoint"] = pipelineBindPoint;
        HandleToJson(args["layout"], layout);
        args["firstSet"] = firstSet;
        args["descriptorSetCount"] = descriptorSetCount;
        HandleToJson(args["pDescriptorSets"], pDescriptorSets);
        args["dynamicOffsetCount"] = dynamicOffsetCount;
        FieldToJson(args["pDynamicOffsets"], pDynamicOffsets);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdClearColorImage");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["image"], image);
        args["imageLayout"] = imageLayout;
        FieldToJson(args["pColor"], pColor);
        args["rangeCount"] = rangeCount;
        FieldToJson(args["pRanges"], pRanges);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatch");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["groupCountX"] = groupCountX;
        args["groupCountY"] = groupCountY;
        args["groupCountZ"] = groupCountZ;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchIndirect");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["event"], event);
        args["stageMask"] = VkPipelineStageFlags_t{stageMask};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["event"], event);
        args["stageMask"] = VkPipelineStageFlags_t{stageMask};
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWaitEvents");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["eventCount"] = eventCount;
        HandleToJson(args["pEvents"], pEvents);
        args["srcStageMask"] = VkPipelineStageFlags_t{srcStageMask};
        args["dstStageMask"] = VkPipelineStageFlags_t{dstStageMask};
        args["memoryBarrierCount"] = memoryBarrierCount;
        FieldToJson(args["pMemoryBarriers"], pMemoryBarriers);
        args["bufferMemoryBarrierCount"] = bufferMemoryBarrierCount;
        FieldToJson(args["pBufferMemoryBarriers"], pBufferMemoryBarriers);
        args["imageMemoryBarrierCount"] = imageMemoryBarrierCount;
        FieldToJson(args["pImageMemoryBarriers"], pImageMemoryBarriers);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateGraphicsPipelines");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipelineCache"], pipelineCache);
        args["createInfoCount"] = createInfoCount;
        FieldToJson(args["pCreateInfos"], pCreateInfos);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pPipelines"], pPipelines);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateFramebuffer");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pFramebuffer"], pFramebuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyFramebuffer");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["framebuffer"], framebuffer);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateRenderPass");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pRenderPass"], pRenderPass);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyRenderPass");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["renderPass"], renderPass);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRenderAreaGranularity");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["renderPass"], renderPass);
        FieldToJson(args["pGranularity"], pGranularity);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewport");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstViewport"] = firstViewport;
        args["viewportCount"] = viewportCount;
        FieldToJson(args["pViewports"], pViewports);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetScissor");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstScissor"] = firstScissor;
        args["scissorCount"] = scissorCount;
        FieldToJson(args["pScissors"], pScissors);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineWidth");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["lineWidth"], lineWidth);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBias");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["depthBiasConstantFactor"], depthBiasConstantFactor);
        FieldToJson(args["depthBiasClamp"], depthBiasClamp);
        FieldToJson(args["depthBiasSlopeFactor"], depthBiasSlopeFactor);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetBlendConstants");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["blendConstants"], blendConstants);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBounds");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["minDepthBounds"], minDepthBounds);
        FieldToJson(args["maxDepthBounds"], maxDepthBounds);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilCompareMask");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["faceMask"] = VkStencilFaceFlags_t{faceMask};
        args["compareMask"] = compareMask;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilWriteMask");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["faceMask"] = VkStencilFaceFlags_t{faceMask};
        args["writeMask"] = writeMask;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilReference");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["faceMask"] = VkStencilFaceFlags_t{faceMask};
        args["reference"] = reference;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindIndexBuffer");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        args["indexType"] = indexType;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindVertexBuffers");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstBinding"] = firstBinding;
        args["bindingCount"] = bindingCount;
        HandleToJson(args["pBuffers"], pBuffers);
        FieldToJson(args["pOffsets"], pOffsets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDraw");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["vertexCount"] = vertexCount;
        args["instanceCount"] = instanceCount;
        args["firstVertex"] = firstVertex;
        args["firstInstance"] = firstInstance;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexed");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["indexCount"] = indexCount;
        args["instanceCount"] = instanceCount;
        args["firstIndex"] = firstIndex;
        args["vertexOffset"] = vertexOffset;
        args["firstInstance"] = firstInstance;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirect");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        args["drawCount"] = drawCount;
        args["stride"] = stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirect");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        args["drawCount"] = drawCount;
        args["stride"] = stride;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBlitImage");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["srcImage"], srcImage);
        args["srcImageLayout"] = srcImageLayout;
        HandleToJson(args["dstImage"], dstImage);
        args["dstImageLayout"] = dstImageLayout;
        args["regionCount"] = regionCount;
        FieldToJson(args["pRegions"], pRegions);
        args["filter"] = filter;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdClearDepthStencilImage");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["image"], image);
        args["imageLayout"] = imageLayout;
        FieldToJson(args["pDepthStencil"], pDepthStencil);
        args["rangeCount"] = rangeCount;
        FieldToJson(args["pRanges"], pRanges);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdClearAttachments");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["attachmentCount"] = attachmentCount;
        FieldToJson(args["pAttachments"], pAttachments);
        args["rectCount"] = rectCount;
        FieldToJson(args["pRects"], pRects);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResolveImage");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["srcImage"], srcImage);
        args["srcImageLayout"] = srcImageLayout;
        HandleToJson(args["dstImage"], dstImage);
        args["dstImageLayout"] = dstImageLayout;
        args["regionCount"] = regionCount;
        FieldToJson(args["pRegions"], pRegions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pRenderPassBegin"], pRenderPassBegin);
        args["contents"] = contents;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["contents"] = contents;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindBufferMemory2");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["bindInfoCount"] = bindInfoCount;
        FieldToJson(args["pBindInfos"], pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindImageMemory2");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["bindInfoCount"] = bindInfoCount;
        FieldToJson(args["pBindInfos"], pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupPeerMemoryFeatures");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["heapIndex"] = heapIndex;
        args["localDeviceIndex"] = localDeviceIndex;
        args["remoteDeviceIndex"] = remoteDeviceIndex;
        FieldToJson(args["pPeerMemoryFeatures"], pPeerMemoryFeatures);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDeviceMask");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["deviceMask"] = deviceMask;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEnumeratePhysicalDeviceGroups");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pPhysicalDeviceGroupCount"], pPhysicalDeviceGroupCount);
        FieldToJson(args["pPhysicalDeviceGroupProperties"], pPhysicalDeviceGroupProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageMemoryRequirements2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferMemoryRequirements2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSparseMemoryRequirements2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pFeatures"], pFeatures);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFormatProperties2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["format"] = format;
        FieldToJson(args["pFormatProperties"], pFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceImageFormatProperties2");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pImageFormatInfo"], pImageFormatInfo);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount);
        FieldToJson(args["pQueueFamilyProperties"], pQueueFamilyProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pMemoryProperties"], pMemoryProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pFormatInfo"], pFormatInfo);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTrimCommandPool");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["commandPool"], commandPool);
        args["flags"] = VkCommandPoolTrimFlags_t{flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceQueue2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pQueueInfo"], pQueueInfo);
        HandleToJson(args["pQueue"], pQueue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalBufferProperties");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pExternalBufferInfo"], pExternalBufferInfo);
        FieldToJson(args["pExternalBufferProperties"], pExternalBufferProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalFenceProperties");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pExternalFenceInfo"], pExternalFenceInfo);
        FieldToJson(args["pExternalFenceProperties"], pExternalFenceProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pExternalSemaphoreInfo"], pExternalSemaphoreInfo);
        FieldToJson(args["pExternalSemaphoreProperties"], pExternalSemaphoreProperties);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchBase");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["baseGroupX"] = baseGroupX;
        args["baseGroupY"] = baseGroupY;
        args["baseGroupZ"] = baseGroupZ;
        args["groupCountX"] = groupCountX;
        args["groupCountY"] = groupCountY;
        args["groupCountZ"] = groupCountZ;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDescriptorUpdateTemplate");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pDescriptorUpdateTemplate"], pDescriptorUpdateTemplate);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorUpdateTemplate");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["descriptorUpdateTemplate"], descriptorUpdateTemplate);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutSupport");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pSupport"], pSupport);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSamplerYcbcrConversion");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pYcbcrConversion"], pYcbcrConversion);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySamplerYcbcrConversion");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["ycbcrConversion"], ycbcrConversion);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetQueryPool");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["queryPool"], queryPool);
        args["firstQuery"] = firstQuery;
        args["queryCount"] = queryCount;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreCounterValue(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSemaphoreCounterValue");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["semaphore"], semaphore);
        FieldToJson(args["pValue"], pValue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWaitSemaphores");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pWaitInfo"], pWaitInfo);
        args["timeout"] = timeout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSignalSemaphore");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pSignalInfo"], pSignalInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddress");
    FieldToJsonAsHex(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferOpaqueCaptureAddress");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryOpaqueCaptureAddress");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectCount");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        HandleToJson(args["countBuffer"], countBuffer);
        args["countBufferOffset"] = countBufferOffset;
        args["maxDrawCount"] = maxDrawCount;
        args["stride"] = stride;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirectCount");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        HandleToJson(args["countBuffer"], countBuffer);
        args["countBufferOffset"] = countBufferOffset;
        args["maxDrawCount"] = maxDrawCount;
        args["stride"] = stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateRenderPass2");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pRenderPass"], pRenderPass);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pRenderPassBegin"], pRenderPassBegin);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceToolProperties");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pToolCount"], pToolCount);
        FieldToJson(args["pToolProperties"], pToolProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreatePrivateDataSlot");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pPrivateDataSlot"], pPrivateDataSlot);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPrivateDataSlot");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["privateDataSlot"], privateDataSlot);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetPrivateData");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["objectType"] = objectType;
        HandleToJson(args["objectHandle"], objectHandle);
        HandleToJson(args["privateDataSlot"], privateDataSlot);
        args["data"] = data;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPrivateData");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["objectType"] = objectType;
        HandleToJson(args["objectHandle"], objectHandle);
        HandleToJson(args["privateDataSlot"], privateDataSlot);
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPipelineBarrier2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteTimestamp2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["stage"] = VkPipelineStageFlags2_t{stage};
        HandleToJson(args["queryPool"], queryPool);
        args["query"] = query;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSubmit2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSubmit2");
    jdata[NameSubmitIndex()] = ++submit_index_;
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        args["submitCount"] = submitCount;
        FieldToJson(args["pSubmits"], pSubmits);
        HandleToJson(args["fence"], fence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBuffer2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyBufferInfo"], pCopyBufferInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImage2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyImageInfo"], pCopyImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBufferToImage2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyBufferToImageInfo"], pCopyBufferToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToBuffer2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyImageToBufferInfo"], pCopyImageToBufferInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceBufferMemoryRequirements");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageMemoryRequirements");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageSparseMemoryRequirements");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["event"], event);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["event"], event);
        args["stageMask"] = VkPipelineStageFlags2_t{stageMask};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWaitEvents2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["eventCount"] = eventCount;
        HandleToJson(args["pEvents"], pEvents);
        FieldToJson(args["pDependencyInfos"], pDependencyInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBlitImage2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pBlitImageInfo"], pBlitImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResolveImage2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pResolveImageInfo"], pResolveImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRendering");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pRenderingInfo"], pRenderingInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRendering");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCullMode");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["cullMode"] = VkCullModeFlags_t{cullMode};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFrontFace");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["frontFace"] = frontFace;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveTopology");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["primitiveTopology"] = primitiveTopology;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWithCount");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["viewportCount"] = viewportCount;
        FieldToJson(args["pViewports"], pViewports);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetScissorWithCount");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["scissorCount"] = scissorCount;
        FieldToJson(args["pScissors"], pScissors);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindVertexBuffers2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstBinding"] = firstBinding;
        args["bindingCount"] = bindingCount;
        HandleToJson(args["pBuffers"], pBuffers);
        FieldToJson(args["pOffsets"], pOffsets);
        FieldToJson(args["pSizes"], pSizes);
        FieldToJson(args["pStrides"], pStrides);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthTestEnable");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["depthTestEnable"], depthTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthWriteEnable");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["depthWriteEnable"], depthWriteEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthCompareOp");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["depthCompareOp"] = depthCompareOp;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBoundsTestEnable");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["depthBoundsTestEnable"], depthBoundsTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilTestEnable");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["stencilTestEnable"], stencilTestEnable);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilOp");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["faceMask"] = VkStencilFaceFlags_t{faceMask};
        args["failOp"] = failOp;
        args["passOp"] = passOp;
        args["depthFailOp"] = depthFailOp;
        args["compareOp"] = compareOp;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizerDiscardEnable");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["rasterizerDiscardEnable"], rasterizerDiscardEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBiasEnable");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["depthBiasEnable"], depthBiasEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveRestartEnable");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["primitiveRestartEnable"], primitiveRestartEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkMapMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryMapInfo>* pMemoryMapInfo,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMapMemory2");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pMemoryMapInfo"], pMemoryMapInfo);
        FieldToJsonAsHex(args["ppData"], ppData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryUnmapInfo>* pMemoryUnmapInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUnmapMemory2");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pMemoryUnmapInfo"], pMemoryUnmapInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfo>* pInfo,
    StructPointerDecoder<Decoded_VkSubresourceLayout2>* pLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageSubresourceLayout");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pLayout"], pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2>* pLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSubresourceLayout2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["image"], image);
        FieldToJson(args["pSubresource"], pSubresource);
        FieldToJson(args["pLayout"], pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToImage(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfo>* pCopyMemoryToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMemoryToImage");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCopyMemoryToImageInfo"], pCopyMemoryToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfo>* pCopyImageToMemoryInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToMemory");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCopyImageToMemoryInfo"], pCopyImageToMemoryInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToImage(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToImageInfo>* pCopyImageToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToImage");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCopyImageToImageInfo"], pCopyImageToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTransitionImageLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    transitionCount,
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfo>* pTransitions)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTransitionImageLayout");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["transitionCount"] = transitionCount;
        FieldToJson(args["pTransitions"], pTransitions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushDescriptorSet(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushDescriptorSet");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineBindPoint"] = pipelineBindPoint;
        HandleToJson(args["layout"], layout);
        args["set"] = set;
        args["descriptorWriteCount"] = descriptorWriteCount;
        FieldToJson(args["pDescriptorWrites"], pDescriptorWrites);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorSets2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pBindDescriptorSetsInfo"], pBindDescriptorSetsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushConstants2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushConstantsInfo>* pPushConstantsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushConstants2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pPushConstantsInfo"], pPushConstantsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushDescriptorSet2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pPushDescriptorSetInfo"], pPushDescriptorSetInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStipple(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStipple");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["lineStippleFactor"] = lineStippleFactor;
        args["lineStipplePattern"] = lineStipplePattern;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindIndexBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindIndexBuffer2");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        args["size"] = size;
        args["indexType"] = indexType;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRenderingAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingAreaInfo>* pRenderingAreaInfo,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRenderingAreaGranularity");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pRenderingAreaInfo"], pRenderingAreaInfo);
        FieldToJson(args["pGranularity"], pGranularity);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRenderingAttachmentLocations(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo>* pLocationInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRenderingAttachmentLocations");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pLocationInfo"], pLocationInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRenderingInputAttachmentIndices(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo>* pInputAttachmentIndexInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRenderingInputAttachmentIndices");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInputAttachmentIndexInfo"], pInputAttachmentIndexInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySurfaceKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["surface"], surface);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceSupportKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        HandleToJson(args["surface"], surface);
        Bool32ToJson(args["pSupported"], pSupported);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["surface"], surface);
        FieldToJson(args["pSurfaceCapabilities"], pSurfaceCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceFormatsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["surface"], surface);
        FieldToJson(args["pSurfaceFormatCount"], pSurfaceFormatCount);
        FieldToJson(args["pSurfaceFormats"], pSurfaceFormats);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfacePresentModesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["surface"], surface);
        FieldToJson(args["pPresentModeCount"], pPresentModeCount);
        FieldToJson(args["pPresentModes"], pPresentModes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSwapchainKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSwapchain"], pSwapchain);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySwapchainKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainImagesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pSwapchainImageCount"], pSwapchainImageCount);
        HandleToJson(args["pSwapchainImages"], pSwapchainImages);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireNextImageKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        args["timeout"] = timeout;
        HandleToJson(args["semaphore"], semaphore);
        HandleToJson(args["fence"], fence);
        FieldToJson(args["pImageIndex"], pImageIndex);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueuePresentKHR");
    jdata[NameSubmitIndex()] = ++submit_index_;
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        FieldToJson(args["pPresentInfo"], pPresentInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupPresentCapabilitiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pDeviceGroupPresentCapabilities"], pDeviceGroupPresentCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupSurfacePresentModesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["surface"], surface);
        FieldToJson(args["pModes"], pModes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDevicePresentRectanglesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["surface"], surface);
        FieldToJson(args["pRectCount"], pRectCount);
        FieldToJson(args["pRects"], pRects);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireNextImage2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pAcquireInfo"], pAcquireInfo);
        FieldToJson(args["pImageIndex"], pImageIndex);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceDisplayPropertiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    planeIndex,
    PointerDecoder<uint32_t>*                   pDisplayCount,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplays)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDisplayPlaneSupportedDisplaysKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["planeIndex"] = planeIndex;
        FieldToJson(args["pDisplayCount"], pDisplayCount);
        HandleToJson(args["pDisplays"], pDisplays);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDisplayModePropertiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["display"], display);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDisplayModeKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["display"], display);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pMode"], pMode);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDisplayPlaneCapabilitiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["mode"], mode);
        args["planeIndex"] = planeIndex;
        FieldToJson(args["pCapabilities"], pCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDisplayPlaneSurfaceKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSharedSwapchainsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["swapchainCount"] = swapchainCount;
        FieldToJson(args["pCreateInfos"], pCreateInfos);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSwapchains"], pSwapchains);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateXlibSurfaceKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
    Bool32ToJson(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        args["dpy"] = dpy;
        args["visualID"] = visualID;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateXcbSurfaceKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
    Bool32ToJson(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        args["connection"] = connection;
        args["visual_id"] = visual_id;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateWaylandSurfaceKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
    Bool32ToJson(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        args["display"] = display;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateAndroidSurfaceKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateWin32SurfaceKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
    Bool32ToJson(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile,
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pVideoProfile"], pVideoProfile);
        FieldToJson(args["pCapabilities"], pCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo,
    PointerDecoder<uint32_t>*                   pVideoFormatPropertyCount,
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pVideoFormatInfo"], pVideoFormatInfo);
        FieldToJson(args["pVideoFormatPropertyCount"], pVideoFormatPropertyCount);
        FieldToJson(args["pVideoFormatProperties"], pVideoFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionKHR>*    pVideoSession)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateVideoSessionKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pVideoSession"], pVideoSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyVideoSessionKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["videoSession"], videoSession);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetVideoSessionMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    PointerDecoder<uint32_t>*                   pMemoryRequirementsCount,
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetVideoSessionMemoryRequirementsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["videoSession"], videoSession);
        FieldToJson(args["pMemoryRequirementsCount"], pMemoryRequirementsCount);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindVideoSessionMemoryKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["videoSession"], videoSession);
        args["bindSessionMemoryInfoCount"] = bindSessionMemoryInfoCount;
        FieldToJson(args["pBindSessionMemoryInfos"], pBindSessionMemoryInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateVideoSessionParametersKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pVideoSessionParameters"], pVideoSessionParameters);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUpdateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUpdateVideoSessionParametersKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["videoSessionParameters"], videoSessionParameters);
        FieldToJson(args["pUpdateInfo"], pUpdateInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyVideoSessionParametersKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["videoSessionParameters"], videoSessionParameters);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginVideoCodingKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pBeginInfo"], pBeginInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndVideoCodingKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pEndCodingInfo"], pEndCodingInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdControlVideoCodingKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCodingControlInfo"], pCodingControlInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDecodeVideoKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pDecodeInfo"], pDecodeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderingKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pRenderingInfo"], pRenderingInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderingKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pFeatures"], pFeatures);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFormatProperties2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["format"] = format;
        FieldToJson(args["pFormatProperties"], pFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceImageFormatProperties2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pImageFormatInfo"], pImageFormatInfo);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount);
        FieldToJson(args["pQueueFamilyProperties"], pQueueFamilyProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pMemoryProperties"], pMemoryProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pFormatInfo"], pFormatInfo);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["heapIndex"] = heapIndex;
        args["localDeviceIndex"] = localDeviceIndex;
        args["remoteDeviceIndex"] = remoteDeviceIndex;
        FieldToJson(args["pPeerMemoryFeatures"], pPeerMemoryFeatures);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDeviceMaskKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["deviceMask"] = deviceMask;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchBaseKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["baseGroupX"] = baseGroupX;
        args["baseGroupY"] = baseGroupY;
        args["baseGroupZ"] = baseGroupZ;
        args["groupCountX"] = groupCountX;
        args["groupCountY"] = groupCountY;
        args["groupCountZ"] = groupCountZ;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTrimCommandPoolKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["commandPool"], commandPool);
        args["flags"] = VkCommandPoolTrimFlags_t{flags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEnumeratePhysicalDeviceGroupsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pPhysicalDeviceGroupCount"], pPhysicalDeviceGroupCount);
        FieldToJson(args["pPhysicalDeviceGroupProperties"], pPhysicalDeviceGroupProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pExternalBufferInfo"], pExternalBufferInfo);
        FieldToJson(args["pExternalBufferProperties"], pExternalBufferProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryWin32HandleKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pGetWin32HandleInfo"], pGetWin32HandleInfo);
        FieldToJson(args["pHandle"], pHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    handle,
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryWin32HandlePropertiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["handleType"] = handleType;
        args["handle"] = handle;
        FieldToJson(args["pMemoryWin32HandleProperties"], pMemoryWin32HandleProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryFdKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pGetFdInfo"], pGetFdInfo);
        FieldToJson(args["pFd"], pFd);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryFdPropertiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["handleType"] = handleType;
        args["fd"] = fd;
        FieldToJson(args["pMemoryFdProperties"], pMemoryFdProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pExternalSemaphoreInfo"], pExternalSemaphoreInfo);
        FieldToJson(args["pExternalSemaphoreProperties"], pExternalSemaphoreProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreWin32HandleKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pImportSemaphoreWin32HandleInfo"], pImportSemaphoreWin32HandleInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSemaphoreWin32HandleKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pGetWin32HandleInfo"], pGetWin32HandleInfo);
        FieldToJson(args["pHandle"], pHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreFdKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pImportSemaphoreFdInfo"], pImportSemaphoreFdInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSemaphoreFdKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pGetFdInfo"], pGetFdInfo);
        FieldToJson(args["pFd"], pFd);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushDescriptorSetKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineBindPoint"] = pipelineBindPoint;
        HandleToJson(args["layout"], layout);
        args["set"] = set;
        args["descriptorWriteCount"] = descriptorWriteCount;
        FieldToJson(args["pDescriptorWrites"], pDescriptorWrites);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDescriptorUpdateTemplateKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pDescriptorUpdateTemplate"], pDescriptorUpdateTemplate);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDescriptorUpdateTemplateKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["descriptorUpdateTemplate"], descriptorUpdateTemplate);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateRenderPass2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pRenderPass"], pRenderPass);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pRenderPassBegin"], pRenderPassBegin);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainStatusKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pExternalFenceInfo"], pExternalFenceInfo);
        FieldToJson(args["pExternalFenceProperties"], pExternalFenceProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportFenceWin32HandleKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pImportFenceWin32HandleInfo"], pImportFenceWin32HandleInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetFenceWin32HandleKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pGetWin32HandleInfo"], pGetWin32HandleInfo);
        FieldToJson(args["pHandle"], pHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportFenceFdKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pImportFenceFdInfo"], pImportFenceFdInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetFenceFdKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pGetFdInfo"], pGetFdInfo);
        FieldToJson(args["pFd"], pFd);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        FieldToJson(args["pCounterCount"], pCounterCount);
        FieldToJson(args["pCounters"], pCounters);
        FieldToJson(args["pCounterDescriptions"], pCounterDescriptions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pPerformanceQueryCreateInfo"], pPerformanceQueryCreateInfo);
        FieldToJson(args["pNumPasses"], pNumPasses);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireProfilingLockKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseProfilingLockKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo);
        FieldToJson(args["pSurfaceCapabilities"], pSurfaceCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceFormats2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo);
        FieldToJson(args["pSurfaceFormatCount"], pSurfaceFormatCount);
        FieldToJson(args["pSurfaceFormats"], pSurfaceFormats);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceDisplayProperties2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDisplayModeProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDisplayModeProperties2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["display"], display);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDisplayPlaneCapabilities2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pDisplayPlaneInfo"], pDisplayPlaneInfo);
        FieldToJson(args["pCapabilities"], pCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageMemoryRequirements2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferMemoryRequirements2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSparseMemoryRequirements2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateSamplerYcbcrConversionKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pYcbcrConversion"], pYcbcrConversion);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroySamplerYcbcrConversionKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["ycbcrConversion"], ycbcrConversion);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindBufferMemory2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["bindInfoCount"] = bindInfoCount;
        FieldToJson(args["pBindInfos"], pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindImageMemory2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["bindInfoCount"] = bindInfoCount;
        FieldToJson(args["pBindInfos"], pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutSupportKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pSupport"], pSupport);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectCountKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        HandleToJson(args["countBuffer"], countBuffer);
        args["countBufferOffset"] = countBufferOffset;
        args["maxDrawCount"] = maxDrawCount;
        args["stride"] = stride;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirectCountKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        HandleToJson(args["countBuffer"], countBuffer);
        args["countBufferOffset"] = countBufferOffset;
        args["maxDrawCount"] = maxDrawCount;
        args["stride"] = stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreCounterValueKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSemaphoreCounterValueKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["semaphore"], semaphore);
        FieldToJson(args["pValue"], pValue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWaitSemaphoresKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pWaitInfo"], pWaitInfo);
        args["timeout"] = timeout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSignalSemaphoreKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pSignalInfo"], pSignalInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pFragmentShadingRateCount"], pFragmentShadingRateCount);
        FieldToJson(args["pFragmentShadingRates"], pFragmentShadingRates);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFragmentShadingRateKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pFragmentSize"], pFragmentSize);
        FieldToJson(args["combinerOps"], combinerOps);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo>* pLocationInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRenderingAttachmentLocationsKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pLocationInfo"], pLocationInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo>* pInputAttachmentIndexInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRenderingInputAttachmentIndicesKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInputAttachmentIndexInfo"], pInputAttachmentIndexInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWaitForPresentKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        args["presentId"] = presentId;
        args["timeout"] = timeout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddressKHR");
    FieldToJsonAsHex(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferOpaqueCaptureAddressKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDeferredOperationKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pDeferredOperation"], pDeferredOperation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDeferredOperationKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["operation"], operation);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeferredOperationMaxConcurrencyKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["operation"], operation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeferredOperationResultKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["operation"], operation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDeferredOperationJoinKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["operation"], operation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineExecutablePropertiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pPipelineInfo"], pPipelineInfo);
        FieldToJson(args["pExecutableCount"], pExecutableCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineExecutableStatisticsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pExecutableInfo"], pExecutableInfo);
        FieldToJson(args["pStatisticCount"], pStatisticCount);
        FieldToJson(args["pStatistics"], pStatistics);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineExecutableInternalRepresentationsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pExecutableInfo"], pExecutableInfo);
        FieldToJson(args["pInternalRepresentationCount"], pInternalRepresentationCount);
        FieldToJson(args["pInternalRepresentations"], pInternalRepresentations);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkMapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryMapInfo>* pMemoryMapInfo,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMapMemory2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pMemoryMapInfo"], pMemoryMapInfo);
        FieldToJsonAsHex(args["ppData"], ppData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryUnmapInfo>* pMemoryUnmapInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUnmapMemory2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pMemoryUnmapInfo"], pMemoryUnmapInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR>* pQualityLevelInfo,
    StructPointerDecoder<Decoded_VkVideoEncodeQualityLevelPropertiesKHR>* pQualityLevelProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pQualityLevelInfo"], pQualityLevelInfo);
        FieldToJson(args["pQualityLevelProperties"], pQualityLevelProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetEncodedVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersGetInfoKHR>* pVideoSessionParametersInfo,
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR>* pFeedbackInfo,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetEncodedVideoSessionParametersKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pVideoSessionParametersInfo"], pVideoSessionParametersInfo);
        FieldToJson(args["pFeedbackInfo"], pFeedbackInfo);
        FieldToJson(args["pDataSize"], pDataSize);
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEncodeVideoKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pEncodeInfo"], pEncodeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["event"], event);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["event"], event);
        args["stageMask"] = VkPipelineStageFlags2_t{stageMask};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWaitEvents2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["eventCount"] = eventCount;
        HandleToJson(args["pEvents"], pEvents);
        FieldToJson(args["pDependencyInfos"], pDependencyInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPipelineBarrier2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteTimestamp2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["stage"] = VkPipelineStageFlags2_t{stage};
        HandleToJson(args["queryPool"], queryPool);
        args["query"] = query;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSubmit2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSubmit2KHR");
    jdata[NameSubmitIndex()] = ++submit_index_;
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        args["submitCount"] = submitCount;
        FieldToJson(args["pSubmits"], pSubmits);
        HandleToJson(args["fence"], fence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindIndexBuffer3KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindIndexBuffer3InfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindIndexBuffer3KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindVertexBuffers3KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    StructPointerDecoder<Decoded_VkBindVertexBuffer3InfoKHR>* pBindingInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindVertexBuffers3KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstBinding"] = firstBinding;
        args["bindingCount"] = bindingCount;
        FieldToJson(args["pBindingInfos"], pBindingInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirect2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirect2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDispatchIndirect2InfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchIndirect2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryInfoKHR>* pCopyMemoryInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyMemoryInfo"], pCopyMemoryInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToImageKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryImageInfoKHR>* pCopyMemoryInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToImageKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyMemoryInfo"], pCopyMemoryInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryImageInfoKHR>* pCopyMemoryInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToMemoryKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyMemoryInfo"], pCopyMemoryInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdUpdateMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDeviceAddressRangeKHR>* pDstRange,
    VkAddressCommandFlagsKHR                    dstFlags,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdUpdateMemoryKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pDstRange"], pDstRange);
        args["dstFlags"] = VkAddressCommandFlagsKHR_t{dstFlags};
        args["dataSize"] = dataSize;
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdFillMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDeviceAddressRangeKHR>* pDstRange,
    VkAddressCommandFlagsKHR                    dstFlags,
    uint32_t                                    data)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdFillMemoryKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pDstRange"], pDstRange);
        args["dstFlags"] = VkAddressCommandFlagsKHR_t{dstFlags};
        args["data"] = data;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRangeKHR>* pDstRange,
    VkAddressCommandFlagsKHR                    dstFlags,
    VkQueryResultFlags                          queryResultFlags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyQueryPoolResultsToMemoryKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["queryPool"], queryPool);
        args["firstQuery"] = firstQuery;
        args["queryCount"] = queryCount;
        FieldToJson(args["pDstRange"], pDstRange);
        args["dstFlags"] = VkAddressCommandFlagsKHR_t{dstFlags};
        args["queryResultFlags"] = VkQueryResultFlags_t{queryResultFlags};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectCount2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndexedIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirectCount2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginConditionalRendering2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfo2EXT>* pConditionalRenderingBegin)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginConditionalRendering2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pConditionalRenderingBegin"], pConditionalRenderingBegin);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindTransformFeedbackBuffers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT>* pBindingInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindTransformFeedbackBuffers2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstBinding"] = firstBinding;
        args["bindingCount"] = bindingCount;
        FieldToJson(args["pBindingInfos"], pBindingInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterRange,
    uint32_t                                    counterRangeCount,
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT>* pCounterInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginTransformFeedback2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstCounterRange"] = firstCounterRange;
        args["counterRangeCount"] = counterRangeCount;
        FieldToJson(args["pCounterInfos"], pCounterInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterRange,
    uint32_t                                    counterRangeCount,
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT>* pCounterInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndTransformFeedback2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstCounterRange"] = firstCounterRange;
        args["counterRangeCount"] = counterRangeCount;
        FieldToJson(args["pCounterInfos"], pCounterInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawIndirectByteCount2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT>* pCounterInfo,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectByteCount2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["instanceCount"] = instanceCount;
        args["firstInstance"] = firstInstance;
        FieldToJson(args["pCounterInfo"], pCounterInfo);
        args["counterOffset"] = counterOffset;
        args["vertexStride"] = vertexStride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirect2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirect2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectCount2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirectCount2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteMarkerToMemoryAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkMemoryMarkerInfoAMD>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteMarkerToMemoryAMD");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateAccelerationStructure2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfo2KHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateAccelerationStructure2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pAccelerationStructure"], pAccelerationStructure);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBuffer2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyBufferInfo"], pCopyBufferInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImage2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyImageInfo"], pCopyImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBufferToImage2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyBufferToImageInfo"], pCopyBufferToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToBuffer2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyImageToBufferInfo"], pCopyImageToBufferInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBlitImage2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pBlitImageInfo"], pBlitImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResolveImage2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pResolveImageInfo"], pResolveImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdTraceRaysIndirect2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJsonAsHex(args["indirectDeviceAddress"], indirectDeviceAddress);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceBufferMemoryRequirementsKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageMemoryRequirementsKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageSparseMemoryRequirementsKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindIndexBuffer2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        args["size"] = size;
        args["indexType"] = indexType;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRenderingAreaGranularityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingAreaInfo>* pRenderingAreaInfo,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRenderingAreaGranularityKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pRenderingAreaInfo"], pRenderingAreaInfo);
        FieldToJson(args["pGranularity"], pGranularity);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSubresourceLayoutKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfo>* pInfo,
    StructPointerDecoder<Decoded_VkSubresourceLayout2>* pLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageSubresourceLayoutKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pLayout"], pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2>* pLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSubresourceLayout2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["image"], image);
        FieldToJson(args["pSubresource"], pSubresource);
        FieldToJson(args["pLayout"], pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkWaitForPresent2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkPresentWait2InfoKHR>* pPresentWait2Info)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWaitForPresent2KHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pPresentWait2Info"], pPresentWait2Info);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreatePipelineBinariesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineBinaryCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    StructPointerDecoder<Decoded_VkPipelineBinaryHandlesInfoKHR>* pBinaries)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreatePipelineBinariesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        FieldToJson(args["pBinaries"], pBinaries);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPipelineBinaryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineBinary,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPipelineBinaryKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipelineBinary"], pipelineBinary);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineKeyKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCreateInfoKHR>* pPipelineCreateInfo,
    StructPointerDecoder<Decoded_VkPipelineBinaryKeyKHR>* pPipelineKey)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineKeyKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pPipelineCreateInfo"], pPipelineCreateInfo);
        FieldToJson(args["pPipelineKey"], pPipelineKey);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineBinaryDataKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineBinaryDataInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkPipelineBinaryKeyKHR>* pPipelineBinaryKey,
    PointerDecoder<size_t>*                     pPipelineBinaryDataSize,
    PointerDecoder<uint8_t>*                    pPipelineBinaryData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineBinaryDataKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pPipelineBinaryKey"], pPipelineBinaryKey);
        FieldToJson(args["pPipelineBinaryDataSize"], pPipelineBinaryDataSize);
        FieldToJson(args["pPipelineBinaryData"], pPipelineBinaryData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseCapturedPipelineDataKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseCapturedPipelineDataInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseCapturedPipelineDataKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoKHR>* pReleaseInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseSwapchainImagesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pReleaseInfo"], pReleaseInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesKHR>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["lineStippleFactor"] = lineStippleFactor;
        args["lineStipplePattern"] = lineStipplePattern;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainKHR>*            pTimeDomains)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pTimeDomainCount"], pTimeDomainCount);
        FieldToJson(args["pTimeDomains"], pTimeDomains);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetCalibratedTimestampsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetCalibratedTimestampsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["timestampCount"] = timestampCount;
        FieldToJson(args["pTimestampInfos"], pTimestampInfos);
        FieldToJson(args["pTimestamps"], pTimestamps);
        FieldToJson(args["pMaxDeviation"], pMaxDeviation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorSets2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pBindDescriptorSetsInfo"], pBindDescriptorSetsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushConstantsInfo>* pPushConstantsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushConstants2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pPushConstantsInfo"], pPushConstantsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPushDescriptorSet2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pPushDescriptorSetInfo"], pPushDescriptorSetInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT>* pSetDescriptorBufferOffsetsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDescriptorBufferOffsets2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pSetDescriptorBufferOffsetsInfo"], pSetDescriptorBufferOffsetsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT>* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pBindDescriptorBufferEmbeddedSamplersInfo"], pBindDescriptorBufferEmbeddedSamplersInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryIndirectInfoKHR>* pCopyMemoryIndirectInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryIndirectKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyMemoryIndirectInfo"], pCopyMemoryIndirectInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageIndirectInfoKHR>* pCopyMemoryToImageIndirectInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToImageIndirectKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pCopyMemoryToImageIndirectInfo"], pCopyMemoryToImageIndirectInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceFaultReportsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    timeout,
    PointerDecoder<uint32_t>*                   pFaultCounts,
    StructPointerDecoder<Decoded_VkDeviceFaultInfoKHR>* pFaultInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceFaultReportsKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["timeout"] = timeout;
        FieldToJson(args["pFaultCounts"], pFaultCounts);
        FieldToJson(args["pFaultInfo"], pFaultInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceFaultDebugInfoKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceFaultDebugInfoKHR>* pDebugInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceFaultDebugInfoKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pDebugInfo"], pDebugInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRendering2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingEndInfoKHR>* pRenderingEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRendering2KHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pRenderingEndInfo"], pRenderingEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkFrameBoundaryANDROID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    format::HandleId                            image)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkFrameBoundaryANDROID");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["semaphore"], semaphore);
        HandleToJson(args["image"], image);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDebugReportCallbackEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pCallback"], pCallback);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDebugReportCallbackEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["callback"], callback);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDebugReportMessageEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        args["flags"] = VkDebugReportFlagsEXT_t{flags};
        args["objectType"] = objectType;
        HandleToJson(args["object"], object);
        args["location"] = location;
        args["messageCode"] = messageCode;
        FieldToJson(args["pLayerPrefix"], pLayerPrefix);
        FieldToJson(args["pMessage"], pMessage);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDebugMarkerSetObjectTagEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pTagInfo"], pTagInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDebugMarkerSetObjectNameEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pNameInfo"], pNameInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerBeginEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerEndEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerInsertEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindTransformFeedbackBuffersEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstBinding"] = firstBinding;
        args["bindingCount"] = bindingCount;
        HandleToJson(args["pBuffers"], pBuffers);
        FieldToJson(args["pOffsets"], pOffsets);
        FieldToJson(args["pSizes"], pSizes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginTransformFeedbackEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstCounterBuffer"] = firstCounterBuffer;
        args["counterBufferCount"] = counterBufferCount;
        HandleToJson(args["pCounterBuffers"], pCounterBuffers);
        FieldToJson(args["pCounterBufferOffsets"], pCounterBufferOffsets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndTransformFeedbackEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstCounterBuffer"] = firstCounterBuffer;
        args["counterBufferCount"] = counterBufferCount;
        HandleToJson(args["pCounterBuffers"], pCounterBuffers);
        FieldToJson(args["pCounterBufferOffsets"], pCounterBufferOffsets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginQueryIndexedEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["queryPool"], queryPool);
        args["query"] = query;
        args["flags"] = VkQueryControlFlags_t{flags};
        args["index"] = index;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndQueryIndexedEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["queryPool"], queryPool);
        args["query"] = query;
        args["index"] = index;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectByteCountEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["instanceCount"] = instanceCount;
        args["firstInstance"] = firstInstance;
        HandleToJson(args["counterBuffer"], counterBuffer);
        args["counterBufferOffset"] = counterBufferOffset;
        args["counterOffset"] = counterOffset;
        args["vertexStride"] = vertexStride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageViewHandleNVX");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageViewHandle64NVX(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageViewHandle64NVX");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageViewAddressNVX");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["imageView"], imageView);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceCombinedImageSamplerIndexNVX(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    imageViewIndex,
    uint64_t                                    samplerIndex)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceCombinedImageSamplerIndexNVX");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["imageViewIndex"] = imageViewIndex;
        args["samplerIndex"] = samplerIndex;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndirectCountAMD");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        HandleToJson(args["countBuffer"], countBuffer);
        args["countBufferOffset"] = countBufferOffset;
        args["maxDrawCount"] = maxDrawCount;
        args["stride"] = stride;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawIndexedIndirectCountAMD");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        HandleToJson(args["countBuffer"], countBuffer);
        args["countBufferOffset"] = countBufferOffset;
        args["maxDrawCount"] = maxDrawCount;
        args["stride"] = stride;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetShaderInfoAMD");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipeline"], pipeline);
        args["shaderStage"] = shaderStage;
        args["infoType"] = infoType;
        FieldToJson(args["pInfoSize"], pInfoSize);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateStreamDescriptorSurfaceGGP");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["format"] = format;
        args["type"] = type;
        args["tiling"] = tiling;
        args["usage"] = VkImageUsageFlags_t{usage};
        args["flags"] = VkImageCreateFlags_t{flags};
        args["externalHandleType"] = VkExternalMemoryHandleTypeFlagsNV_t{externalHandleType};
        FieldToJson(args["pExternalImageFormatProperties"], pExternalImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryWin32HandleNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["memory"], memory);
        args["handleType"] = VkExternalMemoryHandleTypeFlagsNV_t{handleType};
        FieldToJson(args["pHandle"], pHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateViSurfaceNN");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginConditionalRenderingEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pConditionalRenderingBegin"], pConditionalRenderingBegin);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndConditionalRenderingEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWScalingNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstViewport"] = firstViewport;
        args["viewportCount"] = viewportCount;
        FieldToJson(args["pViewportWScalings"], pViewportWScalings);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseDisplayEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["display"], display);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireXlibDisplayEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["dpy"] = dpy;
        HandleToJson(args["display"], display);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRandROutputDisplayEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["dpy"] = dpy;
        args["rrOutput"] = rrOutput;
        HandleToJson(args["pDisplay"], pDisplay);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["surface"], surface);
        FieldToJson(args["pSurfaceCapabilities"], pSurfaceCapabilities);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDisplayPowerControlEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["display"], display);
        FieldToJson(args["pDisplayPowerInfo"], pDisplayPowerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkRegisterDeviceEventEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pDeviceEventInfo"], pDeviceEventInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pFence"], pFence);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkRegisterDisplayEventEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["display"], display);
        FieldToJson(args["pDisplayEventInfo"], pDisplayEventInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pFence"], pFence);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainCounterEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        args["counter"] = counter;
        FieldToJson(args["pCounterValue"], pCounterValue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRefreshCycleDurationGOOGLE");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pDisplayTimingProperties"], pDisplayTimingProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPastPresentationTimingGOOGLE");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pPresentationTimingCount"], pPresentationTimingCount);
        FieldToJson(args["pPresentationTimings"], pPresentationTimings);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDiscardRectangleEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstDiscardRectangle"] = firstDiscardRectangle;
        args["discardRectangleCount"] = discardRectangleCount;
        FieldToJson(args["pDiscardRectangles"], pDiscardRectangles);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDiscardRectangleEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["discardRectangleEnable"], discardRectangleEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDiscardRectangleModeEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["discardRectangleMode"] = discardRectangleMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetHdrMetadataEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["swapchainCount"] = swapchainCount;
        HandleToJson(args["pSwapchains"], pSwapchains);
        FieldToJson(args["pMetadata"], pMetadata);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateIOSSurfaceMVK");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateMacOSSurfaceMVK");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDebugUtilsObjectNameEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pNameInfo"], pNameInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDebugUtilsObjectTagEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pTagInfo"], pTagInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueBeginDebugUtilsLabelEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        FieldToJson(args["pLabelInfo"], pLabelInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueEndDebugUtilsLabelEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueInsertDebugUtilsLabelEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        FieldToJson(args["pLabelInfo"], pLabelInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginDebugUtilsLabelEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pLabelInfo"], pLabelInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndDebugUtilsLabelEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdInsertDebugUtilsLabelEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pLabelInfo"], pLabelInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDebugUtilsMessengerEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pMessenger"], pMessenger);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDebugUtilsMessengerEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        HandleToJson(args["messenger"], messenger);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSubmitDebugUtilsMessageEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        args["messageSeverity"] = messageSeverity;
        args["messageTypes"] = VkDebugUtilsMessageTypeFlagsEXT_t{messageTypes};
        FieldToJson(args["pCallbackData"], pCallbackData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAndroidHardwareBufferPropertiesANDROID");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["buffer"] = buffer;
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryAndroidHardwareBufferANDROID");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pBuffer"], pBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleLocationsEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pSampleLocationsInfo"], pSampleLocationsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["samples"] = samples;
        FieldToJson(args["pMultisampleProperties"], pMultisampleProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageDrmFormatModifierPropertiesEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["image"], image);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateValidationCacheEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pValidationCache"], pValidationCache);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyValidationCacheEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["validationCache"], validationCache);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMergeValidationCachesEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["dstCache"], dstCache);
        args["srcCacheCount"] = srcCacheCount;
        HandleToJson(args["pSrcCaches"], pSrcCaches);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetValidationCacheDataEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["validationCache"], validationCache);
        FieldToJson(args["pDataSize"], pDataSize);
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindShadingRateImageNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["imageView"], imageView);
        args["imageLayout"] = imageLayout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportShadingRatePaletteNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstViewport"] = firstViewport;
        args["viewportCount"] = viewportCount;
        FieldToJson(args["pShadingRatePalettes"], pShadingRatePalettes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoarseSampleOrderNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["sampleOrderType"] = sampleOrderType;
        args["customSampleOrderCount"] = customSampleOrderCount;
        FieldToJson(args["pCustomSampleOrders"], pCustomSampleOrders);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateAccelerationStructureNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pAccelerationStructure"], pAccelerationStructure);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyAccelerationStructureNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["accelerationStructure"], accelerationStructure);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureMemoryRequirementsNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindAccelerationStructureMemoryNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["bindInfoCount"] = bindInfoCount;
        FieldToJson(args["pBindInfos"], pBindInfos);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBuildAccelerationStructureNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
        HandleToJson(args["instanceData"], instanceData);
        args["instanceOffset"] = instanceOffset;
        Bool32ToJson(args["update"], update);
        HandleToJson(args["dst"], dst);
        HandleToJson(args["src"], src);
        HandleToJson(args["scratch"], scratch);
        args["scratchOffset"] = scratchOffset;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyAccelerationStructureNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["dst"], dst);
        HandleToJson(args["src"], src);
        args["mode"] = mode;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdTraceRaysNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["raygenShaderBindingTableBuffer"], raygenShaderBindingTableBuffer);
        args["raygenShaderBindingOffset"] = raygenShaderBindingOffset;
        HandleToJson(args["missShaderBindingTableBuffer"], missShaderBindingTableBuffer);
        args["missShaderBindingOffset"] = missShaderBindingOffset;
        args["missShaderBindingStride"] = missShaderBindingStride;
        HandleToJson(args["hitShaderBindingTableBuffer"], hitShaderBindingTableBuffer);
        args["hitShaderBindingOffset"] = hitShaderBindingOffset;
        args["hitShaderBindingStride"] = hitShaderBindingStride;
        HandleToJson(args["callableShaderBindingTableBuffer"], callableShaderBindingTableBuffer);
        args["callableShaderBindingOffset"] = callableShaderBindingOffset;
        args["callableShaderBindingStride"] = callableShaderBindingStride;
        args["width"] = width;
        args["height"] = height;
        args["depth"] = depth;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateRayTracingPipelinesNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipelineCache"], pipelineCache);
        args["createInfoCount"] = createInfoCount;
        FieldToJson(args["pCreateInfos"], pCreateInfos);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pPipelines"], pPipelines);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRayTracingShaderGroupHandlesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipeline"], pipeline);
        args["firstGroup"] = firstGroup;
        args["groupCount"] = groupCount;
        args["dataSize"] = dataSize;
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRayTracingShaderGroupHandlesNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipeline"], pipeline);
        args["firstGroup"] = firstGroup;
        args["groupCount"] = groupCount;
        args["dataSize"] = dataSize;
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureHandleNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["accelerationStructure"], accelerationStructure);
        args["dataSize"] = dataSize;
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteAccelerationStructuresPropertiesNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["accelerationStructureCount"] = accelerationStructureCount;
        HandleToJson(args["pAccelerationStructures"], pAccelerationStructures);
        args["queryType"] = queryType;
        HandleToJson(args["queryPool"], queryPool);
        args["firstQuery"] = firstQuery;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCompileDeferredNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCompileDeferredNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipeline"], pipeline);
        args["shader"] = shader;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryHostPointerPropertiesEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["handleType"] = handleType;
        args["pHostPointer"] = pHostPointer;
        FieldToJson(args["pMemoryHostPointerProperties"], pMemoryHostPointerProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteBufferMarkerAMD");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineStage"] = pipelineStage;
        HandleToJson(args["dstBuffer"], dstBuffer);
        args["dstOffset"] = dstOffset;
        args["marker"] = marker;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteBufferMarker2AMD");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["stage"] = VkPipelineStageFlags2_t{stage};
        HandleToJson(args["dstBuffer"], dstBuffer);
        args["dstOffset"] = dstOffset;
        args["marker"] = marker;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainKHR>*            pTimeDomains)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pTimeDomainCount"], pTimeDomainCount);
        FieldToJson(args["pTimeDomains"], pTimeDomains);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoKHR>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetCalibratedTimestampsEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["timestampCount"] = timestampCount;
        FieldToJson(args["pTimestampInfos"], pTimestampInfos);
        FieldToJson(args["pTimestamps"], pTimestamps);
        FieldToJson(args["pMaxDeviation"], pMaxDeviation);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["taskCount"] = taskCount;
        args["firstTask"] = firstTask;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirectNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        args["drawCount"] = drawCount;
        args["stride"] = stride;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirectCountNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        HandleToJson(args["countBuffer"], countBuffer);
        args["countBufferOffset"] = countBufferOffset;
        args["maxDrawCount"] = maxDrawCount;
        args["stride"] = stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    PointerDecoder<VkBool32>*                   pExclusiveScissorEnables)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetExclusiveScissorEnableNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstExclusiveScissor"] = firstExclusiveScissor;
        args["exclusiveScissorCount"] = exclusiveScissorCount;
        Bool32ToJson(args["pExclusiveScissorEnables"], pExclusiveScissorEnables);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetExclusiveScissorNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstExclusiveScissor"] = firstExclusiveScissor;
        args["exclusiveScissorCount"] = exclusiveScissorCount;
        FieldToJson(args["pExclusiveScissors"], pExclusiveScissors);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCheckpointNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pCheckpointMarker"] = pCheckpointMarker;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetQueueCheckpointDataNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        FieldToJson(args["pCheckpointDataCount"], pCheckpointDataCount);
        FieldToJson(args["pCheckpointData"], pCheckpointData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetQueueCheckpointData2NV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        FieldToJson(args["pCheckpointDataCount"], pCheckpointDataCount);
        FieldToJson(args["pCheckpointData"], pCheckpointData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetSwapchainPresentTimingQueueSizeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint32_t                                    size)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetSwapchainPresentTimingQueueSizeEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        args["size"] = size;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainTimingPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkSwapchainTimingPropertiesEXT>* pSwapchainTimingProperties,
    PointerDecoder<uint64_t>*                   pSwapchainTimingPropertiesCounter)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainTimingPropertiesEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pSwapchainTimingProperties"], pSwapchainTimingProperties);
        FieldToJson(args["pSwapchainTimingPropertiesCounter"], pSwapchainTimingPropertiesCounter);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainTimeDomainPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkSwapchainTimeDomainPropertiesEXT>* pSwapchainTimeDomainProperties,
    PointerDecoder<uint64_t>*                   pTimeDomainsCounter)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainTimeDomainPropertiesEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pSwapchainTimeDomainProperties"], pSwapchainTimeDomainProperties);
        FieldToJson(args["pTimeDomainsCounter"], pTimeDomainsCounter);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPastPresentationTimingEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPastPresentationTimingInfoEXT>* pPastPresentationTimingInfo,
    StructPointerDecoder<Decoded_VkPastPresentationTimingPropertiesEXT>* pPastPresentationTimingProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPastPresentationTimingEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pPastPresentationTimingInfo"], pPastPresentationTimingInfo);
        FieldToJson(args["pPastPresentationTimingProperties"], pPastPresentationTimingProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkInitializePerformanceApiINTEL");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInitializeInfo"], pInitializeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUninitializePerformanceApiINTEL");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceMarkerINTEL");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceStreamMarkerINTEL");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceOverrideINTEL");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pOverrideInfo"], pOverrideInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquirePerformanceConfigurationINTEL");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pAcquireInfo"], pAcquireInfo);
        HandleToJson(args["pConfiguration"], pConfiguration);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleasePerformanceConfigurationINTEL");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["configuration"], configuration);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSetPerformanceConfigurationINTEL");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        HandleToJson(args["configuration"], configuration);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPerformanceParameterINTEL");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["parameter"] = parameter;
        FieldToJson(args["pValue"], pValue);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetLocalDimmingAMD");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapChain"], swapChain);
        Bool32ToJson(args["localDimmingEnable"], localDimmingEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateImagePipeSurfaceFUCHSIA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateMetalSurfaceEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddressEXT");
    FieldToJsonAsHex(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceToolPropertiesEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pToolCount"], pToolCount);
        FieldToJson(args["pToolProperties"], pToolProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pCombinationCount"], pCombinationCount);
        FieldToJson(args["pCombinations"], pCombinations);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo);
        FieldToJson(args["pPresentModeCount"], pPresentModeCount);
        FieldToJson(args["pPresentModes"], pPresentModes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireFullScreenExclusiveModeEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseFullScreenExclusiveModeEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupSurfacePresentModes2EXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo);
        FieldToJson(args["pModes"], pModes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateHeadlessSurfaceEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["lineStippleFactor"] = lineStippleFactor;
        args["lineStipplePattern"] = lineStipplePattern;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetQueryPoolEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["queryPool"], queryPool);
        args["firstQuery"] = firstQuery;
        args["queryCount"] = queryCount;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCullModeEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["cullMode"] = VkCullModeFlags_t{cullMode};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFrontFaceEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["frontFace"] = frontFace;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveTopologyEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["primitiveTopology"] = primitiveTopology;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWithCountEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["viewportCount"] = viewportCount;
        FieldToJson(args["pViewports"], pViewports);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetScissorWithCountEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["scissorCount"] = scissorCount;
        FieldToJson(args["pScissors"], pScissors);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindVertexBuffers2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstBinding"] = firstBinding;
        args["bindingCount"] = bindingCount;
        HandleToJson(args["pBuffers"], pBuffers);
        FieldToJson(args["pOffsets"], pOffsets);
        FieldToJson(args["pSizes"], pSizes);
        FieldToJson(args["pStrides"], pStrides);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthTestEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["depthTestEnable"], depthTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthWriteEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["depthWriteEnable"], depthWriteEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthCompareOpEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["depthCompareOp"] = depthCompareOp;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBoundsTestEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["depthBoundsTestEnable"], depthBoundsTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilTestEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["stencilTestEnable"], stencilTestEnable);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilOpEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["faceMask"] = VkStencilFaceFlags_t{faceMask};
        args["failOp"] = failOp;
        args["passOp"] = passOp;
        args["depthFailOp"] = depthFailOp;
        args["compareOp"] = compareOp;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfo>* pCopyMemoryToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMemoryToImageEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCopyMemoryToImageInfo"], pCopyMemoryToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfo>* pCopyImageToMemoryInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToMemoryEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCopyImageToMemoryInfo"], pCopyImageToMemoryInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToImageInfo>* pCopyImageToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToImageEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCopyImageToImageInfo"], pCopyImageToImageInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTransitionImageLayoutEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    transitionCount,
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfo>* pTransitions)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTransitionImageLayoutEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["transitionCount"] = transitionCount;
        FieldToJson(args["pTransitions"], pTransitions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2>* pLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSubresourceLayout2EXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["image"], image);
        FieldToJson(args["pSubresource"], pSubresource);
        FieldToJson(args["pLayout"], pLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoKHR>* pReleaseInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseSwapchainImagesEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pReleaseInfo"], pReleaseInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetGeneratedCommandsMemoryRequirementsNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPreprocessGeneratedCommandsNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pGeneratedCommandsInfo"], pGeneratedCommandsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdExecuteGeneratedCommandsNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["isPreprocessed"], isPreprocessed);
        FieldToJson(args["pGeneratedCommandsInfo"], pGeneratedCommandsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindPipelineShaderGroupNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineBindPoint"] = pipelineBindPoint;
        HandleToJson(args["pipeline"], pipeline);
        args["groupIndex"] = groupIndex;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateIndirectCommandsLayoutNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pIndirectCommandsLayout"], pIndirectCommandsLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyIndirectCommandsLayoutNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["indirectCommandsLayout"], indirectCommandsLayout);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBias2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pDepthBiasInfo"], pDepthBiasInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    format::HandleId                            display)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireDrmDisplayEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["drmFd"] = drmFd;
        HandleToJson(args["display"], display);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    HandlePointerDecoder<VkDisplayKHR>*         display)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDrmDisplayEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["drmFd"] = drmFd;
        args["connectorId"] = connectorId;
        HandleToJson(args["display"], display);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreatePrivateDataSlotEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pPrivateDataSlot"], pPrivateDataSlot);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyPrivateDataSlotEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["privateDataSlot"], privateDataSlot);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetPrivateDataEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["objectType"] = objectType;
        HandleToJson(args["objectHandle"], objectHandle);
        HandleToJson(args["privateDataSlot"], privateDataSlot);
        args["data"] = data;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPrivateDataEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["objectType"] = objectType;
        HandleToJson(args["objectHandle"], objectHandle);
        HandleToJson(args["privateDataSlot"], privateDataSlot);
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSetPerfHintQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPerfHintInfoQCOM>* pPerfHintInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSetPerfHintQCOM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        FieldToJson(args["pPerfHintInfo"], pPerfHintInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchTileQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDispatchTileInfoQCOM>* pDispatchTileInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchTileQCOM");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pDispatchTileInfo"], pDispatchTileInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerTileBeginInfoQCOM>* pPerTileBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginPerTileExecutionQCOM");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pPerTileBeginInfo"], pPerTileBeginInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerTileEndInfoQCOM>* pPerTileEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndPerTileExecutionQCOM");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pPerTileEndInfo"], pPerTileEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            layout,
    PointerDecoder<VkDeviceSize>*               pLayoutSizeInBytes)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutSizeEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["layout"], layout);
        FieldToJson(args["pLayoutSizeInBytes"], pLayoutSizeInBytes);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutBindingOffsetEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            layout,
    uint32_t                                    binding,
    PointerDecoder<VkDeviceSize>*               pOffset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutBindingOffsetEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["layout"], layout);
        args["binding"] = binding;
        FieldToJson(args["pOffset"], pOffset);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorGetInfoEXT>* pDescriptorInfo,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pDescriptor)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pDescriptorInfo"], pDescriptorInfo);
        args["dataSize"] = dataSize;
        FieldToJson(args["pDescriptor"], pDescriptor);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorBuffersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    bufferCount,
    StructPointerDecoder<Decoded_VkDescriptorBufferBindingInfoEXT>* pBindingInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorBuffersEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["bufferCount"] = bufferCount;
        FieldToJson(args["pBindingInfos"], pBindingInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDescriptorBufferOffsetsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    setCount,
    PointerDecoder<uint32_t>*                   pBufferIndices,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDescriptorBufferOffsetsEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineBindPoint"] = pipelineBindPoint;
        HandleToJson(args["layout"], layout);
        args["firstSet"] = firstSet;
        args["setCount"] = setCount;
        FieldToJson(args["pBufferIndices"], pBufferIndices);
        FieldToJson(args["pOffsets"], pOffsets);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineBindPoint"] = pipelineBindPoint;
        HandleToJson(args["layout"], layout);
        args["set"] = set;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFragmentShadingRateEnumNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["shadingRate"] = shadingRate;
        FieldToJson(args["combinerOps"], combinerOps);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts,
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceFaultInfoEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pFaultCounts"], pFaultCounts);
        FieldToJson(args["pFaultInfo"], pFaultInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireWinrtDisplayNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        HandleToJson(args["display"], display);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetWinrtDisplayNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["deviceRelativeId"] = deviceRelativeId;
        HandleToJson(args["pDisplay"], pDisplay);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDirectFBSurfaceEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
    Bool32ToJson(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        args["dfb"] = dfb;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetVertexInputEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["vertexBindingDescriptionCount"] = vertexBindingDescriptionCount;
        FieldToJson(args["pVertexBindingDescriptions"], pVertexBindingDescriptions);
        args["vertexAttributeDescriptionCount"] = vertexAttributeDescriptionCount;
        FieldToJson(args["pVertexAttributeDescriptions"], pVertexAttributeDescriptions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryZirconHandleFUCHSIA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pGetZirconHandleInfo"], pGetZirconHandleInfo);
        FieldToJson(args["pZirconHandle"], pZirconHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint32_t                                    zirconHandle,
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["handleType"] = handleType;
        args["zirconHandle"] = zirconHandle;
        FieldToJson(args["pMemoryZirconHandleProperties"], pMemoryZirconHandleProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreZirconHandleFUCHSIA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pImportSemaphoreZirconHandleInfo"], pImportSemaphoreZirconHandleInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSemaphoreZirconHandleFUCHSIA");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pGetZirconHandleInfo"], pGetZirconHandleInfo);
        FieldToJson(args["pZirconHandle"], pZirconHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindInvocationMaskHUAWEI");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["imageView"], imageView);
        args["imageLayout"] = imageLayout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo,
    PointerDecoder<uint64_t, void*>*            pAddress)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryRemoteAddressNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pMemoryGetRemoteAddressInfo"], pMemoryGetRemoteAddressInfo);
        FieldToJson(args["pAddress"], pAddress);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPatchControlPointsEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["patchControlPoints"] = patchControlPoints;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizerDiscardEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["rasterizerDiscardEnable"], rasterizerDiscardEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBiasEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["depthBiasEnable"], depthBiasEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLogicOpEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["logicOp"] = logicOp;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveRestartEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["primitiveRestartEnable"], primitiveRestartEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateScreenSurfaceQNX");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSurface"], pSurface);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    window)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceScreenPresentationSupportQNX");
    Bool32ToJson(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        args["window"] = window;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorWriteEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["attachmentCount"] = attachmentCount;
        Bool32ToJson(args["pColorWriteEnables"], pColorWriteEnables);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMultiEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["drawCount"] = drawCount;
        FieldToJson(args["pVertexInfo"], pVertexInfo);
        args["instanceCount"] = instanceCount;
        args["firstInstance"] = firstInstance;
        args["stride"] = stride;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMultiIndexedEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["drawCount"] = drawCount;
        FieldToJson(args["pIndexInfo"], pIndexInfo);
        args["instanceCount"] = instanceCount;
        args["firstInstance"] = firstInstance;
        args["stride"] = stride;
        FieldToJson(args["pVertexOffset"], pVertexOffset);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromap)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateMicromapEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pMicromap"], pMicromap);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyMicromapEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["micromap"], micromap);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBuildMicromapsEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["infoCount"] = infoCount;
        FieldToJson(args["pInfos"], pInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBuildMicromapsEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["deferredOperation"], deferredOperation);
        args["infoCount"] = infoCount;
        FieldToJson(args["pInfos"], pInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMicromapEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["deferredOperation"], deferredOperation);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMicromapToMemoryEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["deferredOperation"], deferredOperation);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMemoryToMicromapEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["deferredOperation"], deferredOperation);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWriteMicromapsPropertiesEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["micromapCount"] = micromapCount;
        HandleToJson(args["pMicromaps"], pMicromaps);
        args["queryType"] = queryType;
        args["dataSize"] = dataSize;
        FieldToJson(args["pData"], pData);
        args["stride"] = stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMicromapEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMicromapToMemoryEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToMicromapEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteMicromapsPropertiesEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["micromapCount"] = micromapCount;
        HandleToJson(args["pMicromaps"], pMicromaps);
        args["queryType"] = queryType;
        HandleToJson(args["queryPool"], queryPool);
        args["firstQuery"] = firstQuery;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMicromapCompatibilityEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pVersionInfo"], pVersionInfo);
        FieldToJson(args["pCompatibility"], pCompatibility);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMicromapBuildSizesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo,
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMicromapBuildSizesEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["buildType"] = buildType;
        FieldToJson(args["pBuildInfo"], pBuildInfo);
        FieldToJson(args["pSizeInfo"], pSizeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawClusterHUAWEI");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["groupCountX"] = groupCountX;
        args["groupCountY"] = groupCountY;
        args["groupCountZ"] = groupCountZ;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawClusterIndirectHUAWEI");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDeviceMemoryPriorityEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["memory"], memory);
        FieldToJson(args["priority"], priority);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDispatchParametersARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDispatchParametersARM>* pDispatchParameters)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDispatchParametersARM");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pDispatchParameters"], pDispatchParameters);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetLayoutHostMappingInfoVALVE");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pBindingReference"], pBindingReference);
        FieldToJson(args["pHostMapping"], pHostMapping);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDescriptorSetHostMappingVALVE");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["descriptorSet"], descriptorSet);
        FieldToJsonAsHex(args["ppData"], ppData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineIndirectMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineIndirectMemoryRequirementsNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdUpdatePipelineIndirectBufferNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineBindPoint"] = pipelineBindPoint;
        HandleToJson(args["pipeline"], pipeline);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineIndirectDeviceAddressNV(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineIndirectDeviceAddressNV");
    FieldToJsonAsHex(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClampEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["depthClampEnable"], depthClampEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPolygonModeEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["polygonMode"] = polygonMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizationSamplesEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["rasterizationSamples"] = rasterizationSamples;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleMaskEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["samples"] = samples;
        FieldToJson(args["pSampleMask"], pSampleMask);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAlphaToCoverageEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["alphaToCoverageEnable"], alphaToCoverageEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAlphaToOneEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["alphaToOneEnable"], alphaToOneEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLogicOpEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["logicOpEnable"], logicOpEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorBlendEnables)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorBlendEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstAttachment"] = firstAttachment;
        args["attachmentCount"] = attachmentCount;
        Bool32ToJson(args["pColorBlendEnables"], pColorBlendEnables);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorBlendEquationEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstAttachment"] = firstAttachment;
        args["attachmentCount"] = attachmentCount;
        FieldToJson(args["pColorBlendEquations"], pColorBlendEquations);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorWriteMaskEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstAttachment"] = firstAttachment;
        args["attachmentCount"] = attachmentCount;
        FieldToJson(args["pColorWriteMasks"], pColorWriteMasks);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetTessellationDomainOriginEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["domainOrigin"] = domainOrigin;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizationStreamEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["rasterizationStream"] = rasterizationStream;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetConservativeRasterizationModeEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["conservativeRasterizationMode"] = conservativeRasterizationMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetExtraPrimitiveOverestimationSizeEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["extraPrimitiveOverestimationSize"], extraPrimitiveOverestimationSize);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClipEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["depthClipEnable"], depthClipEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleLocationsEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["sampleLocationsEnable"], sampleLocationsEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorBlendAdvancedEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstAttachment"] = firstAttachment;
        args["attachmentCount"] = attachmentCount;
        FieldToJson(args["pColorBlendAdvanced"], pColorBlendAdvanced);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetProvokingVertexModeEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["provokingVertexMode"] = provokingVertexMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineRasterizationModeEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["lineRasterizationMode"] = lineRasterizationMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["stippledLineEnable"], stippledLineEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClipNegativeOneToOneEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["negativeOneToOne"], negativeOneToOne);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWScalingEnableNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["viewportWScalingEnable"], viewportWScalingEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportSwizzleNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["firstViewport"] = firstViewport;
        args["viewportCount"] = viewportCount;
        FieldToJson(args["pViewportSwizzles"], pViewportSwizzles);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageToColorEnableNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["coverageToColorEnable"], coverageToColorEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageToColorLocationNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["coverageToColorLocation"] = coverageToColorLocation;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationModeNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["coverageModulationMode"] = coverageModulationMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationTableEnableNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["coverageModulationTableEnable"], coverageModulationTableEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationTableNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["coverageModulationTableCount"] = coverageModulationTableCount;
        FieldToJson(args["pCoverageModulationTable"], pCoverageModulationTable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetShadingRateImageEnableNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["shadingRateImageEnable"], shadingRateImageEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRepresentativeFragmentTestEnableNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["representativeFragmentTestEnable"], representativeFragmentTestEnable);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageReductionModeNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["coverageReductionMode"] = coverageReductionMode;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetShaderModuleIdentifierEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["shaderModule"], shaderModule);
        FieldToJson(args["pIdentifier"], pIdentifier);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetShaderModuleCreateInfoIdentifierEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pIdentifier"], pIdentifier);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo,
    PointerDecoder<uint32_t>*                   pFormatCount,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pOpticalFlowImageFormatInfo"], pOpticalFlowImageFormatInfo);
        FieldToJson(args["pFormatCount"], pFormatCount);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateOpticalFlowSessionNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSession"], pSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyOpticalFlowSessionNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["session"], session);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindOpticalFlowSessionImageNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["session"], session);
        args["bindingPoint"] = bindingPoint;
        HandleToJson(args["view"], view);
        args["layout"] = layout;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdOpticalFlowExecuteNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["session"], session);
        FieldToJson(args["pExecuteInfo"], pExecuteInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAntiLagUpdateAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAntiLagDataAMD>* pData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAntiLagUpdateAMD");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateShadersEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkShaderCreateInfoEXT>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateShadersEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["createInfoCount"] = createInfoCount;
        FieldToJson(args["pCreateInfos"], pCreateInfos);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pShaders"], pShaders);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shader,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyShaderEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["shader"], shader);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetShaderBinaryDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            shader,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetShaderBinaryDataEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["shader"], shader);
        FieldToJson(args["pDataSize"], pDataSize);
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    stageCount,
    PointerDecoder<VkShaderStageFlagBits>*      pStages,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindShadersEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["stageCount"] = stageCount;
        FieldToJson(args["pStages"], pStages);
        HandleToJson(args["pShaders"], pShaders);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDepthClampModeEXT                         depthClampMode,
    StructPointerDecoder<Decoded_VkDepthClampRangeEXT>* pDepthClampRange)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClampRangeEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["depthClampMode"] = depthClampMode;
        FieldToJson(args["pDepthClampRange"], pDepthClampRange);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    PointerDecoder<uint32_t>*                   pPropertiesCount,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetFramebufferTilePropertiesQCOM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["framebuffer"], framebuffer);
        FieldToJson(args["pPropertiesCount"], pPropertiesCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDynamicRenderingTilePropertiesQCOM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pRenderingInfo"], pRenderingInfo);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCooperativeVectorPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeVectorPropertiesNV>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkConvertCooperativeVectorMatrixInfoNV>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkConvertCooperativeVectorMatrixNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkConvertCooperativeVectorMatrixInfoNV>* pInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdConvertCooperativeVectorMatrixNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["infoCount"] = infoCount;
        FieldToJson(args["pInfos"], pInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetLatencySleepModeNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkLatencySleepModeInfoNV>* pSleepModeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetLatencySleepModeNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pSleepModeInfo"], pSleepModeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkLatencySleepNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkLatencySleepInfoNV>* pSleepInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkLatencySleepNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pSleepInfo"], pSleepInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetLatencyMarkerNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkSetLatencyMarkerInfoNV>* pLatencyMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetLatencyMarkerNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pLatencyMarkerInfo"], pLatencyMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetLatencyTimingsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkGetLatencyMarkerInfoNV>* pLatencyMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetLatencyTimingsNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["swapchain"], swapchain);
        FieldToJson(args["pLatencyMarkerInfo"], pLatencyMarkerInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueNotifyOutOfBandNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkOutOfBandQueueTypeInfoNV>* pQueueTypeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueNotifyOutOfBandNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue);
        FieldToJson(args["pQueueTypeInfo"], pQueueTypeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDataGraphPipelinesARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkDataGraphPipelineCreateInfoARM>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDataGraphPipelinesARM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["deferredOperation"], deferredOperation);
        HandleToJson(args["pipelineCache"], pipelineCache);
        args["createInfoCount"] = createInfoCount;
        FieldToJson(args["pCreateInfos"], pCreateInfos);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pPipelines"], pPipelines);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionCreateInfoARM>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDataGraphPipelineSessionARM>* pSession)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateDataGraphPipelineSessionARM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pSession"], pSession);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDataGraphPipelineSessionBindPointRequirementsARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionBindPointRequirementsInfoARM>* pInfo,
    PointerDecoder<uint32_t>*                   pBindPointRequirementCount,
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionBindPointRequirementARM>* pBindPointRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDataGraphPipelineSessionBindPointRequirementsARM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pBindPointRequirementCount"], pBindPointRequirementCount);
        FieldToJson(args["pBindPointRequirements"], pBindPointRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDataGraphPipelineSessionMemoryRequirementsARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionMemoryRequirementsInfoARM>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDataGraphPipelineSessionMemoryRequirementsARM");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBindDataGraphPipelineSessionMemoryARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindDataGraphPipelineSessionMemoryInfoARM>* pBindInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBindDataGraphPipelineSessionMemoryARM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["bindInfoCount"] = bindInfoCount;
        FieldToJson(args["pBindInfos"], pBindInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDataGraphPipelineSessionARM");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["session"], session);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchDataGraphARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkDataGraphPipelineDispatchInfoARM>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchDataGraphARM");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["session"], session);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDataGraphPipelineAvailablePropertiesARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDataGraphPipelineInfoARM>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pPropertiesCount,
    PointerDecoder<VkDataGraphPipelinePropertyARM>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDataGraphPipelineAvailablePropertiesARM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pPipelineInfo"], pPipelineInfo);
        FieldToJson(args["pPropertiesCount"], pPropertiesCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDataGraphPipelinePropertiesARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDataGraphPipelineInfoARM>* pPipelineInfo,
    uint32_t                                    propertiesCount,
    StructPointerDecoder<Decoded_VkDataGraphPipelinePropertyQueryResultARM>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDataGraphPipelinePropertiesARM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pPipelineInfo"], pPipelineInfo);
        args["propertiesCount"] = propertiesCount;
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    PointerDecoder<uint32_t>*                   pQueueFamilyDataGraphPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM>* pQueueFamilyDataGraphProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        FieldToJson(args["pQueueFamilyDataGraphPropertyCount"], pQueueFamilyDataGraphPropertyCount);
        FieldToJson(args["pQueueFamilyDataGraphProperties"], pQueueFamilyDataGraphProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM>* pQueueFamilyDataGraphProcessingEngineInfo,
    StructPointerDecoder<Decoded_VkQueueFamilyDataGraphProcessingEnginePropertiesARM>* pQueueFamilyDataGraphProcessingEngineProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pQueueFamilyDataGraphProcessingEngineInfo"], pQueueFamilyDataGraphProcessingEngineInfo);
        FieldToJson(args["pQueueFamilyDataGraphProcessingEngineProperties"], pQueueFamilyDataGraphProcessingEngineProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM>* pQueueFamilyDataGraphProperties,
    StructPointerDecoder<Decoded_VkBaseOutStructure>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        FieldToJson(args["pQueueFamilyDataGraphProperties"], pQueueFamilyDataGraphProperties);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAttachmentFeedbackLoopEnableEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["aspectMask"] = VkImageAspectFlags_t{aspectMask};
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindTileMemoryQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkTileMemoryBindInfoQCOM>* pTileMemoryBindInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindTileMemoryQCOM");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pTileMemoryBindInfo"], pTileMemoryBindInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDecompressMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDecompressMemoryInfoEXT>* pDecompressMemoryInfoEXT)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDecompressMemoryEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pDecompressMemoryInfoEXT"], pDecompressMemoryInfoEXT);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDecompressMemoryIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkMemoryDecompressionMethodFlagsEXT         decompressionMethod,
    VkDeviceAddress                             indirectCommandsAddress,
    VkDeviceAddress                             indirectCommandsCountAddress,
    uint32_t                                    maxDecompressionCount,
    uint32_t                                    stride)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDecompressMemoryIndirectCountEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["decompressionMethod"] = VkMemoryDecompressionMethodFlagsEXT_t{decompressionMethod};
        FieldToJsonAsHex(args["indirectCommandsAddress"], indirectCommandsAddress);
        FieldToJsonAsHex(args["indirectCommandsCountAddress"], indirectCommandsCountAddress);
        args["maxDecompressionCount"] = maxDecompressionCount;
        args["stride"] = stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPartitionedAccelerationStructuresBuildSizesNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPartitionedAccelerationStructureInstancesInputNV>* pInfo,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPartitionedAccelerationStructuresBuildSizesNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pSizeInfo"], pSizeInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBuildPartitionedAccelerationStructuresNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBuildPartitionedAccelerationStructureInfoNV>* pBuildInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBuildPartitionedAccelerationStructuresNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pBuildInfo"], pBuildInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetGeneratedCommandsMemoryRequirementsEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo,
    format::HandleId                            stateCommandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPreprocessGeneratedCommandsEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pGeneratedCommandsInfo"], pGeneratedCommandsInfo);
        HandleToJson(args["stateCommandBuffer"], stateCommandBuffer);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdExecuteGeneratedCommandsEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        Bool32ToJson(args["isPreprocessed"], isPreprocessed);
        FieldToJson(args["pGeneratedCommandsInfo"], pGeneratedCommandsInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutEXT>* pIndirectCommandsLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateIndirectCommandsLayoutEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pIndirectCommandsLayout"], pIndirectCommandsLayout);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyIndirectCommandsLayoutEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["indirectCommandsLayout"], indirectCommandsLayout);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectExecutionSetCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectExecutionSetEXT>* pIndirectExecutionSet)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateIndirectExecutionSetEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pIndirectExecutionSet"], pIndirectExecutionSet);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectExecutionSet,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyIndirectExecutionSetEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["indirectExecutionSet"], indirectExecutionSet);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUpdateIndirectExecutionSetPipelineEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectExecutionSet,
    uint32_t                                    executionSetWriteCount,
    StructPointerDecoder<Decoded_VkWriteIndirectExecutionSetPipelineEXT>* pExecutionSetWrites)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUpdateIndirectExecutionSetPipelineEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["indirectExecutionSet"], indirectExecutionSet);
        args["executionSetWriteCount"] = executionSetWriteCount;
        FieldToJson(args["pExecutionSetWrites"], pExecutionSetWrites);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUpdateIndirectExecutionSetShaderEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectExecutionSet,
    uint32_t                                    executionSetWriteCount,
    StructPointerDecoder<Decoded_VkWriteIndirectExecutionSetShaderEXT>* pExecutionSetWrites)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUpdateIndirectExecutionSetShaderEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["indirectExecutionSet"], indirectExecutionSet);
        args["executionSetWriteCount"] = executionSetWriteCount;
        FieldToJson(args["pExecutionSetWrites"], pExecutionSetWrites);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixFlexibleDimensionsPropertiesNV>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        FieldToJson(args["pPropertyCount"], pPropertyCount);
        FieldToJson(args["pProperties"], pProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryMetalHandleEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetMetalHandleInfoEXT>* pGetMetalHandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryMetalHandleEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pGetMetalHandleInfo"], pGetMetalHandleInfo);
        FieldToJson(args["pHandle"], pHandle);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetMemoryMetalHandlePropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHandle,
    StructPointerDecoder<Decoded_VkMemoryMetalHandlePropertiesEXT>* pMemoryMetalHandleProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetMemoryMetalHandlePropertiesEXT");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["handleType"] = handleType;
        args["pHandle"] = pHandle;
        FieldToJson(args["pMemoryMetalHandleProperties"], pMemoryMetalHandleProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    PointerDecoder<uint32_t>*                   pCounterCount,
    StructPointerDecoder<Decoded_VkPerformanceCounterARM>* pCounters,
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionARM>* pCounterDescriptions)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        FieldToJson(args["pCounterCount"], pCounterCount);
        FieldToJson(args["pCounters"], pCounters);
        FieldToJson(args["pCounterDescriptions"], pCounterDescriptions);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRendering2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingEndInfoKHR>* pRenderingEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRendering2EXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pRenderingEndInfo"], pRenderingEndInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginCustomResolveEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBeginCustomResolveInfoEXT>* pBeginCustomResolveInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginCustomResolveEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pBeginCustomResolveInfo"], pBeginCustomResolveInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    StructPointerDecoder<Decoded_VkQueueFamilyDataGraphPropertiesARM>* pQueueFamilyDataGraphProperties,
    StructPointerDecoder<Decoded_VkDataGraphOpticalFlowImageFormatInfoARM>* pOpticalFlowImageFormatInfo,
    PointerDecoder<uint32_t>*                   pFormatCount,
    StructPointerDecoder<Decoded_VkDataGraphOpticalFlowImageFormatPropertiesARM>* pImageFormatProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice);
        args["queueFamilyIndex"] = queueFamilyIndex;
        FieldToJson(args["pQueueFamilyDataGraphProperties"], pQueueFamilyDataGraphProperties);
        FieldToJson(args["pOpticalFlowImageFormatInfo"], pOpticalFlowImageFormatInfo);
        FieldToJson(args["pFormatCount"], pFormatCount);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetComputeOccupancyPriorityNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkComputeOccupancyPriorityParametersNV>* pParameters)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetComputeOccupancyPriorityNV");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pParameters"], pParameters);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartIndexEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    primitiveRestartIndex)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveRestartIndexEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["primitiveRestartIndex"] = primitiveRestartIndex;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateAccelerationStructureKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pCreateInfo"], pCreateInfo);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pAccelerationStructure"], pAccelerationStructure);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyAccelerationStructureKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["accelerationStructure"], accelerationStructure);
        FieldToJson(args["pAllocator"], pAllocator);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBuildAccelerationStructuresKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["infoCount"] = infoCount;
        FieldToJson(args["pInfos"], pInfos);
        FieldToJson(args["ppBuildRangeInfos"], ppBuildRangeInfos);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyAccelerationStructureToMemoryKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["deferredOperation"], deferredOperation);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMemoryToAccelerationStructureKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["deferredOperation"], deferredOperation);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkWriteAccelerationStructuresPropertiesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["accelerationStructureCount"] = accelerationStructureCount;
        HandleToJson(args["pAccelerationStructures"], pAccelerationStructures);
        args["queryType"] = queryType;
        args["dataSize"] = dataSize;
        FieldToJson(args["pData"], pData);
        args["stride"] = stride;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyAccelerationStructureKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyAccelerationStructureToMemoryKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToAccelerationStructureKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureDeviceAddressKHR");
    FieldToJsonAsHex(jdata[NameReturn()], returnValue);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pInfo"], pInfo);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdWriteAccelerationStructuresPropertiesKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["accelerationStructureCount"] = accelerationStructureCount;
        HandleToJson(args["pAccelerationStructures"], pAccelerationStructures);
        args["queryType"] = queryType;
        HandleToJson(args["queryPool"], queryPool);
        args["firstQuery"] = firstQuery;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceAccelerationStructureCompatibilityKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        FieldToJson(args["pVersionInfo"], pVersionInfo);
        FieldToJson(args["pCompatibility"], pCompatibility);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
    PointerDecoder<uint32_t>*                   pMaxPrimitiveCounts,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureBuildSizesKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        args["buildType"] = buildType;
        FieldToJson(args["pBuildInfo"], pBuildInfo);
        FieldToJson(args["pMaxPrimitiveCounts"], pMaxPrimitiveCounts);
        FieldToJson(args["pSizeInfo"], pSizeInfo);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdTraceRaysKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pRaygenShaderBindingTable"], pRaygenShaderBindingTable);
        FieldToJson(args["pMissShaderBindingTable"], pMissShaderBindingTable);
        FieldToJson(args["pHitShaderBindingTable"], pHitShaderBindingTable);
        FieldToJson(args["pCallableShaderBindingTable"], pCallableShaderBindingTable);
        args["width"] = width;
        args["height"] = height;
        args["depth"] = depth;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateRayTracingPipelinesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["deferredOperation"], deferredOperation);
        HandleToJson(args["pipelineCache"], pipelineCache);
        args["createInfoCount"] = createInfoCount;
        FieldToJson(args["pCreateInfos"], pCreateInfos);
        FieldToJson(args["pAllocator"], pAllocator);
        HandleToJson(args["pPipelines"], pPipelines);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipeline"], pipeline);
        args["firstGroup"] = firstGroup;
        args["groupCount"] = groupCount;
        args["dataSize"] = dataSize;
        FieldToJson(args["pData"], pData);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdTraceRaysIndirectKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        FieldToJson(args["pRaygenShaderBindingTable"], pRaygenShaderBindingTable);
        FieldToJson(args["pMissShaderBindingTable"], pMissShaderBindingTable);
        FieldToJson(args["pHitShaderBindingTable"], pHitShaderBindingTable);
        FieldToJson(args["pCallableShaderBindingTable"], pCallableShaderBindingTable);
        FieldToJsonAsHex(args["indirectDeviceAddress"], indirectDeviceAddress);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceSize                                returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRayTracingShaderGroupStackSizeKHR");
    jdata[NameReturn()] = returnValue;
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device);
        HandleToJson(args["pipeline"], pipeline);
        args["group"] = group;
        args["groupShader"] = groupShader;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRayTracingPipelineStackSizeKHR");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["pipelineStackSize"] = pipelineStackSize;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        args["groupCountX"] = groupCountX;
        args["groupCountY"] = groupCountY;
        args["groupCountZ"] = groupCountZ;
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirectEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        args["drawCount"] = drawCount;
        args["stride"] = stride;
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksIndirectCountEXT");
    jdata[NameCommandIndex()] = GetCommandBufferRecordIndex(commandBuffer);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer);
        HandleToJson(args["buffer"], buffer);
        args["offset"] = offset;
        HandleToJson(args["countBuffer"], countBuffer);
        args["countBufferOffset"] = countBufferOffset;
        args["maxDrawCount"] = maxDrawCount;
        args["stride"] = stride;
    WriteBlockEnd();
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
