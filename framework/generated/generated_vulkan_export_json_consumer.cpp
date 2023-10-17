/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCreateInstance");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pInstance"], pInstance, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyInstance");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pPhysicalDeviceCount"], pPhysicalDeviceCount, json_options_);
        HandleToJson(args["pPhysicalDevices"], pPhysicalDevices, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pFeatures"], pFeatures, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["format"], format, json_options_);
        FieldToJson(args["pFormatProperties"], pFormatProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["format"], format, json_options_);
        FieldToJson(args["type"], type, json_options_);
        FieldToJson(args["tiling"], tiling, json_options_);
        FieldToJson(VkImageUsageFlags_t(), args["usage"], usage, json_options_);
        FieldToJson(VkImageCreateFlags_t(), args["flags"], flags, json_options_);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount, json_options_);
        FieldToJson(args["pQueueFamilyProperties"], pQueueFamilyProperties, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pMemoryProperties"], pMemoryProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pDevice"], pDevice, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDestroyDevice");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options_);
        FieldToJson(args["queueIndex"], queueIndex, json_options_);
        HandleToJson(args["pQueue"], pQueue, json_options_);
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
    FieldToJson(jdata[NameSubmitIndex()], ++submit_index_, json_options_);
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options_);
        FieldToJson(args["submitCount"], submitCount, json_options_);
        FieldToJson(args["pSubmits"], pSubmits, json_options_);
        HandleToJson(args["fence"], fence, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueWaitIdle");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDeviceWaitIdle");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pAllocateInfo"], pAllocateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pMemory"], pMemory, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["memory"], memory, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["memory"], memory, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        FieldToJson(args["size"], size, json_options_);
        FieldToJson(VkMemoryMapFlags_t(), args["flags"], flags, json_options_);
        FieldToJsonAsHex(args["ppData"], ppData, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUnmapMemory");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["memory"], memory, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["memoryRangeCount"], memoryRangeCount, json_options_);
        FieldToJson(args["pMemoryRanges"], pMemoryRanges, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["memoryRangeCount"], memoryRangeCount, json_options_);
        FieldToJson(args["pMemoryRanges"], pMemoryRanges, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["memory"], memory, json_options_);
        FieldToJson(args["pCommittedMemoryInBytes"], pCommittedMemoryInBytes, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        HandleToJson(args["memory"], memory, json_options_);
        FieldToJson(args["memoryOffset"], memoryOffset, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["image"], image, json_options_);
        HandleToJson(args["memory"], memory, json_options_);
        FieldToJson(args["memoryOffset"], memoryOffset, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["image"], image, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["image"], image, json_options_);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options_);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["format"], format, json_options_);
        FieldToJson(args["type"], type, json_options_);
        FieldToJson(args["samples"], samples, json_options_);
        FieldToJson(VkImageUsageFlags_t(), args["usage"], usage, json_options_);
        FieldToJson(args["tiling"], tiling, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options_);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options_);
        FieldToJson(args["pBindInfo"], pBindInfo, json_options_);
        HandleToJson(args["fence"], fence, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pFence"], pFence, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["fence"], fence, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["fenceCount"], fenceCount, json_options_);
        HandleToJson(args["pFences"], pFences, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetFenceStatus");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["fence"], fence, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["fenceCount"], fenceCount, json_options_);
        HandleToJson(args["pFences"], pFences, json_options_);
        VkBool32ToJson(args["waitAll"], waitAll, json_options_);
        FieldToJson(args["timeout"], timeout, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSemaphore"], pSemaphore, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["semaphore"], semaphore, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pEvent"], pEvent, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["event"], event, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetEventStatus");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["event"], event, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetEvent");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["event"], event, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetEvent");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["event"], event, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pQueryPool"], pQueryPool, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["firstQuery"], firstQuery, json_options_);
        FieldToJson(args["queryCount"], queryCount, json_options_);
        FieldToJson(args["dataSize"], dataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
        FieldToJson(VkQueryResultFlags_t(), args["flags"], flags, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pBuffer"], pBuffer, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pView"], pView, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["bufferView"], bufferView, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pImage"], pImage, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["image"], image, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["image"], image, json_options_);
        FieldToJson(args["pSubresource"], pSubresource, json_options_);
        FieldToJson(args["pLayout"], pLayout, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pView"], pView, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["imageView"], imageView, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["shaderModule"], shaderModule, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["dstCache"], dstCache, json_options_);
        FieldToJson(args["srcCacheCount"], srcCacheCount, json_options_);
        HandleToJson(args["pSrcCaches"], pSrcCaches, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options_);
        FieldToJson(args["createInfoCount"], createInfoCount, json_options_);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pPipelines"], pPipelines, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options_);
        FieldToJson(args["createInfoCount"], createInfoCount, json_options_);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pPipelines"], pPipelines, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipeline"], pipeline, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pPipelineLayout"], pPipelineLayout, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipelineLayout"], pipelineLayout, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSampler"], pSampler, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["sampler"], sampler, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSetLayout"], pSetLayout, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["descriptorSetLayout"], descriptorSetLayout, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pDescriptorPool"], pDescriptorPool, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["descriptorPool"], descriptorPool, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["descriptorPool"], descriptorPool, json_options_);
        FieldToJson(VkDescriptorPoolResetFlags_t(), args["flags"], flags, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pAllocateInfo"], pAllocateInfo, json_options_);
        HandleToJson(args["pDescriptorSets"], pDescriptorSets, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["descriptorPool"], descriptorPool, json_options_);
        FieldToJson(args["descriptorSetCount"], descriptorSetCount, json_options_);
        HandleToJson(args["pDescriptorSets"], pDescriptorSets, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["descriptorWriteCount"], descriptorWriteCount, json_options_);
        FieldToJson(args["pDescriptorWrites"], pDescriptorWrites, json_options_);
        FieldToJson(args["descriptorCopyCount"], descriptorCopyCount, json_options_);
        FieldToJson(args["pDescriptorCopies"], pDescriptorCopies, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pFramebuffer"], pFramebuffer, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["framebuffer"], framebuffer, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pRenderPass"], pRenderPass, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["renderPass"], renderPass, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["renderPass"], renderPass, json_options_);
        FieldToJson(args["pGranularity"], pGranularity, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pCommandPool"], pCommandPool, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["commandPool"], commandPool, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["commandPool"], commandPool, json_options_);
        FieldToJson(VkCommandPoolResetFlags_t(), args["flags"], flags, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pAllocateInfo"], pAllocateInfo, json_options_);
        HandleToJson(args["pCommandBuffers"], pCommandBuffers, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["commandPool"], commandPool, json_options_);
        FieldToJson(args["commandBufferCount"], commandBufferCount, json_options_);
        HandleToJson(args["pCommandBuffers"], pCommandBuffers, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkBeginCommandBuffer");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pBeginInfo"], pBeginInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkEndCommandBuffer");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkResetCommandBuffer");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkCommandBufferResetFlags_t(), args["flags"], flags, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindPipeline");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pipelineBindPoint"], pipelineBindPoint, json_options_);
        HandleToJson(args["pipeline"], pipeline, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstViewport"], firstViewport, json_options_);
        FieldToJson(args["viewportCount"], viewportCount, json_options_);
        FieldToJson(args["pViewports"], pViewports, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstScissor"], firstScissor, json_options_);
        FieldToJson(args["scissorCount"], scissorCount, json_options_);
        FieldToJson(args["pScissors"], pScissors, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineWidth");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["lineWidth"], lineWidth, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["depthBiasConstantFactor"], depthBiasConstantFactor, json_options_);
        FieldToJson(args["depthBiasClamp"], depthBiasClamp, json_options_);
        FieldToJson(args["depthBiasSlopeFactor"], depthBiasSlopeFactor, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetBlendConstants");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["blendConstants"], blendConstants, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBounds");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["minDepthBounds"], minDepthBounds, json_options_);
        FieldToJson(args["maxDepthBounds"], maxDepthBounds, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilCompareMask");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkStencilFaceFlags_t(), args["faceMask"], faceMask, json_options_);
        FieldToJson(args["compareMask"], compareMask, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilWriteMask");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkStencilFaceFlags_t(), args["faceMask"], faceMask, json_options_);
        FieldToJson(args["writeMask"], writeMask, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilReference");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkStencilFaceFlags_t(), args["faceMask"], faceMask, json_options_);
        FieldToJson(args["reference"], reference, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pipelineBindPoint"], pipelineBindPoint, json_options_);
        HandleToJson(args["layout"], layout, json_options_);
        FieldToJson(args["firstSet"], firstSet, json_options_);
        FieldToJson(args["descriptorSetCount"], descriptorSetCount, json_options_);
        HandleToJson(args["pDescriptorSets"], pDescriptorSets, json_options_);
        FieldToJson(args["dynamicOffsetCount"], dynamicOffsetCount, json_options_);
        FieldToJson(args["pDynamicOffsets"], pDynamicOffsets, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        FieldToJson(args["indexType"], indexType, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstBinding"], firstBinding, json_options_);
        FieldToJson(args["bindingCount"], bindingCount, json_options_);
        HandleToJson(args["pBuffers"], pBuffers, json_options_);
        FieldToJson(args["pOffsets"], pOffsets, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["vertexCount"], vertexCount, json_options_);
        FieldToJson(args["instanceCount"], instanceCount, json_options_);
        FieldToJson(args["firstVertex"], firstVertex, json_options_);
        FieldToJson(args["firstInstance"], firstInstance, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["indexCount"], indexCount, json_options_);
        FieldToJson(args["instanceCount"], instanceCount, json_options_);
        FieldToJson(args["firstIndex"], firstIndex, json_options_);
        FieldToJson(args["vertexOffset"], vertexOffset, json_options_);
        FieldToJson(args["firstInstance"], firstInstance, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        FieldToJson(args["drawCount"], drawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        FieldToJson(args["drawCount"], drawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["groupCountX"], groupCountX, json_options_);
        FieldToJson(args["groupCountY"], groupCountY, json_options_);
        FieldToJson(args["groupCountZ"], groupCountZ, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDispatchIndirect");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["srcBuffer"], srcBuffer, json_options_);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options_);
        FieldToJson(args["regionCount"], regionCount, json_options_);
        FieldToJson(args["pRegions"], pRegions, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["srcImage"], srcImage, json_options_);
        FieldToJson(args["srcImageLayout"], srcImageLayout, json_options_);
        HandleToJson(args["dstImage"], dstImage, json_options_);
        FieldToJson(args["dstImageLayout"], dstImageLayout, json_options_);
        FieldToJson(args["regionCount"], regionCount, json_options_);
        FieldToJson(args["pRegions"], pRegions, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["srcImage"], srcImage, json_options_);
        FieldToJson(args["srcImageLayout"], srcImageLayout, json_options_);
        HandleToJson(args["dstImage"], dstImage, json_options_);
        FieldToJson(args["dstImageLayout"], dstImageLayout, json_options_);
        FieldToJson(args["regionCount"], regionCount, json_options_);
        FieldToJson(args["pRegions"], pRegions, json_options_);
        FieldToJson(args["filter"], filter, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["srcBuffer"], srcBuffer, json_options_);
        HandleToJson(args["dstImage"], dstImage, json_options_);
        FieldToJson(args["dstImageLayout"], dstImageLayout, json_options_);
        FieldToJson(args["regionCount"], regionCount, json_options_);
        FieldToJson(args["pRegions"], pRegions, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["srcImage"], srcImage, json_options_);
        FieldToJson(args["srcImageLayout"], srcImageLayout, json_options_);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options_);
        FieldToJson(args["regionCount"], regionCount, json_options_);
        FieldToJson(args["pRegions"], pRegions, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options_);
        FieldToJson(args["dstOffset"], dstOffset, json_options_);
        FieldToJson(args["dataSize"], dataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options_);
        FieldToJson(args["dstOffset"], dstOffset, json_options_);
        FieldToJson(args["size"], size, json_options_);
        FieldToJson(args["data"], data, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["image"], image, json_options_);
        FieldToJson(args["imageLayout"], imageLayout, json_options_);
        FieldToJson(args["pColor"], pColor, json_options_);
        FieldToJson(args["rangeCount"], rangeCount, json_options_);
        FieldToJson(args["pRanges"], pRanges, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["image"], image, json_options_);
        FieldToJson(args["imageLayout"], imageLayout, json_options_);
        FieldToJson(args["pDepthStencil"], pDepthStencil, json_options_);
        FieldToJson(args["rangeCount"], rangeCount, json_options_);
        FieldToJson(args["pRanges"], pRanges, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options_);
        FieldToJson(args["pAttachments"], pAttachments, json_options_);
        FieldToJson(args["rectCount"], rectCount, json_options_);
        FieldToJson(args["pRects"], pRects, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["srcImage"], srcImage, json_options_);
        FieldToJson(args["srcImageLayout"], srcImageLayout, json_options_);
        HandleToJson(args["dstImage"], dstImage, json_options_);
        FieldToJson(args["dstImageLayout"], dstImageLayout, json_options_);
        FieldToJson(args["regionCount"], regionCount, json_options_);
        FieldToJson(args["pRegions"], pRegions, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["event"], event, json_options_);
        FieldToJson(VkPipelineStageFlags_t(), args["stageMask"], stageMask, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["event"], event, json_options_);
        FieldToJson(VkPipelineStageFlags_t(), args["stageMask"], stageMask, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["eventCount"], eventCount, json_options_);
        HandleToJson(args["pEvents"], pEvents, json_options_);
        FieldToJson(VkPipelineStageFlags_t(), args["srcStageMask"], srcStageMask, json_options_);
        FieldToJson(VkPipelineStageFlags_t(), args["dstStageMask"], dstStageMask, json_options_);
        FieldToJson(args["memoryBarrierCount"], memoryBarrierCount, json_options_);
        FieldToJson(args["pMemoryBarriers"], pMemoryBarriers, json_options_);
        FieldToJson(args["bufferMemoryBarrierCount"], bufferMemoryBarrierCount, json_options_);
        FieldToJson(args["pBufferMemoryBarriers"], pBufferMemoryBarriers, json_options_);
        FieldToJson(args["imageMemoryBarrierCount"], imageMemoryBarrierCount, json_options_);
        FieldToJson(args["pImageMemoryBarriers"], pImageMemoryBarriers, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkPipelineStageFlags_t(), args["srcStageMask"], srcStageMask, json_options_);
        FieldToJson(VkPipelineStageFlags_t(), args["dstStageMask"], dstStageMask, json_options_);
        FieldToJson(VkDependencyFlags_t(), args["dependencyFlags"], dependencyFlags, json_options_);
        FieldToJson(args["memoryBarrierCount"], memoryBarrierCount, json_options_);
        FieldToJson(args["pMemoryBarriers"], pMemoryBarriers, json_options_);
        FieldToJson(args["bufferMemoryBarrierCount"], bufferMemoryBarrierCount, json_options_);
        FieldToJson(args["pBufferMemoryBarriers"], pBufferMemoryBarriers, json_options_);
        FieldToJson(args["imageMemoryBarrierCount"], imageMemoryBarrierCount, json_options_);
        FieldToJson(args["pImageMemoryBarriers"], pImageMemoryBarriers, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["query"], query, json_options_);
        FieldToJson(VkQueryControlFlags_t(), args["flags"], flags, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndQuery");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["query"], query, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["firstQuery"], firstQuery, json_options_);
        FieldToJson(args["queryCount"], queryCount, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pipelineStage"], pipelineStage, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["query"], query, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["firstQuery"], firstQuery, json_options_);
        FieldToJson(args["queryCount"], queryCount, json_options_);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options_);
        FieldToJson(args["dstOffset"], dstOffset, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
        FieldToJson(VkQueryResultFlags_t(), args["flags"], flags, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pRenderPassBegin"], pRenderPassBegin, json_options_);
        FieldToJson(args["contents"], contents, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["contents"], contents, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdExecuteCommands");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["commandBufferCount"], commandBufferCount, json_options_);
        HandleToJson(args["pCommandBuffers"], pCommandBuffers, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options_);
        FieldToJson(args["pBindInfos"], pBindInfos, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options_);
        FieldToJson(args["pBindInfos"], pBindInfos, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["heapIndex"], heapIndex, json_options_);
        FieldToJson(args["localDeviceIndex"], localDeviceIndex, json_options_);
        FieldToJson(args["remoteDeviceIndex"], remoteDeviceIndex, json_options_);
        FieldToJson(args["pPeerMemoryFeatures"], pPeerMemoryFeatures, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDeviceMask");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["deviceMask"], deviceMask, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["baseGroupX"], baseGroupX, json_options_);
        FieldToJson(args["baseGroupY"], baseGroupY, json_options_);
        FieldToJson(args["baseGroupZ"], baseGroupZ, json_options_);
        FieldToJson(args["groupCountX"], groupCountX, json_options_);
        FieldToJson(args["groupCountY"], groupCountY, json_options_);
        FieldToJson(args["groupCountZ"], groupCountZ, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pPhysicalDeviceGroupCount"], pPhysicalDeviceGroupCount, json_options_);
        FieldToJson(args["pPhysicalDeviceGroupProperties"], pPhysicalDeviceGroupProperties, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options_);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pFeatures"], pFeatures, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["format"], format, json_options_);
        FieldToJson(args["pFormatProperties"], pFormatProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pImageFormatInfo"], pImageFormatInfo, json_options_);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount, json_options_);
        FieldToJson(args["pQueueFamilyProperties"], pQueueFamilyProperties, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties2");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pMemoryProperties"], pMemoryProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pFormatInfo"], pFormatInfo, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["commandPool"], commandPool, json_options_);
        FieldToJson(VkCommandPoolTrimFlags_t(), args["flags"], flags, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pQueueInfo"], pQueueInfo, json_options_);
        HandleToJson(args["pQueue"], pQueue, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pYcbcrConversion"], pYcbcrConversion, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["ycbcrConversion"], ycbcrConversion, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pDescriptorUpdateTemplate"], pDescriptorUpdateTemplate, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["descriptorUpdateTemplate"], descriptorUpdateTemplate, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pExternalBufferInfo"], pExternalBufferInfo, json_options_);
        FieldToJson(args["pExternalBufferProperties"], pExternalBufferProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pExternalFenceInfo"], pExternalFenceInfo, json_options_);
        FieldToJson(args["pExternalFenceProperties"], pExternalFenceProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pExternalSemaphoreInfo"], pExternalSemaphoreInfo, json_options_);
        FieldToJson(args["pExternalSemaphoreProperties"], pExternalSemaphoreProperties, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pSupport"], pSupport, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        HandleToJson(args["countBuffer"], countBuffer, json_options_);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options_);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        HandleToJson(args["countBuffer"], countBuffer, json_options_);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options_);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pRenderPass"], pRenderPass, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pRenderPassBegin"], pRenderPassBegin, json_options_);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo, json_options_);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["firstQuery"], firstQuery, json_options_);
        FieldToJson(args["queryCount"], queryCount, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["semaphore"], semaphore, json_options_);
        FieldToJson(args["pValue"], pValue, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pWaitInfo"], pWaitInfo, json_options_);
        FieldToJson(args["timeout"], timeout, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSignalSemaphore");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pSignalInfo"], pSignalInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddress");
    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferOpaqueCaptureAddress");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryOpaqueCaptureAddress");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pToolCount"], pToolCount, json_options_);
        FieldToJson(args["pToolProperties"], pToolProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pPrivateDataSlot"], pPrivateDataSlot, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["objectType"], objectType, json_options_);
        HandleToJson(args["objectHandle"], objectHandle, json_options_);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options_);
        FieldToJson(args["data"], data, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["objectType"], objectType, json_options_);
        HandleToJson(args["objectHandle"], objectHandle, json_options_);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["event"], event, json_options_);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["event"], event, json_options_);
        FieldToJson(VkPipelineStageFlags2_t(), args["stageMask"], stageMask, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["eventCount"], eventCount, json_options_);
        HandleToJson(args["pEvents"], pEvents, json_options_);
        FieldToJson(args["pDependencyInfos"], pDependencyInfos, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPipelineBarrier2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkPipelineStageFlags2_t(), args["stage"], stage, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["query"], query, json_options_);
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
    FieldToJson(jdata[NameSubmitIndex()], ++submit_index_, json_options_);
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options_);
        FieldToJson(args["submitCount"], submitCount, json_options_);
        FieldToJson(args["pSubmits"], pSubmits, json_options_);
        HandleToJson(args["fence"], fence, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBuffer2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pCopyBufferInfo"], pCopyBufferInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImage2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pCopyImageInfo"], pCopyImageInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBufferToImage2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pCopyBufferToImageInfo"], pCopyBufferToImageInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToBuffer2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pCopyImageToBufferInfo"], pCopyImageToBufferInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBlitImage2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pBlitImageInfo"], pBlitImageInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResolveImage2");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pResolveImageInfo"], pResolveImageInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRendering");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pRenderingInfo"], pRenderingInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRendering");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCullMode");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkCullModeFlags_t(), args["cullMode"], cullMode, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFrontFace");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["frontFace"], frontFace, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveTopology");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["primitiveTopology"], primitiveTopology, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWithCount");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["viewportCount"], viewportCount, json_options_);
        FieldToJson(args["pViewports"], pViewports, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetScissorWithCount");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["scissorCount"], scissorCount, json_options_);
        FieldToJson(args["pScissors"], pScissors, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstBinding"], firstBinding, json_options_);
        FieldToJson(args["bindingCount"], bindingCount, json_options_);
        HandleToJson(args["pBuffers"], pBuffers, json_options_);
        FieldToJson(args["pOffsets"], pOffsets, json_options_);
        FieldToJson(args["pSizes"], pSizes, json_options_);
        FieldToJson(args["pStrides"], pStrides, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthTestEnable");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["depthTestEnable"], depthTestEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthWriteEnable");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["depthWriteEnable"], depthWriteEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthCompareOp");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["depthCompareOp"], depthCompareOp, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBoundsTestEnable");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["depthBoundsTestEnable"], depthBoundsTestEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilTestEnable");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["stencilTestEnable"], stencilTestEnable, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkStencilFaceFlags_t(), args["faceMask"], faceMask, json_options_);
        FieldToJson(args["failOp"], failOp, json_options_);
        FieldToJson(args["passOp"], passOp, json_options_);
        FieldToJson(args["depthFailOp"], depthFailOp, json_options_);
        FieldToJson(args["compareOp"], compareOp, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizerDiscardEnable");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["rasterizerDiscardEnable"], rasterizerDiscardEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBiasEnable");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["depthBiasEnable"], depthBiasEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveRestartEnable");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["primitiveRestartEnable"], primitiveRestartEnable, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options_);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options_);
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
        HandleToJson(args["instance"], instance, json_options_);
        HandleToJson(args["surface"], surface, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options_);
        HandleToJson(args["surface"], surface, json_options_);
        VkBool32ToJson(args["pSupported"], pSupported, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["surface"], surface, json_options_);
        FieldToJson(args["pSurfaceCapabilities"], pSurfaceCapabilities, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["surface"], surface, json_options_);
        FieldToJson(args["pSurfaceFormatCount"], pSurfaceFormatCount, json_options_);
        FieldToJson(args["pSurfaceFormats"], pSurfaceFormats, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["surface"], surface, json_options_);
        FieldToJson(args["pPresentModeCount"], pPresentModeCount, json_options_);
        FieldToJson(args["pPresentModes"], pPresentModes, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSwapchain"], pSwapchain, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapchain"], swapchain, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapchain"], swapchain, json_options_);
        FieldToJson(args["pSwapchainImageCount"], pSwapchainImageCount, json_options_);
        HandleToJson(args["pSwapchainImages"], pSwapchainImages, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapchain"], swapchain, json_options_);
        FieldToJson(args["timeout"], timeout, json_options_);
        HandleToJson(args["semaphore"], semaphore, json_options_);
        HandleToJson(args["fence"], fence, json_options_);
        FieldToJson(args["pImageIndex"], pImageIndex, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueuePresentKHR");
    FieldToJson(jdata[NameSubmitIndex()], ++submit_index_, json_options_);
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options_);
        FieldToJson(args["pPresentInfo"], pPresentInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceGroupPresentCapabilitiesKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pDeviceGroupPresentCapabilities"], pDeviceGroupPresentCapabilities, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["surface"], surface, json_options_);
        FieldToJson(args["pModes"], pModes, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["surface"], surface, json_options_);
        FieldToJson(args["pRectCount"], pRectCount, json_options_);
        FieldToJson(args["pRects"], pRects, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pAcquireInfo"], pAcquireInfo, json_options_);
        FieldToJson(args["pImageIndex"], pImageIndex, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["planeIndex"], planeIndex, json_options_);
        FieldToJson(args["pDisplayCount"], pDisplayCount, json_options_);
        HandleToJson(args["pDisplays"], pDisplays, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["display"], display, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["display"], display, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pMode"], pMode, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["mode"], mode, json_options_);
        FieldToJson(args["planeIndex"], planeIndex, json_options_);
        FieldToJson(args["pCapabilities"], pCapabilities, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["swapchainCount"], swapchainCount, json_options_);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSwapchains"], pSwapchains, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
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
            VkBool32ToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options_);
        FieldToJson(args["dpy"], dpy, json_options_);
        FieldToJson(args["visualID"], visualID, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
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
            VkBool32ToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options_);
        FieldToJson(args["connection"], connection, json_options_);
        FieldToJson(args["visual_id"], visual_id, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
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
            VkBool32ToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options_);
        FieldToJson(args["display"], display, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
            VkBool32ToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pVideoProfile"], pVideoProfile, json_options_);
        FieldToJson(args["pCapabilities"], pCapabilities, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pVideoFormatInfo"], pVideoFormatInfo, json_options_);
        FieldToJson(args["pVideoFormatPropertyCount"], pVideoFormatPropertyCount, json_options_);
        FieldToJson(args["pVideoFormatProperties"], pVideoFormatProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pVideoSession"], pVideoSession, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["videoSession"], videoSession, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["videoSession"], videoSession, json_options_);
        FieldToJson(args["pMemoryRequirementsCount"], pMemoryRequirementsCount, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["videoSession"], videoSession, json_options_);
        FieldToJson(args["bindSessionMemoryInfoCount"], bindSessionMemoryInfoCount, json_options_);
        FieldToJson(args["pBindSessionMemoryInfos"], pBindSessionMemoryInfos, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pVideoSessionParameters"], pVideoSessionParameters, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["videoSessionParameters"], videoSessionParameters, json_options_);
        FieldToJson(args["pUpdateInfo"], pUpdateInfo, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["videoSessionParameters"], videoSessionParameters, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginVideoCodingKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pBeginInfo"], pBeginInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndVideoCodingKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pEndCodingInfo"], pEndCodingInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdControlVideoCodingKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pCodingControlInfo"], pCodingControlInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDecodeVideoKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pDecodeInfo"], pDecodeInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderingKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pRenderingInfo"], pRenderingInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderingKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceFeatures2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pFeatures"], pFeatures, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceProperties2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["format"], format, json_options_);
        FieldToJson(args["pFormatProperties"], pFormatProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pImageFormatInfo"], pImageFormatInfo, json_options_);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pQueueFamilyPropertyCount"], pQueueFamilyPropertyCount, json_options_);
        FieldToJson(args["pQueueFamilyProperties"], pQueueFamilyProperties, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceMemoryProperties2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pMemoryProperties"], pMemoryProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pFormatInfo"], pFormatInfo, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["heapIndex"], heapIndex, json_options_);
        FieldToJson(args["localDeviceIndex"], localDeviceIndex, json_options_);
        FieldToJson(args["remoteDeviceIndex"], remoteDeviceIndex, json_options_);
        FieldToJson(args["pPeerMemoryFeatures"], pPeerMemoryFeatures, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDeviceMaskKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["deviceMask"], deviceMask, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["baseGroupX"], baseGroupX, json_options_);
        FieldToJson(args["baseGroupY"], baseGroupY, json_options_);
        FieldToJson(args["baseGroupZ"], baseGroupZ, json_options_);
        FieldToJson(args["groupCountX"], groupCountX, json_options_);
        FieldToJson(args["groupCountY"], groupCountY, json_options_);
        FieldToJson(args["groupCountZ"], groupCountZ, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["commandPool"], commandPool, json_options_);
        FieldToJson(VkCommandPoolTrimFlags_t(), args["flags"], flags, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pPhysicalDeviceGroupCount"], pPhysicalDeviceGroupCount, json_options_);
        FieldToJson(args["pPhysicalDeviceGroupProperties"], pPhysicalDeviceGroupProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pExternalBufferInfo"], pExternalBufferInfo, json_options_);
        FieldToJson(args["pExternalBufferProperties"], pExternalBufferProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pGetWin32HandleInfo"], pGetWin32HandleInfo, json_options_);
        FieldToJson(args["pHandle"], pHandle, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["handleType"], handleType, json_options_);
        FieldToJson(args["handle"], handle, json_options_);
        FieldToJson(args["pMemoryWin32HandleProperties"], pMemoryWin32HandleProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pGetFdInfo"], pGetFdInfo, json_options_);
        FieldToJson(args["pFd"], pFd, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["handleType"], handleType, json_options_);
        FieldToJson(args["fd"], fd, json_options_);
        FieldToJson(args["pMemoryFdProperties"], pMemoryFdProperties, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pExternalSemaphoreInfo"], pExternalSemaphoreInfo, json_options_);
        FieldToJson(args["pExternalSemaphoreProperties"], pExternalSemaphoreProperties, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreWin32HandleKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pImportSemaphoreWin32HandleInfo"], pImportSemaphoreWin32HandleInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pGetWin32HandleInfo"], pGetWin32HandleInfo, json_options_);
        FieldToJson(args["pHandle"], pHandle, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreFdKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pImportSemaphoreFdInfo"], pImportSemaphoreFdInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pGetFdInfo"], pGetFdInfo, json_options_);
        FieldToJson(args["pFd"], pFd, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pipelineBindPoint"], pipelineBindPoint, json_options_);
        HandleToJson(args["layout"], layout, json_options_);
        FieldToJson(args["set"], set, json_options_);
        FieldToJson(args["descriptorWriteCount"], descriptorWriteCount, json_options_);
        FieldToJson(args["pDescriptorWrites"], pDescriptorWrites, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pDescriptorUpdateTemplate"], pDescriptorUpdateTemplate, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["descriptorUpdateTemplate"], descriptorUpdateTemplate, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pRenderPass"], pRenderPass, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginRenderPass2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pRenderPassBegin"], pRenderPassBegin, json_options_);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdNextSubpass2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pSubpassBeginInfo"], pSubpassBeginInfo, json_options_);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndRenderPass2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pSubpassEndInfo"], pSubpassEndInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetSwapchainStatusKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapchain"], swapchain, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pExternalFenceInfo"], pExternalFenceInfo, json_options_);
        FieldToJson(args["pExternalFenceProperties"], pExternalFenceProperties, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportFenceWin32HandleKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pImportFenceWin32HandleInfo"], pImportFenceWin32HandleInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pGetWin32HandleInfo"], pGetWin32HandleInfo, json_options_);
        FieldToJson(args["pHandle"], pHandle, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportFenceFdKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pImportFenceFdInfo"], pImportFenceFdInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pGetFdInfo"], pGetFdInfo, json_options_);
        FieldToJson(args["pFd"], pFd, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options_);
        FieldToJson(args["pCounterCount"], pCounterCount, json_options_);
        FieldToJson(args["pCounters"], pCounters, json_options_);
        FieldToJson(args["pCounterDescriptions"], pCounterDescriptions, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pPerformanceQueryCreateInfo"], pPerformanceQueryCreateInfo, json_options_);
        FieldToJson(args["pNumPasses"], pNumPasses, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireProfilingLockKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseProfilingLockKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo, json_options_);
        FieldToJson(args["pSurfaceCapabilities"], pSurfaceCapabilities, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo, json_options_);
        FieldToJson(args["pSurfaceFormatCount"], pSurfaceFormatCount, json_options_);
        FieldToJson(args["pSurfaceFormats"], pSurfaceFormats, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["display"], display, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pDisplayPlaneInfo"], pDisplayPlaneInfo, json_options_);
        FieldToJson(args["pCapabilities"], pCapabilities, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options_);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pYcbcrConversion"], pYcbcrConversion, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["ycbcrConversion"], ycbcrConversion, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options_);
        FieldToJson(args["pBindInfos"], pBindInfos, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options_);
        FieldToJson(args["pBindInfos"], pBindInfos, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pSupport"], pSupport, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        HandleToJson(args["countBuffer"], countBuffer, json_options_);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options_);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        HandleToJson(args["countBuffer"], countBuffer, json_options_);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options_);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["semaphore"], semaphore, json_options_);
        FieldToJson(args["pValue"], pValue, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pWaitInfo"], pWaitInfo, json_options_);
        FieldToJson(args["timeout"], timeout, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSignalSemaphoreKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pSignalInfo"], pSignalInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pFragmentShadingRateCount"], pFragmentShadingRateCount, json_options_);
        FieldToJson(args["pFragmentShadingRates"], pFragmentShadingRates, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFragmentShadingRateKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pFragmentSize"], pFragmentSize, json_options_);
        FieldToJson(args["combinerOps"], combinerOps, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapchain"], swapchain, json_options_);
        FieldToJson(args["presentId"], presentId, json_options_);
        FieldToJson(args["timeout"], timeout, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddressKHR");
    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferOpaqueCaptureAddressKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pDeferredOperation"], pDeferredOperation, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["operation"], operation, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeferredOperationMaxConcurrencyKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["operation"], operation, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeferredOperationResultKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["operation"], operation, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDeferredOperationJoinKHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["operation"], operation, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pPipelineInfo"], pPipelineInfo, json_options_);
        FieldToJson(args["pExecutableCount"], pExecutableCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pExecutableInfo"], pExecutableInfo, json_options_);
        FieldToJson(args["pStatisticCount"], pStatisticCount, json_options_);
        FieldToJson(args["pStatistics"], pStatistics, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pExecutableInfo"], pExecutableInfo, json_options_);
        FieldToJson(args["pInternalRepresentationCount"], pInternalRepresentationCount, json_options_);
        FieldToJson(args["pInternalRepresentations"], pInternalRepresentations, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkMapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryMapInfoKHR>* pMemoryMapInfo,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkMapMemory2KHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pMemoryMapInfo"], pMemoryMapInfo, json_options_);
        FieldToJsonAsHex(args["ppData"], ppData, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryUnmapInfoKHR>* pMemoryUnmapInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUnmapMemory2KHR");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pMemoryUnmapInfo"], pMemoryUnmapInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pQualityLevelInfo"], pQualityLevelInfo, json_options_);
        FieldToJson(args["pQualityLevelProperties"], pQualityLevelProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pVideoSessionParametersInfo"], pVideoSessionParametersInfo, json_options_);
        FieldToJson(args["pFeedbackInfo"], pFeedbackInfo, json_options_);
        FieldToJson(args["pDataSize"], pDataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEncodeVideoKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pEncodeInfo"], pEncodeInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetEvent2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["event"], event, json_options_);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResetEvent2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["event"], event, json_options_);
        FieldToJson(VkPipelineStageFlags2_t(), args["stageMask"], stageMask, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["eventCount"], eventCount, json_options_);
        HandleToJson(args["pEvents"], pEvents, json_options_);
        FieldToJson(args["pDependencyInfos"], pDependencyInfos, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPipelineBarrier2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pDependencyInfo"], pDependencyInfo, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkPipelineStageFlags2_t(), args["stage"], stage, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["query"], query, json_options_);
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
    FieldToJson(jdata[NameSubmitIndex()], ++submit_index_, json_options_);
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options_);
        FieldToJson(args["submitCount"], submitCount, json_options_);
        FieldToJson(args["pSubmits"], pSubmits, json_options_);
        HandleToJson(args["fence"], fence, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkPipelineStageFlags2_t(), args["stage"], stage, json_options_);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options_);
        FieldToJson(args["dstOffset"], dstOffset, json_options_);
        FieldToJson(args["marker"], marker, json_options_);
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
        HandleToJson(args["queue"], queue, json_options_);
        FieldToJson(args["pCheckpointDataCount"], pCheckpointDataCount, json_options_);
        FieldToJson(args["pCheckpointData"], pCheckpointData, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBuffer2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pCopyBufferInfo"], pCopyBufferInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImage2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pCopyImageInfo"], pCopyImageInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyBufferToImage2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pCopyBufferToImageInfo"], pCopyBufferToImageInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyImageToBuffer2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pCopyImageToBufferInfo"], pCopyImageToBufferInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBlitImage2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pBlitImageInfo"], pBlitImageInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdResolveImage2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pResolveImageInfo"], pResolveImageInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdTraceRaysIndirect2KHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJsonAsHex(args["indirectDeviceAddress"], indirectDeviceAddress, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pSparseMemoryRequirementCount"], pSparseMemoryRequirementCount, json_options_);
        FieldToJson(args["pSparseMemoryRequirements"], pSparseMemoryRequirements, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        FieldToJson(args["size"], size, json_options_);
        FieldToJson(args["indexType"], indexType, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetRenderingAreaGranularityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingAreaInfoKHR>* pRenderingAreaInfo,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetRenderingAreaGranularityKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pRenderingAreaInfo"], pRenderingAreaInfo, json_options_);
        FieldToJson(args["pGranularity"], pGranularity, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetDeviceImageSubresourceLayoutKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetDeviceImageSubresourceLayoutKHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pLayout"], pLayout, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSubresourceLayout2KHR");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["image"], image, json_options_);
        FieldToJson(args["pSubresource"], pSubresource, json_options_);
        FieldToJson(args["pLayout"], pLayout, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["semaphore"], semaphore, json_options_);
        HandleToJson(args["image"], image, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pCallback"], pCallback, json_options_);
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
        HandleToJson(args["instance"], instance, json_options_);
        HandleToJson(args["callback"], callback, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(VkDebugReportFlagsEXT_t(), args["flags"], flags, json_options_);
        FieldToJson(args["objectType"], objectType, json_options_);
        FieldToJson(args["object"], object, json_options_);
        FieldToJson(args["location"], location, json_options_);
        FieldToJson(args["messageCode"], messageCode, json_options_);
        FieldToJson(args["pLayerPrefix"], pLayerPrefix, json_options_);
        FieldToJson(args["pMessage"], pMessage, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDebugMarkerSetObjectTagEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pTagInfo"], pTagInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkDebugMarkerSetObjectNameEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pNameInfo"], pNameInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerBeginEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerEndEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDebugMarkerInsertEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstBinding"], firstBinding, json_options_);
        FieldToJson(args["bindingCount"], bindingCount, json_options_);
        HandleToJson(args["pBuffers"], pBuffers, json_options_);
        FieldToJson(args["pOffsets"], pOffsets, json_options_);
        FieldToJson(args["pSizes"], pSizes, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstCounterBuffer"], firstCounterBuffer, json_options_);
        FieldToJson(args["counterBufferCount"], counterBufferCount, json_options_);
        HandleToJson(args["pCounterBuffers"], pCounterBuffers, json_options_);
        FieldToJson(args["pCounterBufferOffsets"], pCounterBufferOffsets, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstCounterBuffer"], firstCounterBuffer, json_options_);
        FieldToJson(args["counterBufferCount"], counterBufferCount, json_options_);
        HandleToJson(args["pCounterBuffers"], pCounterBuffers, json_options_);
        FieldToJson(args["pCounterBufferOffsets"], pCounterBufferOffsets, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["query"], query, json_options_);
        FieldToJson(VkQueryControlFlags_t(), args["flags"], flags, json_options_);
        FieldToJson(args["index"], index, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["query"], query, json_options_);
        FieldToJson(args["index"], index, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["instanceCount"], instanceCount, json_options_);
        FieldToJson(args["firstInstance"], firstInstance, json_options_);
        HandleToJson(args["counterBuffer"], counterBuffer, json_options_);
        FieldToJson(args["counterBufferOffset"], counterBufferOffset, json_options_);
        FieldToJson(args["counterOffset"], counterOffset, json_options_);
        FieldToJson(args["vertexStride"], vertexStride, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageViewHandleNVX");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["imageView"], imageView, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        HandleToJson(args["countBuffer"], countBuffer, json_options_);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options_);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        HandleToJson(args["countBuffer"], countBuffer, json_options_);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options_);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipeline"], pipeline, json_options_);
        FieldToJson(args["shaderStage"], shaderStage, json_options_);
        FieldToJson(args["infoType"], infoType, json_options_);
        FieldToJson(args["pInfoSize"], pInfoSize, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["format"], format, json_options_);
        FieldToJson(args["type"], type, json_options_);
        FieldToJson(args["tiling"], tiling, json_options_);
        FieldToJson(VkImageUsageFlags_t(), args["usage"], usage, json_options_);
        FieldToJson(VkImageCreateFlags_t(), args["flags"], flags, json_options_);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(), args["externalHandleType"], externalHandleType, json_options_);
        FieldToJson(args["pExternalImageFormatProperties"], pExternalImageFormatProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["memory"], memory, json_options_);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(), args["handleType"], handleType, json_options_);
        FieldToJson(args["pHandle"], pHandle, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginConditionalRenderingEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pConditionalRenderingBegin"], pConditionalRenderingBegin, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndConditionalRenderingEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstViewport"], firstViewport, json_options_);
        FieldToJson(args["viewportCount"], viewportCount, json_options_);
        FieldToJson(args["pViewportWScalings"], pViewportWScalings, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseDisplayEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["display"], display, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["dpy"], dpy, json_options_);
        HandleToJson(args["display"], display, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["dpy"], dpy, json_options_);
        FieldToJson(args["rrOutput"], rrOutput, json_options_);
        HandleToJson(args["pDisplay"], pDisplay, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["surface"], surface, json_options_);
        FieldToJson(args["pSurfaceCapabilities"], pSurfaceCapabilities, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["display"], display, json_options_);
        FieldToJson(args["pDisplayPowerInfo"], pDisplayPowerInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pDeviceEventInfo"], pDeviceEventInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pFence"], pFence, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["display"], display, json_options_);
        FieldToJson(args["pDisplayEventInfo"], pDisplayEventInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pFence"], pFence, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapchain"], swapchain, json_options_);
        FieldToJson(args["counter"], counter, json_options_);
        FieldToJson(args["pCounterValue"], pCounterValue, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapchain"], swapchain, json_options_);
        FieldToJson(args["pDisplayTimingProperties"], pDisplayTimingProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapchain"], swapchain, json_options_);
        FieldToJson(args["pPresentationTimingCount"], pPresentationTimingCount, json_options_);
        FieldToJson(args["pPresentationTimings"], pPresentationTimings, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstDiscardRectangle"], firstDiscardRectangle, json_options_);
        FieldToJson(args["discardRectangleCount"], discardRectangleCount, json_options_);
        FieldToJson(args["pDiscardRectangles"], pDiscardRectangles, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDiscardRectangleEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["discardRectangleEnable"], discardRectangleEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDiscardRectangleModeEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["discardRectangleMode"], discardRectangleMode, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["swapchainCount"], swapchainCount, json_options_);
        HandleToJson(args["pSwapchains"], pSwapchains, json_options_);
        FieldToJson(args["pMetadata"], pMetadata, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDebugUtilsObjectNameEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pNameInfo"], pNameInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkSetDebugUtilsObjectTagEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pTagInfo"], pTagInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueBeginDebugUtilsLabelEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options_);
        FieldToJson(args["pLabelInfo"], pLabelInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueEndDebugUtilsLabelEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueInsertDebugUtilsLabelEXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options_);
        FieldToJson(args["pLabelInfo"], pLabelInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBeginDebugUtilsLabelEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pLabelInfo"], pLabelInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdEndDebugUtilsLabelEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdInsertDebugUtilsLabelEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pLabelInfo"], pLabelInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pMessenger"], pMessenger, json_options_);
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
        HandleToJson(args["instance"], instance, json_options_);
        HandleToJson(args["messenger"], messenger, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["messageSeverity"], messageSeverity, json_options_);
        FieldToJson(VkDebugUtilsMessageTypeFlagsEXT_t(), args["messageTypes"], messageTypes, json_options_);
        FieldToJson(args["pCallbackData"], pCallbackData, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pBuffer"], pBuffer, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleLocationsEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pSampleLocationsInfo"], pSampleLocationsInfo, json_options_);
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
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["samples"], samples, json_options_);
        FieldToJson(args["pMultisampleProperties"], pMultisampleProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["image"], image, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pValidationCache"], pValidationCache, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["validationCache"], validationCache, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["dstCache"], dstCache, json_options_);
        FieldToJson(args["srcCacheCount"], srcCacheCount, json_options_);
        HandleToJson(args["pSrcCaches"], pSrcCaches, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["validationCache"], validationCache, json_options_);
        FieldToJson(args["pDataSize"], pDataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindShadingRateImageNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["imageView"], imageView, json_options_);
        FieldToJson(args["imageLayout"], imageLayout, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstViewport"], firstViewport, json_options_);
        FieldToJson(args["viewportCount"], viewportCount, json_options_);
        FieldToJson(args["pShadingRatePalettes"], pShadingRatePalettes, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["sampleOrderType"], sampleOrderType, json_options_);
        FieldToJson(args["customSampleOrderCount"], customSampleOrderCount, json_options_);
        FieldToJson(args["pCustomSampleOrders"], pCustomSampleOrders, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pAccelerationStructure"], pAccelerationStructure, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["accelerationStructure"], accelerationStructure, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureMemoryRequirementsNV");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["bindInfoCount"], bindInfoCount, json_options_);
        FieldToJson(args["pBindInfos"], pBindInfos, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        HandleToJson(args["instanceData"], instanceData, json_options_);
        FieldToJson(args["instanceOffset"], instanceOffset, json_options_);
        VkBool32ToJson(args["update"], update, json_options_);
        HandleToJson(args["dst"], dst, json_options_);
        HandleToJson(args["src"], src, json_options_);
        HandleToJson(args["scratch"], scratch, json_options_);
        FieldToJson(args["scratchOffset"], scratchOffset, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["dst"], dst, json_options_);
        HandleToJson(args["src"], src, json_options_);
        FieldToJson(args["mode"], mode, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["raygenShaderBindingTableBuffer"], raygenShaderBindingTableBuffer, json_options_);
        FieldToJson(args["raygenShaderBindingOffset"], raygenShaderBindingOffset, json_options_);
        HandleToJson(args["missShaderBindingTableBuffer"], missShaderBindingTableBuffer, json_options_);
        FieldToJson(args["missShaderBindingOffset"], missShaderBindingOffset, json_options_);
        FieldToJson(args["missShaderBindingStride"], missShaderBindingStride, json_options_);
        HandleToJson(args["hitShaderBindingTableBuffer"], hitShaderBindingTableBuffer, json_options_);
        FieldToJson(args["hitShaderBindingOffset"], hitShaderBindingOffset, json_options_);
        FieldToJson(args["hitShaderBindingStride"], hitShaderBindingStride, json_options_);
        HandleToJson(args["callableShaderBindingTableBuffer"], callableShaderBindingTableBuffer, json_options_);
        FieldToJson(args["callableShaderBindingOffset"], callableShaderBindingOffset, json_options_);
        FieldToJson(args["callableShaderBindingStride"], callableShaderBindingStride, json_options_);
        FieldToJson(args["width"], width, json_options_);
        FieldToJson(args["height"], height, json_options_);
        FieldToJson(args["depth"], depth, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options_);
        FieldToJson(args["createInfoCount"], createInfoCount, json_options_);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pPipelines"], pPipelines, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipeline"], pipeline, json_options_);
        FieldToJson(args["firstGroup"], firstGroup, json_options_);
        FieldToJson(args["groupCount"], groupCount, json_options_);
        FieldToJson(args["dataSize"], dataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipeline"], pipeline, json_options_);
        FieldToJson(args["firstGroup"], firstGroup, json_options_);
        FieldToJson(args["groupCount"], groupCount, json_options_);
        FieldToJson(args["dataSize"], dataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["accelerationStructure"], accelerationStructure, json_options_);
        FieldToJson(args["dataSize"], dataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["accelerationStructureCount"], accelerationStructureCount, json_options_);
        HandleToJson(args["pAccelerationStructures"], pAccelerationStructures, json_options_);
        FieldToJson(args["queryType"], queryType, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["firstQuery"], firstQuery, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipeline"], pipeline, json_options_);
        FieldToJson(args["shader"], shader, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["handleType"], handleType, json_options_);
        FieldToJson(args["pHostPointer"], pHostPointer, json_options_);
        FieldToJson(args["pMemoryHostPointerProperties"], pMemoryHostPointerProperties, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pipelineStage"], pipelineStage, json_options_);
        HandleToJson(args["dstBuffer"], dstBuffer, json_options_);
        FieldToJson(args["dstOffset"], dstOffset, json_options_);
        FieldToJson(args["marker"], marker, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pTimeDomainCount"], pTimeDomainCount, json_options_);
        FieldToJson(args["pTimeDomains"], pTimeDomains, json_options_);
    WriteBlockEnd();
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
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetCalibratedTimestampsEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["timestampCount"], timestampCount, json_options_);
        FieldToJson(args["pTimestampInfos"], pTimestampInfos, json_options_);
        FieldToJson(args["pTimestamps"], pTimestamps, json_options_);
        FieldToJson(args["pMaxDeviation"], pMaxDeviation, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawMeshTasksNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["taskCount"], taskCount, json_options_);
        FieldToJson(args["firstTask"], firstTask, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        FieldToJson(args["drawCount"], drawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        HandleToJson(args["countBuffer"], countBuffer, json_options_);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options_);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstExclusiveScissor"], firstExclusiveScissor, json_options_);
        FieldToJson(args["exclusiveScissorCount"], exclusiveScissorCount, json_options_);
        VkBool32ToJson(args["pExclusiveScissorEnables"], pExclusiveScissorEnables, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstExclusiveScissor"], firstExclusiveScissor, json_options_);
        FieldToJson(args["exclusiveScissorCount"], exclusiveScissorCount, json_options_);
        FieldToJson(args["pExclusiveScissors"], pExclusiveScissors, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCheckpointNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pCheckpointMarker"], pCheckpointMarker, json_options_);
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
        HandleToJson(args["queue"], queue, json_options_);
        FieldToJson(args["pCheckpointDataCount"], pCheckpointDataCount, json_options_);
        FieldToJson(args["pCheckpointData"], pCheckpointData, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkInitializePerformanceApiINTEL");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInitializeInfo"], pInitializeInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkUninitializePerformanceApiINTEL");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceMarkerINTEL");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceStreamMarkerINTEL");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pMarkerInfo"], pMarkerInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPerformanceOverrideINTEL");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pOverrideInfo"], pOverrideInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pAcquireInfo"], pAcquireInfo, json_options_);
        HandleToJson(args["pConfiguration"], pConfiguration, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleasePerformanceConfigurationINTEL");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["configuration"], configuration, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkQueueSetPerformanceConfigurationINTEL");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["queue"], queue, json_options_);
        HandleToJson(args["configuration"], configuration, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["parameter"], parameter, json_options_);
        FieldToJson(args["pValue"], pValue, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapChain"], swapChain, json_options_);
        VkBool32ToJson(args["localDimmingEnable"], localDimmingEnable, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetBufferDeviceAddressEXT");
    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pToolCount"], pToolCount, json_options_);
        FieldToJson(args["pToolProperties"], pToolProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pPropertyCount"], pPropertyCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pCombinationCount"], pCombinationCount, json_options_);
        FieldToJson(args["pCombinations"], pCombinations, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo, json_options_);
        FieldToJson(args["pPresentModeCount"], pPresentModeCount, json_options_);
        FieldToJson(args["pPresentModes"], pPresentModes, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireFullScreenExclusiveModeEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapchain"], swapchain, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseFullScreenExclusiveModeEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["swapchain"], swapchain, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pSurfaceInfo"], pSurfaceInfo, json_options_);
        FieldToJson(args["pModes"], pModes, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["lineStippleFactor"], lineStippleFactor, json_options_);
        FieldToJson(args["lineStipplePattern"], lineStipplePattern, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["firstQuery"], firstQuery, json_options_);
        FieldToJson(args["queryCount"], queryCount, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCullModeEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkCullModeFlags_t(), args["cullMode"], cullMode, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFrontFaceEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["frontFace"], frontFace, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveTopologyEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["primitiveTopology"], primitiveTopology, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWithCountEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["viewportCount"], viewportCount, json_options_);
        FieldToJson(args["pViewports"], pViewports, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetScissorWithCountEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["scissorCount"], scissorCount, json_options_);
        FieldToJson(args["pScissors"], pScissors, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstBinding"], firstBinding, json_options_);
        FieldToJson(args["bindingCount"], bindingCount, json_options_);
        HandleToJson(args["pBuffers"], pBuffers, json_options_);
        FieldToJson(args["pOffsets"], pOffsets, json_options_);
        FieldToJson(args["pSizes"], pSizes, json_options_);
        FieldToJson(args["pStrides"], pStrides, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthTestEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["depthTestEnable"], depthTestEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthWriteEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["depthWriteEnable"], depthWriteEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthCompareOpEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["depthCompareOp"], depthCompareOp, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBoundsTestEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["depthBoundsTestEnable"], depthBoundsTestEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetStencilTestEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["stencilTestEnable"], stencilTestEnable, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkStencilFaceFlags_t(), args["faceMask"], faceMask, json_options_);
        FieldToJson(args["failOp"], failOp, json_options_);
        FieldToJson(args["passOp"], passOp, json_options_);
        FieldToJson(args["depthFailOp"], depthFailOp, json_options_);
        FieldToJson(args["compareOp"], compareOp, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyMemoryToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfoEXT>* pCopyMemoryToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyMemoryToImageEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCopyMemoryToImageInfo"], pCopyMemoryToImageInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfoEXT>* pCopyImageToMemoryInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToMemoryEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCopyImageToMemoryInfo"], pCopyImageToMemoryInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCopyImageToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToImageInfoEXT>* pCopyImageToImageInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCopyImageToImageEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCopyImageToImageInfo"], pCopyImageToImageInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkTransitionImageLayoutEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    transitionCount,
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfoEXT>* pTransitions)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkTransitionImageLayoutEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["transitionCount"], transitionCount, json_options_);
        FieldToJson(args["pTransitions"], pTransitions, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetImageSubresourceLayout2EXT");
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["image"], image, json_options_);
        FieldToJson(args["pSubresource"], pSubresource, json_options_);
        FieldToJson(args["pLayout"], pLayout, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkReleaseSwapchainImagesEXT");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pReleaseInfo"], pReleaseInfo, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdPreprocessGeneratedCommandsNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pGeneratedCommandsInfo"], pGeneratedCommandsInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdExecuteGeneratedCommandsNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["isPreprocessed"], isPreprocessed, json_options_);
        FieldToJson(args["pGeneratedCommandsInfo"], pGeneratedCommandsInfo, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pipelineBindPoint"], pipelineBindPoint, json_options_);
        HandleToJson(args["pipeline"], pipeline, json_options_);
        FieldToJson(args["groupIndex"], groupIndex, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pIndirectCommandsLayout"], pIndirectCommandsLayout, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["indirectCommandsLayout"], indirectCommandsLayout, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBias2EXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pDepthBiasInfo"], pDepthBiasInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["drmFd"], drmFd, json_options_);
        HandleToJson(args["display"], display, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["drmFd"], drmFd, json_options_);
        FieldToJson(args["connectorId"], connectorId, json_options_);
        HandleToJson(args["display"], display, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pPrivateDataSlot"], pPrivateDataSlot, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["objectType"], objectType, json_options_);
        HandleToJson(args["objectHandle"], objectHandle, json_options_);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options_);
        FieldToJson(args["data"], data, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["objectType"], objectType, json_options_);
        HandleToJson(args["objectHandle"], objectHandle, json_options_);
        HandleToJson(args["privateDataSlot"], privateDataSlot, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetFragmentShadingRateEnumNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["shadingRate"], shadingRate, json_options_);
        FieldToJson(args["combinerOps"], combinerOps, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pFaultCounts"], pFaultCounts, json_options_);
        FieldToJson(args["pFaultInfo"], pFaultInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkAcquireWinrtDisplayNV");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        HandleToJson(args["display"], display, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["deviceRelativeId"], deviceRelativeId, json_options_);
        HandleToJson(args["pDisplay"], pDisplay, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
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
            VkBool32ToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options_);
        FieldToJson(args["dfb"], dfb, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["vertexBindingDescriptionCount"], vertexBindingDescriptionCount, json_options_);
        FieldToJson(args["pVertexBindingDescriptions"], pVertexBindingDescriptions, json_options_);
        FieldToJson(args["vertexAttributeDescriptionCount"], vertexAttributeDescriptionCount, json_options_);
        FieldToJson(args["pVertexAttributeDescriptions"], pVertexAttributeDescriptions, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pGetZirconHandleInfo"], pGetZirconHandleInfo, json_options_);
        FieldToJson(args["pZirconHandle"], pZirconHandle, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["handleType"], handleType, json_options_);
        FieldToJson(args["zirconHandle"], zirconHandle, json_options_);
        FieldToJson(args["pMemoryZirconHandleProperties"], pMemoryZirconHandleProperties, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkImportSemaphoreZirconHandleFUCHSIA");
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pImportSemaphoreZirconHandleInfo"], pImportSemaphoreZirconHandleInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pGetZirconHandleInfo"], pGetZirconHandleInfo, json_options_);
        FieldToJson(args["pZirconHandle"], pZirconHandle, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBindInvocationMaskHUAWEI");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["imageView"], imageView, json_options_);
        FieldToJson(args["imageLayout"], imageLayout, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pMemoryGetRemoteAddressInfo"], pMemoryGetRemoteAddressInfo, json_options_);
        FieldToJson(args["pAddress"], pAddress, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPatchControlPointsEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["patchControlPoints"], patchControlPoints, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizerDiscardEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["rasterizerDiscardEnable"], rasterizerDiscardEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthBiasEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["depthBiasEnable"], depthBiasEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLogicOpEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["logicOp"], logicOp, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPrimitiveRestartEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["primitiveRestartEnable"], primitiveRestartEnable, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSurface"], pSurface, json_options_);
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
            VkBool32ToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["queueFamilyIndex"], queueFamilyIndex, json_options_);
        FieldToJson(args["window"], window, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetColorWriteEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options_);
        VkBool32ToJson(args["pColorWriteEnables"], pColorWriteEnables, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["drawCount"], drawCount, json_options_);
        FieldToJson(args["pVertexInfo"], pVertexInfo, json_options_);
        FieldToJson(args["instanceCount"], instanceCount, json_options_);
        FieldToJson(args["firstInstance"], firstInstance, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["drawCount"], drawCount, json_options_);
        FieldToJson(args["pIndexInfo"], pIndexInfo, json_options_);
        FieldToJson(args["instanceCount"], instanceCount, json_options_);
        FieldToJson(args["firstInstance"], firstInstance, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
        FieldToJson(args["pVertexOffset"], pVertexOffset, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pMicromap"], pMicromap, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["micromap"], micromap, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdBuildMicromapsEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["infoCount"], infoCount, json_options_);
        FieldToJson(args["pInfos"], pInfos, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options_);
        FieldToJson(args["infoCount"], infoCount, json_options_);
        FieldToJson(args["pInfos"], pInfos, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["micromapCount"], micromapCount, json_options_);
        HandleToJson(args["pMicromaps"], pMicromaps, json_options_);
        FieldToJson(args["queryType"], queryType, json_options_);
        FieldToJson(args["dataSize"], dataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMicromapEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMicromapToMemoryEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToMicromapEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["micromapCount"], micromapCount, json_options_);
        HandleToJson(args["pMicromaps"], pMicromaps, json_options_);
        FieldToJson(args["queryType"], queryType, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["firstQuery"], firstQuery, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pVersionInfo"], pVersionInfo, json_options_);
        FieldToJson(args["pCompatibility"], pCompatibility, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["buildType"], buildType, json_options_);
        FieldToJson(args["pBuildInfo"], pBuildInfo, json_options_);
        FieldToJson(args["pSizeInfo"], pSizeInfo, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["groupCountX"], groupCountX, json_options_);
        FieldToJson(args["groupCountY"], groupCountY, json_options_);
        FieldToJson(args["groupCountZ"], groupCountZ, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdDrawClusterIndirectHUAWEI");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["memory"], memory, json_options_);
        FieldToJson(args["priority"], priority, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pBindingReference"], pBindingReference, json_options_);
        FieldToJson(args["pHostMapping"], pHostMapping, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["descriptorSet"], descriptorSet, json_options_);
        FieldToJsonAsHex(args["ppData"], ppData, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pMemoryRequirements"], pMemoryRequirements, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdUpdatePipelineIndirectBufferNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pipelineBindPoint"], pipelineBindPoint, json_options_);
        HandleToJson(args["pipeline"], pipeline, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetPipelineIndirectDeviceAddressNV(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetPipelineIndirectDeviceAddressNV");
    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetTessellationDomainOriginEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["domainOrigin"], domainOrigin, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClampEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["depthClampEnable"], depthClampEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetPolygonModeEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["polygonMode"], polygonMode, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizationSamplesEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["rasterizationSamples"], rasterizationSamples, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleMaskEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["samples"], samples, json_options_);
        FieldToJson(args["pSampleMask"], pSampleMask, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAlphaToCoverageEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["alphaToCoverageEnable"], alphaToCoverageEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAlphaToOneEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["alphaToOneEnable"], alphaToOneEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLogicOpEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["logicOpEnable"], logicOpEnable, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstAttachment"], firstAttachment, json_options_);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options_);
        VkBool32ToJson(args["pColorBlendEnables"], pColorBlendEnables, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstAttachment"], firstAttachment, json_options_);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options_);
        FieldToJson(args["pColorBlendEquations"], pColorBlendEquations, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstAttachment"], firstAttachment, json_options_);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options_);
        FieldToJson(args["pColorWriteMasks"], pColorWriteMasks, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRasterizationStreamEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["rasterizationStream"], rasterizationStream, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetConservativeRasterizationModeEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["conservativeRasterizationMode"], conservativeRasterizationMode, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetExtraPrimitiveOverestimationSizeEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["extraPrimitiveOverestimationSize"], extraPrimitiveOverestimationSize, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClipEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["depthClipEnable"], depthClipEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetSampleLocationsEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["sampleLocationsEnable"], sampleLocationsEnable, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstAttachment"], firstAttachment, json_options_);
        FieldToJson(args["attachmentCount"], attachmentCount, json_options_);
        FieldToJson(args["pColorBlendAdvanced"], pColorBlendAdvanced, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetProvokingVertexModeEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["provokingVertexMode"], provokingVertexMode, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineRasterizationModeEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["lineRasterizationMode"], lineRasterizationMode, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetLineStippleEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["stippledLineEnable"], stippledLineEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetDepthClipNegativeOneToOneEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["negativeOneToOne"], negativeOneToOne, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetViewportWScalingEnableNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["viewportWScalingEnable"], viewportWScalingEnable, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["firstViewport"], firstViewport, json_options_);
        FieldToJson(args["viewportCount"], viewportCount, json_options_);
        FieldToJson(args["pViewportSwizzles"], pViewportSwizzles, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageToColorEnableNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["coverageToColorEnable"], coverageToColorEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageToColorLocationNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["coverageToColorLocation"], coverageToColorLocation, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationModeNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["coverageModulationMode"], coverageModulationMode, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationTableEnableNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["coverageModulationTableEnable"], coverageModulationTableEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageModulationTableNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["coverageModulationTableCount"], coverageModulationTableCount, json_options_);
        FieldToJson(args["pCoverageModulationTable"], pCoverageModulationTable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetShadingRateImageEnableNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["shadingRateImageEnable"], shadingRateImageEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRepresentativeFragmentTestEnableNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        VkBool32ToJson(args["representativeFragmentTestEnable"], representativeFragmentTestEnable, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetCoverageReductionModeNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["coverageReductionMode"], coverageReductionMode, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["shaderModule"], shaderModule, json_options_);
        FieldToJson(args["pIdentifier"], pIdentifier, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pIdentifier"], pIdentifier, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["physicalDevice"], physicalDevice, json_options_);
        FieldToJson(args["pOpticalFlowImageFormatInfo"], pOpticalFlowImageFormatInfo, json_options_);
        FieldToJson(args["pFormatCount"], pFormatCount, json_options_);
        FieldToJson(args["pImageFormatProperties"], pImageFormatProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pSession"], pSession, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["session"], session, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["session"], session, json_options_);
        FieldToJson(args["bindingPoint"], bindingPoint, json_options_);
        HandleToJson(args["view"], view, json_options_);
        FieldToJson(args["layout"], layout, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdOpticalFlowExecuteNV");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["session"], session, json_options_);
        FieldToJson(args["pExecuteInfo"], pExecuteInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["createInfoCount"], createInfoCount, json_options_);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pShaders"], pShaders, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["shader"], shader, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["shader"], shader, json_options_);
        FieldToJson(args["pDataSize"], pDataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["stageCount"], stageCount, json_options_);
        FieldToJson(args["pStages"], pStages, json_options_);
        HandleToJson(args["pShaders"], pShaders, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["framebuffer"], framebuffer, json_options_);
        FieldToJson(args["pPropertiesCount"], pPropertiesCount, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pRenderingInfo"], pRenderingInfo, json_options_);
        FieldToJson(args["pProperties"], pProperties, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetAttachmentFeedbackLoopEnableEXT");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(VkImageAspectFlags_t(), args["aspectMask"], aspectMask, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pCreateInfo"], pCreateInfo, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pAccelerationStructure"], pAccelerationStructure, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["accelerationStructure"], accelerationStructure, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["infoCount"], infoCount, json_options_);
        FieldToJson(args["pInfos"], pInfos, json_options_);
        FieldToJson(args["ppBuildRangeInfos"], ppBuildRangeInfos, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["accelerationStructureCount"], accelerationStructureCount, json_options_);
        HandleToJson(args["pAccelerationStructures"], pAccelerationStructures, json_options_);
        FieldToJson(args["queryType"], queryType, json_options_);
        FieldToJson(args["dataSize"], dataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyAccelerationStructureKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyAccelerationStructureToMemoryKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdCopyMemoryToAccelerationStructureKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkGetAccelerationStructureDeviceAddressKHR");
    FieldToJsonAsHex(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pInfo"], pInfo, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["accelerationStructureCount"], accelerationStructureCount, json_options_);
        HandleToJson(args["pAccelerationStructures"], pAccelerationStructures, json_options_);
        FieldToJson(args["queryType"], queryType, json_options_);
        HandleToJson(args["queryPool"], queryPool, json_options_);
        FieldToJson(args["firstQuery"], firstQuery, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["pVersionInfo"], pVersionInfo, json_options_);
        FieldToJson(args["pCompatibility"], pCompatibility, json_options_);
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
        HandleToJson(args["device"], device, json_options_);
        FieldToJson(args["buildType"], buildType, json_options_);
        FieldToJson(args["pBuildInfo"], pBuildInfo, json_options_);
        FieldToJson(args["pMaxPrimitiveCounts"], pMaxPrimitiveCounts, json_options_);
        FieldToJson(args["pSizeInfo"], pSizeInfo, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pRaygenShaderBindingTable"], pRaygenShaderBindingTable, json_options_);
        FieldToJson(args["pMissShaderBindingTable"], pMissShaderBindingTable, json_options_);
        FieldToJson(args["pHitShaderBindingTable"], pHitShaderBindingTable, json_options_);
        FieldToJson(args["pCallableShaderBindingTable"], pCallableShaderBindingTable, json_options_);
        FieldToJson(args["width"], width, json_options_);
        FieldToJson(args["height"], height, json_options_);
        FieldToJson(args["depth"], depth, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["deferredOperation"], deferredOperation, json_options_);
        HandleToJson(args["pipelineCache"], pipelineCache, json_options_);
        FieldToJson(args["createInfoCount"], createInfoCount, json_options_);
        FieldToJson(args["pCreateInfos"], pCreateInfos, json_options_);
        FieldToJson(args["pAllocator"], pAllocator, json_options_);
        HandleToJson(args["pPipelines"], pPipelines, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipeline"], pipeline, json_options_);
        FieldToJson(args["firstGroup"], firstGroup, json_options_);
        FieldToJson(args["groupCount"], groupCount, json_options_);
        FieldToJson(args["dataSize"], dataSize, json_options_);
        FieldToJson(args["pData"], pData, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pRaygenShaderBindingTable"], pRaygenShaderBindingTable, json_options_);
        FieldToJson(args["pMissShaderBindingTable"], pMissShaderBindingTable, json_options_);
        FieldToJson(args["pHitShaderBindingTable"], pHitShaderBindingTable, json_options_);
        FieldToJson(args["pCallableShaderBindingTable"], pCallableShaderBindingTable, json_options_);
        FieldToJsonAsHex(args["indirectDeviceAddress"], indirectDeviceAddress, json_options_);
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
    FieldToJson(jdata[NameReturn()], returnValue, json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["device"], device, json_options_);
        HandleToJson(args["pipeline"], pipeline, json_options_);
        FieldToJson(args["group"], group, json_options_);
        FieldToJson(args["groupShader"], groupShader, json_options_);
    WriteBlockEnd();
}

void VulkanExportJsonConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    nlohmann::ordered_json& jdata = WriteApiCallStart(call_info, "vkCmdSetRayTracingPipelineStackSizeKHR");
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["pipelineStackSize"], pipelineStackSize, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        FieldToJson(args["groupCountX"], groupCountX, json_options_);
        FieldToJson(args["groupCountY"], groupCountY, json_options_);
        FieldToJson(args["groupCountZ"], groupCountZ, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        FieldToJson(args["drawCount"], drawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
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
    FieldToJson(jdata[NameCommandIndex()], GetCommandBufferRecordIndex(commandBuffer), json_options_);
    auto& args = jdata[NameArgs()];
        HandleToJson(args["commandBuffer"], commandBuffer, json_options_);
        HandleToJson(args["buffer"], buffer, json_options_);
        FieldToJson(args["offset"], offset, json_options_);
        HandleToJson(args["countBuffer"], countBuffer, json_options_);
        FieldToJson(args["countBufferOffset"], countBufferOffset, json_options_);
        FieldToJson(args["maxDrawCount"], maxDrawCount, json_options_);
        FieldToJson(args["stride"], stride, json_options_);
    WriteBlockEnd();
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
